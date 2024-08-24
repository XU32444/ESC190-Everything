import numpy as np
N = 6

houses = [[7, 6, 7, 8, 9, 20],
          [3, 8, 9, 22, 12, 8],
          [16, 10, 4, 2, 5, 7]]

cost = [[0]*N,
        [0]*N,
        [0]*N]

# cost[0][j] is R[j+1]
# cost[1][j] is G[j+1]
# cost[2][j] is B[j+1]

# fibonacci dynamic programing

cost[0][0] = houses[0][0]  # R(1)
cost[1][0] = houses[1][0]  # G(1)
cost[2][0] = houses[2][0]  # B(1)

# R(k) = cost(k,"red") +  //the cost of painting house k red
#       min(G(k-1),B(k-1)) //the minimum cost of painting the previous house green or blue
#                          either paint k-1 green or blue, whichever is associated with the minimum cost
#                          with the smaller total cost

# cost[0][k-1] = houses[0][k-1] + min(cost[1][k-2],cost[2][k-2])
# cost[1][k-1] = houses[1][k-1] + min(cost[0][k-2],cost[2][k-2])
# cost[2][k-1] = houses[2][k-1] + min(cost[0][k-2],cost[1][k-2])

for k in range(1, N):
    # the min cost to paint the first i hourses, with the i-th being painted red
    cost[0][k] = houses[0][k] + min(cost[1][k-1], cost[2][k-1])
    # the mi cots to paint the first i hourses, with the i-th being painted green
    cost[1][k] = houses[1][k] + min(cost[0][k-1], cost[2][k-1])
    # the min cost to paint the first i houses, with the i-th being painted blue
    cost[2][k] = houses[2][k] + min(cost[0][k-1], cost[1][k-1])

min(cost[0][5], cost[1][5], cost[2][5])  # the minimal cost of painting
# the first 6 houses

np.argmin([cost[0][5], cost[1][5], cost[2][5]])  # the color of the last house
# that was painted to achieve
# the minimal cost

# the color of ourse number 5 (starting from 0)  is np.argmin([cost[0][5],cost[1][5],cost[2][5]])
# if I know that hourse umber 5 is color 1,
# house number 4 will be np.argmin([cost[0][4],cost[2][4]]) if I know that house 5 is color 1


cols = [0]*N
i = N-1
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= cost[2][N-1]:
    cols[N-1] = 1
else:
    cols[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = 100000
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col


def print_house_cast(houses, cols, i):
    '''return the cost of painting houses with the given colors'''
    if i == 0:
        return houses[col][i]
    cur_min = sum(sum(cost) for cost in houses)
    for col in [0, 1, 2]:
        if col == cols[i]:
            continue
        cur_min = min(cur_min, print_house_cast(
            houses, cols, i-1) + houses[col][i])
    for i in range(N):
        print(houses[cols[i]][i], end=" ")
    print()

# analogy to scheduling
# A couse cannot have two assessmennts, scheudle in the sme week
# Instructors
