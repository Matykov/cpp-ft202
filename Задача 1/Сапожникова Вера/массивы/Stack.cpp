// массивы.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

template<class T>
class Stack {
	 struct node {
		T     val;
		node* next;
	};
private:
	node * head;
	size_t cnt;
public:

	Stack(void) :head(NULL), cnt(0) {
	}

public:

	bool push(const T& val) {
		node* p = (node*)malloc(sizeof(node));
		if (p != NULL) {
			p->val = val;
			p->next = head;
			head = p;
			++cnt;
		}
		return (p != NULL);
	}

	T pop(void) {
		node* prev = NULL;
		int val;
		if (head == NULL) {
			exit(-1);
		}
		prev = head;
		val = prev->val;
		head = head->next;
		free(prev);
		--cnt;
		return val;
	}

	void removeall(void) {
		node* prev = NULL;
		while (head->next) {
			prev = head;
			head = head->next;
			free(prev);
			--cnt;
		}
		free(head);
		--cnt;
	}

	size_t size(void) const { return cnt; }

	void print() {
		node* temp = head;
		while (head != NULL) {
			printf("%d ", head->val);
			head = head->next;
		}
		printf("\n");
		head = temp;
	}

	T peek() {
		if (head == NULL) {
			exit(-1);
		}
		return head->val;
	}

};


/*int main(void) {
	Stack<int> lc;
	for (int i = 0; i < 5; ++i) {
			lc.push(i);
	}
	lc.print();
	printf(" peek: %d\n ", lc.peek());
	printf("size: %d\n ", lc.size());
	printf("pop: %d\n ", lc.pop());
	printf("pop: %d\n ", lc.pop());
	lc.print();;

	lc.removeall();
	return 0;
}*/

