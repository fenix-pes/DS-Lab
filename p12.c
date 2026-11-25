#include <stdio.h>

int q[20], top = -1, front = -1, rear = -1;
int a[20][20], vis[20], stack[20];

void add(int item);
int delete1();
void push(int item);
int pop();
void bfs(int s, int n);
void dfs(int s, int n);

int main()
{
    int n, i, j, s, ch;
    char c;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if(n < 1 || n > 19)
    {
        printf("Invalid number of vertices");
        return 0;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%d %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }

    do
    {
        for(i = 1; i <= n; i++)
            vis[i] = 0;

        printf("\nMENU");
        printf("\n1. B.F.S");
        printf("\n2. D.F.S");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        printf("Enter the source vertex: ");
        scanf("%d", &s);

        if(s < 1 || s > n)
        {
            printf("Invalid source vertex");
        }
        else
        {
            switch(ch)
            {
                case 1:
                    printf("\nBFS Traversal: ");
                    bfs(s, n);

                    for(i = 1; i <= n; i++)
                    {
                        if(vis[i] == 0)
                            bfs(i, n);
                    }
                    break;

                case 2:
                    printf("\nDFS Traversal: ");
                    dfs(s, n);

                    for(i = 1; i <= n; i++)
                    {
                        if(vis[i] == 0)
                            dfs(i, n);
                    }
                    break;

                default:
                    printf("Invalid choice");
            }
        }

        printf("\nDo you want to continue (Y/N)? ");
        scanf(" %c", &c);

    } while(c == 'y' || c == 'Y');

    return 0;
}

void bfs(int s, int n)
{
    int p, i;

    front = rear = -1;

    add(s);
    vis[s] = 1;

    while(front <= rear)
    {
        p = delete1();
        printf("%d ", p);

        for(i = 1; i <= n; i++)
        {
            if(a[p][i] != 0 && vis[i] == 0)
            {
                add(i);
                vis[i] = 1;
            }
        }
    }
}

void add(int item)
{
    if(rear == 19)
        printf("Queue full");
    else
    {
        if(rear == -1)
            front = 0;

        q[++rear] = item;
    }
}

int delete1()
{
    if(front > rear || front == -1)
        return 0;

    return q[front++];
}

void dfs(int s, int n)
{
    int i, k;

    top = -1;

    push(s);
    vis[s] = 1;

    while(top != -1)
    {
        k = pop();
        printf("%d ", k);

        for(i = 1; i <= n; i++)
        {
            if(a[k][i] != 0 && vis[i] == 0)
            {
                push(i);
                vis[i] = 1;
            }
        }
    }
}

void push(int item)
{
    if(top == 19)
        printf("Stack overflow");
    else
        stack[++top] = item;
}

int pop()
{
    if(top == -1)
        return 0;

    return stack[top--];
}
