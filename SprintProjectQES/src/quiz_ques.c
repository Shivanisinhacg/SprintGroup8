/*************************************************************************************
 * *
 * * FILE NAME : vi quiz_ques.c
 * *
 * * DESCRIPTION : This function to add or update in particular quiz
 * *
 * * REVISION HISTORY
 * *
 * * DATE 		NAME		REFERNCE	REASON
 * *
 * * 23-11-2022        SprintGroup8    New              Initial Creation
 * *
 * *Copyright 2022, Altran Group All Rights Reserved
 * *
 * **********************************************************************************/ 
/************************************************************************************
 * *			STANDARD HEADER FILES
 * **********************************************************************************/
#include "quiz.h"

//Function for creating a new node
QQ *createNode()
{
   QQ *head = (QQ *)malloc(sizeof(QQ) * 1);
   head->next = NULL;
   return head;
}


//Function for adding a new node in the beginning of the linked list.
QQ *addfirst(QQ *head)
{
	
   QQ *n = createNode();
   n->next = head;
   head = n;
   return head;
}

//Function for loading all the data from quiz_ques.txt file to a linked list.
QQ *loadques(){

   QQ *head =createNode();
   int j=0;
	
   FILE *fp3;
   fp3=fopen("quiz_ques.txt","r");
   
   
   char line[200];
   
   while(fgets(line,sizeof line ,fp3)){
      char *token;
      token=strtok(line,",");
      int i=1;
      if(j==1)
      head=addfirst(head);
      while(token!=NULL){
         if(i==1)
            head->quiz_ID=atoi(token);
         if(i==2)
            head->ques_1=atoi(token);
         if(i==3)
            head->ques_2=atoi(token);
         if(i==4)
            head->ques_3=atoi(token);
         if(i==5)
            head->ques_4=atoi(token);
         if(i==6)
            head->ques_5=atoi(token);
         
         i++;
         token=strtok(NULL,",");
         
      }
      j=1;
      
   }
   
   fclose(fp3);
   return head;
}
/***********************************************************************************
 * *
 * * FUNCTION NAME : unloadques
 * *
 * * DESCRIPTION   :Function for unloading all the data from a linked list to quiz_ques.txt file
 * * 
 * * RETURNS       : SUCCESS or FAILURE
 * ********************************************************************************/
void unloadques(QQ *head){

   FILE *fp3;
   fp3 = fopen("quiz_ques.txt","w");
   QQ *n = head;
   while(n!=NULL)
   {
      fprintf(fp3,"%d,%d,%d,%d,%d,%d\n",n->quiz_ID,n->ques_1,n->ques_2,n->ques_3,n->ques_4,n->ques_5);
      n=n->next;
   }
   fclose(fp3);

}

/**********************************************************************************
 * *
 * * FUNCTION NAME : addquesid
 * *
 * * DESCRIPTION  : This function is used to add questions to particular quiz id
 * *
 * * RETURNS      : SUCCESS or FAILURE
 * ********************************************************************************/
void addquesid(){
   
   
   QQ *head = loadques();
   head=addfirst(head);
   printf("\nEnter Quiz ID : ");
   scanf("%d",&head->quiz_ID);
   printf("\nEnter First Question ID : ");
   scanf("%d",&head->ques_1);
   printf("\nEnter Second Question ID : ");
   scanf("%d",&head->ques_2);
   printf("\nEnter Third Question ID : ");
   scanf("%d",&head->ques_3);
   printf("\nEnter Fourth Question ID : ");
   scanf("%d",&head->ques_4);
   printf("\nEnter Fifth Question ID : ");
   scanf("%d",&head->ques_5);
   
   unloadques(head);
   

}
/**********************************************************************************
 * *
 * * FUNCTION NAME : updatequesid
 * *
 * * DESCRIPTION  : This function is used to  update questions with their quiz ids
 * *
 * * RETURNS      : SUCCESS or FAILURE
 * *******************************************************************************/
void updatequesid(){

   QQ *head = loadques();
   int id;
   printf("\nEnter Quiz ID to update : ");
   scanf("%d",&id);
   
   QQ *n = head;
   while(n->quiz_ID!=id)
      n=n->next;
   
   do{
   printf("\nFirst Question ID : %d",n->ques_1);
   printf("\nSecond Question ID : %d",n->ques_2);
   printf("\nThird Question ID : %d",n->ques_3);
   printf("\nFourth Question ID : %d",n->ques_4);
   printf("\nFifth Question ID : %d",n->ques_5);
   
   
   printf("\n\nWhich Question ID do you want to update?\n1, 2, 3, 4 or 5\nEnter : ");
   scanf("%d",&id);
   printf("\n");
   switch(id){
   case 1 : printf("Enter new First Question ID :");
            scanf("%d",&n->ques_1);
            break;
   case 2 : printf("Enter new Second Question ID :");
            scanf("%d",&n->ques_2);
            break;
   case 3 : printf("Enter new Third Question ID :");
            scanf("%d",&n->ques_3);
            break;
   case 4 : printf("Enter new Fourth Question ID :");
            scanf("%d",&n->ques_4);
            break;
   case 5 : printf("Enter new Fifth Question ID :");
            scanf("%d",&n->ques_5);
            break;
   default : printf("Error! Type a number between 1 to 5\n");
   }
   
   printf("\nDo you want to continue updating?\nType 0 to continue or 1 to exit : ");
   scanf("%d",&id);
   }while(id!=1);
   
   
   
   unloadques(head);

}
