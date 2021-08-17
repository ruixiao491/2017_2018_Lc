#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
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
#include <TChain.h>
#include <TCut.h>
#define  MAX_XB    20000
using namespace std;
void skim_tree_formva(TString infile, TString outfile)
		{
			/*
		if(istest)
		{   
		infile ="/scratch/halstead/x/xiao147/pp2015_correct_dls_agreedARC_0706/add_branches/firetrigger/Dntuple_MB2_whole.root_12.root";
		outfile="/scratch/halstead/x/xiao147/BDT_test/skimtree_formva/pp/MB2_skim_MB2_whole.root";
		iseos=false;
		}   
		TString ifname;
		if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
		else ifname = infile;
		if (!TFile::Open(ifname))   { cout << " fail to open file" << endl; return 0;}      
		TFile* f = TFile::Open(infile); 
		TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");
*/
		TFile *f = new TFile(infile);
		TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

		cout<<"---read the needed branch"<<endl;
		TTree * t1 = (TTree *)f->Get("t1");
		TTree t2("t2","skim tree from fire trigger");
		float mass[MAX_XB];
		float pt[MAX_XB];
		float dls[MAX_XB];
		float chi2cl[MAX_XB];
		float alpha[MAX_XB];
		float trk1Pt[MAX_XB];
		float trk1Y[MAX_XB];
		float trk2Pt[MAX_XB];
		float trk2Y[MAX_XB];
		float trk3Pt[MAX_XB];
		float trk3Y[MAX_XB];
		float trk1Eta[MAX_XB];
		float trk2Eta[MAX_XB];
		float trk3Eta[MAX_XB];
		int   size;
		int   Bin;
		float kaonpt[MAX_XB];
		float pionpt[MAX_XB];
		float protonpt[MAX_XB];
		float y[MAX_XB];
		int   pass19trigger;
		float vz;
		int   BeamScrapingFilter;
		int   PAprimaryVertexFilter;
		bool  trk1highPurity[MAX_XB];
		bool  trk2highPurity[MAX_XB];
		bool  trk3highPurity[MAX_XB];
		float trk1PtErr[MAX_XB];
		float trk2PtErr[MAX_XB];
		float trk3PtErr[MAX_XB];
		float DlxyBS_2D[MAX_XB];
		float DlxyBSErr_2D[MAX_XB];
		float alpha_BS2D_correction[MAX_XB];

		t1->SetBranchAddress("size",&size);
		t1->SetBranchAddress("pt",pt);
		t1->SetBranchAddress("dls",dls);
		t1->SetBranchAddress("chi2cl",chi2cl);
		t1->SetBranchAddress("alpha",alpha);
		t1->SetBranchAddress("trk1Pt",trk1Pt);
		t1->SetBranchAddress("trk1Y",trk1Y);
		t1->SetBranchAddress("trk2Pt",trk2Pt);
		t1->SetBranchAddress("trk2Y",trk2Y);
		t1->SetBranchAddress("trk3Pt",trk3Pt);
		t1->SetBranchAddress("trk3Y",trk3Y);
		t1->SetBranchAddress("trk1Eta",trk1Eta);
		t1->SetBranchAddress("trk2Eta",trk2Eta);
		t1->SetBranchAddress("trk3Eta",trk3Eta);
		t1->SetBranchAddress("mass",mass);
		t1->SetBranchAddress("Bin",&Bin);
		t1->SetBranchAddress("kaonpt",kaonpt);
		t1->SetBranchAddress("pionpt",pionpt);
		t1->SetBranchAddress("protonpt",protonpt);
		t1->SetBranchAddress("y",y);
		t1->SetBranchAddress("pass19trigger",&pass19trigger);
		t1->SetBranchAddress("vz",&vz);
		t1->SetBranchAddress("BeamScrapingFilter",&BeamScrapingFilter);
		t1->SetBranchAddress("PAprimaryVertexFilter",&PAprimaryVertexFilter);
		t1->SetBranchAddress("trk1highPurity",trk1highPurity);
		t1->SetBranchAddress("trk2highPurity",trk2highPurity);
		t1->SetBranchAddress("trk3highPurity",trk3highPurity);
		t1->SetBranchAddress("trk1PtErr",trk1PtErr);
		t1->SetBranchAddress("trk2PtErr",trk2PtErr);
		t1->SetBranchAddress("trk3PtErr",trk3PtErr);
		t1->SetBranchAddress("DlxyBS_2D",DlxyBS_2D);
		t1->SetBranchAddress("DlxyBSErr_2D",DlxyBSErr_2D);
		t1->SetBranchAddress("alpha_BS2D_correction",alpha_BS2D_correction);


		float Dmass[MAX_XB];
		float Dpt[MAX_XB];
		float   Dchi2cl[MAX_XB];
		int     Dsize;
		float   Dy[MAX_XB];
		float   Dtrk1Pt[MAX_XB];
		float   Dtrk1Y[MAX_XB];
		float   Dtrk2Pt[MAX_XB];
		float   Dtrk2Y[MAX_XB];
		float   Dtrk3Pt[MAX_XB];
		float   Dtrk3Y[MAX_XB];
		float   Dtrk1Eta[MAX_XB];
		float   Dtrk2Eta[MAX_XB];
		float   Dtrk3Eta[MAX_XB];
		int     hiBin;
		float   pion_pt[MAX_XB];
		float   kaon_pt[MAX_XB];
		float   proton_pt[MAX_XB];
		int     pass19triggers;
		int     pBeamScrapingFilter;
		int     pPAprimaryVertexFilter;
		float   PVz;
		bool    Dtrk1highPurity[MAX_XB];
		bool    Dtrk2highPurity[MAX_XB];
		bool    Dtrk3highPurity[MAX_XB];
		float   Dtrk1PtErr[MAX_XB];
		float   Dtrk2PtErr[MAX_XB];
		float   Dtrk3PtErr[MAX_XB];
		float   DlxyBS[MAX_XB];
		float   DlxyBSErr[MAX_XB];
		float   alpha_BS_2D_correction[MAX_XB];
		
		t2.Branch("Dsize",&Dsize);
		t2.Branch("Dmass",Dmass,"Dmass[Dsize]/F");
		t2.Branch("Dpt",Dpt,"Dpt[Dsize]/F");
	    t2.Branch("Dchi2cl",Dchi2cl,"Dchi2cl[Dsize]/F");
		t2.Branch("Dy",Dy,"Dy[Dsize]/F");
		t2.Branch("Dtrk1Pt",Dtrk1Pt,"Dtrk1Pt[Dsize]/F");
		t2.Branch("Dtrk1Y",Dtrk1Y,"Dtk1Y[Dsize]/F");
		t2.Branch("Dtrk2Pt",Dtrk2Pt,"Dtrk2Pt[Dsize]/F");
		t2.Branch("Dtrk2Y",Dtrk2Y,"Dtrk2Y[Dsize]/F");
		t2.Branch("Dtrk3Pt",Dtrk3Pt,"Dtrk3Pt[Dsize]/F");
		t2.Branch("Dtrk3Y",Dtrk3Y,"Dtrk3Y[Dsize]/F");
		t2.Branch("Dtrk1Eta",Dtrk1Eta,"Dtrk1Eta[Dsize]/F");
		t2.Branch("Dtrk2Eta",Dtrk2Eta,"Dtrk2Eta[Dsize]/F");
		t2.Branch("Dtrk3Eta",Dtrk3Eta,"Dtrk3Eta[Dsize]/F");
		t2.Branch("hiBin",&hiBin);
		t2.Branch("pion_pt",pion_pt,"pion_pt[Dsize]/F");
		t2.Branch("kaon_pt",kaon_pt,"kaon_pt[Dsize]/F");
		t2.Branch("proton_pt",proton_pt,"proton_pt[Dsize]/F");
		t2.Branch("pass19triggers",&pass19triggers);
		t2.Branch("pBeamScrapingFilter",&pBeamScrapingFilter);
		t2.Branch("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
		t2.Branch("PVz",&PVz);
		t2.Branch("Dtrk1highPurity",Dtrk1highPurity,"Dtrk1highPurity[Dsize]/O");
		t2.Branch("Dtrk2highPurity",Dtrk2highPurity,"Dtrk2highPurity[Dsize]/O");
		t2.Branch("Dtrk3highPurity",Dtrk3highPurity,"Dtrk3highPurity[Dsize]/O");
		t2.Branch("Dtrk1PtErr",Dtrk1PtErr,"Dtrk1PtErr[Dsize]/F");
		t2.Branch("Dtrk2PtErr",Dtrk2PtErr,"Dtrk2PtErr[Dsize]/F");
		t2.Branch("Dtrk3PtErr",Dtrk3PtErr,"Dtrk3PtErr[Dsize]/F");
		t2.Branch("DlxyBS",DlxyBS,"DlxyBS[Dsize]/F");
		t2.Branch("DlxyBSErr",DlxyBSErr,"DlxyBSErr[Dsize]/F");
		t2.Branch("alpha_BS_2D_correction",alpha_BS_2D_correction,"alpha_BS_2D_correction[Dsize]/F");

	cout<<"----starting filling the branch in the new tree"<<endl;
	for (int entry = 0; entry < t1->GetEntries();entry++)
	{
		t1->GetEntry(entry);
		Dsize = size;
		hiBin = Bin;
		PVz = vz;
		pass19triggers=pass19trigger;
		pBeamScrapingFilter=BeamScrapingFilter;
		pPAprimaryVertexFilter=PAprimaryVertexFilter;
		int dsize = 0;
		//cout<<"filling the candidate"<<endl;
		for (int i=0;i<size;i++)
		{
			Dmass[dsize]=mass[i];
			Dpt[dsize]=pt[i];
			Dy[dsize]=y[i];
			Dchi2cl[dsize] = chi2cl[i];
			Dtrk1Pt[dsize]=trk1Pt[i];
			Dtrk2Pt[dsize]=trk2Pt[i];
			Dtrk3Pt[dsize]=trk3Pt[i];
			Dtrk1Y[dsize]=trk1Y[i];
			Dtrk1Eta[dsize]=trk1Eta[i];
			Dtrk1highPurity[dsize]=trk1highPurity[i];
			Dtrk1PtErr[dsize]=trk1PtErr[i];
			Dtrk2Y[dsize]=trk2Y[i];
			Dtrk2Eta[dsize]=trk2Eta[i];
			Dtrk2highPurity[dsize]=trk2highPurity[i];
			Dtrk2PtErr[dsize]=trk2PtErr[i];
			Dtrk3Y[dsize]=trk3Y[i];
			Dtrk3highPurity[dsize]=trk3highPurity[i];
			Dtrk3Eta[dsize]=trk3Eta[i];
			Dtrk3PtErr[dsize]=trk3PtErr[i];
			DlxyBS[dsize]=DlxyBS_2D[i];
			DlxyBSErr[dsize]=DlxyBSErr_2D[i];
			alpha_BS_2D_correction[dsize]=alpha_BS_2D_correction[i];
			kaon_pt[dsize]=kaonpt[i];
			pion_pt[dsize]=pionpt[i];
			proton_pt[dsize]=protonpt[i];
			dsize++;
		}//for i
	t2.Fill();
	}//for entry
	t2.Write();
	outf->Write();
	cout<<"----Writing finished"<<endl;
	outf->Close();
	//return 0;


}
/*
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		skim_tree_formva(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
*/
