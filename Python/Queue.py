# %%
# ************************************
# *  Name: Mohammad Amini Nasab      *
# *  Student No.: 39911541054532     *
# ************************************

class Queue:
  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def enqueue(self, item):
    self.items.insert(0, item)

  def dequeue(self):
    if self.isEmpty():
      return None
    return self.items.pop()

  def size(self):
    return len(self.items)

  def __str__(self):
    return str(self.items)
