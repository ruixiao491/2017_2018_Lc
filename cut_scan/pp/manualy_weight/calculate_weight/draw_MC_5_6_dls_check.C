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
void divideBinWidth(TH1* h)
{   
	for(int i=1;i<=h->GetNbinsX();i++)
	{   
		Float_t contentvalue=h->GetBinContent(i);
		Float_t content_err=h->GetBinError(i);
		contentvalue/=h->GetBinWidth(i);
		content_err/=h->GetBinWidth(i);
		h->SetBinContent(i,contentvalue);
		h->SetBinError(i,content_err);
	}
}
double dlscut=3.09;
double chi2cut=8.8444355737265931e-02;
double alphacut=1.2016100458684457e-01;
double kaoncut=6.9083857490045031e-02;
double protoncut=2.8162090410134671e-01;

int draw_MC_5_6_dls_check(TString infile="/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_dlsalpha_weight/pT10_MC_1020_combine/test_distribution/Delta1232_pt10_MC_BDTG_pT3_100_5_cutvariable_0_1_2_3_5_DATA.root",TString outfile="test_reweight.root",Bool_t iseos=false)
{

	TFile *f_data_pp_pt = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_accp/third_turn/cross_section_third_turn_fit.root");
	TFile *f_genpt_pp = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG/prompt_accp/first_turn_combine_accp/official_pp_Genpt_shape2017.root");
	TFile* f = new TFile(infile);
	TTree * t2 = (TTree *) f->Get("ntlambdaCtopkpi");
	TTree * mvaTree = (TTree *) f->Get("mvaTree");
	TTree * ntSkim = (TTree *) f->Get("ntSkim");
	t2->AddFriend("mvaTree");
	t2->AddFriend("ntSkim");
	auto MC_fit_fun = (TF1*) f_genpt_pp->Get("fit_fun");
	auto data_fit_fun = (TF1*) f_data_pp_pt->Get("fit_data");

	TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");
	//const Int_t NBINS = 13;
	//double edges[NBINS+1]={2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};
	const Int_t NBINS = 10;
	double edges[NBINS+1]={1.5,3,3.5,4,5,6,7,8,9,10.5,12};
	
	TH1 *h_dls_4_5 = new TH1D("h_dls_4_5","h_dls_4_5",NBINS,edges);
	TH1 *h_dls_5_6 = new TH1D("h_dls_5_6","h_dls_5_6",NBINS,edges);
	TH1 *h_dls_6_8 = new TH1D("h_dls_6_8","h_dls_6_8",NBINS,edges);
	TH1 *h_dls_8_10 = new TH1D("h_dls_8_10","h_dls_8_10",NBINS,edges);
	TH1 *h_dls_10_125 = new TH1D("h_dls_10_125","h_dls_10_125",NBINS,edges);
	TH1 *h_dls_125_15 = new TH1D("h_dls_125_15","h_dls_125_15",NBINS,edges);
	TH1 *h_dls_15_20 = new TH1D("h_dls_15_20","h_dls_15_20",NBINS,edges);
	TH1 *h_dls_10_20 = new TH1D("h_dls_10_20","h_dls_10_20",NBINS,edges);


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
	int     Dgen[MAX_XB];
	float Dgenpt[MAX_XB];
	float corrected_dls[MAX_XB];

	t2->SetBranchAddress("Dgenpt",Dgenpt);
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
	ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
	ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
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
	t2->SetBranchAddress("Dgen",Dgen);
	t2->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);
	t2->SetBranchAddress("corrected_dls",corrected_dls);

	for (int entry = 0; entry < t2->GetEntries(); entry++)
	{
		t2->GetEntry(entry);
		mvaTree->GetEntry(entry);
		ntSkim->GetEntry(entry);
		double weight=0;
		if (abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter)
		{
			for (int i = 0; i < Dsize; i++ )
			{
				if(Dpt[i]>4&&Dpt[i]<5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_4_5->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>5&&Dpt[i]<6&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_5_6->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>6&&Dpt[i]<8&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_6_8->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>8&&Dpt[i]<10&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_8_10->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>10&&Dpt[i]<12.5&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_10_125->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>12.5&&Dpt[i]<15&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_125_15->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>15&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_15_20->Fill(DlxyBS[i]/sqrt(DlxyBSErr[i]),weight);
				}

				if(Dpt[i]>10&&Dpt[i]<20&&Dtrk1PtErr[i]/Dtrk1Pt[i]<0.3&&Dtrk2PtErr[i]/Dtrk2Pt[i]<0.3&&Dtrk3PtErr[i]/Dtrk3Pt[i]<0.3&&abs(Dtrk1Eta[i])<1.2&&abs(Dtrk2Eta[i])<1.2&&abs(Dtrk3Eta[i])<1.2&&abs(Dy[i])<1&&Dtrk1highPurity[i]==1&&Dtrk2highPurity[i]==1&&Dtrk3highPurity[i]==1&&DlxyBS[i]/sqrt(DlxyBSErr[i])>2&&(Dtrk1PixelHit[i]+Dtrk1StripHit[i])>=11&&(Dtrk2PixelHit[i]+Dtrk2StripHit[i])>=11&&(Dtrk3PixelHit[i]+Dtrk3StripHit[i])>=11&&Dgen[i]==23333&&Dchi2cl[i]>chi2cut&&alpha_BS_2D_correction[i]<alphacut&&proton_pt[i]/Dpt[i]>protoncut&&kaon_pt[i]/Dpt[i]>kaoncut)
				{
					weight=data_fit_fun->Eval(Dgenpt[i])/MC_fit_fun->Eval(Dgenpt[i]);
					h_dls_10_20->Fill(corrected_dls[i]);
				}


			}//Dsize


		}//if

    }//entry
	divideBinWidth(h_dls_4_5);
	divideBinWidth(h_dls_5_6);
	divideBinWidth(h_dls_6_8);
	divideBinWidth(h_dls_8_10);
	divideBinWidth(h_dls_10_125);
	divideBinWidth(h_dls_125_15);
	divideBinWidth(h_dls_15_20);
	divideBinWidth(h_dls_10_20);
	h_dls_4_5->Scale(1/h_dls_4_5->Integral());
	h_dls_5_6->Scale(1/h_dls_5_6->Integral());
	h_dls_6_8->Scale(1/h_dls_6_8->Integral());
	h_dls_8_10->Scale(1/h_dls_8_10->Integral());
	h_dls_10_125->Scale(1/h_dls_10_125->Integral());
	h_dls_125_15->Scale(1/h_dls_125_15->Integral());
	h_dls_15_20->Scale(1/h_dls_15_20->Integral());
	h_dls_10_20->Scale(1/h_dls_10_20->Integral());
	/*
	TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],0)",2,9);
	fit_fun->SetParameter(0,h->Integral());
	fit_fun->SetParameter(1,2.5);
	fit_fun->SetParameter(2,0.4);
	h->Fit("fit_fun","I","",1.7,9);
	h->Draw("e");
	fit_fun->Draw("same");
	h->Write();
	fit_fun->Write();
	*/
	h_dls_4_5->Write();
	h_dls_5_6->Write();
	h_dls_6_8->Write();
	h_dls_8_10->Write();
	h_dls_10_125->Write();
	h_dls_125_15->Write();
	h_dls_15_20->Write();
	h_dls_10_20->Write();
	outf->Write();
	outf->Close();
return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		draw_MC_5_6_dls_check(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;

}
