//functions of Admin

#include"quiz.h"

int id_count=10000;

FILE *fptr;

//function to display admin tasks
void admin_Menu()
{
	int id,choice;
	quiz q;
	node *head,*newnode;
	head=NULL;
	/*temp=NULL;*/
	FILE *dptr2;
	extern int id_count;
	
	//Reading data from the file to linked list
	
	head=read_from_file_quiz(head);
	
	//fclose(dptr);
	
	
	//do while loop runs until the user enters zero value
		
	do
	{
		printf("\n\n_ _ _ _ _ _ _ _ _ _ _ _ ADMIN MENU _ _ _ _ _ _ _ _ _ _ _ _\n");
		printf("\n\t\t\tSELECT YOUR TASK\n");
		printf("\t\t\t 1 - DISPLAY PARTICIPANT details\n\
			 2 - DISPLAY TRAINER details\n\
			 3 - DISPLAY QUIZ \n\
			 4 - ADD QUIZ \n\
			 5 - DISPLAY RESULTS \n\
			 6 - DELETE QUIZ \n\
			 7 - LOGIN PAGE\n\
			 0 - EXIT\n");
		
		scanf("%d", &choice);
		switch (choice)
		{
			
			case 1:
				display_Participants(fptr);
				break;
				
			case 2:
				display_Trainers(fptr);
				break;
				
			case 3:
				display_Quiz(head);
				break;
				
			case 4:
				printf("\nEnter the details to add a quiz:\n");
				
				q.quiz_id=++id_count;
				
				while(getchar()!='\n');
				printf("\nQuiz description: ");
				scanf("%[^\n]s",q.quiz_desc);
				newnode=create_node_quiz(q);
								
				dptr2=fopen("quiz.txt","a");
				head=add_node_quiz(head,newnode, dptr2);
				fclose(dptr2);
			
				printf("\nquiz with quiz_id %d is added.\n",q.quiz_id);
				break;
				
			case 5:
				display_results();
				break;
				
			case 6:
				printf("\nEnter the quiz id to delete the record\n");
				scanf("%d",&id);
				head=delete_Quiz(id,head);
				break;
				
		/*	case 7:
				delete_user('P');
				break;
				
			case 8:
				delete_user('T');
				break;*/
			
			
			case 7:
				menu();
				break;
				
			case 0:
				printf("\nEXITED\n");
				exit(0);
				break;
				
			default:
				break;	
		}
		
	}while(choice!=0);
	return;
}

