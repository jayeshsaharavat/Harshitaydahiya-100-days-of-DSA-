#include <stdbool.h>

// DFS function
void dfs(int** rooms, int* roomsColSize, bool* visited, int room) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, visited, key);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    // Initialize all rooms as unvisited
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // Start DFS from room 0
    dfs(rooms, roomsColSize, visited, 0);

    // Check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}
