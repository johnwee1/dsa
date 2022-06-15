//Longest Common Substring problem
//DP sol is O(mn) but look up suffix trees
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string minDistance(string wi, string wj) {
        string longest = "";
        string current = "";
        int x=0;
        bool still_matching = false;
        bool check_for_x = false;
        for(int i=0;i<wi.size();++i){
            check_for_x = false;
            still_matching = false;
            for(int j=0;j<wj.size();++j){
                if (wi[i]==wj[j] || (wi.at(x)==wj[j] && check_for_x)){
                    if (!still_matching){
                        current = "";
                        if (x==0){
                            x = i;
                            check_for_x = true;
                        }
                        still_matching = true;
                    }
                    current.push_back(wi[x++]);
                    if (current.length()>longest.length()) longest = current;
                    if (x==wi.length()) {
                        x = 0;
                        check_for_x = false;
                    }
                }else{
                    still_matching = false;
                    x=0;
                    check_for_x = false;
                }
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    string s1 = "park";
    string s2 = "spake";
    cout << s.minDistance(s1,s2);
}