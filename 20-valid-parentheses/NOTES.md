Solutions locked in leetcode.
Not much to learn or need to revisit.

According to comments, everyone used the stack approach in one way or another. i.e., add open bracket to stack, if closed one comes and is same then pop, else, if the closing bracket is different or stack is empty, they're invalid. \

A good solution for this (in java) is to store closing brackets in stack whenever an opening one comes, so we know what to compare when a closing one comes in string:\

public boolean isValid(String s) { \
	Stack<Character> stack = new Stack<Character>();\
	for (char c : s.toCharArray()) {\
		if (c == '(')\
			stack.push(')');\
		else if (c == '{')\
			stack.push('}');\
		else if (c == '[')\
			stack.push(']');\
		else if (stack.isEmpty() || stack.pop() != c)\
			return false;\
	}\
	return stack.isEmpty();\
}\

Time Complexity: O(n)\
Space Complexity: O(n) //If all are opening brackets, all will be stored in stack
