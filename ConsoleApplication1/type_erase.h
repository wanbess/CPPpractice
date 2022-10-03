#include<memory>
#include<algorithm>
namespace detail {
	template<class T>
	class Smart_ptr {
	private:
		struct delete_base {
			virtual void func(T* t) {}
			virtual ~delete_base() {}
		};
		template<class Deletor>
		struct Deletet : delete_base {
			Deletet(Deletor d) :d(d) {}
			void func(T* t) override {
				d(static_cast<T*>(t));
			}
			Deletor d;
		};
		delete_base* dptr;
		T* t;
	public:
		template <class Deletor>
		Smart_ptr(T* t, Deletor&& d) :dptr(new Deletet(std::forward<Deletor>(d))), t(t) {}
		T* operator->() { return dptr; }
		T const* operator->() const { return dptr; }
		~Smart_ptr() {
			dptr->func(t);
			delete dptr;
		}
	};
}