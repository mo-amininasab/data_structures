// ************************************
// *  Name: Mohammad Amini Nasab      *
// *  Student No.: 39911541054532     *
// ************************************

#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;

template <class T>
class Stack {
  friend ostream& operator<<(ostream& out, const Stack& obj) {
    if (obj.is_full()) {
      out << "Stack is FULL" << endl;
    } else if (obj.is_empty()) {
      out << "Stack is EMPTY" << endl;
    }

    for (int i = 0; i <= obj.top; i++) {
      out << obj.stack_ptr[i] << "";
    }

    return out;
  }

 public:
  Stack(int _capacity = 10) {
    top = -1;
    capacity = (_capacity > 0) ? _capacity : 10;

    stack_ptr = new T[capacity];
  }
  ~Stack() { delete[] stack_ptr; }

  const Stack& operator=(const Stack& stk) {
    if (this != &stk) {
      delete[] stack_ptr;
      top = stk.top;
      capacity = stk.capacity;
      stack_ptr = new T[capacity];
      for (int i = 0; i <= top; i++) {
        stack_ptr[i] = stk.stack_ptr[i];
      }
    }
    return *this;
  }

  bool push(const T& item) {
    if (is_full()) {
      return false;
    }
    stack_ptr[++top] = item;

    return true;
  }

  T pop() {
    if (is_empty()) {
      return false;
    }
    return stack_ptr[top--];
  }

  T peak() {
    if (is_empty()) {
      return false;
    }

    return stack_ptr[top];
  }

  char* to_string() {
    if (is_empty()) {
      return nullptr;
    }

    char* str = new char[top + 1];
    for (int i = 0; i <= top; i++) str[i] = stack_ptr[i];

    str[top + 1] = '\0';
    return str;
  }

  bool is_empty() const { return (top == -1); }
  bool is_full() const { return top == capacity - 1; }

 private:
  // ! assuming top is index of top reserved cell.
  int top;
  int capacity;
  T* stack_ptr;
};

int prec(char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}

bool is_operand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool is_digit(char ch) { return (ch >= '0' && ch <= '9'); }

Stack<char> infix_to_postfix(const char* expression) {
  int length = strlen(expression);
  Stack<char> operators(length);
  Stack<char> result(length + 5);  // +5 just to be safe

  for (int i = 0; i < length; i++) {
    if (is_operand(expression[i]) || is_digit(expression[i])) {  // if operand
      result.push(expression[i]);

    } else if (expression[i] == '(') {
      operators.push(expression[i]);

    } else if (expression[i] == ')') {
      while (!operators.is_empty() && operators.peak() != '(') {
        result.push(operators.pop());
      }

      operators.pop();  // pop '('

    } else {  // if operator
      while (!operators.is_empty() &&
             prec(expression[i]) <= prec(operators.peak())) {
        result.push(operators.pop());
      }

      operators.push(expression[i]);
    }
  }
  // pop all remaining operators
  while (!operators.is_empty()) {
    result.push(operators.pop());
  }

  return result;
}

float evaluate(const char* expression) {
  int length = strlen(expression);
  Stack<float> stk(length);

  for (int i = 0; i < length; i++) {
    if (is_digit(expression[i])) {  // if digit
      stk.push(expression[i] - '0');
    } else {  // if operator
      float b = stk.pop();
      float a = stk.pop();
      switch (expression[i]) {
        case '+':
          stk.push(a + b);
          break;

        case '-':
          stk.push(a - b);
          break;

        case '*':
          stk.push(a * b);
          break;

        case '/':
          stk.push(a / b);
          break;

        case '^':
          stk.push(pow(a, b));
          break;
      }
    }
  }

  return stk.pop();
}

int main() {
  char* expression1 = "(1+2)*(3+4)";
  Stack<char> postfix1 = infix_to_postfix(expression1);
  cout << expression1 << "  --->  " << postfix1 << "  --->  "
       << evaluate(postfix1.to_string()) << endl
       << endl;

  char* expression2 = "3+5*(8-2)";
  Stack<char> postfix2 = infix_to_postfix(expression2);
  cout << expression2 << "  --->  " << postfix2 << "  --->  "
       << evaluate(postfix2.to_string()) << endl
       << endl;

  char* expression3 = "1+(2*3^4)^(5-6)/7";
  Stack<char> postfix3 = infix_to_postfix(expression3);
  cout << expression3 << "  --->  " << postfix3 << "  --->  "
       << evaluate(postfix3.to_string()) << endl
       << endl;

  char* expression4 = "2^(1+2)-0+4*5";
  Stack<char> postfix4 = infix_to_postfix(expression4);
  cout << expression4 << "  --->  " << postfix4 << "  --->  "
       << evaluate(postfix4.to_string()) << endl
       << endl;

  char* expression5 = "1+2^3*4";
  Stack<char> postfix5 = infix_to_postfix(expression5);
  cout << expression5 << "  --->  " << postfix5 << "  --->  "
       << evaluate(postfix5.to_string()) << endl
       << endl;

  char* expression6 = "1+2/(3*4+5)-6^2";
  Stack<char> postfix6 = infix_to_postfix(expression6);
  cout << expression6 << "  --->  " << postfix6 << "  --->  "
       << evaluate(postfix6.to_string()) << endl
       << endl;

  char* expression7 = "(1+2)+(3*4^(5-2/(3^2)))";
  Stack<char> postfix7 = infix_to_postfix(expression7);
  cout << expression7 << "  --->  " << postfix7 << "  --->  "
       << evaluate(postfix7.to_string()) << endl
       << endl;

  return 0;
}