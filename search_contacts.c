#include "declarations.h"

void Search_Contacts(struct AddressBook *addressbook)
{
    if (addressbook->contactCount == 0)
    {
        printf("No Contacts Available to search!!\n");
    }

    else
    {
        int flag = 1;
        do
        {
            int option = 1;
            printf("\n1. Search By Name\n");
            printf("2. Search By Mobile\n");
            printf("3. Search By Email ID\n");
            printf("4. Exit\n");
            printf("How You Would Like to Search: ");
            scanf("%d", &option);
            getchar();
            switch (option)
            {
            case 1:
                // Search By Name
                {
                    char name[30];
                    printf("Enter Name to Search: ");
                    scanf("%[^\n]", name);
                    getchar();

                    // If Valid Name then only move forward
                    if (Name_Checker(name))
                    {
                        Search_By_Name(addressbook, name);
                    }
                    else
                    {
                        printf("Invalid Name!!\n");
                    }
                    break;
                }

            case 2:
                // Search By Mobile
                {
                    char mob[12];
                    printf("Enter Mobile Number to Search: ");
                    scanf("%[^\n]", mob);
                    getchar();

                    // If Valid Mobile Number then only move forward
                    if (Search_Mobile_Checker(mob))
                    {
                        Search_By_Mobile(addressbook, mob);
                    }

                    else
                    {
                        printf("Invalid Mobile Number!!\n");
                    }
                    break;
                }

            case 3:
                // Search By Email
                {
                    char email[30];
                    printf("Enter Email ID to search: ");
                    scanf("%[^\n]", email);
                    getchar();

                    if (Search_Email_Checker(email))
                    {
                        Search_By_Email(addressbook, email);
                    }

                    else
                    {
                        printf("Invalid Email ID!!\n");
                    }
                    break;
                }

            case 4:
                // Exit
                flag = 0;
                break;

            default:
                printf("Invalid Input!!");
                break;
            }
        } while (flag);
    }
}
