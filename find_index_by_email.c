#include "declarations.h"

int Find_Index_By_Email(struct AddressBook *addressbook, char email[])
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(email, addressbook->contacts[i].email_id) == 0)
            return i;
    }

    return -1; // If nothing found
}
