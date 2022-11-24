CC = gcc
ProjDir = /home/vasanthi/SprintGroup8/SprintProjectQES

INC = $(ProjDir)/inc
SRC = $(ProjDir)/src
OBJ = $(ProjDir)/obj
BIN = $(ProjDir)/bin
CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)
all: QES

QES: $(OBJ)/admin_fun.o $(OBJ)/delete.o $(OBJ)/login_test.o $(OBJ)/participant_fun.o $(OBJ)/quiz_client.o $(OBJ)/quiz_def.o $(OBJ)/quiz_ques.o $(OBJ)/remove.o $(OBJ)/trainer_fun.o $(OBJ)/validation.o
	$(CC) $(LDFLAGS) $(BIN)/QES  $(OBJ)/admin_fun.o $(OBJ)/delete.o $(OBJ)/login_test.o $(OBJ)/participant_fun.o $(OBJ)/quiz_client.o $(OBJ)/quiz_def.o $(OBJ)/quiz_ques.o $(OBJ)/remove.o $(OBJ)/trainer_fun.o $(OBJ)/validation.o 
	
$(OBJ)/admin_fun.o: $(SRC)/admin_fun.c
	$(CC) $(CFLAGS) $(SRC)/admin_fun.c $(IFLAGS)
	mv admin_fun.o $(OBJ)/

$(OBJ)/delete.o: $(SRC)/delete.c
	$(CC) $(CFLAGS) $(SRC)/delete.c $(IFLAGS)
	mv delete.o $(OBJ)/

$(OBJ)/login_test.o: $(SRC)/login_test.c
	$(CC) $(CFLAGS) $(SRC)/login_test.c $(IFLAGS)
	mv login_test.o $(OBJ)/

$(OBJ)/participant_fun.o: $(SRC)/participant_fun.c
	$(CC) $(CFLAGS) $(SRC)/participant_fun.c $(IFLAGS)
	mv participant_fun.o $(OBJ)/

$(OBJ)/quiz_client.o: $(SRC)/quiz_client.c
	$(CC) $(CFLAGS) $(SRC)/quiz_client.c $(IFLAGS)
	mv quiz_client.o $(OBJ)/

$(OBJ)/quiz_def.o: $(SRC)/quiz_def.c
	$(CC) $(CFLAGS) $(SRC)/quiz_def.c $(IFLAGS)
	mv quiz_def.o $(OBJ)/

$(OBJ)/quiz_ques.o: $(SRC)/quiz_ques.c
	$(CC) $(CFLAGS) $(SRC)/quiz_ques.c $(IFLAGS)
	mv quiz_ques.o $(OBJ)/

$(OBJ)/remove.o: $(SRC)/remove.c
	$(CC) $(CFLAGS) $(SRC)/remove.c $(IFLAGS)
	mv remove.o $(OBJ)/

$(OBJ)/trainer_fun.o: $(SRC)/trainer_fun.c
	$(CC) $(CFLAGS) $(SRC)/trainer_fun.c $(IFLAGS)
	mv trainer_fun.o $(OBJ)/

$(OBJ)/validation.o: $(SRC)/validation.c
	$(CC) $(CFLAGS) $(SRC)/validation.c $(IFLAGS)
	mv validation.o $(OBJ)/

clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"





