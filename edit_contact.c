#include "declarations.h"

void Edit_Contact(struct AddressBook *addressbook)
{
    if (addressbook->contactCount == 0)
    {
        printf("No Contacts Found\n");
    }

    else
    {
        int flag = 1;
        do
        {
            printf("1. Edit Name\n");
            printf("2. Edit Mobile\n");
            printf("3. Edit Email ID\n");
            printf("4. Exit\n");
            printf("Enter Choice: ");
            int option;
            scanf("%d", &option);
            getchar();

            switch (option)
            {
            case 1:
                // Edit name
                {
                    int name_flag = 1;
                    do
                    {
                        char old_name[30];
                        printf("Enter Old Name that u entered before: ");
                        scanf("%[^\n]", old_name);
                        getchar();

                        if (Name_Checker(old_name))
                        {
                            // If name is valid then only move forward
                            // Now here we will get the index from old name
                            int index = Find_Index_By_Name(addressbook, old_name);

                            if (index != -1 && index != -2)
                            {
                                // Now we can ask for new name
                                int new_name_flag = 1;
                                do
                                {
                                    char new_name[30];
                                    printf("Enter New Name: ");
                                    scanf("%[^\n]", new_name);
                                    getchar();

                                    if (Name_Checker(new_name))
                                    {
                                        // If name is valid then only perform updation
                                        Edit_Contact_Name(addressbook, new_name, index);
                                        printf("\nContact Updated Successfully!!\n");
                                        new_name_flag = 0;
                                    }

                                    else
                                    {
                                        printf("Enter Valid Name!!\n");
                                    }
                                } while (new_name_flag);
                            }

                            // Duplicate Names Found
                            else if (index == -2)
                            {
                                printf("Duplicate Contacts found.\n");
                                printf("Enter Email or Mobile Number to identify\n");
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
                                            if (index != -1)
                                            {
                                                int new_name_flag = 1;
                                                do
                                                {
                                                    char new_name[30];
                                                    printf("Enter New Name: ");
                                                    scanf("%[^\n]", new_name);
                                                    getchar();

                                                    if (Name_Checker(new_name))
                                                    {
                                                        Edit_Contact_Name(addressbook, new_name, index);
                                                        printf("\nContact Updated\n");
                                                        new_name_flag = 0;
                                                        mob_flag = 0;
                                                    }
                                                    else
                                                    {
                                                        printf("Enter Valid Name\n");
                                                    }
                                                } while (new_name_flag);
                                            }

                                            else
                                            {
                                                printf("No Contact Found of such number\n");
                                            }
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

                                        // If valid email id
                                        if (Search_Email_Checker(email))
                                        {
                                            int index = Find_Index_By_Email(addressbook, email);
                                            if (index != -1)
                                            {
                                                int new_name_flag = 1;
                                                do
                                                {
                                                    char new_name[30];
                                                    printf("Enter New Name: ");
                                                    scanf("%[^\n]", new_name);
                                                    getchar();
                                                    if (Name_Checker(new_name))
                                                    {
                                                        Edit_Contact_Name(addressbook, new_name, index);
                                                        printf("\nContact Updated\n");
                                                        email_flag = 0;
                                                        new_name_flag = 0;
                                                    }
                                                    else
                                                    {
                                                        printf("Enter Valid Name\n");
                                                        new_name_flag = 0;
                                                    }
                                                } while (new_name_flag);
                                            }

                                            else
                                                printf("No Contact found of this Email ID\n");
                                        }

                                        else
                                            printf("Enter Valid Email ID\n");
                                    } while (email_flag);

                                    break;
                                }

                                default:
                                    printf("Invalid Input\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("No Contact Found of this name!!\n");
                            }
                            name_flag = 0;
                        }

                        else
                            printf("Enter Valid Name!!\n");

                    } while (name_flag);

                    break;
                }

            case 2:
                // Edit Mobile
                {
                    int mob_flag = 1;
                    do
                    {
                        char old_number[30];
                        printf("Enter Old Mobile Number that u entered before: ");
                        scanf("%[^\n]", old_number);
                        getchar();

                        if (Search_Mobile_Checker(old_number))
                        {
                            // If number is valid then only move forward
                            // Now here we will get the index from old number
                            int index = Find_Index_By_Mobile(addressbook, old_number);

                            if (index != -1)
                            {
                                // Now we can ask for new mobile number
                                int new_mob_flag = 1;
                                do
                                {
                                    char new_mob[30];
                                    printf("Enter New Mobile Number: ");
                                    scanf("%[^\n]", new_mob);
                                    getchar();

                                    if (Search_Mobile_Checker(new_mob))
                                    {
                                        // If number is valid then only perform updation
                                        Edit_Contact_Mobile(addressbook, new_mob, index);
                                        printf("\nContact Updated Successfully!!\n");
                                        new_mob_flag = 0;
                                    }
                                    else
                                    {
                                        printf("Enter Valid Mobile Number!!\n");
                                    }
                                } while (new_mob_flag);
                            }
                            else
                            {
                                printf("No Contact Found of this number!!\n");
                            }
                            mob_flag = 0;
                        }

                        else
                            printf("Enter Valid Mobile Number!!\n");

                    } while (mob_flag);

                    break;
                }

            case 3:
                // Edit Email
                {
                    int email_flag = 1;
                    do
                    {
                        char old_email[30];
                        printf("Enter Old Email ID that u entered before: ");
                        scanf("%[^\n]", old_email);
                        getchar();

                        if (Search_Email_Checker(old_email))
                        {
                            // If email is valid then only move forward
                            // Now here we will get the index from old email
                            int index = Find_Index_By_Email(addressbook, old_email);

                            if (index != -1)
                            {
                                // Now we can ask for new email ID
                                int new_email_flag = 1;
                                do
                                {
                                    char new_email[30];
                                    printf("Enter New Email ID: ");
                                    scanf("%[^\n]", new_email);
                                    getchar();

                                    if (Search_Email_Checker(new_email))
                                    {
                                        // If email is valid then only perform updation
                                        Edit_Contact_Email(addressbook, new_email, index);
                                        printf("\nContact Updated Successfully!!\n");
                                        new_email_flag = 0;
                                    }
                                    else
                                    {
                                        printf("Enter Valid Email ID!!\n");
                                    }
                                } while (new_email_flag);
                            }
                            else
                            {
                                printf("No Contact Found of this Email ID!!\n");
                            }
                            email_flag = 0;
                        }

                        else
                            printf("Enter Valid Email ID!!\n");

                    } while (email_flag);

                    break;
                }

            case 4:
                flag = 0;
                break;

            default:
                break;
            }
        } while (flag);
    }
}
