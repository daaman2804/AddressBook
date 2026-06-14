#include "declarations.h"

void Print_Full_Struct(struct AddressBook *addressbook)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        printf("Name: %s\t\tMobile: %s\t\tEmail: %s\n", addressbook->contacts[i].name, addressbook->contacts[i].mobile, addressbook->contacts[i].email_id);
    }
}
