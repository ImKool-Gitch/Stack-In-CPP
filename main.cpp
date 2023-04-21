//Demo

#include <iostream>
#include "stack.hpp"

int main() {
	Stack <int> stack;
	stack.push(100);
	stack.push(100);
	stack.print_stack();
	stack.pop();
	std::cout << std::endl;
	stack.print_stack();
	std::cout << std::endl;
	stack.push(200);
	stack.print_stack();
	std::cout << std::endl;
	stack.peek();
	std::cout << std::endl;
	if (!stack.is_empty())
		std::cout << "Stack is not empty" << std::endl;
	else
		std::cout << "Stack is empty" << std::endl;
	return 0;
}

/*Output:
100
100

100

200
100

200

Stack is not empty
*/
