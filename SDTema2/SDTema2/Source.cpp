#include<iostream>
struct node {
	int data;
	node* next;
};
struct lista {
	node* prim = nullptr;
	node* ultim = nullptr;
	int size = 0;
	void push_front(node*& cap,int value)
	{
		node* nodnou = new node;
		nodnou->data = value;
		nodnou->next = cap;
		cap = nodnou;
	}

};