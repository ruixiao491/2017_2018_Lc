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
#include <RooDataSet.h>
#include <RooFormulaVar.h>
#include <RooRealVar.h>
#include <TFile.h>
#include <TH1F.h>
#include <RooGaussian.h>
#include <RooPlot.h>
#include <RooChebychev.h>
#include <RooAddPdf.h>
#include <TLegend.h>
#include <RooFitResult.h>

using namespace RooFit;
void unbinned_fit_test_modified_PbPb_trytomanytimes_10_12_5_pol2(TString nt_number, TString outfile, TString outfigure, int range1, int range2){
//pp 10-20
TFile * f = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/manually_cut_scan_weight_whole.root");
//pp 10-20 pol2
TFile *f_fun = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_3_100_BDTG/2gaus_1fit/pp_10_12_5_BDT4_100_MC_2gaus_fit_hits.root");


auto *f3 = (TF1*) f_fun->Get("f3");
double w1 = f3->GetParameter(2);
double w2 = f3->GetParameter(4);
double r1 = f3->GetParameter(3);
double mean_value = 2.28700e+00;
TH1F *h_output = new TH1F ("h_output","output",2,0,2);

//TNtuple *nt1 = (TNtuple*)f->Get("nt6");
TNtuple *nt1 = (TNtuple*)f->Get(nt_number);
TH1F *hb = new TH1F("hb","hb",43,2.1,2.444);
nt1->Draw("mass>>hb");
double numbers = 2451;
double numberb = hb->Integral();

RooRealVar mass("mass","mass",2.1,2.444);
RooDataSet ds("ds","ds",nt1,mass);
ds.Print();
RooPlot *massframe = new RooPlot("mass","mass",mass,2.108,2.444,42);
ds.plotOn(massframe,Name("ds"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1),XErrorSize(0));
TCanvas *c1 = new TCanvas("c1","c1",600,600);
c1->SetLeftMargin(0.12);
c1->SetRightMargin(0.05);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f);
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);
gStyle->SetTitleFontSize(0.06);
///try to remove the horizontal error bar
gStyle->SetErrorX(kFALSE);

//try the TStyle setting for canvas
gStyle->SetCanvasBorderMode(0);
gStyle->SetCanvasColor(kWhite);
gStyle->SetCanvasDefX(0);//position on screen
gStyle->SetCanvasDefY(0);
///TStyle setting for the Margins:
gStyle->SetPadTopMargin(0.05);
gStyle->SetPadBottomMargin(0.13);
gStyle->SetPadLeftMargin(0.16);
gStyle->SetPadRightMargin(0.02);
//TStyle setting about the Postscript options
gStyle->SetPaperSize(20.,20.);
//TStyle setting about the frame
gStyle->SetFrameBorderMode(0);
gStyle->SetFrameBorderSize(1);
gStyle->SetFrameFillColor(0);
gStyle->SetFrameFillStyle(0);
gStyle->SetFrameLineColor(1);
gStyle->SetFrameLineStyle(1);
gStyle->SetFrameLineWidth(1);

//massframe->SetAxisRange(7700,12500,"Y");//without hits
massframe->SetAxisRange(range1,range2,"Y");//without hits
massframe->Draw();
cout<<"begin fitting"<<endl;
RooRealVar mean("mean","mean",mean_value,mean_value,mean_value);
//RooRealVar mean("mean","mean",mean_value,2.21,2.36);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);

RooRealVar p1("p1","p1",0,-1,1);
RooRealVar p2("p2","p2",0,-1,1);
RooRealVar p3("p3","p3",0,-1,1);

//RooRealVar p1("p1","p1",0,-1,1);
//RooRealVar p2("p2","p2",0,-1,1);
RooRealVar float_width("float_width","float_width",6.07734e-02,6.07734e-02,6.07734e-02);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooChebychev back("back","second polynomial",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*100, numbers*100);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*100, numberb*100);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));

//model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE)); 
RooFitResult * r = model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Save());

//model.plotOn(massframe,Name("model"),Range(2.108,2.444),LineColor(2));
//model.plotOn(massframe,Name("back"),Components(back),LineColor(9),LineStyle(kDashed));
model.plotOn(massframe,Name("back"),Components(back),LineColor(9),LineStyle(7));
model.plotOn(massframe,Name("model"),Range(2.108,2.444),LineColor(2));

//RooFitResult * r = model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE),Save());

massframe->GetXaxis()->CenterTitle();
massframe->GetYaxis()->CenterTitle();
massframe->SetXTitle("m_{pk#pi} (GeV/c^{2})");
massframe->SetYTitle("Events/0.008 GeV/c^{2}");
massframe->SetTitleOffset(1.5,"Y");
massframe->SetTitleOffset(0.9,"X");
massframe->SetTitleFont(42,"X");
massframe->SetTitleFont(42,"Y");
massframe->SetLabelFont(42,"Y");
massframe->SetLabelFont(42,"X");
massframe->SetLabelSize(0.033,"X");
massframe->SetLabelSize(0.033,"Y");
massframe->SetTitleSize(0.045,"X");
massframe->SetTitleSize(0.04,"Y");
massframe->SetAxisRange(4500,7500,"Y");///separate pt train
massframe->Draw();



TLatex* tex;
tex = new TLatex(0.16,0.85,"10 < p_{T} < 12.5 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex =  new TLatex(0.75,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{#font[122]{\55}}}");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.055);
tex->SetLineWidth(2);
tex->Draw();


int a = round(NumSig.getVal());
int b = round(NumSig.getError());
tex = new TLatex(0.16,0.75,Form("Raw yield: %i #pm %i ",a,b));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
tex = new TLatex(0.16,0.8,"|y| < 1");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
/*
TLatex Tl; 
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.045);
Tl.SetTextFont(42);
Tl.SetTextOffset(0.1);
Tl.DrawLatex(0.1,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.22,0.93, "#font[52]{Preliminary}");
Tl.DrawLatex(0.59,0.93, "#scale[0.8]{38.2 nb^{-1} (5.02 TeV)}");//pp
h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);
*/
TLatex Tl; 
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.12,0.93, "#font[61]{CMS }");
//Tl.DrawLatex(0.63,0.93, "#scale[0.8]{38.2 nb^{-1} (5.02 TeV pp)}");//pp
Tl.DrawLatex(0.63,0.93, "#scale[0.8]{252 nb^{-1} (5.02 TeV pp)}");//pp

h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);


TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.23,0.93, "#font[52]{Preliminary}");

auto leg = new TLegend(0.16,0.16,0.34,0.3);
leg->SetTextSize(0.04);
leg->AddEntry("ds","Data","EP");
leg->AddEntry("model","Signal+Background","L");
leg->AddEntry("back","Background","l");
leg->SetBorderSize(0);
leg->Draw();

c1->SaveAs(Form("%s",outfigure.Data()));
TFile *outf = TFile::Open(Form("%s",outfile.Data()),"recreate");
h_output->Write();
massframe->Write();
outf->Close();

}
