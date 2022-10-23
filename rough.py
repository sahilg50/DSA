def specialNumber(n):
   n = n*2
   m = {}
   for i in range(1,10**8):
      m.update({i: i*(i+1)})

   ans = "NO"
   for i in m:
      if(n/m[i] in m.values()):
         ans = "YES"
         break
   
   return ans

print(specialNumber(256))