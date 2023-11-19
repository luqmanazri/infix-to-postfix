#include <iostream>
#include <stack>
#include <string>
using namespace std;

class InfixToPostfix
{
    private:
        string infx;
        string pfx;
    public:
        InfixToPostfix() {}; //default constructor
        InfixToPostfix(string s) // constructor with parameters
        {
            infx = s;
        }
        ~InfixToPostfix() {}; //destructor

        void GetInfix() // stores the infix expression
        {
            cout << "Enter the infix expression: ";
            getline(cin,infx);
        }

        void showInfix() //output the infix expression
        {
            cout << "Infix Expression: " << infx << endl;
        }

        void showPostfix() //output the postfix expression
        {
            cout << "Postfix Expression: " << pfx << endl;
        }

        bool precedence(char op1, char op2) // Determines the precedence between two operators
        {
            if (op2 == '(' || op2 == ')')
                return false;
            if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
                return false;
            else
                return true;
        }

  void convertToPostfix() //converts the infix expression into a postfix expression
{
    stack<char> s;
    pfx = "";
    for (int i = 0; i < infx.length(); i++)
    {
        char sym = infx[i];
        if (infx[i] == ' ' || infx[i] == ',') continue;
        if (isalnum(sym))
        {
            // if sym is an operand, append sym to pfx.
            pfx += sym;
        }
        else if (sym == '(')
        {
            //if sym is (, push sym into the stack.
            s.push(sym);
        }
        else if (sym == ')')
        {
            // if sym is ), pop and append all the symbols from the stack until the most
            //recent left parenthesis. Pop and discard the left parenthesis.
            while (!s.empty() && s.top() != '(')
            {
                pfx += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            // Pop and append all the operator from the stack to pfx that are
            //above the most recent left parenthesis and have precedence greater
            //than or equal to sym.
            while (!s.empty() && s.top() != '(' && precedence(infx[i], s.top()))
            {
                pfx += s.top();
                s.pop();
            }
            //Push sym onto the stack.
            s.push(sym);
        }
    }
    // After processing infx, some operators might be left in the stack. Pop and append to
    //pfx everything from the stack.
    while (!s.empty())
    {
        pfx += s.top();
        s.pop();
    }
}

};

int main()
{
    InfixToPostfix Cpt; // object declaration
    Cpt.GetInfix(); // fucntion to get Infix Expression
    Cpt.showInfix(); // function to display Infix Expression
    Cpt.convertToPostfix(); //fucntion to Convert Infix to Postfix
    Cpt.showPostfix(); //fucntion to show Postfix expression
    return 0;
}


/*

A + B – C; 
(A + B) * C; 
(A + B) * (C – D);
A + (( B + C) * ( E – F ) – G ) / ( H- I); 
A + B * (C+D) – E / F * G + H;

*/



