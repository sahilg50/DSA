class Solution():

    # Function to find maximum weighted node
    def maxWeight(self, N, Edge):

        weight = {}
        for i in range(N): 
            if Edge[i] not in weight: 
                weight[Edge[i]] = 0
                weight[Edge[i]] += i

            else: weight[Edge[i]] += i
        
        maxWeight = 0
        result = -1
        for key, value in weight:
            if (value > maxWeight):
                maxWeight = value
                result = key
            
        return result
    
            

    
if __name__ == '__main__':

    T = int(input())

    for i in range(T):
        N = int(input())
        Edge = input().split(' ')
    
        obj = Solution()
        result = obj.maxWeight(N, Edge)

        print(result)
