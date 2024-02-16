import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm  # 正規分布を使用するためにscipy.statsをインポート

# CSVファイルからデータを読み込む（適切なファイルパスを指定）
file_path = 'kadai_4_A.csv'
data = pd.read_csv(file_path)

# ヒストグラムを作成
plt.hist(data['Pn'], bins=30, color='white', edgecolor='black', density=True)  # density=Trueで正規化

# 正規分布のパラメータを計算
mu, std = data['Pn'].mean(), data['Pn'].std()

# 範囲を指定して正規分布の確率密度関数を計算
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)

# 正規分布をプロット
plt.plot(x, p, 'k', linewidth=2)

# グラフにタイトルやラベルを追加（任意）
plt.xlabel('Pn')
plt.title('Histogram with Theoretical Normal Distribution')
plt.legend(['Normal Distribution', 'Histogram'])

# グラフを保存
plt.savefig('my_plot_4_A.png')

# グラフを表示
plt.show()
