#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#define VERTICES 5

int visited[VERTICES]={0};
int graph[VERTICES][VERTICES] = {{0, 1, 1, 0, 0}, 
                                {1, 0, 0, 1, 0}, 
                                {1, 0, 0, 1, 1}, 
                                {0, 1, 1, 0, 1}, 
                                {0, 0, 1, 1, 0}};

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);

    for (uint16_t i = 0; i < VERTICES; i++) {
        if (graph[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    uint16_t v;
    printf("Give node to begin dfs: ");
    scanf("%"SCNu16, &v);
    dfs(v);

    return 0;
}