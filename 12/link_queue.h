#include<string>

#ifndef LINK_QUEUE_
#define LINK_QUEUE_

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
	linkQueue() { front = rear = NULL; }
	~linkQueue();
	bool isEmpty() { return front == NULL; }
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead() { return front->data; }

private:
	struct node
	{
		elemType data;
		node * next;
		node(const elemType &x, node * N = NULL)
		{
			data = x; next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};

	node *front, *rear;
};

template <class elemType>
linkQueue < elemType > :: ~linkQueue()
{
	node * tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

template <class elemType>
void linkQueue < elemType > ::enQueue(const elemType &x)
{
	if (rear == NULL)
	{
		front = rear = new node(x);
	}
	else
	{
		rear->next = new node(x);
		rear = rear->next;
	}
}

template<class elemType>
elemType linkQueue<elemType>::deQueue()
{
	node * tmp = front;
	elemType value = front->data;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete tmp;
	return value;
}

#endif // LINK_QUEUE_