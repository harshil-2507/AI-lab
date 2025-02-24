from pyswip import Prolog


prolog = Prolog()

prolog.assertz("human(socrates)")

prolog.assertz("mortal(X) :- human(X)")  


query = "mortal(socrates)"
result = list(prolog.query(query))


if result:
    print(f"{query} is proven")
else:
    print(f"{query} is not proven")
