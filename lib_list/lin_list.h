#include <list>

template <typename T>
struct Node {
	T obj;
	Node<T>* _next;

public:
	Node() {
		obj = 0;
		next = nullptr;
	}

	Node(T val, Node<T>* next = nullptr) {
		obj = val;
		if (next != nullptr) {
			_next = next;
		}
	}

	Node(std::list& list, size_t pos) {
		obj = list[pos];
		next = &list[pos + 1];
	}
};

template <typename T>
class List {
	// ...........
	Node<T>* _head;
	Node<T>* _tail;
	int _count;

public:
	List(): _head(nullptr), _tail(nullptr), _count(0){}
	List(const List& oth);

	void pushBack(const T& obj) noexcept;
	void pushFront(const T& obj) noexcept;
	void insert(const T& obj, int pos);
	T popBack();
	T popFront();
	bool isEmpty();
	Node<T>* find(const T& val) const;




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


template <typename T>
void List<T>::pushBack(const T& obj) noexcept {
	Node<T>* node = new Node<T>(obj);
	if (isEmpty()) {
		_head = _tail = node;
		_count++; 
		return;
	}
	_tail->_next = node;
	_tail = node;
	++_count;
}