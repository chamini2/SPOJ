#include <cstdio>
#include <iostream>
#include <vector>

int rec(int count, int i, std::vector<int> mixtures) {
    
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

        printf("%d", rec(0, 0, mixtures));
    }

}