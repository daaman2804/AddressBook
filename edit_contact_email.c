#include "declarations.h"

void Edit_Contact_Email(struct AddressBook *addressbook, char new_email[], int index)
{
    strcpy(addressbook->contacts[index].email_id, new_email);
}