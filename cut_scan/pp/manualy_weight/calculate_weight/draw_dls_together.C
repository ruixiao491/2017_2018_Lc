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

void draw_dls_together(){
TFile *f_data=new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_20_separatefit_dlsbins_update_data_2.root");
TFile *f_MC_old=new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/test_MC_dls.root");
TFile *f_MC_new=new TFile("/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_dlsalpha_weight/pT10_MC_1020_combine/Lambda1520_pt10_MC_BDTG_pT3_100_5_cutvariable_0_1_2_3_5_DATA_check_corected.root");

TH1F *h_data = (TH1F*)f_data->Get("h_data");
TH1F *h_MC_old = (TH1F*) f_MC_old->Get("h_dls_10_20");
TH1F *h_MC_new = (TH1F*) f_MC_new->Get("h_dls_10_20_corrected");


h_MC_old->SetLineColor(4);


h_data->SetLineColor(2);
//h_data->Scale(1./h_data->Integral(2,8.5));
h_data->Draw("e");
h_MC_old->Draw("esame");
h_MC_new->SetLineColor(8);
h_MC_new->Scale(1./h_MC_new->Integral());
h_MC_new->Draw("esame");

auto leg = new TLegend(0.59,0.62,0.81,0.83);
leg->AddEntry(h_MC_old,"MC old");
leg->AddEntry(h_data,"data");
leg->AddEntry(h_MC_new,"MC new");
leg->SetBorderSize(0);
leg->Draw();







}
