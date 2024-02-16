import matplotlib.pyplot as plt
import csv
import cmath
# データを格納するためのリスト
n = []
pi = []

# CSVファイルを読み込む
with open('kadai_2_1.csv', 'r') as csvfile:
    csvreader = csv.DictReader(csvfile)
    for row in csvreader:
        n.append(int(row['n']))
        pi.append(float(row['pi']))

# グラフを作成
plt.figure(figsize=(10, 6))  # グラフのサイズを設定 (オプション)

# 折れ線グラフを作成
plt.plot(n, pi, color = 'black', marker='o', linestyle='None')

y_value = 3.141
plt.axhline(y=y_value, color='black', linestyle='-', label=f'y = {y_value}')
# グラフにタイトルと軸ラベルを追加
plt.xlabel('n')
plt.ylabel('Pi')

# グリッドを表示
plt.grid(True)
plt.savefig("my_plot2-1.png")
# グラフを表示
plt.show()
