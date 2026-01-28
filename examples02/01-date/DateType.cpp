#include "DateType.h"

/** Constructors **/
DateType::DateType()
{
    Day = 1;
    Month = 1;
    Year = 1;
}
DateType::DateType(int newMonth, int newDay, int newYear)
{
    Day = newDay;
    Month = newMonth;
    Year = newYear;
}
// returns Year
int DateType::GetYear() const
{
    return Year;
}
// returns Month
int DateType::GetMonth() const
{
    return Month;
}
// returns Day
int DateType::GetDay() const
{
    return Day;
}

RelationType DateType::ComparedTo(DateType otherDate)
{
    if (Year < otherDate.Year)
        return Precedes;
    if (Year > otherDate.Year)
        return Follows;
    if (Month < otherDate.Month)
        return Precedes;
    if (Month > otherDate.Month)
        return Follows;
    if (Day < otherDate.Day)
        return Precedes;
    if (Day > otherDate.Day)
        return Follows;
    return Same;
}
