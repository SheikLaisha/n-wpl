#include<stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];
int main()
{
    int dmat[20][20];
    int i,j,k,n,count=0;
    printf("enter the number of nodes");
    scanf("%d",&n);
    printf("enter the cost matrix");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        scanf("%d",&dmat[i][j]);
        dmat[i][i]=0;
        rt[i].dist[j]=dmat[i][j];
        rt[i].from[j]=j;
    }
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = dmat[i][k] + rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }
    while(count != 0);
    {
        for(i=0;i<n;i++)
        {
            printf("\nstate value for router %d is",i+1);
            printf("\n node \t via \t dist");
            for(j=0;j<n;j++)
            {
                printf("\n %d \t %d \t %d ",j+1, rt[i].from[j]+1, rt[i].dist[j]);
            }
        }
        printf("\n\n");
    }
}
