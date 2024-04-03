////////////////////////////////////////////////////////////////////////
//
// File          			: p2support.h
// Description    			: Headers of general-purpose utility functions 
//					          we use for the 257 project #2.
// Author					: Esha Sharma 
// Date						: 11/10 3:36 pm
// Notes					:
////////////////////////////////////////////////////////////////////////
#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE the email below to your vcu email
#define user_email "esharma@mail.com"
//add other define Macros as needed

struct Email
{	char sender[ADRESS_SIZE];
	char receiver[ADRESS_SIZE];
	char subject[SUBJECT_SIZE];
	char body[BODY_SIZE];
	struct sent_date
	{
		int month; 
		int day; 
		int year;
	} date ;
	int ID; 
	//add other struct members as needed
	//consider adding a nested struct here


}; 


struct Mailbox
{
	int size;
	struct Email* emails;
	//add other struct members as needed

};

//////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the .h file
//////////////////////////////////////////////////////////////////////////
//
// Function		: initialize 
// Description		: Initializes the database for CMSC257 project #2 by manually entering the records using create_email function
// Inputs		: struct Mailbox* - pointer to the database
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: create_email
// Description		: Initializes the database for CMSC257 project #2 by manually entering the records using create_email function
// Inputs		: char arrays (strings): mysender, myreceiver, sub, bd, integers: mon, d, yr, and  struct Mailbox* - pointer to the database
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: display_inbox_menu 
// Description		: Display the interactive main menu that will be used to navigate the email client. 
// Inputs		: struct Mailbox* - pointer to the database
// Outputs		: int
//////////////////////////////////////////////////////////////////////////
//
// Function		: show_inbox 
// Description		: Prints out the emails in the inbox
// Inputs		: struct Mailbox* - pointer to the database
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: show_email_by_ID
// Description		: Prints out the email that matches with the given email ID
// Inputs		: struct Mailbox* - pointer to the database, integer newID
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: sort_inbox_by_sender
// Description		: Sorts the emails lexicographically by the sender's email address
// Inputs		: struct Mailbox* - pointer to the database
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: sort_inbox_by_ID
// Description		: Sort the emails by ID, lower to higher ID numbers
// Inputs		: struct Mailbox* - pointer to the database
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: search_inbox_by_kwrd
// Description		: Searches the inbox and displays all the emails including the given string keyword in the sender, subject, or body fields
// Inputs		: struct Mailbox* - pointer to the database, pointer to string keyword
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: delete
// Description		: Deletes the email that matches with the given email ID, prints a message and the ID number of deleted email and prints a message if the email with the given ID does not exist
// Inputs		: struct Mailbox* - pointer to the database, integer newID
// Outputs		: void
//////////////////////////////////////////////////////////////////////////
//
// Function		: string_cmp
// Description		: Comparator function that compares two sender email address inputs and returns an integer
// Inputs		: const void *a, const void *b
// Outputs		: int
//////////////////////////////////////////////////////////////////////////
//
// Function		: int_cmp
// Description		: Comparator function that compares two email ID inputs and returns an integer indicating which one is bigger
// Inputs		: const void *a, const void *b
// Outputs		: int
///////////////////////////////////////////////////////////////////////////

void initialize(struct Mailbox* ib);

void create_email(char mysender[], char myreceiver[], char sub[], char bd[], int mon, int d, int yr, struct Mailbox* ib);

int display_inbox_menu(struct Mailbox* ib);

void show_inbox(struct Mailbox* ib);

void show_email_by_ID(struct Mailbox* ib, int newID);

void sort_inbox_by_sender(struct Mailbox* ib);

int string_cmp(const void *a, const void *b); 

void sort_inbox_by_ID(struct Mailbox* ib);

int int_cmp(const void *a, const void *b); 

void search_inbox_by_kwrd(struct Mailbox* ib, char *keyword);

void delete_email(struct Mailbox* ib, int newID);

//add other function declarations as needed
