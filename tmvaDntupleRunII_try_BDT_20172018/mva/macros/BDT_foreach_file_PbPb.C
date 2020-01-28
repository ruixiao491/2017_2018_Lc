#include "../header.h"
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <vector>
#include <TMath.h>
#include <iostream>
#include "../../prefilter_modify_trigger_sidebandchange_withBBS.h"
#define MAX_XB       20000

using namespace std;
Bool_t istest = false;

int BDT_foreach_file_PbPb(TString inputfile="", TString outfile1="", int pbpb=1, int ptMin=8, int ptMax=20, string mvatype="BDT",int cut_number=6,TString name_variable="0_to_5")
{

	TString MVAtype = (TString)mvatype;
	//bool isPbPb = (bool)pbpb;
	ptmin = ptMin;
	ptmax = ptMax;

	if(istest)
	{
		inputfile = "/scratch/halstead/x/xiao147/2018PbPb_rereco_data_Dntuple_07022019/skim_for_BDT/first_attempt/MB0/MB0_part1_0000/Dntuple_Dntuple_HiForestAOD_delet_files_0426_whole_numEvent100_1.root_0.root_0.root";
	//	inputfile = "/scratch/halstead/x/xiao147/2018PbPb_rereco_data_Dntuple_07022019/skim_for_BDT/first_attempt/MB2/MB2_part1_0000/Dntuple_Dntuple_HiForestAOD_delet_files_0426_whole_numEvent100_997.root_994.root_996.root";
		outfile1 = Form("PbPb_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());


	}


	//TFile *inf = TFile::Open(inputfile);
	TFile *inf = new TFile(inputfile);

	TTree *t = (TTree*)inf->Get("t1");

	Int_t           Dsize;
	Float_t         Dchi2cl[MAX_XB];   //[Dsize]
	Float_t         Dpt[MAX_XB];
	Float_t         kaon_pt[MAX_XB];
	Float_t         pion_pt[MAX_XB];
	Float_t         proton_pt[MAX_XB];
	Float_t         Dtrk1Eta[MAX_XB];
	Float_t         Dtrk2Eta[MAX_XB];
	Float_t         Dtrk3Eta[MAX_XB];
	Float_t         Dy[MAX_XB];
	float Dmass[MAX_XB];
	float   Dtrk1Pt[MAX_XB];
	float   Dtrk1Y[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk2Y[MAX_XB];
	float   Dtrk3Pt[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	float   PVz;
	bool    Dtrk1highPurity[MAX_XB];
	bool    Dtrk2highPurity[MAX_XB];
	bool    Dtrk3highPurity[MAX_XB];
	float   Dtrk1PtErr[MAX_XB];
	float   Dtrk2PtErr[MAX_XB];
	float   Dtrk3PtErr[MAX_XB];
	float   DsvpvDistance[MAX_XB];
	float   DsvpvDisErr[MAX_XB];
	float   Dalpha[MAX_XB];

	t->SetBranchAddress("Dsize", &Dsize);
	t->SetBranchAddress("Dchi2cl", Dchi2cl);
	t->SetBranchAddress("Dpt",Dpt);
	t->SetBranchAddress("kaon_pt",kaon_pt);
	t->SetBranchAddress("pion_pt",pion_pt);
	t->SetBranchAddress("proton_pt",proton_pt);
	t->SetBranchAddress("Dy",Dy);
	t->SetBranchAddress("Dmass",Dmass);
	t->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	t->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	t->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
	t->SetBranchAddress("Dtrk1Y",Dtrk1Y);
	t->SetBranchAddress("Dtrk2Y",Dtrk2Y);
	t->SetBranchAddress("Dtrk3Y",Dtrk3Y);
	t->SetBranchAddress("PVz",&PVz);
	t->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
	t->SetBranchAddress("Dtrk2highPurity",Dtrk2highPurity);
	t->SetBranchAddress("Dtrk3highPurity",Dtrk3highPurity);
	t->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
	t->SetBranchAddress("Dtrk2PtErr",Dtrk2PtErr);
	t->SetBranchAddress("Dtrk3PtErr",Dtrk3PtErr);
	t->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	t->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	t->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	t->SetBranchAddress("DsvpvDistance",DsvpvDistance);
	t->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
	t->SetBranchAddress("Dalpha",Dalpha);


	std::vector<std::string> theInputVars;
	string a1="(log10(DsvpvDistance/DsvpvDisErr))";//0
	string a2="Dchi2cl";//1
	string a3="Dalpha";//2
	string a4="kaon_pt/Dpt";//3
	string a5="pion_pt/Dpt";
	string a6="proton_pt/Dpt";//5

	theInputVars.push_back(a1);
	theInputVars.push_back(a2);
	theInputVars.push_back(a3);
	theInputVars.push_back(a4); 
	theInputVars.push_back(a5); 
	theInputVars.push_back(a6); 

	vector<double> inputValues;
	ReadBDT mva(theInputVars);

	TFile *outf = new TFile(outfile1,"recreate");
	TTree *mvaTree = new TTree("mvaTree","MVA");

	double MVA[MAX_XB];
	mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
	//mvaTree->Branch(mvatype.Data(),MVA,Form("%s[Dsize]/D",mvatype.Data()));
	mvaTree->Branch(Form("BDT_pt_%i_%i_%i_cutvar_%s_weight",ptMin,ptMax,cut_number,name_variable.Data()),MVA, Form("BDT_pt_%i_%i_%i_cutvar_%s_weight[Dsize]/D",ptMin,ptMax,cut_number,name_variable.Data()));
	


	for(int i=0;i<t->GetEntries();i++)
	{
		t->GetEntry(i);
		if(i%1000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
		for(int j=0;j<Dsize;j++)
		{
			MVA[j]=-999;//initial value	  


			if (Dpt[j]>ptMin&& Dpt[j]<ptMax&&(DsvpvDistance[j]/DsvpvDisErr[j])>2)
			{
				inputValues.clear();
				inputValues.push_back((log10(DsvpvDistance[j]/DsvpvDisErr[j])));//0
				inputValues.push_back(Dchi2cl[j]);//1
				inputValues.push_back(Dalpha[j]);//2
				inputValues.push_back(kaon_pt[j]/Dpt[j]);//3
				inputValues.push_back(pion_pt[j]/Dpt[j]);//4
				inputValues.push_back(proton_pt[j]/Dpt[j]);//5


				MVA[j]=mva.GetMvaValue(inputValues);      
			}//if
		}//for Dsize
		mvaTree->Fill();
	}//for entry
	outf->cd();
	t->CloneTree()->Write();
	outf->Write();
	outf->Close();
	
	return 0;

}
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		BDT_foreach_file_PbPb(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
