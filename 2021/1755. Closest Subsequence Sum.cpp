class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
//          def minAbsDifference(self, nums: List[int], goal: int) -> int:
//         # function that generates all possible sums of sebsequences
//         def dfs(i,cur,arr,sums):
//             if i==len(arr):
//                 sums.add(cur)
//                 return
//             dfs(i+1,cur,arr,sums)
//             dfs(i+1,cur+arr[i],arr,sums)
        
//         sums1,sums2=set(),set()
//         # generate all possible sums of the 1st and 2nd half 
//         dfs(0,0,nums[:len(nums)//2],sums1)
//         dfs(0,0,nums[len(nums)//2:],sums2)
        
//         # sort the possible sums of the 2nd half
//         s2=sorted(sums2)
//         ans=10**10
//         # for each possible sum of the 1st half, find the sum in the 2nd half
//         # that gives a value closest to the goal using binary search
//         for s in sums1:
//             remain=goal-s
// 			# binary search for the value in s2 that's closest to the remaining value
//             i2=bisect_left(s2,remain)
//             if i2<len(s2):
//                 ans=min(ans,abs(remain-s2[i2]))
//             if i2>0:
//                 ans=min(ans,abs(remain-s2[i2-1]))
//         return ans
        unordered_set<int> sumSet1, sumSet2;
        dfs(nums, 0, nums.size() / 2, 0, sumSet1);
        dfs(nums, nums.size() / 2 + 1, nums.size() - 1, 0, sumSet2);
        
        vector<int> sum2(sumSet2.begin(), sumSet2.end());                
        sort(sum2.begin(), sum2.end());
                        
        int minDiff = abs(goal);
        for (int s : sumSet1) {
            int rem = goal - s;
            int i2 = lower_bound(sum2.begin(), sum2.end(), rem) - sum2.begin();
            if (i2 < sum2.size()) {
                minDiff = min(minDiff, abs(rem - sum2[i2]));
            }
            if (i2 > 0) {
                minDiff = min(minDiff, abs(rem - sum2[i2 - 1]));
            }            
        }
        return minDiff;
    }
    
    void dfs(vector<int>& nums, int start, int end, int curr, unordered_set<int>& sums) {
        sums.insert(curr);
        for (int i = start; i <= end; i++) {
            dfs(nums, i + 1, end, curr + nums[i], sums);
        }        
    }    
};