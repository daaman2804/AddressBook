#include "declarations.h"
int Search_Email_Checker(char email[])
{
    int digit_flag = 0;
    int at_the_rate_flag = 0;
    int dot_flag = 0;

    char *at_ptr = strchr(email, '@');
    char *dot_ptr = strchr(email, '.');

    // If character is upper case then immediately reject it
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (isupper(email[i]) != 0)
        {
            printf("Error: Upper Case Characters not allowed in Email ID!!\n");
            return 0;
        }
    }

    // Checking for '@' and '.'
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            at_the_rate_flag = 1;

        if (email[i] == '.')
            dot_flag = 1;
    }

    if ((at_the_rate_flag && dot_flag) != 1)
    {
        printf("Error: Either '.' or '@' is not present in the given email!!\n");
        return 0;
    }

    // Position check for @ and .
    if (at_ptr == email)
    {
        printf("Error: Cannot start with @\n");
        return 0;
    }

    // Ends with '.'
    if (*(dot_ptr + 1) == '\0')
    {
        printf("Error: Email cannot end with .\n");
        return 0;
    }

    // If dot comes before @
    if (dot_ptr < at_ptr)
    {
        printf("Error: '.' must be after '@'\n");
        return 0;
    }

    // If both are consecutive to each other
    if (dot_ptr == at_ptr + 1)
    {
        printf("Error: Invalid Domain\n");
        return 0;
    }

    // Check for digits
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (isdigit(email[i]))
        {
            digit_flag = 1;
            break;
        }
    }

    if (digit_flag == 0)
    {
        printf("Error: Email should also contain some digits!!\n");
        return 0;
    }

    return 1;
}