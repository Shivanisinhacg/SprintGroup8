all: quiz

quiz: quiz_def.o login_test.o admin_fun.o trainer_fun.o participant_fun.o quiz_ques.o delete.o quiz_client.o
	gcc quiz.h quiz_def.c login_test.c admin_fun.c trainer_fun.c participant_fun.c validation.c quiz_ques.c delete.c quiz_client.c -o quiz
	
quiz_client.o: quiz_client.c
	gcc -c quiz.h quiz_client.c 
	
quiz_def.o: quiz_def.c
	gcc -c quiz_def.c
	
login_test.o: login_test.c
	gcc -c login_test.c
	
admin_fun.o: admin_fun.c
	gcc -c admin_fun.c
	
trainer_fun.o: trainer_fun.c
	gcc -c trainer_fun.c
	
participant_fun.o: participant_fun.c
	gcc -c participant_fun.c
	
validation.o: validation.c
	gcc -c validation.c
	
delete.o: delete.c
	gcc -c delete.c
	
quiz_ques.o: quiz_ques.c
	gcc -c quiz_ques.c
	
