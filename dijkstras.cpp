#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 9999
void dijkstras(int [5][5],int,int);
int main(){
    cout<<"dijstras algorithm program is started\n";
    int adj[5][5]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
    int n=5;
    int u=0;
    dijkstras(adj,n,u);
    return 0;
}
void dijkstras(int adj[5][5],int n,int startnode){
    int pred[5],visited[5],cost[5][5];
    int distance[5],i,j,count,mindistance,nextnode;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]!=0)    
                cost[i][j]=adj[i][j];
            else
                cost[i][j]=INFINITY;
        }
    }

    // cout<<cost[2][0]<<"\n";
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        visited[i]=0;
        pred[i]=startnode;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1){
        mindistance=INFINITY;
        for(i=0;i<n;i++){
            if(!visited[i] && distance[i]<mindistance){
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                if(distance[nextnode]+cost[nextnode][i]<distance[i]){
                    distance[i] = distance[nextnode]+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;
    }

    for(i=0;i<n;i++)
   if(i!=startnode) {
      cout<<"\nDistance of node"<<i<<"="<<distance[i];
      cout<<"\nPath="<<i;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=startnode);
   }

}

