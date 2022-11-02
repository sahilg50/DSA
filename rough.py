a= 0
b = 0
n = 4
array = [[5,6,7,8],
         [9,4,2,5],
         [1,2,3,4],
         [7,8,9,0]]
for i in range(n):
   a+=array[i][i]
   b+=array[i][n-i-1]
if a>b: print(a-b)
else: print(b-a)