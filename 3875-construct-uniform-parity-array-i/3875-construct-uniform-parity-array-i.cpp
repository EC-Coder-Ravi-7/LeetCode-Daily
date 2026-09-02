class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> arr(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i != j){
                    arr[i] = nums1[i] - nums1[j];
                } else {
                    arr[i] = nums1[i];
                }
            }
        }
        return arr != nums1;
    }
};