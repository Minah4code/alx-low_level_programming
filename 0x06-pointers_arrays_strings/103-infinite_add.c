#include "main.h"

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, i = 0, j = 0, k = 0, sum = 0;
	char tmp;

	while (n1[len1 + 1] != '\0')
		len1++;
	while (n2[len2 + 1] != '\0')
		len2++;

	if (len1 + 1 > size_r || len2 + 1 > size_r)
		return (0);

	for (i = len1, j = len2, k = 0; i >= 0 || j >= 0; i--, j--, k++)
	{
		sum = (i >= 0 ? n1[i] - '0' : 0) + (j >= 0 ? n2[j] - '0' : 0) + sum / 10;
		if (k + 1 == size_r && sum / 10 > 0 && k + 2 == size_r)
			return (0);
		r[k] = sum % 10 + '0';
	}

	if (sum / 10 != 0 && k + 1 < size_r)
	{
		r[k] = sum / 10 + '0';
		k++;
	}

	for (i = 0; i < k / 2; i++)
	{
		tmp = r[i];
		r[i] = r[k - i - 1];
		r[k - i - 1] = tmp;
	}

	r[k] = '\0';
	return (r);
}
