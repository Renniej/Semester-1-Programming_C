/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

// Structure type Name declaration (Milestone 1)
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...

struct Address {

	int streetNumber;
	char postalCode[8];
	int apartmentNumber;
	char street[41];
	char city[41];

};


// Structure type Numbers declaration
// Place your code here...
struct  Numbers {
	char cell[41];
	char home[41];
	char business[41];
};

struct Contacts {

	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...

void getName(struct Name *);


// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *);

