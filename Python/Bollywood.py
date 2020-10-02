import random
movies = ('LAGAAN', 'HIGHWAY', 'THOR', 'DANGAL', 'NEWTON','ANEK','APNE','CHHICHHORE','WAR','GULAAL','DHOOM','MALANG', 'STAR WARS') #movies_name_that_you_will_get_to_play
selected_movie = random.sample(movies,1)    #one movie is selected by random library
starred_movie = '*' * len(selected_movie[0])
print(starred_movie) #output movie name in stars


lap = {}                                         #assigning the stars values the letters of movie
for letter in range(len(selected_movie[0])):
    if selected_movie[0][letter] not in lap.keys():
        movie_name = list()
        movie_name.append(letter)
        lap[selected_movie[0][letter]] = movie_name
    else:
        movie_name = lap[selected_movie[0][letter]]
        movie_name.append(letter)
        lap[selected_movie[0][letter]] = movie_name
score = 10

print(f'Score = {score}')                              #prints the starting score

while score > 0 and '*' in starred_movie:
    letter = input("Guess a letter:").capitalize()     #capitalizes the user input
    if letter in lap.keys():                           # checks if the letter is present in the movie name  
        movie_guess = lap[letter]  
        for letter_guess in movie_guess:
            starred_movie = starred_movie[:letter_guess]+letter+starred_movie[letter_guess+1:]
        score = score+3                                #increases the points ofg the player
        print('correct guess')
        print(starred_movie)
        print(f' Score= {score}')
        lap.pop(letter)
#correct guess adds three points

    else:                                               #deducts the points if the letter is not present in movie name
        score = score-2
        print('incorrect guess')
        print(starred_movie)
        print(f'Score={score}')

if '*' not in starred_movie:
    print("YOU WON ")

else:
    print("YOU LOOSE")

print(f"The Answer was {selected_movie[0]}")                     #prints the correct answer
