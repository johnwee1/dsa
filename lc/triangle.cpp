#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Not bad - managed to work out a bottom up solution on the first try
//Question could be more challenging if we had to return an array containing the min path

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sum = triangle;
        int x;
        for (int i=1;i<triangle.size();++i){
            for (int j=0;j<triangle[i].size();++j){
                x=0;
                if(j<triangle[i-1].size() && j>0){
                    x = triangle[i][j] + min(sum[i-1][j],sum[i-1][j-1]);
                }
                else if(j==0){
                    x = triangle[i][j] + sum[i-1][j];
                }
                else{
                    //if j==triangle[i-1].size()
                    x = triangle[i][j] + sum[i-1][j-1];
                }
                sum[i][j] = x;
            }
        }
        for(auto& i:sum.back()) cout << i;
        sort(sum.back().begin(),sum.back().end());
        return sum.back().front();
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle = {{-1},{3,2},{1,-2,-1}};
    cout << s.minimumTotal(triangle);

}