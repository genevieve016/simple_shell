#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - creates a UNIX command line interpreter
 * 
 * Returns: always 0
 */

int main(int ac, char **argv)
{
	char *prmpt = "simple_shell $";
	char *lin3ptr;
	size_t bufrsize = 0;

	/* declaing void arg*/
	(void)ac;
	(void)argv;

	printf("%s", prmpt);
	getline(&lin3ptr, &bufrsize, stdin);
	printf("%s\n", lin3ptr);

free(lin3ptr);
return (0);
}
