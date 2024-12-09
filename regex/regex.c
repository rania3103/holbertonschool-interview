#include "regex.h"
/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: is the string to scan
 * @pattern:is the regular expression
 * Return:1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');
	int match = (*str != '\0' && (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern +  2) ||
		(match && regex_match(str + 1, pattern)));
	if (match)
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
