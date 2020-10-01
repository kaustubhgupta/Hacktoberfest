import random
movies = ('LAGAAN', 'HIGHWAY', 'THOR', 'DANGAL', 'NEWTON','ANEK','APNE','CHHICHHORE','WAR','GULAAL','DHOOM','MALANG', 'STAR WARS') #movies_name_that_you_will_get_to_play
c_m = random.sample(movies,1)    #one movie is selected by random library
k = '*' * len(c_m[0])
print(k) #output movie name in stars


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

print(f'Score = {score}')                              #prints the starting score

while score > 0 and '*' in k:
    letter = input("Guess a letter:").capitalize()     #capitalizes the user input
    if letter in lap.keys():                           # checks if the letter is present in the movie name  
        n = lap[letter]  
        for p in n:
            k = k[:p]+letter+k[p+1:]
        score = score+3                                #increases the points ofg the player
        print('correct guess')
        print(k)
        print(f' Score= {score}')
        lap.pop(letter)
#correct guess adds three points

    else:                                               #deducts the points if the letter is not present in movie name
        score = score-2
        print('incorrect guess')
        print(k)
        print(f'Score={score}')

if '*' not in k:
    print("YOU WON ")

else:
    print("YOU LOOSE")

print(f"The Answer was {c_m[0]}")                     #prints the correct answer
