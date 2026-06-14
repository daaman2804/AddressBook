#include "declarations.h"

int Mobile_Checker(char mob[], struct AddressBook *addressbook)
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

    // Now Check for uniqueness, if current number matches to any number from other data then reject it
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(mob, addressbook->contacts[i].mobile) == 0)
        {
            // Match is found so reject it
            printf("Error: Number Already Exists!!\n");
            return 0;
        }
    }

    return 1;
}
