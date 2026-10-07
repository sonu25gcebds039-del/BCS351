#include <stdio.h> 
#define MAX_NODES 100 
struct Graph { 
    int vertices; 
    int adjacencyMatrix[MAX_NODES][MAX_NODES]; 
}; 
void initGraph(struct Graph *graph, int vertices) { 
    graph->vertices = vertices; 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            graph->adjacencyMatrix[i][j] = 0; 
        } 
    } 
} 
void addEdge(struct Graph *graph, int source, int destination) { 
    graph->adjacencyMatrix[source][destination] = 1; 
    graph->adjacencyMatrix[destination][source] = 1; 
} 
void printGraph(struct Graph *graph) { 
    printf("Adjacency Matrix:\n"); 
    for (int i = 0; i < graph->vertices; i++) { 
        for (int j = 0; j < graph->vertices; j++) { 
            printf("%d ", graph->adjacencyMatrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
int main() { 
    struct Graph graph; 
    int numVertices, numEdges, source, destination; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &numVertices); 
    initGraph(&graph, numVertices); 
    printf("Enter the number of edges: "); 
    scanf("%d", &numEdges); 
    for (int i = 0; i < numEdges; i++) { 
        printf("Enter edge (source destination): "); 
        scanf("%d %d", &source, &destination); 
        addEdge(&graph, source, destination); 
    } 
    printGraph(&graph); 
    return 0; 
}