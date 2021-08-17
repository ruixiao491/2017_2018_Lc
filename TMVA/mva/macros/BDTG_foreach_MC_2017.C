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
Bool_t istest = true;

int BDTG_foreach_MC_2017(TString inputfile="", TString outfile1="", int pbpb=0, int ptMin=3, int ptMax=100, string mvatype="BDTG",int cut_number=5,TString name_variable="0_1_2_3_5")
{

	TString MVAtype = (TString)mvatype;
	bool isPbPb = (bool)pbpb;
	ptmin = ptMin;
	ptmax = ptMax;

	//TString inputfile = "/scratch/halstead/x/xiao147/pp2015_correct_dls_agreedARC_0706_backup/add_branches/firetrigger/Dntuple_MB1_whole.root_10.root";
	if(istest)
	{
		/*
		inputfile = "/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/skim_tree_forBDT/HIZero1/Dntuple_Dntuple_HiForestAOD_998.root_989.root_2632.root";

		outfile1 =Form("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/fill_BDT/MB_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());
*/
		/*
		inputfile = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_gen_pxpypz/MC_pt10/pkpi_pt10_whole.root";
		outfile1 = Form("/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_gen_pxpypz/MC_pt10/Fill_BDTG_3_100/pkpi_pt10_MC_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());
*/
		inputfile = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/add_DCA_significance/pp_pt4_Dntuple/pkpi_pt4_whole.root";
		outfile1 = Form("/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/add_DCA_significance/pp_pt4_Dntuple/fill_BDTG_3_100/pkpi_pt4_MC_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());

	}


	TFile *inf = new TFile(inputfile);
	TTree *t = (TTree*)inf->Get("ntlambdaCtopkpi");
	TTree *ntHlt = (TTree*)inf->Get("ntHlt");
	TTree *ntGen = (TTree*)inf->Get("ntGen");
	TTree *ntSkim = (TTree*)inf->Get("ntSkim");
	TTree *ntHi = (TTree*)inf->Get("ntHi");

	Int_t           Dsize;
	Float_t         Dchi2cl[MAX_XB];   //[Dsize]
	Float_t         Dpt[MAX_XB];
	Float_t         kaon_pt[MAX_XB];
	Float_t         pion_pt[MAX_XB];
	Float_t         proton_pt[MAX_XB];
	Float_t         DlxyBS[MAX_XB];
	Float_t         DlxyBSErr[MAX_XB];
	Float_t         alpha_BS_2D_correction[MAX_XB];
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
	int     pBeamScrapingFilter;
	int     pPAprimaryVertexFilter;
	float   PVz;
	bool    Dtrk1highPurity[MAX_XB];
	bool    Dtrk2highPurity[MAX_XB];
	bool    Dtrk3highPurity[MAX_XB];
	float   Dtrk1PtErr[MAX_XB];
	float   Dtrk2PtErr[MAX_XB];
	float   Dtrk3PtErr[MAX_XB];
	int   pass12trigger;


	t->SetBranchAddress("Dsize", &Dsize);
	t->SetBranchAddress("Dchi2cl", Dchi2cl);
	t->SetBranchAddress("Dpt",Dpt);
	t->SetBranchAddress("kaon_pt",kaon_pt);
	t->SetBranchAddress("pion_pt",pion_pt);
	t->SetBranchAddress("proton_pt",proton_pt);
	t->SetBranchAddress("DlxyBS",DlxyBS);
	t->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	t->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);
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


	std::vector<std::string> theInputVars;
	string a1="(log10(DlxyBS/sqrt(DlxyBSErr)))";//0
	string a2="Dchi2cl";//1
	string a3="alpha_BS_2D_correction";//2
	string a4="kaon_pt/Dpt";//3
	//string a5="pion_pt/Dpt";
	string a5="proton_pt/Dpt";//5
	//string a7="Dtrk1Eta";
	//string a8="Dtrk2Eta";
	//string a9="Dtrk3Eta";

	theInputVars.push_back(a1);
	theInputVars.push_back(a2);
	theInputVars.push_back(a3);
	theInputVars.push_back(a4); 
	theInputVars.push_back(a5); 

	vector<double> inputValues;
	ReadBDTG mva(theInputVars);

	TFile *outf = new TFile(outfile1,"recreate");
	TTree *mvaTree = new TTree("mvaTree","MVA");

	double MVA[MAX_XB];
	mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
	//mvaTree->Branch(mvatype.Data(),MVA,Form("%s[Dsize]/D",mvatype.Data()));
	mvaTree->Branch(Form("BDTG_pt_%i_%i_%i_cutvar_%s_weight",ptMin,ptMax,cut_number,name_variable.Data()),MVA, Form("BDTG_pt_%i_%i_%i_cutvar_%s_weight[Dsize]/D",ptMin,ptMax,cut_number,name_variable.Data()));
	


	for(int i=0;i<t->GetEntries();i++)
	{
		t->GetEntry(i);
		if(i%1000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
		for(int j=0;j<Dsize;j++)
		{
			MVA[j]=-999;//initial value	  


			if (Dpt[j]>ptMin&& Dpt[j]<ptMax&&(DlxyBS[j]/sqrt(DlxyBSErr[j]))>2)
			{
				inputValues.clear();
				inputValues.push_back((log10(DlxyBS[j]/sqrt(DlxyBSErr[j]))));//0
				inputValues.push_back(Dchi2cl[j]);//1
				inputValues.push_back(alpha_BS_2D_correction[j]);//2
				inputValues.push_back(kaon_pt[j]/Dpt[j]);//3
				inputValues.push_back(proton_pt[j]/Dpt[j]);//5

				MVA[j]=mva.GetMvaValue(inputValues);      
			}//if
		}//for Dsize
		mvaTree->Fill();
	}//for entry
	outf->cd();
	t->CloneTree()->Write();
	ntGen->CloneTree()->Write();
	ntSkim->CloneTree()->Write();
	ntHi->CloneTree()->Write();
	ntHlt->CloneTree()->Write();
	outf->Write();
	outf->Close();
	
	return 0;

}
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		BDTG_foreach_MC_2017(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
