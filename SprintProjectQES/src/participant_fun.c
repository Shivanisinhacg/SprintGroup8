/*************************************************************************************
 * *
 * * FILE NAME  : participant_fun.c
 * *
 * * DESCRIPTION : This function includes all the details of the participant
 * *
 * * REVISION HISTORY:
 * * DATE        NAME            REFERNCE         REASON
 * *
 * *23-11-2022   SprintGroup8    New              Initial Creation
 * *
 * *******************************************************************//*********************************************************************
				STANDARD HEADER FILES
* ********************************************************************/
#include "quiz.h"

extern char name[20];
/*********************************************************************
 * *
 * * FUNCTION NAME : participant_Memu
 * *
 * * DESCRIPTION   : It includes all the details of the participant menu
 * *
 * * RETURNS       : SUCCESS or FAILURE
 * *******************************************************************/

void participant_Menu()
{
	int ch;
	printf("\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	printf("\n\t\tWelcome To Quiz\n\n");
	printf("\t\t  RULES \n\n\tThere will be FIVE questions\n\tAnswering every question is compulsory\n\tEnter the correct option corresponding to the answer\n");
	printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	printf("\n\tPress 1 to play the quiz");
	printf("\n\tPress 9 to display Results");
	printf("\n\tPress 0 to exit\n\n\t");
	printf("\n\tChoose Option : ");

	scanf("%d",&ch);

	switch(ch){

		case 1 : 
			choosequiz();
			break;
		case 9 : 
			display_results();
			int next_step;
			printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
			printf("\n\tPress 1 to home page");
			printf("\n\tPress 2 to go to Login page");
			printf("\n\tPress 0 to exit\n\n\t");
			scanf("%d", &next_step);
	
			if(next_step==1)
			{
				participant_Menu();
			}
			else if(next_step==2)
			{
				menu();
			}
			else if(next_step==0)
			{
				exit(0);
			}
			break;
			
		case 0 : 
			exit(0);
			break;
	}
}
//Function for creating a new node
node_p *createNode_participant()
{
   node_p *head = (node_p *)malloc(sizeof(node_p) * 1);
   head->next = NULL;
   return head;
}


//Function for adding a new node in the beginning of the linked list.
node_p *addAtStart(node_p *head)
{
	
   node_p *n = createNode_participant();
   n->next = head;
   head = n;
   return head;
}
/*********************************************************************
 * *
 * * FUNCTION NAME : choosequiz
 * *
 * * DESCRIPTION   :This function lets you choose the quiz after displaying the quizcode.
 * *
 * * RETURNS        :SUCCESS or FAILURE
 * ********************************************************************/
void choosequiz(){
   
	int quizcode;
	printf("\n\n\t\t\tChoose Quiz\n");
	node *h;
	h = NULL;
	h=read_from_file_quiz(h);
	display_Quiz(h);
	printf("\n\tPress 0 to exit\n\n\t");
	printf("\n\tEnter Quiz code to continue : ");

	scanf("%d",&quizcode);

	searchquiz(quizcode);

}
/*********************************************************************
 * *
 * * FUNCTION NAME : searchquiz
 * * 
 * * DESCRIPTION   :This function uses the quizcode as the argument and searches the code in the quiz_ques.txt file
 * *
 * * RETURNS      : SUCCESS or FAILURE
 * ********************************************************************/
void searchquiz(int quizcode){
   int q1,q2,q3,q4,q5;
   FILE *fp;
   fp=fopen("quiz_ques.txt","r");
   char line[200];
   while(fgets(line,sizeof line ,fp)){
      char *token;
      token=strtok(line,",");
      int i=1;
      while(token!=NULL){
         if(i==1){
            if(atoi(token)==quizcode);
            else {token=NULL;continue;}
            }
         if(i==2)
            q1=atoi(token);
         if(i==3)
            q2=atoi(token);
         if(i==4)
            q3=atoi(token);
         if(i==5)
            q4=atoi(token);
         if(i==6){
            q5=atoi(token);
            break;
            }
         
         i++;
         token=strtok(NULL,",");
         
      }
      if(i==6) break;
   
   }
   
   fclose(fp);
   
   searchques(q1,q2,q3,q4,q5,quizcode);


}

/**********************************************************************
 * * 
 * * FUNCTION NAME :searchques
 * * 
 * * DESCRIPTION   :This function searches a question with question id
 * *
 * * RETURNS       : SUCCESS or FAILURE
 * *******************************************************************/
void searchques(int q1,int q2,int q3,int q4,int q5, int quizcode){
    
   int q[]={q1,q2,q3,q4,q5};
   
   node_p *head;
   head=createNode_participant();
   FILE *fp1;
   fp1=fopen("questions.txt","r");
   
   char line[200];
   int j=0;
   for(int k=0;k<5;k++){
   
   while(fgets(line,sizeof line ,fp1)){
      
      char *token;
      token=strtok(line,",");
      int i=1;
      while(token!=NULL){
      
         if(i==1){
            if(atoi(token)==q[k])
               head->ques_ID=atoi(token);
            else {token=NULL;continue;}
            }
         if(i==2)
            strcpy(head->ques_desc,token);
         if(i==3)
            strcpy(head->option1,token);
         if(i==4)
            strcpy(head->option2,token);
         if(i==5)
            strcpy(head->option3,token);
         if(i==6)
            strcpy(head->option4,token);
         if(i==7){
            head->correctop=atoi(token);;break;}
         
         i++;
         token=strtok(NULL,",");
         
      }
      
      
      
      if(i==7) break;
   
   }
   ++j;
   if(j<5)
   head=addAtStart(head);
   rewind(fp1);
   }
   startquiz(head, quizcode);
   fclose(fp1);

}
/***********************************************************************************
 * *
 * * FUNCTION NAME :startquiz
 * *
 * * DESCRIPTION  :This function uses a pointer argument of the type struct.
 * *
 * * RETURNS      : SUCCESS 
 * ********************************************************************************/
void startquiz(node_p *head, int quizcode){
   
	node_p *n=head;
	int marks=0;
	FILE *fp;
	fp=fopen("results.txt","a");
	printf("\n\n\n");
	
	fprintf(fp,"%s,", name);
	fprintf(fp,"%d,", quizcode);

	   while(n!=NULL){
		printf("%s\n%s\n%s\n%s\n%s\n\nAnswer - ",n->ques_desc,n->option1,n->option2,n->option3,n->option4);
		scanf("%d", &n->answer);
		printf("\n");
		fprintf(fp,"%d,%d,",n->answer,n->correctop);
		if(n->answer == n->correctop)
		{
			++marks;}
		n=n->next;
	}
	fprintf(fp,"%d",marks);
	fprintf(fp,"\n");

	printf("\n\tTHE QUIZ IS OVER!!!\n");
	printf("\n\tYou obtained %d marks out of 5 \n",marks);
	fclose(fp);
	
	int next_step;
	printf("\n\tPress 1 to home page");
	printf("\n\tPress 2 to go to Login page");
	printf("\n\tPress 0 to exit\n\n\t");
	scanf("%d", &next_step);
	
	if(next_step==1)
	{
		participant_Menu();
	}
	else if(next_step==2)
	{
		menu();
	}
	else if(next_step==0)
	{
		return;
	}
}
