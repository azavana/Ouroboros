/*Andry Rafam Andrianjafy - October 2018.

KRATOS: Multiple encryption text program based on RC4A_SPRITZ, SHA 256 and SHA 384.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <openssl/sha.h>
#include "HEADER.h"

// Driver program			
int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\nUsage: %s < Plaintext >\n\n", argv[0]);
		return -1;
	}
	
	// Salt the clear message before performing encryption
	unsigned char *stage0 = malloc(sizeof(unsigned char) * (8 + strlen(argv[1])));
	assert (stage0 != NULL);
	
	strcpy (stage0, argv[1]);
	strcat (stage0, salt());

	printf("\n\n=================== KRATOS ENCRYPTION PROGRAM ====================\n\n");
	printf("[ STAGE_0 ]\n\n");
	printf(">> %s\n", stage0);

	unsigned char *stage1 = malloc(sizeof(int) * strlen(stage0));
	assert (stage1 != NULL);

	KRATOS_Encrypt (stage0, KRATOS_Key(), stage1);

	printf("\n\n");
	
	printf("[ STAGE_1 ]\n\n");
	printf(">> ");
	for (int v = 0; v < strlen(argv[1]); v++)
		printf("%02X%c", stage1[v], v < (strlen(argv[1]) - 1) ? ' ' : '\n');
	printf("\n\n");

	

	unsigned char *stage2 = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
	assert (stage2 != NULL);
	SHA256 (stage1, strlen(stage1), stage2);
	
	printf("[ STAGE_2 ]\n\n");
	printf(">> ");
	for (int x = 0; x < SHA256_DIGEST_LENGTH; x++)
		printf("%02X%c", stage2[x], x < (SHA256_DIGEST_LENGTH - 1) ? ' ' : '\n');
	printf("\n\n");



	unsigned char *stage3 = malloc(sizeof(unsigned char) * SHA384_DIGEST_LENGTH);
	assert (stage3 != NULL);
	SHA384 (swap_character(stage2), strlen(stage2), stage3); // Swap the character two by two before the final stage

	printf("[ FINAL STAGE ]\n\n");
	printf(">> ");
	for (int y = 0; y < SHA384_DIGEST_LENGTH; y++)
		printf("%02X%c", stage3[y], y < (SHA384_DIGEST_LENGTH - 1) ? ' ' : '\n');
	printf("\n\n");
	

	free (stage0);
	free (stage1);
	free (stage2);
	free (stage3);

	return EXIT_SUCCESS;
}


	
