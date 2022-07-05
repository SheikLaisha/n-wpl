#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char res[100];
void sender()
{
    int i,n,len;
    char f[100], l[100];
    printf("enter the number of frames");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the frame");
        scanf("%s",f);
        len=strlen(f);
        sprintf(l, "%d", len);
        strcat(l,f);
        strcat(res,l);
    }
    printf("total data:%s\n",res);
}
void receiver()
{
    int len,i,j;
    printf("data received is:");
    for(i=0;i<strlen(res);i++)
    {
        len=res[i]-'0';
        for(j=i+1;j<=(i+len);j++)
        printf("%c",res[j]);
        i=i+len;
        printf("\n");
    }
}
int main()
{
    sender();
    receiver();
    return 0;
}
