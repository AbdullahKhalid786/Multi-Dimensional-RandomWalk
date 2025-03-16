import matplotlib
matplotlib.use("TkAgg")  # Interactive backend for WSL
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import csv

# Lists to store x, y, z positions
x, y, z = [], [], []

# Reading the CSV file
with open("../data/RandomWalk3D.csv") as f:
    reader = csv.reader(f)
    next(reader)  # Skip the header
    for row in reader:
        x.append(int(row[0]))
        y.append(int(row[1]))
        z.append(int(row[2]))

# Create 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the random walk
ax.plot(x, y, z, marker='o', markersize=2, linewidth=1)

# Titles and labels
plt.title("3D Random Walk")
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")

# Show plot
plt.show()
