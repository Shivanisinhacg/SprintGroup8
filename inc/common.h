#ifndef QUIZ_H
#define QUIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
void welcomePage();
void menu();
void login(char);
int check(FILE *);
void entry(FILE *);
int validate_number(char *);
int validate_email(char *);
typedef struct Quiz
{
	int quiz_id;
	char quiz_desc[200];
}quiz;
typedef struct Quiz_LL
{
	quiz q;
	struct Quiz_LL *next;
}node;
void admin_Menu();
void display_Participants();
void display_Trainers();
node* read_from_file_quiz( node*);


