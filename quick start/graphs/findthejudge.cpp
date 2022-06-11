using namespace std;
#include <vector>
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg (n+1, 0);
        for (auto& vect:trust){
            deg[vect[0]]-=1;
            deg[vect[1]]+=1;
        }
        for(int i=1;i<deg.size();i++){
            if(deg[i] == n-1) return i;
        }
        return -1;
    }
};