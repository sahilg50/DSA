def maxUniqueStones(input1, input2, input3):
   
   SUM = input1
   maxi = -10**9
   L = []
   for i in range(input2): L.append(input3[i])

   for i in range(1, input1+1):
      SUM = SUM-i
      count = 0
      if(i not in L):
         for j in range(i+1,input1+1):
            if(j not in L) and (SUM-j>=0):
               SUM-=j
               count+=1
         maxi = max(count, maxi)
   return maxi+1




ans = maxUniqueStones(14,4,[4,6,8,9])
print(ans)