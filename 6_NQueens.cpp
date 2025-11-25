class Solution {
public:

    void backtrack(
        int n,
        int cur_row, //we have queens in rows 0..cur_row-1
        int cols_bitmask, //positions covered by col attacks
        int right_diags_bitmask, //positions covered by right diag attacks
        int left_diags_bitmask, //positions covered by left diag attacks
        vector<string> &cur,
        vector<vector<string>> &all_solutions)
    {
        if(cur_row >= n){
            all_solutions.push_back(cur);
            return;
        }

        string cur_line = "";
        for(int i=0; i<n; i++)cur_line+=".";

        for(int col=0; col<n; col++){
            if((cols_bitmask&(1<<col)) > 0)continue;
            if((right_diags_bitmask&(1<<col)) > 0)continue;
            if((left_diags_bitmask&(1<<col)) > 0)continue;
            //safe position => try to place queen at (cur_row, col)
            cur_line[col] = 'Q';
            cols_bitmask = (cols_bitmask|(1<<col));
            int new_right_diags_bitmask = (right_diags_bitmask|(1<<col))<<1;//one row down => shift right diags to the right
            int new_left_diags_bitmask = (left_diags_bitmask|(1<<col))>>1;//one row down => shift left diags to the left
            cur.push_back(cur_line);
            backtrack(n, cur_row+1, cols_bitmask, new_right_diags_bitmask, new_left_diags_bitmask, cur, all_solutions);
            //remove queen at (cur_row, col) to try other solutions
            cur.pop_back();
            cols_bitmask = (cols_bitmask^(1<<col));
            cur_line[col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> cur;
        backtrack(n, 0, 0, 0, 0, cur, ret);
        return ret;
    }
};
