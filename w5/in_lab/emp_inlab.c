/*
Name:
Student number:
Email:
Workshop:
Section:
Date:
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 2
#include <stdio.h>

int NumEmp = 0; //Number of employees counter

struct Employee {

	int ID;
	int Age;
	double Salary;

};

// Define Number of Employees "SIZE" to be 2
		

// Declare Struct Employee 


/* main program */
int main(void) {

	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");
	struct Employee emp[SIZE] = { {0} };  //{0}


	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			int i;

			for (i = 1; i <= SIZE; i++) { // Go through array spots

				if (emp[i-1].ID > 0) { //if array spot has valid value then print 

					printf("%6d%9d%11.2lf\n", emp[i - 1].ID, emp[i - 1].Age, emp[i - 1].Salary);

				}
				


			}
			printf("\n");
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 
			
			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:	// Adding Employee
				// @IN-LAB
				
			printf("Adding Employee\n");
			printf("===============\n");

			if (emp[SIZE - 1].ID > 0) { // If final spot in array has been modified then array is full and new values cant be inputted
			
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}
			else {
				

				printf("Enter Employee ID: ");
				scanf("%d", &emp[NumEmp].ID);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[NumEmp].Age);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[NumEmp].Salary);

				NumEmp = NumEmp + 1;

				printf("\n");
			}
			// Check for limits on the array and add employee 
			// data accordingly. 



			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0; 
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
