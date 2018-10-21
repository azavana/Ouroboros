KRATOS.exe : KRATOS.o FUNCTIONS.o
	gcc KRATOS.o FUNCTIONS.o -o KRATOS.exe -I. -lcrypto
KRATOS.o : KRATOS.c HEADER.h
	gcc -c -I. KRATOS.c -lcrypto
FUNCTIONS.o : FUNCTIONS.c
	gcc -c FUNCTIONS.c
