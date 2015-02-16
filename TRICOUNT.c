#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int dp[1000001];

int main() {

	int T;
	long long int i, n;
	scanf("%d", &T);

	dp[1] = 1;

	for (i = 2; i <= 1000000; i++) {

		dp[i] = dp[i-1] + ((3*i*i + 2*i)/4);
	}

	for (; T > 0; T--) {

		scanf("%llu", &n);

		printf("%llu\n", dp[n]);

	}
	return 0;
}