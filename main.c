#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    SYSTEMTIME t; // Declare SYSTEMTIME struct
    GetLocalTime(&t); // Fill out the struct so that it can be used
    const int YEAR = t.wYear;

    char new_person;
    const char NATIONALITY[10] = "GHANANIAN";
    char fname[100], lname[100];
    char Gender[2];
    char town [100];
    int day, month, year;

    do {
             /* Get user's details*/
        printf("Firstname: ");
        scanf("%s", &fname);
        printf("Surname: ");
        scanf("%s", &lname);
        printf("Enter You Date of Birth - Day: ");
        scanf("%d", &day);
        printf("Month: ");
        scanf("%d", &month);
        printf("Year: ");
        scanf("%d", &year);
        printf("Location: ");
        scanf("%s", &town);
        printf("Gender (M/F): ");
        scanf("%s", Gender);


        if (YEAR - year >= 18)
        {
            /** User is old enough to vote */
            srand(time(NULL));
            printf("Thank you for making the right choice to be a good citizen by getting a voter ID card.\nHere are your card details\n");
            printf("Fullname: %s %s\n", fname, lname);
            printf("Gender: %s\n", Gender);
            printf("Nationality: %s\n", NATIONALITY);
            printf("Date of birth: %d-%d-%d\n", day, month, year);
            /* Print ID number */
            int id_number_length;
            printf("ID No: ");
            for (id_number_length = 10; id_number_length > 0; id_number_length--)
            {
                int random_number = rand() % 9 + 1;
                printf("%d", random_number);
            }
            printf("\n");
            printf("Polling Center: %s\n", town);
            printf("Expiration date: %d\n", YEAR + 10);
        } else {
            /** User is not old enough to vote */
            int age = YEAR - year;
            int year_to_try_again = 18 - age;
            printf("Sorry %s\nYou are not eligible to vote yet, try again in %d years time", fname, year_to_try_again);
        }

        printf("\n");
        char still_on[3];

        /** check for any other user, to do a new registration*/
        printf("Any one else want to register? y/n: ");
        scanf("%s", still_on);

        if (strcmp(still_on, "y") == 0)
        {
             new_person = true;
        } else
        {
            goto stop;
        }


    } while (new_person);


    stop:
        printf("Thank you for getting your card. See you at the next election\n\n");


    return 0;
}
