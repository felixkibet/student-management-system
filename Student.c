#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Student Student;

struct Student {
	int regno;
	char fname[10];
	char lname[10];
	char gender[2];
	char course[10];
};
// Function prototypes
void adddetails(Student *stud);
void editdetails(Student *stud);
void printdetails(Student *stud);
void searchstudent(Student *stud);
void deletestudent(Student *stud);

int main()
{
	while(1)
	{
		printf("1] Create a Record\n");
	
	    printf("2] Display Records\n");
	
	    printf("3] Update Records\n");
		
		printf("4] Search Records\n");
		
		printf("5] Delete Records\n");
		
	    printf("6] Exit");
		int choice;
		Student student;
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				adddetails(&student);
				break;
			case 2:
				printdetails(&student);
				break;
			case 3:
				editdetails(&student);
				break;
			case 4:
				searchstudent(&student);
				break;
			case 5:
				deletestudent(&student);
				break;
			case 6:
				exit(0);
			defaut:
				printf("Please that is not an option");
		}
	}
    return 0;
}

// Add student details to file
void adddetails(Student *stud)
{
	FILE *fptr;
	fptr = fopen("student.txt","a");
	if(fptr == NULL)
	{
		printf("Error creating file...");
	}
	printf("Enter student regno:");
	scanf("%d", &stud->regno);
	printf("Enter student flname:");
	scanf("%s", stud->fname);
	printf("Enter student lname:");
	scanf("%s", stud->lname);
	printf("Enter student gender:");
	scanf("%s", stud->gender);
	printf("Enter student course:");
	scanf("%s", stud->course);
	fwrite(stud, sizeof(Student), 1, fptr);
	fclose(fptr);
}

// Edit student details and save to file
void editdetails(Student *stud)
{
	FILE *fptr, *fop;
	char name[20];
	
	fptr = fopen("student.txt","rb");
	fop = fopen("temporary.txt","w");
	printf("Enter name of student to update: ");
	scanf("%s", name);
	while(fread(stud, sizeof(Student), 1, fptr))
	{
		if(!strcmp(name, stud->fname) == 0)
		{
			fwrite(stud, sizeof(Student),1, fop);
		} else
		{
			printf("Enter student regno:");
			scanf("%d", &stud->regno);
			printf("Enter student flname:");
			scanf("%s", stud->fname);
			printf("Enter student lname:");
			scanf("%s", stud->lname);
			printf("Enter student gender:");
			scanf("%s", stud->gender);
			printf("Enter student course:");
			scanf("%s", stud->course);
			fwrite(stud, sizeof(Student),1, fop);
		}
	}
	fclose(fptr);
	fclose(fop);
	
	fptr = fopen("student.txt", "w");
	fop = fopen("temporary.txt", "rb");
	while(fread(stud, sizeof(Student), 1, fop))
	{
		fwrite(stud, sizeof(Student), 1, fptr);
	}
	printf("Record updated...\n");
	fclose(fop);
	fclose(fptr);
}

// Print student details of the console
void printdetails(Student *stud)
{
	FILE *fptr;
	fptr = fopen("student.txt","rb");
	if(fptr == NULL)
	{
		printf("Error opening file...");
	}
	
	int i = 0;
	while(fread(stud, sizeof(Student), 1, fptr))
	{
		printf("\n");
		printf("RegNo: %d\n", stud->regno);
		printf("First Name: %s\n", stud->fname);
		printf("Last Name: %s\n", stud->lname);
		printf("Gender: %s\n", stud->gender);
		printf("Course: %s\n", stud->course);
	}
	for(; i < 10; i++)
	{
		printf("==");
	}
	printf("\n");
	fclose(fptr);		
}

// Search for student in the record
void searchstudent(Student *stud)
{
	FILE *fptr;
	char name[20];
	
	fptr = fopen("student.txt", "rb");
	printf("Enter the first name: ->");
	scanf("%s", name);
	while(fread(stud, sizeof(Student),1, fptr)) 
	{
		if(strcmp(name,stud->fname) == 0)
		{
			printf("\n");
			printf("RegNo: %d\n", stud->regno);
			printf("First Name: %s\n", stud->fname);
			printf("Last Name: %s\n", stud->lname);
			printf("Gender: %s\n", stud->gender);
			printf("Course: %s\n", stud->course);
			getch();
			break;
		}	
	}
	fclose(fptr);
}

// Delete student from the record
void deletestudent(Student *stud)
{
	FILE *fptr, *fop;
	char name[20];
	fptr = fopen("student.txt", "rb");
	fop = fopen("temporary.txt", "w");
	printf("Enter name of student to delete: ");
	scanf("%s", name);
	while(fread(stud, sizeof(Student),1, fptr))
	{
		if(!strcmp(name, stud->fname) == 0)
		{
			fwrite(stud, sizeof(Student),1, fop);	
		}
	}
	fclose(fop);
	fclose(fptr);
	
	fptr = fopen("student.txt", "w");
	fop = fopen("temporary.txt", "rb");
	while(fread(stud, sizeof(Student), 1, fop))
	{
		fwrite(stud, sizeof(Student), 1, fptr);
	}
	printf("Record updated...\n");
	fclose(fop);
	fclose(fptr);
}

