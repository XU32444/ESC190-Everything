class stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, element):
        self.stack.append(element)

    def pop(self):
        if self.is_empty():
            print("Cannot pop frm an empty stack")
        else:
            return self.stack.pop()


s = stack()
s.stack  # []

s.push(52)
s.push(122)
print(s.stack)
print(s.pop())
print(s.stack)
