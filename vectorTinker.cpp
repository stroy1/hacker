#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct Node{
	string contents;
};

int main(){

	list<Node *> l;
	Node *n = new Node();
	n->contents = "Hello";
	cout << n->contents << endl;
	l.push_back(n);
	cout << "before: " << l.front()->contents << endl;
	Node *after = l.front();
	l.pop_front();

	string words = after->contents;
	cout << "After: " << after->contents << endl;
	delete(after);
	cout << "deleted: " << after->contents << endl;
	delete(after);
	cout << "deleted Twice: " << after->contents << endl;

	return 0;

}
