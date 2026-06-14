/*
	Name		: DAAMAN PATEL
	Date		: 25-04-2026
	Project		: Address Book Application in C
	Description	: Console-based address book to create, search, edit, delete, display and save contacts.
				  Each contact includes name, phone number and email.
				  Sorting is also supported by name, phone or email.
				  Created by using structures, FILE I/O and standard lib of C
	Sample I/O	: 
				  Choose Any Option: 1
				  Enter Your Name: Harry Kane
				  Enter Your Mobile Number: 9381819281
				  Enter Your Email ID: harry9@gmail.com
				  Contact Added Successfully!!

*/


#include "declarations.h"

int main(void)
{
	// Initialising Struct variable
	struct AddressBook addressbook;

	addressbook.contactCount = 0;

	// Loading all contacts from file
	if (Load_Contacts(&addressbook) == 1)
	{
		printf("Contact File cannot be opened\n");
		return 0;
	}
	else
	{
		printf("Contacts Loaded!!\n");
	}

	// Displaying Menu
	int flag = 1;
	do
	{
		printf("\n1. Add Contacts\n");
		printf("2. Print All Contacts\n");
		printf("3. Search Contact\n");
		printf("4. Delete Contact\n");
		printf("5. Edit Contact\n");
		printf("6. Save Contact\n");
		printf("7. Exit");

		int option;
		printf("\n\nChoose Any Option: ");
		scanf("%d", &option);
		getchar();

		switch (option)
		{
		case 1:
			// Add Contacts
			{
				Add_Contact(&addressbook);
				break;
			}

		case 2:
			// Print Contacts
			{
				Print_All_Contacts(&addressbook);
				break;
			}

		case 3:
			// Search Contact
			{
				Search_Contacts(&addressbook);
				break;
			}

		case 4:
			// Delete Contact
			{
				Delete_Contact(&addressbook);
				break;
			}

		case 5:
			// Edit Contact
			{
				Edit_Contact(&addressbook);
				break;
			}

		case 6:
			// Save Contact
			{
				int status = Save_Contact(&addressbook);
				if (status == 1)
				{
					printf("File Couldn't be opened or created\n");
				}
				printf("Contacts Saved Successfully\n");
				break;
			}

		case 7:
			printf("\nThank You!!\n");
			flag = 0;
			break;

		default:
			printf("Invalid Option!!\n");
			break;
		}
	} while (flag);
}