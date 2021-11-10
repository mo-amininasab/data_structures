// ************************************
// *  Name: Mohammad Amini Nasab      *
// *  Student No.: 39911541054532     *
// ************************************

#include <iostream>
#include <string>
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

  // string get_str() const {
  //   string str = "";
  //   for (int i = 0; i <= top; i++) {
  //     char item = stack_ptr[i];
  //     if (item == NULL) {
  //       break;
  //     }
  //     str += item;
  //   }
  //   return str;
  // }

  // int get_size() const { return top; }

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

Stack<char> infix_to_postfix(const string expression) {
  int length = expression.length();
  Stack<char> operators(length);
  Stack<char> result(length + 5); // +5 just to be safe.

  for (int i = 0; i < length; i++) {
    if (is_operand(expression[i])) {  // if operand
      result.push(expression[i]);

    } else if (expression[i] == '(') {
      operators.push(expression[i]);

    } else if (expression[i] == ')') {
      while (!operators.is_empty() && operators.peak() != '(') {
        result.push(operators.pop());
      }

      operators.pop();

    } else {  // if operator
      while (!operators.is_empty() &&
             prec(expression[i]) <= prec(operators.peak())) {
        result.push(operators.pop());
      }

      operators.push(expression[i]);
    }
  }
  // pop all the operators.
  while (!operators.is_empty()) {
    result.push(operators.pop());
  }

  return result;
}

int main() {
  string expression1 = "(a+b)*(c+d)";
  cout << expression1 << "  --->  ";
  cout << infix_to_postfix("(a+b)*(c+d)") << endl;

  string expression2 = "a+(b*c^d)^(e-f)/g";
  cout << expression2 << "  --->  ";
  cout << infix_to_postfix("a+(b*c^d)^(e-f)/g") << endl;

  string expression3 = "a^(b+c)-a/d*e";
  cout << expression3 << "  --->  ";
  cout << infix_to_postfix("a^(b+c)-a/d*e") << endl;

  string expression4 = "a+b^c*d";
  cout << expression4 << "  --->  ";
  cout << infix_to_postfix("a+b^c*d") << endl;

  string expression5 = "a+b/(c*d+e)-f^g";
  cout << expression5 << "  --->  ";
  cout << infix_to_postfix("a+b/(c*d+e)-f^g") << endl;

  return 0;
}