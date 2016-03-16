#include <stdio.h>
#include <iostream>   
#include <string>   
#include<fstream>
#include "GraphList.h"
using namespace std;


GraphList::GraphList()
{
	vertexCount = 0;
	linkCount = 0;
	vertextMax = 600;
	m_vVertex = new Vertex[600];
	for (int i = 0; i<600;i++)
	{
		m_vVertex[i].VertexID = -1;
		m_vVertex[i].firstLink = NULL;
	}

}

GraphList::~GraphList(){
	for (int i = 0; i < vertexCount; ++i){
		Link* tmp = m_vVertex[i].firstLink;
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
	ifstream file ( "../../test-case/case1/topo.csv" ); //                    
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
		//cout<<rowStr<<endl;
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
				*vertexString = '\0';
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
		m_vVertex[SourceID].firstLink = NULL;
	}

	if (m_vVertex[DestinationID].VertexID != DestinationID)
	{
		vertexCount++;
		m_vVertex[DestinationID].VertexID = DestinationID;
		m_vVertex[DestinationID].firstLink = NULL;
	}	
}

void GraphList::addLinkToList(int LinkID,int SourceID, int DestinationID, int Cost)
{
	Link* link = new Link();
	link->LinkedID = LinkID;
	link->endVertexID = DestinationID;
	link->Cost = Cost;
	link->next = NULL;
	if (m_vVertex[SourceID].firstLink){
		Link* tmp = m_vVertex[SourceID].firstLink;
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = link;
	}else{
		m_vVertex[SourceID].firstLink = link;
	}
}

void GraphList::printGraph()
{
	for (int i = 0; i < 600; ++i){
		Link* tmp = m_vVertex[i].firstLink;
		if (tmp != NULL)
		{
			cout << "list:**" << m_vVertex[i].VertexID << "->";
			while(tmp){
				cout <<"*"<< tmp->LinkedID<<"(" << tmp->Cost << ")"<<"->";
				cout << tmp->endVertexID<<"  " ;
				tmp = tmp->next;
			}
			cout<<endl;
		}
	}
}

int GraphList:: getVertextCount() 
{
	return vertexCount;
}

