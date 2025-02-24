from itertools import product

class Symbol:
    def __init__(self, name): 
        self.name = name

    def __repr__(self):  
        return self.name

def NOT(value):
    return not value

def AND(value1, value2):
    return value1 and value2

def OR(value1, value2):
    return value1 or value2

def IMPLIES(value1, value2):  
    return not value1 or value2

def EQUIVALENT(value1, value2):  
    return value1 == value2

def print_truth_table(symbols, operation_name, operation):
    print(f"\n{' '.join([s.name for s in symbols])} {operation_name}")
    print("-" * (4 * len(symbols) + len(operation_name) + 2))
    for values in product([False, True], repeat=len(symbols)):
        result = operation(*values)
        row = " ".join("T" if v else "F" for v in values)
        print(f"{row} {result and 'T' or 'F'}")

def evaluate_proposition(symbols, proposition):
    print("\nTruth Table for Proposition:", proposition.__name__)  # Fixed __name__ access
    print_truth_table(symbols, proposition.__name__, proposition)

def proposition_1(P, Q):
    return IMPLIES(NOT(P), Q)

def proposition_2(P, Q):
    return AND(NOT(P), NOT(Q))

def proposition_3(P, Q):
    return OR(NOT(P), NOT(Q))

def proposition_4(P, Q):
    return IMPLIES(NOT(P), NOT(Q))

def proposition_5(P, Q):
    return EQUIVALENT(NOT(P), NOT(Q))

def proposition_6(P, Q):
    return AND(OR(P, Q), IMPLIES(NOT(P), Q))

def proposition_7(P, Q, R):
    return IMPLIES(OR(P, Q), NOT(R))

def proposition_8(P, Q, R):
    return EQUIVALENT(IMPLIES(OR(P, Q), NOT(R)), IMPLIES(AND(NOT(P), NOT(Q)), NOT(R)))

def proposition_9(P, Q, R):
    return IMPLIES(AND(IMPLIES(P, Q), IMPLIES(Q, R)), IMPLIES(Q, R))

def proposition_10(P, Q, R):
    return IMPLIES(IMPLIES(P, OR(Q, R)), AND(NOT(P), AND(NOT(Q), NOT(R))))

P = Symbol('P')
Q = Symbol('Q')
R = Symbol('R')

evaluate_proposition([P, Q], proposition_1)
evaluate_proposition([P, Q], proposition_2)
evaluate_proposition([P, Q], proposition_3)
evaluate_proposition([P, Q], proposition_4)
evaluate_proposition([P, Q], proposition_5)
evaluate_proposition([P, Q], proposition_6)
evaluate_proposition([P, Q, R], proposition_7)
evaluate_proposition([P, Q, R], proposition_8)
evaluate_proposition([P, Q, R], proposition_9)
evaluate_proposition([P, Q, R], proposition_10)
