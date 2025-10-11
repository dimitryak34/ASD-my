#pragma once
#define STEP_CAPACITY 15
#define classsssssssssss class 

template <typename T>
class Tvector {
protected:
	size_t _size;  // size of vector
	size_t _cap;   // capacity - memory for vector
	T* _data;
	void resetMemory(size_t newSize);

public:
	Tvector();
	Tvector(T* data, size_t size);
	Tvector(size_t size);
	~Tvector();
	void pushFront(T val);
	void pushBack(T val);
	void insert(size_t pos, T val);					//

	// delete the element
	T popFront();
	T popBack();
	void erase(size_t pos, size_t count = 1); // delete the currrent part of vector 

	T operator[](size_t pos) {
		T ret = this->_data[pos];
		return ret;
	}

	// getters of fields
	size_t size() const noexcept { return _size; }
	size_t cap() const noexcept { return _cap; }
	T* data() const noexcept { return _data; }

};








template <typename T>
Tvector<T>::Tvector() : _cap(1), _size(1), _data(nullptr) {}

template <typename T>
Tvector<T>::Tvector(T* data, size_t size) {
	_size = size;
	_cap = (_size + STEP_CAPACITY) / STEP_CAPACITY * STEP_CAPACITY;
	_data = new T[_cap];
	for (int i = 0; i < _size; i++) {
		_data[i] = data[i];
	}
}

template <typename T>
Tvector<T>::Tvector(size_t size) {
	_size = size;
	_cap = (_size + STEP_CAPACITY) / STEP_CAPACITY * STEP_CAPACITY;
	_data = new T[_cap];
	for (int i = 0; i < _size; i++) {
		_data[i] = 0;
	}
}



template <typename T>
Tvector<T>::~Tvector() {
	delete[] _data;
	_data = nullptr;
}

template <typename T>
T Tvector<T>::popBack() {
	_size -= 1;
	resetMemory(_size);
	return _data[_size];
}
template <typename T>
T Tvector<T>::popFront() {
	T pop = _data[0];
	for (int i = 0; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_size -= 1;
	resetMemory(_size);
	return pop;
}

template <typename T>
void Tvector<T>::resetMemory(size_t newSize) {
	size_t newCap = (newSize + STEP_CAPACITY) / STEP_CAPACITY * STEP_CAPACITY;
	if (newCap != _cap) {
		_cap = newCap;
		T* newData = new T[_cap];
		for (int i = 0; i < newSize; i++) {
			newData[i] = _data[i];
		}
		delete[] _data;
		_data = newData;
	}
}

template <typename T>
void Tvector<T>::erase(size_t pos, size_t count) {
	for (int i = pos; i < _size - count; i++) {
		_data[i] = _data[i + count];
	}
	_size -= count;
	resetMemory(_size);
}

template <typename T>
void Tvector<T>::insert(size_t pos, T val) {
	_size += 1;
	resetMemory(_size);
	for (int i = _size - 1; i > pos; i--) {
		_data[i] = _data[i - 1];
	}
	_data[pos] = val;

}
template <typename T>
void Tvector<T>::pushBack(T val) {
	_size += 1;
	resetMemory(_size);
	_data[_size - 1] = val;
}
template <typename T>
void Tvector<T>::pushFront(T val) {
	_size += 1;
	resetMemory(_size);
	for (int i = _size - 1; i > 0; i--) {
		_data[i] = _data[i - 1];
	}
	_data[0] = val;
}

