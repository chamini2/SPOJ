#include <cstdio>
#include <string>
#include <iostream>
#define MAX_LENGTH 150

char inswords[100][MAX_LENGTH + 1];
std::string phrase;
int size;
const char *acronym;
std::string last_case("LAST CASE");

int main() {
    int ins;
    int pos;

    phrase = (char*) malloc(sizeof(char) * (MAX_LENGTH + 1));

    std::cin >> ins;
    while (ins > 0) {

        for (int i = 0; i < ins; ++i) 
            scanf("%s\n", inswords[i]);

        while (true) {
            std::getline(std::cin, phrase);
            if (phrase == last_case) break;

            std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);

            pos = phrase.find_first_of(std::string(" "));

            acronym = phrase.substr(0, pos).c_str();

            std::cout << acronym << " in \"" << phrase << '"' << std::endl;
        }

        std::cin >> ins;
    }
}