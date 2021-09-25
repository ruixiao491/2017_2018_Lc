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

void draw_data_5_6_dls()
{
 TFile *f1 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_4_5.root");
 TFile *f2 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_5_6.root");
 TFile *f3 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_6_7.root");
 TFile *f4 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_7_8.root");
 TFile *f5 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_8_9.root");
 TFile *f6 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_9_10.root");
 TFile *f7 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_10_11.root");
 TFile *f8 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_11_12.root");
 TFile *f9 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_12_13.root");
 TFile *f10 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_13_14.root");
 TFile *f11 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_14_15.root");
 TFile *f12 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_15_16.root");
 TFile *f13 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/5_6_bins/pT_5_6_dlsscan_16_17.root");

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

//const Int_t NBINS = 14;
//double edges[NBINS+1]={1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};

const Int_t NBINS = 13;
double edges[NBINS+1]={2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};

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

h_data->SetBinContent(1,content1);
h_data->SetBinContent(2,content2);
h_data->SetBinContent(3,content3);
h_data->SetBinContent(4,content4);
h_data->SetBinContent(5,content5);
h_data->SetBinContent(6,content6);
h_data->SetBinContent(7,content7);
h_data->SetBinContent(8,content8);
h_data->SetBinContent(9,content9);
h_data->SetBinContent(10,content10);
h_data->SetBinContent(11,content11);
h_data->SetBinContent(12,content12);
h_data->SetBinContent(13,content13);

h_data->SetBinError(1,err1);
h_data->SetBinError(2,err2);
h_data->SetBinError(3,err3);
h_data->SetBinError(4,err4);
h_data->SetBinError(5,err5);
h_data->SetBinError(6,err6);
h_data->SetBinError(7,err7);
h_data->SetBinError(8,err8);
h_data->SetBinError(9,err9);
h_data->SetBinError(10,err10);
h_data->SetBinError(11,err11);
h_data->SetBinError(12,err12);
h_data->SetBinError(13,err13);

divideBinWidth(h_data);
h_data->Scale(1/h_data->Integral());
h_data->Draw("e");
//TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],0)",2,9);
TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],1)+[3]",-9,9);
//fit_fun->SetParameter(0,h_data->Integral());
fit_fun->SetParameter(1,2.6);
//fit_fun->SetParLimits(1,2.3,2.9);
fit_fun->SetParameter(2,0.4);
h_data->Fit("fit_fun","I","",2,5);
h_data->Fit("fit_fun","I","",2,9);
h_data->Fit("fit_fun","I","",2,9);

cout<<fit_fun->Integral(2,9)<<endl;

TFile * result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_5_6_separatefit_dlsbins_update_data.root","RECREATE");
h_data->Write();
fit_fun->Write();
result->Close();

}
