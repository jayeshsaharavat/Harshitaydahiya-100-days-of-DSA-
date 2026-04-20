class Solution:
    def kosaraju(self, V, edges):
        
        # Step 0: Convert edges -> adjacency list
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
        
        stack = []
        visited = [False] * V
        
        # Step 1: DFS to fill stack
        def dfs(node):
            visited[node] = True
            for nei in adj[node]:
                if not visited[nei]:
                    dfs(nei)
            stack.append(node)
        
        for i in range(V):
            if not visited[i]:
                dfs(i)
        
        # Step 2: Transpose graph
        transpose = [[] for _ in range(V)]
        for u in range(V):
            for v in adj[u]:
                transpose[v].append(u)
        
        # Step 3: DFS on reversed graph
        visited = [False] * V
        
        def dfs_rev(node):
            visited[node] = True
            for nei in transpose[node]:
                if not visited[nei]:
                    dfs_rev(nei)
        
        # Step 4: Count SCC
        count = 0
        while stack:
            node = stack.pop()
            if not visited[node]:
                dfs_rev(node)
                count += 1
        
        return count
