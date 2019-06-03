import numpy as np
data1 = [6, 7.5, 8, 0, 1]
arr1 = np.array(data1)

data2 = [[1, 2, 3, 4], [5, 6, 7, 8]]
arr2 = np.array(data2)

print arr2
print arr2.ndim
print arr2.shape

print arr1.dtype
print arr2.dtype

print np.zeros(10)

print np.zeros((3, 6))

print np.empty((2, 3, 2)) #np.empty does not

print np.arange(15)

print np.identity(5)

# Arrays
aar1 = np.array([1, 2, 3], dtype = np.float64)
arr2 = np.array([1, 2, 3], dtype=np.int32)
print arr1.dtype
print arr2.dtype

arr = np.array([1, 2, 3, 4, 5])
print arr.dtype

float_arr = arr.astype(np.float)
print float_arr.dtype

arr = np.array([3.7, -1.2, -2.6, 0.5, 12.9, 10.1])
print arr

print arr.astype(np.int32)

numeric_strings = np.array(['1.25', '-9.6', '42'], dtype=np.string_)
print numeric_strings
print numeric_strings.astype(float)

int_array = np.arange(10)
print int_array
calibers = np.array([.22, .270, .357, .380, .44, .50], dtype=np.float64)
print calibers
print int_array.astype(calibers.dtype) # I can simply take a dtype from another vector or table and concerte the type

empty_uint32 = np.empty(8, dtype= 'u4')
print empty_uint32

arr = np.array([[1., 2., 3.], [4., 5., 6.]])
print arr

print arr * arr

print 1/ arr
print arr ** 0.5 #Square root

arr = np.arange(10)

print arr[5]
print arr[4:6]

arr[4:7] = 12
print arr

arr_slice = arr[5:8] # tohle nevytvori novy vektro, ale pouze podmnozinu ktera je porad vazana na puvodni
arr_copy = arr[5:8].copy() # tohle vytvori novy vekror
print 'Arr copy'
arr_copy[:] = 12
print 'Arr slice'
arr_slice[1] = 12345
print arr

arr_slice[:] = 64
print arr

arr2d = np.array([[1,2,3],[4, 5, 6], [7, 8, 9]])

print arr2d[2]
print arr2d[0][2]
print arr2d[0, 2]

arr3d = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
print arr3d
print arr3d[0]
print arr3d[0, 1, 0]

old_values = arr3d[0].copy()

arr3d[0] = 42
print arr3d

arr3d[0] = old_values
print arr3d

print arr3d[1, 0]

print arr[1:6]
print arr2d
print arr2d[:2]

print arr2d[:2, 1:]

names = np.array(['Bob', 'Joe', 'Will', 'Bob', 'Will', 'Joe', 'Joe'])
print names
data = np.random.rand(7,4)
print data

print "Boolian vectors"
print names == 'Bob'
print data[names == 'Bob']
print data[names == 'Bob', 2:]
print data[names == 'Bob', 3]
print names != 'Bob'
print data[(names != 'Bob')]
mask = (names == 'Bob') | (names == "Will") #Use of pipe
print mask
print data[mask]

data[names != 'Joe'] = 7
print data

arr = np.empty((8, 4))
for i in range(8):
    arr[i] = i
print arr

print arr[[4, 3, 0, 6]]
print arr[[-3, -5, -7]]

arr = np.arange(32).reshape((8, 4))
print arr

arr = np.arange(15).reshape((3, 5))
print arr
print arr.T

arr = np.random.rand(6, 3)
print arr
print np.dot(arr.T, arr)

#Multiple dimensions, 3 +

arr = np.arange(16).reshape((2, 2, 4))
print arr
print arr.transpose(1,0,2)
print arr.swapaxes(1,2)

arr = np.arange(10)
print np.sqrt(arr)
print np.exp(arr)

x = np.random.rand(8)
print x
y = np.random.rand(8)
print y
print np.maximum(x, y) # element wise maximum

arr = np.random.rand(7) * 5
print arr
print np.modf(arr)

print "Data processing using arrays"

points = np.arange(-5, 5, 0.01)
xs, ys = np.meshgrid(points, points)
print ys
print xs

import matplotlib.pyplot as plt

z = np.sqrt(xs ** 2 + ys ** 2)
print z

plt.imshow(z, cmap=plt.cm.gray)
plt.colorbar()
plt.title("Image plot of $\sqrt{x^2 + y^2}$ for grid values")
plt.show()

