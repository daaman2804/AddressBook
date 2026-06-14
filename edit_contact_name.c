#include "declarations.h"

void Edit_Contact_Name(struct AddressBook *addressbook, char new_name[], int index)
{
    // We cannot just assign new_name char array to old name array
    // So we copy new name to old name character
    strcpy(addressbook->contacts[index].name, new_name);
}
