#include "GraphList.h"
const int  MAXINT = 32767;
const int MAXNUM = 600;
int A[MAXNUM][MAXNUM];


void Dijkstra(GraphList* graph,int v0)
{
	bool S[MAXNUM];                                  // 判断是否已存入该点到S集合中
    int  n=MAXNUM;
	int dist[MAXNUM];
	int prev[MAXNUM];

	for(int i=1; i<=n; ++i)
	{
		//dist[i] = A[v0][i];
		//S[i] = false;                                // 初始都未用过该点
		//if(dist[i] == MAXINT)    
		//  prev[i] = -1;
		//else 
		//  prev[i] = v0;
		prev[i] = -1;
		dist[i] = MAXINT;
	}

	// 
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
		while(link)
		{
			//1. 遍历当前节点的相邻边，2. 将相邻边的权值与这一点一个节点的距离权值相加，如果小于它之前的权值，就更新 
			//3.比较它和其他邻接点的值，如果最小，则就记住他的ID，将它加入S集合       4.更新当前点为最小权值点
			dist[link->endVertexID] = dist[lastMinVertexID]+ link->Cost ;
			prev[link->endVertexID] = lastMinVertexID;
			if (link->Cost < tempMin)
			{
				tempMin = link->Cost;
				minCostVertID = link->endVertexID;
			}
			link = link->next;
		}
		lastMinVertexID = minCostVertID;
		S[lastMinVertexID] = true
		dist[lastMinVertexID] = tempMin;
		//判断当前点的所有相连点是否遍历玩，如果完，则置flag =1
		link = graph->m_vVertex[lastMinVertexID].firstLink;
		int secondVertID = graph->m_vVertex[lastMinVertexID].firstLink->endVertexID;

		do 
		{
			if (S[secondVertID] != true)
			{
				flag = 0;
			}
			link = link->next;
			secondVertID = link->endVertexID;
			
		} while (flag == 1);
		
	}
	for(int i=2; i<=n; i++)
	{
		int mindist = MAXINT;
		int u = v0;                // 找出当前未使用的点j的dist[j]最小值
		for(int j=1; j<=n; ++j)
		if((!S[j]) && dist[j]<mindist)
			{
				u = j;                             // u保存当前邻接点中距离最小的点的号码 
				mindist = dist[j];
			}

		S[u] = true;
		for(int j=1; j<=n; j++)
		if((!S[j]) && A[u][j]<MAXINT)
			{
				if(dist[u] + A[u][j] < dist[j])     //在通过新加入的u点路径找到离v0点更短的路径  
					{
						dist[j] = dist[u] + A[u][j];    //更新dist 
						prev[j] = u;                    //记录前驱顶点 
					}
			}
	}
}