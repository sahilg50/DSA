import numpy as np
def CountOccurrences(str) :
   n = len(str)
   freq = np.zeros(26, dtype = np.int)
   for i in range(0, n) :
      freq[ord(str[i]) - ord('a')] += 1
   ans = ""
   for i in range(0, n) :
      if (freq[ord(str[i])- ord('a')] != 0) :
         ans+=(str[i]  + freq[ord(str[i]) - ord('a')])
         freq[ord(str[i]) - ord('a')] = 0

   return ans

Countt("Sahil")