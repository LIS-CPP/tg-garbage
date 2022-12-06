#include <iostream>
#include <set>

struct comparator {
	bool operator()(const int& a, const int& b) const {
		return b < a;
	}
};

int main() {
	std::set<int, comparator> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(4);

	for(auto&& el : s)
		std::cout << el << ' ';
	std::cout << std::endl;
}

