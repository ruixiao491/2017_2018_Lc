#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
#include <TF1.h>
void fit_MC_alpha(TString branch, TString outfile, TString outfigure)
{
 TFile *f_MC = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/test_alpha_MC.root");
 TH1F *h_MC = (TH1F*) f_MC->Get(branch);

 TCanvas *c1 = new TCanvas("c1","c1",600,600);
 TF1 *fit_fun = new TF1("fit_fun","[0]*exp([1]+[2]*x)+[3]",0,0.2);
 fit_fun->SetParameter(0,5.38547e-02);
 fit_fun->SetParameter(1,3);
 fit_fun->SetParameter(2,-2.26198e+01);
 fit_fun->SetParameter(3,0);
 h_MC->Fit("fit_fun","I","",0,0.2);
 h_MC->Draw("e");
 fit_fun->Draw("same");

 c1->SaveAs(Form("%s",outfigure.Data()));
 TFile *outf = TFile::Open(Form("%s",outfile.Data()),"recreate");
 h_MC->Write();
 fit_fun->Write();
 outf->Close();



}
