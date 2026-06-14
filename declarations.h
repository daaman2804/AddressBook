#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Contact
{
	char name[30];
	char mobile[12];
	char email_id[30];
};

struct AddressBook
{
	struct Contact contacts[100];
	int contactCount;
};

// Function Declarations
void Add_Contact(struct AddressBook *); 
void Print_All_Contacts(struct AddressBook *); 
void Sort_By_Name(struct AddressBook *); 
void Sort_By_Mob(struct AddressBook *); 
void Sort_By_Email(struct AddressBook *); 
void Print_Full_Struct(struct AddressBook *); 
void Search_Contacts(struct AddressBook *); 
void Search_By_Name(struct AddressBook *, char[]); 
void Search_By_Mobile(struct AddressBook *, char[]); 
void Search_By_Email(struct AddressBook *, char[]); 
void Delete_Contact(struct AddressBook *); 
int Find_Index_By_Name(struct AddressBook *, char[]); 
int Find_Index_By_Mobile(struct AddressBook *, char[]); 
int Find_Index_By_Email(struct AddressBook *, char[]); 
void Delete_Particular_Contact(struct AddressBook *, int); 
void Edit_Contact(struct AddressBook *); 
void Edit_Contact_Name(struct AddressBook *, char[], int); 
void Edit_Contact_Mobile(struct AddressBook *, char[], int); 
void Edit_Contact_Email(struct AddressBook *, char[], int); 
int Save_Contact(struct AddressBook *); 
int Load_Contacts(struct AddressBook *); 

// Validators Declarations
int Name_Checker(char[]); 
int Mobile_Checker(char[], struct AddressBook *); 
int Email_Checker(char[], struct AddressBook *); 
int Search_Mobile_Checker(char[]); 
int Search_Email_Checker(char[]);
#endif
