class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> countD(1e5+1, 0);
        for(int i=0; i<n; i++) {
            int d = abs(nums1[i]-nums2[i]);
            countD[d]++;
        }
        long long ans = 0;
        
        int k = k1 + k2;
        for(int currD=1e5; currD>0 && k > 0; currD--) {
            int currOps = min(countD[currD], k);
            countD[currD] -= currOps;
            countD[currD-1] += currOps;
            k-=currOps;
        }

        for(long long d=1; d<=1e5; d++){
            ans += (countD[d] * d*d);
        }

        return ans;
    }
};