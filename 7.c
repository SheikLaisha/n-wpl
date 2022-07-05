#include<stdio.h>
#include<stdlib.h>
# define MIN(x,y) (x>y)?y:x
int main()
{
    int count=0, ch, i=0, drop=0, orate, inp[10]={0}, nsec, cap, x;
    printf("enter bucket size:");
    scanf("%d",&cap);
    printf("enter output rate:");
    scanf("%d",&orate);
    do{
        printf("enter the packet coming at %d second:",i+1);
        scanf("%d",&inp[i]);
        if(inp[i]>cap)
        {
            printf("Bucket overflow\n");
            printf("packet discarded\n");
            exit(0);
        }
        i++;
        printf("enter 1 to contineu or 0 to quit...");
        scanf("%d",&ch);
    }
    while(ch);
    nsec=i;
    printf("\n Second \t Received \t Sent \t Dropped \t Remained\n");
    for(i=0;count || i<nsec;i++)
    {
        printf(" %d",i+1);
        printf("\t\t %d \t",inp[i]);
        printf("\t %d \t", MIN((inp[i]+count),orate));
        if((x=inp[i]+count-orate)>0)
        {
            if(x>cap)
            {
                count=cap;
                drop=x-cap;
            }
            else
            {
                count=x;
                drop=0;
            }
        }
        else
        {
            drop=0;
            count=0;
        }
        printf("\t %d \t %d \n",drop,count);
    }
    return 0;
    
}
