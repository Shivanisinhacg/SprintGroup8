/**********************************************************************************
 * *
 * * FILE NAME  : quiz_def.c
 * *
 * * DESCRIPTION : this program includes all the details of the quiz definitions
 * *
 * * Revision History:
 * * DATE 	  NAME		REFERENCE    		INITIAL CREATION
 * * 23-11-2022  SprintGroup8   New                     Initial Creation
 * *
 * * Copyright 2022, Altran Group All Rights Reserved
 * *
 * *******************************************************************************/
/**********************************************************************************
 * *			STANDARD HEADER FILES
 * ********************************************************************************/
#include "quiz.h"
FILE *fptr;
char name[20];
char pass[20];
char phone[10];
char email[30];
/**********************************************************************************
 * *
 * * FUNCTION NAME : welcomePage
 * *
 * * DESCRIPTION  : This function includes all the details of login page
 * *
 * * RETURNS      : SUCCESS or FAILURE
 * ********************************************************************************/
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
/**********************************************************************************
 * *
 * * FUNCTION NAME : menu
 * *
 * * DESCRIPTION   : This function includes all the details of welcomepage
 * *
 * * RETURNS       : SUCCESS or FAILURE
 * ********************************************************************************/
void menu()
{
    welcomePage();
    
    printf("\n\t         ENTER YOUR CHOICE         \n\n\t\t\t");
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
