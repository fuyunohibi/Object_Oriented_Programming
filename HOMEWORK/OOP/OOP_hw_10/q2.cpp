#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <ctype.h>
using namespace std;

// define the bitwise logical expression tree node
struct BitwiseLogicalNode
{
    char value;
    BitwiseLogicalNode *left;
    BitwiseLogicalNode *right;
};

// tokenize the input bitwise logical expression string
void tokenize(const string &expression, stack<string> &tokens)
{
    int i = 0;
    while (i < expression.length())
    {
        // ignore whitespaces
        if (isspace(expression[i]))
        {
            ++i;
            continue;
        }

        // parse the operator
        if (expression[i] == '~' || expression[i] == '&' || expression[i] == '|' || expression[i] == '^')
        {
            tokens.push(string(1, expression[i]));
            ++i;
            continue;
        }

        // parse the operand
        int j = i;
        while (j < expression.length() && isdigit(expression[j]))
        {
            ++j;
        }
        if (j > i)
        {
            tokens.push(expression.substr(i, j - i));
            i = j;
            continue;
        }

        // unexpected character
        throw invalid_argument("Unexpected character: " + string(1, expression[i]));
    }
}

// parse the bitwise logical expression tree from the tokens
BitwiseLogicalNode *parse(stack<string> &tokens)
{
    string token = tokens.top();
    tokens.pop();

    BitwiseLogicalNode *node;
    if (token == "~")
    {
        node = new BitwiseLogicalNode;
        node->value = '~';
        node->left = parse(tokens);
        node->right = NULL;
    }
    else if (token == "&" || token == "|" || token == "^")
    {
        node = new BitwiseLogicalNode;
        node->value = token[0];
        node->left = parse(tokens);
        node->right = parse(tokens);
    }
    else
    {
        node = new BitwiseLogicalNode;
        node->value = '0';
        for (char c : token)
        {
            node->value <<= 1;
            if (c == '1')
            {
                node->value |= 1;
            }
        }
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

// evaluate the bitwise logical expression tree
char evaluate(BitwiseLogicalNode *node)
{
    if (node->value == '~')
    {
        return ~evaluate(node->left);
    }
    else if (node->value == '&')
    {
        return evaluate(node->left) & evaluate(node->right);
    }
    else if (node->value == '|')
    {
        return evaluate(node->left) | evaluate(node->right);
    }
    else if (node->value == '^')
    {
        return evaluate(node->left) ^ evaluate(node->right);
    }
    else
    {
        return node->value;
    }
}

// evaluate the bitwise logical expression string
char evaluate_bitwise_logical_expression(const string &expression)
{
    stack<string> tokens;
    tokenize(expression, tokens);
    BitwiseLogicalNode *root = parse(tokens);
    char result = evaluate(root);
    delete root;
    return result;
}

// main function for testing
int main()
{
    // 1011|0101&1100^0110~1010
    string expression;
    cout << "============ Bitwise Logical Expression Evaluator ============" << endl;
    cout << "Enter a bitwise logical expression: ";
    cin >> expression;
    char result = evaluate_bitwise_logical_expression(expression);
    cout << "Result: " << bitset<8>(result) << endl;
    return 0;
}
