#include<vector>

namespace detail {
	template<class T, template<class Elem, class Alloc = std::allocator<Elem>> class Cond = std::vector>
	class Stack {
	private:
		Cond<T> elems;
	public:
		Stack() = default;
		explicit Stack(T t) noexcept :elems({ t }) {}
		void push(T const&);
		void pop();
		T  const& top();
		//Cond2这里是模板参数模板，不能写成Stack<U,  Cond2<Elem2,Alloc2>> ，因为此时Cond2<Elem2,Alloc2>是
	   //具体的实例化的类，它不再是模板参数模板
		template<class U, template<class Elem2, class Alloc2 = std::allocator<Elem2>> class Cond2 = std::vector>
		auto operator=(Stack<U, Cond2> const& s) -> decltype(*this);
		//friend在template>后面在class 前面
		template<class U, template<class, class> class > friend class Stack;
	};
	template<class T, template<class Elem, class Alloc> class Cond>
	void Stack<T, Cond>::push(T const& t) {
		elems.push_back(t);
	}
	template<class T, template<class Elem, class Alloc> class Cond>
	void Stack<T, Cond>::pop() {
		elems.pop_back();
	}
	template<class T, template<class Elem, class Alloc> class Cond>
	T  const& Stack<T, Cond>::top() {
		return elems.back();
	}
	template<class T, template<class, class> class Cond>
	template<class U, template<class, class> class Cond2>
	auto Stack<T, Cond>::operator=(Stack<U, Cond2>  const& s) -> decltype(*this) {
		elems.clear();
		for (auto&&a_elem: s.elems) {
			this->elems.push_back(static_cast<T>(a_elem));
		}
		return *this;
	}
	template<class T>
	void printstack(T& s) {

	}
}


