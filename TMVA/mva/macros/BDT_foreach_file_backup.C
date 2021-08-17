#include "../header.h"
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <vector>
#include <TMath.h>
#include <iostream>
#include "../../prefilter_modify_trigger_sidebandchange_withBBS.h"
#define MAX_XB       20000

void BDT_foreach_file(TString inputfile, int number, int pbpb=0, float ptMin=6 , float ptMax=20, string mvatype="BDT")
{
	void makeoutput(TString infname, TString ofname, TString mvatype);

	TString MVAtype = (TString)mvatype;
	bool isPbPb = (bool)pbpb;
	ptmin = ptMin;
	ptmax = ptMax;

	//TString inputfile = "/scratch/halstead/x/xiao147/pp2015_correct_dls_agreedARC_0706_backup/add_branches/firetrigger/Dntuple_MB1_whole.root_10.root";

	cout<<"begin producing the outfiles"<<endl;

	//TString outfile1 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/data_withBDT/MB_%i_%s_%.0f_%.0f_DATA.root",number,MVAtype.Data(),ptMin,ptMax) ;//6-20 train together
	TString outfile1 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/data_withBDT/5_6_separate/MB_%i_%s_%.0f_%.0f_DATA.root",number,MVAtype.Data(),ptMin,ptMax) ;
	makeoutput(inputfile,outfile1,MVAtype);
}

void makeoutput(TString infname, TString ofname, TString mvatype)
{
   TFile *inf = new TFile(infname);
   TTree *t = (TTree*)inf->Get("t2");
   
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

   std::vector<std::string> theInputVars;
   string a1="(DlxyBS/sqrt(DlxyBSErr))";
   string a2="Dchi2cl";
   string a3="alpha_BS_2D_correction";
   string a4="kaon_pt/Dpt";
   string a5="pion_pt/Dpt";
   string a6="proton_pt/Dpt";
   string a7="Dtrk1Eta";
   string a8="Dtrk2Eta";
   string a9="Dtrk3Eta";
   //string a10="(DsvpvDistance * sin(Dalpha))"
   theInputVars.push_back(a1);
   theInputVars.push_back(a2);
   theInputVars.push_back(a3);
   theInputVars.push_back(a4); 
   theInputVars.push_back(a5); 
   theInputVars.push_back(a6); 
   theInputVars.push_back(a7); 
   theInputVars.push_back(a8); 
   theInputVars.push_back(a9); 
   //theInputVars.push_back(a10); 

   vector<double> inputValues;
   ReadBDT mva(theInputVars);
  
   TFile *outf = new TFile(ofname,"recreate");
   TTree *mvaTree = new TTree("mvaTree","MVA");

   double MVA[MAX_XB];
   mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
   mvaTree->Branch(mvatype.Data(),MVA,Form("%s[Dsize]/D",mvatype.Data()));
   
   for(int i=0;i<t->GetEntries();i++)
     {
       t->GetEntry(i);
	   if(i%1000000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
	   for(int j=0;j<Dsize;j++)
	   {
		   
		   if (Dpt[j]>ptMin&& Dpt[j]<ptMax)
		   {
		   inputValues.clear();
		   inputValues.push_back((DlxyBS[j]/sqrt(DlxyBSErr[j])));
		   inputValues.push_back(Dchi2cl[j]);
		   inputValues.push_back(alpha_BS_2D_correction[j]);
		   inputValues.push_back(kaon_pt[j]/Dpt[j]);
		   inputValues.push_back(pion_pt[j]/Dpt[j]);
		   inputValues.push_back(proton_pt[j]/Dpt[j]);
		   inputValues.push_back(Dtrk1Eta[j]);
		   inputValues.push_back(Dtrk2Eta[j]);
		   inputValues.push_back(Dtrk3Eta[j]);
		   
		   MVA[j]=mva.GetMvaValue(inputValues);      
         }//if
		 }//for Dsize
      mvaTree->Fill();
   }//for entry
   outf->cd();
   outf->Write();
   outf->Close();
}
