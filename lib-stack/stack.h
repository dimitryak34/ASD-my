#include <iostream>
#include "../lib_TVector/TVector.h"

template <class T>
class Stack:  {
	size_t _top;
	size_t _size;
	T* _data;
public:
	Stack() : _top(0), _size(0), _data(nullptr){}
	Stack(const T& data, size_t size);
	Stack(std::initializer_list<T> data, size_t size);

	void push(const T& val);
	void pop();
	void clear() noexcept;
	T top();
	bool isEmpty();
	bool isFull();

};

template <class T>
Stack<T>::Stack(const T& data, size_t size) {
	_size = size;
	_top = size - 1;
	_data = new T[_size];
	for (int i = 0; i < _size; i++) {
		_data[i] = data[i];
	}
}
template <class T>
Stack<T>::Stack(std::initializer_list<T> data, size_t size) {
	_size = size;
	_top = _size - 1;
	_data = new T[_size];
	for (int i = 0; i < size; i++) {
		_data[i] = data[i];
	}
}