#pragma once
#include <initializer_list>

template <class T>
class TQueue {
	size_t _size, _count;
	int _head;
	T* _data;
public:
	TQueue(): _data(nullptr), _head(0), _size(0), _count(0){}
	TQueue(std::initializer_list<T> data);
	TQueue(size_t size);


	T head() const;

	void push(const T& val);
	void pop();
	bool isEmpty();
	bool isFull();
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
	_head = _size - 1;
	_count = 0;
}


template <class T>
T TQueue<T>::head() const { return _data[_head]; }
