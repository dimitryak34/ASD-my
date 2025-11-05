#pragma once

class DSU {
	int* _parent;
	int* _rank;
	size_t _size;
	int count = 0;
public:
	DSU(size_t size);
	~DSU();

	void unite(int, int);
	int find(int);

	int getCount() const { return count; }

};

