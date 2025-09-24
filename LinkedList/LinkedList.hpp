#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

#include <stdexcept>

namespace LinkedList {

	template <typename T>
	struct Node
	{
		T data;
		Node<T>* next;
	};

	template <typename T>
	class LinkedList {
	public:
		LinkedList() {
			head = nullptr;
			tail = nullptr;
			count = 0;
		}

		~LinkedList() {
			Clear();
		}

		bool Empty() {
			return head == nullptr;
		}

		void Clear() {
			Node<T>* current = head;
			while (current != nullptr) {
				Node<T>* next = current->next;
				delete current;
				current = next;
			}
			head = nullptr;
			tail = nullptr;
			count = 0;
		}

		void PushBack(T d) {
			Node<T>* new_node = new Node<T>;
			new_node->data = d;
			new_node->next = nullptr;

			if (head == nullptr) {
				head = new_node;
			}
			else {
				Node<T>* current = head;

				while (current->next != nullptr)
				{
					current = current->next;
				}
				current->next = new_node;
			}
			count++;
		}

		void PushFront(T d) {
			Node<T>* new_node = new Node<T>;
			new_node->data = d;
			new_node->next = head;

			if (head == nullptr) {
				tail = new_node;
			}
			head = new_node;
			count++;
		}

		void Insert(T d, int index) {
			if (index < 0) {
				throw std::invalid_argument("Index cannot be negative");
			}

			Node<T>* new_node = new Node<T>;
			new_node->data = d;
			new_node->next = nullptr;

			if (index == 0) {
				new_node->next = head;
				head = new_node;
				return;
			}

			Node<T>* current = head;
			int counter = 0;

			while (current != nullptr && counter < index - 1) {
				current = current->next;
				counter++;
			}

			if (current == nullptr) {
				delete new_node;
				throw std::out_of_range("Index out of range");
			}

			new_node->next = current->next;
			current->next = new_node;
			count++;
		}

		void Remove(int index) {
			if (index < 0) {
				throw std::invalid_argument("Index cannot be negative");
			}

			if (index == 0) {
				Node<T>* temp = head;
				head = head->next;
				delete temp;
				return;
			}

			Node<T>* current = head;
			int counter = 0;

			while (current != nullptr && counter < index - 1) {
				current = current->next;
				counter++;
			}

			if (current == nullptr || current->next == nullptr) {
				throw std::out_of_range("Index out of range");
			}

			Node<T>* temp = current->next;
			current->next = temp->next;
			delete temp;
			count--;
		}

		T PopFront() {
			if (Empty()) {
				throw std::underflow_error("List is empty");
			}

			T data = head->data;
			Remove(0);
			return data;
		}

		T PopBack() {
			if (Empty()) {
				throw std::underflow_error("List is empty");
			}

			T data = tail->data;
			Remove(count - 1);
			return data;
		}

		T& GetFront() {
			if (Empty()) {
				throw std::underflow_error("List is empty");
			}
			return head->data;
		}

		T& GetBack() {
			if (Empty()) {
				throw std::underflow_error("List is empty");
			}
			return tail->data;
		}

		T& GetAt(int index) {
			if (index < 0 || index >= count) {
				throw std::out_of_range("Index out of range");
			}

			Node<T>* current = head;
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
			return current->data;
		}

		int Count() {
			return count;
		}

		Node<T>* GetHead() {
			return head;
		}
	private:
		Node<T>* head;
		Node<T>* tail;
		int count;
	};
}

#endif // !_LINKEDLIST_HPP_