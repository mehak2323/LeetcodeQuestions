See something about toggle case here:
https://leetcode.com/problems/letter-case-permutation/discuss/115515/C%2B%2B-backtrack-solution-w-trick

```
backtrack(s, i + 1, res);
if (isalpha(s[i])) {
    // toggle case
    s[i] ^= (1 << 5);
    backtrack(s, i + 1, res);
}
```

Someone did this step this way:

```
// save initial value
char c = s[i];
// path1: toggle lower/upper case
s[i] = islower(c) ? toupper(c) : tolower(c);
backtrack(s, i + 1, ans);
// path2: reset back(NOT go to this path if c is digit)
if (isalpha(c)) {
    s[i] = c;
    backtrack(s, i + 1, ans);
}
 ```
 
 Revisit to understand.
