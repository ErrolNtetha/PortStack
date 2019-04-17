#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program uses structs to make a database of 
// employees and saves records in a disk file

FILE *fptr;	// Defines a file pointer

typedef struct {
	char fullname[50];		//Full names
	int addr;		// The address
	float salary;	// Salaries
	int id;		// Employees' ID numbers
	int noEmpl;	// Number of emlployees
} database;

int main(void)
{
	int ctr = 1; // Counter initialised to 1
	int ctr2 = 0;
	int i, j, k, l;
	
	 database *employee[80];

	// Prompts the valid number of employees
	// limited to 150
	do
	{
		printf("Enter the total number of employees: ");
		scanf("%i", &employee[ctr2]->noEmpl);
	}
	while ((employee[ctr]->noEmpl <= 0) || (employee[ctr]->noEmpl > 150));

	// Capitalize every first character of emlployees' names
	employee[ctr2]->fullname[0] = toupper(employee[ctr]->fullname[0]);

	// Prompts all employee names
	for (i = 0; i < employee[ctr2]->noEmpl; i++)
	{
		printf("%d) Employee: ", ctr++);
		fgets(employee[i]->fullname, 50, stdin);
		printf("\n");
	}

	// Get the salaries for each of them
	for (j = 0; j < employee[ctr2]->noEmpl; j++)
	{
		printf("Salary for %s: ", employee[ctr2]->fullname);
		scanf("%f", &employee[j]->salary);
		printf("\n");
	}

	// Now get key ID numbers
	for (k = 0; k < employee[ctr2]->noEmpl; k++)
	{
		printf("ID number for %s: ", employee[ctr2]->fullname);
		scanf("%i", &employee[k]->id);
		printf("\n");
	}

	// Get addresses
	for (l = 0; l < employee[ctr2]->noEmpl; l++)
	{
		printf("Address for %s: ", employee[ctr2]->fullname);
		scanf("%i", &employee[l]->addr);
		printf("\n");
	}

	fptr = fopen("/sdcard/CompScience/database.txt", "w");

	// Testing the file if its opened
	if (fptr == 0)
	{
		printf("Error! File could not be opened.\n");
		exit (1);
	}

	// Put employees to the file permanently
	fprintf(fptr, "***\nHere is the collection of all your employee:***s\n\n");
	for (int m = 0; m < employee[ctr2]->noEmpl; m++)
	{
		fprintf(fptr, ""); // Coming up with the content
	}
	fclose(fptr); // Closing the file
 }	