from pyswip import Prolog


prolog = Prolog()


prolog.assertz("mammal(tom)")
prolog.assertz("mammal(jerry)")
prolog.assertz("animal(tom)")
prolog.assertz("animal(jerry)")


prolog.assertz("has_fur(X) :- mammal(X)") 
prolog.assertz("alive(X) :- animal(X)")  

queries = ["has_fur(tom)", "has_fur(jerry)", "alive(tom)", "alive(jerry)"]


for query in queries:
    result = list(prolog.query(query))
    if result:
        print(f"{query} is proven")
    else:
        print(f"{query} is not proven")
