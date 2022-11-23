#include "quiz.h"


//Function for creating a new node
ud *createNodeUser1()
{
   ud *head = (ud *)malloc(sizeof(ud) * 1);
   head->next = NULL;
   return head;
}


//Function for adding a new node in the beginning of the linked list.
ud *addfirstUser1(ud *head)
{
	
   ud *n = createNodeUser1();
   n->next = head;
   head = n;
   return head;
}

//Function for loading all the data from participant_details.txt file to a linked list.
ud *loadUser1(char ch){

   ud *head =createNodeUser1();
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
      head=addfirstUser1(head);
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

//Function for unloading all the data from the linked list to participant_details.txt file
void unloadUser(ud *head, char ch){

   FILE *fp3;
   if(ch=='T')
   {
   	fp3=fopen("trainer_details.txt","w");
   }
   else if(ch == 'P')
   {
   	fp3=fopen("participant_details.txt","w");
   }
   ud *n = head;
   while(n!=NULL)
   {
      fprintf(fp3,"%s,%s,%s,%s,%s",n->name,n->pass,n->quali,n->mobno,n->email);
      n=n->next;
   }
   fclose(fp3);

}

//Function for deleting participant details
void delete_user1(char ch){

   ud *head = loadUser1(ch);
   char id[30];
   int x=0;
   printf("\nEnter the participant name to delete : ");
   scanf("%s",id);
   ud *n = head,*prev=head;
   while(strcmp(n->name,id)!=0){
      x=1;
      prev=n;
      n=n->next;
   }
   if(x==0){
      head=head->next;
      free(prev);
      }
   else{
      prev->next=n->next;
      printf("%s : Deleted\n", id); 
      free(n);
   }
   
   unloadUser(head, ch);

}
