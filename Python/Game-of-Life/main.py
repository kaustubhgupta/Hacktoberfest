#! ./venv/bin/python3.7

import argparse
import numpy as np
import pygame
from time import sleep


textColor = 200,200,200
liveColor = 250,250,250
bgColor = 10,10,10
borderColor = pygame.Color(100,100,100)
nn, l, t, originText = 0, 0, 0, 0
screen, font = None, None
TITLE = 'Game of Life'

def configure(args):
    global nn, l, t, originText, screen, font, font_title
    nn = args.n # number of cel
    t = args.t
    maxSizeCel = args.m # max size of cel, en px

    pygame.init()
    hwWidth  = pygame.display.Info().current_w
    hwHeigth = pygame.display.Info().current_h
    if not pygame.font.get_init():
        pygame.font.init()
    font_title = pygame.font.SysFont('freesans', 26)
    font = pygame.font.SysFont('freesans', 18)
    # sets the width of a cell depending on the amount to be displayed.
    l = int(hwHeigth / nn) if int(hwHeigth / nn) < maxSizeCel else maxSizeCel

    # calculates the width of the screen based on the width of each cell.
    screenHeigth = (l * nn) if (l * nn) < hwHeigth else hwHeigth
    originText = screenHeigth + 10
    # for now it shows only one square of cells. Then it will show information on the right.
    sizeScreen = (screenHeigth + 200, screenHeigth)
    screen = pygame.display.set_mode(sizeScreen)

def getNumberNeighbor(gameStatus, coor):
    # Calcute number of neighbors for each cel(x,y), with toroide topology.
    x, y = coor
    return (gameStatus[(x-1+nn)%nn,(y-1+nn)%nn] + gameStatus[(x-1+nn)%nn,y] + gameStatus[(x-1)%nn,(y+1)%nn] +\
            gameStatus[x,(y-1+nn)%nn]                       +                 gameStatus[x,(y+1)%nn] +\
            gameStatus[(x+1)%nn,(y-1+nn)%nn] +  gameStatus[(x+1)%nn,y]   + gameStatus[(x+1)%nn,(y+1)%nn])

def polygon(x, y, l):
    # Square from coordinates x, y, with size l
    return [(    x * l  ,    y * l)   ,\
            (    x * l  , (y + 1) * l),\
            ((x + 1) * l, (y + 1) * l),\
            ((x + 1) * l,    y * l)   ]

def handle_event(pause, newGameStatus):
    running = True
    events = pygame.event.get()
    for ev in events:
        if ev.type == pygame.QUIT:
            running = False
        elif ev.type == pygame.KEYDOWN and ev.key == pygame.K_SPACE:
            pause = not pause

        mouseClick = pygame.mouse.get_pressed()
        if sum(mouseClick) > 0:
            x, y = pygame.mouse.get_pos()
            i, j = int(np.floor(x / l)), int(np.floor(y / l))
            newGameStatus[i,j] = not mouseClick[2]
    return pause, running

def game():
    i = 0
    running = True
    pause = True

    # Initial status of game
    gameStatus = np.zeros((nn, nn))

    while running:
        newGameStatus = np.copy(gameStatus)
        pause, running = handle_event(pause, newGameStatus)
        screen.fill(bgColor)
        # Set the initial text of game
        title = font_title.render(TITLE, True, textColor)

        info1 = font.render('Cells: {0} x {0}'.format(nn), True, textColor)
        info2 = font.render('Iteration: {0}'.format(i), True, textColor)
        originY = 0
        screen.blit(title, (originText, originY))
        originY = font_title.size(TITLE)[1] + 10
        screen.blit(info1, (originText, originY))
        originY = originY + font.size('Cells: {0} x {0}'.format(nn))[1] + 5
        screen.blit(info2, (originText, originY))

        for y in range(0, nn):
            for x in range(0, nn):

                if not pause:
                    n_neigh = getNumberNeighbor(gameStatus, (x, y))
                    # if is dead and have three neighbors alive again.
                    if gameStatus[x,y] == 0 and n_neigh == 3:
                        newGameStatus[x,y] = 1
                    # if is alive, die for loneliness or overpopulation.
                    elif gameStatus[x,y] == 1 and (n_neigh <2 or n_neigh > 3):
                        newGameStatus[x,y] = 0

                if newGameStatus[x,y] == 1:
                    pygame.draw.polygon(screen, liveColor, polygon(x, y, l), 0)
                else:
                    pygame.draw.polygon(screen, borderColor, polygon(x, y, l), 1)

        i = i + 1 if (not pause) and not (gameStatus == newGameStatus).all() else i
        gameStatus = np.copy(newGameStatus)
        pygame.display.flip()
        sleep(t)

def au_revoir():
    # print("\nGracias por probar este juego =D\n")
    # print("\nThanks for trying this game =D\n")
    # print("\nMerci d'avoir essayé ce jeu =D\n")
    # print("\nDankon pro provi ĉi tiun ludon =D\n")
    # print("\nDeo gratias, quia hoc ludum conatur =D\n")
    pygame.font.quit()
    pygame.quit()


def main():
    parser = argparse.ArgumentParser(description='Game of Life.')
    parser.add_argument('-n', metavar='n', type=int, default=35,
                        help='Number of cels')
    parser.add_argument('-m', metavar='m', type=int, default=20,
                        help='Max size of cel, in px')
    parser.add_argument('-t', metavar='t', type=float, default=.1,
                        help='Time between updates screen')
    args = parser.parse_args()
    configure(args)
    game()
    au_revoir()

if __name__ == '__main__':
    main()
