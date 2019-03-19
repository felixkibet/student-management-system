#include <stdio.h>

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