#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "../LinkedList/LinkedList.hpp"
#include <stdexcept>

namespace Stack {
	template<typename T>
	class Stack {
	public:
		bool Empty() const {
			return list.Empty();
		}

		void Push(const T& value) {
			list.Insert(value, 0);
		}

		void Pop() {
			if (Empty()) {
				throw std::underflow_error("Stack is empty");
			}
			list.Remove(0);
		}

		T& Top() {
			if (Empty()) {
				throw std::underflow_error("Stack is empty");
			}
			auto* firstNode = list.GetHead();
			return firstNode->data;
		}



		size_t Size() const {
			return list.Count();
		}
	private:
		LinkedList::LinkedList<T> list;
	};
}

#endif // !_STACK_HPP_