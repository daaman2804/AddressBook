#include "declarations.h"

int Load_Contacts(struct AddressBook *addressbook)
{
    // Opening file
    FILE *fp = fopen("contacts.csv", "r");

    // Safety Check
    if (fp == NULL)
    {
        return 1;
    }

    // Reading content from file and one by one filling it into struct
    while (fscanf(fp, " %[^,],%[^,],%[^\n]",
                  addressbook->contacts[addressbook->contactCount].name,
                  addressbook->contacts[addressbook->contactCount].mobile,
                  addressbook->contacts[addressbook->contactCount].email_id) == 3)
    {
        // Increment the contact count as 1 contact is stored
        addressbook->contactCount++;
    }

    // Closing the file
    fclose(fp);

    return 0;
}