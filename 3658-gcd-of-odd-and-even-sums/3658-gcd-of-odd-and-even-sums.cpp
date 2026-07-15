class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        int count = 0;

        int i = 1;
        while(true){
            sumOdd += i;
            i+=2;
            count++;
            if(count == n) break;
        }
        i = 2;
        count = 0;
        while(true){
            sumEven += i;
            i+=2;
            count++;
            if(count == n) break;
        }
        return __gcd(sumOdd, sumEven);
    }
};