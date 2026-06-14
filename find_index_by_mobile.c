#include "declarations.h"

int Find_Index_By_Mobile(struct AddressBook *addressbook, char mob[])
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(mob, addressbook->contacts[i].mobile) == 0)
            return i;
    }

    return -1; // If nothing found
}
