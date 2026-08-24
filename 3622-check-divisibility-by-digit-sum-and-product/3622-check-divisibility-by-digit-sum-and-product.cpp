class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(num >0)
        {
            int digit = num % 10;
            product *= digit;
            sum += digit;
            num = num/10;
        }


        int f_sum = sum + product;

        if(n % f_sum == 0)
        {
            return true;
        }
        return false;
    }
};