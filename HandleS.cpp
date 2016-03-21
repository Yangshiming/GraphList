#include <stdio.h>
#include <iostream>   
#include <string>   
#include<fstream>
#include <vector>
#include "GraphList.h"
#include "Dijkstra.h"
using namespace std;


 void readSdata(int &v0, int &v1,vector<int>& demand_S)
{
	ifstream file ( "../../test-case/case1/demand.csv" );
	string value; 
	const char* rowStr;
	char* v0String = new char();
	char* v1String = new char();
	char* demandString = new char();
	if (file.good())  
	{
		getline ( file, value ,'\n'); // read a string until next comma:  
		rowStr = value.c_str();
		char* address0 = v0String;

		//∂¡»°v0£ª
		while(*rowStr != ',')
		{
			*v0String = *rowStr;
			rowStr++;
		}
		*v0String = '\0';
		v0 = atoi(address0);
		rowStr++;

		//∂¡»°v1
		char* address1 = v1String;
		while(*rowStr != ',')
		{
			*v1String = *rowStr;
			rowStr++;
		}
		*v1String = '\0';
		v0 = atoi(address1);
		rowStr++;


		
		char* address3 = demandString;
		while(1)
		{
			if (*rowStr != '|'&& *rowStr != '\0')
			{
				*demandString = *rowStr;
				demandString++;
			}
			else if (*rowStr == '|' || *rowStr == '\0')
			{
				*demandString = '\0';
				demandString = address3;
				cout<<atoi(address3)<<endl;
				demand_S.push_back(atoi(address3));
				if (*rowStr == '\0')
				{
					break;
				}
			}
			rowStr += 1;
		}

		for (int i = 0; i< demand_S.size();i++)
		{
			cout<< demand_S[i]<<"|";
		}
		
	}
}


void Bruteforce(GraphList* graphList,vector<int>& demand_S)
{
	for (int i = 0; i< demand_S.size();i++)
	{
		for (int j = 0;j< demand_S.size();j++)
		{
			if (i != j)
			{
				vector<int> path;
				path = Dijkstra(graphList,demand_S[i],demand_S[j]);
			}
		}
	}
	
}


//GraphList* createV_graphList(vector& demand_S,GraphList* graphList)
//{
//	GraphList* V_graphList = new GraphList();
//	for (int i = 0; i< demand_S.size();i++)
//	{
//		Link* link = graphList->m_vVertex[demand_S[i]].firstLink;
//		while(link)
//		{
//			V_graphList->
//		}
//
//	}
//	return
//}


