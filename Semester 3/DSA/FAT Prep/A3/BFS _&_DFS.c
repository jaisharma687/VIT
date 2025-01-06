# include <stdio.h>

int stack[10];
int top;
int queue[10];
int front;
int rear;

void push(int x)
{
    stack[++top] = x;
}

int isEmptystack()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int pop()
{
    if(!isEmptystack())
        return stack[top--];
}

void dfs(int n, int graph[][n],int start)
{
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    top=-1;
    visited[start]=1;
    push(start);
    int count = 0;
    while(!isEmptystack())
    {
        int current = pop();
        if(count == n-1)
            printf("%d\n",current+1);
        else
        {
            printf("%d->",current+1);
            count++;
        }
        for(int i=0;i<n;i++)
            if(visited[i]==0 && graph[current][i]==1)
            {
                push(i);
                visited[i] = 1;
            }
    }
}

int isEmptyQueue()
{
    if(rear==-1 || front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if(front==-1)
        front=0;
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void bfs(int n, int graph[][n],int start)
{
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[start]=1;
    front = -1;
    rear = -1;
    enqueue(start);
    int count=0;
    while(!isEmptyQueue())
    {
        int current = dequeue();
        if(count == n-1)
            printf("%d\n",current+1);
        else
        {
            printf("%d->",current+1);
            count++;
        }
        for(int i=0;i<n;i++)
            if(graph[current][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
    }
}

int main()
{
    int V;
    scanf("%d",&V);
    int graph[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    dfs(V,graph,0);
    bfs(V,graph,0);
    return 0;
}