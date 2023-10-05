CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

WAYlAB1 = ./lab_1/
WAYlAB2 = ./lab_2/
WAYlAB3 = ./lab_3/
WAYlAB4 = ./lab_4/
WAYlAB5 = ./lab_5/
WAYlAB6 = ./lab_6/
WAYlAB7 = ./lab_7/
WAYlAB8 = ./lab_8/
WAYlAB9 = ./lab_9/
WAYlAB10 = ./lab_10/
WAYlAB11 = ./lab_11/
WAYlAB12 = ./lab_12/

FUNCLAB1 = $(WAYlAB1)*.c
FUNCLAB2 = $(WAYlAB2)*.c
FUNCLAB3FOR = $(WAYlAB3)*for.c
FUNCLAB3WH = $(WAYlAB3)*while.c
FUNCLAB4 = $(WAYlAB4)*.c
FUNCLAB5 = $(WAYlAB5)*.c
FUNCLAB6 = $(WAYlAB6)*.c
FUNCLAB7 = $(WAYlAB7)*.c
FUNCLAB8 = $(WAYlAB8)*.c
FUNCLAB9 = $(WAYlAB9)*.c
FUNCLAB10 = $(WAYlAB10)*.c
FUNCLAB11 = $(WAYlAB11)*.c
FUNCLAB12 = $(WAYlAB12)*.c

lab_1: clean lab_1.o
	$(CC) $(CFLAGS) lab_1.o -o test

lab_1.o: $(FUNCLAB1)
	$(CC) -c $(CFLAGS) $(FUNCLAB1) -o lab_1.o

lab_2: clean lab_2.o
	$(CC) $(CFLAGS) lab_2.o -o test -lm

lab_2.o: $(FUNCLAB2)
	$(CC) -c $(CFLAGS) $(FUNCLAB2) -o lab_2.o

lab_3_for : clean lab_3_for.o
	$(CC) $(CFLAGS) lab_3_for.o -o testFo -lm

lab_3_Wh: clean lab_3_while.o
	$(CC) $(CFLAGS) lab_3_while.o -o testWh -lm

lab_3_for.o : $(FUNCLAB3FOR)
	$(CC) -c $(CFLAGS) $(FUNCLAB3FOR) -o lab_3_for.o

lab_3_while.o : $(FUNCLAB3Wh)
	$(CC) -c $(CFLAGS) $(FUNCLAB3WH) -o lab_3_while.o -lm

lab_4: clean lab_4.o
	$(CC) $(CFLAGS) lab_4.o -o test -lm 

lab_4.o: $(FUNCLAB4)
	$(CC) -c $(CFLAGS) $(FUNCLAB4) -o lab_4.o

lab_5: clean lab_5.o
	$(CC) $(CFLAGS) lab_5.o -o test

lab_5.o: $(FUNCLAB5)
	$(CC) -c $(CFLAGS) $(FUNCLAB5) -o lab_5.o

lab_6: lab_6.o
	$(CC) $(CFLAGS) lab_6.o -o test

lab_6.o: $(FUNCLAB6)
	$(CC) -c $(CFLAGS) $(FUNCLAB6) -o lab_6.o

lab_7: lab_7.o
	$(CC) $(CFLAGS) lab_7.o -o test

lab_7.o: $(FUNCLAB7)
	$(CC) -c $(CFLAGS) $(FUNCLAB7) -o lab_7.o

lab_8: lab_8.o
	$(CC) $(CFLAGS) lab_8.o -o test

lab_8.o: $(FUNCLAB8)
	$(CC) -c $(CFLAGS) $(FUNCLAB8) -o lab_8.o

lab_9: lab_9.o
	$(CC) $(CFLAGS) lab_9.o -o test

lab_9.o: $(FUNCLAB9)
	$(CC) -c $(CFLAGS) $(FUNCLAB9) -o lab_9.o

lab_10: lab_10.o
	$(CC) $(CFLAGS) lab_10.o -o test

lab_10.o: $(FUNCLAB10)
	$(CC) -c $(CFLAGS) $(FUNCLAB10) -o lab_10.o

lab_11: lab_11.o
	$(CC) $(CFLAGS) lab_11.o -o test

lab_11.o: $(FUNCLAB11)
	$(CC) -c $(CFLAGS) $(FUNCLAB11) -o lab_11.o

lab_12: lab_12.o
	$(CC) $(CFLAGS) lab_12.o -o test

lab_12.o: $(FUNCLAB12)
	$(CC) -c $(CFLAGS) $(FUNCLAB12) -o lab_12.o


cl: 
	clang-format -i ./*/*.c

clean:
	rm -f *.o test

cllab3:
	rm -f *.o testFo testWh