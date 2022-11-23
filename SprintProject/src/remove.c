//function to add/edit questions to a particular quiz

#include "quiz.h"

//Function for creating a new node
ud *createNodeUser()
{
   ud *head = (ud *)malloc(sizeof(ud) * 1);
   head->next = NULL;
   return head;
}


//Function for adding a new node in the beginning of the linked list.
ud *addfirstUser(ud *head)
{
	
   ud *n = createNodeUser();
   n->next = head;
   head = n;
   return head;
}

//Function for loading all the data from quiz_ques.txt file to a linked list.
ud *loadUser(char ch){

   ud *head =createNodeUser();
   int j=0;
	
   FILE *fp3;
   if(ch=='T')
   {
   	fp3=fopen("trainer_details.txt","r");
   }
   else if(ch == 'P')
   {
   	fp3=fopen("participant_details.txt","r");
   }
   
  
   char line[200];
   
   while(fgets(line,sizeof line ,fp3)){
      char *token;
      token=strtok(line,",");
      int i=1;
      if(j==1)
      head=addfirstUser(head);
      while(token!=NULL){
         if(i==1)
            strcpy(head->name,token);
         if(i==2)
            strcpy(head->pass,token);
         if(i==3)
            strcpy(head->quali,token);
         if(i==4)
            strcpy(head->mobno,token);
         if(i==5)
            strcpy(head->email,token);
            
         i++;
         token=strtok(NULL,",");
         
      }
      j=1;
      
   }
   
   fclose(fp3);
   return head;
}


//function to delete user
void delete_user(char ch)
{
   ud *head = loadUser(ch);
   char id[30];

   printf("\nEnter the user name to delete : ");
   scanf("%s",id);
   
   ud *n = head; 
   ud *prev = head;
   while(strcmp(n->name,id)!=0){
      prev=n;
      n=n->next;
   }
   prev->next=n->next;
   free(n);
   
    ud *temp=head;
    ud *tag;
    if(head==NULL)
    {
        printf("\nLIST EMPTY");
    }
    else if(head->next==NULL)
    {
        if(strcmp(temp->name,id)!=0)
        {
            head=NULL;
        }
    }
    else if(strcmp(head->name,id)==0)
    {
         head=head->next;
         free(temp);
         printf("\nQuestion deleted");
    }
    else
    {
        while(temp!=NULL && (strcmp(temp->name,id)!=0))
        {
            tag=temp;
            temp=temp->next;
        }
        if(strcmp(temp->name,id)==0)
        {
           tag->next=temp->next;
           free(temp);
           printf("\nUser deleted");
        }
        else
        {
            printf("\nUser Id invalid");
        }
        
    }
    
    FILE *wptr;
    if(ch=='T')
    {
    	wptr=fopen("trainer_details.txt","w");
    }
    else if(ch == 'P')
    {
   	wptr=fopen("participant_details.txt","w");
    }
    wptr=write_user(wptr, head);
    fclose(wptr);
}

FILE* write_user(FILE *wptr, ud *head)
{
	ud *n=head;
	while(n!=NULL)
	{
		fprintf(wptr,"%s,%s,%s,%s,%s",n->name,n->pass,n->quali,n->mobno,n->email);
		n=n->next;
	}
	
	return wptr;
}
	
