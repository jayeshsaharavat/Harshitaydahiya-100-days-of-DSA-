class Solution:
    def articulationPoints(self, V, adj):
        self.timer = 0
        disc = [-1] * V     
        low = [-1] * V      
        visited = [False] * V
        ap = [False] * V    

        def dfs(u, parent):
            visited[u] = True
            disc[u] = low[u] = self.timer
            self.timer += 1
            children = 0

            for v in adj[u]:
                if v == parent:
                    continue

                if not visited[v]:
                    children += 1
                    dfs(v, u)

                   
                    low[u] = min(low[u], low[v])

                   
                    if parent != -1 and low[v] >= disc[u]:
                        ap[u] = True

                else:
                   
                    low[u] = min(low[u], disc[v])

            
            if parent == -1 and children > 1:
                ap[u] = True

        
        for i in range(V):
            if not visited[i]:
                dfs(i, -1)

       
        result = [i for i in range(V) if ap[i]]
        
        return result if result else [-1]
