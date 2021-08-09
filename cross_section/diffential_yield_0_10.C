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
void diffential_yield_0_10(){
	double N_evt=3.6505427e+08/0.97;//0-10% event numbers
	//event selection is (97+-1.5)%
	//centrality reweight accp*effi
	TFile *f1 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/accp/ROOT/several_turns/third_turn_PVz/combine_accp/accp_P_cen0_10_thirdturn_PVz.root");//accp
	TFile *f2 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/systematic_3gaus/PbPb_10_125_3gaus_pol3_unbinned_rec_cen0_10_10125_cen0_10cut11.root");//10-12.5
	TFile *f3 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/systematic_3gaus/PbPb_125_15_2gaus_pol3_unbinned_rec_cen0_10_3gaus.root");//12.5-15
	TFile *f4 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/systematic_3gaus/PbPb_15_20_2gaus_pol3_unbinned_rec_cen0_10_3gaus.root");//15-20
	TFile *f5 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/systematic_3gaus/PbPb_20_30_2gaus_pol3_unbinned_rec_cen0_10_3gaus.root");//20-30
	TFile *f6 = TFile::Open("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/signal_fit_firstturn/ROOT_files/unbinned_fit/final_result/systematic_3gaus/PbPb_30_40_2gaus_pol3_unbinned_rec_3gaus_cen0_10.root");//30-40

	int a=0;
	int b=10;
	//Taa=5.607;
	double Ncoll_0_10= 1625;
	double sigma_pp=70;
	double Taa = Ncoll_0_10/sigma_pp;
	cout<<"Taa: "<<Taa<<endl;


	TH1F *fun_10_125 = (TH1F*) f2->Get("h_output")->Clone("fun_10_125");
	TH1F *fun_125_15 = (TH1F*) f3->Get("h_output")->Clone("fun_125_15");
	TH1F *fun_15_20 = (TH1F*) f4->Get("h_output")->Clone("fun_15_20");
	TH1F *fun_20_30 = (TH1F*) f5->Get("h_output")->Clone("fun_20_30");
	TH1F *fun_30_40 = (TH1F*) f6->Get("h_output")->Clone("fun_30_40");
	TH1F *hrecoeffi_weighted = (TH1F*) f1->Get("hrecoeff_combine");
	
	cout<<"raw yield:  "<<fun_15_20->GetBinContent(1)<<endl;

	double BR=0.0635;

	const Int_t NBINS = 7;
	Double_t edges[NBINS + 1]={6,8,10,12.5,15,20,30,40};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hDpt_high_err = new TH1D("hDpt_high_err","hDpt_high_err",NBINS,edges);
	TH1 *hDpt_low_err = new TH1D("hDpt_low_err","hDpt_low_err",NBINS,edges);
	TH1 *h_prompt_ratio = new TH1D("h_prompt_ratio","h_prompt_ratio",NBINS,edges);
	h_prompt_ratio->Sumw2();
	hDpt->Sumw2();
	hDpt_high_err->Sumw2();
	hDpt_low_err->Sumw2();
	
	h_prompt_ratio->SetBinContent(1,0);//6-8
	h_prompt_ratio->SetBinContent(2,0);//8-10
	h_prompt_ratio->SetBinContent(3,0.69);//10-12.5
	h_prompt_ratio->SetBinContent(4,0.91);//12.5
	h_prompt_ratio->SetBinContent(5,0.96);//15-20
	h_prompt_ratio->SetBinContent(6,0.94);
	h_prompt_ratio->SetBinContent(7,0.9);

    h_prompt_ratio->SetBinError(1,0);
    h_prompt_ratio->SetBinError(2,0);
	h_prompt_ratio->SetBinError(3,0.22);
	h_prompt_ratio->SetBinError(4,0.03);
	h_prompt_ratio->SetBinError(5,0.03);
	h_prompt_ratio->SetBinError(6,0.02);
	h_prompt_ratio->SetBinError(7,0.04);

    hDpt->SetBinContent(1,0);
    hDpt->SetBinContent(2,0);
	hDpt->SetBinContent(3,fun_10_125->GetBinContent(1));
	hDpt->SetBinContent(4,fun_125_15->GetBinContent(1));
	hDpt->SetBinContent(5,fun_15_20->GetBinContent(1));
	hDpt->SetBinContent(6,fun_20_30->GetBinContent(1));
	hDpt->SetBinContent(7,fun_30_40->GetBinContent(1));


    hDpt_high_err->SetBinContent(1,0);
    hDpt_high_err->SetBinContent(2,0);
	hDpt_high_err->SetBinContent(3,fun_10_125->GetBinError(1));
	hDpt_high_err->SetBinContent(4,fun_125_15->GetBinError(1));
	hDpt_high_err->SetBinContent(5,fun_15_20->GetBinError(1));
	hDpt_high_err->SetBinContent(6,fun_20_30->GetBinError(1));
	hDpt_high_err->SetBinContent(7,fun_30_40->GetBinError(1));

    hDpt_low_err->SetBinContent(1,0);
    hDpt_low_err->SetBinContent(2,0);
	hDpt_low_err->SetBinContent(3,fun_10_125->GetBinError(2));	
	hDpt_low_err->SetBinContent(4,fun_125_15->GetBinError(2));	
	hDpt_low_err->SetBinContent(5,fun_15_20->GetBinError(2));	
	hDpt_low_err->SetBinContent(6,fun_20_30->GetBinError(2));	
	hDpt_low_err->SetBinContent(7,fun_30_40->GetBinError(2));	

	TCanvas *c1 = new TCanvas("c1","c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	divideBinWidth(hDpt);
	divideBinWidth(hDpt_high_err);
	divideBinWidth(hDpt_low_err);

	TH1F *h_yield = (TH1F*) hDpt->Clone("h_yield");
	h_yield->Sumw2();
	h_yield->Multiply(h_prompt_ratio);
	h_yield->Divide(hrecoeffi_weighted);  
	h_yield->Scale(1./(2*N_evt*BR));
	h_yield->Scale(1./(Taa/1000));
	h_yield->Sumw2();

	hDpt_high_err->Divide(hrecoeffi_weighted);
	hDpt_high_err->Multiply(h_prompt_ratio);
	hDpt_high_err->Scale(1./(2*N_evt*BR));
	hDpt_high_err->Scale(1./(Taa/1000));
cout<<"accp: "<<hrecoeffi_weighted->GetBinContent(hrecoeffi_weighted->FindBin(17))<<endl;
cout<<"Nevent: "<<N_evt<<endl;
cout<<"prompt ratio:  "<<h_prompt_ratio->GetBinContent(h_prompt_ratio->FindBin(17))<<endl;

	hDpt_low_err->Divide(hrecoeffi_weighted);
	hDpt_low_err->Multiply(h_prompt_ratio);
	hDpt_low_err->Scale(1./(2*N_evt*BR));
	hDpt_low_err->Scale(1./(Taa/1000));
cout<<"yield:  "<<h_yield->GetBinContent(h_yield->FindBin(17))<<endl;
/*
	for (int i=1;i<8;i++)
	{
		cout<<"i: "<<i<<endl;
		cout<<"value: "<<h_yield->GetBinContent(i)<<endl;
		cout<<"high: "<<hDpt_high_err->GetBinContent(i)<<endl;
		cout<<"low: "<<hDpt_low_err->GetBinContent(i)<<endl;

	}
*/

	cout<<"begin filling the asymmetry TGrapher "<<endl;

	double x[5];
	double py[5];
	double zero[5] ={1.25,1.25,2.5,5,5};
	double err_high[5];
	double err_low[5];

	for (int i=2;i<7;i++)
	{
		x[i-2]=(edges[i]+edges[i+1])/2;
		py[i-2]=h_yield->GetBinContent(i+1);
		err_high[i-2]=hDpt_high_err->GetBinContent(i+1);
		err_low[i-2]=hDpt_low_err->GetBinContent(i+1);
		cout<<"x:  "<<x[i-2]<<endl;
		cout<<"py: "<<py[i-2]<<endl;
		

	}

	TGraphAsymmErrors *gr = new TGraphAsymmErrors(5,x,py,zero,zero,err_low,err_high);
	gr->SetName("gr");

	gPad->SetLogy();
	gr->SetMarkerSize(1.1);
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
	gr->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	gr->GetYaxis()->SetTitle("dN/dp_{T} (GeV^{-1}c, |y_{#Lambda_{C}}|<1)");
	gr->SetLineColor(2);
	gr->Draw("ap");

	//	c1->SaveAs(Form("yield_%i_%i_centra_reweight_withcentrality_reweight0227.gif",a,b));	
	TFile * result = new TFile(Form("/home/xiao147/private/2018_PbPb_Lc_rereco_Dntuple/CMSSW_10_3_3_patch1/src/Bfinder/Bfinder/Dntuple/analysis_steps/accp/ROOT/several_turns/third_turn_PVz/differential_yield_TMVA_PbPbMC_%i_%i_centr_reweight_withcentralityreweight.root",a,b),"RECREATE");
	gr->Write();
	result->Close();

}
