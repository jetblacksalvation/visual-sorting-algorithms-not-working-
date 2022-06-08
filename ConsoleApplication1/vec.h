#pragma once
#include <iostream>
template<class type>class vec {
public:
	vec() {
		size = 0;
		arr = (type*)malloc(0 * sizeof(type));
	}
	vec(std::initializer_list<type> list ) {
		arr = (type*)malloc(list.size() * sizeof(type));
		int count = 0;
		for (auto elem : list) {
			arr[count] = elem;
			count++;
		}
		size = (size_t)list.size();
	}
	vec(int alloc) {
		arr = (type*)malloc(alloc * sizeof(type));
		size = alloc - 1;
	}
	~vec() {
		delete[]arr;
	}
	void push_back(type new_variable) {
		arr = (type*)malloc(size + 1 * sizeof(type));
		arr[size] = new_variable;
		size++;
	}
	size_t length() {
		return size;
	}
	type operator[](size_t index) {
		if (index > size) {

			return NULL;
		}
		return arr[index];
	};

private:
	size_t size;

	type* arr;
};
