class Solution:
    def tsp(self, cost):
        n = len(cost)
        
        dp = [[-1] * n for _ in range(1 << n)]
        
        def solve(mask, pos):
            if mask == (1 << n) - 1:
                return cost[pos][0]
            
            if dp[mask][pos] != -1:
                return dp[mask][pos]
            
            ans = float('inf')
            
            for city in range(n):
                if (mask & (1 << city)) == 0:
                    new_ans = cost[pos][city] + solve(mask | (1 << city), city)
                    ans = min(ans, new_ans)
            
            dp[mask][pos] = ans
            return ans
        
        return solve(1, 0)
