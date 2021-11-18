#include "lunar.h"

Lunar::Lunar()
{


}
int Lunar::LunarCalendar(int year, int month, int day)
{
    int Spring_NY, Sun_NY, StaticDayCount;
    int index, flag;
    //Spring_NY 记录春节离当年元旦的天数。
    //Sun_NY 记录阳历日离当年元旦的天数。
    if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
    else
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
    Sun_NY = MonthAdd[month - 1] + day - 1;
    if ((!(year % 4)) && (month > 2))
        Sun_NY++;
    //StaticDayCount记录大小月的天数 29 或30
    //index 记录从哪个月开始来计算。
    //flag 是用来对闰月的特殊处理。
    //判断阳历日在春节前还是春节后
    if (Sun_NY >= Spring_NY)//阳历日在春节后（含春节那天）
    {
        Sun_NY -= Spring_NY;
        month = 1;
        index = 1;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Sun_NY >= StaticDayCount)
        {
            Sun_NY -= StaticDayCount;
            index++;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
            {
                flag = ~flag;
                if (flag == 0)
                    month++;
            }
            else
                month++;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = Sun_NY + 1;
    }
    else //阳历日在春节前
    {
        Spring_NY -= Sun_NY;
        year--;
        month = 12;
        if (((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
            index = 12;
        else
            index = 13;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Spring_NY > StaticDayCount)
        {
            Spring_NY -= StaticDayCount;
            index--;
            if (flag == 0)
                month--;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
                flag = ~flag;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = StaticDayCount - Spring_NY + 1;
    }
    LunarCalendarDay |= day;
    LunarCalendarDay |= (month << 6);
    if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
        return 1;
    else
        return 0;
}
QString Lunar::getLunar(int year, int month, int day)
{
    const char* ChDay[] = { "*","初一","初二","初三","初四","初五",
                            "初六","初七","初八","初九","初十",
                            "十一","十二","十三","十四","十五",
                            "十六","十七","十八","十九","二十",
                            "廿一","廿二","廿三","廿四","廿五",
                            "廿六","廿七","廿八","廿九","三十"
                          };
    const char* ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","十一","腊" };
    char str[100] = "";
    if (LunarCalendar(year, month, day))
    {
        strcat_s(str, "闰");
        strcat_s(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    }
    else
        strcat_s(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    strcat_s(str, "月");
    strcat_s(str, 100, ChDay[LunarCalendarDay & 0x3F]);
    return str;
}
int Lunar::weekOfDate(int year, int month, int day)
{
    /*w=y+[y/4]+[c/4]-2c+[26(m+1）/10]+d-1   2049年10月1日

       =49+[49/4]+[20/4]-2×20+[26×（10+1）/10]+1-1*/
    if(month==1||month==2) {
           month+=12;
           year--;
       }
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7 + 1;
}

int Lunar::weekOfDate(QString year, QString month, QString day)
{
    return weekOfDate(year.toInt(),month.toInt(),day.toInt());
}

QString Lunar::getLunar(QString year, QString month, QString day)
{
    return getLunar(year.toInt(),month.toInt(),day.toInt());
}
