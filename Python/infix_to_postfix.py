# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************

class Stack:
  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def push(self, item):
    self.items.append(item)

  def pop(self):
    if self.isEmpty():
      return None
    return self.items.pop()

  def peek(self):
    return self.items[len(self.items) - 1]

  def size(self):
    return len(self.items)

  def __str__(self) -> str:
    return str(self.items)


def precedence(op: str) -> (int):
  if op == '+' or op == '-':
    return 1
  elif op == '*' or op == '/':
    return 2
  elif op == '^':
    return 3
  else:
    return -1


def infix_to_postfix(infix_expr: str) -> (str):
  opStack = Stack()
  postfix_expr = ""

  for ch in infix_expr:
    if ch == '(':
      opStack.push(ch)
    elif ch == ')':
      top_ch = opStack.pop()
      while top_ch != '(':
        postfix_expr += top_ch
        top_ch = opStack.pop()
    elif ch in '+-*/^':
      while (not opStack.isEmpty()) and (precedence(opStack.peek()) >= precedence(ch)):
        postfix_expr += opStack.pop()
      opStack.push(ch)
    else:  # ch is an operand
      postfix_expr += ch

  while not opStack.isEmpty():
    postfix_expr += opStack.pop()

  return postfix_expr


def do_math(operand1: str, operand2: str, op: str) -> (float):
  if op == '+':
    return float(operand1 + operand2)
  elif op == '-':
    return float(operand1 - operand2)
  elif op == '*':
    return float(operand1 * operand2)
  elif op == '/':
    return float(operand1 / operand2)
  elif op == '^':
    return float(operand1 ** operand2)
  else:
    return None


def evaluate_postfix(postfix_expr: str) -> (float):
  opStack = Stack()

  for ch in postfix_expr:
    if ch in '0123456789':
      opStack.push(int(ch))
    else:
      operand2 = opStack.pop()
      operand1 = opStack.pop()
      result = do_math(operand1, operand2, ch)
      opStack.push(result)

  return opStack.pop()
