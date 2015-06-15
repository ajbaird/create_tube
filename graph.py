import numpy as np 
import matplotlib.pyplot as plt 

array = np.loadtxt('tube_points.vertex', skiprows=1)

print np.shape(array)

plt.plot(array[:,0], array[:,1],'bD')
plt.show()
