class Solution {
public:

    set<vector<int>> solve(vector<int> candidates, int target, vector<int> cur){
        int n = (int)candidates.size();
        set<vector<int>> ret;
        if(target == 0){//cur is a solution
            ret.insert(cur);
            return ret;
        }
        if(n == 0)return ret;
        //else target > 0 and we need to add elements to cur

        int last_element = candidates[n-1];
        //case1: use last_element
        set<vector<int>> case1;
        if(target >= last_element){
            cur.push_back(last_element);
            case1 = solve(candidates, target-last_element, cur);
            cur.pop_back();
        }
        //case2: do not use last_element
        candidates.pop_back();
        set<vector<int>> case2;
        case2 = solve(candidates, target, cur);
        //merge case1 and case2 then return ret
        for(vector<int> v : case1)ret.insert(v);
        for(vector<int> v : case2)ret.insert(v);
        return ret;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        reverse(candidates.begin(), candidates.end());
        set<vector<int>> aux = solve(candidates, target, vector<int>(0));
        vector<vector<int>> ret;
        for(vector<int> v : aux){
            ret.push_back(v);
        }
        return ret;
    }
};