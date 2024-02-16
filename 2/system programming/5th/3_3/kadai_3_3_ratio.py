import matplotlib.pyplot as plt
import csv
import pandas as pd

df = pd.read_csv('kadai_3_3_ratio.csv')
x = df['n']
y = df['tousen']

plt.scatter(x, y, label = 'atari', color = 'black', s = 10)
#put labels on each
plt.xlabel('N')
plt.ylabel('Number of wins')
plt.grid(True)
plt.legend()
plt.savefig('my_plot_3_3_ratio.png')
plt.show()