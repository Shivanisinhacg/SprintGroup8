/************************************************************************************
 * *
 * * FILE NAME : login_test.c
 * *
 * * DESCRIPTION : program to read and write login credentials in a file
 * *
 * * Revision History
 * * DATE   		NAME		REFERENCE  		REASON
 * * 23-11-2022       SprintGroup8	New                	Initial Creation
 * *
 * *Copyrights 2022, Altran Group All Rights Reserved
 * *
 * *********************************************************************************/

#include "quiz.h"
FILE *fptr;
extern char name[20];
char pass[20];
char phone[10];
char email[30];
char qual[30];
int res=0;
/**********************************************************************************
 * * 
 * * FUNCTION NAME : login
 * *
 * * DESCRIPTION   : This function includes the details of login page
 * *
 * * RETURNS      : SUCCESS or FAILURE
 * *******************************************************************************/

void login(char ch)
{
	int type;
	printf("\n\t-----------------------------\n");
	printf("\n\t\t       Select\n\n\
		0	:	Login\n\
		1	:	Sign Up\n\n\t\t\t");
	scanf("%d", &type);
		
	switch (ch)
	{
		
		case 'A':
			if(type)
			{
				fptr = fopen("admin_details.txt", "a");
				entry(fptr);
				fclose(fptr);
				login(ch);
			}
			else
			{
				fptr = fopen("admin_details.txt", "r");
				res = check(fptr);
				if(res)
				{
					printf("\n\t\t\tLogin successful :)\n");
					admin_Menu();
				}
				else
				{
					printf("\n\tUsername or Password is incorrect\n\n\t\t*****Try again******");
					login(ch);
				}	
				printf("\n------------------------------------\n");
				fclose(fptr);
			}
			break;
			
		case 'T':
			if(type)
			{
				fptr = fopen("trainer_details.txt", "a");
				entry(fptr);
				fclose(fptr);
				login(ch);
			}
			else
			{
				fptr = fopen("trainer_details.txt", "r");
				res = check(fptr);
				if(res)
				{
					printf("\n\t\t\tLogin successful :)\n");
					trainer_Menu();
				}
				else
				{
					printf("\n\tUsername or Password is incorrect\n\n\t\t*****Try again******");
					login(ch);
				}	
				printf("\n------------------------------------\n");
				fclose(fptr);
			}
			break;
			
		case 'P':
			if(type)
			{
				fptr = fopen("participant_details.txt", "a");
				entry(fptr);
				fclose(fptr);
				login(ch);
			}
			else
			{
				fptr = fopen("participant_details.txt", "r");
				res = check(fptr);
				if(res)
				{
					printf("\n\t\t\tLogin successful :)\n");
					participant_Menu();
				}
				else
				{
					printf("\n\tUsername or Password is incorrect\n\n\t\t*****Try again******");
					login(ch);
				}	
				printf("\n------------------------------------\n");
				fclose(fptr);
			}
			break;
			
		default:
			break;	
	}
	
	return;	      
}

/**********************************************************************************
 * *
 * * FUNCTION NAME :check
 * *
 * * DESCRIPTION   : this function whether the login credentials is correct or not
 * *
 * * RETURNS       : SUCCESS or FAILURE
 * *******************************************************************************/
int check(FILE *fptr)
{
	char *user;/*initializing a user*/
	char *code;
	int res=0;
		
	printf("Enter User Name : ");
	scanf("%s", name);
	printf("\nEnter Password : ");
	scanf("%s", pass);
	
	if(fptr == NULL)
	{
		printf("n\tFile not available..");
		exit(0);
	}
	
	char line[200];
	
	while(fgets(line, sizeof(line), fptr))
	{
		user=strtok(line,",");
		code=strtok(NULL,",");		
		if(!(strcmp(name, user) || strcmp(pass, code)))
		{
			res = 1;
			break;
		}
		else
		{
			continue;
		}
	}
	return res;
}
/**********************************************************************************
 * *
 * * FUNCTION NAME : entry
 * *
 * * DESCRIPTION   : This function enters into the login data check whether it is correct or not
 * *
 * * RETURNS       : SUCCESS or FAILURE
 * ********************************************************************************/
void entry(FILE *fptr)
{
	printf("\nRegistration of new user\n");
	printf("Enter User Name : ");
	scanf("%s", name);
	
	printf("\nEnter Password : ");
	scanf("%s", pass);
	
	int q;
	printf("\nEnter Qualification : \n\
		1\tPh.D\n\
		2\tPost Graduated\n\
		3\tGraduated\n\
		4\tUnder Graduated\n");
	scanf("%d", &q);
	
	if(q==1)
	{
		strcpy(qual, "Ph.D");
	}
	else if(q==2)
	{
		strcpy(qual, "PG");
	}
	else if(q==3)
	{
		strcpy(qual, "Graduated");
	}
	else
	{
		strcpy(qual, "UG");
	}
	
	int res = 0;
	while(res!=1)
	{
		printf("\nEnter 10 digit mobile number: ");
		scanf("%s", phone);
		res = validate_number(phone);
	}
	
	
	res = 0;
	while(res!=1)
	{
		printf("\nEnter Email ID: ");
		scanf("%s", email);
		res = validate_email(email);
	}
	
	fprintf(fptr, "%s,%s,%s,%s,%s\n", name, pass, qual, phone, email);
	printf("\n\tRegistration Successful\n");
	
	
	return ;
}
