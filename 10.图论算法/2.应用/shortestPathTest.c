//2020年12月9日 16:19:24
//测试最短路径算法

#include <stdio.h>
#include "shortestPath.h"

void TestUnweightShortestPath(Graph G, Table T);
void TestDijkstra(Graph G, Table T);
void TestWeightedNegative(Graph G, Table T);

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);

    Table T = CreatTable(G->VexNum);

    printf("Choice : 1 for testing UnweightShortestPath, 2 for testing Dijkstra, 3 for testing WeightedNegative: ");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        TestUnweightShortestPath(G, T);
        break;
    case 2:
        TestDijkstra(G, T);
        break;
    case 3:
        TestWeightedNegative(G, T);
        break;
    default:
        break;
    }
    
    return 0;
}

void TestUnweightShortestPath(Graph G, Table T)
{
    char ch;
    do
    {
        printf("Input begin point and end point: ");
        char ch1 = ReadChar();
        char ch2 = ReadChar();

        UnweightShortestPath(G, T, ch1);
        //PrintTable(G, T);
        PrintPath(G, T, ch2);

        MakeTableEmpty(T, G->VexNum);
        getchar();
        printf("Continue input?(Y/N) : ");
        ch = getchar();

    }while(ch == 'Y' || ch == 'y');
}

void TestDijkstra(Graph G, Table T)
{
    char ch;
    do
    {
        char ch1;
        printf("Input begin point: ");
        ch1 = ReadChar();
        Dijkstra(G, T, ch1);
        //PrintTable(G, T);
        PrintWeightAndPath(G, T, ch1);

        MakeTableEmpty(T, G->VexNum);
        getchar();
        printf("Continue input?(Y/N) : ");
        ch = getchar();

    }while(ch == 'Y' || ch == 'y');
}

void TestWeightedNegative(Graph G, Table T)
{
    char ch;
    do
    {
        char ch1;
        printf("Input begin point: ");
        ch1 = ReadChar();
        WeightedNegative(G, T, ch1);
        PrintWeightAndPath(G, T, ch1);

        MakeTableEmpty(T, G->VexNum);
        getchar();
        printf("Continue input?(Y/N) : ");
        ch = getchar();

    }while(ch == 'Y' || ch == 'y');
}