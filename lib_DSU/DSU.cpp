#include "DSU.h"
#include <iostream>

DSU::DSU(size_t size) {
	_size = size;
	_parent = new int[_size];
	_rank = new int[_size];

	for (int i = 0; i < size; i++) {
		_parent[i] = i;
		_rank[i] = 0;
	}
}
DSU::~DSU() {
	delete[] _parent;
	delete[] _rank;
}


int DSU::find(int x) {
	if (_parent[x] == x) {
		count++;
		return x;
	}
	else {
		count++;
		return find(_parent[x]);
	}
}
void DSU::unite(int x1, int x2) {
	if (x1 == x2) { throw std::logic_error("unite the same node isn't allowed"); }

	int rank_1 = _rank[find(x1)], rank_2 = _rank[find(x2)];
	if (rank_1 < rank_2) {
		_parent[x1] = find(x2);
	}
	if (rank_1 == rank_2) {
		_rank[x1]++;
	}
	if (rank_1 > rank_2) {
		_parent[x2] = find(x1);
	}
}
