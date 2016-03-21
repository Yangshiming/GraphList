#include <iostream> 
#include "GraphList.h"
using namespace std;
const int  MAXINT = 32767;
const int MAXNUM = 600;
int A[MAXNUM][MAXNUM];


void Dijkstra(GraphList* graph,int v0,int v1)
{
	bool S[MAXNUM];                                  // 判断是否已存入该点到S集合中
    int  n=MAXNUM;
	int dist[MAXNUM];
	int prev[MAXNUM];

	//将每一个定点的pre置-1，并将到v0的距离置为max。
	for(int i=0; i<n; ++i)
	{

		S[i] = false;
		prev[i] = -1;
		dist[i] = MAXINT;
	}

	// 将初始点v0的所有相邻距离都置为权值，上一个最佳相邻点设为v0。
	Link* link = graph->m_vVertex[v0].firstLink;
	dist[v0] = 0;
	prev[v0] = v0;
	while(link)
	{
		dist[link->endVertexID] = link->Cost;
		prev[link->endVertexID] = v0;
		link = link->next;
	}


	S[v0] = true; 
	link = graph->m_vVertex[v0].firstLink;
	int lastMinVertexID = graph->m_vVertex[v0].VertexID;
	int flag = 0; //flag = 0 则代表当前点的相邻点还有不是S[]集合的
	while(flag == 0 )
	{
		int tempVert = -1;
		int tempMin = MAXINT;
		int minCostVertID  = -1;
		link = graph->m_vVertex[lastMinVertexID].firstLink;
		while(link)
		{
			//1. 遍历当前节点的相邻边，2. 将相邻边的权值与这一点一个节点的距离权值相加，如果小于它之前的权值，就更新 
			//3.比较它和其他邻接点的值，如果最小，则就记住他的ID，将它加入S集合       4.更新当前点为最小权值点
			int distValue = dist[lastMinVertexID]+ link->Cost ;			
			if (distValue < dist[link->endVertexID])
			{
				dist[link->endVertexID] = distValue;
				prev[link->endVertexID] = lastMinVertexID;
			}
			if (link->Cost < tempMin)
			{
				tempMin = link->Cost;
				minCostVertID = link->endVertexID;
			}
			link = link->next;
		}


		
		
		//从U中选距离最短的为当前最新的k顶点,并加入S
		int minPath = MAXINT;
		for(int i=1; i<n; ++i)
		{
			if (graph->m_vVertex[i].VertexID != -1)
			{
				if (S[i] != true)
				{
					if (dist[i] <= minPath)
					{
						lastMinVertexID = i;
						minPath = dist[i];
					}
				}
			}
		}
		S[lastMinVertexID] = true;
		//cout<<"%%"<<lastMinVertexID<<endl;
		
		//判断所有顶点是否全部属于S，如果完，则置flag =1
		for(int i=1; i<n; ++i)
		{
			
			if (S[i] != true)
			{
				if (graph->m_vVertex[i].VertexID != -1)
				{
					flag = 0;
					break;
				}
			}
			else
				flag = 1;
		}
		
	}

	cout<<v1<<"<<";
	while(prev[v1] != v0)
	{
		cout<<prev[v1]<<"<<";
		v1 = prev[v1];
	}
	cout<<v0;

}