// All functions used in the program

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int GCD (int a, int b)
{
	if (a > b)
	{
		if (a % b == 0)
			return b;
		else
			return GCD(b,a%b);
	}
	else if (b > a)
	{
		if (b % a == 0)
			return a;
		else
			return GCD(a,b%a);
	}
}

void swap (unsigned char *a, unsigned char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

unsigned char *swap_character (unsigned char *text)
{
	unsigned char *result = malloc(sizeof(unsigned char) * strlen(text));
	assert (result != NULL);

	if (strlen(text) % 2 == 0)
	{
		for (int i = 0; i < strlen(text); i += 2)
		{
			swap (&text[i], &text[i+1]);
			result[i] = text[i];
			result[i+1] = text[i+1];
		}
	}
	else
	{
		for (int i = 0; i < strlen(text) - 1; i += 2)
		{
			swap (&text[i], &text[i+1]);
			result[i] = text[i];
			result[i+1] = text[i+1];
		}
		result[strlen(text)-1] = text[strlen(text)-1];
	}
	return result;
}

void KSA (char *key, unsigned char S[256])
{
	for (int i = 0; i < 256; i++)
		S[i] = i;

	int j = 0;

	for (int i = 0; i < 256; i++)
	{
		j = (j + S[i] + key[i % strlen(key)]) % 256;
		swap (&S[i], &S[j]);
	}
	return;
}

// Here RC4A_SPRITZ is a combination of RC4A and SPRITZ; two of updated version of RC4
void RC4A_SPRITZ (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext)
{
	int i = 0;
	int j1 = 0, j2 = 0;
	int k1 = 0, k2 = 0;
	int w1 = 0, w2 = 0;
	int z1 = 0, z2 = 0;

	srand(time(NULL));

	for (int n = 0; n < strlen(plaintext); n++)
	{
		do
		{
			w1 = rand() % 256 + 1; // w1 is relatively prime to S1 size; 256
		} while (GCD(w1,256) != 1);

		i = (i + w1) % 256;
		j1 = (k1 + S1[j1] + S1[i]) % 256;
		k1 = (k1 + i + S1[j1]) % 256;
		swap (&S1[i], &S1[j1]);
		z1 = S2[(j1 + S1[i + S1[z1 + k1]]) % 256];

		ciphertext[n] = z1^plaintext[n];
	}
	
	for (int k = 0; k < strlen(ciphertext); k++)
	{
		do
		{
			w2 = rand() % 256 + 1; // w2 is relatively prime to S2 size; 256
		} while (GCD(w2,256) != 1);

		i = (i + w2) % 256;
		j2 = (k2 + S2[j2] + S2[i]) % 256;
		k2 = (k2 + i + S2[j2]) % 256;
		swap (&S2[i], &S2[j2]);
		z2 = S1[(j2 + S2[i + S2[z2 + k2]]) % 256];

		ciphertext[k] = z2^ciphertext[k];
	}
	return;
}

void KRATOS_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext)
{
	unsigned char S1[256];
	unsigned char S2[256];

	KSA (key, S1);
	KSA (key, S2);

	RC4A_SPRITZ (S1, S2, plaintext, ciphertext);

	return;
}

unsigned char *KRATOS_Key() // Generate randomly the key
{
	srand(time(NULL));
	int len = rand() % 256 + 5; // Key length between 5 Bytes (40 bits) and 256 Bytes (2048 bits)
	unsigned char *Key = malloc(sizeof(unsigned char) * len);
	assert (Key != NULL);

	for (int i = 0; i < len; i++)
	{
		int random = rand() % 2;
		int key = rand() % 26;
		if (random == 0)
			Key[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			Key[i] = (char)((key-97) % 26 + 97);
	}
	return Key;
}

char *salt () // Salt the clear message
{
	unsigned char *string = malloc(sizeof(unsigned char) * 8);
	assert (string != NULL);
	srand(time(NULL));
	int i = 0;

	while (i < 8)
	{
		int random = rand() % 2;
		int key = rand() % 26;

		if (random == 0)
			string[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			string[i] = (char)((key-97) % 26 + 97);
		i += 1;
	}
	return string;
}

	

