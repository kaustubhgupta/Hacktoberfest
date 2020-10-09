"""
@author: Arpit Somani
"""

#Import the required modules

import numpy

#Creating the platform, where we play the game.

board= numpy.array([['_','_','_'],['_','_','_'],['_','_','_']])

#We have 2 symbols , as its a 2 player game

p1s= 'X'
p2s= 'O'

#Checking for empty place in rows

def check_rows(symbol):
    for r in range (3):
        count=0
        for c in range(3):
            if board[r][c] == symbol:
                count=count+1
        if count==3:
            print(symbol,"Won")
            return True
    return False

#Checking for empty place in columns

def check_cols(symbol):
    for c in range (3):
        count=0
        for r in range(3):
            if board[r][c] == symbol:
                count=count+1
        if count==3:
            print(symbol,"Won")
            return True
    return False

#Checking for empty place in diagonals
   
def check_diagonals(symbol):
    if board[0][2]==board[1][1] and board[1][1]==board[2][0] and board[1][1]==symbol:
        print(symbol,"Won")
        return True
    if board[0][0]==board[1][1] and board[1][1]==board[2][2] and board[1][1]==symbol:
        print(symbol,"Won")
        return True
    return False

#When a player get into the win siituation, when a straight line formed either at row,column or diagonal position.

def won(symbol):
    return check_rows(symbol) or check_cols(symbol) or check_diagonals(symbol)


#Placing of players symbol as desired empty position

def place(symbol):
    print(numpy.matrix(board))
    while(1):
        row=int(input('Enter row: 1 or 2 or 3: '))
        col=int(input('Enter col: 1 or 2 or 3: '))
        if row>0 and row<4 and col>0 and col<4 and board[row-1][col-1]=='_':
            break
        else:
            print('Invalid input. PLease enter again!')
    board[row-1][col-1]=symbol
 

#The play function, player 1 starts game, and the chances will revolve one by one in between 2 players, until a winner arise.

def play():
    for turn in range(9):
        if turn%2==0:
            print("X's turn")
            place(p1s)
            if won(p1s):
                break
        else:
            print("O's turn")
            place(p2s)
            if won(p2s):
                break
            
    if not(won(p1s)) and not(won(p2s)):
        print("Draw!")

#Calling play function       

play()
