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
	prev[v0] = v0;
	while(link)
	{
		dist[link->endVertexID] = link->Cost;
		prev[link->endVertexID] = v0;

		link = link->next;
	}

	dist[v0] = 0;
	S[v0] = true; 
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