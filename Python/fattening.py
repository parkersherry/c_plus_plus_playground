import matplotlib.pyplot as plt
import numpy as np

# make the data

x_square = [3, 3.2, 4.5, 5]
y_square = [4, 5, 3.5, 6]

x_tri = [3.8, 4, 5.2]
y_tri = [4.8, 3.8, 4.7]

# plot
fig, ax = plt.subplots()

# plot the points
ax.scatter(x_square, y_square, marker='s', c='white', edgecolors='black', vmin=0, vmax=100)
ax.scatter(x_tri, y_tri, marker='^', c='black', vmin=0, vmax=100)

# plot the disks
ax.scatter(x_tri, y_tri, s=8500, c='#ffa1aa', alpha=0.2, vmin=0, vmax=100)

ax.set(xlim=(0, 8), xticks=np.arange(1, 8),
       ylim=(0, 8), yticks=np.arange(1, 8), alpha=0)
plt.axis('off')

plt.show()