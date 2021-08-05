#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TF1.h>
#include <iostream>
#define MAX_XB       20000
#define MAX_GEN      6000


void systematic_recoeffi_pp_with_weight_2017_pp(TString infile,TString infile_datapt,TString outfile){
//void systematic_recoeffi_pp_with_weight_2017_pp(TString infile="/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt2_MC_Dntuple/with_gen_nonprompt/Fill_BDTG_3_100/pkpi_pt2_MC_BDTG_pT3_100_5_cutvariable_0_1_2_3_5_DATA.root",TString infile_datapt="/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG/prompt_accp/first_turn_combine_accp/cross_section_first_turn_fit.root"){
	
	TFile *f1 = TFile::Open(infile);
	TFile *f_genpt_pp = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG/prompt_accp/first_turn_combine_accp/official_pp_Genpt_shape2017.root");
	TFile *f_data_pp_pt = TFile::Open(infile_datapt);
	TFile *f_dataMC_PVz = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/accp/ROOT/BDTG_working_scan/PVz_weight_dataMC_pp.root");	

	TTree *ntlambdaCtopkpi  = (TTree *) f1->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f1->Get("ntGen");
	TTree *ntSkim = (TTree *) f1->Get("ntSkim");
	TTree *mvaTree = (TTree *) f1->Get("mvaTree");
	ntlambdaCtopkpi->AddFriend("ntSkim");
	ntGen->AddFriend("ntSkim");

	auto MC_fit_fun = (TF1*) f_genpt_pp->Get("fit_fun");
	auto data_fit_fun = (TF1*) f_data_pp_pt->Get("fit_data");
	TH1F* h_PVz_weight = (TH1F*) f_dataMC_PVz->Get("h_weight");

	const Int_t NBINS = 9;
	Double_t edges[NBINS + 1]={3,4,5,6,8,10,12.5,15,20,30};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hGpt = new TH1D("hGpt","Gpt",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	hDpt->Sumw2();
	hGpt->Sumw2();
    
	cout<<"read trees"<<endl;	
	float   Dy[MAX_XB];
	float   Dtrk1Eta[MAX_XB];
	float   Dtrk2Eta[MAX_XB];
	float   Dtrk3Eta[MAX_XB];
	float   Dtrk1Y[MAX_XB];
	float   Dtrk2Y[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	int     Dsize;
	float   Dpt[MAX_XB];
	int     Dgen[MAX_XB];
	int     Gsize;
	float   Gy[MAX_GEN];
	int     GpdgId[MAX_GEN];
	int     GisSignal[MAX_GEN];
	float   Gpt[MAX_GEN];
	int     pBeamScrapingFilter;
	int     pPAprimaryVertexFilter;
	float   PVz;
	float   Dgenpt[MAX_XB];
	bool    Dtrk1highPurity[MAX_XB];
	bool    Dtrk2highPurity[MAX_XB];
	bool    Dtrk3highPurity[MAX_XB];
	float   Dtrk1PtErr[MAX_XB];
	float   Dtrk2PtErr[MAX_XB];
	float   Dtrk3PtErr[MAX_XB];
	float   Dtrk1Pt[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk3Pt[MAX_XB];
	float   DlxyBS[MAX_XB];
	float   DlxyBSErr[MAX_XB];
	double BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[MAX_XB];
	int     Dgen_nonprompt[MAX_XB];
	int     Gnonprompt[MAX_GEN];
	float   Dtrk1PixelHit[MAX_XB];
	float   Dtrk2PixelHit[MAX_XB];
	float   Dtrk3PixelHit[MAX_XB];
	float   Dtrk1StripHit[MAX_XB];
	float   Dtrk2StripHit[MAX_XB];
	float   Dtrk3StripHit[MAX_XB];


	ntlambdaCtopkpi->SetBranchAddress("Dy",Dy);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Y",Dtrk1Y);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Y",Dtrk2Y);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Y",Dtrk3Y);
	ntlambdaCtopkpi->SetBranchAddress("Dsize",&Dsize);
	ntlambdaCtopkpi->SetBranchAddress("Dpt",Dpt);
	ntlambdaCtopkpi->SetBranchAddress("Dgen",Dgen);
	ntlambdaCtopkpi->SetBranchAddress("PVz",&PVz);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2highPurity",Dtrk2highPurity);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3highPurity",Dtrk3highPurity);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2PtErr",Dtrk2PtErr);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3PtErr",Dtrk3PtErr);
	ntlambdaCtopkpi->SetBranchAddress("Dgenpt",Dgenpt);
	ntlambdaCtopkpi->SetBranchAddress("Dgen_nonprompt",Dgen_nonprompt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1PixelHit",Dtrk1PixelHit);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2PixelHit",Dtrk2PixelHit);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3PixelHit",Dtrk3PixelHit);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2StripHit",Dtrk2StripHit);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3StripHit",Dtrk3StripHit);
	ntGen->SetBranchAddress("Gsize",&Gsize);
    ntGen->SetBranchAddress("Gy",Gy);
	ntGen->SetBranchAddress("GpdgId",GpdgId);
	ntGen->SetBranchAddress("GisSignal",GisSignal);
	ntGen->SetBranchAddress("Gpt",Gpt);
	ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
	ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
	ntlambdaCtopkpi->SetBranchAddress("DlxyBS",DlxyBS);
	ntlambdaCtopkpi->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	mvaTree->SetBranchAddress("BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight",BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight);
	ntGen->SetBranchAddress("Gnonprompt",Gnonprompt);

	for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries(); entry++)
	{
		ntlambdaCtopkpi->GetEntry(entry);
		ntGen->GetEntry(entry);
		ntSkim->GetEntry(entry);
		mvaTree->GetEntry(entry);
		double weight_reco=0;
		double weight_gen=0;
		double weight_ptvalue=0;
		double weight_ptvalue_gen=0;
		double weight_PVz = h_PVz_weight->GetBinContent(h_PVz_weight->FindBin(PVz));
		if (pBeamScrapingFilter&&pPAprimaryVertexFilter)
		{
			for (int icand = 0; icand < Dsize; icand++ )
			{


				if(Dtrk1PtErr[icand]/Dtrk1Pt[icand]<0.3&&Dtrk2PtErr[icand]/Dtrk2Pt[icand]<0.3&&Dtrk3PtErr[icand]/Dtrk3Pt[icand]<0.3&&abs(Dtrk1Eta[icand])<1.2&&abs(Dtrk2Eta[icand])<1.2&&abs(Dtrk3Eta[icand])<1.2&&abs(Dy[icand])<1&&Dtrk1highPurity[icand]==1&&Dtrk2highPurity[icand]==1&&Dtrk3highPurity[icand]==1&&DlxyBS[icand]/sqrt(DlxyBSErr[icand])>2&&BDTG_pt_3_100_5_cutvar_0_1_2_3_5_weight[icand]>0.77&&(Dtrk1PixelHit[icand]+Dtrk1StripHit[icand])>=11&&(Dtrk2PixelHit[icand]+Dtrk2StripHit[icand])>=11&&(Dtrk3PixelHit[icand]+Dtrk3StripHit[icand])>=11&&Dgen[icand]==23333&&Dgen_nonprompt[icand]==0&&fabs(PVz)<15)
				{
					weight_ptvalue = data_fit_fun->Eval(Dgenpt[icand])/MC_fit_fun->Eval(Dgenpt[icand]);
					
					if (weight_ptvalue<0)
					{
						weight_ptvalue=0;
					}
					weight_reco = weight_ptvalue*weight_PVz;		
					hDpt->Fill(Dpt[icand],weight_reco);
					//hDpt->Fill(Dpt[icand]);
				}


			}//for icand ntlambdac
			for (int icand = 0; icand < Gsize; icand++ )
			{
				if (fabs(Gy[icand])<1&&fabs(GpdgId[icand])==4122&& (GisSignal[icand]==15||GisSignal[icand]==16)&&Gnonprompt[icand]==0)
				{
					weight_ptvalue_gen = data_fit_fun->Eval(Gpt[icand])/MC_fit_fun->Eval(Gpt[icand]);
					if (weight_ptvalue_gen<0)
					{
						weight_ptvalue_gen=0;
					}
					weight_gen = weight_ptvalue_gen*weight_PVz;	
					hGpt->Fill(Gpt[icand],weight_gen);
					//hGpt->Fill(Gpt[icand]);

				}//if
			}//for icand ntGen
		}
	}//for entry
	TH1F *hrecoeffi_fun1 = new TH1F("hrecoeffi_fun1","hrecoefficiency_fun1",NBINS,edges);
	hrecoeffi_fun1->Sumw2();
	hrecoeffi_fun1->Divide(hDpt,hGpt,1,1,"B");
	hrecoeffi_fun1->Draw("e");
	cout<<"1: "<<hrecoeffi_fun1->GetBinContent(1)<<"2: "<<hrecoeffi_fun1->GetBinContent(2)<<"3: "<<hrecoeffi_fun1->GetBinContent(3)<<"4: "<<hrecoeffi_fun1->GetBinContent(4)<<"5: "<<hrecoeffi_fun1->GetBinContent(5)<<endl;
	//hDpt->SetLineColor(2);
	//hGpt->SetLineColor(3);
	//hGpt->SetMinimum(0);
	//hGpt->Draw();
	//hDpt->Draw();

cout<<"acc: "<<hrecoeffi_fun1->GetBinContent(1)<<endl;
cout<<"N: "<<hGpt->GetBinContent(1)<<endl;
cout<<"N err: "<<hGpt->GetBinError(1)<<endl;
cout<<"err: "<<hrecoeffi_fun1->GetBinError(1)<<endl;
cout<<"n: "<<hDpt->GetBinContent(1)<<endl;
cout<<"n err: "<<hDpt->GetBinError(1)<<endl;


	TFile *result = new TFile(Form("%s",outfile.Data()),"RECREATE");    
	hrecoeffi_fun1->Write();
	result->Close();

}
