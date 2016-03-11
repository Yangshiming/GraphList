#include <iostream>
#include <cstdio>

using namespace std;

// ��
struct Edge{
	int vName;
	int weight;
	struct Edge* next;
};

// ����(����ͷ)
struct Vertex{
	int vName;
	struct Edge* next;
};

// ����ͼ
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();

private:
	// 1. ���붨����
	void inputVertexCount();
	// 2. ���ɶ�������
	void makeVertexArray();
	// 3. �������
	void inputEdgeCount();
	// 4. ����ߵ���ʼ��
	void inputEdgeInfo();
	// 5. ��ӱ߽ڵ�����Ӧ��������
	void addEdgeToList(int vFrom, int weight, int vTo);
private:
	int m_vCount;
	int m_eCount;
	Vertex* m_vVertex;
};

GraphList::~GraphList(){
	for (int i = 0; i < m_vCount; ++i){
		Edge* tmp = m_vVertex[i].next;
		Edge* edge = NULL;
		while(tmp){
			edge = tmp;
			tmp = tmp->next;
			delete edge;
			edge = NULL;
		}
	}
	delete[] m_vVertex;
}