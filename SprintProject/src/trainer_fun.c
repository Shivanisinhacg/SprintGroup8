//Definition file for question from admin
#include"quiz.h"

int id_qcount=500; //Global variable to generate the quesId

FILE *fptr;

//client file for trainer from admin

void trainer_Menu()
{
	int id,choice;
	question que;
	q_node *head,*temp,*newnode;
	head=NULL;
	temp=NULL;
	FILE *dptr2;
	extern int id_qcount;
	
	//Reading data from the file to linked list
	
	head=read_from_file_question(head);
	
	//fclose(dptr);
	
	
	//do while loop runs until the user enters zero value
	
	
	 do{
			
		printf("\n_ _ _ _ _ _ _ _ _ _ _ _ Trainer MENU _ _ _ _ _ _ _ _ _ _ _ _\n");
		printf("\n\t\t\tChoose your choice :\n\
			\t1. Add question\n\
			\t2. Update question\n\
			\t3. Delete question\n\
			\t4. Display question\n\
			\t5. Display all questions\n\
			\t6. Add questions to a quiz\n\
			\t7. Update questions in a quiz\n\
			\t8. Display Participant Details\n\
			\t9. Display Quiz Details\n\
			\t10. Display Results\n\
			\t11. Login Page\n\
			\t0. Exit\n");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			printf("\nEnter the details to add a question:\n");
			
			que.ques_id=++id_qcount;
			
			while(getchar()!='\n');
			printf("\nQuestion description: ");
			scanf("%[^\n]s",que.ques_desc);
			printf("\noption1: ");
			scanf("%s",que.option1);
			printf("\noption2: ");
			scanf("%s",que.option2);
			printf("\noption3: ");
			scanf("%s",que.option3);
			printf("\noption4: ");
			scanf("%s",que.option4);
			printf("\ncorrectoption: ");
			scanf("%d", &que.correctop);
			newnode=create_node_question(que);
			
			dptr2=fopen("questions.txt","a");
			head=add_node_question(head,newnode, dptr2);
			fclose(dptr2);
			
			printf("\nquestion with ques_id %d is added.\n",que.ques_id);
		}
		
		else if(choice==2)
		{
			printf("\nEnter the Id to update the details of the question\n");
			int id;
			scanf("%d", &id);
			head=update_question(id,head);
			
		}

		else if(choice==3)
		{
			printf("\nEnter the question id to delete the record\n");
			scanf("%d",&id);
			head=delete_question(id,head);
			
		}
		
		else if(choice==4)
		{
			printf("\nEnter the question Id to display the details:\n");
		
			scanf("%d",&id);
			display_question(id,head);
		}
		
		else if(choice==5)
		{
			printf("\nThese are the questions in a file\n");
			displayall_question(head);
			
		}
		else if(choice==6)
		{
			addquesid();
		}
		
		else if(choice==7)
		{
			updatequesid();
			
		}
		else if(choice==8)
		{
			printf("\nThese the the details of Participants\n");
			display_Participants(fptr);
			
		}
		else if(choice==9)
		{
			printf("\nThese are the Quiz details\n");
			node *h;
			h = NULL;
			h=read_from_file_quiz(h);
			display_Quiz(h);
			
		}
		else if(choice==10)
		{
			display_results();
			
		}
		else if(choice==11)
		{
			menu();
		}
		else if(choice==0)
		{
			printf("\nEXITED\n");
			exit(0);
			
		}
		
		else
			printf("\nEnter valid choice\n");
		printf("\n");
	    
	}while(choice!=0);	
	
}

//Function to create a node for the linked list
//Paramaters: structure variable of question and returns the new node created
//Returns the head pointer of the linked list

