#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define MAX_LENGTH 150

char inswords[100][MAX_LENGTH + 1];
int size, ws, chrs;
char *acronym;
char *phrase;
char *words[150];
std::string last_case("LAST CASE");

unsigned long long rec(int w, int wi, int l, bool mandatory) {
    if (l >= chrs) return 0;

    char chr = acronym[l];
    bool found = false;
    unsigned long long ans = 0;

    for (int i = wi; words[w][i] != '\0'; ++i) {
        if (chr == words[w][i]) {
            ans += 1 + rec(w, i + 1, l + 1, false);
            found = true;
        }
    }

    // // Phew!
    // if (found && mandatory) return rec(w+1, 0, l+1, true);

    // // Whatevs
    // if (found && !mandatory) return rec(w+1, 0, l+1, true);

    // // Impossible
    // if (!found && mandatory) return 0;

    // // Didn't find it, doesn't matter
    // if (!found && !mandatory) return rec(w+1, 0, l, true);

}

int main() {
    size_t max_length = MAX_LENGTH;
    int ins;
    int pos;

    phrase = new char[MAX_LENGTH + 1];

    // char test[] = "ACM mcmcmcmc acacacacaca mamamamama";
    // char *k;
    // k = strtok(test, " ");
    // k = strtok(NULL, " ");
    // std::cout << k << std::endl;
    // k = strchr(k, 'a');
    // // k == NULL
    // // std::cout << k << std::endl;

    std::cin >> ins;
    while (ins > 0) {

        for (int i = 0; i < ins; ++i) 
            scanf("%s\n", inswords[i]);

        while (true) {
            size = getline(&phrase, &max_length, stdin) - 1;
            phrase[size] = '\0';

            if (std::string(phrase) == last_case) break;

            acronym = strtok(phrase, " ");

            phrase = acronym;
            // Tokenize all words, ignoring unnecesary ones
            for (ws = 0; (phrase = strtok(NULL, " ")); ++ws) {
                bool is = false;
                for (int j = 0; !is && j < ins; ++j) {
                    is = strcmp(phrase, inswords[j]) == 0;
                }
                if (is) 
                    --ws; 
                else {
                    words[ws] = phrase;
                }
            }

            // Pointing to the first word
            chrs = strlen(acronym);
            phrase = acronym + chrs + 1;

            std::cout << acronym << "(" << chrs << ") -- '";
            for (int i = 0; i < ws; ++i) {
                std::cout << words[i] << " ";
            }
            std::cout << "\b'" << std::endl;

            std::cout << rec(0, 0, 0, true) << std::endl;
        }

        std::cin >> ins;
    }
}