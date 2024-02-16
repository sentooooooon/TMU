import numpy as np
import matplotlib.pyplot as plt

# 正規分布のパラメータ
mu = 0  # 平均
sigma = 1  # 標準偏差

# 理論的な正規分布の確率密度関数（PDF）を計算
x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)
pdf = (1 / (sigma * np.sqrt(2 * np.pi))) * np.exp(-(x - mu)**2 / (2 * sigma**2))

# 確率密度関数（PDF）のプロット
plt.plot(x, pdf, label='Theoretical PDF', color='blue')

# グラフの設定
plt.title('Theoretical Probability Density Function (PDF) of Normal Distribution')
plt.xlabel('Value')
plt.ylabel('Probability Density')
plt.legend()
plt.grid(True)
plt.show()
