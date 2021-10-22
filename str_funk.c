#include "header.h"

/**
 * str_catfish - concatonates 2 strings with a potential insert
 * @one_fish: first string to use in creating catfish
 * @two_fish: second string to use in creating catfish
 * @jelly_fish: char to insert between one_fish & two_fish
 * Return: pointer to allocated memory containing catfish
 */
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish)
{
	int i, size;
	char *catfish;

	for (size = 0; one_fish[size]; ++size)
		;
	for (i = 0; two_fish[i]; ++size, ++i)
		;
	/* if jelly_fish then malloc size + 2, else + 1 */
	if (jelly_fish)
		catfish = malloc(size + 2);
	else
		catfish = malloc(size + 1);
	/* copy strings to buffers */
	for (size = 0; one_fish[size]; ++size)
		catfish[size] = one_fish[size];
	/* if jelly_fish then insert jelly_fish between fish */
	if (jelly_fish)
	{
		catfish[size] = jelly_fish;
		++size;
	}
	for (i = 0; two_fish[i]; ++size, ++i)
		catfish[size] = two_fish[i];
	/* set null byte for eos */
	catfish[size] = '\0';
	return (catfish);
}

/**
 * fish_scales - weigh fish and return difference, or 0 if they're =
 * @red_fish: first string to compare
 * @blue_fish: second string to compare
 * Return: linguistic difference in the deviant char, or zero if match
 */
int fish_scales(char *red_fish, char *blue_fish)
{
	int part, chk = 0;

	for (part = 0; red_fish[part] != '\0' && blue_fish[part] != '\0'; part++)
	{
		if (red_fish[part] != blue_fish[part])
			break;
	}
	chk = red_fish[part] - blue_fish[part];
	return (chk);
}

/**
 * fish_spotter - finds the fish(words) in a school(char *) using a net(char)
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: number of fish spotted
 */
int fish_spotter(char *school_of_fish, char net)
{
	int fish, word, spotted = 0;

	for (fish = 0, word = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		if (school_of_fish[fish] == net && word)
		{
			++spotted;
			word = 0;
		}
	}

	return (spotted);
}

/**
 * trawler - splits school_of_fish(char *) on net(char) and adds to array
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: array of parsed strings
 */
char **trawler(char *school_of_fish, char net)
{
	int fish, st, catch, word, i;
	char **haul;

	// count the fish in the school
	catch = fish_spotter(school_of_fish, net);
	// malloc a chr * for each fish + Null
	haul = malloc(sizeof(char *) * (catch + 2));
	for (fish = 0, st = 0, catch = 0, word = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] == ' ')
			++st;
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		if (school_of_fish[fish] == net && word)
		{
			school_of_fish[fish] = '\0';
			// copying strings to new memory location, uncomment ln 108-111
			// haul[catch] = malloc(fish + 1);
			// for (i = 0; *(school_of_fish + st + i); ++i)
			// 	haul[catch][i] = *(school_of_fish + st + i);
			// haul[catch][i] = '\0';
			// old broken method below, comment out if using above method
			haul[catch] = &school_of_fish[st];
			st = fish + 1;
			++catch, word = 0;
		}
	}
	if (st != fish && word)
	{
		// copying strings to new memory location, uncomment ln 121-124
		// haul[catch] = malloc(fish + 1);
		// for (i = 0; *(school_of_fish + st + i); ++i)
		// 	haul[catch][i] = *(school_of_fish + st + i);
		// haul[catch][i] = '\0';
		// old broken method below, comment out if using above method
		haul[catch] = &school_of_fish[st];
		++catch;
	}
	haul[catch] = NULL;
	if (catch == 0)
		haul[1] = NULL;
	return (haul);
}
