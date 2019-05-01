#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr;	 // Defines file pointer

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif 

typedef struct {
	int age; 
	int id; //Key identification
	long long tax;	// Tax number
	char names[BUFFER_SIZE]; // Full names of employees
	float salary;
} db;

typedef db *base;

int requestNum();
char get_details();
base memAlloc(void);
void capitalize();
void writeDisk();
void errorCheck();

	db *empl[BUFFER_SIZE];
	int noEmpl, ctr, x = 0;

int main(void)
{
	
	for (int index = 0; index < BUFFER_SIZE; index++)
	{
		empl[index] = memAlloc();
	}
	
	printf("\n\n\t\t*** Employees Registrar *** \n\n");	// You can remove new lines preceding this statement
	requestNum();	// Ask for number of employees
	capitalize();	// Capitalize strings
	printf("\n\n");
	get_details();	// Prompts credentials
	writeDisk();	// Save to disk file
	printf("***End***\n\n");
}

/****************************************/
int requestNum()
{
	// Prompt valid number of employees
	do 
	{
		printf("Note: Only a maximum of 150 employees allowed.\n\n");
		printf("Number of employees: ");
		scanf("%d", &noEmpl);
		printf("\n");
		errorCheck();
	}
	while ((noEmpl <= 0) || (noEmpl > 150)); // Limited to 150

	return 0;
}

/****************************************/
void capitalize()
{
	/* This function capitalizes first character of every name 
	of employee */
	int ctr = 0;
	empl[ctr]->names[0] = toupper(empl[ctr]->names[0]);
}

/****************************************/
char get_details()
{
	int ctr1=1;
	
	capitalize();
	for (int i = 0; i < noEmpl; i++)
	{	
		printf("%d) Employee Details\n", ctr1++);
		printf("~ Full names: ");
		scanf("%s", empl[ctr]->names); // fgets does not work properly
		printf("~ Age: ");
		scanf("%d", &empl[ctr]->age);
		printf("~ ID number (last 4 digits): ");
		scanf("%d", &empl[ctr]->id);
		printf("~ Salary: $");
		scanf("%f", &empl[ctr]->salary);
		printf("~ Tax number: ");
		scanf("%lld", &empl[ctr]->tax);
		x++;
		printf("\n\n");
	}
	return 0;
}

/*****************************************/
// Allocates memory
base memAlloc(void)
{
	base ptr = calloc(1, sizeof(db));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error! Failed to allocate memory.");
		exit (EXIT_FAILURE);
	}
	free(ptr);
	return ptr;	
}

/*******************************************/
// Save records on a disk file for late accessibility
void writeDisk()
{
	int c = 1;
	ptr = fopen("/data/data/com.termux/files/home/PortStack/employees.txt", "w");

		if (ptr == NULL)
		{
			fprintf(stderr, "Error! File could not be opened or created. Path not found.");
			exit (EXIT_FAILURE);
		}

		fprintf(ptr, "\t\t*** Database Management System (%d)***\n\n", x);
		
		// Loop all members
		for (int j = 0; j < noEmpl; j++)
		{
			fprintf(ptr, "%d. Employee Credentials:\n", c++);
			fprintf(ptr, "~ Full names: %s\n", empl[ctr]->names);
			fprintf(ptr, "~ Age: %d\n", empl[ctr]->age);
			fprintf(ptr, "~ ID number: %d\n", empl[ctr]->id);
			fprintf(ptr, "~ Salary: $%.2f\n", empl[ctr]->salary);
			fprintf(ptr, "~ Tax number: %lld\n", empl[ctr]->tax);
			fprintf(ptr, "\n\n");
		}
		fclose(ptr);	// Always close file when done
}

// Error checking
void errorCheck()
{
	if (noEmpl > 150)
	{
		printf("Your number exceeds the maximum allowed!\n");
	}
	
	else if (noEmpl <= 0)
	{
		printf("No work to be done. You have no employees.\n");
		exit(EXIT_FAILURE);
	}
}