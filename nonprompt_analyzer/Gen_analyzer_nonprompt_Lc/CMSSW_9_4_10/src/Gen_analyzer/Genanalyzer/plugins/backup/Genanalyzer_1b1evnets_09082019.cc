// -*- C++ -*-
//
// Package:    Gen_analyzer/Genanalyzer
// Class:      Genanalyzer
// 
/**\class Genanalyzer Genanalyzer.cc Gen_analyzer/Genanalyzer/plugins/Genanalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Rui Xiao
//         Created:  Wed, 31 Jul 2019 04:00:53 GMT
//
//


// system include files
#include <memory>
#include <iostream>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJet.h"

#include "TH1.h"
#include "TH2.h"
#include "TLorentzVector.h"
#include "TGraph.h"
#include "TString.h"
#include "TF1.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class Genanalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit Genanalyzer(const edm::ParameterSet&);
      ~Genanalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob();
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob();
	  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
	  virtual void endRun(edm::Run const&, edm::EventSetup const&);
	  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);


      // ----------member data ---------------------------
	    edm::EDGetTokenT< reco::GenParticleCollection > genLabel_;
        edm::Service<TFileService> fs;
		//My output histogram
		TH1D *h_bquark_pt_y7;
		TH1D *h_bquark_pt_y1;
		TH1D *h_bquark_pt_y2;
		TH1D *h_Bhadron_pt_y1;
		TH1D *h_Bhadron_pt_y2;
		TH1D *h_Bhadron_pt_y7;
		TH1D *h_Bhadron_pt_y1_Lb;
		TH1D *h_Bhadron_pt_y2_Lb;
		TH1D *h_Bhadron_pt_y7_Lb;
		TH1D *h_bquark_y;
		TH1D *h_Bhadron_y;
		TH1D *h_pt;
		TFile *f_weight;
		TGraph *pT_weight;
		TF1   *fit_weight; 
		 //static int const NBINS =4;
		 //static constexpr double x[NBINS+1]= {5,6,8,10,20};
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Genanalyzer::Genanalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   //my output histogram
   genLabel_           = consumes< reco::GenParticleCollection >(iConfig.getParameter<edm::InputTag>("GenLabel"));
   usesResource("TFileService");
   //f_weight = TFile::Open("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/ARC_comments/prompt_ratio/ROOT/weight_pTshape_Bhardon_FONLL_PYTHIA_withcrosssection_rapidity7_2.root");
   //f_weight = TFile::Open("$CMSSW_BASE/src/data/weight_pTshape_Bhardon_FONLL_PYTHIA_withcrosssection_rapidity7.root");
   f_weight = TFile::Open("$CMSSW_BASE/src/data/weight_pTshape_Bhardon_FONLL_PYTHIA_withcrosssection_rapidity7_largestatistics_witherr_fit.root");
   
   pT_weight = (TGraph*)f_weight->Get("Bhadron_ptweight");
   fit_weight = (TF1*)f_weight->Get("fit_weight");
   h_bquark_pt_y7 = fs->make<TH1D>("h_bquark_pt_y7","h_bquark_pt_y7",600,0,150);
   h_bquark_pt_y1 = fs->make<TH1D>("h_bquark_pt_y1","h_bquark_pt_y1",600,0,150);
   h_bquark_pt_y2 = fs->make<TH1D>("h_bquark_pt_y2","h_bquark_pt_y2",600,0,150);
   h_bquark_y = fs->make<TH1D>("h_bquark_y","h_bquark_y",600,-15,15);
   h_Bhadron_y = fs->make<TH1D>("h_Bhadron_y","h_Bhadron_y",600,-15,15);
   h_Bhadron_pt_y1 = fs->make<TH1D>("h_Bhadron_pt_y1","h_Bhadron_pt_y1",600,0,150);
   h_Bhadron_pt_y2 = fs->make<TH1D>("h_Bhadron_pt_y2","h_Bhadron_pt_y2",600,0,150);
   h_Bhadron_pt_y7 = fs->make<TH1D>("h_Bhadron_pt_y7","h_Bhadron_pt_y7",600,0,150);
   h_Bhadron_pt_y1_Lb = fs->make<TH1D>("h_Bhadron_pt_y1_Lb","h_Bhadron_pt_y1_Lb",600,0,150);
   h_Bhadron_pt_y2_Lb = fs->make<TH1D>("h_Bhadron_pt_y2_Lb","h_Bhadron_pt_y2_Lb",600,0,150);
   h_Bhadron_pt_y7_Lb = fs->make<TH1D>("h_Bhadron_pt_y7_Lb","h_Bhadron_pt_y7_Lb",600,0,150);

   h_pt = fs->make<TH1D>("h_pt","h_pt",600,0,150);
   h_bquark_pt_y7->Sumw2();
   h_bquark_pt_y1->Sumw2();
   h_bquark_pt_y2->Sumw2();
   h_bquark_y->Sumw2();
   h_Bhadron_pt_y1->Sumw2();
   h_Bhadron_pt_y2->Sumw2();
   h_Bhadron_pt_y7->Sumw2();
   h_Bhadron_pt_y1_Lb->Sumw2();
   h_Bhadron_pt_y2_Lb->Sumw2();
   h_Bhadron_pt_y7_Lb->Sumw2();
   h_Bhadron_y->Sumw2();
   h_pt->Sumw2();
   
}


Genanalyzer::~Genanalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
Genanalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace std;
   using namespace edm;

   cout<<"************"<<endl;
   
   edm::Handle<reco::GenParticleCollection> parts;
   iEvent.getByToken(genLabel_, parts);

   for(unsigned int i=0; i<parts->size();i++){
		const reco::GenParticle& p = (*parts)[i];
		int pdg = p.pdgId();
		if (abs(pdg)==5)
		{
		  h_pt->Fill(p.pt());
		}
		if (abs(pdg)==5)
		{  
			if (p.numberOfDaughters()==0) cout<<"FALSE!!!"<<endl;
			else{
			cout<<"number Lc dau: "<<p.numberOfDaughters()<<"mo  pdgId:"<<p.daughter(0)->pdgId()<<endl;
		    if (abs(p.daughter(0)->pdgId())>100)
			{
				h_bquark_y->Fill(p.y());	
				if(abs(p.y())<1)
				{
				   h_bquark_pt_y1->Fill(p.pt());
				}//if y1
				if (abs(p.y())<2)
				{
				   h_bquark_pt_y2->Fill(p.pt());
				}
				if (abs(p.y())<7)
				{
				   h_bquark_pt_y7->Fill(p.pt());
				}

			}

			}//else
		}//if
	
///the followings are for B hadrons
			if (abs(pdg)==511||abs(pdg)==521||abs(pdg)==531||abs(pdg)==5122||abs(pdg)==5132||abs(pdg)==5232||abs(pdg)==5332)
			{
				h_Bhadron_y->Fill(p.y());
				if (abs(p.y())<1)
				{
					h_Bhadron_pt_y1->Fill(p.pt());
				}
				if (abs(p.y())<2)
				{
					h_Bhadron_pt_y2->Fill(p.pt());
				}
				if (abs(p.y())<7)
				{
					h_Bhadron_pt_y7->Fill(p.pt());
				}



			}//if B hadrons

			if (abs(pdg)==511||abs(pdg)==521||abs(pdg)==531||abs(pdg)==5122)
			{
				if (abs(p.y())<1)
				{
					h_Bhadron_pt_y1_Lb->Fill(p.pt());
				}
				if (abs(p.y())<2)
				{
					h_Bhadron_pt_y2_Lb->Fill(p.pt());
				}
				if (abs(p.y())<7)
				{
					h_Bhadron_pt_y7_Lb->Fill(p.pt());
				}



			}//if B hadrons and only Lb baryons





   }//for







#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
Genanalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
Genanalyzer::endJob() 
{
}

//method called once each job just after ending the event loop
void
Genanalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
//method called when ending the processing of a run
void
Genanalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
/*
//method called when starting to process a luminosity block
Genanalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
//method called when ending the process a luminosity block
Genanalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
Genanalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(Genanalyzer);
