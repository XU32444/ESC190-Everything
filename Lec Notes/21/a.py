def fib(n):
    if n in[0,1]:
        return 1
    return fib(n-1) + fib(n-2)

# memoization cuz fib(10) computes fib(5) multiple times
# store the result of a function call every time it happens
# O(n) additions bcause every Fibonacci nummber is 
# fib(n) ~ phi^n/squrt5
# the number of digits in fib(n) is log(fib(n)) = n log(phi) - log(5)/2
# The amount of space needed to store fib(1)..fib(n)
# log(phi) * (1 + 2 + 3+...+ n ) - n log(5)/2 is O(n^2)
# (1 + 2 + 3 + .... n) = n(n+1)/2
# (if we store in a list rahter than a dictionary)


def new_fib(n,fib_dict[]):
    if n in [0,1]:
        return 1
    if n in fib_dict:
        return fib_dict[n]
    else:
        fib_dict[n] = new_fib(n-1,fib_dict) + new_fib(n-2,fib_dict)
    if n not in fib_dict:
        fib_dict[n] = new_fib(n-1,fib_dict) + new_fib(n-2,fib_dict)
    return fib_dict[n]

# now you only compute every fibonacci number once
#   fib(1) fib(0)
#     \   /
#     fib(2)
#      \
#      fib(3)     fib(2)   fib(1)
#         \           \   /
#         fib(4)      fib(3)
#             \       /
#             fib(5)

# shape of the tree
# Full branch always going to left, of size n
# Branching out to the branches to the rigt, 1 step everytime
# Total: 2n calls
# O(n) calls

# If counting number of additions, complexity is O(n) additins
# IF we are counting operations, need to account for the fact that
# addition tkae O(k) time where k is number of digits in the larger number


