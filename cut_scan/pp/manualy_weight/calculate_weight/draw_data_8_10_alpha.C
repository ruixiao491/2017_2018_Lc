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

void draw_data_8_10_alpha()
{
 TFile *f1 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/8_10_bins/pT_8_10_alphascan_0_1.root");
 TFile *f2 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/8_10_bins/pT_8_10_alphascan_1_2.root");
 TFile *f3 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/8_10_bins/pT_8_10_alphascan_2_3.root");
 TFile *f4 = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/8_10_bins/pT_8_10_alphascan_3_4.root");

TH1F *h_data_1 = (TH1F*)f1->Get("h_output");
TH1F *h_data_2 = (TH1F*)f2->Get("h_output");
TH1F *h_data_3 = (TH1F*)f3->Get("h_output");
TH1F *h_data_4 = (TH1F*)f4->Get("h_output");

h_data_1->Sumw2();
h_data_2->Sumw2();
h_data_3->Sumw2();
h_data_4->Sumw2();

//const Int_t NBINS = 14;
//double edges[NBINS+1]={1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5};

const Int_t NBINS = 4;
double edges[NBINS+1]={0.02,0.04,0.06,0.1,0.17};

TH1 *h_data = new TH1D("h_data","h_data",NBINS,edges);
double content1 = h_data_1->GetBinContent(1);
double content2 = h_data_2->GetBinContent(1);
double content3 = h_data_3->GetBinContent(1);
double content4 = h_data_4->GetBinContent(1);

double err1 = h_data_1->GetBinError(1);
double err2 = h_data_2->GetBinError(1);
double err3 = h_data_3->GetBinError(1);
double err4 = h_data_4->GetBinError(1);

h_data->SetBinContent(1,content1);
h_data->SetBinContent(2,content2);
h_data->SetBinContent(3,content3);
h_data->SetBinContent(4,content4);

h_data->SetBinError(1,err1);
h_data->SetBinError(2,err2);
h_data->SetBinError(3,err3);
h_data->SetBinError(4,err4);

divideBinWidth(h_data);
h_data->Scale(1/h_data->Integral());
h_data->Draw("e");

//TF1 *fit_fun = new TF1("fit_fun","[0]*exp([1]+[2]*x)+[3]",0,0.2);
TF1 *fit_fun = new TF1("fit_fun","[0]*exp([1]+[2]*x)",0,0.2);
fit_fun->SetParameter(0,5.38547e-02);
fit_fun->SetParameter(1,3);
fit_fun->SetParameter(2,-2.26198e+01);
fit_fun->SetParameter(3,0);
h_data->Fit("fit_fun","I","",0,0.2);
cout<<fit_fun->Eval(0.2)<<endl;

//fit_fun->SetParameter(0,h_data->Integral());
//fit_fun->SetParameter(1,2.6);
//fit_fun->SetParLimits(1,2.3,2.9);
//fit_fun->SetParameter(2,0.4);
//h_data->Fit("fit_fun","I","",2,5);
//h_data->Fit("fit_fun","I","",2,9);
//h_data->Fit("fit_fun","I","",2,9);


TFile * result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_8_10_separatefit_alphabins_update_data.root","RECREATE");
h_data->Write();
fit_fun->Write();
result->Close();

}
