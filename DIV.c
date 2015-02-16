#include <stdio.h>

int main() {
	int i, k, j;
	int a[1000001], b[1000001];
	/**DIVISORES**/
	a[1] = 1;

	for (i = 2; i <= 1000000; i++)
		a[i] = 2;

	for (i = 2; i <= 1000; ++i) {

		for (k = i*i; k <= 1000000; k += i) {
			if (k/i == i)
				a[k]++;
			else
				a[k] += 2;
		}
	}

	/**PRIMOS**/
	b[1] = 0;

	for (i = 2; i <= 1000000; i++)
		b[i] = 1;

	for (i = 2; i <= 10000; i++) {

		if (!b[i])
			continue;

		for (k = i*i; k <= 1000000; k += i) 
			b[k] = 0;
	}

	/**CORRIDA**/
	j = 0;

	for (i = 1; i <= 1000000; i++) {

		if (b[i])
			continue;

		for (k = 2; k*k < a[i]; k++) {
			if (b[k] == 0)
				continue;

			if ((a[i]%k == 0) && (b[(a[i]/k)]) && (k != (a[i]/k))) {
				j++;
				if (j%9 == 0)
					printf("%d\n", i);

				break;
			}
		}
	}

	return 0;
}