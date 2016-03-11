#include <iostream>   
#include <string>   
#include<fstream>   
using namespace std;  


int main(int argc, char* argv[])  

{  

	ifstream file ( "D:\\HuaWei\\test-case\\topo.csv" ); //                    

	string value;  

	while ( file.good() )  
	{  
		getline ( file, value ,','); // read a string until next comma:       
		cout<<value;
	}  



}  