/* stephen moring*/
#ifndef STACK_H
#define Stack_H
#include <list>
#include <iostream>
namespace cop4530
{
	template < typename T >
	class Stack
	{
	  public:
		Stack();
		~Stack();
		Stack (const Stack<T>&);
		Stack (Stack<T>&&);
		Stack<T>& operator= (const Stack<T>&);
		Stack<T>& operator= (Stack<T>&&);
		bool empty() const;
		void clear();
		void push (const T& x);
		void push (T && x);
		void pop();
		T& top();
		const T& top() const;
		int size() const;
		void print(std::ostream& os, char ofc = ' ');

	  private:
		std::list<T> pile; // list class used to adapt into stack  
		
	};

	  template <class T>
	  std::ostream& operator<< (std::ostream& os, const Stack<T>& a);

	  template <class T>
	  bool operator== (const Stack<T>&, const Stack<T>&);

	  template <class T>	
	  bool operator!= (const Stack<T>&, const Stack<T>&);

	  template <class T>
	  bool operator<= (const Stack<T>&, const Stack<T>&);


	#include "stack.hpp"
}

#endif
