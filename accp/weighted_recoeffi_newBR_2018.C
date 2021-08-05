#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TLatex.h>
 #include <TStyle.h>
#include <iostream>
void weighted_recoeffi_newBR_2018(TString infile_pkpi, TString infile_lambda1520, TString infile_delta, TString infile_kstar, TString outfile){

	TFile *f1 = TFile::Open(infile_pkpi);
	TFile *f2 = TFile::Open(infile_lambda1520);
	TFile *f3 = TFile::Open(infile_delta);
	TFile *f4 = TFile::Open(infile_kstar);

//for first turn
	TH1F *hrecoeffi_pkpi = (TH1F*) f1->Get("hrecoefficiency");
    TH1F *hrecoeffi_lambda1520 = (TH1F*) f2->Get("hrecoefficiency");
    TH1F *hrecoeffi_delta = (TH1F*) f3->Get("hrecoefficiency");
    TH1F *hrecoeffi_kstar = (TH1F*) f4->Get("hrecoefficiency");

/*
///for several turns
	TH1F *hrecoeffi_pkpi = (TH1F*) f1->Get("hrecoeffi_fun1");
    TH1F *hrecoeffi_lambda1520 = (TH1F*) f2->Get("hrecoeffi_fun1");
    TH1F *hrecoeffi_delta = (TH1F*) f3->Get("hrecoeffi_fun1");
    TH1F *hrecoeffi_kstar = (TH1F*) f4->Get("hrecoeffi_fun1");
*/

	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	//pkpi whole channel is 6.28%
	double BR_pkpi =0.035;
	double BR_lambda1520 =0.00494;
	double BR_delta =0.0108;
	double BR_kstar =0.0131;
	double sum=BR_pkpi+BR_lambda1520+BR_delta+BR_kstar;
	double weight_pkpi=BR_pkpi/sum;
	double weight_lambda1520=BR_lambda1520/sum;
	double weight_delta=BR_delta/sum;
	double weight_kstar=BR_kstar/sum;

	cout<<"pkpi"<<weight_pkpi<<" lambda1520" << weight_lambda1520<<" delta" << weight_delta<<" kstar"<<weight_kstar<<endl;
	TCanvas *c1 = new TCanvas("c1","c1",600,600);
	c1->SetLeftMargin(0.12);
	c1->SetRightMargin(0.05);


    hrecoeffi_pkpi->Scale(weight_pkpi);
	hrecoeffi_pkpi->Sumw2();
	hrecoeffi_lambda1520->Scale(weight_lambda1520);
	hrecoeffi_lambda1520->Sumw2();
	hrecoeffi_delta->Scale(weight_delta);
	hrecoeffi_delta->Sumw2();
	hrecoeffi_kstar->Scale(weight_kstar);
	hrecoeffi_kstar->Sumw2();

	TH1F *hrecoeffi_weighted = (TH1F*)hrecoeffi_pkpi->Clone("hrecoeffi_weighted");
	hrecoeffi_weighted->Add(hrecoeffi_lambda1520);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->Add(hrecoeffi_delta);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->Add(hrecoeffi_kstar);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->SetMarkerSize(1.5);
	hrecoeffi_weighted->SetMarkerColor(2);
	hrecoeffi_weighted->SetMarkerStyle(20);
	hrecoeffi_weighted->SetLineColor(2);
  	hrecoeffi_weighted->GetXaxis()->CenterTitle();
	hrecoeffi_weighted->GetYaxis()->CenterTitle();
	hrecoeffi_weighted->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_weighted->GetYaxis()->SetTitleOffset(1.4);
	hrecoeffi_weighted->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetXaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetYaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetXaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetYaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetYaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetYaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hrecoeffi_weighted->GetYaxis()->SetTitle("Acc #times #epsilon");
	hrecoeffi_weighted->Draw("e");
	
	TLatex* tex;
	tex = new TLatex(0.85,0.85,"pp");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	TFile *result = TFile::Open(Form("%s",outfile.Data()),"RECREATE");
	
	hrecoeffi_weighted->Write();
	result->Close();


}
