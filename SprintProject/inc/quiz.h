#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*declaration of functions*/

/*function with welcome page details*/
void welcomePage();

/*function that displays menu of different users*/
void menu();

/*function to validate the login of user*/
void login(char);

/*Declaration of function to validate login credentials*/
int check(FILE *);

/*Declaration of function to enter details of new user*/
void entry(FILE *);



/***************VALIDATION FUNCTION DECLARATIONS******************/
/*Declaration of function to validate phone number*/
int validate_number(char *);

/*Declaration of function to validate email id*/
int validate_email(char *);



/***************ADMIN FUNCTION DECLARATIONS******************/


typedef struct Quiz{
	   int quiz_id;
	   char quiz_desc[200];
}quiz;

/*struct LinkeList to store Quiz details in a node*/
typedef struct Quiz_LL{
	        quiz q;
		struct Quiz_LL *next;
}node;


/*function to display admin tasks*/
void admin_Menu();

/*function to display participants*/
void display_Participants();

/*function to display trainers*/
void display_Trainers();

/*Function to read data from the file*/
/*Parameters are head pointer of the linked list and file pointer & Returns the head pointer of the linked list*/
node* read_from_file_quiz( node* );
/*Function to create a node for the linked list*/
/*Paramaters are structure variable of doctor and returns the new node created*/
node* create_node_quiz(quiz);


/*Function to add a node to the linked list*/
/*Paramaters: 2 pointers of linked list*/
node* add_node_quiz(node*, node*, FILE*);


/*Function to delete a record using question Id*/
/*Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list*/
node* delete_Quiz(int,node*);

/*Function to display all the question details*/
/*Paramaters: integer, head pointer of the linked list and  no return type*/
void display_Quiz(node *head);


/*Function to load the contents from the linked list and store into the file after all the operations*/
/*Paramaters: file pointer and head pointer of the linked list and  returns the file pointer*/
FILE* write_to_file_quiz(FILE*, node*);

/*Function to display results and quiz attempted*/
/*parameters: Participant ID*/
void display_results();

/*Function to delete participant from the quiz application*/
void delete_user(char);

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

/*function to display admin tasks*/
void trainer_Menu();

/*Function to read data from the file*/
/*Parameters: head pointer of the linked list and file pointer*/
/*Returns the head pointer of the linked list*/
q_node* read_from_file_question( q_node* );


/*Function to create a node for the linked list*/
/*Paramaters: structure variable of doctor and returns the new node created*/
q_node* create_node_question(question);


/*Function to add a node to the linked list*/
/*Paramaters: 2 pointers of linked list*/
q_node* add_node_question(q_node*, q_node*, FILE*);

/*Function to display the question details*/
/*Paramaters: integer, head pointer of the linked list and  no return type*/
void display_question(int id,q_node*);


/*Function to update a record using question Id*/
/*Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list*/
q_node* update_question(int,q_node*);


/*Function to delete a record using question Id*/
/*Paramaters: integer and head pointer of the linked list and return type: head pointer of the updated list*/
q_node* delete_question(int,q_node*);
/*Function to display all the question details*/
/*Paramaters: integer, head pointer of the linked list and  no return type*/
void displayall_question(q_node *head);

/*Function to load the contents from the linked list and store into the file after all the operations*/
/*Paramaters: file pointer and head pointer of the linked list and  returns the file pointer*/
FILE* write_to_file_question(FILE*, q_node*);



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

/*Participant menu function*/
void participant_Menu();

/*Function used for creating a node*/
node_p *createNode_participant();

/*Function for adding a new node in the beginning of the linked list*/
node_p *addAtStart(node_p*);

/*Function used to choose the quiz*/
void choosequiz();

/*Function used for searching the given quizcode in the quiz_ques.txt file*/
void searchquiz(int);

/*Function used for searching the specific quiz questions in the questions.txt file*/
void searchques(int,int,int,int,int,int);

/*Function used for starting the quiz*/
void startquiz(node_p*,int);


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

/*Function for creating a new node*/
QQ *createNode();

/*Function for adding a new node in the beginning of the linked list*/
QQ *addfirst(QQ*);

/*Function for loading all the data from quiz_ques.txt file to a linked list*/
QQ *loadques();

/*Function for unloading all the data from a linked list to quiz_ques.txt file*/
void unloadques(QQ*);

/*Function for adding a single quiz ID followed by 5 question IDs*/
void addquesid();

/*Function for updating question IDs of any quiz IDs*/
void updatequesid();

/***************DELETE USER FUNCTIONS******************/

typedef struct user_del{
      	char name[30];
	char pass[30];
	char quali[100];
	char mobno[20];
	char email[50];
	struct user_del *next;
}ud;

/*Function for creating a new node*/
ud *createNodeUser();

/*Function for adding a new node in the beginning of the linked list*/
ud *addfirstUser(ud*);

/*Function for loading all the data from participant_details.txt file to a linked list*/
ud *loadUser(char);

/*Function for unloading all the data from the linked list to participant_details.txt file*/
void unloadUser(ud*, char);
/*FILE* write_user(FILE*, ud*);*/
