#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char word[500], ch;
	int n, l, i, k;

	while (1) {
		scanf("%s", word);

		if (!strcmp(word, "."))
			return 0;

		scanf("%d", &n);

		l = strlen(word);
		
		for (k = 0; k < l; k++) {
			for (i = 0; i < n; i++)
				printf("%s", word);

			printf("\n");

			ch = word[0];

			for (i = 0; i < l - 1; i++)
				word[i] = word[i+1];

			word[l-1] = ch;
		}
	}
	return 0;
}