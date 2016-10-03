//Queue implementation using 2 stacks.			|
//Idea: 2 stacks, one is inbox for enqueue,		|
//      another one is outbox for dequeue.		|
//      When enqueue, push the element into 	|
//      inbox, when dequeue, if outbox is		|
//      empty, push all element from inbox 		|
//      to outbox. If outbox is not empty		|
//      return the element on top of it.		|
//-----------------------------------------------


#include <iostream>
#include <stack>

using namespace std;

stack<int> inbox;
stack<int> outbox;


void enqueue(int toPush){
	inbox.push(toPush);
}

int dequeue(){
	if(outbox.empty()){
		while(!inbox.empty()){
			outbox.push(inbox.top());
			inbox.pop();
		}
	}
	int res = outbox.top();
	outbox.pop();
	return res;
}


int main(){
	cout << "pushing 1 into inbox" << endl;
	enqueue(1);
	cout << "pushing 2 into inbox" << endl;
	enqueue(2);
	cout << "pushing 3 into inbox" << endl;
	enqueue(3);
	cout << "pushing 4 into inbox" << endl;
	enqueue(4);
	cout << "the inbox now has " << inbox.size() << " elements." << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	cout << dequeue() << endl;
	if(outbox.empty())
		cout << "All elements are popped. " << endl;
	else
		cout << "SOMETHIGN IS NOT RIHGT " << endl;
}