import numpy as np 
import matplotlib.pyplot as plt 

array = np.loadtxt('tube_points.txt')

print np.shape(array)

plt.plot(array[:,0], array[:,1])
plt.show()
