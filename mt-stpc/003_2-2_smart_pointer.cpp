#include <iostream>

template<typename T>
class SmartPointer {
private:
	T* ptr;
public:
	SmartPointer(T* p) : ptr(p) {}
	operator T*() { return ptr; }
	T* operator->() { 
		if(!ptr){
			ptr = new T();
			std::cerr << "Bad pointer!" << std::endl;
		}
		return ptr; 
	}
	std::ptrdiff_t operator-(SmartPointer<T> p) {
		return ptr - p;
	}
	std::ptrdiff_t operator-(void* p) {
		return ptr - p;
	}
};

class Foo {
private:
	int a, b;
public:
	Foo() : a(0), b(0) {}
	Foo(int a, int b) : a(a), b(b) {}
	int Sum() { return a + b; }
};

int main() {
	SmartPointer<Foo> sp(nullptr);
	std::cout << sp->Sum() << std::endl;
}


