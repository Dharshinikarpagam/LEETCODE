Sum of Two Integers Without Using + and -

This problem calculates the sum of two integers using bitwise operators instead of the addition and subtraction operators.

XOR (^) calculates the sum without considering the carry.
AND (&) identifies the carry bits.
Left shift (<< 1) moves the carry to the next position.
The process repeats until the carry becomes zero.

Finally, the variable a contains the sum of the two integers.

Time Complexity: O(1)
Space Complexity: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0)
        {
            int sum=a^b;
            int carry=(a&b);
            carry=carry<<1;
            a=sum;
            b=carry;
        }
        return a;
    }
};
