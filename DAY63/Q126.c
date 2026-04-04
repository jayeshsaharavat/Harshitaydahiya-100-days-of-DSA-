void dfs(int** image, int imageSize, int* imageColSize, 
         int r, int c, int origColor, int newColor) {
    
    // Boundary check
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[0])
        return;

    // If not same color, stop
    if (image[r][c] != origColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Explore neighbors (4 directions)
    dfs(image, imageSize, imageColSize, r+1, c, origColor, newColor);
    dfs(image, imageSize, imageColSize, r-1, c, origColor, newColor);
    dfs(image, imageSize, imageColSize, r, c+1, origColor, newColor);
    dfs(image, imageSize, imageColSize, r, c-1, origColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, 
                int sr, int sc, int color, int* returnSize, 
                int** returnColumnSizes) {
    
    int origColor = image[sr][sc];

    // Edge case: if color is same, no need to process
    if (origColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    // Perform DFS
    dfs(image, imageSize, imageColSize, sr, sc, origColor, color);

    // Return result
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}
