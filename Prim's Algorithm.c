#include <stdio.h>

int main()
{
 int n;
 printf("Enter number of vertices\n");
 scanf("%d",&n);
 int a[n][n],u,v,i,j,total=0,min=999,visited[n];
 
 
 printf("Enter vertices\n");

 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]==0)
        {
           a[i][j]=999;
        }
    }
 }
 
 for(i=0;i<n;i++)
 {
    visited[i]=0;
 }
 
 //visited[0]=1;
 for(i=0;i<n;i++)
 {
    min=999;
    for(j=0;j<n;j++)
    {
       if(a[i][j]<min)
       {
           min=a[i][j];
           u=i;
           v=j;
       }
    }
 
    if(visited[u]==0 || visited[v]==0)
    {
       total=total+min;
       // cout<<"The edge is "<<u<<" "<<v<<" with cost "<<min<<endl;
       printf("the edge id %d %dwith cost %d \n",u,v,min) ;
       visited[u]=1;
       visited[v]=1;
    }
    a[u][v]=a[v][u]=999;
 }
 
 printf("The minimum cost of Spanning tree is %d : \n",total);
 return 0;
}