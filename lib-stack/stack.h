#pragma once
#include <iostream>
#include "../lib_TVector/TVector.h"
#include <initializer_list>

template <class T>
class Stack  {
	int _top;
	int _size;
	T* _data;
	bool isEmpty();
	bool isFull();
public:
	Stack() : _top(-1), _size(0), _data(nullptr){}
	Stack( T* data, int size);					// INIT 1
	Stack(std::initializer_list<T> data);			// INIT 2
	Stack(int size);								// INIT 3

	void push(const T& val);
	void pop();
	void clear() noexcept;
	T top();

	size_t topIndex() { return _top; }
	size_t size() { return _size; }

};

template <class T>
Stack<T>::Stack( T* data, int size) {
	_size = abs(size);
	_top = size - 1;
	_data = new T[_size];
	for (int i = 0; i < _size; i++) {
		_data[i] = data[i];
	}
}
template <class T>
Stack<T>::Stack(std::initializer_list<T> data) {
	_size = data.size();
	_top = _size - 1;
	_data = new T[_size];
	for (int i = 0; i < _size; i++) {
		_data[i] = *(data.begin() + i);
	}
}
template <class T>
Stack<T>::Stack(int size) {
	_size = abs(size);
	_data = new T[_size];
	_top = - 1;
}


template <class T>
void Stack<T>::push(const T& val) {
	if (isFull()) {
		throw std::length_error("stack is full");
	}
	_top++;
	_data[_top] = val;
}
template <class T>
void Stack<T>::pop() {
	if (isEmpty()) {
		throw std::length_error("stack is empty");
	}
	_data[_top] = NULL;
	_top--;
}


template <class T>
T Stack<T>::top() {
	return _data[_top];
}
template <class T>
bool Stack<T>::isFull() {
	return _top == _size - 1;
}
template <class T>
bool Stack<T>::isEmpty() {
	return _top == -1;
}