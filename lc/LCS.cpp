#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Not exactly the leetcode question, because this LCS prints out the string itself rather than length
// Length is found before the string.
class Solution {
public:
    string longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp (s1.size()+1,vector<int> (s2.size()+1,0));
        for(int i=1;i<s1.size()+1;++i){
            for(int j=1;j<s2.size()+1;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //If the newest char doesnt match we just take the longest subsequence of the preceding one.
            }
        }
        string ans (dp[s1.size()][s2.size()], 'x');
        int i=s1.size();
        int j = s2.size();
        int index = dp[s1.size()][s2.size()]-1;
        while(index>-1){
            /*for(int a=1;a<dp.size();++a){
                for(int b=1;b<dp[0].size();++b){
                    if (a==i && b==j) cout << "X ";
                    else cout << dp[a][b] << " ";
                }
                cout << "\n";
            }
            cout << "\n\n";
            //For testing purposes
            */
            if (dp[i-1][j-1]==dp[i][j-1] && dp[i-1][j-1]==dp[i-1][j] && dp[i][j]>dp[i-1][j-1]){
                ans[index--] = s1[i-1];
                --i;--j;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) --i;
                else --j;
            }
            
        }
        return ans;
    }
};

int main(){
    Solution s;
    string s1 = "abcdefhg";
    string s2 = "anne of green gables";
    cout << s.longestCommonSubsequence(s1,s2);
}