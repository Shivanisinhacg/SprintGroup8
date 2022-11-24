/************************************************************************************
 * *
 * * FILE NAME : remove.c
 * *
 * * DESCRIPTION : This program is used to add or delete questions to a particular quiz
 * *
 * *Revision History
 * *DATE		NAME			REFERNCE 		REASON
 * *23-11-2022          SprintGroup8             New                     Initial Creation
 * *
 * *Copyright 2022, Altran Group All Rights Reserved
 * ****************************************************************************************/
 /*****************************************************************************************
  * 				STANDARD HEADER FILE
  * ***************************************************************************************/				
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



	
