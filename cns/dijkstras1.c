

#include <stdio.h>
#include <limits.h>

#define SIZE 7 // Define the size of the graph

// Structure to represent the graph
typedef struct {
    int adjMatrix[SIZE][SIZE];
    char vertexData[SIZE];
} Graph;

// Function to initialize the graph
void initGraph(Graph *g) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            g->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int u, int v, int weight) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        g->adjMatrix[u][v] = weight;
        g->adjMatrix[v][u] = weight; // Undirected graph
    }
}

// Function to add vertex data
void addVertexData(Graph *g, int vertex, char data) {
    if (vertex >= 0 && vertex < SIZE) {
        g->vertexData[vertex] = data;
    }
}

// Function to perform Dijkstra's algorithm
void dijkstra(Graph *g, char startVertexData) {
    int startVertex = -1;
    for (int i = 0; i < SIZE; i++) {
        if (g->vertexData[i] == startVertexData) {
            startVertex = i;
            break;
        }
    }

    if (startVertex == -1) {
        printf("Start vertex not found.\n");
        return;
    }

    int distances[SIZE];
    int visited[SIZE];

    // Initialize distances and visited arrays
    for (int i = 0; i < SIZE; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[startVertex] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < SIZE - 1; count++) {
        int minDistance = INT_MAX;
        int u = -1;

        // Find the vertex with the minimum distance
        for (int i = 0; i < SIZE; i++) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                u = i;
            }
        }

        if (u == -1) {
            break; // All remaining vertices are unreachable
        }

        visited[u] = 1;

        // Update the distances of the adjacent vertices
        for (int v = 0; v < SIZE; v++) {
            if (g->adjMatrix[u][v] != 0 && !visited[v]) {
                int alt = distances[u] + g->adjMatrix[u][v];
                if (alt < distances[v]) {
                    distances[v] = alt;
                }
            }
        }
    }

    // Print the distances
    printf("\nDijkstra's Algorithm starting from vertex %c:\n", startVertexData);
    for (int i = 0; i < SIZE; i++) {
        if (distances[i] == INT_MAX) {
            printf("Distance from %c to %c: INF\n", startVertexData, g->vertexData[i]);
        } else {
            printf("Distance from %c to %c: %d\n", startVertexData, g->vertexData[i], distances[i]);
        }
    }
}

int main() {
    Graph g;
    initGraph(&g);

    // Adding vertex data
    addVertexData(&g, 0, 'A');
    addVertexData(&g, 1, 'B');
    addVertexData(&g, 2, 'C');
    addVertexData(&g, 3, 'D');
    addVertexData(&g, 4, 'E');
    addVertexData(&g, 5, 'F');
    addVertexData(&g, 6, 'G');

    // Adding edges
    addEdge(&g, 3, 0, 4);  // D - A, weight 4
    addEdge(&g, 3, 4, 2);  // D - E, weight 2
    addEdge(&g, 0, 2, 3);  // A - C, weight 3
    addEdge(&g, 0, 4, 4);  // A - E, weight 4
    addEdge(&g, 4, 2, 4);  // E - C, weight 4
    addEdge(&g, 4, 6, 5);  // E - G, weight 5
    addEdge(&g, 2, 5, 5);  // C - F, weight 5
    addEdge(&g, 2, 1, 2);  // C - B, weight 2
    addEdge(&g, 1, 5, 2);  // B - F, weight 2
    addEdge(&g, 6, 5, 5);  // G - F, weight 5

    // Run Dijkstra's algorithm
    dijkstra(&g, 'D');

    return 0;
}


//output

Dijkstra's Algorithm starting from vertex D:
Distance from D to A: 4
Distance from D to B: 8
Distance from D to C: 6
Distance from D to D: 0
Distance from D to E: 2
Distance from D to F: 10
Distance from D to G: 7