q_node* read_from_file_question(q_node *head)
{
	char *token;
	FILE* fptr;
	question que;
	int count=0;
	q_node* newnode;
	char line[100];
	char *end[20];
	fptr=fopen("questions.txt","w");
	
	if(fptr==NULL)
		printf("File doesn't exist\n");
	else
	{
	    while(fgets(line,sizeof(line),fptr)!=NULL)
		{
		token=strtok(line,",");
		
		if(count==0)
		{
			que.ques_id=atoi(token);
			count++;
			token=strtok(NULL,",");
		}
		
		if(count==1)
		{
			strcpy(que.ques_desc,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==2)
		{
			strcpy(que.option1,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==3)
		{
			strcpy(que.option2,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			strcpy(que.option3,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==5)
		{
			strcpy(que.option4,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==6)
		{
			/*strcpy(que.correctop,token);
			token=strtok(NULL,",");
			count++;*/
			que.correctop=atoi(token);
			count++;
			token=strtok(NULL,",");
		}
		
		count=0;
		newnode=create_node_question(que);
		head=add_node_question(head,newnode,fptr);
		}
	}
	fclose(fptr);
	return head;
}



q_node* create_node_question(question q)
{
	q_node *newnode= (q_node*)malloc(sizeof(q_node));
	
	newnode->que.ques_id=q.ques_id;
	strcpy(newnode->que.ques_desc,q.ques_desc);
	strcpy(newnode->que.option1,q.option1);
	strcpy(newnode->que.option2,q.option2);
	strcpy(newnode->que.option3,q.option3);
	strcpy(newnode->que.option4,q.option4);
	newnode->que.correctop = q.correctop;
	//strcpy(newnode->que.correctop,q.correctop);
	id_qcount=q.ques_id;
	return newnode;
}


//Function to add a node to the linked list
//Paramaters: 2 pointers of linked list

q_node* add_node_question(q_node *head,q_node *newnode,  FILE *dptr2)
{
    q_node *temp=head;
    //check if LL is empty
    if(head==NULL)
         head = newnode;
    else
    {
        while(temp->next!=NULL)
              temp = temp->next;
          
        temp->next = newnode; 
    }
	
	fprintf(dptr2,"%d,%s,%s,%s,%s,%s,%d\n",newnode->que.ques_id, newnode->que.ques_desc, newnode->que.option1, newnode->que.option2, newnode->que.option3, newnode->que.option4, newnode->que.correctop);
   return head;
}


//Function to display the question details
//Paramaters: integer, head pointer of the linked list and  no return type

void display_question(int id,q_node *head)
{
	int check=0;
		q_node *temp=head;
		
		while(temp!=NULL && id!=temp->que.ques_id)
		{
			temp=temp->next;
			
		}
		
		if(temp!=NULL)
			printf("\nDetails of the question are :\n%d, %s, %s, %s, %s, %s, %d\n",temp->que.ques_id, temp->que.ques_desc, temp->que.option1, temp->que.option2, temp->que.option3, temp->que.option4, temp->que.correctop);
		else
			printf("\nNo question exists with the ID you entered.\n");
}




//Function to update a record using user Id 
//Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list

q_node* update_question(int id,q_node* head)
{
	q_node *temp=head;
	char ques_desc[200];
	char option1[15];
	char option2[15];
	char option3[15];
	char option4[15];
	int correctop;
	
		
	while(temp!=NULL && id!=temp->que.ques_id)
	{
		temp=temp->next;	
	}
		
	if(temp!=NULL)
	{
		/*while(getchar()!='\n')
		{
			printf("\nEnter new details of the question :\n");
			scanf("%[^\n]s",ques_desc);
			printf("\noption1: ");
			scanf("%s",option1);
			printf("\noption2: ");
			scanf("%s",option2);
			printf("\noption3: ");
			scanf("%s",option3);
			printf("\noption4: ");
			scanf("%s",option4);
			printf("\ncorrectoption: ");
			scanf("%d", &correctop);
			
			strcpy(temp->que.ques_desc,ques_desc);
			strcpy(temp->que.option1,option1);
			strcpy(temp->que.option2,option2);
			strcpy(temp->que.option3,option3);
			strcpy(temp->que.option4,option4);
			//strcpy(temp->que.correctop,correctop);
			temp->que.correctop = correctop;
			
		}*/
		
		while(getchar()!='\n');
			printf("\nQuestion description: ");
			scanf("%[^\n]s",ques_desc);
			printf("\noption1: ");
			scanf("%s",option1);
			printf("\noption2: ");
			scanf("%s",option2);
			printf("\noption3: ");
			scanf("%s",option3);
			printf("\noption4: ");
			scanf("%s",option4);
			printf("\ncorrectoption: ");
			scanf("%d", &correctop);
		
		/*printf("Enter new details of the question : ");
		scanf("%[^\n]s",ques_desc);
		printf("\noption1: ");
		scanf("%s",option1);
		printf("\noption2: ");
		scanf("%s",option2);
		printf("\noption3: ");
		scanf("%s",option3);
		printf("\noption4: ");
		scanf("%s",option4);
		printf("\ncorrectoption: ");
		scanf("%d", &correctop);*/
		
		strcpy(temp->que.ques_desc,ques_desc);
		strcpy(temp->que.option1,option1);
		strcpy(temp->que.option2,option2);
		strcpy(temp->que.option3,option3);
		strcpy(temp->que.option4,option4);
		//strcpy(temp->que.correctop,correctop);
		temp->que.correctop = correctop;
		
		FILE *wptr;
		wptr=fopen("questions.txt","w");
		wptr=write_to_file_question(wptr,head);
		fclose(wptr);
	}
			
			
	else
			printf("\nNo question exists with the ID you entered.\n");
		
	return head;
}



//Function to delete a record using user Id 
//Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list

q_node* delete_question(int id,q_node *head)
{
    q_node *temp=head;
    q_node *tag;
    if(head==NULL)
    {
        printf("\nLIST EMPTY");
    }
    else if(head->next==NULL)
    {
        if(temp->que.ques_id==id)
        {
            head=NULL;
        }
    }
    else if(head->que.ques_id==id)
    {
         head=head->next;
         free(temp);
         printf("\nQuestion deleted");
    }
    else
    {
        while(temp!=NULL && temp->que.ques_id!=id)
        {
            tag=temp;
            temp=temp->next;
        }
        if(temp!=NULL)
        {
           tag->next=temp->next;
           free(temp);
           printf("\nQuestion deleted");
        }
        else
        {
        
            printf("\nQuestion Id invalid");
        }
        
    }
    
    FILE *wptr;
    wptr=fopen("questions.txt","w");
    wptr=write_to_file_question(wptr,head);
    fclose(wptr);
    
    return head;
}



//Function to display the question details
//Paramaters: integer, head pointer of the linked list and  no return type

void displayall_question(q_node *head)
{
	int check=0;
	q_node *temp=head;
		
	while(temp!=NULL)
	{
		printf("\nDetails of the question are :\n%d, %s, %s, %s, %s, %s, %d\n",temp->que.ques_id, temp->que.ques_desc, temp->que.option1, temp->que.option2, temp->que.option3, temp->que.option4, temp->que.correctop);
			temp=temp->next;	
		}
}


FILE* write_to_file_question(FILE *wptr, q_node *head)
{
	q_node *temp=head;
	while(temp!=NULL)
	{
		fprintf(wptr,"%d,%s,%s,%s,%s,%s,%d\n",temp->que.ques_id, temp->que.ques_desc, temp->que.option1, temp->que.option2, temp->que.option3, temp->que.option4, temp->que.correctop);
		temp=temp->next;
	}
	
	return wptr;
}
	
