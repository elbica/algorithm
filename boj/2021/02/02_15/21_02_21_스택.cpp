#include<iostream>
#include<string>
using namespace std;

class Stack {
public:
	struct Node {
		int e;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

	int s=0, capacity;

	Stack(int c) {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		capacity = c;
	}
	int size() { return s; }
	bool empty() { return s == 0; }
	void top() {
		if(!empty()) cout << tail->prev->e << endl;
		else cout << -1 << endl;
	}
	void push(int x) {
		s++;
		Node* newnode = new Node;
		newnode->e = x;
		Node* pre = tail->prev;
		pre->next = newnode; newnode->prev = pre;
		tail->prev = newnode; newnode->next = tail;
	}
	void pop() {
		if (empty()) cout << -1 << endl;
		else {
			s--;
			Node* temp = tail->prev;
			cout << temp->e << endl;
			Node* pre = temp->prev;
			pre->next = tail; tail->prev = pre;
			delete temp;
		}
	}
};
int main() {
	Stack myStack = Stack(10001);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; string s; cin >> s;
		if (s == "empty") cout << myStack.empty() << endl;
		else if (s == "push") {
			cin >> x; myStack.push(x);
		}
		else if (s == "size") cout << myStack.size() << endl;
		else if (s == "pop") myStack.pop();
		else if (s == "top") myStack.top();
	}

}