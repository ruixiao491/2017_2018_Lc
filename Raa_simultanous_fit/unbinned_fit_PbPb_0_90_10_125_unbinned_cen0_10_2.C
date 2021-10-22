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
void unbinned_fit_PbPb_0_90_10_125_unbinned_cen0_10_2(){
/////PbPb cen0_100%

TFile *f =  new TFile("/scratch/halstead/x/xiao147/2018_PbPb_transfer_from_brown_rice/final_PbPb_masstuples_copyfrombrown_forRaa_simultaneousfit/masstuples_10_125_differentvarialbles_rec_cen0_10cuts_sigeff111418.root");

TFile *f_fun = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/MC_fit/3gaus_fit/10_40_rec/10_30_uniform_rec/pp_10_12_MC_3gaus_fit_finbins.root");
TFile *f_accp =  new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/accp/ROOT/several_turns/third_turn_PVz/combine_accp/accp_P_cen0_10_thirdturn_PVz.root");

TFile * f_pp = new TFile("/scratch/halstead/x/xiao147/2017_pp_fullproduction_03112020_2/fill_3_100_BDTG/working_points_scan_whole.root");
TFile *f_fun_pp = new TFile("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/signal_extraction/pp_3_100_BDTG/2gaus_1fit/pp_10_12_5_BDT4_100_MC_2gaus_fit_hits.root");
TFile *f_accp_pp = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_accp/fourth_turn/combine_pT_pp/prompt_pt2_pt4_pt10_combine_fourthturn.root");
TFile *f_prompt_ratio_pp = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_ratio_allpT_2017pp_BDTG.root");

TF1 *f3 = (TF1*) f_fun->Get("f3");
double w1_PbPb = f3->GetParameter(2);
double w2_PbPb = f3->GetParameter(4);
double w3_PbPb = f3->GetParameter(6);
double r1_PbPb = f3->GetParameter(3);
double r2_PbPb = f3->GetParameter(5);
double mean_value_PbPb = f3->GetParameter(1);
double float_width_parameter_PbPb = 0;
TH1F *h_output = new TH1F ("h_output","output",2,0,2);
TH1F *hrecoeff_combine = (TH1F*) f_accp->Get("hrecoeff_combine");
TH1F *hrecoeffi_weighted_pp = (TH1F*) f_accp_pp->Get("hrecoeff_combine");
TH1F *h_ratio_pp = (TH1F*) f_prompt_ratio_pp->Get("h_prompt_ratio")->Clone("h_ratio_pp");
/////pp setting
auto *f4 = (TF1*) f_fun_pp->Get("f3");
double w1_pp = f4->GetParameter(2);
double w2_pp = f4->GetParameter(4);
double r1_pp = f4->GetParameter(3);
double mean_value_pp = f4->GetParameter(1);
double float_width_parameter_pp = 0;
double accp_PbPb = hrecoeff_combine->GetBinContent(hrecoeff_combine->FindBin(11.25));
double promptratio_PbPb = 0.69;
double accp_pp = hrecoeffi_weighted_pp->GetBinContent(hrecoeffi_weighted_pp->FindBin(11.25));
double prompratio_pp = h_ratio_pp->GetBinContent(h_ratio_pp->FindBin(11.25));


TNtuple *nt_PbPb = (TNtuple*)f->Get("nt_1");
TNtuple *nt_pp = (TNtuple*)f_pp->Get("BDTG_10_125_value_0_77");
TH1F *hb_PbPb = new TH1F("hb_PbPb","hb_PbPb",42,2.108,2.444);
TH1F *hb_pp = new TH1F("hb_pp","hb_pp",43,2.1,2.444);
nt_PbPb->Draw("mass>>hb_PbPb");
nt_pp->Draw("mass>>hb_pp");

double numbers_pp = 2600;
double numberb_pp = hb_pp->Integral();
double numberb_PbPb = hb_PbPb->Integral();
RooRealVar Raa("Raa","Raa",0.33147,-15,15);

RooRealVar mass("mass","mass",2.108,2.444);
RooDataSet ds_pp("ds_pp","ds_pp",nt_pp,mass);
RooDataSet ds_PbPb("ds_PbPb","ds_PbPb",nt_PbPb,mass);
ds_pp.Print();

RooPlot *massframe = new RooPlot("mass","mass",mass,2.108,2.444,42);
ds_pp.plotOn(massframe,Name("ds_pp"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1),XErrorSize(0));
ds_PbPb.plotOn(massframe,Name("ds_PbPb"),MarkerStyle(20),MarkerColor(1),MarkerSize(1),LineColor(1),XErrorSize(0));

cout<<"begin fitting"<<endl;
RooRealVar Accp_PbPb("Accp_PbPb","Accp_PbPb",accp_PbPb,accp_PbPb,accp_PbPb);
RooRealVar P_ratio_PbPb("P_ratio_PbPb","P_ratio_PbPb",promptratio_PbPb,promptratio_PbPb,promptratio_PbPb);
RooRealVar Accp_pp("Accp_pp","Accp_pp",accp_pp,accp_pp,accp_pp);
RooRealVar P_ratio_pp("P_ratio_pp","P_ratio_pp",prompratio_pp,prompratio_pp,prompratio_pp);

RooRealVar mean_pp("mean_pp","mean_pp",mean_value_pp,2.26,2.31);
RooRealVar width1_pp("width1_pp","width1",w1_pp,w1_pp,w1_pp);
RooRealVar width2_pp("width2_pp","width2",w2_pp,w2_pp,w2_pp);
RooRealVar ratio_pp("ratio_pp","ratio",r1_pp,r1_pp,r1_pp);

RooRealVar p1_pp("p1_pp","p1_pp",0,-1,1);
RooRealVar p2_pp("p2_pp","p2_pp",0,-1,1);
RooRealVar p3_pp("p3_pp","p3_pp",0,-1,1);

RooRealVar float_width_pp("float_width_pp","float_width_pp",0,-1,1);
RooFormulaVar scale_width1_pp("scale width1_pp","scaled width1_pp","width1_pp*(1+float_width_pp)",RooArgSet(width1_pp,float_width_pp));
RooFormulaVar scale_width2_pp("scale width2_pp","scaled width2_pp","width2_pp*(1+float_width_pp)",RooArgSet(width2_pp,float_width_pp));
RooGaussian sigma1_pp("sigma1_pp","gauss(mass,mean_pp,scale_width1_pp)",mass,mean_pp,scale_width1_pp);
RooGaussian sigma2_pp("sigma2_pp","gauss(mass,mean_pp,scale_width2_pp)",mass,mean_pp,scale_width2_pp);
RooAddPdf signal_pp("signal_pp","signal_pp",RooArgList(sigma1_pp,sigma2_pp),ratio_pp);
RooChebychev back_pp("back_pp","second polynomial",mass,RooArgList(p1_pp,p2_pp,p3_pp));
RooRealVar NumSig_pp("NumSig_pp","Number of Signal pp",numbers_pp,-numbers_pp*10,numbers_pp*10);
RooRealVar NumBkg_pp("NumBkg_pp","Number of Background pp",numberb_pp,-numberb_pp*10, numberb_pp*10);
RooAddPdf model_pp("model_pp","model_pp",RooArgList(signal_pp,back_pp),RooArgList(NumSig_pp,NumBkg_pp));

RooRealVar mean_PbPb("mean_PbPb","mean_PbPb",mean_value_PbPb,2.26,2.3);
RooRealVar width1_PbPb("width1_PbPb","width1_PbPb",w1_PbPb,w1_PbPb,w1_PbPb);
RooRealVar width2_PbPb("width2_PbPb","width2_PbPb",w2_PbPb,w2_PbPb,w2_PbPb);
RooRealVar width3_PbPb("width3_PbPb","width3_PbPb",w3_PbPb,w3_PbPb,w3_PbPb);
RooRealVar ratio1_PbPb("ratio1_PbPb","ratio1_PbPb",r1_PbPb,r1_PbPb,r1_PbPb);
RooRealVar ratio2_PbPb("ratio2_PbPb","ratio2_PbPb",r2_PbPb,r2_PbPb,r2_PbPb);

RooRealVar p1_PbPb("p1_PbPb","p1_PbPb",0,-1,1);
RooRealVar p2_PbPb("p2_PbPb","p2_PbPb",0,-1,1);
RooRealVar p3_PbPb("p3_PbPb","p3_PbPb",0,-1,1);

RooRealVar float_width_PbPb("float_width_PbPb","float_width_PbPb",0.1,-1,1);
RooFormulaVar scale_width1_PbPb("scale width1_PbPb","scaled width1_PbPb","width1_PbPb*(1+float_width_PbPb)",RooArgSet(width1_PbPb,float_width_PbPb));
RooFormulaVar scale_width2_PbPb("scale width2_PbPb","scaled width2_PbPb","width2_PbPb*(1+float_width_PbPb)",RooArgSet(width2_PbPb,float_width_PbPb));
RooFormulaVar scale_width3_PbPb("scale width3_PbPb","scaled width3_PbPb","width3_PbPb*(1+float_width_PbPb)",RooArgSet(width3_PbPb,float_width_PbPb));
RooGaussian sigma1_PbPb("sigma1_PbPb","gauss(mass,mean_PbPb,scale_width1_PbPb)",mass,mean_PbPb,scale_width1_PbPb);
RooGaussian sigma2_PbPb("sigma2_PbPb","gauss(mass,mean_PbPb,scale_width2_PbPb)",mass,mean_PbPb,scale_width2_PbPb);
RooGaussian sigma3_PbPb("sigma3_PbPb","gauss(mass,mean_PbPb,scale_width3_PbPb)",mass,mean_PbPb,scale_width3_PbPb);
RooAddPdf signal_PbPb("signal_PbPb","signal_PbPb",RooArgList(sigma1_PbPb,sigma2_PbPb,sigma3_PbPb),RooArgList(ratio1_PbPb,ratio2_PbPb));
RooChebychev back_PbPb("back_PbPb","background_PbPb",mass,RooArgList(p1_PbPb,p2_PbPb,p3_PbPb));
RooFormulaVar NumSig_PbPb("NumSig_PbPb","@0*@1*@2*3.6505427e+08*23.2143*@3/(@4*0.252*1e6*0.97*@5*1000)",RooArgSet(Raa,NumSig_pp,P_ratio_pp,Accp_PbPb,P_ratio_PbPb,Accp_pp));
RooRealVar NumBkg_PbPb("NumBkg_PbPb","Number of Background PbPb",numberb_PbPb,-numberb_PbPb*10,numberb_PbPb*10);
RooAddPdf model_PbPb("model_PbPb","model_PbPb",RooArgList(signal_PbPb,back_PbPb),RooArgList(NumSig_PbPb,NumBkg_PbPb));

//Create index category and join samples
RooCategory sample("sample","sample");
sample.defineType("pp");
sample.defineType("PbPb");
//construct combined dataset in (mass,sample)
RooDataSet combData("combData","combined data",mass,Index(sample),Import("pp",ds_pp),Import("PbPb",ds_PbPb));

//construct a simultaneous pdf in (mass, sample)
//////construct a simultaneous pdf using category sample as index
RooSimultaneous simPdf("simPdf","simulteous pdf",sample);
simPdf.addPdf(model_pp,"pp");
simPdf.addPdf(model_PbPb,"PbPb");

//Perform a simultaneous fit
////Perform simultaeous fit of model_pp to ds_pp and model_PbPb to ds_PbPb
//////simPdf.fitTo(combData,Extended(kTRUE),Range(2.108,2.444));
RooFitResult *r = simPdf.fitTo(combData,Extended(kTRUE),Range(2.108,2.444),Minos(kTRUE));

//plot model slices on data slices
////---------------------------------
RooPlot *massframe1 = new RooPlot("mass","mass",mass,2.108,2.444,42);
combData.plotOn(massframe1,Cut("sample==sample::pp")) ;
simPdf.plotOn(massframe1,Slice(sample,"pp"),Components(back_pp),ProjWData(sample,combData),LineColor(9),LineStyle(7));
simPdf.plotOn(massframe1,Slice(sample,"pp"),ProjWData(sample,combData),LineColor(2));
RooPlot *massframe2 = new RooPlot("mass","mass",mass,2.108,2.444,42);
combData.plotOn(massframe2,Cut("sample==sample::PbPb")) ;
simPdf.plotOn(massframe2,Slice(sample,"PbPb"),Components(back_PbPb),ProjWData(sample,combData),LineColor(9),LineStyle(7));
simPdf.plotOn(massframe2,Slice(sample,"PbPb"),ProjWData(sample,combData),LineColor(2));
TCanvas *c1 = new TCanvas("c1","c1",1200,600);
c1->Divide(2);
c1->cd(1); gPad->SetLeftMargin(0.12);
gPad->SetRightMargin(0.05);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f);
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);
gStyle->SetTitleFontSize(0.06);
gStyle->SetErrorX(kFALSE);
gStyle->SetCanvasBorderMode(0);
gStyle->SetCanvasColor(kWhite);
gStyle->SetCanvasDefX(0);//position on screen
gStyle->SetCanvasDefY(0);
gStyle->SetPadTopMargin(0.05);
gStyle->SetPadBottomMargin(0.13);
gStyle->SetPadLeftMargin(0.16);
gStyle->SetPadRightMargin(0.02);
gStyle->SetPaperSize(20.,20.);
gStyle->SetFrameBorderMode(0);
gStyle->SetFrameBorderSize(1);
gStyle->SetFrameFillColor(0);
gStyle->SetFrameFillStyle(0);
gStyle->SetFrameLineColor(1);
gStyle->SetFrameLineStyle(1);
gStyle->SetFrameLineWidth(1);

