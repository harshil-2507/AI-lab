from itertools import combinations

def resolve(clause1, clause2):
    """Attempt to resolve two clauses. If resolvable, return new clause; otherwise, return None."""
    new_clause = set()
    found = False
    for literal in clause1:
        if -literal in clause2:
            found = True
        else:
            new_clause.add(literal)
    for literal in clause2:
        if -literal not in clause1:
            new_clause.add(literal)
    return new_clause if found else None

def resolution(kb, conclusion):
    """Resolution refutation method"""
    clauses = [set(clause) for clause in kb]
    negated_goal = {-conclusion}  
    clauses.append(negated_goal)

    while True:
        new_clauses = set()
        for (c1, c2) in combinations(clauses, 2):
            resolvent = resolve(c1, c2)
            if resolvent is not None:
                if not resolvent:
                    return True  
                new_clauses.add(frozenset(resolvent))
        
        if new_clauses.issubset(set(map(frozenset, clauses))):
            return False  
        clauses.extend(list(new_clauses))

kb5 = [
    {1, 2},   
    {-1, 3},   
    {-2, 4},   
    {-3, 4},   
]
goal5 = 4  
print("Resolution Result (3a):", resolution(kb5, goal5))

kb6 = [
    {-1, 2},
    {-2, 3},
    {-4, -3}, 
    {1},     
]
goal6 = 4
print("Resolution Result (3b):", resolution(kb6, goal6))