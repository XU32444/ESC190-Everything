

# deep copy of arbtiaury lists

# want to create a deep copy of the list L, not knowing it's structure ahead of time
# If I can crate deep copies of simple lists, can I create deep copies of arbitary lists?

# to create deep copy of the lits L
# make a new list [deepcopy(L[0]),deepcopy(L[1]),...]


def deepcopy(L):
    '''Return a deep copy of L, which is either a list or an int'''
    if type(L) != list:
        return L
    res = []
    for e in L:
        if type(e) == list:
            res.append(deepcopy(e))
        else:
            res.append(e)
    return L


L = [[[1, 2], 5]]
# shallow copyof L:
L2 = L[:]  # L2 = L.copy() is the same

# shallow copy menas that L nad L2 are seperate lists,
# but the elements are aliases

# changing L[0] isnt the same as changing L2[0]
# changing L[0] is the smae as changing the contents of L2[0]
# => L2[0][0] = 3, changes L2[0][0] to 3
