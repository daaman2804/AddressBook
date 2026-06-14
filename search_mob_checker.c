#include "declarations.h"

int Search_Mobile_Checker(char mob[])
{
    int count = 0;
    int i;
    for (i = 0; mob[i] != '\0'; i++)
    {
        // If character is non-digit then immediately reject it
        if (!(isdigit(mob[i])))
        {
            printf("Error: Invalid Number!!Pls Try Again!!\n");
            return 0;
        }

        // Otherwise normally count it
        count++;
    }

    // If digit count and i match then it is a valid 10 digit mobile number
    if (!(i == 10 && count == 10))
    {
        printf("Error: Invalid Number!!Pls Try Again!!\n");
        return 0;
    }

    return 1;
}
