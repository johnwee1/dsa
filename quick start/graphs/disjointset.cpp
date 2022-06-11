#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz,1) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x!=root[x]) return root[x] = find(root[x]);
        return x;
    }

    void unionSet(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if  (root_x==root_y) return;
        if(rank[root_x]==rank[root_y]){
            //Change root y
            root[root_y] = root_x;
            rank[root_y] += 1;
        }
        else if (rank[root_x]>rank[root_y]){
            //change root y
            root[root_y] = root_x;
        }
        else root[root_x] = root_y;
        return;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}