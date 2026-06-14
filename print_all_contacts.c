#include "declarations.h"

void Print_All_Contacts(struct AddressBook *addressbook)
{
    if (addressbook->contactCount == 0)
    {
        printf("No Contacts Available!!\n");
    }

    else
    {
        int flag = 1;
        do
        {
            printf("\n1. In Sorted Order by Name\n");
            printf("2. In Sorted Order by Mobile\n");
            printf("3. In Sorted Order by Email\n");
            printf("4. Exit\n");
            printf("\nHow Would You Like to see contacts??: ");
            int option;
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                // Sorted Order By Name
                Sort_By_Name(addressbook);
                Print_Full_Struct(addressbook);
                break;

            case 2:
                // Sorted Order by Mobile
                Sort_By_Mob(addressbook);
                Print_Full_Struct(addressbook);
                break;

            case 3:
                // Sorted Order by Email
                Sort_By_Email(addressbook);
                Print_Full_Struct(addressbook);
                break;

            case 4:
                // Exit from this
                flag = 0;
                break;

            default:
                printf("Invalid Option!!");
            }

        } while (flag);
    }
}