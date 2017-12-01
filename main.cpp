#include "stdafx.h"
#include <sstream>
#include<iostream>

using namespace std;

struct node_t 
{
	int value;
	node_t * next;
};

bool read(char & op, int & value) {
	string line;
	getline(cin, line);
	istringstream stream(line);

	if (stream >> op) {
		if (op == '+' && stream >> value) {
			return true;
		}
		else if (op == '-' || op == '/' || op == '=' || op == 'q') {
			return true;
		}
	}
	return false;
}
void add_to_end(node_t * & head , int value)
{
	node_t * node = new node_t;
	node->value = value;
	node->next = nullptr;

	if (head == nullptr) {
		head = node;
	}
	else {
		node_t * last = head; 
		while (last->next) {
			last = last->next;
		}
		last->next = node;
	}
}
void delete_first(node_t * & head)
{
	node_t *time = head; // указатель 
	head = head->next;
	delete time; // т.к указатель , то при удалении удалиться и сам "элемент"
}
void print(node_t * head)
{
	node_t *el;
	el = head->next;

	while (el->next != nullptr) {
		cout << "+---+" << "    ";
		el = el->next;
	}
	el = head->next;
	cout << endl;

	while (el->next != nullptr) {
		cout << "| " << el->value << " |";
		el = el->next;
		if (el->next != nullptr) {
			cout << "--->";
		}
	}
	el = head->next;
	cout << endl;

	while (el->next != nullptr) {
		cout << "+---+" << "    ";
		el = el->next;
	}
	cout << endl;
}
void reverse(node_t * & head)
{
	node_t*new_head = nullptr;
	
	for (node_t*node = head; node; )
	{
		node_t * node_next = node->next;
		node->next = new_head;
		new_head = node;
		node = node_next;
	}
	head = new_head;
}
int main()
{
	node_t * head = nullptr;
	char op ;
	int value;
	while (read(op,value)) {
		if (op == 'q') {
			break;
		}
		switch (op) {
		case '+':
			add_to_end(head, value);
			break;
		case '-':
			delete_first(head);
			break;
		case '=':
			print(head);
			cin.get();
			break;
		case'/':
			reverse(head);
			break;
		}
	}
	return 0;
}
