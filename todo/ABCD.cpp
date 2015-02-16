#include <vector>
#include <iostream>
#define TWON 100001

using namespace std;

char in[TWON], out[TWON];
int n;

// SLOW
bool rec(int as, int bs, int cs, int ds, int i) {
    if(i == n) return true;

    if (as > 0 && in[i] != 'A' && (i == 0 || out[i-1] != 'A')) {
        out[i] = 'A';
        if (rec(as-1, bs, cs, ds, i+1)) return true;
    }
    if (bs > 0 && in[i] != 'B' && (i == 0 || out[i-1] != 'B')) {
        out[i] = 'B';
        if (rec(as, bs-1, cs, ds, i+1)) return true;
    }
    if (cs > 0 && in[i] != 'C' && (i == 0 || out[i-1] != 'C')) {
        out[i] = 'C';
        if (rec(as, bs, cs-1, ds, i+1)) return true;
    }
    if (ds > 0 && in[i] != 'D' && (i == 0 || out[i-1] != 'D')) {
        out[i] = 'D';
        if (rec(as, bs, cs, ds-1, i+1)) return true;
    }

    return false;
}

// WRONG
void greedy(int missing[4]) {
    int last, most = -1;
    for (int i = 0; i < n; ++i) {
        int next = i < (n-1) ? in[i+1] : -1;
        last = most;
        most = -1;
        for (int j = 0; j < 4; ++j) {
            if ((most == -1) && (missing[j] > 0) && (in[i] != j) && (j != last)) {
                most = j;
            } else if ((most != -1) && (missing[j] > missing[most]) 
                       && (in[i] != j) && (j != last)) {
                most = j;
            }
        }
        --missing[most];
        out[i] = ((char) most) + 'A';
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    cin >> in;

    int missing[4];

    for (int i = 0;  i < 4; ++i) {
        missing[i] = n;
    }

    n *= 2;
    for (int i = 0; i < n; ++i) {
        in[i] -= 'A';
        --missing[in[i]];
    }

    // memo(0);
    // rec(missing[0], missing[1], missing[2], missing[3], 0);
    // greedy(missing);
    linear();

    out[n] = '\0';
    cout << out;
    return 0;
}
