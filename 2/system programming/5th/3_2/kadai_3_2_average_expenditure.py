import pandas as pd
import matplotlib.pyplot as plt

# 1. 必要なライブラリをインポートする

# 2. CSVファイルをPandas DataFrameに読み込む
# ファイル名を指定してCSVファイルを読み込みます。delimiterは適切に設定してください。
# 例: ファイル名がdata.csvで、カンマ区切りの場合
df = pd.read_csv('kadai_3_2_average_expenditure.csv')
dd = pd.read_csv('kadai_3_2_average_expenditure1.csv')

# 3. データを散布図としてプロットする

# データフレームのカラムからX軸とY軸のデータを選択
x = df['n']
y = df['average']
x1 = dd['n']
y1 = dd['average']

# 散布図をプロット
plt.scatter(x, y, label = 'atari', color = 'black', s = 10)
plt.scatter(x1, y1, label = 'atari', color = 'grey', s = 10)

# グラフのタイトルや軸ラベルを追加する（オプション）
plt.xlabel('N')
plt.ylabel('spent money')
plt.legend()
plt.savefig('my_plot_3_2_average.png')
# グラフを表示する（Jupyter Notebookなどでインタラクティブに表示する場合は不要）
plt.show()