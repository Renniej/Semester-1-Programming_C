/* -------------------------------------------
Name:           
Student number: 
Email:          
Section:        
Date:           
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACT 5

#include <stdio.h>
#include <stdlib.h>// --- Reason stdlib.h is include is so I can convert strings to int values
#include <ctype.h>
#include <string.h>
#include "contactHelpers.h"




//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+


void FindN(char * String) { //Functions that finds if \n exist in a char array & changes it to \0,  Used when Fgets is called

							

	if ((strlen(String) > 0) && (String[strlen(String) - 1] == '\n')) { //
		String[strlen(String) - 1] = '\0';
	}

	//--------------------------------------------------------------------------------------
}

//I was having problems wih Fgets conflicting with the newline & clearing the input buffer wasn't working.
//Also when printing Contact information, I found some of the chars had a \n stored in them
// After some reasearch I foun the soluion below.
//Remove newline IF there is any -----Source: https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf


// clearKeyboard
void clearKeyboard(void)
{
	int i = 0;

	while (getchar() != '\n') {//clear input buffer
		i++;
	}

}


// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}



// getInt:
int getInt(void) {
	int ValidEntry; //Check for valid entry & eventually input as int
	char num[256]; // Input as string
	int length; // length of string



	do {

		ValidEntry = 1;//Valid entry is assumed true till proven false

		fgets(num, 256, stdin);

		FindN(num);

		length = strlen(num);

		//-------------------------------------------------------- I was orginally using atoi to determine if the user entered a string as input
		int i;												//     the problem with this is that atoi returns 0, which is actually a valid input used in the menu function
		for (i = 0; i < length; i++) {					//         After some research I came across the strtol function but had issues both understanding and getting the code to work
			if (    (!isdigit(num[i])) || num[i] == '-' )	// Finally I remembered that char num[] is an array  and I could possibly check if one of the array spots was a alphabet character or (-) negative symbol
			{											//         Now I would use atoi to check each character but once again it returns 0 (Valid input for menu options) when: 
											//         1. user inputs a alphabetical or 2. when the value inputted is 0
				ValidEntry = -1;  //Valid entry is proven false 
			}										    //         So after a little more research i came across the function isdigit which can check indiviudal char values to see if they hold an int value.
														//         After a tiny bit more searching I came across a function that was (almost) identical to that I was thinking.  (Sourced below)
		}												//  Source: https://stackoverflow.com/questions/17292545/how-to-check-if-the-input-is-a-number-or-not-in-c
														//  It returns invalid int even if the user enters 77x
														//---------------------------------------------------


		if (ValidEntry == -1) {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

		else
		{
			ValidEntry = atoi(num);
		}


	} while (ValidEntry == -1);

	return ValidEntry;

}

// getIntInRange:

int getIntInRange(int a, int b) {

	int c;

	do {
		c = getInt();

		if (c < a || c >b) {

			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);
		}

	} while (c < a || c > b);

	return c;
}

// yes:
int yes(void) {
	char input = ' ';
	char DCinput = ' '; //Double check to make sure user did not input string
	int value = -1;

	do {


		scanf("%c%c", &input, &DCinput);


		if (DCinput != '\n') {

			value = -1;
		}

		else if (input == 'y' || input == 'Y') {
			value = 1;
		}

		else if (input == 'n' || input == 'N') {
			value = 0;
		}
		else {
			value = -1;
		}

		
		if (value == -1) {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			//clearKeyboard();
		}


	} while (value == -1);



	return value;
}


// menu:
int menu(void) {


	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	int choice = getIntInRange(0, 6);
	return choice;


}


// ContactManagerSystem:
void ContactManagerSystem(void) {//NOTE: TEST LATER, ASK TEACHER ABOUT CALLING 


	struct Contact cDatabase[MAXCONTACT + 1] = {
	{ { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};



	int MenuChoice;
	int ExitChoice = 0;
	int counter = 0; //Used to check if it's the first time menu is running, If so it will match what the assignment output wants


	do {

		if (counter != 0) {// On startup do not make an extra line
			printf("\n");
		}

		counter = 1;

		MenuChoice = menu();

		
		printf("\n");
		switch (MenuChoice) {

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			ExitChoice = yes();
			break;

		case 1:
			displayContacts(cDatabase, MAXCONTACT);
			pause();
			break;

		case 2:
			addContact(cDatabase, MAXCONTACT);
			pause();
			break;

		case 3:
			updateContact(cDatabase, MAXCONTACT+1);
			pause();
			break;

		case 4:
			deleteContact(cDatabase, MAXCONTACT+1);
			pause();
			break;

		case 5:
			searchContacts(cDatabase, MAXCONTACT+1);
			printf("\n");
			pause();
			break;

		case 6:
			sortContacts(cDatabase, MAXCONTACT+1);
			pause();
			break;
		default :
			printf("ERROR");
		}


	} while (ExitChoice == 0); //While user does not want to close program


	printf("\nContact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+



// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
	int needInput;
	char InputNum[12];
	int i; //counter used on for loop

	do {

		needInput = 0;

		scanf("%11s", InputNum);



		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(InputNum) == 10) {
			
			//Check if valid phone number
			for (i = 0; i < strlen(InputNum); i++) { 

				if ( (!isdigit(InputNum[i]) ) && (!isspace(InputNum[i])) ) //If char array spot is not a digit or space then invalid input
				{

					needInput = 1;

				}

			}


			//-----------------------------------------------
		}
		else {
			needInput = 1;
		}


		if (needInput != 0) {
			printf("Enter a 10-digit phone number: ");
		}


	} while (needInput == 1);

	strcpy(telNum, InputNum);
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int ArraySpot = -1;


	//-------Compare cellNum to each cellphone number in the contact array
	for (i = 0; i < size; i++) { 

if (strcmp(contacts[i].numbers.cell, cellNum) == 0) { //Compare phone numbers, if they're the same then strcmp will return 0 (Meaning 0 differences between strings)

	ArraySpot = i;
	break; //End loop if match found

}

	}

	return ArraySpot;

}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {

	printf("+-----------------------------------------------------------------------------+\n|                              Contacts Listing                               |\n+-----------------------------------------------------------------------------+");

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int size) {

	printf("\n+-----------------------------------------------------------------------------+\nTotal contacts: %d\n\n", size);

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact) {


	//---------------Display Name-------------------------------------
	if (strlen(contact->name.middleInitial) == 0) { //Check if middleIntial value is empty

		printf(" %s %s\n", contact->name.firstName, contact->name.lastName); //if empty print name wihtout it

	}
	else {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	//---------------------------------------------------------------------------


   //-------------Display contact info---------------------------------------
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);


	//---Display Address-----------------------
	if (contact->address.apartmentNumber == 0) { //Check if apartmentNumber value is empty. -1 means no apartment number exist

		printf("       %d %s, %s, %s", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);

	}
	else {
		printf("       %d %s, Apt# %d, %s, %s", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}


}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int size) {
	//size = 5 (delete this comment after)

	int i;//for loop counter
	int j;
	int VCFound; //Valid Contact found (Contact that has a Cell Number)
	int emptySlots = -1; //Amount of empty slots in array (starts at - 1 due to [i] starting at 0) 
	//This makes sure that even when the Contact array is empty contactfooter prints 0 contacts

	displayContactHeader();

	//Scan Contact Array
	for (i = 0; i < size+1; i++) {

	 if ( (  strlen(contact[i].numbers.cell) == 0) ) { //If contact[i] is empty check if it's te last empty spot

		 VCFound = 0; //Assume there are no more Valid contacts 
		 emptySlots++; //Add 1 to empty slot counter due to empty slot being found

		//are all preceding contacts empty? (For loop scans preceding contacts)
		 for (j = i; j < size; j++) {
			 if (strlen(contact[j + 1].numbers.cell) != 0) {
				 VCFound = 1; //If a preceding contact cell is not empty then current contact[i] is not end of all Valid Contacts
				 break; //end current for loop
			 }
		 }





		 if (VCFound == 0) { //If no more valid contacts are found
			 displayContactFooter(i - emptySlots); //Display footer with contact count
			 break; //end main for loop
		 }
			 
	}

	
		 
	
		else {
			printf("\n");
			displayContact(&contact[i]);
		}

	}


}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int size) {

	char CellNum[11];
	int FoundMatch; //Array spot of matching contact 

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(CellNum);

	FoundMatch = findContactIndex(contact, size, CellNum);

	if (FoundMatch != -1)  {
		printf("\n");
		displayContact(&contact[FoundMatch]); 
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}



}


// :
// Put empty function definition below:
void addContact(struct Contact contact[], int size) {

	int i;
	int SpotFound = 0; //Check if an empty spot for contact has been found




	for (i = 0; i < size; i++) {

		if ( strlen(contact[i].numbers.cell) == 0) { //If contact is invalid then we have reached the end of the all VALID contacts

			SpotFound = 1;
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");

			break; //end for loop
		}


	}


	if (SpotFound == 0) { //If there are no empty spots then the contact array is full
		printf("*** ERROR: The contact list is full! ***\n");
	}

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int size) {

	char CellNum[11];
	int FoundContact;
	int Input;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(CellNum);

	FoundContact = findContactIndex(contact, size, CellNum);

	if (FoundContact != -1) {

		printf("\nContact found:\n");
		displayContact(&contact[FoundContact]);

		printf("\n\nDo you want to update the name? (y or n): ");
		Input = yes();

		if (Input == 1) {//if user says yes
			getName(&contact[FoundContact].name);
		}

		printf("Do you want to update the address? (y or n): ");
		Input = yes();

		if (Input == 1) {

			getAddress(&contact[FoundContact].address);

		}

		printf("Do you want to update the numbers? (y or n): ");
		Input = yes();

		if (Input == 1) {
			getNumbers(&contact[FoundContact].numbers);
		}

		printf("--- Contact Updated! ---\n");

	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contact[], int size) {

	char CellNum[11];
	int FoundContact;
	int Input;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(CellNum);

	FoundContact = findContactIndex(contact, size, CellNum);

	if (FoundContact != -1) {

		printf("\nContact found:\n");
		displayContact(&contact[FoundContact]);

		printf("\n\nCONFIRM: Delete this contact? (y or n): ");
		Input = yes();

		if (Input == 1) {
			//contact[FoundContact].numbers.cell[0] = 0;

			memset(&contact[FoundContact], 0, sizeof(contact[FoundContact])); //Reset Data in contact[index]

			////There is now a blank spot in the array, move all contacts down one space to seal it. 
			////If Contact[2] is deleted then (Copy 3 to 2,  Copy 4 to 3,  Copy 5 to 4)
			//for (i = FoundContact; i < size-1; i++) {

			//	
			//		contact[i].address = contact[i + 1].address;
			//		contact[i].name = contact[i + 1].name;
			//		contact[i].numbers = contact[i + 1].numbers;
			//
			//}  had to remove due to output mismatch (Code worked fine & produced same results but slighly different output)
			    //Also had to redo displayContat because of output mismatch. q.q a lot of extra work for the same results

			//P.S: Fight me ( Not actually <3 ) 



			printf("--- Contact deleted! ---\n");
		}

	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contact[], int size) {
	
	int i;
	float num1, num2;
	int Swapped;

	struct Contact PlaceHolder; //Placeholder contact 


	

	//Bubble sort because i'm lazy to do a more efficient way
	do {
		Swapped = 0;
		for (i = 0; i < size; i++) {

			//Convert char arrays to floats due to size.

			if (strlen(contact[i+1].numbers.cell) != 0) {

				sscanf(contact[i].numbers.cell, "%f", &num1);
				sscanf(contact[i + 1].numbers.cell, "%f", &num2);
				
				if (num1 > num2) { 
			
			    PlaceHolder.name = contact[i].name;
				PlaceHolder.address = contact[i].address;
				PlaceHolder.numbers = contact[i].numbers;
				


				contact[i].name = contact[i + 1].name;
				contact[i].numbers = contact[i + 1].numbers;
				contact[i].address = contact[i + 1].address;


				contact[i + 1].name = PlaceHolder.name;
				contact[i + 1].numbers = PlaceHolder.numbers;
				contact[i + 1].address = PlaceHolder.address;

				Swapped = 1;
				
				}
		}
			else {

				break;
			}
			
		






		}
	} while (Swapped == 1);// Go on in till no more swapping has occcured
	//Final product should be contacts sorted from lowest to highest

	printf("--- Contacts sorted! ---\n");


}