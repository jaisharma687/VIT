# include <stdio.h>
# include <stdlib.h>

# define MAX 100

int queue[MAX];
int top = -1;
int visited[MAX];
int stack[MAX];

void initialize(int vertices) 
{
    for (int i = 0; i < vertices; i++) 
    {
        visited[i] = 0;
    }
}

void enqueue(int vertex) 
{
    if (top == MAX - 1) 
    {
        printf("Queue is full.\n");
        return;
    }
    queue[++top] = vertex;
}

int dequeue() 
{
    if (top == -1) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int vertex = queue[0];
    for (int i = 0; i < top; i++) 
    {
        queue[i] = queue[i + 1];
    }
    top--;
    return vertex;
}

void push(int vertex) 
{
    if (top == MAX - 1) 
    {
        printf("Stack is full.\n");
        return;
    }
    stack[++top] = vertex;
}

int pop() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int vertex = stack[top];
    top--;
    return vertex;
}

void bfs(int vertices, int graph[MAX][MAX], int start) 
{
    initialize(vertices);
    enqueue(start);
    visited[start] = 1;
    int count = 0;
    while (top != -1) 
    {
        int current = dequeue();
        if (count == vertices - 1)
            printf("%d ", current + 1);
        else 
        {
            printf("%d->", current + 1);
            count++;
        }
        for (int i = 0; i < vertices; i++) 
        {
            if (graph[current][i] == 1 && !visited[i]) 
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int vertices, int graph[MAX][MAX], int start) 
{
    initialize(vertices);
    top = -1;
    int count = 0;
    push(start);
    visited[start] = 1;
    while (top != -1) 
    {
        int current = pop();
        if (count == vertices - 1) 
            printf("%d ", current + 1);
        else 
        {
            printf("%d->", current + 1);
            count++;
        }
        for (int i = 0; i < vertices; i++) 
        {
            if (graph[current][i] == 1 && visited[i]==0) 
            {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() 
{
    int vertices, i, j;
    scanf("%d", &vertices);
    int graph[MAX][MAX];
    for (i = 0; i < vertices; i++) 
    {
        for (j = 0; j < vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int start_vertex = 0;
    bfs(vertices, graph, start_vertex);
    dfs(vertices, graph, start_vertex);
    return 0;
}
