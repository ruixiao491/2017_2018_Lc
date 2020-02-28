#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TStyle.h>
#include <TF1.h>

TH1F *h_prompt_MC;
TH1F *h_nonprompt_MC;

Double_t ftotal(Double_t *x, Double_t *par){
	Double_t xx = x[0];
	Int_t bin = h_nonprompt_MC->GetXaxis()->FindBin(xx);
	Double_t br = par[1]*(1-par[0])*h_nonprompt_MC->GetBinContent(bin)/h_nonprompt_MC->Integral();
	Double_t sr = par[1]*par[0]*h_prompt_MC->GetBinContent(bin)/h_prompt_MC->Integral();
	return sr+ br;


}

Double_t funNonPrompt(Double_t *x, Double_t *par){
	Double_t xx = x[0];
	Int_t bin = h_nonprompt_MC->GetXaxis()->FindBin(xx);
	Double_t br = par[1]*(1-par[0])*h_nonprompt_MC->GetBinContent(bin)/h_nonprompt_MC->Integral();
	return br;


}

Double_t funPrompt(Double_t *x, Double_t *par){
	Double_t xx = x[0];
	Int_t bin = h_nonprompt_MC->GetXaxis()->FindBin(xx);
	Double_t sr = par[1]*par[0]*h_prompt_MC->GetBinContent(bin)/h_prompt_MC->Integral();
	return sr;


}

void fit_data_DCA_withMC_DCA(){

TFile *MC_DCA = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/dca_scan_BDT_first_sight/MC_dca_samebin_withdata/10_20/weight_sum/pp_10_20_MC_DCA_samwwithdata.root");
TFile *data_DCA = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/dca_scan_BDT_first_sight/data_dN_dDCA/distribution/pp_10_20_Data_Dca_distribution.root");

/*
TFile *MC_DCA =  new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/dca_scan_BDT_first_sight/MC_dca_samebin_withdata/8_10/weight_sum/pp_8_10_MC_DCA_samwwithdata.root");
TFile *data_DCA = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/dca_scan_BDT_first_sight/data_dN_dDCA/distribution/pp_8_10_Data_Dca_distribution.root");
*/

h_prompt_MC = (TH1F*) MC_DCA->Get("prompt_whole_10_20")->Clone("h_prompt_MC");
h_nonprompt_MC = (TH1F*) MC_DCA->Get("nonprompt_whole_10_20")->Clone("h_nonprompt_MC");
TH1F *h_data_DCA = (TH1F*) data_DCA->Get("h_data_dca")->Clone("h_data_DCA");
TF1 *ftot = new TF1("ftot",ftotal,0,10,2);
double total_yield=h_data_DCA->Integral();
cout<<total_yield<<endl;
ftot->SetParameter(0,0.7);
ftot->SetParameter(1,total_yield);
ftot->SetParLimits(0,0,1);
ftot->SetParLimits(1,0,2*total_yield);
h_data_DCA->Fit("ftot","b");

cout<<ftot->GetParameter(0)<<endl;
TH1F *h_PNP_ratio =  new TH1F ("h_PNP_ratio","h_PNP_ratio",10,0,1);
h_PNP_ratio->Sumw2();
h_PNP_ratio->SetBinContent(1,ftot->GetParameter(0));

TF1* fNP = new TF1("fNP",&funNonPrompt, 0,0.16, 2);
fNP->SetParameters(ftot->GetParameter(0),ftot->GetParameter(1));
fNP->SetLineColor(4);
fNP->SetFillStyle(3001);
fNP->SetFillColor(4);
fNP->Draw("same");

TF1* fP = new TF1("fP",&funPrompt, 0, 0.16, 2);
fP->SetParameters(ftot->GetParameter(0),ftot->GetParameter(1));
fP->SetLineColor(2);
fP->SetFillStyle(3006);
fP->SetFillColor(2);
fP->Draw("same");

/*
TFile * result = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/dca_scan_BDT_first_sight/data_dN_dDCA/PNP_fit_data_withMC/pp_8_10_PNP_ratio.root","RECREATE");
h_PNP_ratio->Write();
result->Close();
*/
}

