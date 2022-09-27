'''''''''''''''''''''''''''
galiga reboot - pygame    '
Ryan Walsh 2019           '
'''''''''''''''''''''''''''
import pygame, random, sys
from pygame.locals import *
from random import randint

'''''''''''''''''''''
Main Game Class     ' 
'''''''''''''''''''''

class mainGame:
    def __init__(self):
        self.screenSize = (650, 650)
        self.numFlags = 0
        self.depth = 0
        self.display = 32
        self.backGround = [pygame.image.load("1.gif"),pygame.image.load("2.gif"),pygame.image.load("3.gif")
                           ,pygame.image.load("4.gif"),pygame.image.load("5.gif"),pygame.image.load("6.gif")
                           ,pygame.image.load("7.gif"),pygame.image.load("8.gif"),pygame.image.load("9.gif")
                           ,pygame.image.load("10.gif"),pygame.image.load("11.gif"),pygame.image.load("12.gif")
                           ,pygame.image.load("13.gif"),pygame.image.load("14.gif"),pygame.image.load("15.gif")
                           ,pygame.image.load("16.gif"),pygame.image.load("17.gif"),pygame.image.load("18.gif")
                           ,pygame.image.load("19.gif"),pygame.image.load("20.gif"),pygame.image.load("21.gif")
                           ,pygame.image.load("22.gif"),pygame.image.load("23.gif"),pygame.image.load("24.gif")
                           ,pygame.image.load("25.gif"),pygame.image.load("26.gif"),pygame.image.load("27.gif")
                           ,pygame.image.load("28.gif"),pygame.image.load("29.gif"),pygame.image.load("30.gif")
                           ,pygame.image.load("31.gif"),pygame.image.load("32.gif"),pygame.image.load("34.gif")
                           ,pygame.image.load("34.gif"),pygame.image.load("35.gif"),pygame.image.load("36.gif")
                           ,pygame.image.load("37.gif"),pygame.image.load("38.gif"),pygame.image.load("39.gif")
                           ,pygame.image.load("40.gif")]
        self.menu = pygame.image.load("menu.png")
        self.white = (0, 0, 0)
        self.FPS = 45
        
        self.allSprites = pygame.sprite.Group()
        self.enemySprites = pygame.sprite.Group()
        self.ammoSprites = pygame.sprite.Group()
        self.playerSprites = pygame.sprite.Group()
        self.asteroidSprites = pygame.sprite.Group()
        
        self.ammoBox = (540, 600, 40, 40)
        self.hudBox = (0, 0, 100, 50)
        self.score = 0
        self.level = 1
                
 
    def startMenu(self, displayScreen):

        menu = True
        while menu == True:
            for event in pygame.event.get():
                displayScreen.blit(self.menu, (0,0))
                pygame.display.update()
                if event.type == QUIT:
                        pygame.quit()
                        sys.exit()
                elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                    if event.key == pygame.K_s or event.key == ord('s'):
                        menu = False
                    elif event.key == pygame.K_q or event.key == ord('q'):
                        pygame.quit()
                        sys.exit()
                        

    def enemyDeathCheck(self):# use pygame.sprite.collide_rect or somethin like that
        hitList = pygame.sprite.groupcollide(self.ammoSprites, self.enemySprites, False, True)
        for element in hitList:
            self.score += 1

    def playerDeathCheck(self, player):
        hitList = pygame.sprite.groupcollide(self.playerSprites, self.enemySprites, False, True)
        for sprites in hitList:
            player.lives -= 1
            if (player.lives == 0):
                self.gameOver()

    def gameOver(self):
        lost = True
        while lost == True:
            for event in pygame.event.get():
                #displaySurf.fill(White)
                #displaySurf.blit(loseScreen, (0,0))
                #pygame.display.update()
                if event.type == QUIT:
                        pygame.quit()
                        sys.exit()

                elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:
                    if event.key == pygame.K_r or event.key == ord('r'):
                        lost = False
                    elif event.key == pygame.K_q or event.key == ord('q'):
                        pygame.quit()
                        sys.exit()

    def levelOne(self):
        count = 0
        for sprites in self.enemySprites:
            count += 1
        if count <= 2:
            tempEnemy = enemy((0,0,0), random.randint(100, 500), random.randint(50, 200))
            self.enemySprites.add(tempEnemy)
            self.allSprites.add(tempEnemy)

    def levelTwo(self):
        count = 0
        for sprites in self.enemySprites:
            count += 1
        if count == 0:
            tempEnemy = enemy((0,0,0), random.randint(100, 500), random.rendint(50, 150))
            
                

    def levelThree(self):
        count = 0
        for sprites in self.enemySprites:
            count += 1
        if count == 0:
            for x in range(40, 550, 46):
                for y in range(40, 300, 36):
                    tempEnemy = enemy((0,0,0), x, y)
                    self.enemySprites.add(tempEnemy)
                    self.allSprites.add(tempEnemy)

            
    def enemyLoad(self):
        levels = {1 : self.levelOne(),
                  2 : self.levelTwo(),
                  3 : self.levelThree(),}
        
        if self.level == 1:
            levels[1]
        elif self.level == 2:
            levels[2]
        elif self.level == 3:
            level[3]
        
            

