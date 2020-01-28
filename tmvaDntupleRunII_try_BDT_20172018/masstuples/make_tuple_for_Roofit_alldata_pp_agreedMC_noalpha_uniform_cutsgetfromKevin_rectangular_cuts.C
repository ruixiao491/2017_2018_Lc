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

int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts(TString infile, TString outfile,  Bool_t iseos=false)
{
	TFile* f = new TFile(infile);
	TTree * t2 = (TTree *) f->Get("t1");
	TTree * mvaTree = (TTree *) f->Get("mvaTree");
	t2->AddFriend("mvaTree");
	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");
/*
	TNtuple *nt1 = new TNtuple("nt1", "pp_Kevin_10_20_nopion_withdls2","mass");
	TNtuple *nt2 = new TNtuple("nt2", "pp_Kevin_8_10_nopion_withdls2","mass");
	TNtuple *nt3 = new TNtuple("nt3", "pp_Kevin_6_8_nopion_withdls2","mass");
	TNtuple *nt4 = new TNtuple("nt4", "pp_Kevin_5_6_nopion_withdls2","mass");
	TNtuple *nt5 = new TNtuple("nt5", "pp_Kevin_5_20_nopion_withdls2","mass");
	TNtuple *nt6 = new TNtuple("nt6", "pp_Kevin_4_5_nopion_withdls2","mass");
*/
	TNtuple *nt7 = new TNtuple("nt7", "pp_Kevin_3_4_nopion_withdls2","mass");
	//TNtuple *nt8 = new TNtuple("nt8", "pp_Kevin_2_3_nopion_withdls2","mass");

	


	
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
	double BDT_pt_5_20_5_cutvar_0_1_2_3_5_weight[MAX_XB];
	float DlxyBS[MAX_XB];
	float DlxyBSErr[MAX_XB];
	float alpha_BS_2D_correction[MAX_XB];
	float   kaon_pt[MAX_XB];
	float   pion_pt[MAX_XB];
	float   proton_pt[MAX_XB];
	
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
	mvaTree->SetBranchAddress("BDT_pt_5_20_5_cutvar_0_1_2_3_5_weight",BDT_pt_5_20_5_cutvar_0_1_2_3_5_weight);
	t2->SetBranchAddress("DlxyBS",DlxyBS);
	t2->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	t2->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);
	t2->SetBranchAddress("kaon_pt",kaon_pt);
	t2->SetBranchAddress("pion_pt",pion_pt);
	t2->SetBranchAddress("proton_pt",proton_pt);

	for (int entry = 0; entry < t2->GetEntries(); entry++)
	{
		t2->GetEntry(entry);
		mvaTree->GetEntry(entry);
		if (abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&pass12trigger)
		{
			for (int i = 0; i < Dsize; i++ )
			{

				/*
				if(Dpt[i]>10&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt1->Fill(Dmass[i]);
				}
				if(Dpt[i]>8&&Dpt[i]<10&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt2->Fill(Dmass[i]);
				}
				if(Dpt[i]>6&&Dpt[i]<8&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt3->Fill(Dmass[i]);
				}
				if(Dpt[i]>5&&Dpt[i]<6&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt4->Fill(Dmass[i]);
				}
				if(Dpt[i]>5&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt5->Fill(Dmass[i]);
				}
				
				if(Dpt[i]>4&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt6->Fill(Dmass[i]);
				}
*/
				if(Dpt[i]>3&&Dpt[i]<4&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&log10(DlxyBS[i]/sqrt(DlxyBSErr[i]))>0.28&&Dchi2cl[i]>0.058&&alpha_BS_2D_correction[i]<0.326&&kaon_pt[i]/Dpt[i]>0.133&&proton_pt[i]/Dpt[i]>0.245)
				{
					nt7->Fill(Dmass[i]);
				}
				/*
				if(Dpt[i]>2&&Dpt[i]<3&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.5&&abs(Dtrk2Eta[i])<1.5&&abs(Dtrk3Eta[i])<1.5&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2.68&&Dchi2cl[i]>0.215&&alpha_BS_2D_correction[i]<0.283&&kaon_pt[i]/Dpt[i]>0.132&&proton_pt[i]/Dpt[i]>0.288)
				{
					nt8->Fill(Dmass[i]);
				}
*/
			}//for size
		}//if
	}//entry
/*
	nt1->Write();
	nt2->Write();
	nt3->Write();
	nt4->Write();
	nt5->Write();
	nt6->Write();
*/
	nt7->Write();

//	nt8->Write();
	
	outf->Write();
	cout<<"--- Writing finished"<<endl;
	outf->Close();

return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}

