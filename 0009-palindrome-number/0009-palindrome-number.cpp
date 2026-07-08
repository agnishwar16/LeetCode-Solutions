class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
             return false;
        int original=x;
        int number=x;
        long long  reverse=0;
        while (number>0){
            int digit=number%10;

            reverse =reverse*10+digit;

            number=number/10;
        }
        if(reverse==original){
            return true;

        }else{
            return false;
        }
    }
};