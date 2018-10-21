#ifndef __HEADER_h__
#define __HEADER_h__

int GCD (int a, int b);
/*Use in the PRG function*/


void swap (unsigned char *a, unsigned char *b);
/*Use in KSA and PRG functions*/


unsigned char *swap_character (unsigned char *text);
/*Swap character two by two like this:
Swap the first character with the second, the third with the fourth and so on.*/


void KSA (char *key, unsigned char S[256]);
/*Key Scheduling Algorithm*/


void PRG (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext);
/*Pseudo random generator*/


void KRATOS_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);
/*The encryption function of the program.*/


unsigned char *KRATOS_Key();
/*Key generator for the encrytpion*/


char *salt();
/*Salting the clear message before performing any encryption.*/


#endif
