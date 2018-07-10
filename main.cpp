#include "Queue.h"

void add_q(const string &s, Queue &ql, Queue &qr)
{
	for(unsigned int i = 0; i < s.size(); i++)
	{
		if(s[i] == ':') break;
		ql.append(s[i]);
	}
	for(unsigned int i = ql.size()+1; i < s.size(); i++)
	{
		qr.append(s[i]);
	}
}

char judge(Queue ql, Queue qr)
{ 
	if(qr.empty()) return 'N';
	else if(ql.size() > qr.size()) 
		return 'L';
	else if(ql.size() < qr.size())
		return 'R';
	else 
	{
		Queue_entry lift, right;
		while(!ql.empty())
		{
			ql.retrieve(lift);
			qr.retrieve(right);
			ql.serve();
			qr.serve();
			if(lift != right) return 'D';
		}
		return 'S';
	}
}

int main()
{
	string s;
	getline(cin, s);
	Queue ql, qr;
	add_q(s,ql, qr);
	cout << judge(ql, qr) << endl;
	return 0;
}