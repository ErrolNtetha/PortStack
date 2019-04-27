#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *ptr;
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 200
#endif 

typedef struct db {
	int age;
	int id;
	int tax;
	int noEmpl;
	char names[BUFFER_SIZE];
	float salary;
} db;

typedef db *base;

int getAge();
int getID();
int getTax();
char getNames();
float getSalary();
base memAlloc(void);
void capitalize();

int main(void)
{
	db *empl[BUFFER_SIZE];
	
	int ctr = 0;

	for (int index = 0; index < BUFFER_SIZE; index++)
	{
		empl[index] = memAlloc();
	}
	do
	{
		printf("Numbers of employees: ");
		scanf("%d", &base[ctr]->noEmpl);
	}
	while ((empl[ctr]->noEmpl <= 0) || (empl[ctr]->noEmpl));
}
/****************************************/
void capitalize(void)
{
	int ctr = 0;
	base[ctr]->names[0] = toupper(base[ctr]->names[0]);
}
/****************************************/
int getAge()
{
	int ctr1 = 1;
	int ctr2 = 1;
	
	for (int i = 0; i < base[ctr1]->noEmpl; i++)
	{	
		printf("Employee age #%d", ctr1++);
		scanf("%d", &base[ctr2]->age);
		printf("\n");
	}
	return 0;
}
/*****************************************/
char getNames()
{
	int ctr2 = 1;
	int ctr = 0;
	printf("%d) Employee name: ", ctr2++);
	fgets(base[ctr]->names, BUFFER_SIZE, stdin);
	return 0;
}
/*****************************************/
base memAlloc(void)
{
	base fptr = calloc(1, sizeof(db));
	if (fptr == NULL)
	{
		fprintf(stderr, "Error! Memory not allocated.");
		exit (EXIT_FAILURE);
	}
	return fptr;	
}