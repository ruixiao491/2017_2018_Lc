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
#include <TLatex.h>
#include <TGaxis.h>
#include <TLegend.h>
#include <TFitResultPtr.h>
#include <TFitResult.h>
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

void fit_data_DCA_withMC_DCA(TString input_MC, TString input_data, TString output, int ptmin, double ptmax, TString outputgif, int resolution){

TFile *MC_DCA = new TFile(input_MC);
TFile *data_DCA = new TFile(input_data);

TCanvas *c1 = new TCanvas("c1","c1",600,1200);
c1->Divide(1,2);
gPad->SetLeftMargin(0.2);
c1->cd(1);
gPad->SetLeftMargin(0.155);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gPad->SetLogy();
//gPad->SetLogx();
//TFitResultPtr fitResult;
int fitStatus = 1;

h_prompt_MC = (TH1F*) MC_DCA->Get("prompt_whole_10_20")->Clone("h_prompt_MC");
h_nonprompt_MC = (TH1F*) MC_DCA->Get("nonprompt_whole_10_20")->Clone("h_nonprompt_MC");
TH1F *h_data_DCA = (TH1F*) data_DCA->Get("h_data_dca")->Clone("h_data_DCA");
TF1 *ftot = new TF1("ftot",ftotal,0,0.1,2);
double total_yield=h_data_DCA->Integral();
cout<<total_yield<<endl;
ftot->SetParameter(0,0.84);
ftot->SetParameter(1,total_yield);
ftot->SetParLimits(0,0,1);
ftot->SetParLimits(1,0,2*total_yield);
h_data_DCA->Fit("ftot","S0");
h_data_DCA->Fit("ftot","S0");
TFitResultPtr fitResult = h_data_DCA->Fit("ftot","ES0");
fitStatus = fitResult->Status();
cout<<"MC:  "<<h_prompt_MC->GetBinWidth(2)<<endl;
cout<<"data: "<<h_data_DCA->GetBinWidth(2)<<endl;
//cout<<"fit precision: "<<TFitter::GetPrecision()<<endl;

TGaxis::SetMaxDigits(3);
h_data_DCA->SetMarkerColor(1);
h_data_DCA->SetMarkerStyle(20);
h_data_DCA->SetMarkerSize(1);
h_data_DCA->GetXaxis()->CenterTitle();
h_data_DCA->GetYaxis()->CenterTitle();
h_data_DCA->GetXaxis()->SetTitleOffset(1.0);
h_data_DCA->GetYaxis()->SetTitleOffset(1.4);
h_data_DCA->GetXaxis()->SetLabelOffset(0.007);
h_data_DCA->GetYaxis()->SetLabelOffset(0.007);
h_data_DCA->GetXaxis()->SetTitleSize(0.045);
h_data_DCA->GetYaxis()->SetTitleSize(0.045);
h_data_DCA->GetXaxis()->SetTitleFont(42);
h_data_DCA->GetYaxis()->SetTitleFont(42);
h_data_DCA->GetXaxis()->SetLabelFont(42);
h_data_DCA->GetYaxis()->SetLabelFont(42);
h_data_DCA->GetXaxis()->SetLabelSize(0.04);
h_data_DCA->GetYaxis()->SetLabelSize(0.04);
h_data_DCA->GetXaxis()->SetTitle("DCA (cm)");
h_data_DCA->GetYaxis()->SetTitle("dN / d(DCA) (cm^{-1})");
h_data_DCA->SetAxisRange(100,h_data_DCA->GetMaximum()*3.,"Y");
h_data_DCA->Draw("e");

cout<<ftot->GetParameter(0)<<endl;
TH1F *h_PNP_ratio =  new TH1F ("h_PNP_ratio","h_PNP_ratio",10,0,1);
h_PNP_ratio->Sumw2();
h_PNP_ratio->SetBinContent(1,ftot->GetParameter(0));



const Int_t NBINS = 3;
//double edges[NBINS +1]={0,0.0016,0.0032,0.0048,0.1};//12.5-15

//double edges[NBINS +1]={0,0.0016,0.0032,0.0048,0.0064,0.1};//15-20
//double edges[NBINS +1]={0,0.0016,0.0032,0.0048,0.008,0.016,0.1};//20-30
//double edges[NBINS +1]={0,0.0016,0.0032,0.1};//12.5-15 cen0-10
//double edges[NBINS +1]={0,0.001,0.0016,0.0032,0.1};//15-20 cen0-10
//double edges[NBINS +1]={0,0.001,0.0016,0.0096,0.1};//20-30 cen0-10
//double edges[NBINS +1]={0,0.0032,0.0064,0.1};//10-12.5 cen0-90
//double edges[NBINS +1]={0,0.0016,0.0048,0.1};//10-12.5 cen0-90
//double edges[NBINS +1]={0,0.0048,0.008,0.1};//30-40 cen0-90
double edges[NBINS +1]={0,0.0016,0.0096,0.1};//30-40 cen0-90


TH1 *h_tot = new TH1D("h_tot","h_tot",NBINS,edges);
TH1 *h_np = new TH1D("h_np","h_np",NBINS,edges);

//h_tot = ftot->DoCreateHistogram(0,0.16,true);

for (int i=1; i<h_tot->GetNbinsX()+1;i++)
{
	h_tot->SetBinContent(i,ftot->Eval((edges[i-1]+edges[i])/2));
}

TH1* h_tot2 = (TH1*)h_tot->Clone("h_tot2");
h_tot2->SetLineColor(2);
h_tot2->SetFillStyle(3022);
h_tot2->SetFillColor(2);
h_tot2->Draw("histsame");

TF1* fNP = new TF1("fNP",&funNonPrompt, 0,0.1,2);
fNP->SetParameters(ftot->GetParameter(0),ftot->GetParameter(1));
//h_np = fNP->DoCreateHistogram(0,0.1,true);
for (int i=1; i<h_np->GetNbinsX()+1;i++)
{
	h_np->SetBinContent(i,fNP->Eval((edges[i-1]+edges[i])/2));
}
TH1 *h_np2 = (TH1*) h_np->Clone("h_np2");
h_np2->SetLineColor(4);
h_np2->SetFillStyle(3013);
h_np2->SetFillColor(4);
h_np2->Draw("same");

TF1* fP = new TF1("fP",&funPrompt, 0, 0.1, 2);
fP->SetParameters(ftot->GetParameter(0),ftot->GetParameter(1));
fP->SetLineColor(5);
fP->SetFillStyle(3015);
fP->SetFillColorAlpha(5,0.35);


TLatex* tex;
//tex = new TLatex(0.22,0.81,Form("%.1f < p_{T} < %i GeV/c", ptmin, ptmax));
tex = new TLatex(0.22,0.79,Form("%i < p_{T} < %.1f GeV/c", ptmin, ptmax));
//tex = new TLatex(0.22,0.81,Form("%i < p_{T} < %i GeV/c", ptmin, ptmax));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.42,0.7,Form("resolution effect scale %i%%",resolution));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.42,0.66,Form("Prompt fraction %0.2f #pm %0.2f",ftot->GetParameter(0),ftot->GetParError(0)));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.22,0.75,"|y| < 1");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl; 
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.15,0.92, "#font[61]{CMS}");
Tl.DrawLatex(0.5,0.92, "#scale[0.8]{PbPb 0.58 nb^{-1} (5.02 TeV)}");

