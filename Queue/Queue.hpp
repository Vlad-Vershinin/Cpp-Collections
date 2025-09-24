#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "../LinkedList/LinkedList.hpp"

namespace Queue {

    template <typename T>
    class Queue {
    private:
        LinkedList::LinkedList<T> list;

    public:
        bool Empty() const {
            return list.Empty();
        }

        void Push(const T& value) {
            list.PushBack(value);
        }

        T Pop() {
            if (Empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return list.PopFront();
        }

        T& Front() {
            return list.GetFront();
        }

        T& Rear() {
            return list.GetBack();
        }

        int Size() const {
            return list.Count();
        }
    };

}

#endif // !_QUEUE_HPP_
