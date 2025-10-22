#include "algorithms.h"


bool checkBrackets(std::string st) {
	int size = st.size();
	char* data = new char[size];
	for (int i = 0; i < size; i++) {
		data[i] = st[i];
	}

	Stack<char> stack(size);
	char temp;
	for (int i = 0; i < size; i++) {
		if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
			stack.push(data[i]);
		}
		if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
			temp = stack.top();
			if (temp == '(' && data[i] == ')' || temp == '[' && data[i] == ']' || temp == '{' && data[i] == '}') {
				stack.pop();
			}
			else {
				return false;
			}
		}

	}
	if (stack.isEmpty()) {
		return true;
	}
	else { return false; }
}