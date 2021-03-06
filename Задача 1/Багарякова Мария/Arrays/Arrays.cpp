#include "pch.h"
#include<iostream>
using namespace std;

class LinearArray {
	int* pointer;
	size_t memorySize = pow(2, 30);
	size_t length = memorySize / sizeof(int);
public:
	LinearArray() {
		pointer = (int*)malloc(memorySize);
	}

	void set(int index, int value) {
		if (index >= length) {
			while (index >= length) {
				memorySize *= 2;
				int *newPointer = (int*)malloc(memorySize);
				memcpy(newPointer, pointer, length);
				length = memorySize / sizeof(int);
				delete[] pointer;
				pointer = newPointer;
			}
		}
		pointer[index] = value;
	}

	int get(int index) {
		if (index < length && index >= 0) {
			return pointer[index];
		}
		throw exception("Index out of range");
	}

	void remove_all() {
		delete[] pointer;
		memorySize = pow(2, 30);
		length = memorySize / sizeof(int);
		pointer = (int*)malloc(memorySize);
	}

	~LinearArray() {
		delete[] pointer;
	}
};

class Stack {
	int* pointer;
	size_t memorySize = pow(2, 30);
	size_t length = memorySize / sizeof(int);
	size_t lastElemIndex = -1;
public:
	Stack() {
		pointer = (int*)malloc(memorySize);
	}

	void push(int value) {
		if (lastElemIndex + 1 >= length) {
			memorySize *= 2;
			int *newPointer = (int*)malloc(memorySize);
			memcpy(newPointer, pointer, length);
			length = memorySize / sizeof(int);
			delete[] pointer;
			pointer = newPointer;
		}
		lastElemIndex++;
		pointer[lastElemIndex] = value;
	}

	int pop() {
		if (lastElemIndex != -1) {
			int result = pointer[lastElemIndex];
			lastElemIndex--;
			return result;
		}
		throw exception("Stack is empty");
	}

	void remove_all() {
		delete[] pointer;
		memorySize = pow(2, 30);
		length = memorySize / sizeof(int);
		pointer = (int*)malloc(memorySize);
	}

	~Stack() {
		delete[] pointer;
	}
};

struct ListItem {
	int value;
	ListItem* next;
};

class LinkedList {
	ListItem* first;
	size_t length;
public:
	LinkedList() {
		first = (ListItem*)malloc(sizeof(ListItem));
		first->next = NULL;
		length = 0;
	}

	void set(int index, int value) {
		ListItem* current = first;
		for (int i = 0; i <= index; i++) {
			if (current->next == NULL) {
				current->next = (ListItem*)malloc(sizeof(ListItem));
				current->next->next = NULL;
				length++;
			}
			current = current->next;
		}
		current->value = value;
	}

	int get(int index) {
		if (index < length && index >= 0) {
			ListItem* current = first;
			for (int i = 0; i <= index; i++) {
				current = current->next;
			}
			return current->value;
		}
		throw exception("Index out of range");
	}

	void push_back(int value) {
		ListItem *current = first;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = (ListItem*)malloc(sizeof(ListItem));
		length++;
		current->next->value = value;
		current->next->next = NULL;
	}

	int pop_back() {
		if (length > 0) {
			ListItem* current = first;
			ListItem* previous = NULL;
			while (true) {
				previous = current;
				current = current->next;
				if (current->next == NULL)
					break;
			}
			int value = current->value;
			length--;
			delete current;
			previous->next = NULL;
			return value;
		}
		throw exception("Index out of range");
	}

	void remove_all() {
		ListItem* current = first;
		while (current != NULL) {
			ListItem* next = current->next;
			delete current;
			current = next;
		}
		first = (ListItem*)malloc(sizeof(ListItem));
		first->next = NULL;
		length = 0;
	}

	~LinkedList() {
		ListItem* current = first;
		while (current != NULL) {
			ListItem* next = current->next;
			delete current;
			current = next;
		}
	}
};

int main() {
	LinearArray* array = new LinearArray();
	array->set(100, 555);
	printf("%i", array->get(100));
	printf("%s", "\n");
	array->set(1000000, 666);
	printf("%i", array->get(1000000));
	printf("%s", "\n");
	array->remove_all();
	printf("%i", array->get(1000000));
	printf("%s", "\n");
	delete array;

	Stack* stack = new Stack();
	stack->push(123);
	stack->push(455);
	printf("%i", stack->pop());
	printf("%s", "\n");
	printf("%i", stack->pop());
	printf("%s", "\n");
	delete stack;

	LinkedList* list = new LinkedList();
	list->set(0, 555);
	printf("%i", list->get(0));
	printf("%s", "\n");
	list->set(1, 666);
	printf("%i", list->get(1));
	printf("%s", "\n");
	list->push_back(777);
	printf("%i", list->pop_back());
	printf("%s", "\n");
	delete list;

	return 0;
}