import matplotlib.pyplot as plt
import csv

N = []
change = []
Nochange = []
with open('kadai_2_3.csv', newline='') as f:
    reader = csv.reader(f)
    hreader = next(reader)
    for row in reader:
        N.append(int(row[0]))
        Nochange.append(int(row[1]))
        change.append(int(row[2]))

plt.plot(N, change, marker = 'o',color = 'black', label = 'changed')
plt.plot(N, Nochange ,marker = 's' , color = 'black',label = 'Not changed')
plt.text(2, 2, 'changed', fontsize=12, color='red')
plt.text(2, 2, 'Not changed', fontsize=12, color='black')
#put labels on each
plt.xlabel('N')
plt.ylabel('Number of wins')
plt.grid(True)
plt.legend()
plt.savefig('my_plot2-3.png')
plt.show()