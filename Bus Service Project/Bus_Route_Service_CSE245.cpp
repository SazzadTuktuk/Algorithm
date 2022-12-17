#include<iostream>
#include <cstdlib>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#define IN 99
#define N 74

using namespace std;


class Bus_Node
{
public:
    string code[200],stopage_name[200];
  int stopage[200],ip,jp;
  int cost[N][N],i,j,w,ch,co;
    int source, target,x,y;
  int dijkstra(int cost[][N], int source, int target);
  void input();
  void graph();
};

void Bus_Node::input()
{
    ifstream route ("route_name.txt");

  if (route.is_open())
  {
    ip=1;
  while(!route.eof())
{
    route>>stopage[ip]>>code[ip];
    getline (route,stopage_name[ip]);

    cout<<stopage[ip]<<" ";
    //cout<<line[i]<<" ";
    cout<<stopage_name[ip]<<" ";
    cout<<endl;
    ip++;
}
route.close();

  }

  else {cout << "Unable to open file 1";
  exit(1);

  }


}
void Bus_Node::graph()
{
    for(i=1;i< N;i++)
    {for(j=1;j< N;j++)
    {
        cost[i][j] = IN;
    }
    }

    ifstream way ("graph.txt");


        if (way.is_open())
            {
            int ipl=1;

              while(!way.eof())
                {
                way>>x>>y>>w;
                cost [x][y] = cost[y][x] = w;

                ipl++;
                }
            way.close();

            }
        else{cout<<"Unable to open file 2";
        exit(1);
        }

        printf("\nEnter the starting location Number from above option: ");
    scanf("%d", &source);
    printf("\nEnter the target location Number from above option: ");
    scanf("%d", &target);
    co = dijkstra(cost,source,target);
    printf("\nThe Shortest Path: %d",co);


}

int Bus_Node::dijkstra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    int k=1,l=j;
    int path[N],pack[N];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 1;
    while(start != -1)
    {
        path[j++] = start;
        start = prev[start];
    }
    path[j]='\0';
    //strrev(path);
    for(k=1,l=j;k<=j&&l>=1;k++,l--)
    {
        pack[j-1]=path[k];
        //printf("%d", path[k]);
    }
    for(int k=1;k<=j;k++)
    {

        printf("%d\n", path[k]);
    }

    return dist[target];
}

int main()
{printf("\n//////////////////////////////////\n");
    printf("///Welcome To Bus Route Service///\n");
    printf("//////////////////////////////////\n\n\n\n");
    Bus_Node b;
    b.input();
    b.graph();
}
