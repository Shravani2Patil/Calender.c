#include <stdio.h>

// Function to check leap year
int isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

int main() {
    int year, month, days, startDay = 0;
    int i;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Days in each month
    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Adjust February for leap year
    if (isLeapYear(year))
        monthDays[1] = 29;

    days = monthDays[month - 1];

    // Calculate starting day (Zeller-like logic)
    int y = year - 1;
    startDay = (y*365 + y/4 - y/100 + y/400) % 7;

    for (i = 0; i < month - 1; i++)
        startDay = (startDay + monthDays[i]) % 7;

    // Print calendar
    printf("\n Sun Mon Tue Wed Thu Fri Sat\n");

    for (i = 0; i < startDay; i++)
        printf("    ");

    for (i = 1; i <= days; i++) {
        printf("%4d", i);
        if ((i + startDay) % 7 == 0)
            printf("\n");
    }

    printf("\n");

    return 0;

}
