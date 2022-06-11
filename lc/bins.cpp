#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int s(vector<int>& nums, int target, int start, int end){
        //int mid = (start+end)/2;
        int mid = start + (end-start)/2; //Prevents integer overflow
        if (target == nums[mid]) return mid;
        if (start == end) return -1;
        if (target>nums[mid]){
            return s(nums, target, mid+1, end);
        }
        else {
            return s(nums, target, start, mid);
        }
        
    }
    int search(vector<int>& nums, int target) {
        return s(nums, target, 0, nums.size()-1);
    }
    
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    cout << sol.search(nums, target);
}

/* Iterative bin search
 class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int mid_pt, left = 0, right = nums.size() - 1;
    while (left <= right) {
      mid_pt = left + (right - left) / 2;
      if (nums[mid_pt] == target) return mid_pt;
      if (target < nums[mid_pt]) right = mid_pt - 1;
      else left = mid_pt + 1;
    }
    return -1;
  }
}; */