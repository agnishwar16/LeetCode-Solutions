class Solution {
public:
    int reverse(int x) {
        long long number=x;
        long long reversem=0;
        while (number!=0){
            int digit=number%10;
            reversem=reversem*10+digit;
            number=number/10;

        }if(reversem > INT_MAX || reversem < INT_MIN)
             return 0;
        else
            return reversem;
    }
};