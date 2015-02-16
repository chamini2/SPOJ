#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAX_SIZE 5010

char *input;
int size;

unsigned long long cache[MAX_SIZE];

unsigned long long rec(int i) {
    // std::cout << "i = " << i << std::endl;
    if (i >= size - 1) {
        if (i == size - 1 && input[i] == '0') return -1;
        return 0;
    }
    if (cache[i] != -1) return cache[i];

    unsigned long long ans;
    switch (input[i]) {
        case '0':
            ans = - 1;
            break;
        case '2':
            if (input[i+1] > '6') {
                ans = rec(i + 1);
                break;
            }
        case '1':
            ans = 1 + rec(i + 1) + rec(i + 2);
            break;
        default:
            ans = rec(i + 1);
            break;
    }

    return cache[i] = ans;
}

int main() {
    size_t max_size = MAX_SIZE;
    input = (char*) malloc(sizeof(char) * (MAX_SIZE + 1));

    while (true) {
        size = getline(&input, &max_size, stdin);
        --size;
        input[size] = '\0';
        // std::cout << "'" << input << "' " << size << " size" << std::endl;

        memset(cache, -1, sizeof(unsigned long long) * MAX_SIZE);
 
        if (input[0] == '0') break;

        std::cout << 1 + rec(0) << std::endl;
    }
}