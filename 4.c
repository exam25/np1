#include<stdio.h>

struct node{
    int from[10];
    int dist[10];
}tbl[10];

void main(){
    int n;
    int a[10][10];
    
    printf("Number of nodes: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            
            if(i == j)
                a[i][j] = 0;
                
            tbl[i].from[j] = i;
            tbl[i].dist[j] = a[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(a[i][j] > (a[i][k] + tbl[k].dist[j])){
                    tbl[i].dist[j] = a[i][k] + tbl[k].dist[j];
                    tbl[i].from[j] = k;
                    a[i][j] = tbl[i].dist[j];
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("State Value for node %d\n", i+1);
        printf("Node\tVia\tDist\n");
        for(int j=0; j<n; j++){
            printf("%d\t%d\t%d\n", j+1, tbl[i].from[j], tbl[i].dist[j]);
        }
    }
}
