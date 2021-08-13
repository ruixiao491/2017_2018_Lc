#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TMath.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLorentzVector.h>
#include <TChain.h>
#include <TCut.h>
#define  MAX_XB    20000
using namespace std;
  Bool_t istest = false;
  int data_triggerfireup_pp_eventselection_forrightdlBS_noterr(TString infile="", TString outfile="", Bool_t iseos=false)
{
	if(istest)
	{
		infile ="/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/Dntuple/pp2017data_forlambdapkpi/HIZeroBias1/HIZeroBias1_0000/Dntuple_HiForestAOD_998.root_989.root";
		//outfile="/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/skim_tree_forBDT/test.root";
		outfile="test.root";
		iseos=false;
	}
	TString ifname;
	if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
	else ifname = infile;
	if (!TFile::Open(ifname))   { cout << " fail to open file" << endl; return 0;}      
	TFile* f = TFile::Open(infile); 
	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

	cout<<"---read the needed branch"<<endl;
	TTree * ntlambdaCtopkpi = (TTree*)f->Get("ntlambdaCtopkpi");
	TTree * ntHlt = (TTree*)f->Get("ntHlt");
	TTree * ntHi = (TTree*)f->Get("ntHi");
	TTree * ntSkim = (TTree*)f->Get("ntSkim");
	TTree t1("t1","s simple Tree with several branches");
	int     RunNo;
	unsigned long long     evt;
	int     LumiNo;
	float Dmass[MAX_XB];
	float Dpt[MAX_XB];
	float   DsvpvDistance[MAX_XB];
	float   DsvpvDisErr[MAX_XB];
	float   Dalpha[MAX_XB];
	float   Dchi2cl[MAX_XB];
	int     Dsize;
	float   Dy[MAX_XB];
	float   Dtrk1Pt[MAX_XB];
    float   Dtrk1Y[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk2Y[MAX_XB];
    float   Dtrk3Pt[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	float   Dtrk1Eta[MAX_XB];
    float   Dtrk2Eta[MAX_XB];
    float   Dtrk3Eta[MAX_XB];
	int     hiBin;
	int     HLT_HIZeroBias_part0_v6;
	int     HLT_HIZeroBias_part1_v6;
	int     HLT_HIZeroBias_part2_v6;
	int     HLT_HIZeroBias_part3_v6;
	int     HLT_HIZeroBias_part4_v6;
	int     HLT_HIZeroBias_part5_v6;
	int     HLT_HIZeroBias_part6_v6;
	int     HLT_HIZeroBias_part7_v6;
	int     HLT_HIZeroBias_part8_v6;
	int     HLT_HIZeroBias_part9_v6;
	int     HLT_HIZeroBias_part10_v6;
	int     HLT_HIZeroBias_part11_v6;
	int     pBeamScrapingFilter;
	float   kaon_pt[MAX_XB];
	float   pion_pt[MAX_XB];
	float   proton_pt[MAX_XB];

	int     pPAprimaryVertexFilter;
	float   PVz;
	bool    Dtrk1highPurity[MAX_XB];
	bool    Dtrk2highPurity[MAX_XB];
	bool    Dtrk3highPurity[MAX_XB];
	float   Dtrk1PtErr[MAX_XB];
	float   Dtrk2PtErr[MAX_XB];
	float   Dtrk3PtErr[MAX_XB];
	float   Dtrk1PixelHit[MAX_XB];
	float   Dtrk2PixelHit[MAX_XB];
	float   Dtrk3PixelHit[MAX_XB];
	float   Dtrk1StripHit[MAX_XB];
	float   Dtrk2StripHit[MAX_XB];
	float   Dtrk3StripHit[MAX_XB];
	
///////add the branches
	float   DlxyBS[MAX_XB];
	float   DlxyBSErr[MAX_XB];
	float   alpha_BS_2D_correction[MAX_XB];

ntlambdaCtopkpi->SetBranchAddress("RunNo",&RunNo);
ntHi->SetBranchAddress("evt",&evt);
ntlambdaCtopkpi->SetBranchAddress("LumiNo",&LumiNo);
ntlambdaCtopkpi->SetBranchAddress("Dmass",Dmass);
ntlambdaCtopkpi->SetBranchAddress("Dpt",Dpt);
ntlambdaCtopkpi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
ntlambdaCtopkpi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
ntlambdaCtopkpi->SetBranchAddress("Dchi2cl",Dchi2cl);
ntlambdaCtopkpi->SetBranchAddress("Dalpha",Dalpha);
ntlambdaCtopkpi->SetBranchAddress("Dsize",&Dsize);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1Y",Dtrk1Y);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2Y",Dtrk2Y);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3Y",Dtrk3Y);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
ntlambdaCtopkpi->SetBranchAddress("PVz",&PVz);
ntlambdaCtopkpi->SetBranchAddress("Dy",Dy);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2highPurity",Dtrk2highPurity);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3highPurity",Dtrk3highPurity);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2PtErr",Dtrk2PtErr);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3PtErr",Dtrk3PtErr);
ntlambdaCtopkpi->SetBranchAddress("kaon_pt",kaon_pt);
ntlambdaCtopkpi->SetBranchAddress("pion_pt",pion_pt);
ntlambdaCtopkpi->SetBranchAddress("proton_pt",proton_pt);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1PixelHit",Dtrk1PixelHit);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2PixelHit",Dtrk2PixelHit);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3PixelHit",Dtrk3PixelHit);
ntlambdaCtopkpi->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);
ntlambdaCtopkpi->SetBranchAddress("Dtrk2StripHit",Dtrk2StripHit);
ntlambdaCtopkpi->SetBranchAddress("Dtrk3StripHit",Dtrk3StripHit);

