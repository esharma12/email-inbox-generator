//////////////////////////////////////////////////////////////////////////
//
// File		: cmsc257-f21-p2.c
// Description	: This is a part of the starter code for CMSC 257
//
//
// Author	: Esha Sharma 
// Last Modified: 11/09 10:08 AM
//

#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"

int main() {
	struct Mailbox* ib;
	ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
	initialize(ib);
	display_inbox_menu(ib);
	free (ib);
	return 0;
}
