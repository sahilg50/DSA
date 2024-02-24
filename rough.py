class Solution():

    #Method to perform DFS
    def dfs(self, node,p=-1):
        self.visited[node]=1
        self.parent[node]=p
        self.temporary.append(node)

        # Iterate the connecting nodes
        for i in self.v[node]:
                
            #if already visited
            if(self.visited[i]==1):

                sum=i
                #calculating cycle sum
                while(node!=i):
                    sum+=node
                    node=self.parent[node]
                
                # if cycle found
                if(node==i): return sum

                return -1
            
            elif(self.visited[i]==0):
                z=self.dfs(i,node)
                if(z!=-1): return z
            
        return -1

    #Function to find cycle sum
    def largestSumCycle(self, N, Edge):
        result=-1
        self.visited=[0]*N
        self.v=[[] for i in range(N)]
        self.parent = [0]*N
        self.temporary = []

        #create  graph
        for i in range(N):
            if(Edge[i]!=-1):
                self.v[i].append(Edge[i])

        #iterate all nodes in graph
        for i in range(N):
            
            #if a node not visited, then perform dfs
            if(~self.visited[i]):
                result=max(result,self.dfs(i))

                for j in self.temporary: self.visited[j]= 2
                
                self.temporary.clear()

        return result
    
if __name__ == '__main__':

    T = input()
    N = int(input())
    Edge = input().split(' ')

    Arr = []
    for i in range(len(Edge)):
        Arr.append(int(Edge[i]))

    Edge = Arr
    
    obj = Solution()

    result = obj.largestSumCycle(N, Edge)

    print(result)