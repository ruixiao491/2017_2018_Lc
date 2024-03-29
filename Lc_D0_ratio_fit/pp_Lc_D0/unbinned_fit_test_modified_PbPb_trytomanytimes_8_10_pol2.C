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
void unbinned_fit_test_modified_PbPb_trytomanytimes_8_10_pol2(){
TFile * f = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_3_100_BDTG/working_points_scan_whole.root");
//8-10
TFile *f_fun = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/signalectraction/forAN_plot/change_fit_function/pp/pol3/8_10_pp_officialTMVAcuts_2gaus_pol3_weighted_ptcuts_eventselection_changefit_L_changefit_function.root");
TFile *f_fun_MC = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_3_100_BDTG/2gaus_1fit/pp_8_10_BDT4_100_MC_2gaus_fit_hits.root");
TFile *f_D0 =  new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/D0_crosssection_2015/D0_crosssection_2015_pp.root");
TFile *f_accp = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_accp/fourth_turn/combine_pT_pp/prompt_pt2_pt4_pt10_combine_fourthturn.root");
TFile *f_prompt_ratio = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_ratio_allpT_2017pp_BDTG.root");

TH1F *hrecoeffi_weighted = (TH1F*) f_accp->Get("hrecoeff_combine");
TH1F *hD0_crosssection = (TH1F*) f_D0->Get("hD_samerange")->Clone("hD0_crosssection");
TH1F *h_ratio = (TH1F*) f_prompt_ratio->Get("h_prompt_ratio")->Clone("h_ratio");


auto *f3 = (TF1*) f_fun->Get("f3");
auto *f3_MC = (TF1*) f_fun_MC->Get("f3");
TH1F *h1 = (TH1F*) f_fun->Get("h1");
double w1 = f3_MC->GetParameter(2);
double w2 = f3_MC->GetParameter(4);
double r1 = f3_MC->GetParameter(3);
double mean_value = f3->GetParameter(1);
TH1F *h_output = new TH1F ("h_output","output",2,0,2);

TNtuple *nt2 = (TNtuple*)f->Get("BDTG_8_10_value_0_77");
TH1F *hb = new TH1F("hb","hb",42,2.108,2.444);
nt2->Draw("mass>>hb");
double numbers = 3902;
double numberb = hb->Integral();
double ND0 = hD0_crosssection->GetBinContent(hD0_crosssection->FindBin(9));
double ND0_err = hD0_crosssection->GetBinError(hD0_crosssection->FindBin(9));
double accp = hrecoeffi_weighted->GetBinContent(hrecoeffi_weighted->FindBin(9));
double prompratio = h_ratio->GetBinContent(h_ratio->FindBin(9));

RooRealVar mass("mass","mass",2.1,2.444);
RooDataSet ds("ds","ds",nt2,mass);
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

RooRealVar Accp("Accp","Accp",accp,accp,accp);
RooRealVar P_ratio("P_ratio","P_ratio",prompratio,prompratio,prompratio);
RooRealVar ratio2("ratio2","ratio2",0.21589,-10,10);
RooRealVar ND0_var("ND0_var","ND0_var",ND0,ND0-10*ND0_err,ND0+10*ND0_err);
RooFormulaVar NumSig("NumSig","@0*@1*2*2*0.0635*0.252*1e6*@2/@3",RooArgSet(ratio2,ND0_var,Accp,P_ratio));
//RooFormulaVar NumSig("NumSig","@0*@1*2*2*0.0635*0.252*1e6*9.39198e-02/7.40454e-01",RooArgSet(ratio2,ND0_var));
//RooFormulaVar NumSig("NumSig","@0*@1*2*2*0.0635*0.252*1e6*0.093888/7.40454e-01",RooArgSet(ratio2,ND0_var));
RooGaussian fconstraint("fconstraint","fconstraint",ND0_var,RooConst(ND0),RooConst(ND0_err));

//RooRealVar mean("mean","mean",mean_value,2.26,2.31);
RooRealVar mean("mean","mean",mean_value,2.25,2.31);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);

RooRealVar p1("p1","p1",-8.19990e-02,-1,1);
RooRealVar p2("p2","p2",-3.05098e-03,-1,1);
RooRealVar p3("p3","p3",0,-1,1);
/*
RooRealVar p1("p1","p1",0,-1,1);
RooRealVar p2("p2","p2",0,-1,1);
*/
RooRealVar float_width("float_width","float_width",0.0,-0.5,0.5);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooChebychev back("back","second polynomial",mass,RooArgList(p1,p2,p3));
//RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*50,numbers*50);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*100,numberb*100);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));
RooProdPdf modelc("modelc","model with constraint",RooArgSet(model,fconstraint)) ;

//RooFitResult * r = model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE),Save());
modelc.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE)); 

modelc.plotOn(massframe,Name("model"),Range(2.108,2.444),LineColor(2));
modelc.plotOn(massframe,Name("back"),Components(back),LineColor(9));

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
//massframe->SetMinimum(4000);
//massframe->SetAxisRange(3300,4700,"Y");//separate train 
massframe->SetAxisRange(10000,15500,"Y");//uniform train 
//massframe->SetAxisRange(2.108,2.444,"X");
massframe->Draw();


TLatex* tex;
tex = new TLatex(0.16,0.85,"8 < p_{T} < 10 GeV/c");
//tex = new TLatex(0.17,0.5,"PbPb: 10GeV < P_{T} < 20GeV");
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

float a = ratio2.getVal();
float b = ratio2.getAsymErrorLo();
float c = ratio2.getAsymErrorHi();
cout<<"low: "<<b<<endl;
cout<<"high: "<<c<<endl;
cout<<"value: "<<a<<endl;

/*
tex = new TLatex(0.16,0.75,Form("Yield: %i^{ + %i}_{ - %i} ",a,c,b));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
*/
tex = new TLatex(0.16,0.8,"|y| < 1");
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
Tl.DrawLatex(0.63,0.93, "#scale[0.8]{252 nb^{-1} (5.02 TeV pp)}");//pp

h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);
h_output->SetBinContent(2,a);
h_output->SetBinError(2,c);

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

c1->SaveAs("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/Lc_D0_fit/full_statistic_BDTG_3_100_workingscan_077/pp_8_10_fullstatistics_Lc_D0ratio_massplots.pdf");
c1->SaveAs("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/Lc_D0_fit/full_statistic_BDTG_3_100_workingscan_077/pp_8_10_fullstatistics_Lc_D0ratio_massplots.C");

TFile *result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/Lc_D0_fit/full_statistic_BDTG_3_100_workingscan_077/Lc_D0_ratio_8_10_pp_fullstatistics.root","RECREATE");
h_output->Write();
massframe->Write();
result->Close();

}
