#include <iostream>
#include <string>
#include <assert.h>

using namespace std;


template<typename ST>
struct node
{
	ST data;
	node<ST>* next;
};

template<class T>
class stack
{
private:
	node<T>* stackTop;
	int count = 0;
public:
	stack()
	{
		stackTop = nullptr;
	}


	stack(const stack<T>& otherStack) //copy constructor
	{
		stackTop = nullptr;
		copyStack(otherStack);
	}


	const stack<T>& operator=(const stack<T>& otherStack) //assignment operator overloading
	{
		if (this != &otherStack)
		{
			copyStack(otherStack);
		}
		return *this;
	}

	void initializeStack() //initializestack for destructor and copystack function
	{
		node<T>* curr = nullptr;
		while (stackTop != nullptr)
		{
			curr = stackTop;
			stackTop = stackTop->next;
			delete curr;
		}
		count = 0;
	}

	~stack()
	{
		initializeStack();
	}


	bool isEmptyStack() const
	{
		if (stackTop == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


	void push(T value)
	{
		node<T> * temp = new node<T>;
		temp->data = value;
		temp->next = stackTop;
		stackTop = temp;
		count++;
	}


	void pop()
	{
		if (stackTop != nullptr)
		{
			node<T>* curr = nullptr;
			curr = stackTop;
			stackTop = stackTop->next;
			curr->next = nullptr;
			delete curr;
			count--;
		}
		else
		{
			cout << "cannot remove form an ampty stack" << endl;
		}
	}

	int size()
	{
		return count;
	}

	T top()
	{
		assert(stackTop != nullptr);
		return stackTop->data;
	}


	void copyStack(const stack<T>& otherStack)
	{
		node<T>* temp;
		node<T>* curr = nullptr;
		node<T>* last = nullptr;
		node<T>* temp2;
		cout << stackTop;
		if (stackTop != nullptr)
		{
			initializeStack();
		}
		if (otherStack.stackTop == nullptr)
		{
			stackTop == nullptr;
		}
		else
		{
			curr = otherStack.stackTop;

			temp2 = new node<T>;
			temp2->data = curr->data;
			temp2->next = nullptr;
			stackTop = temp2;
			last = stackTop;

			//stackTop = new node<T>;
			//stackTop->data = curr->data;
			//stackTop->next = nullptr;
			//last = stackTop;
			curr = curr->next;
			while (curr != nullptr)
			{
				temp = new node<T>;
				temp->data = curr->data;
				temp->next = nullptr;
				last->next = temp;
				last = temp;
				curr = curr->next;
			}
		}
	}



};

int main()
{
	stack<char> extra;

	extra.push('a');
	extra.push('b');
	extra.push('c');
	char one = extra.top();
	extra.pop();
	char two = extra.top();
	extra.pop();
	char three = extra.top();
	extra.pop();
	cout << one << " " << two << " " << three << endl;


	system("pause");
	return 0;
}