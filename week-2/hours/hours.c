#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int total_hours(int hours[], int weeks);
float avg_hours(int hours[], int weeks);
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    } while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    if (output == 'T')
    {
        return total_hours(hours, weeks);
    }
    else if (output == 'A')
    {
        return avg_hours(hours, weeks);
    }
}

int total_hours(int hours[], int weeks)
{
    int total;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }
    return total;
}

float avg_hours(int hours[], int weeks)
{
    int total = total_hours(hours, weeks);
    return (float)total / weeks;
}