xarr = np.array((1.1, 1.2, 1.3, 1.4, 1.5))
yarr = np.array([2.1, 2.2, 2.3, 2.4, 2.5])
cond = np.array([True, False, True, True, False])

result = [(x if c else y)
          for x, y, c, in zip(xarr, yarr, cond)]
print result

result = np.where(cond, xarr, yarr) # If cond == T, then xarr else yarr
print result

arr = np.random.rand(4,4)
print arr

# results = []
# for i in range(n):
#     if cond1[i] and cond[2]:
#         result.append(0)
#     elif cond1[i]:
#         result.append(1)
#     elif cond2[i]:
#         result.append(2)
#     else:
#         result.append(3)

# can be writen as loop

# np.where(cond1 & cond2, 0,
#          np.where(cond1, 1,
#                   np.where(cond2, 2, 3))


#Mathematical and statistical mnethods
arr = np.random.rand(5,4)

print "Mean"
print arr.mean()
print "Numpy mean"
print np.mean(arr)
print arr.sum()
print arr.mean(axis=1)
print arr.sum(0)

arr = np.array([[0,1,2],[3,4,5],[6,7,8]])

print arr.cumsum(0)
print arr.cumprod(1)

#Boolean arrays
print "Checkpoint"
arr = np.random.randn(100)
print (arr > 0).sum()

bools = np.array([False, False, True, False])

print bools.any()
print bools.all()

print "Sorting"
arr = np.random.rand(8)
print arr
print arr.sort()

arr = np.random.rand(5, 3)
print arr
arr.sort(1)
large_arr = np.random.rand(1000)
large_arr.sort()

print large_arr[int(0.05 * len(large_arr))]

print "Unique and othe rset logic"
names = np.array(['Bob', 'Joe', 'Will', 'Bob', 'Will', 'Joe', 'Joe'])
print np.unique(names)

ints = np.array([3, 3, 3, 2, 2, 1, 1, 1, 4, 4])
print np.unique(ints)
print sorted(set(names))

values = np.array([6, 0, 0, 3, 2, 5, 6])
print np.in1d(values, [2, 3, 6]) # Is any if the value in the vector

print "Storing in binary"

arr = np.arange(10)
print np.save("some_array", arr)
print np.load('some_array.npy')

np.savez('array_archive.npz', a=arr, b=arr)
arch = np.load('array_archive.npz')
print arch['b']

print "Linear algebra."
x = np.array([[1., 2., 3.],[4., 5., 6.]])
print x
y = np.array([[6., 23.], [-1, 7],[8, 9]])
print y

print x.dot(y) # it is same as np.dot(x, y)
print np.dot(x, np.ones(3))

from numpy.linalg import inv, qr
X = np.random.rand(5, 5)
mat = X.T.dot(X)

print inv(mat)
print mat.dot(inv(mat))

q, r = qr(mat)

print "Random Numbers"

sample  = np.random.rand(4, 4)
print sample

from random import normalvariate

N = 1000000
import timeit
# print timeit.timeit(samples = [normalvariate(0,1) for _ in xrange(N)])
# print timeit.timeit(np.random.normal(size=N))

print "Random Walks"
import random
position = 0
walk = [position]
steps = 1000
for i in xrange(steps):
    step = 1 if random.randint(0, 1) else -1
    position += step
    walk.append(position)
print walk

nsteps = 1000
draws = np.random.randint(0, 2, size=nsteps)
steps = np.where(draws > 0, 1, -1)
walk = steps.cumsum()

print walk.min()
print walk.max()

nwalks = 5000
nsteps = 1000

draws = np.random.randint(0, 2, size=(nwalks, nsteps))

steps = np.where(draws > 0, 1, -1)
walks = steps.cumsum(1)
print walks
print walks.max()
print walks.min()

hits30 = (np.abs(walks) >= 30).any(1)
print hits30
print hits30.sum() #Numbers that hits 30 or -30

crossing_times = (np.abs(walks[hits30]) >= 30).argmax(1)
print crossing_times
print crossing_times.mean()

steps = np.random.normal(loc=0, scale=.25, size=(nwalks, nsteps))
print steps

print "Starting with pandas."
from pandas import Series, DataFrame
import pandas as pd

obj = Series([4, 7, -5, 3])
print obj
print obj.values
print obj.index



print " **** ***** DONE ***** ****"











