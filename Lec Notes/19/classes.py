class student:
    def __init__(self, name, esc190mark):
        self.name = name
        self.esc190mark = esc190mark

    def print(self):
        print("Name:", self.name, "Mark:", self.esc190mark)


s = student("Jack", 98)
print(s.name)
s.print()
