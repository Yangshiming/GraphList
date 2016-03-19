#include "GraphList.h"
const int  MAXINT = 32767;
const int MAXNUM = 600;
int A[MAXNUM][MAXNUM];


void Dijkstra(GraphList* graph,int v0)
{
	bool S[MAXNUM];                                  // �ж��Ƿ��Ѵ���õ㵽S������
    int  n=MAXNUM;
	int dist[MAXNUM];
	int prev[MAXNUM];

	for(int i=1; i<=n; ++i)
	{
		//dist[i] = A[v0][i];
		//S[i] = false;                                // ��ʼ��δ�ù��õ�
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
	int flag = 0; //flag = 0 �����ǰ������ڵ㻹�в���S[]���ϵ�
	while(flag == 0 )
	{
		int tempVert = -1;
		int tempMin = MAXINT;
		int minCostVertID  = -1;
		while(link)
		{
			//1. ������ǰ�ڵ�����ڱߣ�2. �����ڱߵ�Ȩֵ����һ��һ���ڵ�ľ���Ȩֵ��ӣ����С����֮ǰ��Ȩֵ���͸��� 
			//3.�Ƚ����������ڽӵ��ֵ�������С����ͼ�ס����ID����������S����       4.���µ�ǰ��Ϊ��СȨֵ��
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
		//�жϵ�ǰ��������������Ƿ�����棬����꣬����flag =1
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
		int u = v0;                // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
		for(int j=1; j<=n; ++j)
		if((!S[j]) && dist[j]<mindist)
			{
				u = j;                             // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ��� 
				mindist = dist[j];
			}

		S[u] = true;
		for(int j=1; j<=n; j++)
		if((!S[j]) && A[u][j]<MAXINT)
			{
				if(dist[u] + A[u][j] < dist[j])     //��ͨ���¼����u��·���ҵ���v0����̵�·��  
					{
						dist[j] = dist[u] + A[u][j];    //����dist 
						prev[j] = u;                    //��¼ǰ������ 
					}
			}
	}
}