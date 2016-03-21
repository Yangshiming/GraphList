#include <iostream> 
#include "GraphList.h"
using namespace std;
const int  MAXINT = 32767;
const int MAXNUM = 600;
int A[MAXNUM][MAXNUM];


void Dijkstra(GraphList* graph,int v0,int v1)
{
	bool S[MAXNUM];                                  // �ж��Ƿ��Ѵ���õ㵽S������
    int  n=MAXNUM;
	int dist[MAXNUM];
	int prev[MAXNUM];

	//��ÿһ�������pre��-1��������v0�ľ�����Ϊmax��
	for(int i=0; i<n; ++i)
	{

		S[i] = false;
		prev[i] = -1;
		dist[i] = MAXINT;
	}

	// ����ʼ��v0���������ھ��붼��ΪȨֵ����һ��������ڵ���Ϊv0��
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
		link = graph->m_vVertex[lastMinVertexID].firstLink;
		while(link)
		{
			//1. ������ǰ�ڵ�����ڱߣ�2. �����ڱߵ�Ȩֵ����һ��һ���ڵ�ľ���Ȩֵ��ӣ����С����֮ǰ��Ȩֵ���͸��� 
			//3.�Ƚ����������ڽӵ��ֵ�������С����ͼ�ס����ID����������S����       4.���µ�ǰ��Ϊ��СȨֵ��
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


		
		
		//��U��ѡ������̵�Ϊ��ǰ���µ�k����,������S
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
		
		//�ж����ж����Ƿ�ȫ������S������꣬����flag =1
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