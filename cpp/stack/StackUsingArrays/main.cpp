#include <StackUsingArrays.h>

int main()
{
	Stack<int> s;
	s.isEmpty();
	s.isFull();
	s.getTop();

	s.pop();
	s.getTop();

	s.push(88);
	s.getTop();
	s.isEmpty();
	s.isFull();
	 
	s.push(66);
	s.getTop();
	s.pop();
	s.getTop();

	return 0;
}