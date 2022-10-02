#ifndef STACK_H
#define STACK_H

namespace MyStack {
	const int kArrayGrowth = 5;

	template<typename T>
	class Stack {
		T* data;
		int size;
		int capacity;

		void resize(int);
	public:
		Stack();
		~Stack();

		Stack(int);
		Stack(std::initializer_list<T>&);
		Stack(Stack&);
		Stack(Stack&&);

		Stack<T> operator=(const Stack<T>&);

		void push(T);
		T pop();
		T check_pop();

		void operator<<(T);
		template<typename U> friend void operator>>(U&, Stack<U>&);

		bool empty();
		int get_size();
		int get_capacity();
		void clear();
		void optimize();

		bool operator==(Stack<T>&);
		bool operator!=(Stack<T>&);

		T& top();

		void swap(T);

		template<typename U> friend std::ostream& operator<<(std::ostream&, const Stack<U>&);
	};

	template<typename T>
	void Stack<T>::resize(int _capacity) {
		if (size > _capacity) _capacity = size;
		capacity = _capacity;

		T* temp_data = new T[capacity];
		for (int i = 0; i < size; ++i)
			temp_data[i] = data[i];

		if (data != nullptr) delete[] data;
		data = temp_data;
	}

	template<typename T>
	Stack<T>::Stack() {
		data = nullptr;
		capacity = size = 0;
	}

	template<typename T>
	Stack<T>::~Stack() {
		if (data != nullptr) delete[] data;
	}

	template<typename T>
	Stack<T>::Stack(int cap) {
		std::cout << "\n#Create Stack<int> data(" << cap << ")#\n"; //<------------------Отладка

		if (cap < 0) throw std::exception("Stack can't be negative");

		if (cap == 0) {
			size = capacity = 0;
			data = nullptr;
		}
		else {
			this->resize(cap);
			size = 0;
		}
	}

	template<typename T>
	Stack<T>::Stack(std::initializer_list<T>& list) {

	}

	template<typename T>
	Stack<T>::Stack(Stack<T>& other) {
		if (data != nullptr) delete[] data;

		capacity = other.capacity;
		size = other.size;

		data = new T[capacity];
		for (int i = 0; i < size; ++i)
			data = other.data[i];
	}

	template<typename T>
	Stack<T>::Stack(Stack<T>&& other) {

	}

	template<typename T>
	Stack<T> Stack<T>::operator=(const Stack<T>& other) {
		size = other.size;
		capacity = other.capacity;

		if (data != nullptr) delete[] data;

		data = new T[capacity];
		for (int i = 0; i < size; ++i)
			data[i] = other.data[i];

		return *this;
	}

	template<typename T>
	void Stack<T>::push(T element) {
		std::cout << "\n#ADD Stack<T>::push(" << element << ")#\n"; //<------------------Отладка
		if (capacity > size) {
			data[size++] = element;
		}
		else {
			this->resize(capacity + kArrayGrowth);
			data[size++] = element;
		}
	}

	template<typename T>
	T Stack<T>::pop() {
		if (size <= 0) throw std::exception("Stack is empty (Stack<T>::pop)");
		size--;
		std::cout << "\n#EXTRACT Stack<T>::pop() = " << data[size] << "#\n"; //<------------------Отладка
		return data[size];
	}

	template<typename T>
	T Stack<T>::check_pop() {
		if (size <= 0) throw std::exception("Stack is empty (Stack<T>::check_pop)");
		std::cout << "\n#RETURN Stack<T>::check.pop() = " << data[size - 1] << "#\n"; //<------------------Отладка
		return data[size - 1];
	}

	template<typename T>
	void Stack<T>::operator<<(T element) {
		this->push(element);
	}

	template<typename T>
	bool Stack<T>::empty()
	{
		return size <= 0 ? true : false;
	}

	template<typename T>
	int Stack<T>::get_size() {
		return size;
	}

	template<typename T>
	int Stack<T>::get_capacity() {
		return capacity;
	}

	template<typename T>
	void Stack<T>::clear() {
		std::cout << "\n#CLEAR Stack<T>::clear()\n"; //<------------------Отладка
		if (data != nullptr) delete[] data;
		data = nullptr;
		capacity = size = 0;
	}

	template<typename T>
	void Stack<T>::optimize() {
		std::cout << "\n#SYS Stack<T>::optimize()#\n"; //<------------------Отладка
		this->resize(-1);
	}

	template<typename T>
	bool Stack<T>::operator==(Stack<T>& other) {
		if (size == other.size) {
			for (int i = 0; i < size; i++) {
				if (data[i] != other.data[i]) return false;
			}
			return true;
		}
		return false;
	}

	template<typename T>
	bool Stack<T>::operator!=(Stack<T>& other) {
		return !(*this == other);
	}

	template<typename T>
	T& Stack<T>::top() {
		if (size <= 0) throw std::exception("Stack is empty (Stack<T>::top)");
		return data[size - 1];
	}

	template<typename T>
	void Stack<T>::swap(T element) {
		if (size <= 0) throw std::exception("Stack is empty (Stack<T>::swap)");
		data[size - 1] = element;
	}

	template<typename U>
	void operator>>(U& element, MyStack::Stack<U>& stck) {
		element = (stck.check_pop());
	}

	template<typename U>
	std::ostream& operator<<(std::ostream& os, const MyStack::Stack<U>& stck) {
		std::cout << "___________________\n Stack\n";
		os << stck.size << " of " << stck.capacity << std::endl;
		for (int i = 0; i < stck.size; i++)
			os << stck.data[i] << " ";
		os << "\n___________________\n";
		return os;
	}
}

#endif