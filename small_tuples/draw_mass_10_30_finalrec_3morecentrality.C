#include <iostream>
#include <TFile.h>
#include <TH1.h>
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
#include <TCut.h>
#define  MAX_XB    20000

using namespace std;
Bool_t istest = true;
int draw_mass_10_30_finalrec_3morecentrality(TString infile="", TString outfile="",  Bool_t iseos=false, double chi2cut=0.13886, double alphacut=0.04201197, double kaonptcut=0.1594, double pionptcut=0.12202, double protonptcut=0.22831)
{
  if(istest)
  {
	infile="/scratch/brown/xiao147/2018PbPb_rereco_data_Dntuple_05052020_firstturn/masstuples_10_30_differentvarialbles_hadd_brown_whole.root";
	outfile="/scratch/brown/xiao147/2018PbPb_rereco_data_Dntuple_05052020_firstturn/masstuples_10_30_differentvarialbles_rec_uniformcuts_final_3morecentralities.root";
	iseos=false;
  }  
  

  TString ifname;
  if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
  else ifname = infile;
  if (!TFile::Open(ifname))   { cout << " fail to open file" << endl; return 0;}     
  TFile* f = TFile::Open(infile);
  TNtuple * nt1 = (TNtuple *) f->Get("nt1");

  TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");
  
  float mass;
  float dls;
  float alpha;
  float kaonpt;
  float pionpt;
  float protonpt;
  float chi2;
  float pt;
  float Bin;

  nt1->SetBranchAddress("mass",&mass);
  nt1->SetBranchAddress("dls",&dls);
  nt1->SetBranchAddress("alpha",&alpha);
  nt1->SetBranchAddress("kaonpt",&kaonpt);
  nt1->SetBranchAddress("pionpt",&pionpt);
  nt1->SetBranchAddress("protonpt",&protonpt);
  nt1->SetBranchAddress("chi2",&chi2);
  nt1->SetBranchAddress("pt",&pt);
  nt1->SetBranchAddress("Bin",&Bin);

  TNtuple *nt_1 = new TNtuple("nt_1", "10_125_cen0_90_rec","mass");//0-90%
  TNtuple *nt_2 = new TNtuple("nt_2", "125_15_cen0_90_rec","mass");
  TNtuple *nt_3 = new TNtuple("nt_3", "15_20_cen0_90_rec","mass");
  TNtuple *nt_4 = new TNtuple("nt_4", "20_30_cen0_90_rec","mass");
	
  TNtuple *nt_5 = new TNtuple("nt_5", "10_125_cen0_10_rec","mass");//0-10%
  TNtuple *nt_6 = new TNtuple("nt_6", "125_15_cen0_10_rec","mass");
  TNtuple *nt_7 = new TNtuple("nt_7", "15_20_cen0_10_rec","mass");
  TNtuple *nt_8 = new TNtuple("nt_8", "20_30_cen0_10_rec","mass");
	
  TNtuple *nt_9 = new TNtuple("nt_9", "10_125_cen10_30_rec","mass");//10-30%
  TNtuple *nt_10 = new TNtuple("nt_10", "125_15_cen10_30_rec","mass");
  TNtuple *nt_11 = new TNtuple("nt_11", "15_20_cen10_30_rec","mass");
  TNtuple *nt_12 = new TNtuple("nt_12", "20_30_cen10_30_rec","mass");
	
  TNtuple *nt_13 = new TNtuple("nt_13", "10_125_cen30_50_rec","mass");//30-50%
  TNtuple *nt_14 = new TNtuple("nt_14", "125_15_cen30_50_rec","mass");
  TNtuple *nt_15 = new TNtuple("nt_15", "15_20_cen30_50_rec","mass");
  TNtuple *nt_16 = new TNtuple("nt_16", "20_30_cen30_50_rec","mass");
	
  TNtuple *nt_17 = new TNtuple("nt_17", "10_125_cen50_90_rec","mass");//50-90%
  TNtuple *nt_18 = new TNtuple("nt_18", "125_15_cen50_90_rec","mass");
  TNtuple *nt_19 = new TNtuple("nt_19", "15_20_cen50_90_rec","mass");
  TNtuple *nt_20 = new TNtuple("nt_20", "20_30_cen50_90_rec","mass");
	

  for (int i=0; i< nt1->GetEntries(); i++)
  {
	nt1->GetEntry(i);
	//0-90%;
	if (chi2>chi2cut&&alpha<alphacut&&pt>10&&pt<12.5&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut)
	{
		nt_1->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>12.5&&pt<15)
	{
		nt_2->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>15&&pt<20)
	{
		nt_3->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>20&&pt<30)
	{
		nt_4->Fill(mass);
	}
	//0-10
	if (chi2>chi2cut&&alpha<alphacut&&pt>10&&pt<12.5&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&Bin<20)
	{
		nt_5->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>12.5&&pt<15&&Bin<20)
	{
		nt_6->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>15&&pt<20&&Bin<20)
	{
		nt_7->Fill(mass);
	}
	if (chi2>chi2cut&&alpha<alphacut&&kaonpt>kaonptcut&&pionpt>pionptcut&&protonpt>protonptcut&&pt>20&&pt<30&&Bin<20)
	{
		nt_8->Fill(mass);
	}
	//10-30
	if (chi2>1.7026407512100433e-01&&alpha<4.1039934306296620e-02&&pt>10&&pt<12.5&&kaonpt>1.4253181511730856e-01&&pionpt>1.0101802575805585e-01&&protonpt>2.0803238473298030e-01&&Bin>=20&&Bin<60&&log10(dls)>5.9997834638155467e-01)
	{
		nt_9->Fill(mass);
	}
	if (chi2>1.7026407512100433e-01&&alpha<4.1039934306296620e-02&&kaonpt>1.4253181511730856e-01&&pionpt>1.0101802575805585e-01&&protonpt>2.0803238473298030e-01&&pt>12.5&&pt<15&&Bin>=20&&Bin<60&&log10(dls)>5.9997834638155467e-01)
	{
		nt_10->Fill(mass);
	}
	if (chi2>1.3059028591201585e-01&&alpha<5.2805352990738907e-02&&kaonpt>1.9625563157580633e-01&&pionpt>1.1099278970485636e-01&&protonpt>2.7012734011561446e-01&&pt>15&&pt<20&&Bin>=20&&Bin<60&&log10(dls)>4.8301785530748331e-01)
	{
		nt_11->Fill(mass);
	}
	if (chi2>6.4047226331585314e-02&&alpha<3.3976264760583380e-02&&kaonpt>1.2553227181436158e-01&&pionpt>5.4714584532047361e-02&&protonpt>2.5699897413410816e-01&&pt>20&&pt<30&&Bin>=20&&Bin<60&&log10(dls)>5.5919871231868690e-01)
	{
		nt_12->Fill(mass);
	}
	//30-50
	if (chi2>1.1665944891068171e-01&&alpha<5.3406646111235100e-02&&pt>10&&pt<12.5&&kaonpt>1.4894413470856116e-01&&pionpt>1.2474633553054308e-01&&protonpt>2.8880706964724745e-01&&Bin>=60&&Bin<100&&log10(dls)>4.7695901891180192e-01)
	{
		nt_13->Fill(mass);
	}
	if (chi2>1.0303662033846935e-01&&alpha<4.2429897283060770e-02&&kaonpt>1.2183785396294693e-01&&pionpt>9.8421881709406245e-02&&protonpt>2.7537112433455407e-01&&pt>12.5&&pt<15&&Bin>=60&&Bin<100&&log10(dls)>4.7833714160309337e-01)
	{
		nt_14->Fill(mass);
	}
	if (chi2>2.3963883896166818e-01&&alpha<3.5580560037385606e-02&&kaonpt>1.4795413070122054e-01&&pionpt>6.7074208251992645e-02&&protonpt>2.6456612835290677e-01&&pt>15&&pt<20&&Bin>=60&&Bin<100&&log10(dls)>4.8311008135445305e-01)
	{
		nt_15->Fill(mass);
	}
	if (chi2>2.3963883896166818e-01&&alpha<3.5580560037385606e-02&&kaonpt>1.4795413070122054e-01&&pionpt>6.7074208251992645e-02&&protonpt>2.6456612835290677e-01&&pt>20&&pt<30&&Bin>=60&&Bin<100&&log10(dls)>4.8311008135445305e-01)
	{
		nt_16->Fill(mass);
	}
	//50-90
	if (chi2>1.7967935711196595e-01&&alpha<7.3493558379332247e-02&&pt>10&&pt<12.5&&kaonpt>1.3806717283784140e-01&&pionpt>8.4147536110062607e-02&&protonpt>3.1424753091765961e-01&&Bin>=100&&Bin<180&&log10(dls)>3.5625507364690656e-01)
	{
		nt_17->Fill(mass);
	}
	if (chi2>1.8313111369401883e-01&&alpha<7.1590472331040711e-02&&kaonpt>1.3798563044605480e-01&&pionpt>3.7002042336125064e-02&&protonpt>3.2765366978374172e-01&&pt>12.5&&pt<15&&Bin>=100&&Bin<180&&log10(dls)>3.7050697826132201e-01)
	{
		nt_18->Fill(mass);
	}
	if (chi2>2.5821446801524173e-01&&alpha<6.3202081320343467e-02&&kaonpt>1.2644120492187949e-01&&pionpt>5.9404186753845595e-02&&protonpt>3.2312019892098809e-01&&pt>15&&pt<20&&Bin>=100&&Bin<180&&log10(dls)>3.7265046089452847e-01)
	{
		nt_19->Fill(mass);
	}
	if (chi2>1.2178671799801942e-01&&alpha<9.0142676687659601e-02&&kaonpt>1.2628885071372031e-01&&pionpt>4.5123107116517659e-02&&protonpt>2.9632802893070309e-01&&pt>20&&pt<30&&Bin>=100&&Bin<180&&log10(dls)>4.0372011800554924e-01)
	{
		nt_20->Fill(mass);
	}



  }

 
  nt_1->Write();
  nt_2->Write();
  nt_3->Write();
  nt_4->Write();
  nt_5->Write();
  nt_6->Write();
  nt_7->Write();
  nt_8->Write();
  nt_9->Write();
  nt_10->Write();
  nt_11->Write();
  nt_12->Write();
  nt_13->Write();
  nt_14->Write();
  nt_15->Write();
  nt_16->Write();
  nt_17->Write();
  nt_18->Write();
  nt_19->Write();
  nt_20->Write();
  outf->Close();
  return 0;

}



int main(int argc, char *argv[])
{
	if(argc==3)
	{   
		draw_mass_10_30_finalrec_3morecentrality(argv[1], argv[2]);
	}   
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
