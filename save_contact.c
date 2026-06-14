#include "declarations.h"

int Save_Contact(struct AddressBook *addressbook)
{
    // Open the file in write mode
    FILE *fp = fopen("contacts.csv", "w");

    // Safety check
    if (fp == NULL)
    {
        return 1;
    }

    // Filling the file with all contents of struct
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n", addressbook->contacts[i].name, addressbook->contacts[i].mobile, addressbook->contacts[i].email_id);
    }

    // Closing the file
    fclose(fp);

    return 0;
}
