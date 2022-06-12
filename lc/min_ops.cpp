#include <iostream>
#include <vector>
using namespace std;
//Upon first glance, this looks like a DP problem - recursively remove elems from the end and shrink the problem
//But it is actually a deceptive simple problem (max subarray) - hence requires sliding window
//This is actually my first attempt at sliding window without looking at a solution, not as easy as i thought
//Off-by-one errors are plentiful:
//line 21 if i<nums.size()-1 it actually misses the case where the max subarray is the last one...
//j is init to -1 so that it can be incremented to match the current sum (another off by one error)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (const auto& elem:nums){
            sum += elem;
        }
        int t_sum = sum - x; //target sum
        int c_sum = 0;
        int msize = -1;
        int i=0,j=-1;
        while(i<nums.size()){
            if(c_sum<t_sum){
                //expand window if current sum is less than target sum
                if (j!=nums.size()-1){
                    ++j;
                    c_sum += nums[j];
                } else break;
            }
            else if(c_sum==t_sum){
                //Shrink window from the left and expand rightwards and update max
                msize = max(j-i+1,msize);
                c_sum -= nums[i++];
                if (j!=nums.size()-1){
                    ++j;
                    c_sum += nums[j];
                } else break;

            }
            else if(c_sum>t_sum){
                //shrink window
                c_sum -= nums[i++];
            }
        }
        if (msize == -1) return -1;
        else return nums.size()-msize;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,99};
    int n = 1;
    cout << sol.minOperations(nums,n);
}