ntHi->SetBranchAddress("hiBin",&hiBin);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part0_v6",&HLT_HIZeroBias_part0_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part1_v6",&HLT_HIZeroBias_part1_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part2_v6",&HLT_HIZeroBias_part2_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part3_v6",&HLT_HIZeroBias_part3_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part4_v6",&HLT_HIZeroBias_part4_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part5_v6",&HLT_HIZeroBias_part5_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part6_v6",&HLT_HIZeroBias_part6_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part7_v6",&HLT_HIZeroBias_part7_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part8_v6",&HLT_HIZeroBias_part8_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part9_v6",&HLT_HIZeroBias_part9_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part10_v6",&HLT_HIZeroBias_part10_v6);
ntHlt->SetBranchAddress("HLT_HIZeroBias_part11_v6",&HLT_HIZeroBias_part11_v6);
ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
///add new branches
ntlambdaCtopkpi->SetBranchAddress("DlxyBS",DlxyBS);
ntlambdaCtopkpi->SetBranchAddress("DlxyBSErr",DlxyBSErr);
ntlambdaCtopkpi->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);



int   pass12trigger;

t1.Branch("RunNo",&RunNo);
t1.Branch("evt",&evt);
t1.Branch("LumiNo",&LumiNo);
t1.Branch("Dsize",&Dsize);
t1.Branch("hiBin",&hiBin);
t1.Branch("Dmass",Dmass,"Dmass[Dsize]/F");
t1.Branch("Dpt",Dpt,"Dpt[Dsize]/F");
t1.Branch("DsvpvDistance",DsvpvDistance,"DsvpvDistance[Dsize]/F");
t1.Branch("DsvpvDisErr",DsvpvDisErr,"DsvpvDisErr[Dsize]/F");
t1.Branch("kaon_pt",kaon_pt,"kaon_pt[Dsize]/F");
t1.Branch("pion_pt",pion_pt,"pion_pt[Dsize]/F");
t1.Branch("proton_pt",proton_pt,"proton_pt[Dsize]/F");

