class Solution {
public:
    void build(int *seg, int *h, int idx, int l, int r){
        if(l == r){
            seg[idx] = h[l];
            return;
        }
        int fe = 2*idx + 1;
        int fd = fe+1;
        int mid = (l+r)/2;
        build(seg, h, fe, l, mid);
        build(seg, h, fd, mid+1, r);
        seg[idx] = max(seg[fe], seg[fd]);
    }
    int query(int *seg, int idx, int l, int r, int ql, int qr){
        if(qr < ql || l>qr || r<ql)return 0;
        if(l>=ql && r<=qr)return seg[idx];
        int fe = 2*idx + 1;
        int fd = fe+1;
        int mid = (l+r)/2;
        return max(query(seg, fe, l, mid, ql, qr), query(seg, fd, mid+1, r, ql, qr));
    }
    int trap(vector<int>& height) {
        //water[i] = min(maxH_left, maxH_right) - h[i]
        int n = height.size();
        int *seg = (int *)malloc(4*n*sizeof(int));
        int *h = (int *)malloc(n*sizeof(int));
        for(int i = 0; i<n; i++){
            h[i] = height[i];
        }
        build(seg, h, 0, 0, n-1);
        int water = 0;
        for(int i = 1; i < n-1; i++){
            water += max(0, min(query(seg, 0, 0, n-1, 0, i-1), query(seg, 0, 0, n-1, i+1, n-1)) - height[i]);
        }
        return water;
    }
};
