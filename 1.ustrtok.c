#include <stdio.h>
#include <string.h>


int main(void)
{

	char a[] = "hello; hello2; hello3;";
	char *tokenized = NULL;

	tokenized = strtok(a, ";");
	while(tokenized != NULL)
	{
		printf("Next token-->%s\n",tokenized);
		tokenized = strtok(NULL, ";");
	}
	return (1);
}