'''
        make board check with all sprites so they dont go out of bounds
'''    

'''''''''''''''''''''
First Player Class  ' 
'''''''''''''''''''''    
class firstPlayer(pygame.sprite.Sprite):
    def __init__(self,color, width, height):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load('planeship.png')
        self.rect = self.image.get_rect()
        self.rect.x = width
        self.rect.y = height
        self.numAmmo = 1
        self.lives = 3
        self.prevX = [width]
        self.prevY = [height]

    def shot(self, ammoSprites):
        for ammo in ammoSprites:
            
            if ammo.sF == True:
                break
            
            else:
                ammo.rect.x = self.rect.x + 21
                ammo.rect.y = self.rect.y - 35
                ammo.sF = True

    def shotCheck(self, ammoSprites):
        for ammo in ammoSprites:
            
            if ammo.sF == True:
                ammo.rect.y -= 21
                
            if ammo.rect.y <= 20:
                ammo.sF = False
                ammo.rect.x = 550
                ammo.rect.y = 600


        
        
        
                
        

'''''''''''''''''''''
ammo class          '
'''''''''''''''''''''
class ammo(pygame.sprite.Sprite):
    def __init__(self, color, width, height):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load('shot01.png')
        self.rect = self.image.get_rect()
        self.rect.x = width
        self.rect.y = height
        self.sF = False

'''''''''''''''''''''
Enemy class         '
'''''''''''''''''''''
class enemy(pygame.sprite.Sprite):
    def __init__(self, color, width, height):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load('enemy.png')
        self.rect = self.image.get_rect()
        self.rect.x = width
        self.rect.y = height
        self.prevX = [width]
        self.prevY = [height]
        self.step = 0

    def move(self):
        self.step += 1
        moveNum = random.randint(0,100)
        if (moveNum <= 25):
            self.prevX.append(self.rect.x)
            self.rect.x += 3
        elif (moveNum <= 50):
            self.prevX.append(self.rect.x)
            self.rect.x -= 3
        elif (moveNum <= 75):
            self.prevY.append(self.rect.y)
            self.rect.y += 3
        elif (moveNum <= 100):
            self.prevY.append(self.rect.y)
            self.rect.y -= 3
        
            

    def zMove(self):
        self.step += 1
        self.prevX.append(self.rect.x)
        self.prevY.append(self.rect.y)
        if(self.step <= 130):
            self.rect.x = self.prevX.pop(-1) + 3
        elif(self.step <= 300):
            self.rect.x = self.prevX.pop(-1) - 3
            self.rect.y = self.prevY.pop(-1) + 3
        elif(self.step <= 450):
            self.rect.x = self.prevX.pop(-1) + 3
            

    def boardCheck(self):
        if (self.rect.x + 20 >= 650):
            self.rect.x = 620 #self.prevX.pop(-1)
        elif (self.rect.x <= 0):
            self.rect.x = 50 #self.prevX.pop(-1)
        elif(self.rect.y >= 650 | self.rect.y <= 0):
            self.rect.y = self.prevY.pop()
        
            
            

