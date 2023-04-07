#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Expression
{
public:
    virtual string repr() = 0;
    virtual double calculate() = 0;
};

class Number : public Expression
{
public:
    Number(double value) : value(value) {}
    string repr() { return to_string(value); }
    double calculate() { return value; }

private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression *left, Expression *right) : left(left), right(right) {}
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

protected:
    Expression *left;
    Expression *right;
};

class Addition : public BinaryOperation
{
public:
    Addition(Expression *left, Expression *right) : BinaryOperation(left, right) {}
    string repr() { return "(" + left->repr() + " + " + right->repr() + ")"; }
    double calculate() { return left->calculate() + right->calculate(); }
};

class Subtraction : public BinaryOperation
{
public:
    Subtraction(Expression *left, Expression *right) : BinaryOperation(left, right) {}
    string repr() { return "(" + left->repr() + " - " + right->repr() + ")"; }
    double calculate() { return left->calculate() - right->calculate(); }
};

class Multiplication : public BinaryOperation
{
public:
    Multiplication(Expression *left, Expression *right) : BinaryOperation(left, right) {}
    string repr() { return "(" + left->repr() + " * " + right->repr() + ")"; }
    double calculate() { return left->calculate() * right->calculate(); }
};

class Division : public BinaryOperation
{
public:
    Division(Expression *left, Expression *right) : BinaryOperation(left, right) {}
    string repr() { return "(" + left->repr() + " / " + right->repr() + ")"; }
    double calculate() { return left->calculate() / right->calculate(); }
};

int main()
{
    double a, b, c;
    int choice;

    cout << "Please choose an expression:\n"
         << "1. a + b\n"
         << "2. a - b\n"
         << "3. a * b\n"
         << "4. a / b\n";
    cin >> choice;

    cout << "Please enter the value of a: ";
    cin >> a;
    cout << "Please enter the value of b: ";
    cin >> b;

    Expression *expression;

    switch (choice)
    {
    case 1:
        expression = new Addition(new Number(a), new Number(b));
        break;
    case 2:
        expression = new Subtraction(new Number(a), new Number(b));
        break;
    case 3:
        expression = new Multiplication(new Number(a), new Number(b));
        break;
    case 4:
        cout << "Please enter the value of c: ";
        cin >> c;
        expression = new Division(new Multiplication(new Number(a), new Number(b)), new Number(c));
        break;
    default:
        cout << "Invalid choice." << endl;
        return 0;
    }

    cout << expression->repr() << " = " << expression->calculate() << endl;

    delete expression;

    return 0;
}
