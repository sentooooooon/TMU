import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('kadai_3_A_profits.csv')
x = df['prob']
y = df['profit']

# 散布図をプロット
plt.scatter(x, y, label = 'atari', color = 'black', s = 10)

# グラフのタイトルや軸ラベルを追加する（オプション）
plt.xlabel('probability')
plt.ylabel('profits')
plt.legend()
plt.savefig('my_plot_3_A_profits.png')
# グラフを表示する（Jupyter Notebookなどでインタラクティブに表示する場合は不要）
plt.show()