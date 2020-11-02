#include <stdio.h>
#include <string.h>

/**
 *_strcmp - A special compare function that compares is sub
 * is aubset of fstring. for example if fstring is "hello"
 * "h", "he", ... but not "hello" are all subsets and
 * in such a case a 1 will be returned
 *@fstring: fstring
 *@sub: subset
 *Return: 1 on success and -1 on faliur
 */
int _strcmp(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (strlen(fstring) < strlen(sub))
		return (-1);
	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);
		sub++, fstring++;
	}
	return (1);

}
/**
 * _strtok - tokenizes a string according to a certain delimiter
 * it doesnt creat a new string to hold the tokens but rather creats a
 * a static variable that will directly copy str and puts the null
 * terminator everytime it finds the delimeter, the default str will be
 * manipulated so beware
 * for example if you have a string str = "helo; now; bo"
 * when _strtok is called for the first time (_strtok(str, ";")) it will put
 * \0 (a null terminator in the first location of the delimeter so the str
 * variable will be "helo\0 nowo; bo", ";" and it will be returned and the
 * static variable save would hold " nowo; bo" and when _strtok is called
 * for the second time _strtok(NULL, ";"); the same cyle continue
 * but this time instead of str save will be manipulated. This
 *cycle continues untile save == NULL
 * @str: the string to be tokenized
 * @delimeter: the delimiter to separate tokens
 * Return: a character pointer to the current delimited token
 */
char *_strtok(char *str, const char *delimeter)
{
	static char *save;
	char *_new = NULL;
	int i = 0;

	if (!str || !*str)
	{
		if (!save || !*save)
			return (NULL);

		while (_strcmp(save + i, delimeter) != 1 && *(save + i) != '\0')
			i++;
		if (*(save + i) == '\0')
		{
			save = NULL;
			return (save);
		}

		_new = save;
		*(save + i) = '\0';
		save = save + i + strlen(delimeter);

		return (_new);

	}
	while (_strcmp(str + i, delimeter) != 1 && *(str + i) != '\0')
		i++;

	if (*(str + i) == '\0')
		return (str);

	save = str + i + strlen(delimeter);
	*(str + i) = '\0';

	return (str);
}
/**
*main - entry point
*Return: 1 on sucess
*/
int main(void)
{

	char a[] = "hello; hello2; hello3;";
	char *tokenized = NULL;

	tokenized = _strtok(a, ";");
	while (tokenized != NULL)
	{
		printf("token-->%s\n", tokenized);
		tokenized = _strtok(NULL, ";");
	}
	return (1);
}
