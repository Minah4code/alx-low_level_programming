#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 * Return: 1 if string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	if (len == 0 || len == 1)
		return (1);
	if (s[0] != s[len - 1])
		return (0);
	s[len - 1] = '\0';
	return (is_palindrome(s + 1));
}

int main(void)
{
	int r;

	r = (is_palindrome("level"));
	printf("%d\n", r);

	r = (is_palindrome("redder"));
	printf("%d\n", r);

	r = (is_palindrome("test"));
	printf("%d\n", r);

	r = (is_palindrome("step on no pets"));
	printf("%d\n", r);

	return (0);
}
