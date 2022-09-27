import pygame, random, sys
from pygame.locals import *


pygame.init()

FPS         = 30
fpsClock    = pygame.time.Clock()
boardWdith  = 500
boardHeight = 500
displaySurf = pygame.display.set_mode((boardWdith, boardHeight), 0, 32)
pygame.display.set_caption('Run Bitch')
White =  (255, 255, 255)
Green =  (  0, 255,   0)
Blue  =  (  0,   0, 128)
playerImg   = pygame.image.load('plane.png')
backGround  = pygame.image.load('spacebg.png')
enemyImg    = pygame.image.load('enemy.png')
shot        = pygame.image.load('shot01.png')
Menu1       = pygame.image.load('menu.png')
loseScreen  = pygame.image.load('lose.png')
lvl2Menu    = pygame.image.load('lvl2Menu.png')
enemyArray  = []
        
class firstPlayer(object):
    def __init__(self,height, width, px, py, changex, changey):
        self.height  = height
        self.width   = width
        self.px      = px
        self.py      = py
        self.changex = changex
        self.changey = changey
        self.hitbox  = (self.px + 50, self.py, 30, 60)
        self.death = False
    
    def boardCheck(player):
        if player.px      <= 0:
            player.changex = 0
            player.px      = 1
        
        if player.px      >= 445:
            player.changex = 0
            player.px      = 444

        if player.py      >= 400:
            player.changey = 0
            player.py      = 399


    def deathCheck(self, enemy01):
        if self.px + 25 > enemy01.ex and self.px - 25 < enemy01.ex + 30:
            if self.py - 20 <= enemy01.ey + 20:
                self.death = True
        else:
                self.death = False


    def beatLevel(self, enemy01, enemy02, enemy03):
        if enemy01.alive == False and enemy02.alive == False and enemy03.alive == False:
            changeLevel()
        
    
class enemy(object):

    def __init__(self, width, height, ex, ey, changex, changey):
        self.width   = width
        self.height  = height
        self.ex      = ex
        self.ey      = ey
        self.changex = changex
        self.changey = changey
        self.hitbox  = (self.ex, self.ey, 30,30)
        self.hitFlag = False
        self.alive = True

    def boardCheck(enemy):
        if enemy.ex      <= 0:
            enemy.changex = 8
            enemy.ex      = 1
        
        if enemy.ex      >= 445:
            enemy.changex = -8
            enemy.ex      = 444 

        if enemy.ey      >= 375:
            enemy.changey = -8
            enemy.ey      = 10

    def reloadEn():
        for enemy in enemyArray:
            enemy.alive = True

    def hit(self):
        print('hit')
        pass

class ammo(object):
    
    ax      = 0
    ay      = 0
    changex = 0
    changey = 0
    Fire    = False
    First   = True
    Kill    = False
    ammobox = (450,400,30,30)
    def fire(ammo01, player, enemy01, enemy02, enemy03):
        if ammo01.Fire == True:
            ammo01.hit(enemy01)
            ammo01.hit(enemy02)
            ammo01.hit(enemy03)
            ammo01.changey = -7
            if ammo01.First == True:
                ammo01.ay      = player.py
                ammo01.ax      = player.px + 21
                ammo01.First   = False
            if ammo01.ay      <= 10:
                ammo01.ax      = 0
                ammo01.ay      = 0
                ammo01.changey = 0
                ammo01.Fire    = False
                ammo01.First   = True

    def hit(ammo01,enemy01):
        if ammo01.ax + 15 > enemy01.hitbox[0] and ammo01.ax - 15 < enemy01.hitbox[0] + enemy01.hitbox[2]:
                    if ammo01.ay - 15 < enemy01.hitbox[1] + enemy01.hitbox[3] and ammo01.ay + 15 > enemy01.hitbox[1]:
                        enemy01.hit()
                        enemy01.alive   = False
                        ammo01.ax       = 0
                        ammo01.ay       = 0
                        ammo01.changey  = 0
                        ammo01.Fire     = False
                        ammo01.First    = True
                        enemy01.hitFlag = True

def displayAmmo(ammo01):
    if ammo01.Fire   == False:
        displaySurf.blit(shot, (460,400))
        
    
            
        
    
