import numpy as np
import matplotlib.pyplot as plt

cpus = [1, 2, 8, 16, 64, 128]
time = 1/np.array([0.619, 0.3846, 0.3237,0.2894, 0.1479, 0.08328])
fig, ax = plt.subplots(1,1)
ax.scatter(cpus, time)
ax.plot(time, time, c = "red")
ax.set_ylabel("1/time")
ax.set_xlabel("cpus")

plt.savefig('plot.png')
