import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm  # SciPyのstatsモジュールから正規分布を使用

# CSVファイルからデータを読み込む（適切なファイルパスを指定）
file_path = 'kadai_4_2.csv'
data = pd.read_csv(file_path)

# ヒストグラムを作成
plt.hist(data['Yn'], bins=30, color='white', edgecolor='black', density=True)  # density=Trueで正規化

# 理論的な正規分布の確率密度関数（PDF）を計算
mu = data['Yn'].mean()  # 平均
sigma = data['Yn'].std()  # 標準偏差
x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)
pdf = norm.pdf(x, mu, sigma)

# 確率密度関数（PDF）のプロット
plt.plot(x, pdf, label='Theoretical PDF', color='black')

# グラフにタイトルやラベルを追加
plt.xlabel('Yn')
plt.legend()

# グラフを保存
plt.savefig('my_plot_4_2.png')

# グラフを表示
plt.show()
