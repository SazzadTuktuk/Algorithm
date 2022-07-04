#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 6
int step =1;
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[N][N])
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            {

                    printf(" %d ",sol[i][j]);
                }
                 printf("\n");
            }
        printf("\n");
    }


/* A utility function to check if x,y is valid index for N*N maze */
int safe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return 0
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return 1;

    return 0;
}


int solveMaze(int maze[N][N])
{
    int sol[N][N] ;
    for (int i=0;i<N; i++)
    {
        for (int j = 0; j < N; j++)
            {sol[i][j]=0;}

    }

    if(solveMazeUtil(maze, 0, 0, sol)==0)
    {
        printf("Solution doesn't exist");
        return 0;
    }

    printSolution(sol);
    return 1;
}

/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{printf("step : %d",step);
printf("\n");
printf("\n");
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            {
                if(x==i&&y==j)
                {printf(" R ");}
                else{
                    printf(" %d ",maze[i][j]);
                }
            }
        printf("\n");
    }
    step++;

    printf("\n");
    printf("\n");
    printf("\n");

    // if (x,y is goal) return 1
    if(x==N-1 && y==N-1)
    {
        sol[x][y]=1;
        return 1;
    }

    // Check if maze[x][y] is valid
    if(safe(maze,x,y)==1)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move right in x axis*/
        if (solveMazeUtil(maze, x+1, y, sol) == 1)
            return 1;

        /* Move down in y axis */
        if (solveMazeUtil(maze, x, y+1, sol) == 1)
            return 1;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// driver program to test above function
int main()
{

    int block_count=0;
    srand(time(NULL));
    int maze[N][N]  =  { {1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 1}
    };

// Block Control Mechanism
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            {

                maze[i][j]=rand()%2;
                if(maze[i][j]==0)
                {
                    block_count++;
                }
                if(block_count>16||maze[N-1][N-1]==0||maze[0][0]==0)// how many block will be there ???
                {
                    maze[i][j]=1;
                }
            }

    }
printf("Main Maze Start here");
printf("\n");
    printf("\n");
    printf("\n");


    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            printf(" %d ", maze[i][j]);
        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("\n");
printf("Rat is running");
printf("\n");
    printf("\n");
    printf("\n");
    solveMaze(maze);
    return 0;
}
