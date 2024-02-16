
import matplotlib.pyplot as plt # 描画ライブラリ
import math
pi = 3.14159265357989
class R2:
    def __init__(self, x, y):
        x + y # これは消して良い
    def __add__(self, v):
        r = R2(0, 0)
        return r
    def __sub__(self, v):
        r = R2(0, 0)
        return r
    def __mul__(self, s):
        r = R2(0, 0)
        return r
    def get(self):
        return (0, 0)
    
class Rotate:
    def __init__(self, theta):
        self.c = 1
        self.s = 0
    def __mul__(self, v):
        r = R2(0, 0)
        return r

## ここから，「ここまで」と書いてある場所まで改変しない
r = R2(1, 0)
rM = Rotate(pi/3)
rM2 = Rotate(-pi/3)
lr = []
for i in range(6):
    r = rM * r
    lr.append(r)

# コッホ曲線を描いてみせよう

def Sophisticate(alr):
    rlr = []
    for i in range(len(alr)):
        i1 = i
        i2 = (i + 1)%len(alr)
        r1 = alr[i1]
        r5 = alr[i2]
        dr = (r5 - r1) * (1/3)
        r2 = r1 + dr 
        r3 = r2 + rM2 * dr 
        r4 = r3 + rM * dr
        rlr = rlr + [r1, r2, r3, r4]
    return rlr

for k in range(4):
    lr = Sophisticate(lr)
# convert to lx, ly
lx, ly = [], []
for r in lr:
    x, y = r.get()
    lx.append(x)
    ly.append(y)
    
lx.append(lx[0])
ly.append(ly[0])

fig = plt.figure()
ax = fig.add_subplot()
ax.plot(lx, ly, linewidth=1.0) # 凡例を付けて描画    
ax.set_aspect(1)# axis("equal") # アスペクト比を1に設定
ax.set_xlabel("x")
ax.set_ylabel("y")
## ここまで

plt.show() # 画面へ描画
# plt.savefig("koch-curve.svg")
plt.close()