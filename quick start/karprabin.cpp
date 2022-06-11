#include <iostream>
#include <string>
//Using cp alg's binpow, no need #include <cmath>
using namespace std;

class Solution{
    public:
    int search(string find, string text){
        //Prints out the index of the substring to be found. Otherwise, print -1.
        int rf = h(find);
        long long rt = 0;
        for(int i=0;i<text.size();i++){
            if (i<find.size()){
                rt = (rt*127%prime + ((int)text[i])%prime)%prime;
            }
            else{
                if (rt==rf) return i-find.size();
                rt = rt - (int)text[i-find.size()]*(binpow(127,find.size()-1));
                rt = (((rt%prime+prime)%prime)*127)%prime; //If rt is negative, turn positive. Then bitshift
                rt = (rt+(int)text[i])%prime; //Add the next number
            }
        }
        if(rt==rf) return text.size()-find.size()+1; //Catch case where string is the last
        return -1;

    }
    
    private:
    int h(string find){
        long long hash = 0;
        for(int i=0;i<find.size();i++){
            hash = (hash*127%prime + ((int)find[i])%prime)%prime;
        }
        return hash;
    }
    long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
    const int prime = 115249; //bigger is better. normally upper val is size of hashtable but KR str matching has no HT
    

};

int main(){
    Solution sol;
    string s = "aabghewrioghbwei;ogwbiogeoreownbio;g 1532WR Hcda";
    string b = "oreo";
    cout << sol.search(b,s);
}