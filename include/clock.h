#ifndef CLOCK_H
#define CLOCK_H

typedef struct {
    int day;
    int month;
    int year;
    int weekday;
    char month_name[16];
    char weekday_name[16];
} DateInfo;

int get_current_date(DateInfo *date);

#endif
