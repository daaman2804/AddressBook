#include "declarations.h"

void Add_Contact(struct AddressBook *addressbook)
{
    int name_flag = 1;
    do
    {
        printf("Enter Your Name: ");
        scanf("%[^\n]", addressbook->contacts[addressbook->contactCount].name);
        getchar();

        if (Name_Checker(addressbook->contacts[addressbook->contactCount].name))
            name_flag = 0;

        else
            printf("Invalid Name!! Pls Try Again!!\n");

    } while (name_flag);

    int mob_flag = 1;
    do
    {
        printf("Enter Your Mobile Number: ");
        scanf("%[^\n]", addressbook->contacts[addressbook->contactCount].mobile);
        getchar();

        if (Mobile_Checker(addressbook->contacts[addressbook->contactCount].mobile, addressbook))
            mob_flag = 0;

    } while (mob_flag);

    int email_flag = 1;
    do
    {
        printf("Enter Your Email ID: ");
        scanf("%[^\n]", addressbook->contacts[addressbook->contactCount].email_id);
        getchar();

        if (Email_Checker(addressbook->contacts[addressbook->contactCount].email_id, addressbook))
            email_flag = 0;
    } while (email_flag);

    // After successful data collection of all contact fields, update count
    printf("\nContact Added Successfully!!\n");
    addressbook->contactCount++;
}
