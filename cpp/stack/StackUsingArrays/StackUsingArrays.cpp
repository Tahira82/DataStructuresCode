#include <StackUsingArrays.h>

template <class T>
Stack<T>::Stack()
{
	m_nTop = -1;
}

//#############################################################################
template <class T>
Stack<T>::~Stack()
{
	m_nTop = -1;
}

//#############################################################################
template <class T>
bool Stack<T>::isEmpty()
{
	if (m_nTop == -1)
	{
		cout << "Stack is empty." << std::endl;
		return true;
	}
	return false;
}

//#############################################################################
template <class T>
bool Stack<T>::isFull()
{
	if (m_nTop == (m_nMaxSize - 1))
	{
		cout << "Stack is full." << std::endl;
		return true;
	}
	return false;
}

//#############################################################################
template <class T>
T Stack<T>::getTop()
{
	if (isEmpty())
		return 0;
	cout << "Top element's value is " << m_temStack[m_nTop] << std::endl;
	return (m_temStack[m_nTop]);
}

//#############################################################################
template <class T>
void Stack<T>::push(T value)
{
	if (isFull())
	{
		cout << "Stack overflow." << std::endl;
		return;
	}
	++m_nTop;
	m_temStack[m_nTop] = value;
}

//#############################################################################
template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack underflow." << std::endl;
		return 0;
	}
	T removed = m_temStack[m_nTop];
	cout << "Removed " << removed << " at location " << (m_nTop + 1) << std::endl;
	--m_nTop;
	return removed;
}

//#############################################################################
//template initialization for compiler
template class Stack<int>;

template class Stack<uint64_t>;
template class Stack<uint32_t>;
template class Stack<uint16_t>;
template class Stack<uint8_t>;

template class Stack<int64_t>;
template class Stack<int32_t>;
template class Stack<int16_t>;
template class Stack<int8_t>;

template class Stack<float>;

template class Stack<double>;

template class Stack<char>;

template class Stack<bool>;