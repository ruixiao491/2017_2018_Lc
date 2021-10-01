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
#define MAX_XB       20000
//signal two gaus, different mean
void fit_3gaus_1mean(double ptmin=5, double ptmax=6){
//TFile *f = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_normalized_files/10_40_rec/10_30_uniform/PbPb_pT_10_30_hits_signal_uniform_rec.root");
TFile *f = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_normalized_files/PbPb_pT_5_6_hits_signal_mass_withpT4MC_alpha007.root");

TH1F *h_whole_withcuts_sig = (TH1F*) f->Get("h_whole_withcuts_prompt_sig");
//TH1F *h_whole_withcuts_sig = (TH1F*) f->Get("h_whole_withcuts_sig");

h_whole_withcuts_sig->SetMarkerColor(2);
h_whole_withcuts_sig->SetMarkerStyle(20);
h_whole_withcuts_sig->SetMarkerSize(1.5);
TCanvas *c1 = new TCanvas("c1","c1",600,600);
c1->SetLeftMargin(0.12);
c1->SetRightMargin(0.05);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1);
gStyle->SetTitleX(0.8f); //title box x position
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);  //Title box width as fraction of pad size.
gStyle->SetTitleFontSize(0.06);


h_whole_withcuts_sig->SetTitle("5.02TeV PP");
h_whole_withcuts_sig->GetXaxis()->CenterTitle();
h_whole_withcuts_sig->GetYaxis()->CenterTitle();
h_whole_withcuts_sig->GetXaxis()->SetTitleOffset(1.0);
h_whole_withcuts_sig->GetYaxis()->SetTitleOffset(1.4);
h_whole_withcuts_sig->GetXaxis()->SetLabelOffset(0.007);
h_whole_withcuts_sig->GetYaxis()->SetLabelOffset(0.007);
h_whole_withcuts_sig->GetXaxis()->SetTitleSize(0.045);
h_whole_withcuts_sig->GetYaxis()->SetTitleSize(0.045);
h_whole_withcuts_sig->GetXaxis()->SetTitleFont(42);
h_whole_withcuts_sig->GetYaxis()->SetTitleFont(42);
h_whole_withcuts_sig->GetXaxis()->SetLabelFont(42);
h_whole_withcuts_sig->GetYaxis()->SetLabelFont(42);
h_whole_withcuts_sig->GetXaxis()->SetLabelSize(0.04);
h_whole_withcuts_sig->GetYaxis()->SetLabelSize(0.04);


h_whole_withcuts_sig->GetXaxis()->SetTitle("m_{pk#pi} (GeV/c^{2})");
h_whole_withcuts_sig->GetYaxis()->SetTitle("Entries");

//after here would do fit.
Double_t c=h_whole_withcuts_sig->GetBinWidth(1);
TF1 *f3=new TF1("f3","0.007/2*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[5]*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4])+(1-[3]-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6]))",2.1,2.45);
//TF1 *f3=new TF1("f3","0.007/4*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[5]*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4])+(1-[3]-[5])*TMath::Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6]))",2.1,2.45);
f3->SetParNames("Strength1","mean","sigma1","pro1","sigma2","pro2","sigma3");
Double_t par[7];
//f3->SetParameter(0,3000);
f3->SetParameter(0,h_whole_withcuts_sig->Integral());//pp 10-20 pthat 4 pp cuts
f3->SetParameter(1,2.286);
f3->SetParameter(2,0.003);
f3->SetParameter(3,0.17);// PbPb 8-10
f3->SetParameter(4,0.007);
f3->SetParameter(5,0.7);
f3->SetParameter(6,0.014);

//f3->SetParLimits(2,0.0004,0.009);
f3->SetParLimits(3,0,1);
f3->SetParLimits(4,0.0008,0.009);
f3->SetParLimits(5,0,1);
f3->SetParLimits(6,0.007,0.03);
//h_whole_withcuts_sig->Fit("f3","ILM","",2.223,2.335); //pp 10-20. MC 2 gaus.pp 8-10 pp6-8, new option
//h_whole_withcuts_sig->Fit("f3","ILM","",2.23,2.333); //pp 10-20. MC 2 gaus.pp 8-10 pp6-8, new option
//h_whole_withcuts_sig->Fit("f3","ILM","",2.24,2.35); //pp 10-20. MC 2 gaus.pp 8-10 pp6-8, new option
//h_whole_withcuts_sig->Fit("f3","ILM","",2.22,2.35); //pp 10-20. MC 2 gaus.pp 8-10 pp6-8, new option
//h_whole_withcuts_sig->Fit("f3","ILM","",2.25,2.33);
h_whole_withcuts_sig->Fit("f3","ILM","",2.267,2.335);
//h_whole_withcuts_sig->Fit("f3","ILM","",2.27,2.33);
//h_whole_withcuts_sig->Fit("f3","ILM","",2.263,2.35);
h_whole_withcuts_sig->Draw("e");
f3->GetParameters(par);
TF1 *f1=new TF1("f1","0.007/2*[0]*[1]*TMath::Gaus(x,[2],[3])/(sqrt(2*3.14159)*[3])",2.1,2.45);
f1->SetParameter(0,par[0]);
f1->SetParameter(1,par[3]);
f1->SetParameter(2,par[1]);
f1->SetParameter(3,par[2]);
TF1 *f2=new TF1("f2","0.007/2*[0]*[1]*TMath::Gaus(x,[2],[3])/(sqrt(2*3.14159)*[3])",2.1,2.45);
f2->SetParameter(0,par[0]);
f2->SetParameter(1,par[5]);
f2->SetParameter(2,par[1]);
f2->SetParameter(3,par[4]);
f2->SetLineColor(6);
f1->SetLineColor(3);
f3->SetLineColor(4);
f1->Draw("same");
f2->Draw("same");
f3->Draw("same");
TF1 *f4 = new TF1("f4","0.007/2*[0]*(1-[1]-[4])*TMath::Gaus(x,[2],[3])/(sqrt(2*3.14159)*[3])",2.1,2.45);
f4->SetParameter(0,par[0]);
f4->SetParameter(1,par[3]);
f4->SetParameter(4,par[5]);
f4->SetParameter(2,par[1]);
f4->SetParameter(3,par[6]);
f4->Draw("same");



TLatex* tex;
tex = new TLatex(0.18,0.79,Form("%.1f < p_{T} < %.1f GeV/c", ptmin, ptmax));
//tex = new TLatex(0.18,0.79,"12.5 < p_{T} < 15 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();



tex = new TLatex(0.18,0.73,"|y| < 1");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
/*
tex = new TLatex(0.18,0.83,"cen: 0-30%");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
*/
TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.11,0.965, "#font[61]{CMS}");
Tl.DrawLatex(0.58,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

TLatex Tl2;
Tl2.SetNDC();
Tl2.SetTextAlign(12);
Tl2.SetTextSize(0.05*0.75);
Tl2.SetTextFont(42);
Tl2.DrawLatex(0.22,0.965, "#font[52]{Simulations}");

c1->SaveAs(Form("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_fit/3gaus_fit/10_40_rec/10_30_uniform_rec/pp_%i_%i_MC_3gaus_fit_finebins.pdf",int(ptmin), int(ptmax)));
TFile *result = new TFile(Form("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_fit/3gaus_fit/10_40_rec/10_30_uniform_rec/pp_%i_%i_MC_3gaus_fit_finbins.root",int(ptmin),int(ptmax)),"RECREATE");

h_whole_withcuts_sig->Write();
f1->Write();
f2->Write();
f3->Write();
f4->Write();
result->Close();

}
