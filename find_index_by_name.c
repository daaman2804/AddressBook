#include "declarations.h"

int Find_Index_By_Name(struct AddressBook *addressbook, char name[])
{
    int count = 0;
    int index;
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(name, addressbook->contacts[i].name) == 0)
        {
            index = i;
            count++;
        }
    }

    if (count == 1)
        return index;

    // Duplicate contacts found
    else if (count > 1)
        return -2;

    return -1; // If nothing found
}
