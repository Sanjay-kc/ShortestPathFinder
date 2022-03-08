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
    /*take input of no. of node initilaize window*/
    int **weight;
    int no_of_nodes;
    GUI graphics;
    if(graphics.start())
    {
     no_of_nodes=graphics.drawnodes();
     weight = new int*[no_of_nodes];
     for(int i = 0; i < no_of_nodes; ++i)
     weight[i] = new int[no_of_nodes];

     for(int i=0;i<no_of_nodes;i++)
    {
        for(int j=0;j<no_of_nodes;j++)
        {
            if (i==j)
            {
                weight[i][j]=0;
            }
            else
            {
                weight[i][j]=INFINITY;
            }
            
                
        }
    }

    graphics.inputWeight(weight);
    for(int i=0;i<no_of_nodes;i++)
    {
        for(int j=0;j<no_of_nodes;j++)
        {
            if(i==j)
                weight[i][j]=0;

            if (i>j)
            {
                weight[i][j]=weight[j][i];
            }


        }

    }


    for(int i=0;i<no_of_nodes;i++)
    {
        for(int j=0;j<no_of_nodes;j++)
        {
                std::cout<<weight[i][j]<<" ";
        }
        std::cout<<std::endl;

    }

    unsigned int dist[no_of_nodes],perm[no_of_nodes];
    unsigned int current,k,dc,smalldist,newdist,membnodes=0;
    unsigned int s=0,pd,precede[no_of_nodes];

    for(int i=0;i<no_of_nodes;i++)
    {
        perm[i]=NONMEMBER;
        dist[i]=INFINITY;
    }

    perm[s]=MEMBER;
    membnodes=1;
    dist[s]=0;
    current=s;
    graphics.update(s,s);

    while(true)
    {
        smalldist=INFINITY;
        dc=dist[current];
        for(int i=0;i<no_of_nodes;i++)
            if((perm[i]==NONMEMBER))
            {if (weight[current][i]!=INFINITY)
            {
            newdist=dc+weight[current][i];
            if(newdist<dist[i])
            {
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

