int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    
    int queue[rows * cols][2];
    int front = 0, rear = 0;
    
    int fresh = 0;
    
    // Directions: up, down, left, right
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    // Step 1: Push all rotten oranges into queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    // If no fresh oranges
    if (fresh == 0) return 0;
    
    int minutes = 0;
    
    // Step 2: BFS
    while (front < rear) {
        int size = rear - front;
        int rottenThisMinute = 0;
        
        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    
                    fresh--;
                    rottenThisMinute = 1;
                }
            }
        }
        
        // Only increment time if something rotted
        if (rottenThisMinute) minutes++;
    }
    
    // Step 3: Check if fresh oranges remain
    if (fresh > 0) return -1;
    
    return minutes;
}
