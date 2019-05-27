#include<stdio.h>

// global variables
int queue[50],f=0,r=-1;

void read_matrix(int adj[20][20],int n);
void print_matrix(int adj[20][20],int n);
void bfs(int sv,int adj[20][20],int n,int *bfs_visited);
void dfs(int sv,int adj[20][20],int n,int *dfs_visited);

void read_matrix(int adj[20][20], int n){
    printf("Enter 1 if an edge exists else 0 for given %d edges: \n",n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n");
}

void print_matrix(int adj[20][20], int n){
    printf("Matrix entered: \n");
    for(int i=0;i<n;i++){
        printf("\t");
        for(int j=0;j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bfs(int sv, int adj[20][20], int n, int *bfs_visited){
    queue[++r] = sv;
    bfs_visited[sv] = 1;
    int v = queue[sv];
    while(f<=r){    //while queue is not empty 
        for(int i=0;i<n;i++){
            if(adj[v][i] && !bfs_visited[i]){
                queue[++r] = i;
                bfs_visited[i] = 1;
            }
        }
        printf("%d ", queue[f++]);
        v = queue[f];
    }
    printf("\n");
}

void dfs(int sv, int adj[20][20], int n, int *dfs_visited){
    printf("%d ",sv);
    dfs_visited[sv] = 1;
    for(int i=0;i<n;i++){
        if(adj[i][sv] && !dfs_visited[i]){
            dfs(i,adj,n,dfs_visited);
        }
    }
}

//DFS and BFS can be performed on connected graphs (cyclic or acyclic) only.
void main(){
    int adj[20][20] = {0};
    int bfs_visited[20] = {0};
    int dfs_visited[20] = {0};
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    read_matrix(adj,n);
    print_matrix(adj,n);
    printf("BFS Traversal: ");
    bfs(0,adj,n,bfs_visited);       //0 is the start vertex.
    printf("DFS Traversal: ");
    dfs(0,adj,n,dfs_visited);
    printf("\n");
    return;
}

