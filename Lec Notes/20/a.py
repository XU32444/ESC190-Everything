def f(x):
    print("Current augument:", x)
    print()

# acorn =


# usually use class
class AcornEntry:
    def __init__(self, course, mark):
        self.course = course
        self.mark = mark

    def __repr__(self):
        return f"The mark in {self.course} is {self.mark}"

    def __lt__(self, other):
        # return self.mark < other.mark
        if self.course < other.course:
            return True
        elif self.course == other.course:
            return self.mark < other.mark
        else:
            return False

        # return (self.course, self.mark) < (other.course, other.mark)

# want to sort AcornEntry by course, and then by mark
# ESC180 90
# ESC180 91
# ESC190 87
# ESC190 89


entries = [AcornEntry("ESC180", 90),
           AcornEntry("ESC190", 87),
           AcornEntry("ESC180", 100),
           AcornEntry("ESC190", 89)]

entries[0].__lt__(entries[1])  # same as entries[0] < entries[1]

entries.sort()
print(entries)  # defined less then... go from small to big(of the same type)
# function dand operator overloadig
# Defining how
# addition
# conversion to string
# comparison
# work for the custom class


# acorn_artsie = AcornEntry("CSC108", 100)
# acorn_engsci = AcornEntry("CSC180", 8)
# print(acorn_artsie)
