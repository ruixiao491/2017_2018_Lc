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
using namespace RooFit;
void unbinned_fit_test_modified_PbPb_trytomanytimes_6_8_pol2(){
//pp 10-20
TFile * f = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/masstuples_withfill_3_100_noHIZero7_nopartofMB3.root");

//6-8
TFile *f_fun = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/signalectraction/forAN_plot/change_fit_function/pp/pol3/6_8_pp_officialTMVAcuts_2gaus_pol3_weighted_ptcuts_eventselection_changefit_L_changefit_function.root");
TFile *f_fun_MC = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_3_100_first_sight_fit/2gaus_1fit/pp_6_8_MC_2gaus_fit.root");

auto *f3 = (TF1*) f_fun->Get("f3");
auto *f3_MC = (TF1*) f_fun_MC->Get("f3");
TH1F *h1 = (TH1F*) f_fun->Get("h1");
double w1 = f3_MC->GetParameter(2);
double w2 = f3_MC->GetParameter(4);
double r1 = f3_MC->GetParameter(3);
double mean_value = f3_MC->GetParameter(1);
double float_width_parameter = 0.0;
TH1F *h_output = new TH1F ("h_output","output",2,0,2);

TNtuple *nt3 = (TNtuple*)f->Get("nt20");
TH1F *hb = new TH1F("hb","hb",42,2.108,2.444);
nt3->Draw("mass>>hb");
double numbers = 7200;
double numberb = hb->Integral();

RooRealVar mass("mass","mass",2.1,2.444);
RooDataSet ds("ds","ds",nt3,mass);
ds.Print();
RooPlot *massframe = new RooPlot("mass","mass",mass,2.108,2.444,42);
ds.plotOn(massframe,Name("ds"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1),XErrorSize(0));
TCanvas *c1 = new TCanvas("c1","c1",600,600);
c1->Divide(2,2);
c1->cd(1);

gPad->SetLeftMargin(0.12);
gPad->SetRightMargin(0.05);
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
cout<<"begin fitting"<<endl;
RooRealVar mean("mean","mean",mean_value,2.26,2.31);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);
RooRealVar p1("p1","p1",0,-1,1);
RooRealVar p2("p2","p2",0,-1,1);
RooRealVar p3("p3","p3",0,-1,1);

RooRealVar float_width("float_width","float_width",float_width_parameter,-0.5,0.5);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooChebychev back("back","second polynomial",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*50,numbers*50);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*50,numberb*50);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));

model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE)); 

//model.plotOn(massframe,Name("model"),Range(2.108,2.444),LineColor(2));
model.plotOn(massframe,Name("back"),Components(back),LineColor(9),LineStyle(7));
model.plotOn(massframe,Name("model"),Range(2.108,2.444),LineColor(2));

massframe->GetXaxis()->CenterTitle();
massframe->GetYaxis()->CenterTitle();
massframe->SetXTitle("m_{pk#pi} (GeV/c^{2})");
massframe->SetYTitle("Events/0.008 GeV/c^{2}");
massframe->SetTitleOffset(1.8,"Y");
massframe->SetTitleOffset(0.9,"X");
massframe->SetTitleFont(42,"X");
massframe->SetTitleFont(42,"Y");
massframe->SetLabelFont(42,"Y");
massframe->SetLabelFont(42,"X");
massframe->SetLabelSize(0.033,"X");
massframe->SetLabelSize(0.032,"Y");
massframe->SetTitleSize(0.045,"X");
massframe->SetTitleSize(0.035,"Y");
//massframe->SetMinimum(9000);
//massframe->SetAxisRange(18200,19800,"Y");//separate pt train
massframe->SetAxisRange(17000,28500,"Y");//uniform cuts
massframe->Draw();

TLatex* tex;
tex = new TLatex(0.16,0.85,"6 < p_{T} < 8 GeV/c");
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
int b = abs(round(NumSig.getAsymErrorLo()));
int c = round(NumSig.getAsymErrorHi());
int d = round((c-b)/2);
cout<<"low: "<<c<<endl;
cout<<"high: "<<d<<endl;
tex = new TLatex(0.16,0.75,Form("Yield: %i^{ + %i}_{ - %i} ",a,c,b));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
tex = new TLatex(0.16,0.8,"|y| < 1.0");
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
Tl.DrawLatex(0.12,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.63,0.93, "#scale[0.8]{38 nb^{-1} (5.02 TeV pp)}");//pp

h_output->SetBinContent(1,a);
h_output->SetBinError(1,c);
h_output->SetBinContent(2,a);
h_output->SetBinError(2,b);

TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.23,0.93, "#font[52]{Preliminary}");

auto leg = new TLegend(0.16,0.16,0.3,0.3);
leg->SetTextSize(0.04);
leg->AddEntry("ds","Data","EP");
leg->AddEntry("model","Signal+Background","L");
leg->AddEntry("back","Background","L");
leg->SetBorderSize(0);
leg->Draw();

RooWorkspace *w = new RooWorkspace("w","workspace");
w->import(model);
w->import(mean);
w->import(width1);
w->import(width2);
w->import(ratio);
w->import(scale_width1);
w->import(scale_width2);
w->import(float_width);
w->import(NumSig);
w->import(NumBkg);
w->import(ds);
w->Print();
w->writeToFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/pp_6_8_whole_DCA_range_withhits_cut_toyMC.root");
RooMCStudy* mcstudy = new RooMCStudy(model,mass,Silence(),Extended(),
                                            FitOptions(Save(kTRUE),PrintEvalErrors(0),NumCPU(8))) ;

///Generate and fit events
//------------------------
//Generate and fit 1000 samples of Poisson(nExpexted) events


mcstudy->generateAndFit(100);
RooPlot* frame1 = mcstudy->plotParam(NumSig,Bins(40)) ;
RooPlot* frame2 = mcstudy->plotError(NumSig,Bins(40)) ;
RooPlot* frame3 = mcstudy->plotPull(NumSig,Bins(40),FitGauss(kTRUE)) ;
c1->cd(2); frame1->Draw();
c1->cd(3);
gPad->SetLeftMargin(0.12);
gPad->SetRightMargin(0.05);
frame2->Draw();
c1->cd(4); frame3->Draw();

c1->SaveAs("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/pp_6_8_whole_DCA_range_withhits_toyMC.pdf");
c1->SaveAs("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/pp_6_8_whole_DCA_range_withhits_toyMC.C");

}
