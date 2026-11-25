#include <stdio.h>

void input();
void output(int c[]);
void setunion();
void intersection();
void difference();

int a[9] = {0,0,0,0,0,0,0,0,0};
int b[9] = {0,0,0,0,0,0,0,0,0};

int main()
{
    int ch, wish;

    do
    {
        printf("\nMENU\n");
        printf("1. Input\n");
        printf("2. Union\n");
        printf("3. Intersection\n");
        printf("4. Difference\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                input();
                break;

            case 2:
                setunion();
                break;

            case 3:
                intersection();
                break;

            case 4:
                difference();
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &wish);

    } while(wish == 1);

    return 0;
}

void input()
{
    int n, x, i;

    printf("Enter size of the 1st set: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if(x >= 1 && x <= 9)
            a[x-1] = 1;
    }

    printf("Enter size of the 2nd set: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if(x >= 1 && x <= 9)
            b[x-1] = 1;
    }

    printf("\n1st set: ");
    for(i = 0; i < 9; i++)
        printf("%d", a[i]);

    printf("\n2nd set: ");
    for(i = 0; i < 9; i++)
        printf("%d", b[i]);
}

void output(int c[])
{
    int i;

    printf("\nSet is: ");

    for(i = 0; i < 9; i++)
    {
        if(c[i] != 0)
            printf("%d ", i + 1);
    }
}

void setunion()
{
    int i, c[9];

    for(i = 0; i < 9; i++)
    {
        if(a[i] != b[i])
            c[i] = 1;
        else
            c[i] = a[i];
    }

    printf("\nUnion bit stream: ");
    for(i = 0; i < 9; i++)
        printf("%d", c[i]);

    output(c);
}

void intersection()
{
    int i, c[9];

    for(i = 0; i < 9; i++)
    {
        if(a[i] == b[i])
            c[i] = a[i];
        else
            c[i] = 0;
    }

    printf("\nIntersection bit stream: ");
    for(i = 0; i < 9; i++)
        printf("%d", c[i]);

    output(c);
}

void difference()
{
    int i, c[9];

    for(i = 0; i < 9; i++)
    {
        if(a[i] == 1 && b[i] == 0)
            c[i] = 1;
        else
            c[i] = 0;
    }

    printf("\nDifference bit stream: ");
    for(i = 0; i < 9; i++)
        printf("%d", c[i]);

    output(c);
}
