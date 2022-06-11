#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    vector<string> generateParenthesis(int n){
        if (n==0) return {};
        unordered_set<string> set = helper(n);
        vector<string> vec;
        vec.reserve(set.size());
        for(auto it:set){
            vec.push_back(it);
        }
        return vec;
    }

    unordered_set<string> helper(int n){
        if (n==1) return {"()"};
        unordered_set<string> bank {};
        for (string s:helper(n-1)){
            for(int i=0;i<s.size();++i){
                if(s.at(i)=='('){
                    string temp = s;
                    temp.insert(i+1,"()");
                    if (bank.find(temp)==bank.end()) bank.insert(temp);
                }
                if(i==s.size()-1){
                    string temp = s;
                    temp.insert(i+1,"()");
                    if (bank.find(temp)==bank.end()){
                        bank.insert(temp);
                    }
                }
            }
        }
        return bank;
    }
};
void print(vector<string> vec){
    for (auto it:vec){
        cout << it + " ";
    }
}
int main(){
    Solution sol;
    print(sol.generateParentheses(8));
}