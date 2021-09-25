#include "../header.h"
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TF1.h>
#include <vector>
#include <TMath.h>
#include <iostream>
#include "../../prefilter_modify_trigger_sidebandchange_withBBS.h"
#define MAX_XB       20000

double dlscut=3.09;
double chi2cut=8.8444355737265931e-02;
double alphacut=1.2016100458684457e-01;
double kaoncut=6.9083857490045031e-02;
double protoncut=2.8162090410134671e-01;
using namespace std;
Bool_t istest = true;

int BDTG_foreach_MC_2017_weight_combine_10_20_2(TString inputfile="", TString outfile1="", int pbpb=0, int ptMin=3, int ptMax=100, string mvatype="BDTG",int cut_number=5,TString name_variable="0_1_2_3_5")
{

	TString MVAtype = (TString)mvatype;
	bool isPbPb = (bool)pbpb;
	ptmin = ptMin;
	ptmax = ptMax;

	//TString inputfile = "/scratch/halstead/x/xiao147/pp2015_correct_dls_agreedARC_0706_backup/add_branches/firetrigger/Dntuple_MB1_whole.root_10.root";
	if(istest)
	{
		/*
		inputfile = "/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/skim_tree_forBDT/HIZero1/Dntuple_Dntuple_HiForestAOD_998.root_989.root_2632.root";

		outfile1 =Form("/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/fill_BDT/MB_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());
*/
		/*
		inputfile = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_gen_pxpypz/MC_pt10/pkpi_pt10_whole.root";
		outfile1 = Form("/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_gen_pxpypz/MC_pt10/Fill_BDTG_3_100/pkpi_pt10_MC_%s_pT%i_%i_%i_cutvariable_%s_DATA.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());
*/
		inputfile = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_gen_pxpypz/MC_pt10/pkpi_pt10_whole.root";

		outfile1 = Form("/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/with_dlsalpha_weight/pT10_MC_1020_combine/pkpi_pt10_MC_%s_pT%i_%i_%i_cutvariable_%s_DATA_check_corected.root",MVAtype.Data(),ptMin,ptMax,cut_number,name_variable.Data());
		

	}

		TFile *f_5_6_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_5_6_separatefit_dlsbins_update_data.root");
		TFile *f_5_6_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_5_6_separatefit_alphabins_update_data.root");
		
		TFile *f_6_8_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_6_8_separatefit_dlsbins_update_data.root");
		TFile *f_6_8_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_6_8_separatefit_alphabins_update_data.root");
		TFile *f_8_10_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_8_10_separatefit_dlsbins_update_data.root");
		TFile *f_8_10_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_8_10_separatefit_alphabins_update_data.root");
		TFile *f_10_125_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_125_separatefit_dlsbins_update_data.root");
		TFile *f_10_125_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_125_separatefit_alphabins_update_data.root");
		TFile *f_125_15_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_125_15_separatefit_dlsbins_update_data.root");
		TFile *f_125_15_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_125_15_separatefit_alphabins_update_data.root");
		TFile *f_15_20_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_15_20_separatefit_dlsbins_update_data.root");
		TFile *f_10_20_dls_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_20_separatefit_dlsbins_update_data.root");
		TFile *f_10_20_alpha_data = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/scan_cut_fit/data_fit/pp_10_20_separatefit_alphabins_update_data.root");

		TFile *f_5_6_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_5_6.root");
		TFile *f_5_6_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_5_6.root");
		TFile *f_6_8_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_6_8.root");
		TFile *f_6_8_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_6_8.root");
		TFile *f_8_10_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_8_10.root");
		TFile *f_8_10_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_8_10.root");
		TFile *f_10_125_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_10_125.root");
		TFile *f_10_125_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_10_125.root");
		TFile *f_125_15_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_125_15.root");
		TFile *f_125_15_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_125_15.root");
		TFile *f_15_20_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_15_20.root");
		TFile *f_10_20_dls_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_dls_10_20.root");
		TFile *f_10_20_alpha_MC = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/manualy_weight/ROOT/MC_distribution/MC_fit/h_alpha_10_20.root");


		auto * fit_fun_5_6_dls_MC = (TF1*) f_5_6_dls_MC->Get("fit_fun")->Clone("fit_fun_5_6_dls_MC");
		auto * fit_fun_5_6_alpha_MC = (TF1*) f_5_6_alpha_MC->Get("fit_fun");
		auto * fit_fun_6_8_dls_MC = (TF1*) f_6_8_dls_MC->Get("fit_fun");
		auto * fit_fun_6_8_alpha_MC = (TF1*) f_6_8_alpha_MC->Get("fit_fun");
		auto * fit_fun_8_10_dls_MC = (TF1*) f_8_10_dls_MC->Get("fit_fun");
		auto * fit_fun_8_10_alpha_MC = (TF1*) f_8_10_alpha_MC->Get("fit_fun");
		auto * fit_fun_10_125_dls_MC = (TF1*) f_10_125_dls_MC->Get("fit_fun");
		auto * fit_fun_10_125_alpha_MC = (TF1*) f_10_125_alpha_MC->Get("fit_fun");
		auto * fit_fun_125_15_dls_MC = (TF1*) f_125_15_dls_MC->Get("fit_fun");
		auto * fit_fun_125_15_alpha_MC = (TF1*) f_125_15_alpha_MC->Get("fit_fun");
		auto * fit_fun_15_20_dls_MC = (TF1*) f_15_20_dls_MC->Get("fit_fun");
		auto * fit_fun_10_20_dls_MC = (TF1*) f_10_20_dls_MC->Get("fit_fun");
		auto * fit_fun_10_20_alpha_MC = (TF1*) f_10_20_alpha_MC->Get("fit_fun");	
		
		TF1 * fit_fun_5_6_dls_data = (TF1*) f_5_6_dls_data->Get("fit_fun");
		auto * fit_fun_5_6_alpha_data = (TF1*) f_5_6_alpha_data->Get("fit_fun");
		
		auto * fit_fun_6_8_dls_data = (TF1*) f_6_8_dls_data->Get("fit_fun");
		auto * fit_fun_6_8_alpha_data = (TF1*) f_6_8_alpha_data->Get("fit_fun");
		auto * fit_fun_8_10_dls_data = (TF1*) f_8_10_dls_data->Get("fit_fun");
		auto * fit_fun_8_10_alpha_data = (TF1*) f_8_10_alpha_data->Get("fit_fun");
		auto * fit_fun_10_125_dls_data = (TF1*) f_10_125_dls_data->Get("fit_fun");
		auto * fit_fun_10_125_alpha_data = (TF1*) f_10_125_alpha_data->Get("fit_fun");
		auto * fit_fun_125_15_dls_data = (TF1*) f_125_15_dls_data->Get("fit_fun");
		auto * fit_fun_125_15_alpha_data = (TF1*) f_125_15_alpha_data->Get("fit_fun");
		auto * fit_fun_15_20_dls_data = (TF1*) f_15_20_dls_data->Get("fit_fun");
		auto * fit_fun_10_20_dls_data = (TF1*) f_10_20_dls_data->Get("fit_fun");
		auto * fit_fun_10_20_alpha_data = (TF1*) f_10_20_alpha_data->Get("fit_fun");		

	const Int_t NBINS = 10;
	double edges[NBINS+1]={1.5,3,3.5,4,5,6,7,8,9,10.5,12};
	TH1 *h_dls_10_20_corrected = new TH1D("h_dls_10_20_corrected","h_dls_10_20_corrected",NBINS,edges);



	TFile *inf = new TFile(inputfile);
	TTree *t = (TTree*)inf->Get("ntlambdaCtopkpi");
	TTree *ntHlt = (TTree*)inf->Get("ntHlt");
	TTree *ntGen = (TTree*)inf->Get("ntGen");
	TTree *ntSkim = (TTree*)inf->Get("ntSkim");
	TTree *ntHi = (TTree*)inf->Get("ntHi");

	Int_t           Dsize;
	Float_t         Dchi2cl[MAX_XB];   //[Dsize]
	Float_t         Dpt[MAX_XB];
	Float_t         kaon_pt[MAX_XB];
	Float_t         pion_pt[MAX_XB];
	Float_t         proton_pt[MAX_XB];
	Float_t         DlxyBS[MAX_XB];
	Float_t         DlxyBSErr[MAX_XB];
	Float_t         alpha_BS_2D_correction[MAX_XB];
	Float_t         Dtrk1Eta[MAX_XB];
	Float_t         Dtrk2Eta[MAX_XB];
	Float_t         Dtrk3Eta[MAX_XB];
	Float_t         Dy[MAX_XB];
	float Dmass[MAX_XB];
	float   Dtrk1Pt[MAX_XB];
	float   Dtrk1Y[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk2Y[MAX_XB];
	float   Dtrk3Pt[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	int     pBeamScrapingFilter;
	int     pPAprimaryVertexFilter;
	float   PVz;
	bool    Dtrk1highPurity[MAX_XB];
	bool    Dtrk2highPurity[MAX_XB];
	bool    Dtrk3highPurity[MAX_XB];
	float   Dtrk1PtErr[MAX_XB];
	float   Dtrk2PtErr[MAX_XB];
	float   Dtrk3PtErr[MAX_XB];
	int   pass12trigger;
	float   Dtrk1PixelHit[MAX_XB];
	float   Dtrk2PixelHit[MAX_XB];
	float   Dtrk3PixelHit[MAX_XB];
	float   Dtrk1StripHit[MAX_XB];
	float   Dtrk2StripHit[MAX_XB];
	float   Dtrk3StripHit[MAX_XB];
	int     Dgen[MAX_XB];

	t->SetBranchAddress("Dsize", &Dsize);
	t->SetBranchAddress("Dchi2cl", Dchi2cl);
	t->SetBranchAddress("Dpt",Dpt);
	t->SetBranchAddress("kaon_pt",kaon_pt);
	t->SetBranchAddress("pion_pt",pion_pt);
	t->SetBranchAddress("proton_pt",proton_pt);
	t->SetBranchAddress("DlxyBS",DlxyBS);
	t->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	t->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);
	t->SetBranchAddress("Dy",Dy);
	t->SetBranchAddress("Dmass",Dmass);
	t->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	t->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	t->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
	t->SetBranchAddress("Dtrk1Y",Dtrk1Y);
	t->SetBranchAddress("Dtrk2Y",Dtrk2Y);
	t->SetBranchAddress("Dtrk3Y",Dtrk3Y);
	t->SetBranchAddress("PVz",&PVz);
	t->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
	t->SetBranchAddress("Dtrk2highPurity",Dtrk2highPurity);
	t->SetBranchAddress("Dtrk3highPurity",Dtrk3highPurity);
	t->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
	t->SetBranchAddress("Dtrk2PtErr",Dtrk2PtErr);
	t->SetBranchAddress("Dtrk3PtErr",Dtrk3PtErr);
	t->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	t->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	t->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	t->SetBranchAddress("Dtrk1PixelHit",Dtrk1PixelHit);
	t->SetBranchAddress("Dtrk2PixelHit",Dtrk2PixelHit);
	t->SetBranchAddress("Dtrk3PixelHit",Dtrk3PixelHit);
	t->SetBranchAddress("Dtrk1StripHit",Dtrk1StripHit);
	t->SetBranchAddress("Dtrk2StripHit",Dtrk2StripHit);
	t->SetBranchAddress("Dtrk3StripHit",Dtrk3StripHit);
	t->SetBranchAddress("Dgen",Dgen);

	std::vector<std::string> theInputVars;
	string a1="(log10(DlxyBS/sqrt(DlxyBSErr)))";//0
	string a2="Dchi2cl";//1
	string a3="alpha_BS_2D_correction";//2
	string a4="kaon_pt/Dpt";//3
	//string a5="pion_pt/Dpt";
	string a5="proton_pt/Dpt";//5

	theInputVars.push_back(a1);
	theInputVars.push_back(a2);
	theInputVars.push_back(a3);
	theInputVars.push_back(a4); 
	theInputVars.push_back(a5); 

	vector<double> inputValues;
	ReadBDTG mva(theInputVars);

	TFile *outf = new TFile(outfile1,"recreate");
	TTree *mvaTree = new TTree("mvaTree","MVA");

	double MVA[MAX_XB];
	mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
	mvaTree->Branch(Form("BDTG_pt_%i_%i_%i_cutvar_%s_weight",ptMin,ptMax,cut_number,name_variable.Data()),MVA, Form("BDTG_pt_%i_%i_%i_cutvar_%s_weight[Dsize]/D",ptMin,ptMax,cut_number,name_variable.Data()));
	
	double integral_dls_data_5_6 = fit_fun_5_6_dls_data->Integral(2,9);
	double integral_dls_MC_5_6 = fit_fun_5_6_dls_MC->Integral(2,9);
	double integral_alpha_data_5_6 =  fit_fun_5_6_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_5_6 = fit_fun_5_6_alpha_MC->Integral(0,0.2);

	double integral_dls_data_6_8 = fit_fun_6_8_dls_data->Integral(2,9);
	double integral_dls_MC_6_8 = fit_fun_6_8_dls_MC->Integral(2,9);
	double integral_alpha_data_6_8 =  fit_fun_6_8_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_6_8 = fit_fun_6_8_alpha_MC->Integral(0,0.2);

	double integral_dls_data_8_10 = fit_fun_8_10_dls_data->Integral(2,9);
	double integral_dls_MC_8_10 = fit_fun_8_10_dls_MC->Integral(2,9);
	double integral_alpha_data_8_10 =  fit_fun_8_10_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_8_10 = fit_fun_8_10_alpha_MC->Integral(0,0.2);

	double integral_dls_data_10_125 = fit_fun_10_125_dls_data->Integral(2,9);
	double integral_dls_MC_10_125 = fit_fun_10_125_dls_MC->Integral(2,9);
	double integral_alpha_data_10_125 =  fit_fun_10_125_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_10_125 = fit_fun_10_125_alpha_MC->Integral(0,0.2);

	double integral_dls_data_125_15 = fit_fun_125_15_dls_data->Integral(2,9);
	double integral_dls_MC_125_15 = fit_fun_125_15_dls_MC->Integral(2,9);
	double integral_alpha_data_125_15 =  fit_fun_125_15_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_125_15 = fit_fun_125_15_alpha_MC->Integral(0,0.2);
	
	double integral_dls_data_15_20 = fit_fun_15_20_dls_data->Integral(2,9);
	double integral_dls_MC_15_20 = fit_fun_15_20_dls_MC->Integral(2,9);
	
	double integral_dls_data_10_20 = fit_fun_10_20_dls_data->Integral(2,12);
	double integral_dls_MC_10_20 = fit_fun_10_20_dls_MC->Integral(2,12);
	double integral_alpha_data_10_20 = fit_fun_10_20_alpha_data->Integral(0,0.2);
	double integral_alpha_MC_10_20 = fit_fun_10_20_alpha_MC->Integral(0,0.2);
	
	double integral_MC_dls;
	double integral_MC_alpha;
	double corrected_dls_MC;
	double corrected_alpha_MC;
	//cout<<fit_fun_10_20_dls_MC->Integral(2,12)<<"          "<<fit_fun_10_20_dls_MC->Integral(2,9)<<endl;
	//cout<<"data integral: "<<integral_dls_data_5_6<<"   MC integral       "<<integral_dls_MC_5_6<<endl;
	//cout<<"data integral:  "<<integral_alpha_data_5_6<<"  MC integral   "<<integral_alpha_MC_5_6<<endl;

	for(int i=0;i<t->GetEntries();i++)
	//for(int i=0;i<10;i++)
	{
		t->GetEntry(i);
		if(i%1000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
		for(int j=0;j<Dsize;j++)
		{
			MVA[j]=-999;//initial value	  
			double dls_corrected=1;
			double alpha_corrected=1;

			if (Dpt[j]>ptMin&& Dpt[j]<ptMax&&(DlxyBS[j]/sqrt(DlxyBSErr[j]))>2)
			{
				
				if (Dpt[j]>5&&Dpt[j]<6)
				{
					integral_MC_dls=fit_fun_5_6_dls_MC->Integral(2,DlxyBS[j]/sqrt(DlxyBSErr[j]))/integral_dls_MC_5_6;
					integral_MC_alpha=fit_fun_5_6_alpha_MC->Integral(0,alpha_BS_2D_correction[j])/integral_alpha_MC_5_6;	
					int k=0;
					//dls correction
					while(k<=5000)
					{
						corrected_dls_MC=2+k*7./5000;
						if ((fit_fun_5_6_dls_data->Integral(2,corrected_dls_MC)/integral_dls_data_5_6)>=integral_MC_dls)
						{
							//cout<<integral_MC_dls<<"      "<<(fit_fun_5_6_dls_data->Integral(2,corrected_dls_MC)/integral_dls_data_5_6)<<endl;
							break;
						}
						k=k+1;

					}//while k 
					//alpha correction
					if (alpha_BS_2D_correction[j]>=0.2)
					{   
						corrected_alpha_MC=alpha_BS_2D_correction[j];
					}   
					else
					{   
						int m=0;
						while (m<=1000)
						{   
							corrected_alpha_MC=0+0.2*m/1000;
							//cout<<m<<"       "<<corrected_alpha_MC<<endl;
							if ((fit_fun_5_6_alpha_data->Integral(0,corrected_alpha_MC)/integral_alpha_data_5_6)>=integral_MC_alpha)
							{   
								break;
							}   
							m=m+1;
						}//while m
					}//else
					//cout<<alpha_BS_2D_correction[j]<<"        "<<corrected_alpha_MC<<endl;
				}//5-6
				if (Dpt[j]>6&&Dpt[j]<8)
				{
					integral_MC_dls=fit_fun_6_8_dls_MC->Integral(2,DlxyBS[j]/sqrt(DlxyBSErr[j]))/integral_dls_MC_6_8;
					integral_MC_alpha=fit_fun_6_8_alpha_MC->Integral(0,alpha_BS_2D_correction[j])/integral_alpha_MC_6_8;	
					int k=0;
					//dls correction
					while(k<=5000)
					{
						corrected_dls_MC=2+k*7./5000;
						if ((fit_fun_6_8_dls_data->Integral(2,corrected_dls_MC)/integral_dls_data_6_8)>=integral_MC_dls)
						{
							break;
						}
						k=k+1;

					}//while k 
					//alpha correction
					if (alpha_BS_2D_correction[j]>=0.2)
					{   
						corrected_alpha_MC=alpha_BS_2D_correction[j];
					}   
					else
					{   
						int m=0;
						while (m<=1000)
						{   
							corrected_alpha_MC=0+0.2*m/1000;
							if ((fit_fun_6_8_alpha_data->Integral(0,corrected_alpha_MC)/integral_alpha_data_6_8)>=integral_MC_alpha)
							{   
								break;
							}   
							m=m+1;
						}//while m
					}//else
					//cout<<alpha_BS_2D_correction[j]<<"        "<<corrected_alpha_MC<<endl;
				}//6-8
				if (Dpt[j]>8&&Dpt[j]<10)
				{
					integral_MC_dls=fit_fun_8_10_dls_MC->Integral(2,DlxyBS[j]/sqrt(DlxyBSErr[j]))/integral_dls_MC_8_10;
					integral_MC_alpha=fit_fun_8_10_alpha_MC->Integral(0,alpha_BS_2D_correction[j])/integral_alpha_MC_8_10;	
					int k=0;
					//dls correction
					while(k<=5000)
					{
						corrected_dls_MC=2+k*7./5000;
						if ((fit_fun_8_10_dls_data->Integral(2,corrected_dls_MC)/integral_dls_data_8_10)>=integral_MC_dls)
						{
							break;
						}
						k=k+1;

					}//while k 
					//alpha correction
					if (alpha_BS_2D_correction[j]>=0.2)
					{   
						corrected_alpha_MC=alpha_BS_2D_correction[j];
					}   
					else
					{   
						int m=0;
						while (m<=1000)
						{   
							corrected_alpha_MC=0+0.2*m/1000;
							if ((fit_fun_8_10_alpha_data->Integral(0,corrected_alpha_MC)/integral_alpha_data_8_10)>=integral_MC_alpha)
							{   
								break;
							}   
							m=m+1;
						}//while m
					}//else
					//cout<<alpha_BS_2D_correction[j]<<"        "<<corrected_alpha_MC<<endl;
				}//8-10

				if (Dpt[j]>10&&Dpt[j]<20)
				{
					integral_MC_dls=fit_fun_10_20_dls_MC->Integral(2,DlxyBS[j]/sqrt(DlxyBSErr[j]))/integral_dls_MC_10_20;
					integral_MC_alpha=fit_fun_10_20_alpha_MC->Integral(0,alpha_BS_2D_correction[j])/integral_alpha_MC_10_20;	
					if(DlxyBS[j]/sqrt(DlxyBSErr[j])>=12)
					{
						corrected_dls_MC=DlxyBS[j]/sqrt(DlxyBSErr[j]);
					}
					else
					{
						int k=0;
						//dls correction
						while(k<=5000)
						{
							corrected_dls_MC=2+k*10./5000;
							if ((fit_fun_10_20_dls_data->Integral(2,corrected_dls_MC)/integral_dls_data_10_20)>=integral_MC_dls)
							{
								break;
							}
							k=k+1;

						}//while k 
					}
					if(Dpt[j]>10&&Dpt[j]<20&&Dtrk1PtErr[j]/Dtrk1Pt[j]<0.3&&Dtrk2PtErr[j]/Dtrk2Pt[j]<0.3&&Dtrk3PtErr[j]/Dtrk3Pt[j]<0.3&&abs(Dtrk1Eta[j])<1.2&&abs(Dtrk2Eta[j])<1.2&&abs(Dtrk3Eta[j])<1.2&&abs(Dy[j])<1&&Dtrk1highPurity[j]==1&&Dtrk2highPurity[j]==1&&Dtrk3highPurity[j]==1&&DlxyBS[j]/sqrt(DlxyBSErr[j])>2&&(Dtrk1PixelHit[j]+Dtrk1StripHit[j])>=11&&(Dtrk2PixelHit[j]+Dtrk2StripHit[j])>=11&&(Dtrk3PixelHit[j]+Dtrk3StripHit[j])>=11&&Dgen[j]==23333&&Dchi2cl[j]>chi2cut&&alpha_BS_2D_correction[j]<alphacut&&proton_pt[j]/Dpt[j]>protoncut&&kaon_pt[j]/Dpt[j]>kaoncut)
					{
						h_dls_10_20_corrected->Fill(corrected_dls_MC);
					}
					//alpha correction
					if (alpha_BS_2D_correction[j]>=0.2)
					{   
						corrected_alpha_MC=alpha_BS_2D_correction[j];
					}   
					else
					{   
						int m=0;
						while (m<=1000)
						{   
							corrected_alpha_MC=0+0.2*m/1000;
							if ((fit_fun_10_20_alpha_data->Integral(0,corrected_alpha_MC)/integral_alpha_data_10_20)>=integral_MC_alpha)
							{   
								break;
							}   
							m=m+1;
						}//while m
					}//else
					//cout<<alpha_BS_2D_correction[j]<<"        "<<corrected_alpha_MC<<endl;
				}//10-20


				inputValues.clear();
				inputValues.push_back(log10(corrected_dls_MC));//0
				inputValues.push_back(Dchi2cl[j]);//1
				inputValues.push_back(corrected_alpha_MC);//2
				inputValues.push_back(kaon_pt[j]/Dpt[j]);//3
				inputValues.push_back(proton_pt[j]/Dpt[j]);//5

				MVA[j]=mva.GetMvaValue(inputValues);      
			}//if
		}//for Dsize
		mvaTree->Fill();
	}//for entry
	outf->cd();
	t->CloneTree()->Write();
	ntGen->CloneTree()->Write();
	ntSkim->CloneTree()->Write();
	ntHi->CloneTree()->Write();
	ntHlt->CloneTree()->Write();
	h_dls_10_20_corrected->Write();
	outf->Write();
	outf->Close();
	
	return 0;

}
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		BDTG_foreach_MC_2017_weight_combine_10_20_2(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
