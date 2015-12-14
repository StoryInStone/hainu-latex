// =====================================================================================
// 
//       Filename:  Mst.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  12/08/2015 04:22:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Junxing Lu (SIS), StoryInStone@outlook.com
//        Company:  
// 
// =====================================================================================

#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;

#define V 300                                  // 选择股票样本总数
class Mst
{
    private:
        int parent[V];
        double key[V];
        bool mstSet[V];
        double graph[V][V];
    public:
    void createGraph(double gra[V][V]) {
        for (int i=0;i<V;i++) {
            for (int j=0;j<V;j++) {
                graph[i][j] = gra[i][j];
            }
        }
    }
    int minKey()
    {
        int min = 65535, min_index;
        for (int v = 0; v < V; v++)
        {
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        }
        return min_index;
    }
    void primMST()
    {
        for (int i = 0; i < V; i++)
        {
            key[i] = 65535, mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V-1; count++)
        {
            int u = minKey();
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST();
    }
    void printMST()
    {
        for (int i = 0; i < V; i++)
            cout << parent[i] << "--" << i << "   " << graph[i][parent[i]] << endl;
    }
};
