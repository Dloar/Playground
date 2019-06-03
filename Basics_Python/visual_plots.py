import numpy as np
import matplotlib.pyplot as plt
from numpy.random import randn
from pandas import DataFrame

# x = [1, 2, 3]
# # y = [3, 3, 3]
# # z = [10, 0, 10]
# # t = [1, 5, 10]
# # plt.plot(x, y)
# # plt.plot(z, t)
# # plt.show()

fig = plt.figure()
ax1 = fig.add_subplot(2, 2, 1)
ax2 = fig.add_subplot(2, 2, 2)
ax3 = fig.add_subplot(2, 2, 3)
plt.plot(randn(50).cumsum(), 'k--')

_ = ax1.hist(randn(100), bins=20, color='g', alpha=0.3)
ax2.scatter(np.arange(30), np.arange(30) + 3 * randn(30))

fig.show()

fig, axes = plt.subplots(2, 3)
print axes

fig, axes = plt.subplots(2, 2, sharex=True, sharey=True)
for i in range(2):
    for j in range(2):
        axes[i, j].hist(randn(500), bins=50, color='k', alpha=0.5)
plt.subplots_adjust(wspace=0, hspace=0)
plt.show()

df = DataFrame(np.random.randn(10, 4).cumsum(0),
               columns=['A', 'B', 'C', 'D'],
               index=np.arange(0, 100, 10))

df.plot()