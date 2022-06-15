//Done after min_ops, second time implementing sliding window - first time submission accepted.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int i=0;
        int j = 0;
        int ms=0;
        int sum=0;
        while(i<nums.size()){
            if (map.find(nums[j])==map.end()){
                //If the num is not in the map add to map
                map[nums[j]] = j;
                sum += nums[j];
                ms = max(sum,ms);
                if (j<nums.size()-1) ++j;
                else break;
            }
            else{
                //if nums[j] is actually inside
                int _i = i;
                i = 1+map[nums[j]];
                for(int k=_i;k<i;k++){
                    sum -= nums[k];
                    map.erase(nums[k]);
                }
                map[nums[j]] = j;
                sum+= nums[j];
                if (j<nums.size()) ++j;
                else break;
            }
        }
        return ms;
    }
};

int main(){
    Solution s;
    vector<int> num = {1,2,3,4,5,56,5};
    cout << s.maximumUniqueSubarray(num);
}