import random
# This lib is used to choose a random word from the list of word

# The user can feed his name
name = input("What's your Name? ")
print("Good Luck ! ", name)
words = ['education', 'rainbow', 'computer', 'science', 'programming',
         'python', 'mathematics', 'player', 'condition',
         'reverse', 'water', 'board', 'hacktoberfest']

# Our function will choose a random from the give list
word = random.choice(words)
print("Guess the characters")
guesses = ''
# You can reduce/increase the number of turns
turns = 10
while turns > 0:
    # This holds the number of times a user fails
    failed = 0
    # The letter you feed is taken as input one at a time
    for char in word:
        # Comparing that character with our set
        if char in guesses:
            print(char)
        else:
            print("_")
            # For every failure 1 will be added in failed count
            failed += 1
    if failed == 0:
        # The User will win the game if failure is 0
        print("You Win")
        # This prints the correct word
        print("The word is: ", word)
        break
    # If user has input the wrong alphabet then the user is given a next chance
    guess = input("guess a character:")
    # Every input character will be stored in guesses
    guesses += guess
    # Check input with the character in word
    if guess not in word:
        turns -= 1
 # if the character doesn’t match the word then “Wrong” will be given as output
        print("Wrong")
        # this will print the number of turns left
        print("You have", + turns, 'more guesses')
        if turns == 0:
            print("You Loose")
