#include <stdio.h>
#define n 4
int a[n][n];
int vis[n];
int stack[10];
int top=-1;

void dfs(int v){
    top++;
    stack[top]=v;
    printf("%d\t",v);
    vis[v]=1;
    for(int i=0; i<n; i++){
        if(a[v][i]==1 && vis[i]==0){//to check whether there is an edge between v and i and i is unvisited
            dfs(i);
        }
    }
    
    int i,e;
    while(top!=-1)
    {
        int f=0;
        e=stack[top];
        for(int i=0;i<n;i++)
        {
            if(a[e][i]==1 && !vis[i])
            {
                dfs(i);
                f=1;
            }
        }
        if(f==0)
        {
            top--;
        }
    }
}

int main(){
 
    int v;
    printf("Enter the matrix : \n");
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    scanf("%d",&a[i][j]);
    }
    }
   
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        
    }
   
    printf("Enter start vertex : ");
    scanf("%d",&v);
   
    printf("DFS TRAVERSAL\n");
    dfs(v);
    printf("\n");
    
    
    return 0;
}