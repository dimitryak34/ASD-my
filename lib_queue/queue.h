#pragma once
#include <initializer_list>

template <class T>
class TQueue {
	size_t _size, _count;
	int _head;
	T* _data;
public:
	TQueue(): _data(nullptr), _head(-1), _size(0), _count(0){}
	TQueue(std::initializer_list<T> data);
	TQueue(size_t size);


	T head() const;

	void push(const T& val);
	void pop();
	bool isEmpty();
	bool isFull();

	size_t size() { return _size; }
	size_t count() { return _count; }
	int head() { return _head; }

};

template <class T>
TQueue<T>::TQueue(std::initializer_list<T> data) {
	_size = data.size();
	_head = _size - 1;
	_count = _size;
	_data = new T[_size];
	for (int i = 0; i < _size; i++) {
		_data[i] = *(data.begin() + i);
	}
}
template <class T>
TQueue<T>::TQueue(size_t size) {
	_data = new T[size];
	_size = size;
	for (int i = 0; i < _size; i++) {
		_data[i] = 0;
	}
	_head = _size - 1;
	_count = _size;
}


template <class T>
T TQueue<T>::head() const { return _data[_head]; }

template <class T>
void TQueue<T>::push(const T& val) {
	if (isFull()) {
		throw std::length_error("queue massive is full");
	}
	_count++;
	_data[(_head + (_size - _count)) % _size] = val;
}

template <class T>
void TQueue<T>::pop() {
	if (isEmpty()) {
		throw std::length_error("queue massive is empty");
	}
	_count--;
	_head = (++_head) % _size;
}

template <class T>
bool TQueue<T>::isFull() {
	if (_count == _size) {
		return true;
	}
	return false;
}
template <class T>
bool TQueue<T>::isEmpty() {
	if (_count == 0) { return true; }
	return false;
}