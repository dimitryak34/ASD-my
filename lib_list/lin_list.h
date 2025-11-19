#include <list>

template <typename T>
class Node {
public:
	T _obj;
	Node<T>* _next;

	//friend class List<T>;
	Node() {
		_obj = 0;
		_next = nullptr;
	}

	Node(T val, Node<T>* next = nullptr) {
		_obj = val;
		_next = next;
		
	}
	//~Node() {
	//	_next = nullptr;
	//}

	//Node(std::list& list, size_t pos) {
	//	obj = list[pos];
	//	next = &list[pos + 1];
};

template <typename T>
class List {
	// ...........
	Node<T>* _head;
	Node<T>* _tail;
	int _count;			// number of nodes

public:
	List(): _head(nullptr), _tail(nullptr), _count(0){}
	List(const List& oth);
	~List();

	void pushBack(const T& obj) noexcept;
	void pushFront(const T& obj) noexcept;
	void insert(const T& obj, int pos);
	T erase(int pos);
	T popFront();
	bool isEmpty();
	Node<T>* find(const T& val) const;

	auto head() const noexcept { return _head; }
	auto tail()const noexcept { return _tail; }
	int count() const noexcept { return _count; }



	// ##############################	SUPPORTING CLASS ITERATOR	##################################
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
	// #################################################################################################
};





template <typename T>
List<T>::List(const List& oth) {
	if (_head != oth._head && _tail != oth._tail) {
		Node<T>* cur = _head;
		while (cur != nullptr) {
			pushBack(cur->_obj);
			cur = cur->_next;
		}
		_count = oth._count;
	}
}
template <typename T>
List<T>::~List() {
	Node<T>* temp;
	while (_head != nullptr) {
		temp = _head;
		_head = _head->_next;
		delete temp;
	}

	//delete _head;
	//_count = 0;
}







template <typename T>
bool List<T>::isEmpty() {
	if (_count == 0 && _tail == nullptr && _head == nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void List<T>::pushBack(const T& obj) noexcept {
	Node<T>* node = new Node<T>(obj);
	if (isEmpty()) {
		_head = node;
		_tail = node;
		_count++; 
		return;
	}
	_tail->_next = node;
	_tail = node;
	++_count;
}
template <typename T>
void List<T>::pushFront(const T& obj) noexcept {
	Node<T>* node = new Node<T>(obj);
	node->_next = _head;
	if (isEmpty()) { _tail = node; }
	_head = node;
	_count++;
}

template <typename T>
T List<T>::popFront() {
	Node<T>* temp;
		temp = _head;
		_head = _head->_next;

		T res = temp->_obj;
		delete temp;
		_count--;
		return res;
}
template <typename T>
T List<T>::erase(int pos) {
	if (pos == 0) {
		throw std::logic_error("unvalid position");
	}
	int i = 0;
	Node<T>* cur = _head, *temp;
	T res;
	while (i != pos-1) {
		cur = _head->_next;
		i++;
	}
	res = cur->_next->_obj;
	temp = cur->_next->_next;
	delete cur->_next;
	cur->_next = temp;
	if (pos == _count - 1) { _tail = cur; }
	_count--;
	return res;

}