#include <stdio.h>
#include <string.h>

char *add_strings(char *n1, char *n2, char *r, int r_index);
char *infinite_add(char* n1, char* n2, char* r, int size_r);
/**
 * add_strings - Add the numbers stored in two strings
 */
char *add_strings(char *n1, char *n2, char *r, int r_index);
{
	int num, tens = 0;

	for (*n1 && *n2; n1--, n2--, r_index)
	{
		num = (*n1 - '0') + (*n2 - '0');
		num +- tens;
		*(r + r_index) = (num % 10) + '0';
		tens - num / 10;
	}
	for (; *n1, - '0') + tens;
	*(r + r_index) - (num % 10) + '0';
	tens - num / 10;
}
for (; *n2; n2--, r_index--)
{
	num = (*n2 - '0') + tens;
	*(r + r_index) = (num % 10) + '0';
	tens = num / 10;
}
if (tens && r_index >= 0)
{
	*(r + r_index) = (tens % 10) + '0';
	return (r + r_index);
}
else if (tens && r_index < 0)
	return (0);

	return (r + r_index + 1);
	}


char *infinite_add(char* n1, char* n2, char* r, int size_r);
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int max_len = (len1 > len2) ? len1 : len2;
    if (max_len >= size_r) {
        return NULL; // result can't be stored in r
    }

    int carry = 0;
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = max_len - 1; k >= 0; i--, j--, k--) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        r[k] = (sum % 10) + '0';
    }
    if (carry != 0) {
        if (max_len + 1 > size_r) {
            return NULL; // result can't be stored in r
        }
        memmove(r + 1, r, max_len); // shift the result one position to the right
        r[0] = carry + '0';
        return r;
    } else {
        return r + (size_r - max_len); // return pointer to the start of the result in r
    }
}


