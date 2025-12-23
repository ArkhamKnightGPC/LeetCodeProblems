class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret (n, vector<int>(n, 0));
        int nsq = n*n;
        int i=0, j=0;
        bool going_right = true;
        bool going_down = false;
        bool going_left = false;
        bool going_up = false;
        for(int k=1; k<=nsq; k++){
            ret[i][j] = k;
            if(going_right){
                if(j+1 >= n || ret[i][j+1]!=0){//time to start going down
                    going_right = false;
                    going_down = true;
                    i++;
                }else{
                    j++;
                }
            }else if(going_down){
                if(i+1 >= n || ret[i+1][j]!=0){//time to start going left
                    going_down = false;
                    going_left = true;
                    j--;
                }else{
                    i++;
                }
            }else if(going_left){
                if(j-1 < 0 || ret[i][j-1]!=0){//time to start going up
                    going_left = false;
                    going_up = true;
                    i--;
                }else{
                    j--;
                }
            }else{//going up
                if(i-1 < 0 || ret[i-1][j]!=0){
                    going_up = false;
                    going_right = true;
                    j++;
                }else{
                    i--;
                }
            }
        }
        return ret;
    }
};