#include <bits\stdc++.h>
using namespace std;
/*
As I was attempting to do some bi-directional search question, I wanted to try to implement a normal BFS first
before moving onto a bi-directional BFS. Turns out even normal BFS is a little challenging to implement!

A difficult to debug error I faced was DEADLYSIGNAL something, which after some googling turns out to be the fact that
erasing/pop_front deletes all references to the iterator (which I was currently in)
while it still works locally, it totally didn't work on Leetcode.
apparently c++ trades compiler info/readability for speed

I tried to submit this for fun and it actually passed the judge after fixing the debug
I will try bi-directional BFS on a later date.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dict; //the int maps the current frontier of that word.
        bool flag = false;
        for (auto& word:wordList){
            dict[word] = 0;
            if(word==endWord) flag = true;
        }
        if(!flag) return 0;
        //search
        list<string> q;
        q.push_back(beginWord);
        dict[beginWord] = 1; //init length = 1;
        while(!q.empty()){
            bool pop_front = false;
            for(string word: q){
                if(pop_front) q.pop_front();
                pop_front = false;
                for(int i=0;i<word.size();i++){
                    char x = word[i];
                    int len = dict[word];
                    for(char j='a';j!='z'+1;j++){
                        if (word[i]!=j) word[i] = j;
                        else continue;
                        if (word==endWord) return len+1; 
                        if(dict.find(word)!=dict.end()){ //if this word is in fact in the dictionary
                            if (dict[word]==0){
                                q.push_back(word);
                                dict[word] = len+1; //prevent cycling
                            }
                        }
                    }
                    word[i] = x;
                }
                pop_front = true;
                if (q.size()==1) return 0;
            }
        }
        return 0; //empty q
    }
};

int main(){
    Solution sol;
    vector<string> wordList = {"hot","dog"};
    string a,b;
    a = "hot";
    b = "dog";
    cout << sol.ladderLength(a,b,wordList);
}