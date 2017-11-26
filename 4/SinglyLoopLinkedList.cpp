#include<iostream>

using namespace std;

template <class elemType>
class queue
{
public:
	virtual bool isEmpty() = 0;
	virtual void enQueue(const elemType &x) = 0;
	virtual elemType deQueue() = 0;
	virtual elemType getHead() = 0;
	virtual ~queue() {};
};

template <class elemType>
class linkQueue :public queue< elemType >
{
public:
	linkQueue() { rear = NULL; }
	~linkQueue();
	bool isEmpty() { return rear == NULL; }
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead() { return (rear->next)->data; }
	elemType getRear() { return rear->data; }

private:
	struct node
	{
		elemType data;
		node * next;
		node(const elemType &x, node * N = NULL) {
			data = x; next = N;
		}
		node():next(NULL){}
		~ node(){}
	};

	node * rear;
};

template <class elemType>
linkQueue < elemType > :: ~linkQueue() {
	node * tmp;
	while (rear->next != rear) {
		tmp = rear;
		rear = rear->next;
		delete tmp;
	}
}

template <class elemType>
void linkQueue < elemType > :: enQueue(const elemType &x) {
	if (rear == NULL) {
		rear = new node(x);
	}
	else {
		if (rear->next == NULL) {
			rear->next = new node(x);
			(rear->next)->next = rear;
			rear = rear->next;
		}
		else {
			node * tmp = rear->next;
			rear->next = new node(x);
			(rear->next)->next = tmp;
			rear = rear->next;
		}
	}
}

template <class elemType>
elemType linkQueue < elemType > :: deQueue() {
	if (rear == rear->next) {
		elemType value = rear->data;
		delete rear;
		return value;
	}
	else {
		node * tmp = rear->next;
		elemType value = tmp->data;
		rear->next = tmp->next;
		delete tmp;
		return value;
	}
}

int main() {
	linkQueue<int> linkqueue;
	for (int i = 1; i < 10; i++) {
		linkqueue.enQueue(i);
		cout << linkqueue.getRear() << endl;
	}
	for (int i = 1; i < 9; i++) {
		linkqueue.deQueue();
		cout << linkqueue.getHead() << endl;
	}
	return 0;
}