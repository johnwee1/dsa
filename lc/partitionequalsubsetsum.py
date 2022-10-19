from typing import List
#A slightly different o/1 knapsack question

class Solution:
    '''def dp(self,nums, i, x, arr):
        if (i>len(nums)-1):
            if x==0: return True
            return False
        if (arr[i]!=None): ------------------ (1)
            return arr[i]
        if (nums[i]==x):
            arr[i]=True
            return True
        if self.dp(nums,i+1,x,arr)==True: #Exclude given num
            arr[i] = True
            return True
        elif self.dp(nums,i+1,x-nums[i],arr)==True: #Incl given num
            arr[i] = True
            return True
        else:
            arr[i] = False ---------------------- (2)
            return False

        Something extremely subtle is wrong with my code, even though the logic of it is pretty much correct
        As you can see here, by separating the two different recursive calls and adding an else statement,
        the moment dp arr[i] is set to False, it is no longer NONE and the check for NONE fails, hence it REMAINS false
        Because the next sibling recursive call fails to re-set the value of dp arr[i] true again.

        Even this statement does not work, because it just condenses the above statement:
        arr[i] = self.dp(nums,i+1,x,arr) or self.dp(nums,i+1,x-nums[i],arr)

        Hence the workaround is deceptively simple: use a matrix to store the values arr[x][i]: the validity of an item being selected at each weight

        its also possible to just use a tuple:bool kv pair in a dict to store vals.
            '''

    def dp(self,nums, i, x, arr)->bool:
        if (i>len(nums)-1):
            if x==0:
                return True
            return False
        if (arr[x][i]!=None):
            return arr[x][i]
        if (nums[i]==x):
            arr[x][i]=True
            return True
        arr[x][i] = self.dp(nums,i+1,x,arr) or self.dp(nums,i+1,x-nums[i],arr) #This sets arr[i] only once.
        return arr[x][i]
        
    
    def canPartition(self, nums: list[int]) -> bool:
        x = sum(nums)
        if (x%2):
            return False
        x = x//2
        arr = [[None for z in nums] for y in range(x+2)]
        return self.dp(nums,0,x,arr)

x = Solution()
nums = [2,2,3,5]
print(x.canPartition(nums))
        
        
    
        