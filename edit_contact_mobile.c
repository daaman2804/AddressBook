#include "declarations.h"

void Edit_Contact_Mobile(struct AddressBook *addressbook, char new_mob[], int index)
{
    strcpy(addressbook->contacts[index].mobile, new_mob);
}
