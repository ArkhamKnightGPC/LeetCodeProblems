class Solution {

    public double findIndexValue(int[] nums1, int[] nums2, int idx){
        int size1 = nums1.length;
        int size2 = nums2.length;
        /* we want to find a value >= idx other elements
         * binary search for value
         * to test each value, another binary search
         * Complexity: log squared */
        int leftLimit = Math.min(nums1[0], nums2[0]);
        int rightLimit = Math.max(nums1[size1 - 1], nums2[size2 - 1]);
        while(leftLimit < rightLimit){
            int mid = (leftLimit + rightLimit + 1)/2;

            //count how many elements < mid in nums1 (find first element >=)
            int leftLimit1 = 0;
            int rightLimit1 = size1 - 1;
            int count1 = 0;
            if(nums1[rightLimit1] < mid){//corner case
                count1 = rightLimit1 + 1;
            }else{//binary search :)
                while(leftLimit1 < rightLimit1){
                    int mid1 = (leftLimit1 + rightLimit1)/2;
                    if(nums1[mid1] < mid){
                        leftLimit1 = mid1 + 1;
                    }else{
                        rightLimit1 = mid1;
                    }
                }
                count1 = leftLimit1;
            }
            //count how many elements < mid in nums2
            int leftLimit2 = 0;
            int rightLimit2 = size2 - 1;
            int count2 = 0;
            if(nums2[rightLimit2] < mid){//corner case
                count2 = rightLimit2 + 1;
            }else{//binary search :)
                while(leftLimit2 < rightLimit2){
                    int mid2 = (leftLimit2 + rightLimit2)/2;
                    if(nums2[mid2] < mid){
                        leftLimit2 = mid2 + 1;
                    }else{
                        rightLimit2 = mid2;
                    }
                }
                count2 = leftLimit2;
            }


            if(count1 + count2 <= idx){//we need a value >= mid
                leftLimit = mid;
            }else{//we need a value < mid
                rightLimit = mid - 1;
            }
        }
        return leftLimit;
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int size1 = nums1.length;
        int size2 = nums2.length;
        if(size1 == 0){//corner case
            if(size2%2 == 0)return (nums2[(size2 - 1)/2] + nums2[(size2 + 1)/2])/2.0;
            else return nums2[(size2 - 1)/2];
        }
        if(size2 == 0){//corner case
            if(size1%2 == 0)return (nums1[(size1 - 1)/2] + nums1[(size1 + 1)/2])/2.0;
            else return nums1[(size1 - 1)/2];
        }
        int mid = (size1 + size2)/2 - 1;
        if((size1 + size2)%2 == 0){
            double median1 = findIndexValue(nums1, nums2, mid);
            double median2 = findIndexValue(nums1, nums2, mid + 1);
            return (median1 + median2)/2.0;
        }else{
            double median = findIndexValue(nums1, nums2, mid + 1);
            return median;
        }
    }

}

