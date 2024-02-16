import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# CSVファイルからデータを読み込む（適切なファイルパスを指定）
file_path = 'kadai_4_1.csv'
data = pd.read_csv(file_path)

# ヒストグラムを作成
plt.hist(data['Xn'], bins=30, color='white', edgecolor='black', density=True)  # density=Trueで正規化

# 理論的な正規分布の確率密度関数（PDF）を計算
mu = data['Xn'].mean()  # 平均
sigma = data['Xn'].std()  # 標準偏差
x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)
pdf = (1 / (sigma * np.sqrt(2 * np.pi))) * np.exp(-(x - mu)**2 / (2 * sigma**2))

# 確率密度関数（PDF）のプロット
plt.plot(x, pdf, label='Theoretical PDF', color='black')

# グラフにタイトルやラベルを追加
plt.xlabel('Xn')
#plt.title('Theoretical PDF and Histogram of Xn')
plt.legend()

# グラフを保存
plt.savefig('my_plot_4_1.png')

# グラフを表示
plt.show()
