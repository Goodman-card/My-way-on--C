#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main (void)
{
	char c;
	char prev;
	long chars = 0L;
	int lines = 0;
	int words = 0;
    int p_lines = 0;
	bool inword = false;

	printf("Enter text to be analyzed(| to terminate): \n");
	prev = '\n';
	while((c = getchar()) != STOP)
	{
        chars++;
		if(c == '\n')
			lines++;
		if(!isspace(c) && !inword)
		{
			inword = true;
		    words++;
		}
		if(isspace(c) && inword)
			inword = false;
	    prev = c;
	}

	if(prev != '\n')
		p_lines = 1;
	printf("characters = %ld, words = %d, lines = %d, ",
			chars, words, lines);
	printf("partial lines = %d\n",p_lines);
	return 0;
}

