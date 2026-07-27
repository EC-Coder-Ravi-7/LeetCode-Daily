class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int largest = 0;
        int secondLargest = 0;

        for(int &num : nums){
            if(num > largest){
                secondLargest = largest;
                largest = num;
            }
            else{
                secondLargest = max(secondLargest, num);
            }
        }
        return (largest-1) * (secondLargest-1);
    }
};