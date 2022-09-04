def GetLowestNumber(num, k):
   
   n = len(num)
   mystack = []
     
   for c in num:
      while (len(mystack) > 0 and k > 0 and mystack[-1] > c):
         mystack.pop()
         k -= 1
 
      if (len(mystack) > 0 or c != '0'):
         mystack.append(c)
 
   while (len(mystack) > 0 and k):
      k -= 1
      mystack.pop()
   if (len(mystack) == 0): return None
 
   while (len(mystack) > 0):
      num = num.replace(num[n - 1] , mystack[-1])
      mystack.pop()
      n -= 1
 
   return num[n:]
 

Str = "765028321"
k = 5
print(GetLowestNumber(Str, k))