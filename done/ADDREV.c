#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkzeros(char s[],int l) {

	int i, k;

	for (i = 0; i < l; i++) {

		if (s[i] != '0')
			break;
	}

	for (k = 0; i < l; k++) {

		s[k] = s[i];
		i++;
	}

	s[k] = '\0';
}

void reverse(char s[], int l) {

	int i, k;
	char c;
	k = l-1;
	for (i = 0; i < (l/2); i++) {
		c = s[i];
		s[i] = s[k];
		s[k] = c;
		k--;
	}

	checkzeros(s, l);
}

int main(int argc, char const *argv[])
{
	int t, a, b, r;
	char A[100], B[100];

	scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &a, &b);

		sprintf(A, "%d", a);
		sprintf(B, "%d", b);
		
		reverse(A,strlen(A));
		reverse(B,strlen(B));
				
		a = atoi(A);
		b = atoi(B);

		r = a + b;

		sprintf(A, "%d", r);
		reverse(A, strlen(A));
		printf("%s\n", A);
	}
	return 0;
}