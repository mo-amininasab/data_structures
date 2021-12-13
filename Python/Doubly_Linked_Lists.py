# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************


class Node:
  def __init__(self, data):
    self.data = data
    self.next = None
    self.prev = None


class DoublyLinkedList:
  def __init__(self, data):
    new_node = Node(data)
    self.head = new_node
    self.tail = new_node
    self.length = 1

  def append(self, data):
    new_node = Node(data)

    if self.length == 0:
      self.head = new_node
      self.tail = new_node
    else:
      new_node.prev = self.tail
      self.tail.next = new_node
      self.tail = new_node

    self.length += 1
    return True

  def prepend(self, data):
    new_node = Node(data)

    if self.length == 0:
      self.head = new_node
      self.tail = new_node
    else:
      new_node.next = self.head
      self.head.prev = new_node
      self.head = new_node

    self.length += 1
    return True

  def pop(self):
    if self.length == 0:
      return None

    temp = self.tail

    if self.length == 1:
      self.head = None
      self.tail = None
    else:
      self.tail = temp.prev
      self.tail.next = None
      temp.prev = None

    self.length -= 1
    return temp

  def pop_first(self):
    if self.length == 0:
      return None

    temp = self.head

    if self.length == 1:
      self.head = None
      self.tail = None
    else:
      self.head = self.head.next
      self.head.prev = None
      temp.next = None

    self.length -= 1
    return temp

  def get(self, index):
    if index < 0 or index >= self.length:
      return None

    temp = self.head
    if index < self.length // 2:
      for _ in range(index):
        temp = temp.next
    else:
      temp = self.tail
      for _ in range(self.length - 1, index, -1):
        temp = temp.prev

    return temp

  def set_value(self, index, data):
    temp = self.get(index)
    if temp:
      temp.data = data
      return True

    return False

  def insert(self, index, data):
    if index < 0 or index > self.length:
      return False
    if index == 0:
      return self.prepend(data)
    if index == self.length:
      return self.append(data)

    new_node = Node(data)
    temp = self.get(index)

    new_node.next = temp
    new_node.prev = temp.prev
    temp.prev.next = new_node
    temp.prev = new_node

    self.length += 1
    return True

  def remove(self, index):
    if index < 0 or index >= self.length:
      return None
    if index == 0:
      return self.pop_first()
    if index == self.length - 1:
      return self.pop()

    temp = self.get(index)
    
    temp.prev.next = temp.next
    temp.next.prev = temp.prev
    temp.prev = None
    temp.next = None

    self.length -= 1
    return temp

  def __str__(self):
    string = ""
    temp = self.head
    while temp:
      string += str(temp.data) + " "
      temp = temp.next

    if string == "":
      return "Empty"

    return string


test = DoublyLinkedList(12)
test.append(13)
test.append(14)
test.append(15)
test.append('hello')
print(test, test.length)
test.remove(2)
print(test, test.length)