'''''''''''''''''''''
hud function        '
'''''''''''''''''''''
def hud(displayScreen, screen, player1):
        tempScore = str(screen.score)
        tempLives = str(player1.lives)
        pygame.font.init()
        pygame.draw.rect(displayScreen, (255,255,255), screen.hudBox, 2)
        font = pygame.font.SysFont('344', 16)
        text = font.render('Score: ', True, (255,255,255))
        text2 = font.render('Lives: ', True, (255,255,255))
        score = font.render(tempScore, True, (255,255,255))
        lives = font.render(tempLives, True, (255,255,255))
        displayScreen.blit(text, (10,10))
        displayScreen.blit(score, (50,10))
        displayScreen.blit(text2, (10,25))
        displayScreen.blit(lives, (50,25))
        
        
        

'''''''''''''''''''''
Draw screen Function'
'''''''''''''''''''''

def drawScreen(screen, displayScreen, player1, allSprites, enemySprites, i):
    displayScreen.fill((0,0,0))
    displayScreen.blit(screen.backGround[i], (0,0))
    for sprites in enemySprites:
        sprites.zMove()
        sprites.boardCheck()
    pygame.sprite.Group.draw(allSprites, displayScreen)
    pygame.draw.rect(displayScreen, (255,255,255), screen.ammoBox, 2)
    hud(displayScreen, screen, player1)
    pygame.display.update()

'''''''''''''''''''''''''''
Main Game Function/call   '
'''''''''''''''''''''''''''

def main():
        pygame.display.init()
        if(pygame.display.get_init() == False):
            print("fatal Eror, display could not be opened")
            pygame.display.quit()
    
        screen = mainGame()
        
        player1 = firstPlayer((0,0,0), 300, 550)
        ammo01 = ammo((0,0,0), 550, 600)
        enemy01 = enemy((0,0,0),200, 100)
        enemy02 = enemy((0,0,0), 150, 100)

        screen_width = 600
        screen_height = 700
        displayScreen = pygame.display.set_mode([screen_width, screen_height])
        screen.startMenu(displayScreen)
        pygame.RESIZEABLE = 1
        fpsClock = pygame.time.Clock()
        
        screen.allSprites.add(player1, ammo01, enemy01, enemy02)
        screen.playerSprites.add(player1)
        screen.enemySprites.add(enemy01, enemy02)
        screen.ammoSprites.add(ammo01)
        backGroundIter = 0
        
        while True:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
                    
                elif event.type == pygame.KEYDOWN or event.type == pygame.KEYUP:#pushed a btn
                    
                    if event.key == pygame.K_RIGHT or event.key == ord('d'):#right arrow
                        player1.rect.x += 5
                        
                    elif event.key == pygame.K_LEFT or event.key == ord('a'):#left arrow
                        player1.rect.x -= 5
                        
                    elif event.key == pygame.K_UP or event.key == ord('w'):#up arrow
                        player1.rect.y -= 5
                        
                    elif event.key == pygame.K_DOWN or event.key == ord('s'):#down arrow
                        player1.rect.y += 5

                    elif event.key == pygame.K_SPACE or event.key == ord(' '):#spacebar/shot
                        player1.shot(screen.ammoSprites)
                        
                    elif event.key == pygame.K_q or event.key == ord('q'):#q or quit
                        pygame.quit()
                        sys.exit()
                        
                
            for sprites in screen.enemySprites:
                sprites.boardCheck()
            screen.enemyDeathCheck()
            screen.enemyLoad()
            screen.playerDeathCheck(player1)
            player1.shotCheck(screen.ammoSprites)
            drawScreen(screen, displayScreen, player1, screen.allSprites, screen.enemySprites,backGroundIter)
            fpsClock.tick(screen.FPS)
            backGroundIter += 1
            if backGroundIter >= 39:
                backGroundIter = 0
    #displayScreen.fill((0,0,0))
    #displayScreen.blit(screen.backGround, (0,0))
    #pygame.draw.rect(displayScreen, (0,0,0), Rect(90,0,90,0))
    #screen.initsys()
    #screen.playGame()
    
    
main()
