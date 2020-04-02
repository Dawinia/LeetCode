class Solution {
public:
    int sum(int n) {
        int sum = 0;
        while(n) {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = sum(slow);
            fast = sum(fast);
            fast = sum(fast);
            if(fast == 1)
                return 1;
        } while(slow != fast);
        return 0;
    }
};