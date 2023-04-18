#include <iostream>

template <typename T>
class Stack {
private:
	T* stack;
	// i is a counter for how many elements are in the stack
	unsigned i;
public:
	Stack() {
		stack = nullptr;
		i = 0;
	}
	~Stack() {
		delete[] stack;
	}
	void push(T data) {
		//If there are no elements, the stack is allocated for one element and the new element is copied the first element. In the end i is incremented
		if (i == 0) {
			stack = new T[1];
			stack[0] = data;
			++i;
		}
		else {
			/*How push works :
				the current stack is copied to a temporary stack and the stack is deallocated, after that, the stack
				is allocated for one extra element, and the new element is copied to the first element, after that, the whole temporary stack is copied to the stack. In the end
				i is incremented
			*/
			T* temp_stack = new T[i];
			for (unsigned j = 0; j < i; ++j)
				temp_stack[j] = stack[j];
			delete[] stack;
			stack = new T[i + 1];
			stack[0] = data;
			for (unsigned j = 1; j < i + 1; ++j) {
				stack[j] = temp_stack[j - 1];
			}
			++i;
			delete[] temp_stack;
		}
	}
	void pop() {
		//If there is only one element, the stack is deallocated then nullptr is assigned to it, to indicate that its empty, then i is decremented.
		if (i == 1) {
			delete[] stack;
			stack = nullptr;
			--i;
		}
		else if (i == 0)
			return;
		else {
			/*How pop works:
				the current stack is copied to a temporary stack excluding the first element and the stack is deallocated, 
				then the stack is allocated for (current elements - 1) elements, then all the elements in the temporary stack are copied
				to the stack.
				In the end i is decremented.
			*/
			T* temp_stack = new T[i - 1];
			for (unsigned j = 0; j < i - 1; ++j)
				temp_stack[j] = stack[j + 1];
			delete[] stack;
			stack = new T[i - 1];
			for (unsigned j = 0; j < i - 1; ++j)
				stack[j] = temp_stack[j];
			delete[] temp_stack;
			--i;
		}
	}
	void print_stack() {
		for (unsigned j = 0; j < i; ++j)
			std::cout << stack[j] << std::endl;
	}
	void peek() {
		if (is_empty())
			return;
		std::cout << stack[0] << std::endl;
	}
	bool is_empty() {
		if (i == 0)
			return true;
		return false;
	}
};

//Demo

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
