#include <stdio.h>

int main() {
	
	int c, n, ret, p;

	scanf("%d", &c);

	while (c--){

		scanf("%d", &n);
		ret = 0;

		for (p = 5; p <= n; p*=5)
			ret += n/p;

		printf("%d\n", ret);
	}
	return 0;
}