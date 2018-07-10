#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum Error_code
{
	overflow, underflow, success, fail
};

typedef char Queue_entry;

const int maxqueue = 10;

class Queue
{
public:
	Queue();
	bool full() const;
	int size() const;
	bool empty() const;
	Error_code append(const Queue_entry &item);
	Error_code serve();
	Error_code retrieve(Queue_entry & item) const;
private:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];

};