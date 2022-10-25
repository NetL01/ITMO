class Box:
  def __init__ (self,cat = None):
    self.cat = cat
    self.nextbox = None

class LinkedList:
    def __init__(self):
        self.head = None

    def contains(self, cat):
        lastbox = self.head
        while lastbox:
          if cat == lastbox.cat:
            return True
          else:
            lastbox = lastbox.nextcat
        return False

    def addToEnd(self, newcat):
        newbox = Box(newcat)
        if self.head is None:
          self.head = newbox
          return
        lastbox = self.head
        while lastbox.nextcat:
            lastbox = lastbox.nextcat
        lastbox.nextcat = newbox

LinkedList.addToEnd(1, 1)
LinkedList.contains(0)