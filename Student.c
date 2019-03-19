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