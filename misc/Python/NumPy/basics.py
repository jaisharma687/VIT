import numpy as np
a = np.array([1,2,3],dtype='int16')
print(a)
b = np.array([[1,2,3,4,5,6],[7,8,9,4,5,6]])
print(b)
c = np.array([[[1,2],[3,4]],[[5,6],[7,8]]])
print(c)
# Get dimension
print(a.ndim)
print(b.ndim)
print(c.ndim)
# Get Shape
print(a.shape)
print(b.shape)
print(c.shape)
# Get Type
print(a.dtype)
print(b.dtype)
print(c.dtype)
#Get Size
print(a.itemsize)
print(b.itemsize)
print(c.itemsize)
# Get total size
print(a.itemsize*a.size)
print(b.itemsize*b.size)
print(c.itemsize*c.size)
print(a.nbytes)
print(b.nbytes)
print(c.nbytes)
# Get Specific element
print(b[1,4])
print(b[1,-3])
print(c[0,1,1])
# Get Specific row
print(b[1,:])
print(c[1,1,:])
# Get Specific column
print(b[:,3])
# Array Slicing
print(b[0,1:4:2])
#1:4:2: 1 means starting index, 4 means end index(exclusive) and 2 means the skip
# Changing an element
b[1,4] = 99
print(b)
b[:,3] = 77
print(b)
c[:,1,:] = [[9,9],[8,8]]
print(c)

# Initializing Different Types of Arrays
# All 0s matrix
d = np.zeros((4,3,3),dtype = 'int32')
print(d)
# All 1s matrix
e = np.ones((4,3,3))
print(e)
# Any other number
f = np.full((4,5,3),45,dtype = 'float32')
print(f)
# Any other number full_like
print(np.full_like(b,5))
print(np.full(b.shape,5))
# Random decimal number
print(np.random.rand(2,4))
print(np.random.random_sample(c.shape))
# Random integers value
print(np.random.randint(4,size=(4,6,7)))
# Identity matrix
print(np.identity(4))
# Repeat an array
arr = np.array([[1,2,4]])
r1 = np.repeat(arr,4,axis = 0)
print(r1)
r2 = np.repeat(arr,4,axis = 1)
print(r2)