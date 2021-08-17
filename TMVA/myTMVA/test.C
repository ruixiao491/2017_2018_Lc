#include <iostream>
#include "string.h"
#include <vector>
#include <sstream>
using namespace std;
int main()
{
	int cut_number=2;
	//std::string color = {"Red","Blue"};
	//cout<<color[1]<<endl;
	//string stage = "0,2";
	std::vector<string> valist;

	//vector<int> stages{0,2};
	//stages = '0,2';
	
	string s = "0,2";
	/*
	stringstream geek(s);
	int x=0;
	geek>>x;
	int y=0;
	geek>>y;
	*/
	valist.push_back("Red");
	valist.push_back("Blue");
	valist.push_back("Yellow");
/*
	cout<<valist[0]<<endl;
	cout<<valist[1]<<endl;
	cout<<valist[2]<<endl;
*/
/*
	for(auto& s : stages)
	{
	 //cout<<valist[s]<<endl;
	
	}


*/
//cout<<x<<y<<endl;
//std::size_t pos = s.find("2");
//std::string str3 =  s.substr(pos);
//std::cout<<str3<<endl;
int numbers_chosen[3]={1,1,1};
int j=0;
	cout<<s.size()<<endl;
	for (int i=0;i<s.size();i++)
	{
		char an[]={','};
		char bn[]={' '};
		//if (s.at(i)!= int(*an) && s.at(i)!= int(*bn))
		if (s.at(i)!= int(*an))
		{
		cout<<"print"<<s.at(i)<<endl;
		//numbers_chosen[i]=s.at(i);
		stringstream geek;
		geek << s.at(i);
		geek >> numbers_chosen[j];
		cout<<numbers_chosen[j]<<endl;
		j=j+1;
		}
		else
		{
			cout<<endl;
		}
		
	
	}

for (int i=0; i<2;i++)
{
	int a= numbers_chosen[i];
	//cout<<numbers_chosen[i]<<endl;
	cout<<valist[a]<<endl;
}



}
