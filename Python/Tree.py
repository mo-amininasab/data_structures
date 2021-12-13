# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************


class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None


class BinarySearchTree:
  def __init__(self, data=None):
    new_node = Node(data)
    self.root = new_node

  def insert(self, data):
    new_node = Node(data)

    if self.root.data == None:
      self.root = new_node
      return True

    current = self.root
    while True:
      if new_node.data == current.data:
        return False

      if data < current.data:
        if current.left == None:
          current.left = new_node
          return True
        current = current.left
      elif data > current.data:
        if current.right == None:
          current.right = new_node
          return True
        current = current.right

  def contains(self, data):
    current = self.root
    while True:
      if data < current.data:
        if current.left == None:
          return False
        current = current.left
      elif data > current.data:
        if current.right == None:
          return False
        current = current.right
      else:
        return True


def main():
  my_tree = BinarySearchTree()
  my_tree.insert(2)
  my_tree.insert(1)
  my_tree.insert(3)

  print(my_tree.root.data)
  print(my_tree.root.left.data)
  print(my_tree.root.right.data)
  print(my_tree.contains(-2))


if __name__ == '__main__':
  main()
