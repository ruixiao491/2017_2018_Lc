#include "../header.h"
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <vector>
#include <TMath.h>
#include <iostream>
#include "../../prefilter_modify_trigger_sidebandchange_withBBS.h"

//void BDT(int pbpb, float ptMin , float ptMax, string mvatype)
void BDT(int pbpb=0, float ptMin=6 , float ptMax=20, string mvatype="BDT")
{
  void makeoutput(TString infname, TString ofname, TString mvatype);

  MVAtype = (TString)mvatype;
  isPbPb = (bool)pbpb;
  ptmin = ptMin;
  ptmax = ptMax;
  if(isPbPb)
  {
	  //inputSname = inputSname_PP;
	  //inputBname = inputBname_PP;
	  inputSnamepkpi = inputSname_PbPb_pkpi;
	  inputSnamedelta = inputSname_PbPb_delta;
	  inputSnamelambda1520 = inputSname_PbPb_lambda1520;
	  inputSnamekstar = inputSname_PbPb_kstar;
	  inputBname = inputBname_PbPb;
	  colsyst = "PbPb";
    }
  else{
    //inputSname = inputSname_pp;
	//inputBname = inputBname_pp;
	  inputSnamepkpi = inputSname_PP_pkpi;
	  inputSnamedelta = inputSname_PP_delta;
	  inputSnamelambda1520 = inputSname_PP_lambda1520;
	  inputSnamekstar = inputSname_PP_kstar;
	  inputBname = inputBname_PP;
	  colsyst = "pp";
  }
  
  cout<<"begin producing the outfiles"<<endl;

  TString outfile1 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/%s_%s_%.0f_%.0f_DATA.root",MVAtype.Data(),colsyst.Data(),ptMin,ptMax) ;
  makeoutput(inputBname,outfile1,MVAtype);
  TString outfile2 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/%s_%s_%.0f_%.0f_MC_pkpi.root",MVAtype.Data(),colsyst.Data(),ptMin,ptMax) ;
  makeoutput(inputSnamepkpi,outfile2,MVAtype);
  TString outfile3 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/%s_%s_%.0f_%.0f_MC_delta.root",MVAtype.Data(),colsyst.Data(),ptMin,ptMax) ;
  makeoutput(inputSnamedelta,outfile3,MVAtype);
  TString outfile4 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/%s_%s_%.0f_%.0f_MC_lambda1520.root",MVAtype.Data(),colsyst.Data(),ptMin,ptMax) ;
  makeoutput(inputSnamelambda1520,outfile4,MVAtype);
  TString outfile5 =Form("/scratch/halstead/x/xiao147/BDT_test/MVAfiles/%s_%s_%.0f_%.0f_MC_kstar.root",MVAtype.Data(),colsyst.Data(),ptMin,ptMax) ;
  makeoutput(inputSnamekstar,outfile5,MVAtype);
}

void makeoutput(TString infname, TString ofname, TString mvatype)
{
   TFile *inf = new TFile(infname);
   TTree *t = (TTree*)inf->Get("ntlambdaCtopkpi");
   
   Int_t           Dsize;
   Float_t         Dchi2cl[2000];   //[Dsize]
   Float_t         DlxyBS[2000];   //[Dsize]
   Float_t         DlxyBSErr[2000];   //[Dsize]
   Float_t         alpha_BS_2D_correction[2000];
   Float_t         Dpt[2000];
   Float_t         kaon_pt[2000];
   Float_t         pion_pt[2000];
   Float_t         proton_pt[2000];


   t->SetBranchAddress("Dsize", &Dsize);
   t->SetBranchAddress("Dchi2cl", Dchi2cl);
   t->SetBranchAddress("DlxyBS", DlxyBS);
   t->SetBranchAddress("DlxyBSErr", DlxyBSErr);
   t->SetBranchAddress("alpha_BS_2D_correction",alpha_BS_2D_correction);
   t->SetBranchAddress("Dpt",Dpt);
   t->SetBranchAddress("kaon_pt",kaon_pt);
   t->SetBranchAddress("pion_pt",pion_pt);
   t->SetBranchAddress("proton_pt",proton_pt);
   
   std::vector<std::string> theInputVars;
   string a1="(DlxyBS/sqrt(DlxyBSErr))";
   string a2="Dchi2cl";
   string a3="alpha_BS_2D_correction";
   string a4="kaon_pt/Dpt";
   string a5="pion_pt/Dpt";
   string a6="proton_pt/Dpt";
   theInputVars.push_back(a1);
   theInputVars.push_back(a2);
   theInputVars.push_back(a3);
   theInputVars.push_back(a4); 
   theInputVars.push_back(a5); 
   theInputVars.push_back(a6); 

   vector<double> inputValues;
//cout<<"kf1500"<<endl;
   ReadBDT mva(theInputVars);
//cout<<"kf1600"<<endl;
  
   TFile *outf = new TFile(ofname,"recreate");
   TTree *mvaTree = new TTree("mvaTree","MVA");

   double MVA[2000];
   mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
   mvaTree->Branch(mvatype.Data(),MVA,Form("%s[Dsize]/D",mvatype.Data()));
   
   for(int i=0;i<t->GetEntries();i++)
     {
       t->GetEntry(i);
       if(i%1000000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
       for(int j=0;j<Dsize;j++)
         {
           inputValues.clear();
           inputValues.push_back((DlxyBS[j]/sqrt(DlxyBSErr[j])));
           inputValues.push_back(Dchi2cl[j]);
           inputValues.push_back(alpha_BS_2D_correction[j]);
		   inputValues.push_back(kaon_pt[j]/Dpt[j]);
		   inputValues.push_back(pion_pt[j]/Dpt[j]);
		   inputValues.push_back(proton_pt[j]/Dpt[j]);
		   MVA[j]=mva.GetMvaValue(inputValues);      
         }
      mvaTree->Fill();
   }
   outf->cd();
   outf->Write();
   t->Write();
   outf->Close();
}
