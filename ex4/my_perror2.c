/* my_perror2 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void my_perror2(const char *s)
{
	if(s != NULL)
		printf("%s: " , s);

	printf("%s\n" , strerror(errno));
	
	exit(1);
}

