import random
movies = ('LAGAAN', 'HIGHWAY', 'THOR', 'DANGAL', 'NEWTON','ANEK','APNE','CHHICHHORE','WAR','GULAAL','DHOOM','MALANG', 'STAR WARS')
c_m = random.sample(movies,1)
k = '*' * len(c_m[0])
print(k)
lap = {}
for i in range(len(c_m[0])):
    if c_m[0][i] not in lap.keys():
        j = list()
        j.append(i)
        lap[c_m[0][i]] = j
    else:
        j = lap[c_m[0][i]]
        j.append(i)
        lap[c_m[0][i]] = j
score = 10
print(f'Score = {score}')
while score > 0 and '*' in k:
    letter = input("Guess a letter:").capitalize()
    if letter in lap.keys():
        n = lap[letter]
        for p in n:
            k = k[:p]+letter+k[p+1:]
        score = score+3
        print('correct guess')
        print(k)
        print(f' Score= {score}')
        lap.pop(letter)


    else:
        score = score-2
        print('incorrect guess')
        print(k)
        print(f'Score={score}')

if '*' not in k:
    print("YOU WON ")

else:
    print("YOU LOOSE")

print(f"The Answer was {c_m[0]}")
