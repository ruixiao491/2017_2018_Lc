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

void draw_data_5_6_chi2()
{
 TFile *f1 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_0_1.root");
 TFile *f2 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_1_2.root");
 TFile *f3 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_2_3.root");
 TFile *f4 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_3_4.root");
 TFile *f5 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_4_5.root");
 TFile *f6 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_5_6.root");
 TFile *f7 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_6_7.root");
 TFile *f8 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_7_8.root");
 TFile *f9 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_8_9.root");
 TFile *f10 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_9_10.root");
 TFile *f11 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_10_11.root");
 TFile *f12 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_11_12.root");
 TFile *f13 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_12_13.root");
 TFile *f14 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_13_14.root");
 TFile *f15 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_14_15.root");
 TFile *f16 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_15_16.root");
 TFile *f17 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_16_17.root");
 TFile *f18 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_17_18.root");
 TFile *f19 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_18_19.root");
 TFile *f20 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_19_20.root");
 TFile *f21 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_20_21.root");
 TFile *f22 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_21_22.root");
 TFile *f23 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_22_23.root");
 TFile *f24 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6/pT_5_6_chi2scan_23_24.root");

TH1F *h_data_1 = (TH1F*)f1->Get("h_output");
TH1F *h_data_2 = (TH1F*)f2->Get("h_output");
TH1F *h_data_3 = (TH1F*)f3->Get("h_output");
TH1F *h_data_4 = (TH1F*)f4->Get("h_output");
TH1F *h_data_5 = (TH1F*)f5->Get("h_output");
TH1F *h_data_6 = (TH1F*)f6->Get("h_output");
TH1F *h_data_7 = (TH1F*)f7->Get("h_output");
TH1F *h_data_8 = (TH1F*)f8->Get("h_output");
TH1F *h_data_9 = (TH1F*)f9->Get("h_output");
TH1F *h_data_10 = (TH1F*)f10->Get("h_output");
TH1F *h_data_11 = (TH1F*)f11->Get("h_output");
TH1F *h_data_12 = (TH1F*)f12->Get("h_output");
TH1F *h_data_13 = (TH1F*)f13->Get("h_output");
TH1F *h_data_14 = (TH1F*)f14->Get("h_output");
TH1F *h_data_15 = (TH1F*)f15->Get("h_output");
TH1F *h_data_16 = (TH1F*)f16->Get("h_output");
TH1F *h_data_17 = (TH1F*)f17->Get("h_output");
TH1F *h_data_18 = (TH1F*)f18->Get("h_output");
TH1F *h_data_19 = (TH1F*)f19->Get("h_output");
TH1F *h_data_20 = (TH1F*)f20->Get("h_output");
TH1F *h_data_21 = (TH1F*)f21->Get("h_output");
TH1F *h_data_22 = (TH1F*)f22->Get("h_output");
TH1F *h_data_23 = (TH1F*)f23->Get("h_output");
TH1F *h_data_24 = (TH1F*)f24->Get("h_output");

h_data_1->Sumw2();
h_data_2->Sumw2();
h_data_3->Sumw2();
h_data_4->Sumw2();
h_data_5->Sumw2();
h_data_6->Sumw2();
h_data_7->Sumw2();
h_data_8->Sumw2();
h_data_9->Sumw2();
h_data_10->Sumw2();
h_data_11->Sumw2();
h_data_12->Sumw2();
h_data_13->Sumw2();
h_data_14->Sumw2();
h_data_15->Sumw2();
h_data_16->Sumw2();
h_data_17->Sumw2();
h_data_18->Sumw2();
h_data_19->Sumw2();
h_data_20->Sumw2();
h_data_21->Sumw2();
h_data_22->Sumw2();
h_data_23->Sumw2();
h_data_24->Sumw2();

//const Int_t NBINS = 14;
//double edges[NBINS+1]={1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};

const Int_t NBINS = 23;
double edges[NBINS+1]={0.05,0.07,0.09,0.13,0.15,0.17,0.19,0.21,0.25,0.29,0.33,0.35,0.38,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9};

TH1 *h_data = new TH1D("h_data","h_data",NBINS,edges);
double content1 = h_data_1->GetBinContent(1);
double content2 = h_data_2->GetBinContent(1);
double content3 = h_data_3->GetBinContent(1);
double content4 = h_data_4->GetBinContent(1);
double content5 = h_data_5->GetBinContent(1);
double content6 = h_data_6->GetBinContent(1);
double content7 = h_data_7->GetBinContent(1);
double content8 = h_data_8->GetBinContent(1);
double content9 = h_data_9->GetBinContent(1);
double content10 = h_data_10->GetBinContent(1);
double content11 = h_data_11->GetBinContent(1);
double content12 = h_data_12->GetBinContent(1);
double content13 = h_data_13->GetBinContent(1);
double content14 = h_data_14->GetBinContent(1);
double content15 = h_data_15->GetBinContent(1);
double content16 = h_data_15->GetBinContent(1);
double content17 = h_data_15->GetBinContent(1);
double content18 = h_data_15->GetBinContent(1);
double content19 = h_data_15->GetBinContent(1);
double content20 = h_data_15->GetBinContent(1);
double content21 = h_data_15->GetBinContent(1);
double content22 = h_data_15->GetBinContent(1);
double content23 = h_data_15->GetBinContent(1);
double content24 = h_data_15->GetBinContent(1);

double err1 = h_data_1->GetBinError(1);
double err2 = h_data_2->GetBinError(1);
double err3 = h_data_3->GetBinError(1);
double err4 = h_data_4->GetBinError(1);
double err5 = h_data_5->GetBinError(1);
double err6 = h_data_6->GetBinError(1);
double err7 = h_data_7->GetBinError(1);
double err8 = h_data_8->GetBinError(1);
double err9 = h_data_9->GetBinError(1);
double err10 = h_data_10->GetBinError(1);
double err11 = h_data_11->GetBinError(1);
double err12 = h_data_12->GetBinError(1);
double err13 = h_data_13->GetBinError(1);
double err14 = h_data_14->GetBinError(1);
double err15 = h_data_15->GetBinError(1);
double err16 = h_data_16->GetBinError(1);
double err17 = h_data_17->GetBinError(1);
double err18 = h_data_18->GetBinError(1);
double err19 = h_data_19->GetBinError(1);
double err20 = h_data_20->GetBinError(1);
double err21 = h_data_21->GetBinError(1);
double err22 = h_data_22->GetBinError(1);
double err23 = h_data_23->GetBinError(1);
double err24 = h_data_24->GetBinError(1);

h_data->SetBinContent(1,content1-content2);
h_data->SetBinContent(2,content2-content3);
h_data->SetBinContent(3,content3-content4);
h_data->SetBinContent(4,content4-content5);
h_data->SetBinContent(5,content5-content6);
h_data->SetBinContent(6,content6-content7);
h_data->SetBinContent(7,content7-content8);
h_data->SetBinContent(8,content8-content9);
h_data->SetBinContent(9,content9-content10);
h_data->SetBinContent(10,content10-content11);
h_data->SetBinContent(11,content11-content12);
h_data->SetBinContent(12,content12-content13);
h_data->SetBinContent(13,content13-content14);
h_data->SetBinContent(14,content14-content15);
h_data->SetBinContent(15,content15-content16);
h_data->SetBinContent(16,content16-content17);
h_data->SetBinContent(17,content17-content18);
h_data->SetBinContent(18,content18-content19);
h_data->SetBinContent(19,content19-content20);
h_data->SetBinContent(20,content20-content21);
h_data->SetBinContent(21,content21-content22);
h_data->SetBinContent(22,content22-content23);
h_data->SetBinContent(23,content23-content24);

h_data->SetBinError(1,err1-err2);
h_data->SetBinError(2,err2-err3);
h_data->SetBinError(3,err3-err4);
h_data->SetBinError(4,err4-err5);
h_data->SetBinError(5,err5-err6);
h_data->SetBinError(6,err6-err7);
h_data->SetBinError(7,err7-err8);
h_data->SetBinError(8,err8-err9);
h_data->SetBinError(9,err9-err10);
h_data->SetBinError(10,err10-err11);
h_data->SetBinError(11,err11-err12);
h_data->SetBinError(12,err12-err13);
h_data->SetBinError(13,err13-err14);
h_data->SetBinError(14,err14-err15);
h_data->SetBinError(15,err15-err16);
h_data->SetBinError(16,err16-err17);
h_data->SetBinError(17,err17-err18);
h_data->SetBinError(18,err18-err19);
h_data->SetBinError(19,err19-err20);
h_data->SetBinError(20,err20-err21);
h_data->SetBinError(21,err21-err22);
h_data->SetBinError(22,err22-err23);
h_data->SetBinError(23,err23-err24);

divideBinWidth(h_data);
h_data->Scale(1/h_data->Integral());
h_data->Draw("e");
/*
TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],0)",2,9);
fit_fun->SetParameter(0,h_data->Integral());
fit_fun->SetParameter(1,2.5);
fit_fun->SetParameter(2,0.4);
h_data->Fit("fit_fun","I","",1.7,9);

TFile * result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_5_6_separatefit_dls_data.root","RECREATE");
h_data->Write();
fit_fun->Write();
result->Close();
*/
}
