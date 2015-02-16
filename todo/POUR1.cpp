#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>

class State {
public:
    State() {}
    State(State* s) {
        maxA_ = s->maxA_;
        maxB_ = s->maxB_;
        glassA_ = s->glassA_;
        glassB_ = s->glassB_;
        steps_ = s->steps_;
    }
    State(int maxA, int maxB) {
        maxA_ = maxA;
        maxB_ = maxB;
        glassA_ = 0;
        glassB_ = 0;
        steps_ = 0;
    }
    ~State() {}

    void fill(char g) {
        ++steps_;
        switch (g) {
            case 'a':
            case 'A':
                glassA_ = maxA_;
                break;
            case 'b':
            case 'B':
                glassB_ = maxB_;
                break;
        }
    }

    void empty(char g) {
        ++steps_;
        switch (g) {
            case 'a':
            case 'A':
                glassA_ = 0;
                break;
            case 'b':
            case 'B':
                glassB_ = 0;
                break;
        }
    }

    void pour(char g) {
        ++steps_;
        switch (g) {
            case 'a':
            case 'A':
                if ((maxB_ - glassB_) > glassA_) {
                    glassB_ += glassA_;
                    glassA_ = 0;
                } else {
                    glassA_ -= (maxB_ - glassB_);
                    glassB_ = maxB_;
                }
                break;
            case 'b':
            case 'B':
                if ((maxA_ - glassA_) > glassB_) {
                    glassA_ += glassB_;
                    glassB_ = 0;
                } else {
                    glassB_ -= (maxA_ - glassA_);
                    glassA_ = maxA_;
                }
                glassB_ = maxB_;
                break;
        }
    }

    int solution(int target) {
        if (glassA_ == target || glassB_ == target) 
            return steps_;
        else 
            return -1;
    }

    std::pair<int, int> glass(char g) {
        switch(g) {
            case 'a':
            case 'A':
                return std::make_pair(glassA_, maxA_);
            case 'b':
            case 'B':
                return std::make_pair(glassB_, maxB_);
            }
        return std::make_pair(0,0);
    }

    int glassA() { return glassA_; }
    int glassB() { return glassB_; }
    int steps() { return steps_; }

private:
    int glassA_, glassB_;
    int maxA_, maxB_;
    int steps_;
};


int main(int argc, char** argv) {
    int cases, glA, glB, trg;
    int i,j;
    std::set< std::pair<int, int> > seen;
    std::queue<State> q;

    std::cin >> cases;
    while (cases-- > 0) {
        std::cin >> glA >> glB >> trg;
        State s(glA, glB);
        q = std::queue<State>();
        q.push(s);

        seen.clear();
        seen.insert(std::make_pair(0,0));

        int sol = -1;

        while (!q.empty()) {
            s = q.front();
            q.pop();

            // std::cout << "s: " << s.glass('a').first << " " << s.glass('b').first << " " << s.steps() << std::endl;

            if ((sol = s.solution(trg)) != -1) break;

            std::pair<int, int> glA = s.glass('a');
            std::pair<int, int> glB = s.glass('b');
            State n;

            // pour
            if (glA.first < glA.second && glB.first > 0) {
                n = new State(s);
                n.pour('b');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }
            if (glB.first < glB.second && glA.first > 0) {
                n = new State(s);
                n.pour('a');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }

            // fill
            if (glA.first < glA.second) {
                n = new State(s);
                n.fill('a');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }
            if (glB.first < glB.second) {
                n = new State(s);
                n.fill('b');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }

            // empty
            if (glA.first > 0) {
                n = new State(s);
                n.empty('a');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }
            if (glB.first > 0) {
                n = new State(s);
                n.empty('b');
                std::pair<int, int> k(n.glassA(), n.glassB());
                if (seen.find(k) == seen.end()) {
                    q.push(n);
                    seen.insert(k);
                }
            }
        }

        std::cout << sol << std::endl;
    }
}