#############################
# APS106 Winter 2024 - lab6 #
# Chemical Eqn Checker      #
#############################

######################################################
# PART 1 - Complete the function below to deocompose
#          a compound formula written as a string
#          in a dictionary
######################################################

def mol_form(compound_formula):
    """(str) -> dictionary
    When passed a string of the compound formula, returns a dictionary 
    with the elements as keys and the number of atoms of that element as values.
    """
    d = {}
    for s in compound_formula:
        if s.isupper():
            if s.next().islower():
                d[s + s.next()] = 1
            if s.next().isupper():
                d[s] = 1
            else:

                d[s] = 1
######################################################
# PART 2 - Complete the function below that takes two
#          tuples representing one side of a
#          chemical equation and returns a dictionary
#          with the elements as keys and the total
#          number of atoms in the entire expression
#          as values.
######################################################


def expr_form(expr_coeffs, expr_molecs):
    """
    (tuple (of ints), tuple (of dictionaries)) -> dictionary

    This function accepts two input tuples that represent a chemical expression,
    or one side of a chemical equation. The first tuple contains integers that
    represent the coefficients for molecules within the expression. The second
    tuple contains dictionaries that define these molecules. The molecule
    dictionaries have the form {'atomic symbol' : number of atoms}. The order
    of the coefficients correspond to the order of molecule dictionaries.
    The function creates and returns a dictionary containing all elements within
    the expression as keys and the corresponding number of atoms for each element
    within the expression as values.
    """

########################################################
# PART 3 - Check if two dictionaries representing
#          the type and number of atoms on two sides of
#          a chemical equation contain different
#          key-value pairs
########################################################


def find_unbalanced_atoms(reactant_atoms, product_atoms):
    """
    (Dict,Dict) -> Set

    Determine if reactant_atoms and product_atoms contain equal key-value
    pairs. The keys of both dictionaries are strings representing the 
    chemical abbreviation, the value is an integer representing the number
    of atoms of that element on one side of a chemical equation.

    Return a set containing all the elements that are not balanced between
    the two dictionaries.
    """

    # TODO your code here


########################################################
# PART 4 - Check if a chemical equation represented by
#          two nested tuples is balanced
########################################################

def check_eqn_balance(reactants, products):
    """
    (tuple,tuple) -> Set

    Check if a chemical equation is balanced. Return any unbalanced
    elements in a set.

    Both inputs are nested tuples. The first element of each tuple is a tuple
    containing the coefficients for molecules in the reactant or product expression.
    The second element is a tuple containing strings of the molecules within
    the reactant or product expression. The order of the coefficients corresponds
    to the order of the molecules. The function returns a set containing any
    elements that are unbalanced in the equation.

    For example, the following balanced equation
    C3H8 + 5O2 <-> 4H2O + 3CO2

    would be input as the following two tuples:
    reactants: ((1,5), ("C3H8","O2"))
    products: ((4,3), ("H2O","CO2"))
    """

    # TODO your code here
