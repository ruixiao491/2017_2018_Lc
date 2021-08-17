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
TNtuple *nt0[35];
TNtuple *nt1[35];
TNtuple *nt2[35];
TNtuple *nt3[35];
TNtuple *nt4[35];
TNtuple *nt5[35];
TNtuple *nt6[35];
TNtuple *nt7[35];
TNtuple *nt8[35];
TNtuple *nt9[35];

char hname0[70];
char hname1[70];
char hname2[70];
char hname3[70];
char hname4[70];
char hname5[70];
char hname6[70];
char hname7[70];
char hname8[70];
char hname9[70];

int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_3_100_BDTG_workingpoint_scan(TString infile, TString outfile,  Bool_t iseos=false)
//int make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_3_100_BDTG_workingpoint_scan(TString infile="/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_3_100_BDTG/pp2017data_forlambdapkpi/HIZero1/HIZero1_0000/Dntuple_Dntuple_Dntuple_HiForestAOD_1.root_110.root_0.root_110.root", TString outfile="test.root",  Bool_t iseos=false)
{
	TFile* f = new TFile(infile);
	TTree * t2 = (TTree *) f->Get("t1");
	TTree * mvaTree = (TTree *) f->Get("mvaTree");
	t2->AddFriend("mvaTree");
	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

	double BDTGvalue[35]={-0.9,-0.85,-0.8,-0.75,-0.7,-0.65,-0.6,-0.55,-0.5,-0.45,-0.4,-0.35,-0.3,-0.25,-0.2,-0.15,-0.1,0,0.1,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.77,0.8,0.85,0.9};
	for (int i=0; i<35; i++)
	{
		//cout<<"BDTGvalue"<<BDTGvalue[i]<<endl;
		int a=fabs(int(BDTGvalue[i]*100));

		cout<<"a value:  "<<a<<endl;
		if (i<17)
		{
			sprintf(hname0,"BDTG_3_4_value_minus_%i",a);
			sprintf(hname1,"BDTG_4_5_value_minus_%i",a);
			sprintf(hname2,"BDTG_5_6_value_minus_%i",a);
			sprintf(hname3,"BDTG_6_8_value_minus_%i",a);
			sprintf(hname4,"BDTG_8_10_value_minus_%i",a);
			sprintf(hname5,"BDTG_10_125_value_minus_%i",a);
			sprintf(hname6,"BDTG_125_15_value_minus_%i",a);
			sprintf(hname7,"BDTG_15_20_value_minus_%i",a);
			sprintf(hname8,"BDTG_20_30_value_minus_%i",a);
			sprintf(hname9,"BDTG_3_30_value_minus_%i",a);
		}

		if (i>=17)
		{
			sprintf(hname0,"BDTG_3_4_value_0_%i",a);
			sprintf(hname1,"BDTG_4_5_value_0_%i",a);
			sprintf(hname2,"BDTG_5_6_value_0_%i",a);
			sprintf(hname3,"BDTG_6_8_value_0_%i",a);
			sprintf(hname4,"BDTG_8_10_value_0_%i",a);
			sprintf(hname5,"BDTG_10_125_value_0_%i",a);
			sprintf(hname6,"BDTG_125_15_value_0_%i",a);
			sprintf(hname7,"BDTG_15_20_value_0_%i",a);
			sprintf(hname8,"BDTG_20_30_value_0_%i",a);
			sprintf(hname9,"BDTG_3_30_value_0_%i",a);
		}

		nt0[i]=new TNtuple(hname0,hname0,"mass"); 
		nt1[i]=new TNtuple(hname1,hname1,"mass"); 
		nt2[i]=new TNtuple(hname2,hname2,"mass"); 
		nt3[i]=new TNtuple(hname3,hname3,"mass"); 
		nt4[i]=new TNtuple(hname4,hname4,"mass"); 
		nt5[i]=new TNtuple(hname5,hname5,"mass"); 
		nt6[i]=new TNtuple(hname6,hname6,"mass"); 
		nt7[i]=new TNtuple(hname7,hname7,"mass"); 
		nt8[i]=new TNtuple(hname8,hname8,"mass"); 
		nt9[i]=new TNtuple(hname9,hname9,"mass"); 

	}




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
	double BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[MAX_XB];
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
	mvaTree->SetBranchAddress("BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight",BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight);
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
				for (int j=0; j<35; j++)
				{
					if(Dpt[i]>3&&Dpt[i]<4&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt0[j]->Fill(Dmass[i]);
					}

					if(Dpt[i]>4&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt1[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>5&&Dpt[i]<6&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt2[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>6&&Dpt[i]<8&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt3[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>8&&Dpt[i]<10&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt4[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>10&&Dpt[i]<12.5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt5[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>12.5&&Dpt[i]<15&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt6[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>15&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt7[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>20&&Dpt[i]<30&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt8[j]->Fill(Dmass[i]);
					}
					if(Dpt[i]>3&&Dpt[i]<30&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[i]>BDTGvalue[j]&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11)
					{
						nt9[j]->Fill(Dmass[i]);
					}

				}//BDTG values



			}//for size
		}//if
	}//entry
	for (int i=0; i<35; i++)
	{
		nt0[i]->Write();
		nt1[i]->Write();
		nt2[i]->Write();
		nt3[i]->Write();
		nt4[i]->Write();
		nt5[i]->Write();
		nt6[i]->Write();
		nt7[i]->Write();
		nt8[i]->Write();
		nt9[i]->Write();
	}
	outf->Write();
	cout<<"--- Writing finished"<<endl;
	outf->Close();

return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_allpTranges_3_100_BDTG_workingpoint_scan(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}

