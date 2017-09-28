
/* stephen moring */
#include "stack.h" 
#include <string>
using namespace std;
using namespace cop4530;

void EvaluatePost(string express);
bool isOperand(const char&);
bool isOperator(const char&);

int main()
{
	Stack<string> post;	//stack to aid in conversion
	string postfix;		// posfix expression
	string val;		// stores the next variable
	string infix;		//previously input
	int size;

	cout << "Enter infix expression(\"exit\" to quit): \n";	

	while (!cin.eof())
	{
		
	//reads in the input and operates accordingly based off if the cin.peek() is
	// an operand, an operatopr, or whitespace
	  do {

		if (cin.peek() == '(')	
		{
		  cin >> val;
		  post.push(val);
		  infix = val;
		}
		else if (cin.peek() == ' ')		
		{
		  cin.ignore();
		}

		//checks if next input is mult or div, has higher precedence than add and sub
		else if (cin.peek() == '*' || cin.peek() == '/')	
		{
		  cin >> val;
		  infix = val;
		
		  while(!val.empty())
			{
			  if (post.empty() || post.top() == "(" || post.top() == "-" || post.top() == "+")	
				{
				  post.push(val);
				  val.clear();
				}
			  else
				{
				  postfix += ' ';		
				  postfix.append(post.top());
				  post.pop();			
				}
			} 
		}
		else if (cin.peek() == '+' || cin.peek() == '-')	
		{
		  cin >> val;
		  infix = val;

		  while(!val.empty())
			{
			  if (post.empty() || post.top() == "(")
				{
				  post.push(val);
				  val.clear();
				}
				else
				{
				  postfix += ' ';		
				  postfix.append(post.top());
				  post.pop();
				}

			} 
		}
		else if (cin.peek() == ')')
		{
		  cin >> val;

		  if (isOperator(infix[0]))
			{
			  cout << "Error: Last input was an operator" << endl;
			}
			else
			{
			  if (post.top() != "(")
				{
				  while(post.top() != "(")
					{
					  postfix += ' ';		//keep popping until (
					  postfix.append(post.top());	
					  post.pop();
					} 

					  post.pop();
				}				
			  else
				post.pop();
			}

			  infix = val;
		}
		else if (isOperand(cin.peek()))	//if the next input is a number
		{
		  cin >> val;
		  infix = val;

		  if (postfix.empty())
			{
			  postfix = val;
			  if(postfix == "Exit" || postfix == "exit")
				{
				  exit(0);
				}		
			}
			else
			{
			  postfix += ' ';	
			  postfix.append(val);
			}
		}


		} while (cin.peek() != '\n');

		// deals with newline 
		getline(cin, val, '\n');
		val.clear();

		size = post.size();	

		if (!post.empty())
		{
		  for (int i = 0; i < size; i++)
			{
			  postfix += ' ';
			  postfix.append(post.top());
			  post.pop();
			}
		}
		
		if (!postfix.empty())
		{
		  cout << "Postfix Expression: " << postfix << endl;	
		}
		EvaluatePost(postfix);	

		cout << "Enter infix expression(\"exit\" to quit): \n";

		//clears variables for next expression
		val.clear();	
		infix.clear();
		postfix.clear();

		if (cin.peek() == 0)
			break;

	}
	return 0;
}

// checks if the incoming char from input is an operand
bool isOperand(const char& x)
{
	if ( x >= 48 && x <= 57 || x >= 'A' && x <= 'z')
		return true;

	return false;
}

//checks if the incoming char from input is an operator
bool isOperator(const char& x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return true;

	return false;
}



// takes a postfix expression and solves it by manpulating stacks to 
//  
void EvaluatePost(string postfix)	//evaluating the postfix sequence
{

	// checks if there are any variables in the expession, so it doesnt get evaluated
	cout << "Postfix Evaluation: " << postfix << " = ";
	for (unsigned int i = 0; i < postfix.size(); i++)	
	{
	  if (postfix[i] >= 'A' && postfix[i] <= 'z')
		{
		  cout << postfix << endl;	
		  return;
		}
	}
					
	Stack<float> post;
	float y;
	float first;
	float second;
	string x;
	string k;
	

	for (unsigned int i = 0; i < postfix.size(); i++)
	{
	  if (isOperator(postfix[i]))		//pulls two operands off of the stack to evaluate them then pushes the result back onto the stack
		{
		  if (post.size() < 2)
			{
			  cout << "Error: not enough operands on stack. " << endl;
			}

		  first = post.top();	//pulls two operands off stack for evaluation then determines the mathematical operation
		  post.pop();
		  second = post.top();	
		  post.pop();
		  if (postfix[i] == '+')		
			post.push(first + second);
		  else if (postfix[i] == '-')	
			post.push(second - first);
		  else if (postfix[i] == '*')	
			post.push(first * second);	
		  else if (postfix[i] == '/')
			post.push(second / first);
		}
	  else if(isOperand(postfix[i]))
		{
		  for (int j = i; j < postfix.size(); j++) 
			{
			  if (postfix[j] == ' ')	
				break;
			  else if (postfix[j] == '.')	//decimals/floats
				{
				  k = postfix[i];
				  x.append(k);
				  i++;	
				}
			  else	
				{
				  k = postfix[i];
				  x.append(k);
				  i++;		 
				}
			}
		  y = stod(x);	//converts strings to doubles
		  x.clear();
		  post.push(y);	//pushes the operands onto the stack

		}
	else if(postfix[i] == ' ')
		{
			continue;
		}

	}

	if (post.size() > 1)
	{
	  cout << "Error: Stack has too many operands left" << endl;
	}
	else
		cout << post.top() << endl; // prints answer


};
