#include "declarations.h"

int Name_Checker(char name[])
{
    char *ptr = name;
    int space_count = 0; // Max 1 space would be allowed

    // Name should not start with a space(If first character is space then dont accept the name
    if (ptr[0] == ' ')
        return 0;

    // Tackling Spaces And non alpha chars
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        // If current char is space
        if (ptr[i] == ' ')
        {
            space_count++;
            if (space_count > 1)
                return 0;
        }

        // If current char is non space then check if its an alpha or not
        // If character is a non alphabet then it returns 0 and by !0 we make it true to terminate and reject the string
        else if (!(isalpha(ptr[i])))
            return 0;
    }
    return 1;
}
