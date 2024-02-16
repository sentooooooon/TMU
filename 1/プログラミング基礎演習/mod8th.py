import numpy as np
import random

def init(id):
    random.seed(id)
    np.random.seed(id)


def getPractice1():
    data = ["James","John","Robert","Michael","William","David","Richard","Joseph","Thomas","Charles","Christopher","Daniel","Matthew","Anthony","Donald","Mark","Paul","Steven","Andrew","Kenneth","Joshua","George","Kevin","Brian","Edward","Ronald","Timothy","Jason","Jeffrey","Ryan","Jacob","Gary","Nicholas","Eric","Stephen","Jonathan","Larry","Justin","Scott","Brandon","Frank","Benjamin","Gregory","Samuel","Raymond","Patrick","Alexander","Jack","Dennis","Jerry","Tyler","Aaron","Jose","Henry","Douglas","Adam","Peter","Nathan","Zachary","Walter","Kyle","Harold","Carl","Jeremy","Keith","Roger","Gerald","Ethan","Arthur","Terry","Christian","Sean","Lawrence","Austin","Joe","Noah","Jesse","Albert","Bryan","Billy","Bruce","Willie","Jordan","Dylan","Alan","Ralph","Gabriel","Roy","Juan","Wayne","Eugene","Logan","Randy","Louis","Russell","Vincent","Philip","Bobby","Johnny","Bradley","Mary","Patricia","Jennifer","Linda","Elizabeth","Barbara","Susan","Jessica","Sarah","Karen","Nancy","Margaret","Lisa","Betty","Dorothy","Sandra","Ashley","Kimberly","Donna","Emily","Michelle","Carol","Amanda","Melissa","Deborah","Stephanie","Rebecca","Laura","Sharon","Cynthia","Kathleen","Helen","Amy","Shirley","Angela","Anna","Brenda","Pamela","Nicole","Ruth","Katherine","Samantha","Christine","Emma","Catherine","Debra","Virginia","Rachel","Carolyn","Janet","Maria","Heather","Diane","Julie","Joyce","Victoria","Kelly","Christina","Joan","Evelyn","Lauren","Judith","Olivia","Frances","Martha","Cheryl","Megan","Andrea","Hannah","Jacqueline","Ann","Jean","Alice","Kathryn","Gloria","Teresa","Doris","Sara","Janice","Julia","Marie","Madison","Grace","Judy","Theresa","Beverly","Denise","Marilyn","Amber","Danielle","Abigail","Brittany","Rose","Diana","Natalie","Sophia","Alexis","Lori","Kayla","Jane"]
    dataD = {}
    for k in data:
        s = np.random.normal(loc=50, scale=10)
        dataD[k] = s
    return dataD


codeL = ["a","b","c","d","e","f","g","h","i","j"]
codeM = {}
codeMI = {}
for i in range(10):
    codeM[str(i)] = codeL[i]
    codeMI[codeL[i]] =str(i)

def getPractice2Dict():
    return codeMI

def getPractice2():
    random.shuffle(codeL)

    s = np.random.randint(0, 31)
    text = str(s)
    L = []
    n = 256
    for i in range(0, n):
        s = np.random.randint(0, 31)
        L.append(s)
        text = text + "-" + str(s)
    text2 = ""
    for i in text:
        j = "-"
        if i in codeM:
            j = codeM[i]
            
        text2 = text2 + j
    return text2
    
