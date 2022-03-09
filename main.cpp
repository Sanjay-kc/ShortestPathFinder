#include<limits.h>
#define INFINITY UINT_MAX
#define MAX_NODES 9
#define MEMBER 1
#define NONMEMBER 0
#include "GUI.hpp"
//note:
//take input of no.of nodes and automatically make lines for them


int  main ()
{
    int **weight; //Initialize array of pointers
    int no_of_nodes;
    GUI graphics;
    if(graphics.start()) //initilaize window
    {
     no_of_nodes=graphics.drawnodes(); // take no of nodes from GUI method drawnodes
     weight = new int*[no_of_nodes];  //dynamically allocate memory for n=no. of nodes pointers
     for(int i = 0; i < no_of_nodes; ++i)
     weight[i] = new int[no_of_nodes]; // each pointer in weight[i] points to n= no of nodes element

     for(int i=0;i<no_of_nodes;i++)
    {
        for(int j=0;j<no_of_nodes;j++)
        {
            if (i==j)
            {
                weight[i][j]=0; // V0-->V0=0
            }
            else
            {
                weight[i][j]=INFINITY; // If no edge is defined between two vertex weight is set to infinity
            }
            
                
        }
    }

    graphics.inputWeight(weight); //provides the weight of each edge entered by the user in the window
    for(int i=0;i<no_of_nodes;i++)
    {
        for(int j=0;j<no_of_nodes;j++)
        {
            if(i==j)
                weight[i][j]=0;

            if (i>j)
            {
                weight[i][j]=weight[j][i]; // Since the graph is undirected V1-->V2 == V2-->V1
            }


        }

    }


    // for(int i=0;i<no_of_nodes;i++)
    // {
    //     for(int j=0;j<no_of_nodes;j++)
    //     {
    //             std::cout<<weight[i][j]<<" ";
    //     }
    //     std::cout<<std::endl;

    // }

    unsigned int dist[no_of_nodes],perm[no_of_nodes]; // dist array stores the distance from souce vertex to each vertex, perm array stores the visited vertex in the list
    unsigned int current,k,dc,smalldist,newdist,membnodes=0; //current stores the current vertex, membnodes counts the total no of visited nodes,smalldist stores the smallest distance form the source
    unsigned int s=0,pd,precede[no_of_nodes]; //s stores the source node, precede array stores the vertex that precede vectex precede[i]=vertex that precede vertex[i] in the shortest path

    for(int i=0;i<no_of_nodes;i++)
    {
        perm[i]=NONMEMBER;
        dist[i]=INFINITY;
    }
    //s=graphics.selectSource();
    perm[s]=MEMBER; // Add source vertex in the visited vertex list
    membnodes=1;
    dist[s]=0;
    current=s;
    graphics.update(s,s);//update the window

    while(true)
    {
        smalldist=INFINITY; // Initialize smalldist as infinity
        dc=dist[current];//store distance of current vertex from source vertex in dc
        for(int i=0;i<no_of_nodes;i++)
            if((perm[i]==NONMEMBER)) // if vertex i is not visited
            {   if (weight[current][i]!=INFINITY) //if edge is defined between current vertex and vertex i
                {
                    newdist=dc+weight[current][i]; // calculate the distance of vertex i from source vertex succeeding current vertex
                    if(newdist<dist[i])
                    {   //If newdist is smaller than distance of vertex i from souce vertex
                        dist[i]=newdist; 
                        precede[i]=current;
                    }
            }

            if (dist[i]<smalldist)
            {
                smalldist=dist[i];
                k=i;
            }

        }

        current=k;
        perm[current]=MEMBER;
        membnodes++;

        graphics.update(current,precede[current]);
        graphics.display();
 //       std::cout<<"no of memb"<<membnodes;
        if (membnodes==no_of_nodes)
            break;


         //call function for making change in above code

    }
    while(graphics.display())
          {

          }

//    for(int i=0;i<no_of_nodes;i++)
//    {
//        if(perm[i]==MEMBER && i!=s)
//            std::cout<<dist[i]<<" "<<precede[i]+1<<std::endl;
//    }

    }

}

