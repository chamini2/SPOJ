#include <stdio.h>

unsigned int ar[100001];

unsigned int func(int c) {
	unsigned int i;

	if (!c)
		return 0;

	if ((c <= 100000) && (ar[c] != 0))
		return ar[c];

	i = func(c/2) + func(c/3) + func(c/4);

	if (i < c) {
		if (c <= 100000) 
			ar[c] = c;
		return c;
	} else {
		if (c <= 100000)
			ar[c] = i;
		return i;
	}
}

int main() {

	int c;

	ar[0] = 0;
	ar[1] = 1;
	for (c = 2; c <= 100000; c++)
		ar[c] = 0;

	while (scanf("%d", &c) != EOF)
		printf("%u\n", func(c));
}