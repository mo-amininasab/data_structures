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


class Node:
  def __init__(self, data):
    self.data = data
    self.next = None


class Stack_in_linked_list:
  def __init__(self, data):
    new_node = Node(data)
    self.top = new_node
    self.length = 1

  def push(self, data):
    new_node = Node(data)

    if self.top == None:
      self.top = new_node

    else:
      new_node.next = self.top
      self.top = new_node

    self.length += 1

  def pop(self):
    if self.top == None:
      return None

    temp = self.top
    self.top = self.top.next
    temp.next = None

    self.length -= 1
    return temp

  def __str__(self):
    string = ""
    temp = self.top
    while temp:
      string += str(temp.data) + " "
      temp = temp.next

    if string == "":
      return "Empty Stack"
    return string


my_stack = Stack_in_linked_list(4)
my_stack.push(5)
my_stack.push(6)
print(my_stack)
my_stack.pop()
print(my_stack)
