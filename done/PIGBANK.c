#include <stdio.h>
#include <string.h>
#define MAX_INT 0x7FFFFFFF
#define TABLE_SIZE 10001

int min(int a, int b) {
    if (a < b) return a;  
    else return b;
}

int dp[TABLE_SIZE];
int weight[500], value[500];
int coins;

int minimum(int w) {
    if (w == 0) return 0;
    if (w < 0) return -1;
    if (dp[w] != -1) {
        if (dp[w] == MAX_INT) return -1;
        return dp[w];
    }

    int tmp, i;
    int m = MAX_INT;

    for (i = 0; i < coins; ++i) {
        if ( (weight[i] <= w) && ( (tmp = minimum(w - weight[i])) != -1 ) )
            m = min(m, tmp + value[i]);
    }

    dp[w] = m;

    if (m == MAX_INT) {
        return -1;
    }

    return m;
}

int main(int argc, char** argv) {
    int cases, answ, w, i;

    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &coins, &w);
        w -= coins;

        scanf("%d", &coins);
        for (i = 0; i < coins; ++i) {
            scanf("%d %d", &value[i], &weight[i]);
        }
        memset(dp, -1, sizeof(int) * (w+1));

        if ((answ = minimum(w)) != -1) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", answ);
        } else {
            printf("This is impossible.\n");
        }
    }
}