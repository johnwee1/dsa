#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Not exactly the leetcode question, because this LCS prints out the string itself rather than length
// Length is found before the string.
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp (s1.size()+1,vector<int> (s2.size()+1,0));
        string ans = "";
        for(int i=1;i<s1.size()+1;++i){
            for(int j=1;j<s2.size()+1;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //If the newest char doesnt match we just take the longest subsequence of the preceding one.
            }
        }
        for(int i=0;i<s1.size()+1;++i){
            for(int j=0;j<s2.size()+1;++j){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(){
    Solution s;
    string s1 = "abcde";
    string s2 = "ace";
    cout << s.longestCommonSubsequence(s1,s2);
}