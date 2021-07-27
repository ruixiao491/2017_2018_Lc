#include <TTree.h>
#include <TFile.h>
#include <TDirectory.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>


void getEventNo_noduplicate()
{
TFile *f1 = TFile::Open("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/EventNo_aftercuts_0714_2021_whole.root");

TNtuple *nt0 = (TNtuple*)f1->Get("t_final");

int     RunNo;
unsigned long long     evt;
int     LumiNo;


nt0->SetBranchAddress("RunNo",&RunNo);
nt0->SetBranchAddress("evt",&evt);
nt0->SetBranchAddress("LumiNo",&LumiNo);

std::set<std::pair<long,unsigned long long>> Eventnumbers;

long key1;
int j=0;
for (int entry = 0; entry < nt0->GetEntries(); entry++)
{
	nt0->GetEntry(entry);
	key1=RunNo*10000+LumiNo;
	if (Eventnumbers.find(std::pair<long,unsigned long long> (key1,evt)) == Eventnumbers.end())
	{
		Eventnumbers.insert(make_pair(key1,evt));
		cout<<"'"<<RunNo<<":"<<LumiNo<<":"<<std::setprecision(12)<<evt<<"'"<<",";
		j++;
		if (j%250 == 0) 
		{	
			cout<<endl;
			cout<<endl;
		}
	}//if


}//for

}
