#include <algorithm>
#include <iostream>
#include <vector>

class DisjointSets {
public:
    DisjointSets() {}
    DisjointSets(int size) {
        size_  = size;
        sets_  = std::vector<int>(size, 0);
        ranks_ = std::vector<int>(size, 0);
        for (int i = 0; i < size; ++i) {
            sets_[i] = i;
        }
    }
    ~DisjointSets() {}

    bool unify(int a, int b) {
        int ak, bk;

        ak = find(a);
        bk = find(b);

        if (ak == bk) return false;

        if (ranks_[ak] > ranks_[bk]) {
            sets_[bk] = ak;
        } else if (ranks_[ak] < ranks_[bk]) {
            sets_[ak] = bk;
        } else {
            sets_[bk] = ak;
            ++ranks_[ak];
        }

        return true;
    }

    int find(int e) {
        if (sets_[e] == e) return e;
        return sets_[e] = find(sets_[e]);
    }

    int size() { return size_; }
private:
    int size_;
    std::vector<int> sets_;
    std::vector<int> ranks_;
};

class Edge {
public:
    Edge() {}
    Edge(int from, int to, int cost) {
        from_ = from;
        to_ = to;
        cost_ = cost;
    }
    ~Edge() {}
    int cost() {
        return cost_;
    }
    int from() {
        return from_;
    }
    int to() {
        return to_;
    }
private:
    int from_, to_;
    int cost_;
};

inline bool compareEdge(Edge* l, Edge* r) {
    return l->cost() > r->cost();
}

int main(int argc, char **argv) {
    int cases, price, buildings, streets;
    int from, to, furlongs;

    std::cin >> cases;
    while (cases-- > 0) {
        std::cin >> price >> buildings >> streets;
        std::vector<Edge*> edges;
        edges.reserve(streets);
        // Graph g(buildings);

        for (int i = 0; i < streets; ++i) {
            std::cin >> from >> to >> furlongs;
            edges.push_back(new Edge(from, to, furlongs * price));
            // g.addEdge(from, to, furlongs * price);
        }


        int components = buildings;
        int total = 0;

        std::sort(edges.begin(), edges.end(), compareEdge);
        
        DisjointSets dj(buildings);
        while (components > 1 && ! edges.empty()) {
            Edge *e = edges.back();
            edges.pop_back();
            if ( dj.unify(e->from(), e->to()) ) {
                --components;
                total += e->cost();
            }
        } 

        std::cout << total << std::endl;
    }
}