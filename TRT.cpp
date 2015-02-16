#include <stdio.h>
#include <algorithm>
#include <string.h>

int treat[2001];
int cache[2001][2001];
int n;

// WRONG
// int greedy(int left, int right, int age) {
//     if (left == right) return age * treat[left];
//     if (treat[left] < treat[right]) 
//         return (age * treat[left]) + greedy(left + 1, right, age + 1);
//     else 
//         return (age * treat[right]) + greedy(left, right - 1, age + 1);
// }

// int rec(int left, int right, int age) {
//     if (left == right) return age * treat[left];

//     return std::max(
//         (age * treat[left])  + rec(left + 1, right, age + 1),
//         (age * treat[right]) + rec(left, right - 1, age + 1)
//     );
// }

int memo(int left, int right) {
    int age = n - (right - left + 1) + 1;

    if (left == right) return age * treat[left];
    if (cache[left][right] != -1) return cache[left][right];

    return cache[left][right] = std::max(
        (age * treat[left])  + memo(left + 1, right),
        (age * treat[right]) + memo(left, right - 1)
    );
}

int main(int argc, char** argv) {

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &treat[i]);
    }

    memset(cache, -1, sizeof(int) * 2001 * 2001);

    printf("%d", memo(0, n-1));
    return 0;
}
