#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add an edge in the reverse direction as well
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* currentNode = graph->adjList[i];
        printf("Adjacency list of vertex %d:\n", i);
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

void deleteGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* currentNode = graph->adjList[i];
        while (currentNode != NULL) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Graph created with %d vertices and %d edges.\n", numVertices, numEdges);
    displayGraph(graph);

    // Delete the graph to free allocated memory
    deleteGraph(graph);

    return 0;
}
