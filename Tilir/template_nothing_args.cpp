template<typename ... T>
class A : public T ... {
public:
	A(T ... x) : T(x) ... {}
};

int main() {
	A<> nothing;
}

