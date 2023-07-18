#include<iostream>
using namespace std;
class cElement {
private:
	double x, y;
	cElement *next;
public:
	cElement():x(0),y(0){}
	void SetXY(double xx, double yy) { x = xx;y = yy; }
	double Y() { return y; }
	double X() { return x; }
	cElement *Next() { return next; }
	void Connect(cElement *p) { next = p; }
};
class cLinkElement {
private:
	cElement *head;
public:
	cLinkElement() :head(NULL) {}

	void Output() {
		cElement *buf = head;
		while (buf != NULL) {
			printf("(%g,%g)", buf->X(), buf->Y());
			buf = buf->Next();
		}
	}
	void AddElement(double n) {
		cElement *newnode = new cElement;
		newnode->SetXY(n, 2 * n);
		newnode->Connect(head);
		head = newnode;
	}
	void DeleteElement() {
		cElement *buf = head->Next();
		//printf("delete (%g,%g)\n", head->X(), head->Y());
		delete head;
		head = buf;
	}
	bool Check() {
		if (head != NULL) return true;
		else return false;
	}
};

void main() {
	cLinkElement list;
	for (int i = 0;i < 10;i++) list.AddElement(i);
	cout << "Elements in the list are:" << endl;
	list.Output();
	while (list.Check()) list.DeleteElement();
}