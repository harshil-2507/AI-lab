from collections import deque

def forward_chaining(KB, query):
    inferred = set()
    agenda = deque()
    rules = []
    
   
    for statement in KB:
        if '→' in statement:
            premise, conclusion = statement.split('→')
            premise = tuple(premise.strip().split('∧'))
            rules.append((premise, conclusion.strip()))
        else:
            inferred.add(statement.strip())
            agenda.append(statement.strip())
    
    while agenda:
        fact = agenda.popleft()
        if fact == query:
            return True  
        
        new_facts = []
        for premise, conclusion in rules:
            if all(p in inferred for p in premise):
                if conclusion not in inferred:
                    new_facts.append(conclusion)
        
        for new_fact in new_facts:
            inferred.add(new_fact)
            agenda.append(new_fact)
    
    return False 


KB1 = ["P → Q", "L ∧ M → P", "A ∧ B → L", "A", "B", "M"]
query1 = "Q"
print("Query Q is derived:", forward_chaining(KB1, query1))

KB2 = ["A → B", "B → C", "C → D", "E", "D ∧ E → F"]
query2 = "F"
print("Query F is derived:", forward_chaining(KB2, query2))
