#include <stdio.h>
#include <time.h>
#include "clock.h"

static const char *months[] = {
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

static const char *weekdays[] = {
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday", "Friday",
    "Saturday"
};

int get_current_date(DateInfo *date)
{
    if (!date)
        return -1;

    time_t now = time(NULL);
    if (now == (time_t)-1)
        return -1;

    struct tm *current = localtime(&now);
    if (!current)
        return -1;

    date->day = current->tm_mday;
    date->month = current->tm_mon + 1;
    date->year = current->tm_year + 1900;
    date->weekday = current->tm_wday;

    snprintf(date->month_name, sizeof(date->month_name),
             "%s", months[current->tm_mon]);

    snprintf(date->weekday_name, sizeof(date->weekday_name),
             "%s", weekdays[current->tm_wday]);

    return 0;
}
