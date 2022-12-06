#include <iostream>
#include <memory>

struct B;

struct A {
	int value;
	std::shared_ptr<B> b;
	A() { std::cout << "A()" <<  std::endl;}
	~A() { std::cout << "~A()" << std::endl; }
};
struct B {
	int value;
	std::weak_ptr<A> a;
	B() { std::cout << "B()" <<  std::endl;}
	~B() { std::cout << "~B()" << std::endl; }
};

int main() {
	std::shared_ptr<A> a(new A());
	std::shared_ptr<B> b(new B());
	a->b = b;
	b->a = a;

	a->value = 123;
	{
		std::shared_ptr<A> aa = b->a.lock();
		std::cout << aa->value << std::endl;
	}	
}

