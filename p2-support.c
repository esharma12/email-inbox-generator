//////////////////////////////////////////////////////////////////////////
//
// File			: p2-support.c
// Description		: This is a set of general-purpose utility functions we use for the 257 project #2.
//
// Author		: Esha Sharma 
// Date			: 11/10 2:21 PM
// Notes		:
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"

//////////////////////////////////////////////////////////////////////////
// Function Definitions
//////////////////////////////////////////////////////////////////////////



void initialize (struct Mailbox *ib) 
{
	//allocate memory for 2000 emails
	ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
	ib->size = 0;

	create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.", "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.", 11,20,2020, ib);
	create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!", 11,30,2020, ib);
	create_email ("dboyle@mail.com", user_email, "3rd email!", "Alright, time for another email for your inbox. Not going to lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!", 12,2,2020, ib);
	create_email ("cbluer@mail.com", user_email, "4th email!", "Content of fourth email. More coding, more fun!", 12,8,2020, ib);
	create_email ("cboyle@mail.com", user_email, "5th email!", "Content of fifth email. Coding is fun-tastic!", 12,18,2020, ib);
	create_email ("sblack@mail.com", user_email, "6th email!", "Content of sixth email. Coding is fun-tastic!", 1,1,2021, ib);
	create_email ("sblack@mail.com", user_email, "7th email!", "Body of seventh email. Coding is fun-tastic!", 1,5,2021, ib); 
	create_email ("sblack@mail.com", user_email, "8th email!", "Body of eighth email. Coding is fun-tastic!", 2,15,2021, ib);
	create_email ("sblack@mail.com", user_email, "9th email!", "Body of ninth email. Coding is fun-tastic!", 2,25,2021, ib);
	create_email ("dboyle@mail.com", user_email, "Last email!", "Body of tenth email. Coding is fun-tastic!", 3,15,2021, ib);

}
void create_email(char mysender[], char myreceiver[], char sub[], char bd[], int mon, int d, int yr, struct Mailbox* ib) {
	static int newID = 0; 
	strcpy((ib->emails[newID].sender), mysender);
	strcpy((ib->emails[newID].receiver), myreceiver);
	strcpy((ib->emails[newID].subject), sub);
	strcpy((ib->emails[newID].body), bd);
	ib->emails[newID].date.month = mon; 
	ib->emails[newID].date.day = d;
	ib->emails[newID].date.year = yr; 
	ib->emails[newID].ID = newID;
	newID++;
	ib->size++;

}

int display_inbox_menu(struct Mailbox* ib) {
	int choice, ID1, ID2;
	char keyword[11];
	while (1) {
		printf("\n");
		printf("***************    ESHARMA INBOX    ***************\n");
		printf("***************  Total Inbox: %04d  ***************\n", ib->size);
		printf("\n");
		printf("1. Show Inbox\n2. Show Email by ID\n3. Sort Inbox by Sender\n4. Sort Inbox by ID\n5. Search Inbox by Keyword\n6. Delete\n7. Exit Inbox\n");
		printf("\n");

		scanf("%d", &choice);

		switch (choice) {
			case 1:
				show_inbox(ib);
				break;
			case 2:
				printf("Enter the ID of the email you want to read:\n");
				scanf("%d", &ID1);
				show_email_by_ID(ib, ID1);
				break;
			case 3:
				sort_inbox_by_sender(ib);
				break;
			case 4:
				sort_inbox_by_ID(ib);
				break;
			case 5:
				printf("Enter the keyword you are searching for:\n");
				scanf("%s", keyword);	
				search_inbox_by_kwrd(ib, keyword);
				break;
			case 6:
				printf("Enter the ID of the e-mail you want to delete:\n");
				scanf("%d", &ID2);
				delete_email(ib, ID2);
				break;
			case 7:
				printf("Exiting e-mail client - Good Bye!\n");
				free (ib->emails);
				return 0;
				break;
		}		
	}
}


void show_inbox(struct Mailbox* ib) {
	int i;
	printf("\n"); 
	printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   --------------------   --/--/----   ---------------\n");
	for(i = 0; i < ib->size; i++) {
		printf("%02d - %-20s - %02d/%02d/%04d - %-15s\n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject); 

	}
}


void show_email_by_ID(struct Mailbox* ib, int newID) {
	int i; 
	printf("\n");
	for(i = 0; i < ib->size; i++) {
		if(ib->emails[i].ID == newID) {
			printf("%s - %s\n", ib->emails[i].sender, ib->emails[i].subject);
			printf("Email Received on: %02d/%02d/%04d\n", ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year);
			printf("\n\n");
			printf("%s\n", ib->emails[i].body);

		}
	}	
}


void sort_inbox_by_sender(struct Mailbox* ib) {
	qsort(ib->emails, ib->size, sizeof(struct Email), string_cmp);	
}

int string_cmp(const void *a, const void *b) {
	const struct Email *e1 = (struct Email *)a;
	const struct Email *e2 = (struct Email *)b;
	return strcmp(e1->sender, e2->sender);
}

void sort_inbox_by_ID(struct Mailbox* ib) {
	qsort(ib->emails, ib->size, sizeof(struct Email), int_cmp);
}

int int_cmp(const void *a, const void *b) {
	const struct Email *e3 = (struct Email *)a;
	const struct Email *e4 = (struct Email *)b;
	return e3->ID - e4->ID;
}
void search_inbox_by_kwrd(struct Mailbox* ib, char *keyword) {
	int i; 
	printf("\n"); 
	printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   --------------------   --/--/----   ---------------\n");
	for(i = 0; i < ib->size; i++) {
		if((strstr(ib->emails[i].sender, keyword) != NULL) || (strstr(ib->emails[i].subject, keyword) != NULL) || (strstr(ib->emails[i].body, keyword) != NULL)) {
			printf("%02d - %-20s - %02d/%02d/%04d - %-15s\n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject); 
		}
	}
}


void delete_email(struct Mailbox* ib, int newID) {
	int i, index = -1;
	for(i = 0; i < ib->size; i++) {
		if(ib->emails[i].ID == newID) {
			index = i; 
			break;
		}
	}
	if(index != -1) {
		for(i = index; i < ib->size - 1; i++) {
			ib->emails[i] = ib->emails[i+1];
		}
		ib->size--;
		printf("Email with ID = %d is deleted\n", newID);
	}
	else {
		printf("Email with ID = %d does not exist\n", newID);
	}

}	
