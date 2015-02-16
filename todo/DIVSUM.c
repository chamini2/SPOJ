#include <stdio.h>

int main() {
	int casos, n, i;
	int a[500001];

	a[1] = a[0] = 0;

	for (i = 2; i <= 500000; i++) 
		a[i] = 1;

	for (i = 2; i <= 708; i++) {

		for (n = i*i; n <= 500000; n += i) {

			if (n/i == i)
				a[n] += i;
			else
				a[n] += i + (n/i);
		}
	}

	scanf("%d", &casos);

	while (casos--) {
		scanf("%d", &n);

		printf("%d\n", a[n]);
	}

	return 0;
}