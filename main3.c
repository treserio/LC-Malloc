#include "header.h"

int main(void)
{
	char *path = "/home/treserio/.local/bin:/home/treserio/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Program Files/Common Files/Oracle/Java/javapath:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/Microsoft VS Code Insiders/bin:/mnt/c/Dev/MinGW64/bin:/mnt/c/Users/trese/AppData/Local/Microsoft/WindowsApps:/snap/bin";
	char j1[] = "stuff to join", j2[] = "more stuff";
	char *catfish, **fish_fry;
	int i;

	catfish = str_catfish(j1, path, ':');
	printf("path=%p\n", path);
	printf("j1=%p |%s|\n", j1, j1);
	printf("j1=%p |%s|\n", j2, j2);
	printf("CF=%p |%s|\n", catfish, catfish);

	fish_fry = trawler(catfish, ':');

	// address of fish_fry
	printf("ff=%p\n", fish_fry);

	// show values in fish_fry
	for (i = 0; fish_fry[i]; ++i)
	{
		printf("%02d=%p |%s|\n", i, fish_fry[i], fish_fry[i]);
	}
	// reassign value
	fish_fry[0] = &j2[0];
	for (i = 0; fish_fry[i]; ++i)
	{
		printf("%02d=%p |%s|\n", i, fish_fry[i], fish_fry[i]);
	}

	free(catfish);
	free(fish_fry);
	//4 free(fish_fry[0]);

	return (0);
}