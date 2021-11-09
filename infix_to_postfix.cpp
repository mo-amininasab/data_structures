#include <string>
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
  // Stack(const Stack& obj) {
  //   top = obj.top;
  //   capacity = obj.capacity;

  //   stack_ptr = new T[capacity];
  //   while (!is_empty()) {
  //     obj.push(obj.pop());
  //   }
  //   }
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

  // Stack operator+(const Stack& stk) {
  //   Stack temp(capacity + stk.capacity);
  //   for (int i = 0; i <= top; i++) {
  //     temp.stack_ptr[i] = stack_ptr[i];
  //   }

  //   for (int i = 0; i <= stk.top; i++) {
  //     temp.stack_ptr[i + top + 1] = stk.stack_ptr[i];
  //   }
  //   // while (!is_empty()) {
  //   //   temp.push(pop());
  //   // }
  //   // while (!stk.is_empty()) {
  //   //   temp.push(stk.pop());
  //   // }
  //   return temp;
  // }

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

  string get_str() const {
    string str = "";
    for (int i = 0; i <= top; i++) {
      char item = stack_ptr[i];
      if (item == NULL) {
        break;
      }
      str += item;
    }
    return str;
  }

  int get_size() const { return top; }

  bool is_empty() const { return (top == -1); }
  bool is_full() const { return top == capacity - 1; }

 private:
  // ! assuming top is index of top reserved cell.
  int top;
  int capacity;
  T* stack_ptr;
};

Stack<char> infix_to_postfix(const string expression) {
  int length = expression.length();
  Stack<char> operators(length);
  Stack<char> result(length + 10);

  for (int i = 0; i < length; i++) {
    switch (expression[i]) {
      case '(':

        {
          // Stack<char> temp(length - i - 1);
          Stack<char> temp(10);
          // cout << "SUBSTR: " << expression.substr(i + 1, length) << endl;
          temp = infix_to_postfix(expression.substr(i + 1, length));
          // cout << "TEMP STR: " << temp.get_str() << ";;;" << endl;
          // cout << "TEMP STR: " << result.get_str() << ";;;" << endl;
          string str = temp.get_str();
          for (int j = 0; j < str.length(); j++) {
            result.push(str[j]);
          }
          i = result.get_size() + i + 2;
          // cout << "TEMP SIZE: " << i << endl;
          // cout << "RESULT STR: " << result.get_str() << ";;;" << endl;
          // cout << "RESULT LENGTH: " << result.get_size() << ";;;" << endl;
          // cout << "str LENGTH: " << str.length() << ";;;" << endl;
          // cout << "str : " << str << ";;;" << endl;
          // cout << "EXPRESSION: " << expression << endl;
          // cout << "i: " << i << endl;
          // cout << "EXPRESSION[i]: " << expression[i] << endl;
          // cout << "EXPRESSION: " << expression << endl;

        // operators.push(expression[i]);
        // cout << "Test--------" << endl;
        // cout << expression.substr(i + 1, length) << endl;
        // cout << endl << "Test--------" << endl;
        break;}
      case ')':
      // cout << "------------------------------------" << endl;
      // cout << "EXPRESSION: " << expression;
  

      while(!operators.is_empty()) {
        char a = operators.pop();
        result.push(a);
      }
      //   cout << endl << "RESULT: " << result ;
      // cout << endl << "------------------------------------" << endl;
        
        return result;
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
  cout << infix_to_postfix("a+(b*c^d)^(e-f)/g");
}