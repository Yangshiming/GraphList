#ifndef  GRAPHLIST
#define  GRAPHLIST


// ��
struct Link{
	int endVertexID;  //�ߵ��յ�
	int Cost;
	int LinkedID;
	struct Link* next;
};

// ����(����ͷ)
struct Vertex{
	int VertexID;
	struct Link* firstLink;
};

// ����ͼ
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

	// ���ɶ�����������
	void makeVertexArray(int sourceID,int DestinationID);

	// ��ӱ߽ڵ�����Ӧ��������
	void addLinkToList(int LinkID,int SourceID, int DestinationID, int Cost);

	int vertexCount;
	int vertextMax;
	int linkCount;
	
	
	
};





#endif
#pragma   once