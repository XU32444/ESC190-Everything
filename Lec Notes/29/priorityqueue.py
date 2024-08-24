# Insert("ESC195",5)
# Insert("CIV102",10)
# Insert("ESC190",0)

# pop() // ESC190
# pop() // ESC195
# pop() // CIV102

# [("ESC190",0),("ESC195",5),("CIV102",10)]
# keep the list sorted by priority
# More convenient: [(0,'ESC190'),(5,'ESC195'),(10,'CIV102')]
# pop: remove the first item and return the value

class PriorityQueue:
    def __init__(self):
        self.queue = []

    def insert(self, value, priority):
        self.queue.append((priority, value))
        self.queue.sort()

    def pop(self):
        return self.queue.pop(0)[1]
