#include <stdio.h>

/**
 * Determines whether the given year is a leap year.
 * @param year given year
 * @return 1 for leap year / 0 otherwise
 */
unsigned isLeapYear (unsigned year) {
    // *** TODO ***
    if(year % 4){
        return 0;
    }
    else{
        return 1;
    }
}


/**
 * Checks whether date is valid.
 * @param day
 * @param month
 * @param isLeap 1 if day is in a leap year / 0 otherwise
 * @return 1 if date is valid / 0 otherwise
 * */
unsigned isValidDate (unsigned daysInMonth [], unsigned day, unsigned month ) {
    // *** TODO ***
    unsigned error = 0;
    if(daysInMonth[month] >= day){
        error = 1;
    }
    if(month < 0 || month >= 12)
    {
        error = 1;
    }
    return error;
}


/**
 * Prints the weekday:
 *  1   -> Monday
 *  2   -> Tuesday
 *  ...
 *  0/7 -> Sunday
 *  */
int printWeekday(unsigned weekday) {
    // *** TODO ***
    switch (weekday) {
        case 1:
            printf("Montag");
            break;
        case 2:
            printf("Dienstag");
            break;
        case 3:
            printf("Mittwoch");
            break;
        case 4:
            printf("Donnerstag");
            break;
        case 5:
            printf("Freitag");
            break;
        case 6:
            printf("Samstag");
            break;
        case 7:
            printf("Samstag");
            break;

    }

}


/**
 * Determines which day of the year the given date is.
 * @param daysInMonth array giving the number of days per month
 * @param day
 * @param month
 * @return
 */
unsigned determineDayInYear(unsigned daysInMonth [], unsigned day, unsigned month ) {
    // *** TODO ***
    unsigned DayInYear = 0;
    for(int i = 0; i<= month;i++) {
        if(i < month) {
            DayInYear = DayInYear + daysInMonth[i];
        }
        else if (i == month) {
            DayInYear = DayInYear + day;
        }

    }
    return DayInYear;
}


/**
 * Determines the weekday of the first day (01 Jan) of the given year.
 * @param year
 * @return 1=Monday, 2=Tuesday, ... 0 or 7=Sunday
 */
unsigned determineWeekdayOfJan01(unsigned year) {
    return (2 + (year - 1901) + ((year - 1901)/4)) % 7;
}


/**
 * Determines the weekday of the given date.
 * @param day
 * @param month
 * @param firstWeekday weekday of the first day of the year
 * @return weekday of the given date
 */

unsigned determineWeekday( unsigned daysInMonth[], unsigned firstWeekday, unsigned day, unsigned month ) {
    // *** TODO ***
    unsigned weekday = 0;
    unsigned DayInYear = determineDayInYear(daysInMonth, day, month);
    weekday = (firstWeekday + DayInYear - 1) % 7;
    return weekday;
}


/**
 * Determines the calendar week of a day.
 * @param day_in_year
 * @param weekday_1jan
 * @return calendar week of a day
 */
unsigned determineCalenderWeek (unsigned day_in_year, unsigned weekday_1jan ) {
    // *** TODO ***
    int calenderweek = (day_in_year / 7) + 1;
    return calenderweek;
}


// ==========================

int main(void) {
    // considered date
    unsigned day, month, year;

    // days per month (in normal years, not leap years)
    // first entry (0) is basically useless but indexing is then easier: 1->Jan, 2->Feb, ...
    unsigned daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("\n\nProgramm zur Berechnung von Wochentagen\n");
    printf("----------------------------------------\n");

    // ----------

    // ask user for a date
    printf("Bitte geben Sie das Datum ein [TT.MM.JJJJ]: ");
    scanf("%d.%d.%d", &day, &month, &year);

    // check if date is a leap year
    unsigned leapYear = isLeapYear(year);

    // if this is a leap year, adjust array above
    if (leapYear) {
        daysInMonth[2] = 29;
    }

    // check if date is valid
    if (!isValidDate(daysInMonth, day, month)) {
        printf("Das eingegebene Datum existiert nicht.\n");
        return 1;
    }

    // ----------

    if (leapYear)
        printf("Das Jahr %u in ein Schaltjahr.\n", year);
    else
        printf("Das Jahr %u in KEIN Schaltjahr.\n", year);

    // determine the weekday of the 1 Jan
    //unsigned weekday1Jan = determineWeekdayOfFirstDay(year);
    unsigned weekday1Jan = determineWeekdayOfJan01(year);
    printf("Der 01. Januar %04u ist ein ", year);
    printWeekday(weekday1Jan);
    printf("\n");

    // determine which day of year the given day is
    unsigned dayInYear = determineDayInYear(daysInMonth, day, month);
    printf("Der %02u.%02u.%04u ist:\n- der %u. Tag des Jahres", day, month, year, dayInYear);

    // determine the week day
    unsigned weekday = determineWeekday(daysInMonth, weekday1Jan, day, month);
    printf("\n- ein ");
    printWeekday(weekday);

    // bestimme Kalenderwoche
    unsigned week = determineCalenderWeek(dayInYear, weekday1Jan);
    printf("\n- in Kalenderwoche %u", week);
    printf("\n");

    return 0;
}
