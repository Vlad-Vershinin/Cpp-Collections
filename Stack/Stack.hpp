#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "../LinkedList/LinkedList.hpp"

namespace Stack {
    template <typename T>
    class Stack {
    public:
        bool Empty() const {
            return list.Empty();
        }

        void Push(const T& value) {
            list.PushFront(value);
        }

        T Pop() {
            if (Empty()) {
                throw std::underflow_error("Stack is empty");
            }
            return list.PopFront();
        }

        T& Top() {
            return list.GetFront();
        }

        T& Bottom() {
            return list.GetBack();
        }

        int Size() const {
            return list.Count();
        }

    private:
        LinkedList::LinkedList<T> list;
    };
}

#endif // !_STACK_HPP_