massframe1->GetXaxis()->CenterTitle();
massframe1->GetYaxis()->CenterTitle();
massframe1->SetXTitle("m_{pk#pi} (GeV/c^{2})");
massframe1->SetYTitle("Events/0.008 GeV/c^{2}");
massframe1->SetTitleOffset(1.5,"Y");
massframe1->SetTitleOffset(0.9,"X");
massframe1->SetTitleFont(42,"X");
massframe1->SetTitleFont(42,"Y");
massframe1->SetLabelFont(42,"Y");
massframe1->SetLabelFont(42,"X");
massframe1->SetLabelSize(0.033,"X");
massframe1->SetLabelSize(0.033,"Y");
massframe1->SetTitleSize(0.048,"X");
massframe1->SetTitleSize(0.048,"Y");
massframe1->SetAxisRange(4500,7500,"Y");///separate pt train
massframe1->Draw();
TLatex* tex_pp;
tex_pp = new TLatex(0.16,0.85,"10 < p_{T} < 12.5 GeV/c");
tex_pp->SetNDC();
tex_pp->SetTextFont(42);
tex_pp->SetTextSize(0.047);
tex_pp->SetLineWidth(2);
tex_pp->Draw();

tex_pp =  new TLatex(0.75,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{#font[122]{\55}}}");
tex_pp->SetNDC();
tex_pp->SetTextFont(42);
tex_pp->SetTextSize(0.055);
tex_pp->SetLineWidth(2);
tex_pp->Draw();

tex_pp = new TLatex(0.16,0.8,"|y| < 1");
tex_pp->SetNDC();
tex_pp->SetTextFont(42);
tex_pp->SetTextSize(0.047);
tex_pp->SetLineWidth(2);
tex_pp->Draw();

TLatex Tl_pp;
Tl_pp.SetNDC();
Tl_pp.SetTextAlign(12);
Tl_pp.SetTextSize(0.05);
Tl_pp.SetTextFont(42);
Tl_pp.DrawLatex(0.12,0.93, "#font[61]{CMS }");
Tl_pp.DrawLatex(0.61,0.93, "#scale[0.8]{252 nb^{-1} (5.02 TeV pp)}");//pp

TLatex Tl2_pp;
Tl_pp.SetNDC();
Tl_pp.SetTextAlign(12);
Tl_pp.SetTextSize(0.05*0.75);
Tl_pp.SetTextFont(42);
Tl_pp.DrawLatex(0.23,0.93, "#font[52]{Preliminary}");
c1->cd(2); gPad->SetLeftMargin(0.17); massframe2->Draw();



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
TGaxis::SetMaxDigits(4);
massframe2->GetXaxis()->CenterTitle();
massframe2->GetYaxis()->CenterTitle();
massframe2->SetXTitle("m_{pK#pi} (GeV/c^{2})");
massframe2->SetYTitle("Events/0.008 GeV/c^{2}");
massframe2->SetTitleOffset(1.4,"Y");
massframe2->SetTitleOffset(0.85,"X");
massframe2->SetTitleFont(42,"X");
massframe2->SetTitleFont(42,"Y");
massframe2->SetLabelFont(42,"Y");
massframe2->SetLabelFont(42,"X");
massframe2->SetLabelSize(0.042,"X");
massframe2->SetLabelSize(0.042,"Y");
massframe2->SetTitleSize(0.048,"X");
massframe2->SetTitleSize(0.048,"Y");
massframe2->SetAxisRange(20000,31000,"Y");
massframe2->Draw();


TLatex* tex;
tex = new TLatex(0.2,0.84,"10 < p_{T} < 12.5 GeV/c");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.047);
tex->SetLineWidth(2);
tex->Draw();

tex =  new TLatex(0.71,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{#font[122]{\55}}}");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.055);
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
Tl.DrawLatex(0.17,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.49,0.93, "#scale[0.8]{0.58 nb^{-1} (5.02 TeV PbPb)}");//PbPb cen0_30
//for AN
TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.29,0.93, "#font[52]{Preliminary}");










c1->SaveAs("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/Raa_ratio_fit/full_statistics_pp_BDTG_3_100_workingscan_077/PbPb_10_125_rec_unbinned_cen0_10_10125_cen0_10cut11_Raa.pdf");
c1->SaveAs("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/Raa_ratio_fit/full_statistics_pp_BDTG_3_100_workingscan_077/PbPb_10_125_rec_unbinned_cen0_10_10125_cen0_10cut11_Raa.C");

TFile *result = new TFile("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/Raa_ratio_fit/full_statistics_pp_BDTG_3_100_workingscan_077/PbPb_10_125_3gaus_pol3_unbinned_rec_cen0_10_10125_cen0_10cut11_Raa.root","RECREATE");

h_output->Write();
massframe->Write();
result->Close();




}
