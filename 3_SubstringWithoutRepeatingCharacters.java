class Solution {
    //idea: keep sliding window of possible solutions
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int l = 0;
        int r = -1;
        boolean[] in_window = new boolean[130];   
        int lgt_window = 0;

        while(r+1 < s.length()){
            int curr = s.charAt(r + 1);
            if(in_window[curr]){//must pop window from left
                do{
                    int left = s.charAt(l);
                    in_window[left] = false;
                    l++; lgt_window--;
                }while(in_window[curr]);
            }
            //now, expand window
            in_window[curr] = true;
            r++; lgt_window++;
            ans = Math.max(ans, lgt_window);
        }
        return ans;
    }
}