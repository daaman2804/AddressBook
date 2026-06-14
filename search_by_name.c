#include "declarations.h"

void Search_By_Name(struct AddressBook *addressbook, char name[])
{
    int flag = 0;
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        int inner_flag = 0;
        if (strcmp(name, addressbook->contacts[i].name) == 0)
        {
            inner_flag = 1;
            flag = 1;
        }

        if (inner_flag)
        {
            printf("Name: %s\t\tMobile: %s\t\tEmail: %s\t\t\n", addressbook->contacts[i].name, addressbook->contacts[i].mobile, addressbook->contacts[i].email_id);
        }
    }

    if (flag == 0)
        printf("No Contact Found!!\n");
}
