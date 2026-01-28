#include "DateType.h"
#include <iomanip>
#include <iostream>
using namespace std;

void PrintMonth(int Month, ostream& Out)
{
    switch (Month) {
    case 1:
        Out << "January";
        return;
    case 2:
        Out << "February";
        return;
    case 3:
        Out << "March";
        return;
    case 4:
        Out << "April";
        return;
    case 5:
        Out << "May";
        return;
    case 6:
        Out << "June";
        return;
    case 7:
        Out << "July";
        return;
    case 8:
        Out << "August";
        return;
    case 9:
        Out << "September";
        return;
    case 10:
        Out << "October";
        return;
    case 11:
        Out << "November";
        return;
    case 12:
        Out << "December";
        return;
    default:
        Out << "Juvember";
    }
}

void PrintDate(DateType aDate, ostream& Out)
{
    PrintMonth(aDate.GetMonth(), Out);
    Out << ' ' << aDate.GetDay() << ", " << setw(4) << aDate.GetYear() << endl;
}

RelationType ComparedTo(DateType dateA, DateType dateB)
{
    if (dateA.GetYear() < dateB.GetYear())
        return Precedes;
    if (dateA.GetYear() > dateB.GetYear())
        return Follows;
    if (dateA.GetMonth() < dateB.GetMonth())
        return Precedes;
    if (dateA.GetMonth() > dateB.GetMonth())
        return Follows;
    if (dateA.GetDay() < dateB.GetDay())
        return Precedes;
    if (dateA.GetDay() > dateB.GetDay())
        return Follows;
    return Same;
}

int main()
{
    DateType Tomorrow(1, 18, 2002), AnotherDay(10, 12, 1885);
    if (ComparedTo(Tomorrow, AnotherDay) == Same) {
        cout << "what do you think?" << endl;
    }

    if (Tomorrow.ComparedTo(AnotherDay) == Same)
        cout << "Think about it, Scarlett!" << endl;

    PrintDate(Tomorrow, cout);
}
