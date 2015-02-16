#include <stdio.h>
#include <string.h>
#define max_int 0x7FFFFFFF

typedef struct {

	int ox; // 1 - 21
	int ni; // 1 - 79
	int w;  // 1 - 800
} cilindro;

cilindro cil[1000];
int seen[1000];
int dp[22][80];
int n;		//1<=n<=1000, #cilindros

int min (int a, int b) {

	if (a < b)
		return a;
	else
		return b;
}

int buceo (int oxy, int nit) {

	int ans = max_int, k, i;
	//char s[1000000] = "";

	if ((oxy <= 0) && (nit <= 0))
		return 0;

	if ((oxy >= 0) && (nit >= 0)) {
		if (dp[oxy][nit] != -1) {
			if (dp[oxy][nit] == max_int)
				return -1;

			return dp[oxy][nit];
		}
	}

	for (i = 0; i < n; i++) {
		if (seen[i])
			continue;

		seen[i] = 1;

		k = buceo(oxy - cil[i].ox, nit - cil[i].ni);
		
		if (k != -1) {
			ans = min(ans, cil[i].w + k);
			//sprintf(s, "%sORI: %3d, %3d CALL: %3d, %3d | K: %3d | ANS: %3d\n", s, oxy, nit, oxy - cil[i].ox, nit - cil[i].ni, k, ans);
		}
	}
	//printf("%sRETURN: %d\n---------------------------------------------------------------\n", s, ans);

	if ((oxy >= 0) && (nit >= 0)) {
		dp[oxy][nit] = ans;
	}

	if (ans == max_int)
		return -1;

	return ans;
}

int main () {

	int caso, i,j;
	int ox, ni; //1<=ox<=21 , 1<=ni<=79

	scanf("%d", &caso);

	while (caso--) {
		scanf("%d %d", &ox, &ni);
		scanf("%d", &n);

		memset(dp, -1, sizeof(int) * 22 * 80);

		for (i = 0; i < n; i++)
			scanf("%d %d %d", &cil[i].ox, &cil[i].ni, &cil[i].w);


		memset(seen, 0, sizeof(int) * n);
		/****FIN DE LECTURA*****/

		printf("%d\n", buceo(ox, ni));
	}
}