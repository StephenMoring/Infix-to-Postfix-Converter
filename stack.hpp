/*stephen moring*/ 

//constructor
template <typename T>
Stack<T>::Stack()
{}

//destructor
template <typename T>
Stack<T>::~Stack()
{
	pile.clear();
}

//copy constructor
template <typename T>
Stack<T>::Stack (const Stack<T>& S)
{
 /* if(!S.empty())
  {
	auto itr = S.pile.end();
	while (itr != S.pile.begin())
	{
	  pile.push_front(*itr);
	  itr--;
	}
  }*/
	pile = S.pile;
}

//move constructor 
template <typename T> 
Stack<T>::Stack (Stack<T>&& S) : pile{S.pile}
{
	S.clear();
} 

//copy assignment operator
template <typename T>
Stack<T>& Stack<T>::operator= (const Stack<T>& S)
{
	Stack temp(S);
	std::swap(*this, temp);
	return *this;	
		
}

//move assignment operator
template <typename T>
Stack<T>& Stack<T>::operator= (Stack<T>&& S)
{
	std::swap(pile, S.pile);
	return *this;
}

//tests if stack is empty
template <typename T>
bool Stack<T>::empty() const
{
	if (pile.empty())
		return true;
	return false;
}

//clears the stack
template <typename T>
void Stack<T>::clear() 
{
	pile.clear();
}

//adds elemnt to stack
template <typename T>
void Stack<T>::push (const T& x)
{
	pile.push_front(x);
}

//move version of push
template <typename T>
void Stack<T>::push (T&& x)
{
	pile.push_front(std::move(x));
}

//deletes top element of stack
template <typename T>
void Stack<T>::pop()
{
	pile.pop_front();
}

//returns modifiable L-value of the most recently added stack node
template <typename T>
T& Stack<T>::top()
{
	return pile.front();
}

//returns const version of most recently added stack node
template <typename T>
const T& Stack<T>::top() const
{
	return pile.front();
}

//returns size of stack
template <typename T>
int Stack<T>::size() const
{
	return pile.size();
}

//prints the contents of the stack
template <typename T>
void Stack<T>::print (std::ostream& os, char ofc)
{
	Stack<T> temp(*this);
	Stack<T> temp2;
	while(!temp.empty())
	{
	  temp2.push(temp.top());
	  temp.pop();
	  os << temp2.top() << ofc;
	}
	
}

//<< overload to print stacks with cascading
template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
	Stack<T> x(a);
	x.print(os);
	return os;
}

//equality operator overload
template <typename T>
bool operator== (const Stack<T>& x, const Stack<T>& y)
{
	
	if (x.size() == y.size())
	{
	  Stack<T> a(x);
	  Stack<T> b(y);	
	  
	  for (int i = 0; i < x.size(); i++)
	  {
		if (a.top() == b.top())
		{
			a.pop();
			b.pop();
		}
		else 
			return false;			
	  }
	}
	else 
		return false;
	
	return true;
}

//inequality comparison, opposite of ==
template <typename T>
bool operator!= (const Stack<T>& x, const Stack<T>& y)
{
	return !(x == y);
}

template <typename T>
bool operator<= (const Stack<T>& x, const Stack<T>& y)
{
	Stack<T> a(x);
	Stack<T> b(y);

	while (!a.empty())
	{
		if (a.top() <= b.top())
		{
		  a.pop();
		  b.pop();
		}
		else
			return false;
	}
	
	return true;
}
