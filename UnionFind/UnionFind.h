#ifndef PLAY_WITH_ALGORITHMS_UNIONFIND_H
#define PLAY_WITH_ALGORITHMS_UNIONFIND_H

#include <cassert>


class UnionFind {
private:
    int *parent;
    int *rank;
    int count;

public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int find(int p) {
        assert(p >= 0 && p < count);
        while (p != parent[p]) {
            // path compression
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }

        // rank optimization
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[qRoot] < rank[pRoot]) {
            parent[qRoot] = pRoot;
        } else {
            parent[pRoot] = qRoot;
            rank[qRoot]++;
        }
    }
};


#endif //PLAY_WITH_ALGORITHMS_UNIONFIND_H
