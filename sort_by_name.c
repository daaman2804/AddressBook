#include "declarations.h"

void Sort_By_Name(struct AddressBook *addressbook)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        for (int j = 0; j < addressbook->contactCount - i - 1; j++)
        {
            // If First string is smaller than second then it would return -ve value
            // SO then only swap
            int res = strcmp(addressbook->contacts[j].name, addressbook->contacts[j + 1].name);
            if (res > 0)
            {
                struct Contact temp = addressbook->contacts[j];
                addressbook->contacts[j] = addressbook->contacts[j + 1];
                addressbook->contacts[j + 1] = temp;
            }
        }
    }
}
