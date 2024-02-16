import matplotlib.pyplot as plt
import csv

# CSVファイルからデータを読み取る
x = []
y = []
with open('tcp_time.csv', 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    for row in csvreader:
        x.append(int(row[0]))
        y.append(float(row[1]))

# グラフを作成する
plt.plot(x, y, marker='o', linestyle='',color='black', label='data')  # markerパラメータで点をプロット
plt.xlabel('n')
plt.ylabel('Time[s]')
plt.grid(True)

# 凡例を表示する

plt.show()
