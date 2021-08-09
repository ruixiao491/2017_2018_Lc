#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the dN/dpt.
void divideBinWidth(TH1* h)
{
	for(int i=1;i<=h->GetNbinsX();i++)
	{
		Float_t contentvalue=h->GetBinContent(i);
		Float_t content_err=h->GetBinError(i);
		contentvalue/=h->GetBinWidth(i);
		content_err/=h->GetBinWidth(i);
		h->SetBinContent(i,contentvalue);
		h->SetBinError(i,content_err);
	}
}
void dNdpt_calculate_prompt(){
////new unbinned fit with Kevin uniform cuts.
 	TFile *f1 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_accp/fourth_turn/combine_pT_pp/prompt_pt2_pt4_pt10_combine_fourthturn.root");
 	TFile *f2 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_3_4_whole_DCA_range_withhits_float_minos.root");//3-4
 	TFile *f3 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_4_5_whole_DCA_range_withhits_pol1_default_float.root");//4-5
 	TFile *f4 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_5_6_whole_DCA_range_withhits.root");//5-6
 	TFile *f5 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_6_8_whole_DCA_range_withhits.root");//6-8
 	TFile *f6 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_8_10_whole_DCA_range_withhits.root");//8-10
	TFile *f7 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_10_12_5_whole_DCA_withhitscut.root");//10-12.5
	TFile *f8 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_12_5_15_whole_DCA_withhitscut.root");//12.5-15
	TFile *f9 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_15_20_whole_DCA_withhitscut.root");//15-20
	TFile *f10 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_20_30_whole_DCA_withhits.root");//20-30
	TFile *f_prompt_ratio = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_ratio_allpT_2017pp_BDTG.root");	

	TH1F *hrecoeffi_weighted = (TH1F*) f1->Get("hrecoeff_combine");
 	TH1F *fun1 = (TH1F*) f2->Get("h_output")->Clone("fun1");
	TH1F *fun2 = (TH1F*) f3->Get("h_output")->Clone("fun2");
	TH1F *fun3 = (TH1F*) f4->Get("h_output")->Clone("fun3");
	TH1F *fun4 = (TH1F*) f5->Get("h_output")->Clone("fun4");
	TH1F *fun5 = (TH1F*) f6->Get("h_output")->Clone("fun5");
	TH1F *fun6 = (TH1F*) f7->Get("h_output")->Clone("fun6");
	TH1F *fun7 = (TH1F*) f8->Get("h_output")->Clone("fun7");
	TH1F *fun8 = (TH1F*) f9->Get("h_output")->Clone("fun8");
	TH1F *fun9 = (TH1F*) f10->Get("h_output")->Clone("fun9");
	TH1F *h_ratio = (TH1F*) f_prompt_ratio->Get("h_prompt_ratio")->Clone("h_ratio");
	//lumi 2015 =38163 mu b    3.8e4 *10-6=3.8e-2
	//lumi 2017 = 251838mu b 2.52e5*e-6=2.52e-1
	double lumi=0.252; //for 2017 pp.
	double BR=0.0635;
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	const Int_t NBINS = 9;
	Double_t edges[NBINS + 1]={3,4,5,6,8,10,12.5,15,20,30};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hDpt_high_err = new TH1D("hDpt_high_err","hDpt_high_err",NBINS,edges);
	TH1 *hDpt_low_err = new TH1D("hDpt_low_err","hDpt_low_err",NBINS,edges);
	h_ratio->Sumw2();
	hDpt->Sumw2();
	hDpt_high_err->Sumw2();
	hDpt_low_err->Sumw2();
	cout<<"begin filling the histograms of the central value and asymmetry errs"<<endl;
	hDpt->SetBinContent(1,fun1->GetBinContent(1));//3-4
	hDpt->SetBinContent(2,fun2->GetBinContent(1));//4-5
	hDpt->SetBinContent(3,fun3->GetBinContent(1));//5-6
	hDpt->SetBinContent(4,fun4->GetBinContent(1));//6-8
	hDpt->SetBinContent(5,fun5->GetBinContent(1));//8-10
	hDpt->SetBinContent(6,fun6->GetBinContent(1));//10-12.5
	hDpt->SetBinContent(7,fun7->GetBinContent(1));//12.5-15
	hDpt->SetBinContent(8,fun8->GetBinContent(1));//15-20
	hDpt->SetBinContent(9,fun9->GetBinContent(1));//20-30

	hDpt_high_err->SetBinContent(1,fun1->GetBinContent(1));//3-4
	hDpt_high_err->SetBinContent(2,fun2->GetBinContent(1));//4-5
	hDpt_high_err->SetBinContent(3,fun3->GetBinContent(1));//5-6
	hDpt_high_err->SetBinContent(4,fun4->GetBinContent(1));//6-8
	hDpt_high_err->SetBinContent(5,fun5->GetBinContent(1));//8-10
	hDpt_high_err->SetBinContent(6,fun6->GetBinContent(1));//10-12.5
	hDpt_high_err->SetBinContent(7,fun7->GetBinContent(1));//12.5-15
	hDpt_high_err->SetBinContent(8,fun8->GetBinContent(1));//15-20
	hDpt_high_err->SetBinContent(9,fun9->GetBinContent(1));//20-30

	hDpt_high_err->SetBinError(1,fun1->GetBinError(1));//3-4
	hDpt_high_err->SetBinError(2,fun2->GetBinError(1));//4-5
	hDpt_high_err->SetBinError(3,fun3->GetBinError(1));//5-6
	hDpt_high_err->SetBinError(4,fun4->GetBinError(1));//6-8
	hDpt_high_err->SetBinError(5,fun5->GetBinError(1));//8-10
	hDpt_high_err->SetBinError(6,fun6->GetBinError(1));//10-12.5
	hDpt_high_err->SetBinError(7,fun7->GetBinError(1));//12.5-15
	hDpt_high_err->SetBinError(8,fun8->GetBinError(1));//15-20
	hDpt_high_err->SetBinError(9,fun9->GetBinError(1));//20-30
	
	hDpt_low_err->SetBinContent(1,fun1->GetBinContent(1));//3-4
	hDpt_low_err->SetBinContent(2,fun2->GetBinContent(1));//4-5
	hDpt_low_err->SetBinContent(3,fun3->GetBinContent(1));//5-6
	hDpt_low_err->SetBinContent(4,fun4->GetBinContent(1));//6-8
	hDpt_low_err->SetBinContent(5,fun5->GetBinContent(1));//8-10
	hDpt_low_err->SetBinContent(6,fun6->GetBinContent(1));//10-12.5
	hDpt_low_err->SetBinContent(7,fun7->GetBinContent(1));//12.5-15
	hDpt_low_err->SetBinContent(8,fun8->GetBinContent(1));//15-20
	hDpt_low_err->SetBinContent(9,fun9->GetBinContent(1));//20-30

	hDpt_low_err->SetBinError(1,fun1->GetBinError(2));//3-4
	hDpt_low_err->SetBinError(2,fun2->GetBinError(2));//4-5
	hDpt_low_err->SetBinError(3,fun3->GetBinError(2));//5-6
	hDpt_low_err->SetBinError(4,fun4->GetBinError(2));//6-8
	hDpt_low_err->SetBinError(5,fun5->GetBinError(2));//8-10
	hDpt_low_err->SetBinError(6,fun6->GetBinError(2));//10-12.5
	hDpt_low_err->SetBinError(7,fun7->GetBinError(2));//12.5-15
	hDpt_low_err->SetBinError(8,fun8->GetBinError(2));//15-20
	hDpt_low_err->SetBinError(9,fun9->GetBinError(2));//20-30
	
	hDpt->Multiply(h_ratio);
	hDpt_low_err->Multiply(h_ratio);
	hDpt_high_err->Multiply(h_ratio);

	TCanvas *c1 = new TCanvas("c1","c1");
/*
for ( int i=1;i<10;i++)
{
	cout<<"i: "<<i<<endl;
	cout<<"value: "<<hDpt->GetBinContent(i)<<endl;
	cout<<"high: "<<hDpt_high_err->GetBinError(i)<<endl;
	cout<<"low: "<<hDpt_low_err->GetBinError(i)<<endl;

}
*/
	divideBinWidth(hDpt);
	divideBinWidth(hDpt_high_err);
	divideBinWidth(hDpt_low_err);

	TH1F *h_crosssection = (TH1F*) hDpt->Clone("h_crosssection");
	h_crosssection->Divide(hrecoeffi_weighted);   //the error I am not sure. 
    h_crosssection->Scale(1./(2*lumi*BR));
	h_crosssection->Scale(1./1000000); //this is for unit change.

	hDpt_high_err->Divide(hrecoeffi_weighted);   
    hDpt_high_err->Scale(1./(2*lumi*BR));
	hDpt_high_err->Scale(1./1000000);
	
	hDpt_low_err->Divide(hrecoeffi_weighted);    
    hDpt_low_err->Scale(1./(2*lumi*BR));
	hDpt_low_err->Scale(1./1000000); 

cout<<"begin filling the asymmetry TGrapher "<<endl;
	double x[9]={3.5,4.5,5.5,7,9,(10+12.5)/2,(12.5+15)/2,(15+20)/2,25};
	double py[9];
	double err_high[9];
	double err_low[9];
	//double py[4]={h_crosssection->GetBinContent(2),h_crosssection->GetBinContent(3), h_crosssection->GetBinContent(4),h_crosssection->GetBinContent(5)};
	double zero[9] ={0,0,0,0,0,0,0,0,0};
	//double err_high[4]={hDpt_high_err->GetBinContent(2),hDpt_high_err->GetBinContent(3),hDpt_high_err->GetBinContent(4),hDpt_high_err->GetBinContent(5)};
	//double err_low[4]={hDpt_low_err->GetBinContent(2),hDpt_low_err->GetBinContent(3),hDpt_low_err->GetBinContent(4),hDpt_low_err->GetBinContent(5)};
	for (int i=0; i<9; i++)
	{
		py[i]=h_crosssection->GetBinContent(i+1);
		err_high[i]=hDpt_high_err->GetBinError(i+1);
		err_low[i]=hDpt_low_err->GetBinError(i+1);

		cout<<py[i]<<endl;
	}


		TGraphAsymmErrors * gr = new TGraphAsymmErrors(9,x,py,zero,zero,err_low,err_high);
		gr->SetName("gr");
		
		cout<<gr->Eval(3.5)<<endl;

		TH1F *h_Empty = new TH1F("h_Empty","h_Empty",100,3,30);
		h_Empty->SetAxisRange(0.0001,50,"Y");
		h_Empty->Draw();


		gPad->SetLogy();
		gr->SetMarkerSize(1.5);
		gr->SetMarkerStyle(20);
		gr->SetMarkerColor(2);
		gr->GetXaxis()->CenterTitle();
		gr->GetYaxis()->CenterTitle();
		gr->GetXaxis()->SetTitleOffset(1.0);
		gr->GetYaxis()->SetTitleOffset(1.0);
		gr->GetXaxis()->SetLabelOffset(0.007);
		gr->GetYaxis()->SetLabelOffset(0.007);
		gr->GetXaxis()->SetTitleSize(0.045);
		gr->GetYaxis()->SetTitleSize(0.045);
		gr->GetXaxis()->SetTitleFont(42);
		gr->GetYaxis()->SetTitleFont(42);
		gr->GetXaxis()->SetLabelFont(42);
		gr->GetYaxis()->SetLabelFont(42);
		gr->GetXaxis()->SetLabelSize(0.04);
		gr->GetYaxis()->SetLabelSize(0.04);
		gr->GetXaxis()->SetTitle("P_{T} (GeV/c)");
		gr->GetYaxis()->SetTitle("d#sigma/dP_{T} (#mub GeV^{-1}c, |y_{#Lambda_{C}}|<1)");
		gr->SetLineColor(2);
		gr->Draw("psame");

/*
///for comparsion 2015 official result
	double x1[4]={5.5,7,9,15};
	double y1[4]={5.405,1.752,0.663,0.079};
	double zero1[4]={0,0,0,0};
	double err_high_1[4]={1.13,0.38,0.119,0.024};
	double err_low_1[4]={1.33,0.33,0.109,0.02};
	TGraphAsymmErrors *gr_old = new TGraphAsymmErrors(4,x1,y1,zero1,zero1,err_low_1,err_high_1);
	gr_old->SetName("gr_old");
	gr_old->SetMarkerSize(1.5);
	gr_old->SetMarkerStyle(21);
	gr_old->SetMarkerColor(9);
	gr_old->SetLineColor(9);
	gr_old->Draw("psame");
*/




	TFile * result = new TFile("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/prompt_accp/fourth_turn/crosssection_witheventselection_MBtrigger_fourthturn.root","RECREATE");
	gr->Write();
	result->Close();

}
