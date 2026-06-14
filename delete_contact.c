#include "declarations.h"

void Delete_Contact(struct AddressBook *addressbook)
{
    if (addressbook->contactCount == 0)
    {
        printf("No Contact Available!!\n");
    }

    else
    {
        int flag = 1;
        do
        {
            int option;
            printf("\n1. Delete By Name \n");
            printf("2. Delete By Mobile \n");
            printf("3. Delete By Email \n");
            printf("4. Exit\n");
            printf("Enter Your Choice: ");
            scanf("%d", &option);
            getchar();

            switch (option)
            {
            case 1:
            {
                // Delete By Name
                int name_flag = 1;
                do
                {
                    char name[30];
                    printf("Enter the Name: ");
                    scanf("%[^\n]", name);
                    getchar();

                    // If name is valid then only continue
                    if (Name_Checker(name))
                    {
                        int index = Find_Index_By_Name(addressbook, name);
                        if (index != -1 && index != -2)
                        {
                            // Now Delete it
                            Delete_Particular_Contact(addressbook, index);
                            printf("Contact Deleted Successfully!!\n");
                            name_flag = 0;
                        }
                        else if (index == -2)
                        {
                            printf("Duplicate Contacts found.\n");
                            printf("Enter Email or Mobile to identify\n");
                            printf("1. Enter Mobile Number\n");
                            printf("2. Enter Email ID\n");
                            int choice;
                            printf("Enter Your Choice: ");
                            scanf("%d", &choice);
                            getchar();

                            switch (choice)
                            {
                            case 1:
                            {
                                int mob_flag = 1;
                                do
                                {
                                    char mob[12];
                                    printf("Enter Mobile Number: ");
                                    scanf("%[^\n]", mob);
                                    getchar();

                                    // If valid mobile number
                                    if (Search_Mobile_Checker(mob))
                                    {
                                        int index = Find_Index_By_Mobile(addressbook, mob);
                                        Delete_Particular_Contact(addressbook, index);
                                        printf("\nContact Deleted\n");
                                        mob_flag = 0;
                                    }

                                    else
                                        printf("Enter Valid Mobile Number\n");

                                } while (mob_flag);

                                break;
                            }

                            case 2:
                            {
                                int email_flag = 1;
                                do
                                {
                                    char email[30];
                                    printf("Enter Email ID: ");
                                    scanf("%[^\n]", email);
                                    getchar();

                                    // If valid email ID
                                    if (Search_Email_Checker(email))
                                    {
                                        int index = Find_Index_By_Email(addressbook, email);
                                        Delete_Particular_Contact(addressbook, index);
                                        printf("Contact Deleted\n");
                                        email_flag = 0;
                                    }

                                    else
                                        printf("Enter Valid Email ID\n");
                                } while (email_flag);
                            }

                            default:
                                printf("Invalid Option\n");
                                break;
                            }
                        }

                        else
                        {
                            printf("No Contacts found\n");
                        }
                        name_flag = 0;
                    }
                    else
                    {
                        printf("Enter Valid Name!!\n");
                    }
                } while (name_flag);

                break;
            }

            case 2:
            {
                // Delete By Mobile Number
                int mob_flag = 1;
                do
                {
                    char mob[12];
                    printf("Enter Mobile Number: ");
                    scanf("%[^\n]", mob);
                    getchar();

                    // If Mobile Number is Valid then only continue
                    if (Search_Mobile_Checker(mob))
                    {
                        int index = Find_Index_By_Mobile(addressbook, mob);

                        if (index != -1)
                        {
                            // Delete
                            Delete_Particular_Contact(addressbook, index);
                            printf("Contact Deleted Successfully!!\n");
                        }

                        else
                        {
                            printf("No Contact Found\n");
                        }
                        mob_flag = 0;
                    }
                    else
                    {
                        printf("Enter Valid Mobile Number!!\n");
                    }
                } while (mob_flag);

                break;
            }

            case 3:
            {
                // Delete By Email ID
                int email_flag = 1;
                do
                {
                    char email[30];
                    printf("Enter Email ID: ");
                    scanf("%[^\n]", email);
                    getchar();

                    // If Email is valid then only continue
                    if (Search_Email_Checker(email))
                    {
                        int index = Find_Index_By_Email(addressbook, email);

                        if (index != -1)
                        {
                            // Delete
                            Delete_Particular_Contact(addressbook, index);
                            printf("Contact Deleted Successfully!!\n");
                        }

                        else
                        {
                            printf("No Contacts Found\n");
                        }
                        email_flag = 0;
                    }

                    else
                    {
                        printf("Enter Valid Email ID!!\n");
                    }
                } while (email_flag);

                break;
            }

            case 4:
                flag = 0;

            default:
                printf("Invalid Option!!\n");
                break;
            }
        } while (flag);
    }
}