t1.Branch("Dchi2cl",Dchi2cl,"Dch2cl[Dsize]/F");
t1.Branch("Dalpha",Dalpha,"Dalpha[Dsize]/F");
t1.Branch("Dy",Dy,"Dy[Dsize]/F");
t1.Branch("Dtrk1Pt",Dtrk1Pt,"Dtrk1Pt[Dsize]/F");
t1.Branch("Dtrk1Y",Dtrk1Y,"Dtrk1Y[Dsize]/F");
t1.Branch("Dtrk2Pt",Dtrk2Pt,"Dtrk2Pt[Dsize]/F");
t1.Branch("Dtrk2Y",Dtrk2Y,"Dtrk2Y[Dsize]/F");
t1.Branch("Dtrk3Pt",Dtrk3Pt,"Dtrk3Pt[Dsize]/F");
t1.Branch("Dtrk3Y",Dtrk3Y,"Dtrk3Y[Dsize]/F");
t1.Branch("Dtrk1Eta",Dtrk1Eta,"Dtrk1Eta[Dsize]/F");
t1.Branch("Dtrk2Eta",Dtrk2Eta,"Dtrk2Eta[Dsize]/F");
t1.Branch("Dtrk3Eta",Dtrk3Eta,"Dtrk3Eta[Dsize]/F");
t1.Branch("pass12trigger",&pass12trigger);
t1.Branch("PVz",&PVz);
t1.Branch("pBeamScrapingFilter",&pBeamScrapingFilter);
t1.Branch("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
t1.Branch("Dtrk1highPurity",Dtrk1highPurity,"Dtrk1highPurity[Dsize]/O");
t1.Branch("Dtrk2highPurity",Dtrk2highPurity,"Dtrk2highPurity[Dsize]/O");
t1.Branch("Dtrk3highPurity",Dtrk3highPurity,"Dtrk3highPurity[Dsize]/O");
t1.Branch("Dtrk1PtErr",Dtrk1PtErr,"Dtrk1PtErr[Dsize]/F");
t1.Branch("Dtrk2PtErr",Dtrk2PtErr,"Dtrk2PtErr[Dsize]/F");
t1.Branch("Dtrk3PtErr",Dtrk3PtErr,"Dtrk3PtErr[Dsize]/F");
t1.Branch("DlxyBS",DlxyBS,"DlxyBS[Dsize]/F");
t1.Branch("DlxyBSErr",DlxyBSErr,"DlxyBSErr[Dsize]/F");
t1.Branch("alpha_BS_2D_correction",alpha_BS_2D_correction,"alpha_BS_2D_correction[Dsize]/F");
t1.Branch("Dtrk1PixelHit",Dtrk1PixelHit,"Dtrk1PixelHit[Dsize]/F");
t1.Branch("Dtrk2PixelHit",Dtrk2PixelHit,"Dtrk2PixelHit[Dsize]/F");
t1.Branch("Dtrk3PixelHit",Dtrk3PixelHit,"Dtrk3PixelHit[Dsize]/F");
t1.Branch("Dtrk1StripHit",Dtrk1StripHit,"Dtrk1StripHit[Dsize]/F");
t1.Branch("Dtrk2StripHit",Dtrk2StripHit,"Dtrk2StripHit[Dsize]/F");
t1.Branch("Dtrk3StripHit",Dtrk3StripHit,"Dtrk3StripHit[Dsize]/F");


cout<<"---start filling the branch in the new tree"<<endl;
for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries();entry++)
//for (int entry = 0; entry<200;entry++)
{
	ntlambdaCtopkpi->GetEntry(entry);
	ntHlt->GetEntry(entry);
	ntHi->GetEntry(entry);
	ntSkim->GetEntry(entry);

		pass12trigger = (HLT_HIZeroBias_part0_v6||HLT_HIZeroBias_part1_v6||HLT_HIZeroBias_part2_v6||HLT_HIZeroBias_part3_v6||HLT_HIZeroBias_part4_v6||HLT_HIZeroBias_part5_v6||HLT_HIZeroBias_part6_v6||HLT_HIZeroBias_part7_v6||HLT_HIZeroBias_part8_v6||HLT_HIZeroBias_part9_v6||HLT_HIZeroBias_part10_v6||HLT_HIZeroBias_part11_v6);
		
		t1.Fill();
}//for entry
t1.Write();
outf->Write();
cout<<" --- Writing finished"<<endl;
outf->Close();
return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		data_triggerfireup_pp_eventselection_forrightdlBS_noterr(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}

