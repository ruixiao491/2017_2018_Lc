#include <TMath.h>
#include <TF1.h>
#include <TH1F.h>
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
using namespace RooFit;
void unbinned_fit_PbPb_0_90_30_40_unbinned_cen0_10(){
/////PbPb cen0_100%

TFile *f =  new TFile("/scratch/brown/xiao147/2018PbPb_rereco_data_Dntuple_05052020_firstturn/final_masstuples/PbPb_30_40_final_mass_sig30_brown_server_halstead_server_whole.root");

TFile *f_fun = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_fit/3gaus_fit/10_40_rec/10_30_uniform_rec/pp_20_30_MC_3gaus_fit_finbins.root");


TF1 *f3 = (TF1*) f_fun->Get("f3");
double w1 = f3->GetParameter(2);
double w2 = f3->GetParameter(4);
double w3 = f3->GetParameter(6);
double r1 = f3->GetParameter(3);
double r2 = f3->GetParameter(5);
double mean_value = f3->GetParameter(1);
double float_width_parameter = 0;
TH1F *h_output = new TH1F ("h_output","output",2,0,2);



TNtuple *nt = (TNtuple*)f->Get("nt2");
TH1F *hb = new TH1F("hb","hb",42,2.108,2.444);
nt->Draw("mass>>hb");
//TH1F *hb = (TH1F*)f->Get("alpha_bin_10");
//hb->Draw("e");
double numbers = 219;
double numberb = hb->Integral();

RooRealVar mass("mass","mass",2.108,2.444);
RooDataSet ds("ds","ds",nt,mass);
//RooDataHist ds("ds","ds",mass,Import(*hb));
ds.Print();

cout<<"begin fitting"<<endl;
RooRealVar mean("mean","mean",mean_value,2.26,2.3);
//RooRealVar mean("mean","mean",mean_value,mean_value,mean_value);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar width3("width3","width3",w3,w3,w3);
RooRealVar ratio1("ratio1","ratio1",r1,r1,r1);
RooRealVar ratio2("ratio2","ratio2",r2,r2,r2);


RooRealVar p1("p1","p1",0,-1,1);
RooRealVar p2("p2","p2",0,-1,1);
RooRealVar p3("p3","p3",0,-1,1);

/*
RooRealVar p1("p1","p1",1.05243e-01,1.05243e-01,1.05243e-01);
RooRealVar p2("p2","p2",-2.56187e-02,-2.56187e-02,-2.56187e-02);
RooRealVar p3("p3","p3",1.41742e-03,1.41742e-03,1.41742e-03);
*/

//RooRealVar float_width("float_width","float_width",0.0,0.0,0.0);
RooRealVar float_width("float_width","float_width",0.1,-1,1);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooFormulaVar scale_width3("scale width3","scaled width3","width3*(1+float_width)",RooArgSet(width3,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooGaussian sigma3("sigma3","gauss(mass,mean,scale_width3)",mass,mean,scale_width3);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2,sigma3),RooArgList(ratio1,ratio2));
RooChebychev back("back","background",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*100,numbers*100);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*100,numberb*100);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));
//mass.setRange("cut_region",2.21,2.34);
mass.setRange("cut_region",2.17,2.37);

RooFitResult * r = model.fitTo(ds,Extended(kTRUE),Range("cut_region"),Minos(kTRUE),Save());
//model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE)); 
//model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444)); 
//model.fitTo(ds,Extended(kTRUE),Range(2.25,2.32)); 

RooPlot *massframe = new RooPlot("mass","mass",mass,2.108,2.444,42);
ds.plotOn(massframe,Name("ds"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1),XErrorSize(0));
TCanvas *c1 = new TCanvas("c1","c1",600,600);
c1->SetLeftMargin(0.13);
c1->SetRightMargin(0.04);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f);
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);
gStyle->SetTitleFontSize(0.06);
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




massframe->Draw();

model.plotOn(massframe,Name("back"),Components(back),LineColor(9),LineStyle(7),Range("cut_region"),NormRange("cut_region"));
model.plotOn(massframe,Name("model"),LineColor(2),Range("cut_region"),NormRange("cut_region"));

TGaxis::SetMaxDigits(4);


massframe->GetXaxis()->CenterTitle();
massframe->GetYaxis()->CenterTitle();
massframe->SetXTitle("m_{pK#pi} (GeV/c^{2})");
massframe->SetYTitle("Events/0.008 GeV/c^{2}");
massframe->SetTitleOffset(1.3,"Y");
massframe->SetTitleOffset(0.85,"X");
massframe->SetTitleFont(42,"X");
massframe->SetTitleFont(42,"Y");
massframe->SetLabelFont(42,"Y");
massframe->SetLabelFont(42,"X");
massframe->SetLabelSize(0.042,"X");
massframe->SetLabelSize(0.042,"Y");
massframe->SetTitleSize(0.048,"X");
massframe->SetTitleSize(0.048,"Y");
massframe->SetAxisRange(300,800,"Y");
massframe->Draw();


TLatex* tex;
tex = new TLatex(0.2,0.84,"30 < p_{T} < 40 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.047);
tex->SetLineWidth(2);
tex->Draw();

tex =  new TLatex(0.75,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{#font[122]{\55}}}");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.055);
tex->SetLineWidth(2);
tex->Draw();

int a = round(NumSig.getVal());
int b = abs(round(NumSig.getAsymErrorLo()));
int c = round(NumSig.getAsymErrorHi());

h_output->SetBinContent(1,a);
h_output->SetBinContent(2,a);
h_output->SetBinError(1,b);
h_output->SetBinError(2,c);

tex = new TLatex(0.2,0.66,Form("Yield: %i^{ + %i}_{ - %i} ",a,c,b));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.047);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.2,0.72,"Cent. 0-10%");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.047);
tex->SetLineWidth(2);
tex->Draw();


tex = new TLatex(0.2,0.78,"|y| < 1");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.047);
tex->SetLineWidth(2);
tex->Draw();


TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.22,0.93, "#font[61]{CMS }");
//Tl.DrawLatex(0.6,0.93, "#scale[0.8]{43.9 #mub^{-1} (5.02 TeV PbPb)}");//PbPb cen0_30
Tl.DrawLatex(0.57,0.93, "#scale[0.8]{0.58 nb^{-1} (5.02 TeV PbPb)}");//PbPb cen0_30
//for AN
TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.34,0.93, "#font[52]{Preliminary}");


auto leg = new TLegend(0.2,0.16,0.34,0.3);
leg->SetTextSize(0.045);
leg->AddEntry("ds","Data","EP");
leg->AddEntry("model","Signal+Background","L");
leg->AddEntry("back","Background","L");
leg->SetBorderSize(0);
leg->Draw();


/*
r->Print();
cout<<"EDM = "<<r->edm()<<endl;
cout<<setprecision(20)<<"-log(L) at minimum"<<r->minNll()<<endl;
*/

c1->SaveAs("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/default_change_massrange/PbPb_30_40_rec_unbinned_3gaus_cen0_10_massrange.pdf");
c1->SaveAs("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/default_change_massrange/PbPb_30_40_rec_unbinned_3gaus_cen0_10_massrange.C");

TFile *result = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/default_change_massrange/PbPb_30_40_2gaus_pol3_unbinned_rec_3gaus_cen0_10_massrange.root","RECREATE");

h_output->Write();
massframe->Write();
result->Close();




}
