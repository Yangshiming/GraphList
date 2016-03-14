#ifndef  GRAPHLIST
#define  GRAPHLIST

// 边
struct Link{
	int VertexID;
	int Cost;
	int LinkedID;
	struct Link* next;
};

// 顶点(链表头)
struct Vertex{
	int VertexID;
	struct Link* next;
};

// 有向图
class GraphList
{
public:
	GraphList();
	void createGraph();

	void printGraph();
	~GraphList();
private:

	// 3. 生成定点数组排序
	void makeVertexArray(int sourceID,int DestinationID);

	// 5. 添加边节点至对应的链表中
	void addLinkToList(int LinkID,int SourceID, int DestinationID, int Cost);

	int vertexCount;
	int vertextMax;
	int linkCount;
	Vertex* m_vVertex;
	
	
};

GraphList::GraphList()
{
	vertexCount = 0;
	linkCount = 0;
	vertextMax = 600;
	m_vVertex = new Vertex[600];
	for (int i = 0; i<600;i++)
	{
		m_vVertex[i].VertexID = -1;
		m_vVertex[i].next = NULL;
	}

}

GraphList::~GraphList(){
	for (int i = 0; i < vertexCount; ++i){
		Link* tmp = m_vVertex[i].next;
		Link* link = NULL;
		while(tmp){
			link = tmp;
			tmp = tmp->next;
			delete link;
			link = NULL;
		}
	}
	delete[] m_vVertex;
}

// **************************************************************************
// create Adjacency list
// **************************************************************************
void GraphList::createGraph()
{
	ifstream file ( "topo.csv" ); //                    
	string value; 
	int LinkInfo[4];
	int i = 0;
	vertexCount = 0;
	const char* rowStr;
	char* vertexString = new char();

	while (file.good())  
	{  
		getline ( file, value ,'\n'); // read a string until next comma:  
		rowStr = value.c_str();
		char* address = vertexString;
		while(1)
		{
			if (*rowStr != ',' && *rowStr != '\0')
			{
				*vertexString = *rowStr;
				vertexString++;
			}
			else if (*rowStr == ',' || *rowStr == '\0')
			{
				vertexString = address;
				LinkInfo[i] = atoi(address);
				cout<< LinkInfo[i]<<" ";
				i++;
				if (i%4 == 0)
				{
					i = 0;
					cout<<endl;
					makeVertexArray(LinkInfo[1],LinkInfo[2]);
					addLinkToList(LinkInfo[0],LinkInfo[1],LinkInfo[2],LinkInfo[3]);
				}
				if (*rowStr == '\0')
				{
					break;
				}
			}

			rowStr += 1;
		}
		linkCount ++;
	}
	

	cout<<"Vertex Number:"<<vertexCount<<"  Link Number: "<<linkCount<<endl;
}

void GraphList::makeVertexArray(int SourceID,int DestinationID)
{
	if (m_vVertex[SourceID].VertexID != SourceID)
	{
		vertexCount++;
		m_vVertex[SourceID].VertexID = SourceID;
		m_vVertex[SourceID].next = NULL;
	}

	if (m_vVertex[DestinationID].VertexID != DestinationID)
	{
		vertexCount++;
		m_vVertex[DestinationID].VertexID = DestinationID;
		m_vVertex[DestinationID].next = NULL;
	}	
}

void GraphList::addLinkToList(int LinkID,int SourceID, int DestinationID, int Cost)
{
	Link* link = new Link();
	link->LinkedID = LinkID;
	link->VertexID = DestinationID;
	link->Cost = Cost;
	link->next = NULL;
	if (m_vVertex[SourceID].next){
		Link* tmp = m_vVertex[SourceID].next;
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = link;
	}else{
		m_vVertex[SourceID].next = link;
	}
}

void GraphList::printGraph()
{
	for (int i = 0; i < 600; ++i){
		Link* tmp = m_vVertex[i].next;
		if (tmp != NULL)
		{
			cout << "list:" << m_vVertex[i]
			.VertexID << "->";
			while(tmp){
				cout << tmp->LinkedID<<"(" << tmp->Cost << ")"<<"->";
				cout << tmp->VertexID <<endl;
				tmp = tmp->next;
			}
		}
	}
}




#endif
#pragma   once