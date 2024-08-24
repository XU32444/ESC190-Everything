alphabet = "abcdefghijklmn"

for letter1 in alphabet:
    for letter2 in alphabet:
        for letter3 in alphabet:
            for letter4 in alphabet:
                print(letter1 + letter2 + letter3 + letter4)
# it returns all the strings of length 4 in the list

# want to list all the strings of length k over the alphabet

for letter1 in alphabet:
    # use a helper function to get all completions
    # letter1 + {string of length k-1 over the alphabet}
    



def all_strings(k,alphabet):
    '''return a list of all strings of length k over the alphabet'''e
    if k == 0:
        return [""]

    res = []
    all_k1_strings = all_k1_strings(k-1,alphabet)
    for letter in alphabet:
        # add
        # letter1 + {string of length k-1 over the alphabet}
        all_k1_strings = all_strings(k-1,alphabet)
        for string in all_k1_strings:
            res.append(letter + string) # the string if of length k-1   
            