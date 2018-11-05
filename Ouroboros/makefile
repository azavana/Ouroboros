Ouroboros.exe : Ouroboros.o Basic_Function.o RC4A_Spritz.o
	gcc Ouroboros.o Basic_Function.o RC4A_Spritz.o -o Ouroboros.exe -lssl -lcrypto
Ouroboros.o : Ouroboros.c Core.h Colors.h
	gcc -c -I. Ouroboros.c -lssl -lcrypto
Basic_Function.o : Basic_Function.c
	gcc -c Basic_Function.c
RC4A_Spirtz.o : RC4A_Spirtz.c Core.h
	gcc -c RC4A_Spritz.c
	