//function to display participants
void display_Participants(FILE *fptr)
{
	fptr = fopen("participant_details.txt", "r");
	char line[200];
	char *token;
	
	printf("\nParticipant Details\n-----------------------------------------------\n\n");
	while(fgets(line, sizeof(line), fptr))
	{
		token=strtok(line,",");
		printf("User ID\t\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		/*token=strtok(NULL,",");*/
		printf("Qualification\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		printf("Phone Number\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		printf("Email Id\t:\t%s\n", token);
		printf("-------------------------------------------\n\n");
	}
	
	fclose(fptr);
	return;
}

//function to display trainers
void display_Trainers(FILE *fptr)
{
	fptr = fopen("trainer_details.txt", "r");
	
	char line[200];
	char *token;
	
	printf("\nTrainer Details\n-----------------------------------------------\n\n");
	/*printf("Trainer Name\t Qualification\t\t Phone\t Email id\n");*/
	printf("----------------------------------------------------------\n");
	while(fgets(line, sizeof(line), fptr))
	{
		token=strtok(line,",");
		printf("User ID\t\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		token=strtok(NULL,",");
		printf("Qualification\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		printf("Phone Number\t:\t%s\n", token);
		
		token=strtok(NULL,",");
		printf("Email Id\t:\t%s\n", token);
		printf("-------------------------------------------\n\n");
	}
	
	fclose(fptr);
	return;
}

//Function to create a node for the linked list
//Paramaters: structure variable of question and returns the new node created
//Returns the head pointer of the linked list

node* read_from_file_quiz(node *head)
{
	char *token;
	FILE* fptr;
	quiz q;
	int count=0;
	node* newnode;
	char line[100];
	/*char *end[20];*/
	fptr=fopen("quiz.txt","r");
	
	//printf("Entered the read file");
	if(fptr==NULL)
		printf("File doesn't exist\n");
	else
	{
	    while(fgets(line,sizeof(line),fptr)!=NULL)
		{
	
		//printf("Entered the read file");
		token=strtok(line,",");
		
		if(count==0)
		{
			q.quiz_id=atoi(token);
			count++;
			token=strtok(NULL,",");
		}
		
		if(count==1)
		{
			strcpy(q.quiz_desc,token);
			token=strtok(NULL,",");
			count++;
		}
		count=0;
		newnode=create_node_quiz(q);
		head=add_node_quiz(head,newnode, fptr);
		}
	}
	fclose(fptr);
	return head;
}



node* create_node_quiz(quiz q)
{
	node *newnode= (node*)malloc(sizeof(node));
	
	newnode->q.quiz_id=q.quiz_id;
	strcpy(newnode->q.quiz_desc,q.quiz_desc);
	id_count=q.quiz_id;
	return newnode;
}


//Function to add a node to the linked list
//Paramaters: 2 pointers of linked list

node* add_node_quiz(node *head, node *newnode, FILE *dptr2)
{
    node *temp=head;
    //check if LL is empty
    if(head==NULL)
         head = newnode;
    else
    {
        while(temp->next!=NULL)
        {
        	temp = temp->next;
        }  
        temp->next = newnode; 
    }
    
    fprintf(dptr2,"%d,%s\n",newnode->q.quiz_id, newnode->q.quiz_desc);

   return head;
}



//Function to delete a record using user Id 
//Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list

node* delete_Quiz(int id, node *head)
{
    node *temp=head;
    node *tag;
    if(head==NULL)
    {
        printf("\nLIST EMPTY");
    }
    else if(head->next==NULL)
    {
        if(temp->q.quiz_id==id)
        {
            head=NULL;
        }
    }
    else if(head->q.quiz_id==id)
    {
         head=head->next;
         free(temp);
         printf("\nQuiz deleted");
    }
    else
    {
        while(temp!=NULL && temp->q.quiz_id!=id)
        {
            tag=temp;
            temp=temp->next;
        }
        if(temp!=NULL)
        {
           tag->next=temp->next;
           free(temp);
           printf("\nQuiz deleted");
        }
        else
        {
            printf("\nQuiz Id invalid");
        }
    }
    
    FILE *wptr;
    wptr=fopen("quiz.txt","w");
    wptr=write_to_file_quiz(wptr,head);
    fclose(wptr);
    
    return head;
}

//Function to display the question details
//Paramaters: integer, head pointer of the linked list and  no return type

void display_Quiz(node *head)
{
/*	int check=0;*/
	node *temp=head;	
	while(temp!=NULL)
	{
		printf("\nDetails of the quiz are :%d, %s",temp->q.quiz_id, temp->q.quiz_desc);
		temp=temp->next;	
	}
	printf("\n");
	return;
}

//Function to load the contents from the linked list and store into the file after all the operations
//Paramaters: file pointer and head pointer of the linked list and  returns the file pointer

FILE* write_to_file_quiz(FILE *wptr, node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		fprintf(wptr,"%d,%s",temp->q.quiz_id, temp->q.quiz_desc);
		temp=temp->next;
	}
	return wptr;
	
}


//Function to display results and quiz attempted
//parameters: Participant ID
void display_results()
{
/*	 int pid;*/
	FILE *fp;
	fp=fopen("results.txt","r");
	char str[50];
	printf("Enter participant ID : ");
	scanf("%s", str);   
	char line[200];

	while(fgets(line,sizeof line ,fp))
	{
		char *token;
		token=strtok(line,",");
		int i=1;
		while(token!=NULL)
		{
			 if(i==1)
			 {
			    if(!(strcmp(token, str)));
			    else 
			    {
			    	token=NULL;
			    	continue;
			    }
			 }
			 
			 if(i==2)
			    printf("\nAttempted Quiz ID :\t%d\n",atoi(token));
		/*	 if(i==3)
			    printf("Q1) Correct Answer : %s\n",token);
			 if(i==4)
			    printf("    Participant Answer : %s\n",token);
			 if(i==5)
			    printf("Q2) Correct Answer : %s\n",token);
			 if(i==6)
			    printf("    Participant Answer : %s\n",token);
			 if(i==7)
			    printf("Q3) Correct Answer : %s\n",token);
			 if(i==8)
			    printf("    Participant Answer : %s\n",token);
			 if(i==9)
			    printf("Q4) Correct Answer : %s\n",token);
			 if(i==10)
			    printf("    Participant Answer : %s\n",token);
			 if(i==11)
			    printf("Q5) Correct Answer : %s\n",token);
			 if(i==12)
			    printf("    Participant Answer : %s\n",token);*/
			 if(i==13){
			    printf("Marks obtained    :\t%d/5\n",atoi(token));
			    break;}

			 i++;
			 token=strtok(NULL,",");	 
		}

	}

	fclose(fp);

	return;
}
