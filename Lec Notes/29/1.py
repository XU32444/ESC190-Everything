# 0 1 3 4 6 ... 21
# 0 2 4 5 .... 21

def enum_all(prefix, score, path):
    # prefix: the game played so far
    # score: the current score
    # path: all the posssible games/ "paths" that were played
    if score >= 21:
        path.append(prefix)
        return
    enum_all(prefix + '1', score + 1, path)
    enum_all(prefix + '2', score + 2, path)


def enum_all_stack(prefix, score, path):
    # prefix: the game played so far
    # score: the current score
    # path: all the posssible games/ "paths" that were played
    stack = [(prefix, score)]
    # keep adding new games to the stack
    # Explore the next node from the stack
    while stack:
        prefix, score = stack.pop()
        if score >= 21:
            path.append(prefix)
            continue
        stack.append((prefix + '1', score + 1))
        stack.append((prefix + '2', score + 2))
        return path


print(enum_all_stack('', 0, []))
