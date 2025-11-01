#include <list>

template <typename T>
class Node {
	T obj;
	T* next;

public:
	Node() {
		obj = 0;
		next = nullptr;
	}
	Node(std::list& list, size_t pos) {
		obj = list[pos];
		next = &list[pos + 1];
	}
};

template <typename T>
class List {
	// ...........
	Node<T> _head;
	Node<T>* tail;
	int count;

public:
	void pushBack(const T& obj);

	// .............................


	class Iterator;
	Iterator begin() { return Iterator(); }
	Iterator end() { return Iterator(nullptr); }

	class Iterator {
		Node<T>* current;
	public:
		Iterator() : current(_head) {}
		Iterator(Node<T>* pos) : current(pos) {}
		Iterator(const Iterator& oth) : current(oth.current) {}

		Iterator& operator=(const Iterator& other);
		T& operator*();
		bool operator!=(const Iterator other);
		Iterator operator++(int);
		Iterator& operator++();
	};

};