#include "header.h"

int main(void)
{
	char j1[] = "stuff to join", j2[] = "more stuff";
	char *catfish, **fish_fry;
	int i;

	catfish = str_catfish(j1, j2, ':');
	printf("j1=%p |%s|\n", j1, j1);
	printf("j2=%p |%s|\n", j2, j2);
	printf("CF=%p |%s|\n", catfish, catfish);

	fish_fry = trawler(catfish, ':');

	for (i = 0; fish_fry[i]; ++i)
	{
		printf("%d=%p |%s|\n", i, fish_fry[i], fish_fry[i]);
	}

	return (0);
}