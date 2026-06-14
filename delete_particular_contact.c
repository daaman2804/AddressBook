#include "declarations.h"

void Delete_Particular_Contact(struct AddressBook *addressbook, int index)
{
    int k = 0;
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (i != index)
        {
            addressbook->contacts[k++] = addressbook->contacts[i];
        }
    }

    // Decrementing Contact Count Counter
    addressbook->contactCount = k;
}