#include <iostream>
#include <unordered_set>

struct hasher {
	size_t operator()(const int& a) const {
		return a % 2;
	}
};

int main() {
	std::unordered_set<int, hasher> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);

	for(auto&& el : s)
		std::cout << el << ' ';
	std::cout << std::endl;
}

