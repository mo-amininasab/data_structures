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
      out << obj.stack_ptr[i] << "  ";
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

  bool is_empty() const { return (top == -1); }
  bool is_full() const { return top == capacity - 1; }

 private:
  // ! assuming top is index of top reserved cell.
  int top;
  int capacity;
  T* stack_ptr;
};

Stack<char> infix_to_postfix(const char* expression) {
  int length = strlen(expression);
  Stack<char> operators(length);
  Stack<char> result(length + 10);

  for (int i = 0; i < length; i++) {
    // cout << expression[i];
    switch (expression[i]) {
      case '(':
        operators.push(expression[i]);
        break;
      case ')':
        /* code */
        break;
      case '^':
        while (operators.peak() == '^') {
          char a = operators.pop();
          result.push(a);
        }
        operators.push(expression[i]);
        break;
      case '*':
        while (operators.peak() == '^' || operators.peak() == '*' ||
               operators.peak() == '/') {
          char a = operators.pop();
          result.push(a);
        }
        operators.push(expression[i]);
        break;
      case '/':
        while (operators.peak() == '^' || operators.peak() == '*' ||
               operators.peak() == '/') {
          char a = operators.pop();
          result.push(a);
        }
        operators.push(expression[i]);
        break;
      case '+':
        while (operators.peak() == '^' || operators.peak() == '*' ||
               operators.peak() == '/' || operators.peak() == '-' ||
               operators.peak() == '+') {
          char a = operators.pop();
          result.push(a);
        }
        operators.push(expression[i]);
        break;
      case '-':
        while (operators.peak() == '^' || operators.peak() == '*' ||
               operators.peak() == '/' || operators.peak() == '-' ||
               operators.peak() == '+') {
          char a = operators.pop();
          result.push(a);
        }
        operators.push(expression[i]);
        break;

      default:
        result.push(expression[i]);
        break;
    }
  }

  while (!operators.is_empty()) {
    char a = operators.pop();
    result.push(a);
  }
  return result;
}

int main() {
  // char* b = "hello world";
  // cout << strlen(b);
  cout << infix_to_postfix("a^b*d+f/g");
}