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
    out << endl;

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
    char* str = new char[capacity];
    
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
  Stack<char> stk(length);

  for (int i = 0; i < length; i++) {
    switch (expression[i]) {
      case '+': {
        int b = stk.pop();
        int a = stk.pop();
        stk.push(a + b);
        break;
      }
      case '-': {
        int b = stk.pop();
        int a = stk.pop();
        stk.push(a - b);
        break;
      }
      case '*': {
        int b = stk.pop();
        int a = stk.pop();
        stk.push(a * b);
        break;
      }
      case '/': {
        int b = stk.pop();
        int a = stk.pop();
        stk.push(a / b);
        break;
      }
      case '^': {
        int b = stk.pop();
        int a = stk.pop();
        stk.push(pow(a, b));
        break;
      }
      default:
        stk.push(expression[i] - '0');
        break;
    }
  }

  return stk.pop();
}

int main() {
  string expression1 = "(1+2)*(3+4)";
  cout << expression1 << "  --->  ";
  cout << infix_to_postfix("(1+2)*(3+4)") << endl;
  cout << infix_to_postfix("(1+2)*(3+4)").to_string() << endl;
  // cout << evaluate("12+34+*") << endl;
  // cout << ('1' - '0') + ('2' - '0') << endl;

  // string expression2 = "1+(2*3^4)^(5-6)/7";
  // cout << expression2 << "  --->  ";
  // cout << infix_to_postfix("1+(2*3^4)^(5-6)/7") << endl;

  // string expression3 = "a^(b+c)-a/d*e";
  // cout << expression3 << "  --->  ";
  // cout << infix_to_postfix("a^(b+c)-a/d*e") << endl;

  // string expression4 = "a+b^c*d";
  // cout << expression4 << "  --->  ";
  // cout << infix_to_postfix("a+b^c*d") << endl;

  // string expression5 = "a+b/(c*d+e)-f^g";
  // cout << expression5 << "  --->  ";
  // cout << infix_to_postfix("a+b/(c*d+e)-f^g") << endl;

  // string expression6 = "(a+b)+(c*d^(e-f/(g^h)))";
  // cout << expression6 << "  --->  ";
  // cout << infix_to_postfix("(a+b)+(c*d^(e-f/(g^h)))") << endl;

  // cout << '3' - '0';

  return 0;
}