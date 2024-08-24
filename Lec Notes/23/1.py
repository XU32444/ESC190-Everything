import numpy as np


def make_change(coin,  amt):
    # [inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]
    OPT = [np.inf] * (amt + 1)
    # OPT[v] = min(1 + OPT[v-c], for c in coins)
    OPT[0] = 0

    OPT[j] = min(1+OPT[j-c] for c in coin if j-c >= 0)

# Suppose that we know that thenumber of coins needed for c
# if OPT[v]

# To make llc, what coin should we definitely use?
# Which is the smallest?
# OPT[11-7]
# OPT[11-5] <= need to use a 5c coin
# OPT[11-1]

# To make 6c, what coin should we definitely use??
# OPT[6-7]
# OPT[6-5] <= can use 5c coin
# OPT[6-1] <= can use 1c coin

# To make 1c, what coin should we definitely use?
# OPT[1-7]
# OPT[1-5]
# OPT[1-1] <= can use 1c coin


make_change([1, 7, 5], 11)  # 3
