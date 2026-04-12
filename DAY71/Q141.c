#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100]; // max size
int size;

// Initialize hash table
void init() {
    for(int i = 0; i < size; i++)
        table[i] = EMPTY;
}

// Hash function
int hashFunction(int key) {
    return key % size;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hashFunction(key);

    for(int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if(table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
void search(int key) {
    int h = hashFunction(key);

    for(int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if(table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &size);
    scanf("%d", &q);

    init();

    while(q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0)
            insert(key);
        else if(strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}
