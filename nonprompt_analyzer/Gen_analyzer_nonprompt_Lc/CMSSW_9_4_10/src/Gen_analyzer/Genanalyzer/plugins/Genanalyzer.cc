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
		TH1D *h_Lcpt_Bhadron;
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
   f_weight = TFile::Open("$CMSSW_BASE/src/data/Bhadron_y7_weight_1b1events_09082019_fit.root");
   //f_weight = TFile::Open("$CMSSW_BASE/src/data/Bhadron_y2_weight_1b1events_09082019_fit.root");
   
   pT_weight = (TGraph*)f_weight->Get("Bhadron_ptweight");
   fit_weight = (TF1*)f_weight->Get("fit_weight");
   h_Lcpt_Bhadron = fs->make<TH1D>("h_Lcpt_Bhadron", "h_Lcpt_Bhadron",37,3,40);
   h_pt = fs->make<TH1D>("h_pt","h_pt",37,3,40);
   h_Lcpt_Bhadron->Sumw2();
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
		h_pt->Fill(p.pt());
		//cout<<"weight function test: "<<pT_weight->Eval(10)<<endl;
		if (p.numberOfMothers() !=0)
		{
		
		}//number of mo
		if (abs(pdg)==4122&&(abs(p.mother(0)->pdgId())==5122||abs(p.mother(0)->pdgId())==511||abs(p.mother(0)->pdgId())==521||abs(p.mother(0)->pdgId())==531||abs(p.mother(0)->pdgId())==5132||abs(p.mother(0)->pdgId())==5232||abs(p.mother(0)->pdgId())==5332)&&abs(p.y())<1)
		{  
			if (p.numberOfMothers()==0) cout<<"FALSE!!!"<<endl;
			else{
			cout<<"number Lc mo: "<<p.numberOfMothers()<<"mo  pT:"<<p.mother(0)->pt()<<" mo pdgId: "<<p.mother(0)->pdgId()<<endl;
			double weight =-1;
			if (p.mother(0)->pt()<=25)
			{	
			 weight = pT_weight->Eval(p.mother(0)->pt());
			}
			if (p.mother(0)->pt()>25&&p.mother(0)->pt()<=54)
			{
			 weight = fit_weight->Eval(p.mother(0)->pt());
			}
			if (p.mother(0)->pt()>54)
			{
			 weight = fit_weight->Eval(54);
			}

			if (weight<0) cout<<"WEIGHT PROBLEM!!!!!"<<endl;

			cout<<"weight: "<<weight<<endl;
		   	h_Lcpt_Bhadron->Fill(p.pt(),weight);
		   	//h_Lcpt_Bhadron->Fill(p.pt());
			}//else
		}//if
		



   }







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
