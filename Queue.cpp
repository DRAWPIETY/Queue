#include "Queue.h"

Queue::Queue()
{
	rear = maxqueue - 1;
	front = 0;
	count = 0;
}

bool Queue::full() const
{
	return count >= maxqueue;
}

int Queue::size() const
{
	return count;
}

bool Queue::empty() const
{
	return count == 0;
}

Error_code Queue::append(const Queue_entry &item)
{
	if(this->full()) return overflow;
	count++;
	rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}

Error_code Queue::serve()
{
	if(this->empty()) return underflow;
	count--;
	front=((front+1) == maxqueue)?0:(front +1);
	return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
{
	if(this->empty()) return underflow;
	item = entry[front];
	return success;
}