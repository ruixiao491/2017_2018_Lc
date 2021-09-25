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

void draw_data_10_20_kaon()
{
 TFile *f1 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_1.root");
 TFile *f2 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_3.root");
 TFile *f3 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_4.root");
 TFile *f4 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_5.root");
 TFile *f5 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_6.root");
 TFile *f6 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_7.root");
 TFile *f7 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_8.root");
 TFile *f8 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/10_20_bins/pT_10_20_kaonscan_gr_9.root");

TH1F *h_data_1 = (TH1F*)f1->Get("h_output");
TH1F *h_data_2 = (TH1F*)f2->Get("h_output");
TH1F *h_data_3 = (TH1F*)f3->Get("h_output");
TH1F *h_data_4 = (TH1F*)f4->Get("h_output");
TH1F *h_data_5 = (TH1F*)f5->Get("h_output");
TH1F *h_data_6 = (TH1F*)f6->Get("h_output");
TH1F *h_data_7 = (TH1F*)f7->Get("h_output");
TH1F *h_data_8 = (TH1F*)f8->Get("h_output");

h_data_1->Sumw2();
h_data_2->Sumw2();
h_data_3->Sumw2();
h_data_4->Sumw2();
h_data_5->Sumw2();
h_data_6->Sumw2();
h_data_7->Sumw2();
h_data_8->Sumw2();

//const Int_t NBINS = 14;
//double edges[NBINS+1]={1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};

const Int_t NBINS = 7;
double edges[NBINS+1]={0.05,0.15,0.2,0.25,0.3,0.35,0.4,0.45};


TH1 *h_data = new TH1D("h_data","h_data",NBINS,edges);
double content1 = h_data_1->GetBinContent(1);
double content2 = h_data_2->GetBinContent(1);
double content3 = h_data_3->GetBinContent(1);
double content4 = h_data_4->GetBinContent(1);
double content5 = h_data_5->GetBinContent(1);
double content6 = h_data_6->GetBinContent(1);
double content7 = h_data_7->GetBinContent(1);
double content8 = h_data_8->GetBinContent(1);

double err1 = h_data_1->GetBinError(1);
double err2 = h_data_2->GetBinError(1);
double err3 = h_data_3->GetBinError(1);
double err4 = h_data_4->GetBinError(1);
double err5 = h_data_5->GetBinError(1);
double err6 = h_data_6->GetBinError(1);
double err7 = h_data_7->GetBinError(1);
double err8 = h_data_8->GetBinError(1);

h_data->SetBinContent(1,content1-content2);
h_data->SetBinContent(2,content2-content3);
h_data->SetBinContent(3,content3-content4);
h_data->SetBinContent(4,content4-content5);
h_data->SetBinContent(5,content5-content6);
h_data->SetBinContent(6,content6-content7);
h_data->SetBinContent(7,content7-content8);

cout<<content1<<"        "<<content2<<endl;

for (int i=1; i<8;i++)
{
	cout<<h_data->GetBinContent(i)<<endl;
}
cout<<"err:   "<<h_data->GetBinContent(1)*sqrt(fabs(err1*err1-err2*err2))<<endl;
cout<<"check1: "<<err1*err1-err2*err2<<endl;
cout<<"err1:  "<<err1<<"          "<<err2<<endl;
cout<<"test:  "<<sqrt(fabs(err1*err1-err2*err2))<<endl;

h_data->SetBinError(1,sqrt(fabs(err1*err1-err2*err2)));
h_data->SetBinError(2,sqrt(fabs(err2*err2-err3*err3)));
h_data->SetBinError(3,sqrt(fabs(err3*err3-err4*err4)));
h_data->SetBinError(4,sqrt(fabs(err4*err4-err5*err5)));
h_data->SetBinError(5,sqrt(fabs(err5*err5-err6*err6)));
h_data->SetBinError(6,sqrt(fabs(err6*err6-err7*err7)));
h_data->SetBinError(7,sqrt(fabs(err7*err7-err8*err8)));

divideBinWidth(h_data);
h_data->Scale(1/h_data->Integral());
h_data->Draw("e");
/*
//TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],0)",2,9);
TF1 *fit_fun = new TF1("fit_fun","[0]*TMath::Landau(x,[1],[2],1)+[3]",-9,12);
//fit_fun->SetParameter(0,h_data->Integral());
fit_fun->SetParameter(1,2.6);
//fit_fun->SetParLimits(1,2.3,2.9);
fit_fun->SetParameter(2,0.4);
h_data->Fit("fit_fun","I","",1,5);
h_data->Fit("fit_fun","I","",1,12);
h_data->Fit("fit_fun","I","",1,12);


TFile * result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_20_separatefit_dlsbins_update_data.root","RECREATE");
h_data->Write();
fit_fun->Write();
result->Close();
*/
}
