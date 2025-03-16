import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import csv

x, y= [],[]
count = 0
with open("RandomWalk2D.csv") as f:
    reader = csv.reader(f)
    for row in reader:
        if count == 0:
            count = -1
            continue
        x.append(int(row[0]))
        y.append(int(row[1]))

plt.plot(x, y)
plt.title("2D Random Walk")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
