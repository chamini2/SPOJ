#include <cstdio>
#include <iostream>
#include <vector>

unsigned long long rec(int from, int to) {

}

int main(int argc, char** argv) {
    int ms;

    while(scanf("%d",&ms) != -1) {
        std::vector<int> mixtures;
        mixtures.reserve(ms);
        for (int i = 0; i < ms; ++i) {
            int mix;
            scanf("%d", &mix);
            mixtures.push_back(mix);
        }

        printf("%d", rec());
    }

}