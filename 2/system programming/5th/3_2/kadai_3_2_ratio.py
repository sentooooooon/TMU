import matplotlib.pyplot as plt
import csv
import pandas as pd

df = pd.read_csv('kadai_3_2_ratio.csv')
dd = pd.read_csv('kadai_3_2_ratio1.csv')
x = df['n']
y = df['tousen']
x1 = dd['n']
y1= dd['tousen']

plt.scatter(x, y, label = 'atari', color = 'black', s = 10)
plt.scatter(x1, y1, label = 'atari', color = 'grey', s = 10)
#put labels on each
plt.xlabel('N')
plt.ylabel('Number of wins')
plt.grid(True)
plt.legend()
plt.savefig('my_plot3-2_ratio.png')
plt.show()