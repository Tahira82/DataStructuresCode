#pragma once

#include <iostream>
using namespace std;

const uint64_t m_nMaxSize = 100;

template<class T>
class Stack
{
	//represents top of stack
	int m_nTop;

	//array represnting stack 
	T m_temStack[m_nMaxSize] = {};

  public:

	  //constructor
	  Stack();

	  //destructor
	  ~Stack();

	  //true if stack empty
	  bool isEmpty();

	  //true if full stack
	  bool isFull();

	  //push data to stack
	  void push(T value);

	  //remove data from stack
	  T pop();

	  //get Top value in stack
	  T getTop();
};
