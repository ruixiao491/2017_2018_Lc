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
#include <TCut.h>
#define  MAX_XB    20000

using namespace std;

int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_5(TString infile, TString outfile,  Bool_t iseos=false)
//int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_5(TString infile="/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_BDT_3_5/pp2017data_forlambdapkpi_notfinished_0417/notfinished_0530_submit01132020/HIZero9_notfinished/HIZero9_notfinished_0000/Dntuple_Dntuple_Dntuple_HiForestAOD_97.root_452.root_453.root_452.root", TString outfile="test.root",  Bool_t iseos=false)
{
	TFile* f = new TFile(infile);
	TTree * t2 = (TTree *) f->Get("t1");
	TTree * mvaTree = (TTree *) f->Get("mvaTree");
	t2->AddFriend("mvaTree");
	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

	TNtuple *nt1 = new TNtuple("nt1", "pp_Kevin_3_4_BDT_3_5","mass");
	TNtuple *nt2 = new TNtuple("nt2", "pp_Kevin_4_5_BDT_3_5","mass");
	TNtuple *nt3 = new TNtuple("nt3", "pp_Kevin_3_5_BDT_3_5","mass");

	
	float Dmass[MAX_XB];
	float Dpt[MAX_XB];
	float Dchi2cl[MAX_XB];
	float Dtrk1Pt[MAX_XB];
	float Dtrk1Y[MAX_XB];
	float Dtrk2Pt[MAX_XB];
	float Dtrk2Y[MAX_XB];
	float Dtrk3Pt[MAX_XB];
	float Dtrk3Y[MAX_XB];
	float Dy[MAX_XB];
	float Dtrk1Eta[MAX_XB];
	float Dtrk2Eta[MAX_XB];
	float Dtrk3Eta[MAX_XB];
	int   Dsize;
	float PVz; 
	bool  Dtrk1highPurity[MAX_XB];
	bool  Dtrk2highPurity[MAX_XB];
	bool  Dtrk3highPurity[MAX_XB];
	float Dtrk1PtErr[MAX_XB];
	float Dtrk2PtErr[MAX_XB];
	float Dtrk3PtErr[MAX_XB];
	int   pass12trigger;
	int   pBeamScrapingFilter;
	int   pPAprimaryVertexFilter;
	double BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight[MAX_XB];
	float DlxyBS[MAX_XB];
	float DlxyBSErr[MAX_XB];
	float alpha_BS_2D_correction[MAX_XB];
	float   kaon_pt[MAX_XB];
	float   pion_pt[MAX_XB];
	float   proton_pt[MAX_XB];
	float   Dtrk1PixelHit[MAX_XB];
	float   Dtrk2PixelHit[MAX_XB];
	float   Dtrk3PixelHit[MAX_XB];
	float   Dtrk1StripHit[MAX_XB];
	float   Dtrk2StripHit[MAX_XB];
	float   Dtrk3StripHit[MAX_XB];
	
	t2->SetBranchAddress("Dmass",Dmass);
	t2->SetBranchAddress("Dy",Dy);
	t2->SetBranchAddress("Dchi2cl",Dchi2cl);
	t2->SetBranchAddress("Dpt",Dpt);
	t2->SetBranchAddress("Dsize",&Dsize);
	t2->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	t2->SetBranchAddress("Dtrk1Y",Dtrk1Y);
	t2->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	t2->SetBranchAddress("Dtrk2Y",Dtrk2Y);
	t2->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
	t2->SetBranchAddress("Dtrk3Y",Dtrk3Y);
	t2->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	t2->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	t2->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	t2->SetBranchAddress("PVz",&PVz);
	t2->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
	t2->SetBranchAddress("Dtrk2highPurity",Dtrk2highPurity);
	t2->SetBranchAddress("Dtrk3highPurity",Dtrk3highPurity);
	t2->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
	t2->SetBranchAddress("Dtrk2PtErr",Dtrk2PtErr);
	t2->SetBranchAddress("Dtrk3PtErr",Dtrk3PtErr);
	t2->SetBranchAddress("pass12trigger",&pass12trigger);
	t2->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
	t2->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
	mvaTree->SetBranchAddress("BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight",BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight);
	t2->SetBranchAddress("DlxyBS",DlxyBS);
	t2->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	t2->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);
	t2->SetBranchAddress("kaon_pt",kaon_pt);
	t2->SetBranchAddress("pion_pt",pion_pt);
	t2->SetBranchAddress("proton_pt",proton_pt);
	t2->SetBranchAddress("Dtrk1PixelHit",Dtrk1PixelHit);
	t2->SetBranchAddress("Dtrk2PixelHit",Dtrk2PixelHit);
	t2->SetBranchAddress("Dtrk3PixelHit",Dtrk3PixelHit);
	t2->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);
	t2->SetBranchAddress("Dtrk2StripHit",Dtrk2StripHit);
	t2->SetBranchAddress("Dtrk3StripHit",Dtrk3StripHit);


	t2->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);


	for (int entry = 0; entry < t2->GetEntries(); entry++)
	{
		t2->GetEntry(entry);
		mvaTree->GetEntry(entry);
		if (abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&pass12trigger)
		{
			for (int i = 0; i < Dsize; i++ )
			{
/////hits cuts
/*
				if(Dpt[i]>3&&Dpt[i]<4&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight[i]>0.0953&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt1->Fill(Dmass[i]);
				}
*/
				if(Dpt[i]>4&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight[i]>0.0953&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt2->Fill(Dmass[i]);
				}
				if(Dpt[i]>3&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_3_5_5_cutvar_0_1_2_3_5_weight[i]>0.0953&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt3->Fill(Dmass[i]);
				}

			}//for size
		}//if
	}//entry

//	nt1->Write();
	nt2->Write();
	nt3->Write();

	outf->Write();
	cout<<"--- Writing finished"<<endl;
	outf->Close();

return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_5(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}

