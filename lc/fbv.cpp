//firstBadVers
#include <iostream>
using namespace std;

bool isBadVersion(int bad_ver){
    if (bad_ver>=2) return true;
    else return false;
}
class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1;
        while (true){
            int mid = a+(n-a)/2;
            if (isBadVersion(mid)) n = mid;
            else a = mid+1;
            if  (a==n) return n;
        }
    }
};


int main(){
    Solution sol;
    int n = 2;
    cout << sol.firstBadVersion(n);
}