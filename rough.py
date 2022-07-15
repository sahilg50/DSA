class Graph: 
   def __init__(self, V): 
      self.V = V  
      self.adj = [[] for i in range(V+1)] 
      
   def addEdge(self, u, v): 
      self.adj[u].append(v) 
      

   def countPaths(self, s, d): 
      del self.adj[0]
      visited = [False] * self.V 
      pathCount = [0]  
      self.countPathsUtil(s, d, visited, pathCount)  
      return pathCount[0] 
    
   def countPathsUtil(self, u, d, visited, pathCount): 
      visited[u] = True
      if (u == d): pathCount[0] += 1
      else: 
         i = 0
         while i < len(self.adj[u]): 
            if (not visited[self.adj[u][i]]):  
               self.countPathsUtil(self.adj[u][i], d, visited, pathCount) 
               i += 1
      
      visited[u] = False

if __name__ == '__main__': 
   N = 10
   g = Graph(N)  
   for i in range(2, N+1):
      for j in range(1, int(N/2)):
         if(i%j==0): g.addEdge(i,j)

   print(g.countPaths(1, 10)) 