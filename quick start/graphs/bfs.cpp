#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
//range based for loops good for graphs
//https://www.hackerearth.com/practice/notes/graph-theory-part-i/

using namespace std;

unordered_map<int, vector<int>> adj;

void join(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void ins(int a){
    adj[a].push_back(1);
    adj[a].pop_back();
}

void bfs(vector<bool>& vis, int vertex){
    queue<int> explore;
    unordered_map<int, int> level;
    level[vertex] = 0;
    explore.push(vertex);
    vis[vertex-1] = true;
    while (!explore.empty()){
        int node = explore.front();
        explore.pop();
        for(int& i:adj[node]){
            if (!vis[i-1]){
                level[i] = level[node]+1;
                vis[i-1] = true;
                explore.push(i);
            }
        }
    }
    for(auto& [key,value]:level){
        cout << "[" << key << "]: " << value << "\n"; 
    }
}

int main(){
    //Process input
    join(1,2);
    join(1,3);
    join(3,4);
    join(2,4);
    join(3,5);
    join(4,6);
    vector<bool> visited (adj.size(),false);
    bfs(visited,1);
    return 0;

}