def redrawScreen(ammo01, enemy02, enemy01, enemy03, player):
    i = 0
    displaySurf.fill(White)
    displaySurf.blit(backGround, (0,0))
    
    if ammo01.Fire == True:
        displaySurf.blit(shot, (ammo01.ax,ammo01.ay))
    if player.death == False:   
        displaySurf.blit(playerImg, (player.px,player.py))
        
    #for i in range(len(enemyArray)):
    #    displaySurf.blit(enemyArray[i], (enemyArray[i].ex, enemyArray[i].ey))
    if enemy01.hitFlag == False:
        displaySurf.blit(enemyImg, (enemy01.ex, enemy01.ey))
        
    if enemy02.hitFlag == False:
        displaySurf.blit(enemyImg, (enemy02.ex, enemy02.ey))

    if enemy03.hitFlag == False:
        displaySurf.blit(enemyImg, (enemy03.ex, enemy03.ey))
        
    
    enemy02.hitbox = (enemy02.ex, enemy02.ey, 30,30)
    #pygame.draw.rect(displaySurf, (255,0,0), enemy02.hitbox,2)
        
    enemy01.hitbox = (enemy01.ex, enemy01.ey, 30,30)
    #pygame.draw.rect(displaySurf, (255,0,0), enemy01.hitbox,2)

    enemy03.hitbox = (enemy03.ex, enemy03.ey, 30, 30)
    
    player.hitbox  = (player.px, player.py, 60, 60)
    #pygame.draw.rect(displaySurf, (255,0,0),player.hitbox, 2)
    displayAmmo(ammo01)
    pygame.draw.rect(displaySurf, White, ammo.ammobox, 2)
    pygame.display.update()
    fpsClock.tick(FPS)

def startMenu():
    menu = True
    while menu == True:
        for event in pygame.event.get():
            displaySurf.fill(White)
            displaySurf.blit(Menu1, (0,0))
            pygame.display.update()
            fpsClock.tick(FPS)
            if event.type == QUIT:
                    pygame.quit()
                    sys.exit()

            elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                if event.key == pygame.K_s or event.key == ord('s'):
                    menu = False
                elif event.key == pygame.K_q or event.key == ord('q'):
                    pygame.quit()
                    sys.exit()
                


    

def lose():
    lost = True
    while lost == True:
        for event in pygame.event.get():
            displaySurf.fill(White)
            displaySurf.blit(loseScreen, (0,0))
            pygame.display.update()
            fpsClock.tick(FPS)
            if event.type == QUIT:
                    pygame.quit()
                    sys.exit()

            elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                if event.key == pygame.K_r or event.key == ord('r'):
                    lost = False
                elif event.key == pygame.K_q or event.key == ord('q'):
                    pygame.quit()
                    sys.exit()

def changeLevel():
    menu = True
    while menu == True:
        for event in pygame.event.get():
            displaySurf.fill(White)
            displaySurf.blit(lvl2Menu, (0,0))
            pygame.display.update()
            fpsClock.tick(FPS)
            if event.type == QUIT:
                    pygame.quit()
                    sys.exit()

            elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                if event.key == pygame.K_s or event.key == ord('s'):
                    menu = False
                    enemy.reloadEn()
                elif event.key == pygame.K_q or event.key == ord('q'):
                    pygame.quit()
                    sys.exit()

def main():
    enemy01 = enemy(30, 30, 150, 50,8,0)
    enemy02 = enemy(30, 30, 50, 20,8,0)
    enemy03 = enemy(30, 30, 25, 15,8,0)
    player  = firstPlayer(61, 61, 50, 350, 0, 0) 
    ammo01  = ammo()
    startMenu()
    
    #for alive,1 in enemyArray.__dict__.items():
    enemyArray.append(enemy01)
    enemyArray.append(enemy02)
    enemyArray.append(enemy03)

        
          
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                
                pygame.quit()
                sys.exit()
                
            elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == ord('a'):
                        player.changex -= 1
                    
                elif event.key == pygame.K_RIGHT or event.key == ord('d'):
                    player.changex += 1
                    
                elif event.key == pygame.K_UP or event.key == ord('w'):
                    player.changey -= 1
                    
                elif event.key == pygame.K_DOWN or event.key == ord('s'):
                    player.changey += 1
                    
                elif event.key == pygame.K_SPACE or event.key == ord(' '):
                    ammo01.Fire = True

        
   
        ammo01.fire(player, enemy01, enemy02, enemy03)
        player.boardCheck()
        enemy01.boardCheck()
        enemy02.boardCheck()
        enemy03.boardCheck()

        
        player.px = player.changex + player.px
        player.py = player.changey + player.py

        enemy01.changey = 1
        enemy02.changey = 1
        enemy03.changey = 1
        enemy01.ex = enemy01.ex + enemy01.changex
        enemy01.ey = enemy01.ey + enemy01.changey
        enemy02.ex = enemy02.ex + enemy02.changex
        enemy02.ey = enemy02.ey + enemy02.changey
        enemy03.ex = enemy03.ex + enemy03.changex
        enemy03.ey = enemy03.ey + enemy03.changey
        
        ammo01.ay   = ammo01.ay + ammo01.changey

        
        
        if enemy01.alive == True:
            player.deathCheck(enemy01)
        if enemy02.alive == True:
            player.deathCheck(enemy02)
        if player.death == True:
            lose()
            player.px = 50
            player.py = 350
        player.beatLevel(enemy01, enemy02, enemy03)
        redrawScreen(ammo01, enemy02, enemy01, enemy03, player)
        
        
                      
        print(player.death)
        #print(enemy02.elx)
        #print(enemy02.erx)
        #print(ammo01.ax)
        #print(ammo01.ay)
        #print(ammo01.Kill)
    
        

if __name__ == '__main__':
    main()


