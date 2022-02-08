#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[100];
	int rollno;
	char course[100];
	int marks;
	struct Student *next;
}*head;


void insert(char* name, int rollno, char* course, int marks)
{
	
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	strcpy(student->name, name);
	student->rollno = rollno;
	strcpy(student->course, course);
	student->marks = marks;
	student->next = NULL;
	
	if(head==NULL)
	{
		head = student;
	}
	else
	{
		student->next = head;
		head = student;
	}
}

void delete(int rollno)
{

    struct Student * temp1 = head;
	struct Student * temp2 = head; 
	while(temp1!=NULL){
		
		if(temp1->rollno==rollno){
			
			printf("Record with roll number %d has been found.\n", rollno);
			
			if(temp1==temp2)
			{
				head = head->next;
				free(temp1);
			}
			else
			{
				temp2->next = temp1->next;
				free(temp1); 
			}
			printf("Record successfully deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Student with roll number %d has not been found.\n", rollno);
	
}


void display()
{
    struct Student * temp = head;
	while(temp!=NULL)
	{
		printf("Name: %s\n", temp->name);
	 	printf("Roll Number: %d\n", temp->rollno);
		printf("Course: %s\n", temp->course);
        printf("Marks: %d\n", temp->marks);
        printf("\n");
		temp = temp->next;
	}
}


void search(int rollno)
{
    struct Student * temp = head;
	while(temp!=NULL){
		if(temp->rollno==rollno)
		{
		    printf("Name: %s\n", temp->name);
	 	    printf("Roll Number: %d\n", temp->rollno);
		    printf("Course: %s\n", temp->course);
		    printf("Marks: %d\n", temp->marks);
			return;
		}
		temp = temp->next;
	}
	printf("Student with roll number %d has not been found.\n", rollno);
}


int main()
{
    head = NULL;
    int c;
    char name[100];
    int rollnumber;
    char course[100];
    int marks;
    printf("STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("(1) Insert student details\n(2) Delete student details\n(3) Display student details\n(4) Search student details\n(5) Exit\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter course: ");
                scanf("%s", course);
                printf("Enter marks: ");
                scanf("%d", &marks);
                insert(name, rollnumber, course, marks);
                break;
            
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                delete(rollnumber);
                break;
                
            case 3:
                display(rollnumber);
                break;
                
            case 4:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
                
            default:
                printf("Invalid choice");
        }
    } 
    while (c != 0);
}
