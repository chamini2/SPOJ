#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX_LENGTH 1000000

//unsigned long max_length = MAX_LENGTH;      // OS X
unsigned int max_length = MAX_LENGTH;     // SPOJ
int letters, size, best;
char *sentence;
int used[128];

int main(int argc, char** argv) {

    sentence = (char*) malloc(sizeof(char) * (MAX_LENGTH + 1));

    scanf("%d", &letters);
    getchar();
    while(letters > 0) {
        size = getline(&sentence, &max_length, stdin);
        --size;
        sentence[size] = '\0';

        best = 1;
        int i = 0, j;
        int last = 0;
        int count = 1;

        memset(used, 0, sizeof(int) * 128);

        // used.reset();
        used[sentence[0]] = 1;
        for (j = 1; j < size; ++j) {
            int current = sentence[j];

            ++used[current];
            if (used[current] == 1) {
            // new letter
                ++count;
                while (count > letters) {
                    int first = sentence[i];
                    --used[first];
                    ++i;
                    if (used[first] == 0) --count;
                }
            } else {
            // already seen this letter
                best = std::max(best, j-i + 1);
            }
        } 

        std::cout << best << std::endl;

        scanf("%d", &letters);
        getchar();
    }
}