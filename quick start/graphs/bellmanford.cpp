#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int a, int b, int w;
};

const int INF = 1e9;

int main(){
    solve();
}
/*The orig alg runs with a worst case O(VE) complexity though the theta can be optimised
when there isn't any relaxation in a given iteration (the graph has finished relaxing fully)*/
void solve(vector<Edge> e, int n){
    vector<int> d (e.size(), INF);
    vector<int> p (e.size(), -1);
    d[n] = 0;
    vector<int> p (e.size());
    while(true){
        bool go=false;
        for(auto& v:e){
            if(d[v.a]!=INF){
                if(d[v.b] > d[v.a]+v.w){
                    d[v.b] = d[v.a] + v.w;
                    p[v.b] = v.a;
                    go=true;
                }
            }
        }
        if (!go) break;
    }

    //Now, lets say I am trying to find path to node t
    if(d[t]==INF) cout << "This node is unreachable from the starting vertex"
    else{
        vector<int> path;
        int temp = t;
        while(temp!=-1){
            path.push_back(temp);
            temp = p[temp];
        }/*
        Big brain for loop implementation:
        for(int i=t; i!=-1;i = p[i]){
            path.push_back(i);
        }
        The key is to use -1 as the stop condition
        */

        reverse(path.begin(),path.end());
        for(auto& a:path){
            cout << a << " "; //print path
        }
        

    }
}