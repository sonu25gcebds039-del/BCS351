#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int vertex; 
    struct Node* next; 
}; 
struct Graph { 
    int vertices; 
    struct Node** adjList; 
}; 
struct Node* createNode(int v) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
} 
struct Graph* createGraph(int vertices) { 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->vertices = vertices; 
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*)); 
    for (int i = 0; i < vertices; ++i) { 
        graph->adjList[i] = NULL; 
    } 
    return graph; 
} 
void addEdge(struct Graph* graph, int src, int dest) { 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjList[src]; 
    graph->adjList[src] = newNode; 
    newNode = createNode(src); 
    newNode->next = graph->adjList[dest]; 
    graph->adjList[dest] = newNode; 
} 
void bfs(struct Graph* graph, int startVertex) { 
    int* visited = (int*)malloc(graph->vertices * sizeof(int)); 
    for (int i = 0; i < graph->vertices; ++i) { 
        visited[i] = 0; 
    } 
    struct Node* queue = NULL; 
    visited[startVertex] = 1; 
    printf("BFS Traversal from vertex %d: ", startVertex); 
    struct Node* temp = createNode(startVertex); 
    enqueue(&queue, temp); 
    while (!isEmpty(queue)) { 
        startVertex = dequeue(&queue); 
        printf("%d ", startVertex); 
        struct Node* trav = graph->adjList[startVertex]; 
        while (trav) { 
            int adjVertex = trav->vertex; 
            if (visited[adjVertex] == 0) { 
                visited[adjVertex] = 1; 
                struct Node* newNode = createNode(adjVertex); 
                enqueue(&queue, newNode); 
            } 
            trav = trav->next; 
        } 
    } 
    printf("\n"); 
} 
void enqueue(struct Node** head, struct Node* newNode) { 
    if (*head == NULL) { 
        *head = newNode; 
    }  
    else { 
        struct Node* temp = *head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
int dequeue(struct Node** head) { 
    int val = (*head)->vertex; 
    *head = (*head)->next; 
    return val; 
} 
int isEmpty(struct Node* head) { 
    return (head == NULL); 
} 
int main() { 
    int vertices, edges, src, dest; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &vertices); 
    struct Graph* graph = createGraph(vertices); 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
    for (int i = 0; i < edges; ++i) { 
        printf("Enter edge (source destination): "); 
        scanf("%d %d", &src, &dest); 
        addEdge(graph, src, dest); 
    } 
    int startVertex; 
    printf("Enter the starting vertex for BFS: "); 
    scanf("%d", &startVertex); 
    bfs(graph, startVertex); 
    return 0; 
}