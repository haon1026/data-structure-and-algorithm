//2020年12月7日 16:17:36
//图的创建

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "../../base.h"

#define IsLetter(ch) ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))

int g_includeWeight;
int g_isUndirected;

char ReadChar()
{
    char ch;
    
    do
    {
        ch = getchar();
    } while(!IsLetter(ch));
    
    return ch;
}

int GetPosition(Graph G, char ch)
{
    for(int i = 0; i < G->VexNum; i++)
    {
        if(G->Vexs[i].Data == ch)
            return i;
    }
    return NOTIXIST;
}

void static LinkLast(ENode *List, ENode *Node)
{
    ENode *p = List;
    while(p->NextEdge)
        p = p->NextEdge;
    p->NextEdge = Node;
}

Graph CreateGraph()
{
    printf("Choose weight graph or unweight graph(w/u): ");
    char ch = getchar();
    g_includeWeight = ((ch == 'w' || ch == 'W') ? 1 : 0);
    getchar();
    printf("Choose directed graph or undirected graph(d/u): ");
    ch = getchar();
    g_isUndirected = ((ch == 'u' || ch == 'U') ? 1 : 0);


    int VexNum, EdgeNum;
    printf("Input vertex number: ");
    scanf("%d", &VexNum);
    printf("Input edge number: ");
    scanf("%d", &EdgeNum);
    if(VexNum < 1 || VexNum > MAXVERTEX || EdgeNum < 1 || EdgeNum > VexNum*(VexNum-1))
        FatalError("Input error!!!");

    Graph G = (Graph)malloc(sizeof(struct GraphRecord));
    if(G == NULL)
        FatalError("Out of space!!!");

    memset(G, 0, sizeof(struct GraphRecord));
    G->VexNum = VexNum;
    G->EdgeNum = EdgeNum;

    //初始化邻接表的顶点
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("vertex[%d]: ", i);
        G->Vexs[i].Data = ReadChar();
        G->Vexs[i].FirstEdge = NULL;
    }

    //初始化邻接表的边
    char ch1, ch2;
    int pos1, pos2;
    ENode *Node1, *Node2;
    int weight = 0;
    for(int i = 0; i < G->EdgeNum; i++)
    {
        //读取边的起始顶点和结束顶点
        printf("edge[%d]: ", i);
        ch1 = ReadChar();
        ch2 = ReadChar();

        //权重处理
        if(g_includeWeight == 1)
        {
            printf("weight: ");
            scanf("%d", &weight);
        }

        pos1 = GetPosition(G, ch1);
        pos2 = GetPosition(G, ch2);

        //创建结点并链接
        Node1 = (ENode *)malloc(sizeof(ENode));
        if(Node1 == NULL)
            FatalError("Out of space!!!");
        Node1->Vex = pos2;
        Node1->Weight = weight;
        Node1->NextEdge = NULL;
        if(G->Vexs[pos1].FirstEdge == NULL)
            G->Vexs[pos1].FirstEdge = Node1;
        else
            LinkLast(G->Vexs[pos1].FirstEdge, Node1);
        
        //无向图处理
        if(g_isUndirected == 1)
        {
            Node2 = (ENode *)malloc(sizeof(ENode));
            if(Node2 == NULL)
                FatalError("Out of space!!!");
            Node2->Vex = pos1;
            Node2->Weight = weight;
            Node2->NextEdge = NULL;
            if(G->Vexs[pos2].FirstEdge == NULL)
                G->Vexs[pos2].FirstEdge = Node2;
            else
                LinkLast(G->Vexs[pos2].FirstEdge, Node2);
        }
    }

    return G;
}

void PrintGraph(Graph G)
{
    ENode *Node;
    printf("List Graph:\n");
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("[%d%c]", i, G->Vexs[i].Data);
        Node = G->Vexs[i].FirstEdge;
        while(Node != NULL)
        {
            printf(" -> [%d%c]", Node->Vex, G->Vexs[Node->Vex].Data);
            if(g_includeWeight == 1)
            {
                printf("(%d)", Node->Weight);
            }
            Node = Node->NextEdge;
        }
        printf("\n");
    }
}