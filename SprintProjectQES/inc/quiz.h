/***************************************************************************************
 * *
 * * FILE NAME : quiz.h
 * *
 * * DEscription : This program includes the headers and the functions
 * *
 * *************************************************************************************/
#ifndef QUIZ_H
#define QUIZ_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*declaration of functions*/
void welcomePage();/*function with welcome page details*/
void menu();/*function that displays menu of different users*/
void login(char);/*function to validate the login of user*/
int check(FILE *);/*Declaration of function to validate login credentials*/
void entry(FILE *);/*Declaration of function to enter details of new user*/
int validate_number(char *);/*Declaration of function to validate phone number*/
int validate_email(char *);/*Declaration of function to validate email id*/
typedef struct Quiz{
	   int quiz_id;
	   char quiz_desc[200];
}quiz;/*structure defining to quiz*/

/*struct LinkeList to store Quiz details in a node*/
typedef struct Quiz_LL{
	        quiz q;
		struct Quiz_LL *next;
}node;
void admin_Menu();/*function to display admin tasks*/
void display_Participants();/*function to display participants*/
void display_Trainers();/*function to display trainers*/

/*Function to read data from the file*/
/*Parameters are head pointer of the linked list and file pointer & Returns the head pointer of the linked list*/
node* read_from_file_quiz( node* );
/*Function to create a node for the linked list*/
node* create_node_quiz(quiz);
node* add_node_quiz(node*, node*, FILE*);/*Function to add a node to the linked list*/
node* delete_Quiz(int,node*);/*Function to delete a record using question Id*/
void display_Quiz(node *head);/*Paramaters: integer, head pointer of the linked list and  no return type*/

/*Function to load the contents from the linked list and store into the file after all the operations*/
FILE* write_to_file_quiz(FILE*, node*);
void display_results();/*Function to display results and quiz attempted*/

/***************TRAINER FUNCTION DECLARATIONS******************/
typedef struct Question{
	int ques_id;
	char ques_desc[200];
	char option1[15];
	char option2[15];
	char option3[15];
	char option4[15];
	int correctop;
}question;

/*struct LinkeList to store Quiz details in a node*/
typedef struct Question_LL{
	question que;
	struct Question_LL *next;
}q_node;
void trainer_Menu();/*function to display admin tasks*/
q_node* read_from_file_question( q_node* );/*Function to read data from the file*/
q_node* create_node_question(question);/*Function to create a node for the linked list*/
q_node* add_node_question(q_node*, q_node*, FILE*);/*Function to add a node to the linked list*/
void display_question(int id,q_node*);/*Function to display the question details*/
q_node* update_question(int,q_node*);/*Function to update a record using question details*/
q_node* delete_question(int,q_node*);/*Function to delete a record using question Id*/
void displayall_question(q_node *head);/*Function to display all the question details*/
FILE* write_to_file_question(FILE*, q_node*);/*Function to load the contents from the linked list and store into the file after all the operations*/

/**************PARTICIPANT FUNCTION DECLARATIONS******************/
typedef struct Quiz_participant
{
	int ques_ID;
	char ques_desc[200];
	char option1[15];
	char option2[15];
	char option3[15];
	char option4[15];
	int correctop;
	int answer;
	struct Quiz_participant *next;

}node_p;
void participant_Menu();/*Participant menu function*/
node_p *createNode_participant();/*Function used for creating a node*/
node_p *addAtStart(node_p*);/*Function for adding a new node in the beginning of the linked list*/
void choosequiz();/*Function used to choose the quiz*/
void searchquiz(int);/*Function used for searching the given quizcode in the quiz_ques.txt file*/
void searchques(int,int,int,int,int,int);/*Function used for searching the specific quiz questions in the questions.txt file*/
void startquiz(node_p*,int);/*Function used for starting the quiz*/

/***************QUIZ QUESTION FUNCTION DECLARATIONS******************/
typedef struct Quiz_Question{
	int quiz_ID;
	int ques_1;
	int ques_2;
	int ques_3;
	int ques_4;
	int ques_5;
	struct Quiz_Question *next;
}QQ;
QQ *createNode();/*Function for creating a new node*/
QQ *addfirst(QQ*);/*Function for adding a new node in the beginning of the linked list*/
QQ *loadques();/*Function for loading all the data from quiz_ques.txt file to a linked list*/
void unloadques(QQ*);/*Function for unloading all the data from a linked list to quiz_ques.txt file*/
void addquesid();/*Function for adding a single quiz ID followed by 5 question IDs*/
void updatequesid();/*Function for updating question IDs of any quiz IDs*/

/***************DELETE USER FUNCTIONS******************/

typedef struct user_del{
      	char name[30];
	char pass[30];
	char quali[100];
	char mobno[20];
	char email[50];
	struct user_del *next;
}ud;
ud *createNodeUser();/*Function for creating a new node*/
ud *addfirstUser(ud*);/*Function for adding a new node in the beginning of the linked list*/
ud *loadUser(char);/*Function for loading all the data from participant_details.txt file to a linked list*/
void unloadUser(ud*, char);/*Function for unloading all the data from the linked list to participant_details.txt file*/
FILE* write_user(FILE*, ud*);
#endif
