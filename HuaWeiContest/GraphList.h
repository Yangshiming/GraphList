#ifndef  GRAPHLIST
#define  GRAPHLIST


// 边
struct Link{
	int endVertexID;  //边的终点
	int Cost;
	int LinkedID;
	struct Link* next;
};

// 顶点(链表头)
struct Vertex{
	int VertexID;
	struct Link* firstLink;
};

// 有向图
class GraphList
{
public:
	Vertex* m_vVertex;

	GraphList();
	void createGraph();
	int getVertextCount();
	void printGraph();
	~GraphList();
private:

	// 生成定点数组排序
	void makeVertexArray(int sourceID,int DestinationID);

	// 添加边节点至对应的链表中
	void addLinkToList(int LinkID,int SourceID, int DestinationID, int Cost);

	int vertexCount;
	int vertextMax;
	int linkCount;
	
	
	
};





#endif
#pragma   once