TLatex Tl2;
Tl2.SetNDC();
Tl2.SetTextAlign(12);
Tl2.SetTextSize(0.05*0.75);
Tl2.SetTextFont(42);
Tl2.DrawLatex(0.26,0.92, "#font[52]{Preliminary}");


auto * leg1 = new TLegend(0.42,0.5,0.71,0.65);
leg1->SetTextSize(0.037);
leg1->AddEntry("h_data_DCA","Data","ple");
leg1->AddEntry("h_np2","Nonprompt component","f");
leg1->AddEntry("h_tot2","Total","f");
leg1->SetTextFont(42);
leg1->SetBorderSize(0);
leg1->Draw();

c1->cd(2);
gPad->SetLeftMargin(0.155);
TH1 *h_data_cp = new TH1D("h_data_cp","h_data_cp",NBINS,edges);

h_data_cp->SetMarkerColor(1);
h_data_cp->SetMarkerStyle(20);
h_data_cp->SetMarkerSize(1.0);
h_data_cp->GetXaxis()->CenterTitle();
h_data_cp->GetYaxis()->CenterTitle();
h_data_cp->GetXaxis()->SetTitleOffset(1.0);
h_data_cp->GetYaxis()->SetTitleOffset(1.4);
h_data_cp->GetXaxis()->SetLabelOffset(0.007);
h_data_cp->GetYaxis()->SetLabelOffset(0.007);
h_data_cp->GetXaxis()->SetTitleSize(0.045);
h_data_cp->GetYaxis()->SetTitleSize(0.045);
h_data_cp->GetXaxis()->SetTitleFont(42);
h_data_cp->GetYaxis()->SetTitleFont(42);
h_data_cp->GetXaxis()->SetLabelFont(42);
h_data_cp->GetYaxis()->SetLabelFont(42);
h_data_cp->GetXaxis()->SetLabelSize(0.04);
h_data_cp->GetYaxis()->SetLabelSize(0.04);
h_data_cp->GetXaxis()->SetTitle("DCA (cm)");
h_data_cp->GetYaxis()->SetTitle("data / fit");
//cout<<h_data_cp->GetNbinsX()<<"   "<<h_tot->GetNbinsX()<<endl;
TH1 *h_tot3 = new TH1D("h_tot3","h_tot3",NBINS,edges);

for (int i=1; i<h_data_cp->GetNbinsX()+1;i++)
{
	h_data_cp->SetBinContent(i,h_data_DCA->GetBinContent(i)/ftot->Eval((edges[i-1]+edges[i])/2));
	h_data_cp->SetBinError(i,h_data_DCA->GetBinError(i)/ftot->Eval((edges[i-1]+edges[i])/2));
	//cout<<h_data_cp->GetBinContent(i)<<"       "<<h_data_cp->GetBinError(i)<<endl;
}

h_data_cp->Draw("e");

TLine *l = new TLine(0,1,0.1,1);
l->SetLineStyle(9);
l->SetLineColor(8);
l->SetLineWidth(3);
l->Draw("same");

c1->SaveAs(Form("%s",outputgif.Data()));

cout<<"chi2 / NDF: "<< fitResult->Chi2()<<" / "<<fitResult->Ndf()<<endl;
h_PNP_ratio->SetBinContent(2,fitResult->Chi2());

TFile * result = new TFile(Form("%s",output.Data()),"RECREATE");
h_PNP_ratio->Write();
result->Close();

}

