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
void unbinned_fit_test_modified_PbPb_trytomanytimes_4_5_alone_pol2_floatwidth_float_binned(){
//pp 10-20
TFile * f = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_BDT_3_4/masstuples_whole.root");

TFile *f_fun =  new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_4_100_first_sight_fit/2gaus_1fit/pp_4_5_BDT4_100_MC_2gaus_fit.root");

auto *f3 = (TF1*) f_fun->Get("f3");
double w1 = f3->GetParameter(2);
double w2 = f3->GetParameter(4);
double r1 = f3->GetParameter(3);
double mean_value = f3->GetParameter(1);
//double float_width_parameter = f3->GetParameter(5);
TH1F *h_output = new TH1F ("h_output","output",2,0,2);

TNtuple *nt5 = (TNtuple*)f->Get("nt1");
TH1F *hb = new TH1F("hb","hb",42,2.2,2.4);
nt5->Draw("mass>>hb");
double numbers = 1E4;
double numberb = hb->Integral();
cout<<"numberb value: "<<numberb<<endl;
RooRealVar mass("mass","mass",2.2,2.4);
RooDataHist ds("ds","ds",mass,Import(*hb));
ds.Print();
RooPlot *massframe = new RooPlot("mass","mass",mass,2.2,2.4,42);
ds.plotOn(massframe,Name("ds"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1));
TCanvas *c1 = new TCanvas("c1","c1",1200,600);
c1->Divide(2);
c1->cd(1);
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
RooRealVar mean("mean","mean",mean_value,2.27,2.29);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);
/*
RooRealVar p1("p1","p1",-6.01271e-02,-1,1);
RooRealVar p2("p2","p2",-2.18608e-03,-1,1);
RooRealVar p3("p3","p3",2.04893e-03,-1,1);
*/

RooRealVar p1("p1","p1",7.38705e-02,-1,1);
RooRealVar p2("p2","p2",-1.12762e-02,-1,1);
RooRealVar p3("p3","p3",0,-1,1);


RooRealVar float_width("float_width","float_width",0.0,0.0,0.0);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooChebychev back("back","third polynomial",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-numbers*100,numbers*100);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-numberb*100,numberb*100);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));


//model.fitTo(ds,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE));
model.fitTo(ds,Extended(kTRUE),Range(2.2,2.4));

model.plotOn(massframe,Name("model"),Range("full"),LineColor(2));
//model.plotOn(massframe,Name("back"),Components(back),LineColor(9));

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
//massframe->SetAxisRange(1800000,2100000,"Y");//3-4
massframe->SetAxisRange(1140000,1220000,"Y");//3-4
//massframe->SetAxisRange(270000,315000,"Y");
massframe->Draw();

TLatex* tex;
tex = new TLatex(0.16,0.85,"3 < p_{T} < 4 GeV/c");
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
int b = round(NumSig.getError());
cout<<"a:   "<<a<<endl;
tex = new TLatex(0.16,0.75,Form("Raw yield: %i #pm %i ",a,b));
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
h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);

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
h_output->SetBinError(1,b);


c1->cd(2);
gPad->SetLeftMargin(0.12);
gPad->SetRightMargin(0.05);
RooHist * hpull = massframe->pullHist();
RooPlot *frame3 = new RooPlot("Pull Distribution","Pull Distribution",mass,2.2,2.4,42);
frame3->addPlotable(hpull,"P");
frame3->GetXaxis()->CenterTitle();
frame3->SetXTitle("m_{pk#pi} (GeV/c^{2})");
frame3->SetTitleOffset(1.5,"Y");
frame3->SetTitleOffset(0.9,"X");
frame3->SetTitleFont(42,"X");
frame3->SetTitleFont(42,"Y");
frame3->SetLabelFont(42,"Y");
frame3->SetLabelFont(42,"X");
frame3->SetLabelSize(0.033,"X");
frame3->SetLabelSize(0.033,"Y");
frame3->SetTitleSize(0.045,"X");
frame3->SetTitleSize(0.04,"Y");
frame3->Draw();
TLine *l = new TLine(2.108,1,2.444,1);
l->SetLineStyle(9);
l->SetLineColor(8);
l->SetLineWidth(3);
l->Draw("same");
TLine *l1 = new TLine(2.108,-1,2.444,-1);
l1->SetLineStyle(9);
l1->SetLineColor(8);
l1->SetLineWidth(3);
l1->Draw("same");
tex = new TLatex(0.17,0.85,"4 < p_{T} < 5 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
TLatex Tl3;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.12,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.63,0.93, "#scale[0.8]{38 nb^{-1} (5.02 TeV pp)}");//pp
h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);



/*
c1->SaveAs("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/ARC_comments/signal/ROOT_files_AfterARC/should_be_final_apply_ARC_comments/invariant_mass_fit_basedonMC_withnewcuts/2gaus_1mean_pp/pol2/pp_4_5_pol2_3Dalpha0_2_finalcutsfromscan_invariantmass_BS_correction_basedonMC_withTMVAcuts.pdf");

TFile *result = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/ARC_comments/signal/ROOT_files_AfterARC/should_be_final_apply_ARC_comments/invariant_mass_fit_basedonMC_withnewcuts/2gaus_1mean_pp/pol2/pp_4_5_3Dalpha_0_2_finalcutsfromscan_invariant_mass_BS_correction_basedonMC_withTMVAcuts.root","RECREATE");
h_output->Write();
result->Close();
*/
}
