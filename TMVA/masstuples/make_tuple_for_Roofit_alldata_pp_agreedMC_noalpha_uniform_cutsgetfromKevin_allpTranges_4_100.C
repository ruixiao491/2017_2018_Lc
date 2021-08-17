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

int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_4_100(TString infile, TString outfile,  Bool_t iseos=false)
//int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_4_100(TString infile="/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/Fill_BDT_4_100/pp2017data_forlambdapkpi/HIZero1/HIZero1_0000/Dntuple_Dntuple_Dntuple_HiForestAOD_998.root_989.root_991.root_989.root", TString outfile="test.root",  Bool_t iseos=false)
{
	TFile* f = new TFile(infile);
	TTree * t2 = (TTree *) f->Get("t1");
	TTree * mvaTree = (TTree *) f->Get("mvaTree");
	t2->AddFriend("mvaTree");
	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

	TNtuple *nt1 = new TNtuple("nt1", "pp_Kevin_4_5_nopion_BDT_withhitscut","mass");
	TNtuple *nt2 = new TNtuple("nt2", "pp_Kevin_5_6_nopion_BDT_withhitscut","mass");
	TNtuple *nt3 = new TNtuple("nt3", "pp_Kevin_6_8_nopion_BDT_withhitscut","mass");
	TNtuple *nt4 = new TNtuple("nt4", "pp_Kevin_8_10_nopion_BDT_withhitscut","mass");
	TNtuple *nt5 = new TNtuple("nt5", "pp_Kevin_10_20_nopion_BDT_withhitscut","mass");
	TNtuple *nt6 = new TNtuple("nt6", "pp_Kevin_20_30_nopion_BDT_withhitscut","mass");
	TNtuple *nt7 = new TNtuple("nt7", "pp_Kevin_20_25_nopion_BDT_withhitscut","mass");
	TNtuple *nt8 = new TNtuple("nt8", "pp_Kevin_25_30_nopion_BDT_withhitscut","mass");
	TNtuple *nt9 = new TNtuple("nt9", "pp_Kevin_30_40_nopion_BDT_withhitscut","mass");
	TNtuple *nt10 = new TNtuple("nt10", "pp_Kevin_40_60_nopion_BDT_withhitscut","mass");
	TNtuple *nt11 = new TNtuple("nt11", "pp_Kevin_60_100_nopion_BDT_withhitscut","mass");
	TNtuple *nt12 = new TNtuple("nt12", "pp_Kevin_40_100_nopion_BDT_withhitscut","mass");
	TNtuple *nt13 = new TNtuple("nt13", "pp_Kevin_20_40_nopion_BDT_withhitscut","mass");
	TNtuple *nt14 = new TNtuple("nt14", "pp_Kevin_20_60_nopion_BDT_withhitscut","mass");
	TNtuple *nt15 = new TNtuple("nt15", "pp_Kevin_20_100_nopion_BDT_withhitscut","mass");
	TNtuple *nt16 = new TNtuple("nt16","pp_Kevin_10_12_5_nopion_BDT_withhitscut","mass");
	TNtuple *nt17 = new TNtuple("nt17","pp_Kevin_12_5_15_nopion_BDT_withhitscut","mass");
	TNtuple *nt18 = new TNtuple("nt18","pp_Kevin_15_20_nopion_BDT_withhitscut","mass");

	
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
	double BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[MAX_XB];
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
	mvaTree->SetBranchAddress("BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight",BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight);
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

				if(Dpt[i]>4&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt1->Fill(Dmass[i]);
				}
				if(Dpt[i]>5&&Dpt[i]<6&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt2->Fill(Dmass[i]);
				}
				if(Dpt[i]>6&&Dpt[i]<8&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt3->Fill(Dmass[i]);
				}
				if(Dpt[i]>8&&Dpt[i]<10&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt4->Fill(Dmass[i]);
				}
				if(Dpt[i]>10&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt5->Fill(Dmass[i]);
				}
				if(Dpt[i]>20&&Dpt[i]<30&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt6->Fill(Dmass[i]);
				}
				if(Dpt[i]>20&&Dpt[i]<25&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt7->Fill(Dmass[i]);
				}
				if(Dpt[i]>25&&Dpt[i]<30&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt8->Fill(Dmass[i]);
				}
				if(Dpt[i]>30&&Dpt[i]<40&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt9->Fill(Dmass[i]);
				}
				if(Dpt[i]>40&&Dpt[i]<60&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt10->Fill(Dmass[i]);
				}
				if(Dpt[i]>60&&Dpt[i]<100&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt11->Fill(Dmass[i]);
				}
				if(Dpt[i]>40&&Dpt[i]<100&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt12->Fill(Dmass[i]);
				}
				if(Dpt[i]>20&&Dpt[i]<40&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt13->Fill(Dmass[i]);
				}
				if(Dpt[i]>20&&Dpt[i]<60&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt14->Fill(Dmass[i]);
				}
				if(Dpt[i]>20&&Dpt[i]<100&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt15->Fill(Dmass[i]);
				}
				if(Dpt[i]>10&&Dpt[i]<12.5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt16->Fill(Dmass[i]);
				}
				if(Dpt[i]>12.5&&Dpt[i]<15&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt17->Fill(Dmass[i]);
				}
				if(Dpt[i]>15&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDT_pt_4_100_5_cutvar_0_1_2_3_5_weight[i]>0.1&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
				{
					nt18->Fill(Dmass[i]);
				}





			}//for size
		}//if
	}//entry

	nt1->Write();
	nt2->Write();
	nt3->Write();
	nt4->Write();
    nt5->Write();
	nt6->Write();
	nt7->Write();
	nt8->Write();
	nt9->Write();
	nt10->Write();
	nt11->Write();
	nt12->Write();
	nt13->Write();
	nt14->Write();
	nt15->Write();
	nt16->Write();
	nt17->Write();
	nt18->Write();

	outf->Write();
	cout<<"--- Writing finished"<<endl;
	outf->Close();

return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_4_100(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}

