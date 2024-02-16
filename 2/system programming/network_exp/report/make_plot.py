import matplotlib.pyplot as plt
import csv

# CSVファイルからデータを読み取る関数
def read_csv(filename):
    x = []
    y = []
    with open(filename, 'r') as csvfile:
        csvreader = csv.reader(csvfile)
        for row in csvreader:
            x.append(pow(2,int(row[0])))
            y.append(float(row[1]))
    return x, y

# 2つのCSVファイルからデータを読み込む
x1, y1 = read_csv('cppfile/tcp/tcp_time.csv')
x2, y2 = read_csv('cppfile/udp/udp_time.csv')

# グラフを作成する
plt.plot(x1, y1, marker='o', linestyle='', color='black', label = 'tcp')
plt.plot(x2, y2, marker='o', linestyle='', color='grey', label = 'udp')

plt.xlabel('i')
plt.ylabel('Time[s]')
plt.grid(True)
plt.legend()

plt.savefig('plot.png')

plt.show()
