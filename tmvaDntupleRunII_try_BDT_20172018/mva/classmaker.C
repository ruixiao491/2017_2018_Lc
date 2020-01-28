#include "uti.h"
void classmaker(TString filename)
{
	std::ofstream myfile("header.h");
	myfile<<"#include "<<" \""<<filename<< "\"";
}

int main(int argc, char* argv[])
{
	if(argc==2)
	{
		classmaker(argv[1]);
		return 0;
	}
	else
	{
		std::cout<<"  Error: invalid argument number - classmaker()"<<std::endl;
		return 1;
	}
}
