from random import randint
# LIMITES
n = 500
m = 10000000

with open("input.txt", "w") as file:
    file.write("2\n")
    file.write(f"{n} {m}\n")
    for i in range(1, n+1):
        file.write(f"{randint(1, 100000)} ")