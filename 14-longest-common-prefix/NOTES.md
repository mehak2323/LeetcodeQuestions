Revisit for divide and conquer, binary search, Trie?

SOLUTIONS AVAILABLE for this question.


Learn about vertical scanning in this example. (first loop is length of first string and second is all strings, compare how far in first string we can go till all values in second loop are same.)
Code:
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}

A good solution from comments:
Sort the vector, then the first and last strings will be with most distinct characters. Just find common prefix in them.
OR, to optimize this, find shortest and largest string instead of sorting then find common prefix in them.
Here: https://leetcode.com/problems/longest-common-prefix/discuss/391089/C%2B%2B-Easy-to-understand-solution-%3A-Using-sort 


Time Complexity: O(n*m) or O(S) //n=total strings, m=string length 
Space Complexity: O(1) //for most soln except dac
