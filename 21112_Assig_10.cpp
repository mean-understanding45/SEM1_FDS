/*Implement C++ program for expression conversion as infix to postfix and its 
evaluation using stack based on given conditions:  
1. Operands and operator, both must be single character. 
2. Input Postfix expression must be in a desired format. 
3. Only '+', '-', '*' and '/ ' operators are expected. */

#include <iostream>
using namespace std;
#include <string>

template <class T>
class Stack
{

private:
    int size;
    int top;
    T *arr;

public:
    Stack()
    {
        size = 100;
        top = -1;
        arr = new T[size];
    }
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }

    int isempty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(T data)
    {
        if (isFull() == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    T pop()
    {
        if (isempty() == 1)
        {
            return -1;
        }

        char m = arr[top];
        top--;
        return m;
    }
    void display()
    {
        int i = top;
        while (i >= 0)
        {
            cout << arr[i] << endl;
            i--;
        }
    }

    char topEle()
    {
        return arr[top];
    }
};

class Expression
{
    string infix;
    char postfix[100];
    Stack<char> *sp = new Stack<char>();
    Stack<int> *sp2 = new Stack<int>();
    int j = 0;

public:
    void input()
    {
        cout << "Enter the expression : ";
        cin >> infix;
    }

    int precedence(char ch)
    {

        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        else if (ch == '+' || ch == '-')
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    bool isOperator(char ch)
    {

        if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void infixToPostfix()
    {

        int i = 0;

        while (i != infix.length())
        {

            if (!isOperator(infix[i]))
            {
                if (infix[i] == '(')
                {
                    sp->push('(');
                    i++;
                }
                else if (infix[i] == ')')
                {
                    while (sp->topEle() != '(' && sp->isempty() == 0)
                    {
                        postfix[j] = sp->pop();
                        j++;
                    }
                    sp->pop();
                    i++;
                }
                else
                {

                    postfix[j] = infix[i];
                    i++;
                    j++;
                }
            }
            else
            {
                if (precedence(infix[i]) > precedence(sp->topEle()))
                {
                    sp->push(infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = sp->pop();
                    j++;
                }
            }
        }
        while (!sp->isempty())
        {
            postfix[j] = sp->pop();
            j++;
        }
    }

    void display()
    {
        cout << postfix << endl;
    }

    int eval()
    {
        int i = 0;

        while (i < j)
        {

            if (!isOperator(postfix[i]))
            {
                int d = (int)postfix[i] - 48;

                sp2->push(d);
            }
            else
            {
                int a = (sp2->pop());
                int b = (sp2->pop());

                int result = 0;
                switch (postfix[i])
                {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = b / a;
                    break;
                default:
                    break;
                }

                sp2->push((result));
            }
            i++;
        }
        int final = sp2->pop();
        return final;
    }
};

int main()
{
    Expression exp;
    exp.input();
    exp.infixToPostfix();
    exp.display();
    cout << "Evaluation of the expression : ";
    cout << exp.eval();

    return 0;
}