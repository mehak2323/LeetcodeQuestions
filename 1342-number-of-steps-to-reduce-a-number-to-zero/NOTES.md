- Method 1: 
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/502809/just-count-number-of-0-and-1-in-binary

Usually we have to divide the number by 2 if it's even and subtract 1 if it's odd. \
Look if we see the binary form of an even number, we'll get 0 in the last and for odd numbers there will be 1 in the end. 2 -> 10 and 3 -> 11

Now "&" operator returns 1 if both operands are 1 otherwise 0. \
So, if we compute 8 & 1 ->> (1000 & 1) ->> (1000 & 0001) ->> 0000 \
and 3 & 1 ->> 11 & 1 ->> 01 \
this is what the statement does: num & 1 ->> so if returns 0(for even) we'll have to divide by 2, means number of operations are 1 and if returns 1(for odd) we'll have to first subtract 1 then divide, so no. of operations became 2. Hence we do the above operation.

After this num >>= 1 divides the number by 2, as irrespective of it is even or odd we'll get the same answer, so simply divide and as we've already calculated the answer already.

And for the left most 1 for which we'll get 0 by just subtracting 1 but our logic considers it 2 so at last do res - 1.

```
int numberOfSteps (int num) {
		if(!num) return 0;
        int res = 0;
        while(num) {
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return res - 1;
    }
```

- Method 2: 
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/1062161/C%2B%2B-or-Bit-Manipulation-or-5-Approaches-or-0ms-O(logn)-Beats-100

INFORMATION

- num=num>>1 right shift num is equivalent to num=num/2
- bitset<32>(num).count() = number of set bits(1) in num
- log2(num)=number of bits required to make the num - 1
- __builtin_clz(num) = It counts number of zeros before the first occurrence of 1 (set bit), that is leading zeroes in num
- __builtin_popcount(num) = number of set bits(1) in num
- log2(num) is equivalent to 31 - __builtin_clz(num)
- bitset<32>(num).count() is equivalent to __builtin_popcount(num)

Approach 1 (Iterative, simulating the process)
```
class Solution {
public:
    int numberOfSteps (int num) {
        int count=0;
        while(num){
            if(num%2){ // odd
                --num;
            }
            else{ // even
                num>>=1; // num=num/2
            }
            ++count;
        }
        return count;
    }
};
```
Approach 2 (Built-In)
```
class Solution {
public:
    int numberOfSteps (int num) {
        return num ? log2(num) + bitset<32>(num).count() : 0;
    }
};
```
Approach 3 (Built-In)
```
class Solution {
public:
    int numberOfSteps (int num) {
        return num ? log2(num) + __builtin_popcount(num) : 0;
    }
};
```
Approach 4 (Built-In)
```
class Solution {
public:
    int numberOfSteps (int num) {
        return num ? 31 - __builtin_clz(num) + bitset<32>(num).count() : 0;
    }
};
```
Approach 5 (Built-In)
```
class Solution {
public:
    int numberOfSteps (int num) {
        return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
    }
};
```
TIME COMPLEXITY: O(logn)

SPACE COMPLEXITY: O(1)
