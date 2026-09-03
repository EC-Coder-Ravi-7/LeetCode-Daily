class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        uint32_t z[2] = {-1u, -1u};

        for(uint32_t a : nums1){
            z[a & 1] = min(z[a&1], a);
        }
        return z[1] < z[0] | z[1] == -1u;
    }
};