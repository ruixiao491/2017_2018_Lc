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
void unbinned_fit_test_modified_PbPb_trytomanytimes_4_5_alone_pol2_floatwidth_float(){
//pp 10-20
TFile * f = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_3_100_BDTG/masstuples_whole.root");

TFile *f_fun =  new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_3_100_BDTG/2gaus_1fit/pp_4_5_BDT4_100_MC_2gaus_fit_hits.root");

auto *f3 = (TF1*) f_fun->Get("f3");
//TH1F *h1 = (TH1F*) f_fun->Get("h1");
double w1 = f3->GetParameter(2);
double w2 = f3->GetParameter(4);
double r1 = f3->GetParameter(3);
double mean_value = f3->GetParameter(1);
TH1F *h_output = new TH1F ("h_output","output",2,0,2);

TNtuple *nt5 = (TNtuple*)f->Get("nt1");
TH1F *hb = new TH1F("hb","hb",42,2.108,2.444);
nt5->Draw("mass>>hb");
double numbers = 7595;
double numberb = hb->Integral();
RooRealVar mass("mass","mass",2.108,2.444);
RooDataSet ds("ds","ds",nt5,mass);
ds.Print();
RooPlot *massframe = new RooPlot("mass","mass",mass,2.108,2.444,42);
ds.plotOn(massframe,Name("ds"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1));
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
RooRealVar mean("mean","mean",mean_value,2.27,2.3);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);

RooRealVar p1("p1","p1",-1.44041e-01,-1,1);
RooRealVar p2("p2","p2",7.20387e-04,-1,1);
RooRealVar p3("p3","p3",-3.82506e-03,-1,1);

RooRealVar float_width("float_width","float_width",0.2,-1,1);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooChebychev back("back","third polynomial",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*50,numbers*50);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*50,numberb*50);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));


model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE));
//model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444));

model.plotOn(massframe,Name("model"),Range("full"),LineColor(2));
model.plotOn(massframe,Name("back"),Components(back),LineColor(9));
RooFitResult * r = model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE),Save());

massframe->GetXaxis()->CenterTitle();
massframe->GetYaxis()->CenterTitle();
massframe->SetXTitle("m_{pk#pi} (GeV/c^{2})");
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
//massframe->SetMinimum(77800);//nt10
//massframe->SetMinimum(54000);//nt11
//massframe->SetMinimum(26000);//nt12
//massframe->SetMinimum(180000);//3D alpha 0_2
massframe->SetAxisRange(75000,100000,"Y");
massframe->Draw();

TLatex* tex;
tex = new TLatex(0.16,0.85,"4 < p_{T} < 5 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex =  new TLatex(0.75,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{-}}");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.055);
tex->SetLineWidth(2);
tex->Draw();

int a = round(NumSig.getVal());
int b = abs(round(NumSig.getAsymErrorLo()));
int c = round(NumSig.getAsymErrorHi());

cout<<"a:  "<<a<<endl;

tex = new TLatex(0.16,0.75,Form("Yield: %i^{ + %i}_{ - %i} ",a,c,b));
//tex = new TLatex(0.16,0.75,Form("Raw yield: %i #pm %i ",a,b));
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
Tl.DrawLatex(0.19,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.63,0.93, "#scale[0.8]{38 nb^{-1} (5.02 TeV pp)}");//pp
/*
h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);
*/
TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.3,0.93, "#font[52]{Preliminary}");

auto leg = new TLegend(0.16,0.16,0.3,0.3);
leg->SetTextSize(0.04);
leg->AddEntry("ds","Data","LP");
leg->AddEntry("model","Signal+Background","L");
leg->AddEntry("back","Background","L");
leg->SetBorderSize(0);
leg->Draw();

h_output->SetBinContent(1,a);
h_output->SetBinError(1,c);
h_output->SetBinContent(2,a);
h_output->SetBinError(2,b);

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
w->writeToFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/0605_BDTG_3_100_pp_unifom_toyMC/pp_4_5_withits_whole_DCA_range_withhits_cut_toyMC.root");
RooMCStudy* mcstudy = new RooMCStudy(model,mass,Silence(),Extended(),
                                            FitOptions(Save(kTRUE),PrintEvalErrors(0),NumCPU(8))) ;

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





c1->SaveAs("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/0605_BDTG_3_100_pp_unifom_toyMC/pp_4_5_whole_DCA_range_withhits.pdf");
c1->SaveAs("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/0605_BDTG_3_100_pp_unifom_toyMC/pp_4_5_whole_DCA_range_withhits.C");

TFile *result = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/signal_extraction/pp_nopartMB3_noMB7_toyMC/2gaus_pol3_pp/0605_BDTG_3_100_pp_unifom_toyMC/pp_4_5_whole_DCA_range_withhits.root","RECREATE");
h_output->Write();
result->Close();

}
