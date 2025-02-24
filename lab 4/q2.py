def backward_chaining(kb, goal, inferred=None):
    if inferred is None:
        inferred = set()
    if goal in kb["facts"]:
        return True
    for premises, conclusion in kb["rules"]:
        if conclusion == goal and goal not in inferred:
            inferred.add(goal)
            if all(backward_chaining(kb, premise, inferred) for premise in premises):
                return True
    return False

kb3 = {
    "facts": {"A", "B"},
    "rules": [
        ({"P"}, "Q"),
        ({"R"}, "Q"),
        ({"A"}, "P"),
        ({"B"}, "R"),
    ]
}
goal3 = "Q"
print("Backward Chaining Result (2a):", backward_chaining(kb3, goal3))

kb4 = {
    "facts": {"A", "E"},
    "rules": [
        ({"A"}, "B"),
        ({"B", "C"}, "D"),
        ({"E"}, "C"),
    ]
}
goal4 = "D"
print("Backward Chaining Result (2b):", backward_chaining(kb4, goal4))