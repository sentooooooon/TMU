import numpy as np 

answer = 0
init = False
    
def practice0(NL=128):
    global answer
    global init
    answer = 0
    init = True
    NL = NL + np.random.randint(0, NL)
    ipath = np.random.randint(0, 8)
    head2 = ["a", "b", "v", "x"]
    nh = np.random.randint(2, len(head2)+1)
    head2 = head2[0:nh]
    head2.append("y")
    import random
    random.shuffle(head2)
    # 
    path = "10th-practice-" + str(ipath) + ".csv"
    f = open(path, "w")
    for i in range(len(head2)):
        f.write(head2[i])
        if i != len(head2)-1:
            f.write(",")
    f.write("\n")
    
    for i in range(NL):
        for j in range(len(head2)):
            num = np.random.randint(0, 128)
            snum = str(num)
            t = np.random.randint(0, 4)
            if t == 0:
                snum = "gabage" + snum
                if head2[j] == "y":
                    answer += 1
            else:
                if head2[j] == "y":
                    answer += num
            f.write(snum)
            if j != len(head2) -1:
                f.write(",")
        f.write("\n")
    f.close()
    return path

def practice0GetAns():
    global answer
    global init
    if init:
        return answer
    else:
        raise Exception("practice0　を先に呼び出してください。")

if __name__ == "__main__": 
    path = practice0(2)
    print(path)
    f = open(path, "r")
    print(f.read())
    print(practice0GetAns())
