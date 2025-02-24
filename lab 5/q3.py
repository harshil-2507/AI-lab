from pyswip import Prolog

prolog = Prolog()

prolog.assertz("loves(john, mary)")
prolog.assertz("loves(mary, john)")
prolog.assertz("kind(john)")

prolog.assertz("loves(X, everyone) :- kind(X)")
prolog.assertz("happy(X) :- loves(X, Y)")
prolog.assertz("smiles(X) :- happy(X)")
prolog.assertz("friendly(X) :- smiles(X)")
prolog.assertz("not(sad(X)) :- friendly(X)")
prolog.assertz("not(happy(X)) :- sad(X)")


query = "happy(john)"


result = list(prolog.query(query))


if result:
    print(f"{query} is proven")
else:
    print(f"{query} is not proven")