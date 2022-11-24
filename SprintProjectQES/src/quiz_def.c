//file with function definitions for the quiz application

#include "quiz.h"


FILE *fptr;

char name[20];
char pass[20];
char phone[10];
char email[30];

//function with welcome page details
void welcomePage()
{
    printf("\n\n\n");
    printf("-----------------------------------------------------------\n");
    printf("\n\n\n");
    printf("\n\n\t       WELCOME TO THE QUIZ WORLD              \n");
    printf("\n\n\n");
    printf("--------------------------------------------------------------\n");
    printf("\n                SELECT USER TYPE                    \n\n");
    printf("\n\t\t1\t-\tADMIN\
            \n\t\t2\t-\tTRAINER\
            \n\t\t3\t-\tPARTICIPANT\n");
            
    return;
}


//function to display menu of different users
void menu()
{
    welcomePage();
    
    printf("\n\t         ENTER YOUR CHOICE         \n\n\t\t\t");
    //char ch;
    int ch;
    scanf("%d", &ch);
    
    while(!(ch==1 || ch==2 || ch==3))
    {
    	printf("\n\n\t\tINVALID OPTION\n\n\t");
    	printf("\n\n         ENTER YOUR CHOICE       \n\n\t\t\t");
    	scanf("%d", &ch);
    }
   
    if(ch==1)
    {
    	login('A');
    }
    else if(ch==2)
    {
    	login('T');
    }
    if(ch==3)
    {
    	login('P');
    }
    
    return;
}
