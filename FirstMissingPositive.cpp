class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());//sort does not affect problem!
        bool found = false;
        int i = 1;
        while(!found){
            //is i in nums ?
            int l = 0;
            int r = n-1;
            while(r > l){
                int mid = (l+r)/2;
                if(nums[mid] < i){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            if(nums[l] != i){
                found = true;
                return i;
            }
            i++;
        }
        return n+1;
    }
};
