#include<iostream>
#include<vector>
#include<algorithm>
#include <iostream>
#include<vector>
#include<string>
#include<format>
#include<string_view>
#include<cassert>
#include<functional>
#include"stack.h"
#include"type_erase.h"
template <class T>
class Stack {
public:
	
	Stack(T s) : elems({s}) {}
	
private:
	std::vector<T> elems;
};
Stack(char const*)->Stack<std::string>;

template<class ...Args>
int printall(Args ...args) {
	return (args + ...);
}
int print() {
	return 0;
}
template<class T, class ...Args>
int print(T t, Args ...args) {
	return t+ print(args...);
}
template<typename T>
class Base {
public:
	void bar();
};
template<typename T>
class Derived : Base<T> {
public:
	void foo() {
		Base<T>::bar(); // calls external bar() or error
	}
};

template<int N>
void test(char const(&a)[N]) {

}

template<class T,template <typename> class Cont = std::vector>
class default_stact {
public:
	default_stact(T t) :elems({ t }) {}
	void push(T &&t);
private:
	Cont<T> elems;
};
template<class T, template <typename> class Cont>
void default_stact<T, Cont>::push(T&& t) {
	elems.emplace_back(std::forward<T>(t));
}
template<class T>
struct MyDeletor {
	template<typename = std::enable_if_t< std::is_fundamental_v<T>>>
	void operator()(T* t) {
		delete t;
	}

};
void testa(std::reference_wrapper<std::string> s) {
	s.get();
}
int main() {
	Stack ss(3);
	default_stact<int> d(2);
	d.push(4);
	detail::Stack<int> s;
	s.push(3);
	assert(s.top() == 3);
	detail::Stack<double> s2(3.1);
	s2.push(2.4);
	s2.push(4.5);
	assert(s2.top() == 4.5);
	s2 = s;
	assert(s2.top() == 3);
	detail::printstack("22");
	std::string const str{"233"};
	detail::printstack(std::move(str));
	detail::Smart_ptr<int> ptr(new int(2), MyDeletor<int>());
	std::string s4;
	std::string& s5 = s4;
	testa(std::ref<std::string>(s5));
	int int_a = 1;
	int int_c = 2;
	int& int_b = int_a;
	int_b = int_c;
	std::cout << int_a << std::endl;
}