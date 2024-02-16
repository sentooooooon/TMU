import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('kadai_3_3_average_expenditure.csv')
x = df['n']
y = df['average']

# 散布図をプロット
plt.scatter(x, y, label = 'atari', color = 'black', s = 10)

# グラフのタイトルや軸ラベルを追加する（オプション）
plt.xlabel('N')
plt.ylabel('spent money')
plt.legend()
plt.savefig('my_plot_3_3_average.png')
# グラフを表示する（Jupyter Notebookなどでインタラクティブに表示する場合は不要）
plt.show()