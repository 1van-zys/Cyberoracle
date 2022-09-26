
#!/usr/bin/python3

import random
import time

print("========================================================== ")
print("   ______      __              ____                  __    ")
print("  / ____/_  __/ /_  ___  _____/ __ \_________ ______/ /__  ")
print(" / /_/ / /_/ / /_ \/ _ \/ ___/ / / / ___/ __  / __   / _ \ ")
print("/ /_/ / /_/ / /___/  __/ /  / /_/ / /  / /_/ / /__/ /  __/ ")
print("\____/\__, /_.___/\___/_/   \____/_/   \__,_/\___/_/\___/  ")
print("     /____/                                                ")
print("========================================================== ")
print("@IVAN")
print("Rev.0")
print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ")
print("天何言哉，叩之即应神之灵矣，感而遂通，今有事关心，不知休咎罔释厥疑，惟神惟灵若可若否，望垂昭报")


i = 5
coin = 233
liuyao = [0, 0, 0, 0, 0, 0]

LAOYIN = 6
SHAOYANG = 7
SHAOYIN = 8
LAOYANG = 9

YINYAO = 0
YANGYAO = 1


'''
tosscoin
'''

def tosscoin():
    i = 0
    j = 0
    liuyao = [0, 0, 0, 0, 0, 0]
    coin = [0, 0, 0]

    while i < 6:
        j = 0
        while j < 3:
            coin[j] = random.choice([2,3])
            j += 1
        liuyao[i] = coin[0]+coin[1]+coin[2]
        print("爻：",liuyao[i])
        i += 1
    return liuyao

'''
根据六爻断本卦
'''

def bengua(liuyao):
    i = 0
    num = 0
    benyao = [0, 0, 0, 0, 0, 0]
    while i < 6:
        if liuyao[i] == LAOYIN:
            benyao[i] =YINYAO
        elif liuyao[i] == SHAOYANG:
            benyao[i] = YANGYAO
        elif liuyao[i] == SHAOYIN:
            benyao[i] = YINYAO
        elif liuyao[i] == LAOYANG:
            benyao[i] = YANGYAO

        i += 1

    num = benyao[5]*32+benyao[4]*16+benyao[3]*8+benyao[2]*4+ \
    benyao[1]*2+benyao[0]

    return num 

'''
综卦
'''
def zonggua(liuyao):
    liuyao.reverse()
    return liuyao




'''
变卦
'''

def change(liuyao):
    i = 0
    num = 0
    bianyao = [0, 0, 0, 0, 0, 0]
    while i < 6:
        if liuyao[i] == LAOYIN:
            bianyao[i] =YANGYAO
        elif liuyao[i] == SHAOYANG:
            bianyao[i] = YANGYAO 
        elif liuyao[i] == SHAOYIN:
            bianyao[i] = YINYAO
        elif liuyao[i] == LAOYANG:
            bianyao[i] = YINYAO

        i += 1

    num = bianyao[5]*32+bianyao[4]*16+bianyao[3]*8+bianyao[2]*4+ \
    bianyao[1]*2+bianyao[0]
    return num

liuyao = tosscoin()

print("本卦是：",bengua(liuyao))
print("变卦是：",change(liuyao))
