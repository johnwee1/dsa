#include <iostream>
#include <vector>
#include <unordered_map>
//undirected graph
using namespace std;

unordered_map<int, vector<int>> adj;

void dfs(int vertex, vector<bool>& visited){
    for (int& edge:adj[vertex]){
        if (!visited[edge-1]){
            visited[edge-1] = true;
            dfs(edge,visited);
        }
    }
}

void join(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void ins(int a){
    adj[a].push_back(1);
    adj[a].pop_back();
}

int main(){
    //Process input
    join(1,2);
    join(1,3);
    join(4,5);
    ins(6);
    int conn = 0;
    vector<bool> visited (adj.size(),false);
    for (auto& [vertex,edges]:adj){
        if(!visited[vertex-1]){
            visited[vertex-1] = true;
            dfs(vertex,visited);
            ++conn;
        }
    }
    cout << conn;
    return 0;

}