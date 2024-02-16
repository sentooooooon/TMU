import pandas as pd
import matplotlib.pyplot as plt

# CSVファイルからデータを読み込む
df = pd.read_csv('zuhyo01-05-01.csv')

# データフレームの内容を確認
print(df)

# 推移図の作成
plt.figure(figsize=(10, 6))  # 図のサイズを設定

# データフレームから必要な列を取り出して推移図を作成
# 例: '列1' を x 軸、 '列2' を y 軸に設定
plt.plot(df['year'], df['male'], marker='o', linestyle='-')

# グラフにタイトルや軸ラベルを追加
plt.title('推移図のタイトル')
plt.xlabel('X軸のラベル')
plt.ylabel('Y軸のラベル')

# グリッドを表示
plt.grid(True)

# グラフを表示
plt.show()
