#include <iostream>
#include <cstdio>

using namespace std;

// 边
struct Edge{
	int vName;
	int weight;
	struct Edge* next;
};

// 顶点(链表头)
struct Vertex{
	int vName;
	struct Edge* next;
};

// 有向图
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();

private:
	// 1. 输入定点数
	void inputVertexCount();
	// 2. 生成定点数组
	void makeVertexArray();
	// 3. 输入边数
	void inputEdgeCount();
	// 4. 输入边的起始点
	void inputEdgeInfo();
	// 5. 添加边节点至对应的链表中
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