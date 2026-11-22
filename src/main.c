#include <stdio.h>
#include "clock.h"

int main(void)
{
    DateInfo date;

    if (get_current_date(&date) != 0) {
        printf("Failed to read system date.\n");
        return 1;
    }

    printf("\n");
    printf("Today\n");
    printf("%s %d\n", date.month_name, date.year);
    printf("%s / %02d\n", date.weekday_name, date.day);
    printf("\n");

    return 0;
}
