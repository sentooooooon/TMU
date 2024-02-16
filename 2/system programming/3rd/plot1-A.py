import matplotlib.pyplot as plt
import csv

# データを格納するためのリスト
N = []
Average = []

# CSVファイルを読み込む
with open('DiceAverage1-A.csv', 'r') as csvfile:
    csvreader = csv.DictReader(csvfile)
    for row in csvreader:
        N.append(int(row['N']))
        Average.append(float(row['Average']))

# グラフを作成
plt.figure(figsize=(10, 6))  # グラフのサイズを設定 (オプション)

# 折れ線グラフを作成
plt.plot(N, Average, marker='o', linestyle='None')

y_value = 11.0/3
plt.axhline(y=y_value, color='r', linestyle='-', label=f'y = {y_value}')
# グラフにタイトルと軸ラベルを追加
plt.xlabel('N')
plt.ylabel('Average')

# グリッドを表示
plt.grid(True)
plt.savefig("my_plot1-A.png")
# グラフを表示
plt.show()
