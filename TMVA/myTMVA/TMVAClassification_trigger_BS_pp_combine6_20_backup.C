// @(#)root/tmva $Id$
/**********************************************************************************
 * Project   : TMVA - a ROOT-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Root Macro: TMVAClassification                                                 *
 *                                                                                *
 * This macro provides examples for the training and testing of the               *
 * TMVA classifiers.                                                              *
 *                                                                                *
 * As input data is used a toy-MC sample consisting of four Gaussian-distributed  *
 * and linearly correlated input variables.                                       *
 *                                                                                *
 * The methods to be used can be switched on and off by means of booleans, or     *
 * via the prompt command, for example:                                           *
 *                                                                                *
 *    root -l ./TMVAClassification.C\(\"Fisher,Likelihood\"\)                     *
 *                                                                                *
 * (note that the backslashes are mandatory)                                      *
 * If no method given, a default set of classifiers is used.                      *
 *                                                                                *
 * The output file "TMVA.root" can be analysed with the use of dedicated          *
 * macros (simply say: root -l <macro.C>), which can be conveniently              *
 * invoked through a GUI that will appear at the end of the run of this macro.    *
 * Launch the GUI via the command:                                                *
 *                                                                                *
 *    root -l ./TMVAGui.C                                                         *
 *                                                                                *
 **********************************************************************************/

#include "TMVAClassification.h"
#include "../prefilter_modify_trigger_sidebandchange_withBBS.h"
//#include "../prefilter_modify_trigger.h"
void TMVAClassification_trigger_BS_pp_combine6_20(TString collisionsyst="pp", float ptMin=5.0, float ptMax=20.0, TString myMethodList = "" )
{
  Bool_t isPbPb;
  if(collisionsyst=="pp") isPbPb = false;
  else if(collisionsyst=="PbPb") isPbPb = true;
  else
    {
      std::cout<<"  ERROR: invalide collision system"<<std::endl;
      std::cout<<std::endl;
      return;
    }
  ptmin = ptMin;
  ptmax = ptMax;
  colsyst = collisionsyst;
  if(!isPbPb)
    {
      inputSnamepkpi = inputSname_PP_pkpi;
	  inputSnamedelta = inputSname_PP_delta;
	  inputSnamelambda1520 = inputSname_PP_lambda1520;
	  inputSnamekstar = inputSname_PP_kstar;
      inputBname = inputBname_PP;
      mycuts = mycuts_PP;
      mycutb = mycutb_PP;
      mycutg = mycutg_PP;
    }
  else
    {
	  
      inputSnamepkpi = inputSname_PbPb_pkpi;
	  inputSnamedelta = inputSname_PbPb_delta;
	  inputSnamelambda1520 = inputSname_PbPb_lambda1520;
	  inputSnamekstar = inputSname_PbPb_kstar;
      inputBname = inputBname_PbPb;
      mycuts = mycuts_PbPb;
      mycutb = mycutb_PbPb;
      mycutg = mycutg_PbPb;
    }

  TMVA::Tools::Instance();
  
  // to get access to the GUI and all tmva macros
  TString tmva_dir(TString(gRootDir) + "/tmva");
  if(gSystem->Getenv("TMVASYS"))
    tmva_dir = TString(gSystem->Getenv("TMVASYS"));
  gROOT->SetMacroPath(tmva_dir + "/test/:" + gROOT->GetMacroPath() );
  //gROOT->ProcessLine(".L TMVAGui.C");
  
  
  // Default MVA methods to be trained + tested
  std::map<std::string,int> Use;
  
  // --- Cut optimisation
  Use["Cuts"]            = 0;
  Use["CutsD"]           = 0;
  Use["CutsPCA"]         = 0;
  Use["CutsGA"]          = 0;
  Use["CutsSA"]          = 0;
  // 
  // --- 1-dimensional likelihood ("naive Bayes estimator")
  Use["Likelihood"]      = 0;
  Use["LikelihoodD"]     = 0; // the "D" extension indicates decorrelated input variables (see option strings)
  Use["LikelihoodPCA"]   = 0; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
  Use["LikelihoodKDE"]   = 0;
  Use["LikelihoodMIX"]   = 0;
  //
  // --- Mutidimensional likelihood and Nearest-Neighbour methods
  Use["PDERS"]           = 0;
  Use["PDERSD"]          = 0;
  Use["PDERSPCA"]        = 0;
  Use["PDEFoam"]         = 0;
  Use["PDEFoamBoost"]    = 0; // uses generalised MVA method boosting
  Use["KNN"]             = 0; // k-nearest neighbour method
  //
  // --- Linear Discriminant Analysis
  Use["LD"]              = 0; // Linear Discriminant identical to Fisher
  Use["Fisher"]          = 0;
  Use["FisherG"]         = 0;
  Use["BoostedFisher"]   = 0; // uses generalised MVA method boosting
  Use["HMatrix"]         = 0;
  //
  // --- Function Discriminant analysis
  Use["FDA_GA"]          = 0; // minimisation of user-defined function using Genetics Algorithm
  Use["FDA_SA"]          = 0;
  Use["FDA_MC"]          = 0;
  Use["FDA_MT"]          = 0;
  Use["FDA_GAMT"]        = 0;
  Use["FDA_MCMT"]        = 0;
  //
  // --- Neural Networks (all are feed-forward Multilayer Perceptrons)
  Use["MLP"]             = 0; // Recommended ANN
  Use["MLPBFGS"]         = 0; // Recommended ANN with optional training method
  Use["MLPBNN"]          = 0; // Recommended ANN with BFGS training method and bayesian regulator
  Use["CFMlpANN"]        = 0; // Depreciated ANN from ALEPH
  Use["TMlpANN"]         = 0; // ROOT's own ANN
  //
  // --- Support Vector Machine 
  Use["SVM"]             = 0;
  // 
  // --- Boosted Decision Trees
  Use["BDT"]             = 1;  // uses Adaptive Boost
  Use["BDTG"]            = 0; // uses Gradient Boost
  Use["BDTB"]            = 0; // uses Bagging
  Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
  Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting 
  // 
  // --- Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
  Use["RuleFit"]         = 0;
  // ---------------------------------------------------------------
  
  std::cout << std::endl;
  std::cout << "==> Start TMVAClassification" << std::endl;
  
  // Select methods (don't look at this code - not of interest)
  if(myMethodList!= "")
    {
      for(std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;
      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for(unsigned i=0; i<mlist.size(); i++)
        {
          std::string regMethod(mlist[i]);
          if (Use.find(regMethod)==Use.end())
            {
              std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
              for(std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
              std::cout << std::endl;
              return;
            }
          Use[regMethod] = 1;
        }
    }
  
  // --------------------------------------------------------------------------------------------------
  
  // --- Here the preparation phase begins
  
  // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
  TString outfileName(Form("ROOT/TMVA_%s_%.0f_%.0f.root",colsyst.Data(),ptmin,ptmax));
  TFile* outputFile = TFile::Open(outfileName,"RECREATE");
  
  // Create the factory object. Later you can choose the methods
  // whose performance you'd like to investigate. The factory is 
  // the only TMVA object you have to interact with
  //
  // The first argument is the base of the name of all the
  // weightfiles in the directory weight/
  //
  // The second argument is the output file for the training results
  // All TMVA output can be suppressed by removing the "!" (not) in
  // front of the "Silent" argument in the option string
  TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                              "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );
  
  // If you wish to modify default settings
  // (please check "src/Config.h" to see all available global options)
  //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
  //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";
  
  // Define the input variables that shall be used for the MVA training
  // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
  // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
  
  factory->AddVariable("(DlxyBS/sqrt(DlxyBSErr))");//>
  factory->AddVariable("Dchi2cl");//>
  factory->AddVariable("alpha_BS_2D_correction");//<
  factory->AddVariable("kaon_pt/Dpt");//>
  factory->AddVariable("pion_pt/Dpt");//>
  factory->AddVariable("proton_pt/Dpt");//>
//  factory->AddVariable("Dy");
  factory->AddVariable("Dtrk1Eta");
  factory->AddVariable("Dtrk2Eta");
  factory->AddVariable("Dtrk3Eta");
//  factory->AddVariable("abs(Dtrk1Y)");
//  factory->AddVariable("abs(Dtrk2Y)");
//  factory->AddVariable("abs(Dtrk3Y)");
//  factory->AddVariable("(DsvpvDistance * sin(Dalpha))");


  // You can add so-called "Spectator variables", which are not used in the MVA training,
  // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
   // input variables, the response values of all trained MVAs, and the spectator variables
   //factory->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
   //factory->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );

   // Read training and test data
   // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
   //TString fname = "./tmva_class_example.root";
   
   //if (gSystem->AccessPathName( fname ))  // file does not exist in local directory
   //   gSystem->Exec("wget http://root.cern.ch/files/tmva_class_example.root");
   
   
  TFile *inputS_pkpi = new TFile(inputSnamepkpi.Data());
  TFile *inputS_lambda1520 = new TFile(inputSnamelambda1520.Data());
  TFile *inputS_delta =  new TFile(inputSnamedelta.Data());
  TFile *inputS_kstar = new TFile(inputSnamekstar.Data());
  TFile *inputB = new TFile(inputBname.Data());

   std::cout << "--- TMVAClassification       : Using input file: " << inputS_pkpi->GetName() << " & "<< inputB->GetName() << " & "<<inputS_lambda1520->GetName() << " & " << inputS_delta->GetName() << " & " <<inputS_kstar->GetName() <<std::endl;
   
   // --- Register the training and test trees
   
  TTree* background = (TTree*)inputB->Get("ntlambdaCtopkpi");
  background->AddFriend("ntHlt");
  background->AddFriend("ntHi");
  background->AddFriend("ntSkim");

  TTree* signal_pkpi = (TTree*)inputS_pkpi->Get("ntlambdaCtopkpi");
  TTree* signal_lambda1520 = (TTree*)inputS_lambda1520->Get("ntlambdaCtopkpi");
  TTree* signal_delta = (TTree*)inputS_delta->Get("ntlambdaCtopkpi");
  TTree* signal_kstar = (TTree*)inputS_kstar->Get("ntlambdaCtopkpi");
  signal_pkpi->AddFriend("ntGen");
  signal_pkpi->AddFriend("ntHlt");
  signal_pkpi->AddFriend("ntHi");
  signal_pkpi->AddFriend("ntSkim");
  signal_lambda1520->AddFriend("ntGen");
  signal_lambda1520->AddFriend("ntHlt");
  signal_lambda1520->AddFriend("ntHi");
  signal_lambda1520->AddFriend("ntSkim");
  signal_delta->AddFriend("ntGen");
  signal_delta->AddFriend("ntHlt");
  signal_delta->AddFriend("ntHi");
  signal_delta->AddFriend("ntSkim");
  signal_kstar->AddFriend("ntGen");
  signal_kstar->AddFriend("ntHlt");
  signal_kstar->AddFriend("ntHi");
  signal_kstar->AddFriend("ntSkim");

   //global event weights per tree (see below for setting event-wise weights)
   double signalWeight_pkpi     = 0.546448/100*220;
   double signalWeight_lambda1520 = 0.0772834/20*220;
   double signalWeight_delta = 0.17018/50*220 ;
   double signalWeight_kstar = 0.206089/50*220;
   double backgroundWeight = 1.0;
  

   //cout<<"pkpi"<<signalWeight_pkpi<<endl;
   // You can add an arbitrary number of signal or background trees
   factory->AddSignalTree    ( signal_pkpi,     signalWeight_pkpi     );
   factory->AddSignalTree    ( signal_lambda1520, signalWeight_lambda1520);
   factory->AddSignalTree    ( signal_delta, signalWeight_delta);
   factory->AddSignalTree    ( signal_kstar, signalWeight_kstar);
   factory->AddBackgroundTree( background, backgroundWeight );

   //factory->SetSignalWeightExpression    ("pthatweight");
   
   // To give different trees for training and testing, do as follows:
   //    factory->AddSignalTree( signalTrainingTree, signalTrainWeight, "Training" );
   //    factory->AddSignalTree( signalTestTree,     signalTestWeight,  "Test" );
   
   // Use the following code instead of the above two or four lines to add signal and background
   // training and test events "by hand"
   // NOTE that in this case one should not give expressions (such as "var1+var2") in the input
   //      variable definition, but simply compute the expression before adding the event
   //
   //     // --- begin ----------------------------------------------------------
   //     std::vector<double> vars( 4 ); // vector has size of number of input variables
   //     float  treevars[4], weight;
   //     
   //     // Signal
   //     for (Uint ivar=0; ivar<4; ivar++) signal->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   //     for (Uint i=0; i<signal->GetEntries(); i++) {
   //        signal->GetEntry(i);
   //        for (Uint ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //        // add training and test events; here: first half is training, second is testing
   //        // note that the weight can also be event-wise
   //        if (i < signal->GetEntries()/2.0) factory->AddSignalTrainingEvent( vars, signalWeight );
   //        else                              factory->AddSignalTestEvent    ( vars, signalWeight );
   //     }
   //   
   //     // Background (has event weights)
   //     background->SetBranchAddress( "weight", &weight );
   //     for (Uint ivar=0; ivar<4; ivar++) background->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   //     for (Uint i=0; i<background->GetEntries(); i++) {
   //        background->GetEntry(i);
   //        for (Uint ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //        // add training and test events; here: first half is training, second is testing
   //        // note that the weight can also be event-wise
   //        if (i < background->GetEntries()/2) factory->AddBackgroundTrainingEvent( vars, backgroundWeight*weight );
   //        else                                factory->AddBackgroundTestEvent    ( vars, backgroundWeight*weight );
   //     }
         // --- end ------------------------------------------------------------
   //
   // --- end of tree registration 

   // Set individual event weights (the variables must exist in the original TTree)
   //    for signal    : factory->SetSignalWeightExpression    ("weight1*weight2");
   //    for background: factory->SetBackgroundWeightExpression("weight1*weight2");
   //factory->SetBackgroundWeightExpression( "weight" );

   // Apply additional cuts on the signal and background samples (can be different)

   // Tell the factory how to use the training and testing events
   //
   // If no numbers of events are given, half of the events in the tree are used 
   // for training, and the other half for testing:
   //    factory->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
   // To also specify the number of testing events, use:
   //    factory->PrepareTrainingAndTestTree( mycut,
   //                                         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" );
   
   TString cuts; 
   if(!isPbPb) cuts = Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
   else cuts = Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
   TString cutb; 
   if(!isPbPb) cutb = Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
   else cutb = Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
/////here I want to calculate the weight////
   TTree* ntGen_pkpi = (TTree*)inputS_pkpi->Get("ntGen");
   TTree* ntGen_lambda1520 = (TTree*)inputS_lambda1520->Get("ntGen");
   TTree* ntGen_delta = (TTree*)inputS_delta->Get("ntGen");
   TTree* ntGen_kstar = (TTree*)inputS_kstar->Get("ntGen");


///the following part may not suit PbPb.
   const Int_t NBINS = 5;
   Double_t edges[NBINS + 1]={4,5,6,8,10,20};
   TH1 *hGpt_pkpi = new TH1D("hGpt_pkpi","Gpt_pkpi",NBINS,edges);
   TH1 *hGpt_lambda1520 = new TH1D("hGpt_lambda1520","hGpt_lambda1520",NBINS,edges);
   TH1 *hGpt_delta =  new TH1D("hGpt_delta","hGpt_delta",NBINS,edges);
   TH1 *hGpt_kstar = new TH1D("hGpt_kstar","hGpt_kstar",NBINS,edges);
   /*
   TH1F *hPtSignal_pkpi = new TH1F("hPtSignal_pkpi", "hPtSignal_pkpi", NBINS,edges); 
   TH1F *hPtSignal_lambda1520 = new TH1F("hPtSignal_lambda1520","hPtSignal_lambda1520",NBINS,edges);
   TH1F *hPtSignal_delta = new TH1F("hPtSignal_delta","hPtSignal_delta",NBINS,edges);
   TH1F *hPtSignal_kstar = new TH1F("hPtSignal_kstar","hPtSignal_kstar",NBINS,edges);
   */
   TH1F *hPtSignal_pkpi = new TH1F("hPtSignal_pkpi","hPtSignal_pkpi",50,0,40);
   TH1F *hPtSignal_lambda1520 = new TH1F("hPtSignal_lambda1520","hPtSignal_lambda1520",50,0,40);
   TH1F *hPtSignal_delta = new TH1F("hPtSignal_delta","hPtSignal_delta",50,0,40);
   TH1F *hPtSignal_kstar =  new TH1F("hPtSignal_kstar","hPtSignal_kstar",50,0,40);
   hGpt_pkpi->Sumw2();
   hGpt_lambda1520->Sumw2();
   hGpt_delta->Sumw2();
   hGpt_kstar->Sumw2();
   hPtSignal_pkpi->Sumw2();
   hPtSignal_delta->Sumw2();
   hPtSignal_lambda1520->Sumw2();
   hPtSignal_kstar->Sumw2();
   ntGen_pkpi->Project("hGpt_pkpi","Gpt","fabs(GpdgId)==4122&&abs(Gy)<1&&(GisSignal==15||GisSignal==16)");
   ntGen_lambda1520->Project("hGpt_lambda1520","Gpt","fabs(GpdgId)==4122&&abs(Gy)<1&&(GisSignal==15||GisSignal==16)");
   ntGen_delta->Project("hGpt_delta","Gpt","fabs(GpdgId)==4122&&abs(Gy)<1&&(GisSignal==15||GisSignal==16)");
   ntGen_kstar->Project("hGpt_kstar","Gpt","fabs(GpdgId)==4122&&abs(Gy)<1&&(GisSignal==15||GisSignal==16)");
   signal_pkpi->Draw("Dpt>>hPtSignal_pkpi",cuts,"e");
   signal_lambda1520->Draw("Dpt>>hPtSignal_lambda1520",cuts,"e");
   signal_delta->Draw("Dpt>>hPtSignal_delta",cuts,"e");
   signal_kstar->Draw("Dpt>>hPtSignal_kstar",cuts,"e");

   hGpt_pkpi->Scale(signalWeight_pkpi);
   hGpt_lambda1520->Scale(signalWeight_lambda1520);
   hGpt_delta->Scale(signalWeight_delta);
   hGpt_kstar->Scale(signalWeight_kstar);

   hGpt_pkpi->Add(hGpt_lambda1520);
   hGpt_pkpi->Add(hGpt_delta);
   hGpt_pkpi->Add(hGpt_kstar);


//for pp
	TFile *f1 = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/allupdateresult_withsystematic/final_result/unbinned_fit_chebychev/crosssection_witheventselection_MBtrigger.root");
   TH1F* h_crosssection = (TH1F*)f1->Get("h_crosssection");
   h_crosssection->Scale(2*0.0361*0.0635);
   h_crosssection->Sumw2();
   Float_t content0 = h_crosssection->GetBinContent(h_crosssection->FindBin(4.5));
   Float_t content1 = h_crosssection->GetBinContent(h_crosssection->FindBin(5.5));
   Float_t content2 = h_crosssection->GetBinContent(h_crosssection->FindBin(7))*2;
   Float_t content3 = h_crosssection->GetBinContent(h_crosssection->FindBin(9))*2;
   Float_t content4 = h_crosssection->GetBinContent(h_crosssection->FindBin(15))*10;
   Float_t err0 = h_crosssection->GetBinError(1)*1;
   Float_t err1 = h_crosssection->GetBinError(2)*1;
   Float_t err2 = h_crosssection->GetBinError(3)*2;
   Float_t err3 = h_crosssection->GetBinError(4)*2;
   Float_t err4 = h_crosssection->GetBinError(5)*10;
//here we do train in pt range(8-10)
   h_crosssection->SetBinContent(1,content0);
   h_crosssection->SetBinContent(2,content1);
   h_crosssection->SetBinContent(3,content2);
   h_crosssection->SetBinContent(4,content3);
   h_crosssection->SetBinContent(5,content4);
   h_crosssection->SetBinError(1,err0);
   h_crosssection->SetBinError(2,err1);
   h_crosssection->SetBinError(3,err2);
   h_crosssection->SetBinError(4,err3);
   h_crosssection->SetBinError(5,err4);
   TH1F * hweight =(TH1F*) h_crosssection->Clone("hweight");
   hweight->Sumw2();
   hPtSignal_pkpi->Scale(signalWeight_pkpi);
   hPtSignal_lambda1520->Scale(signalWeight_lambda1520);
   hPtSignal_delta->Scale(signalWeight_delta);
   hPtSignal_kstar->Scale(signalWeight_kstar);
   hPtSignal_pkpi->Add(hPtSignal_lambda1520);
   hPtSignal_pkpi->Add(hPtSignal_delta);
   hPtSignal_pkpi->Add(hPtSignal_kstar);
   hweight->Divide(hGpt_pkpi);
   
/*
///here is for PbPb signal weight.
   TFile *f2 = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/differential_yield_cen30_100_alldata_first.root");
   //TFile *f2 = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/differential_yield_cen0_30.root");//////cen0_30
   //TFile *f2 = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/differential_yield_cen0_100.root");
   TH1F *h_yield =(TH1F*)f2->Get("h_yield");
   //h_yield->Scale(2*0.0635*254828627);//old
   h_yield->Scale(2*0.0635*474320693);//cen 30-100
   //h_yield->Scale(2*0.0635*58093759);//cen 0-30
   //h_yield->Scale(2*0.0635*300476831);//cen 0-100
   h_yield->Sumw2();
   Float_t content1_PbPb = h_yield->GetBinContent(h_yield->FindBin(5.5))*1;
   Float_t content2_PbPb = h_yield->GetBinContent(h_yield->FindBin(7))*2;
   Float_t content3_PbPb = h_yield->GetBinContent(h_yield->FindBin(9))*2;
   Float_t content4_PbPb = h_yield->GetBinContent(h_yield->FindBin(15))*10;
   cout<<"a"<<content1_PbPb<<endl;
   Float_t err1_PbPb = h_yield->GetBinError(1);
   Float_t err2_PbPb = h_yield->GetBinError(2)*2;
   Float_t err3_PbPb = h_yield->GetBinError(3)*2;
   Float_t err4_PbPb = h_yield->GetBinError(4)*10;
   h_yield->SetBinContent(1,content1_PbPb);
   h_yield->SetBinContent(2,content2_PbPb);
   h_yield->SetBinContent(3,content3_PbPb);
   h_yield->SetBinContent(4,content4_PbPb);
   h_yield->SetBinError(1,err1_PbPb);
   h_yield->SetBinError(2,err2_PbPb);
   h_yield->SetBinError(3,err3_PbPb);
   h_yield->SetBinError(4,err4_PbPb);
   TH1F * hweight =(TH1F*) h_yield->Clone("hweight");
   hweight->Sumw2();
   hPtSignal_pkpi->Scale(signalWeight_pkpi);
   hPtSignal_lambda1520->Scale(signalWeight_lambda1520);
   hPtSignal_delta->Scale(signalWeight_delta);
   hPtSignal_kstar->Scale(signalWeight_kstar);
   hPtSignal_pkpi->Add(hPtSignal_lambda1520);
   hPtSignal_pkpi->Add(hPtSignal_delta);
   hPtSignal_pkpi->Add(hPtSignal_kstar);
   hweight->Divide(hGpt_pkpi);
*/
   //here we want to train pt 8-10;
   //TString signalWeightExpression = TString::Format("%e",hweight->GetBinContent(hweight->FindBin(15)));
   TString signalWeightExpression = TString::Format("%e",hweight->GetBinContent(hweight->FindBin(15))+hweight->GetBinContent(hweight->FindBin(9))+hweight->GetBinContent(hweight->FindBin(7)));
  // TString signalWeightExpression = TString::Format("0.0699359*%e",hweight->GetBinContent(hweight->FindBin(15)));
 //  TString signalWeightExpression = TString::Format("1.41669503*%e",hweight->GetBinContent(hweight->FindBin(7)));  //only for 5-6 pp
/*
int nEventsBackgroundTree = background->GetEntries(); 
   //TString backgroundWeightExpression = TString::Format("474320693/%i",nEventsBackgroundTree);// for pp and PbPb 30-100%
   TString backgroundWeightExpression = TString::Format("2.5e8/%i",nEventsBackgroundTree);// for pp and PbPb 30-100%
   //TString backgroundWeightExpression = TString::Format("58093759/%i",nEventsBackgroundTree);// for PbPb 0-30%
   //TString backgroundWeightExpression = TString::Format("300476831/%i",nEventsBackgroundTree);// for PbPb0_100
   //TString backgroundWeightExpression = TString::Format("330186187/%i",nEventsBackgroundTree);// for pp and PbPb 10-100% first try
  */

int nEventsBackgroundTree = background->GetEntries(); 
TString backgroundWeightExpression = TString::Format("1402655233/%i",nEventsBackgroundTree);// for pp

   factory->SetSignalWeightExpression(signalWeightExpression);
   factory->SetBackgroundWeightExpression(backgroundWeightExpression);

  // TH1F* hPtSignal = new TH1F("hPtSignal", "hPtSignal", 100, 0, 10);
   TH1F* hPtBackground =  new TH1F("hPtBackground","hPtBackground", 100, 0, 10);
  // signal->Draw("Dpt>>hPtSignal",cuts,"e");
   background->Draw("Dpt>>hPtBackground",cutb,"e");
   int nSignal = hPtSignal_pkpi->Integral()/(hPtSignal_pkpi->GetBinWidth(1));
   int nBackground = hPtBackground->GetEntries();
   cout<<"signal counts passed cuts: "<<nSignal<<endl;
   cout<<"background counts passed cuts: "<<nBackground<<endl;





   TCut mycutS = (TCut)cuts;
   TCut mycutB = (TCut)cutb;
 //factory->PrepareTrainingAndTestTree(mycutS, mycutB,"nTrain_Signal= nSignal/2: nTrain_Background= nBackground/2 :SplitMode=Random:NormMode=NumEvents:!V");
 factory->PrepareTrainingAndTestTree( mycutS, mycutB, "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

   // ---- Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   // Cut optimisation
   if (Use["Cuts"])
      factory->BookMethod( TMVA::Types::kCuts, "Cuts",
                           "!H:!V:FitMethod=MC:EffSel:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax:VarProp[3]=FMax" );
   //                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart" );

   if (Use["CutsD"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsD",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=Decorrelate" );

   if (Use["CutsPCA"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsPCA",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=PCA:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax:VarProp[3]=FMax" );

   if (Use["CutsGA"])
     factory->BookMethod( TMVA::Types::kCuts, "CutsGA",
			  "H:!V:FitMethod=GA:EffSel:Steps=5:Cycles=3:PopSize=400:SC_steps=10:SC_rate=5:SC_factor=0.95:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax:VarProp[3]=FMax:VarProp[4]=FMin");
   //"H:!V:FitMethod=GA:EffSel:Steps=30:Cycles=3:PopSize=400:SC_steps=10:SC_rate=5:SC_factor=0.95:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax");

   if (Use["CutsSA"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsSA",
                           "!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMin:VarProp[3]=FMax:VarProp[4]=FMax:VarProp[5]=FMax" );
                           //"!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale:VarProp[0]=FMax:VarProp[1]=FMax" );
   //                           "!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale:VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax" );

   // Likelihood ("naive Bayes estimator")
   if (Use["Likelihood"])
      factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood",
                           "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );

   // Decorrelated likelihood
   if (Use["LikelihoodD"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodD",
                           "!H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate" );

   // PCA-transformed likelihood
   if (Use["LikelihoodPCA"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodPCA",
                           "!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA" ); 

   // Use a kernel density estimator to approximate the PDFs
   if (Use["LikelihoodKDE"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodKDE",
                           "!H:!V:!TransformOutput:PDFInterpol=KDE:KDEtype=Gauss:KDEiter=Adaptive:KDEFineFactor=0.3:KDEborder=None:NAvEvtPerBin=50" ); 

   // Use a variable-dependent mix of splines and kernel density estimator
   if (Use["LikelihoodMIX"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodMIX",
                           "!H:!V:!TransformOutput:PDFInterpolSig[0]=KDE:PDFInterpolBkg[0]=KDE:PDFInterpolSig[1]=KDE:PDFInterpolBkg[1]=KDE:PDFInterpolSig[2]=Spline2:PDFInterpolBkg[2]=Spline2:PDFInterpolSig[3]=Spline2:PDFInterpolBkg[3]=Spline2:KDEtype=Gauss:KDEiter=Nonadaptive:KDEborder=None:NAvEvtPerBin=50" ); 

   // Test the multi-dimensional probability density estimator
   // here are the options strings for the MinMax and RMS methods, respectively:
   //      "!H:!V:VolumeRangeMode=MinMax:DeltaFrac=0.2:KernelEstimator=Gauss:GaussSigma=0.3" );
   //      "!H:!V:VolumeRangeMode=RMS:DeltaFrac=3:KernelEstimator=Gauss:GaussSigma=0.3" );
   if (Use["PDERS"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERS",
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600" );

   if (Use["PDERSD"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERSD",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=Decorrelate" );

   if (Use["PDERSPCA"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERSPCA",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=PCA" );

   // Multi-dimensional likelihood estimator using self-adapting phase-space binning
   if (Use["PDEFoam"])
      factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoam",
                           "!H:!V:SigBgSeparate=F:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" );

   if (Use["PDEFoamBoost"])
      factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoamBoost",
                           "!H:!V:Boost_Num=30:Boost_Transform=linear:SigBgSeparate=F:MaxDepth=4:UseYesNoCell=T:DTLogic=MisClassificationError:FillFoamWithOrigWeights=F:TailCut=0:nActiveCells=500:nBin=20:Nmin=400:Kernel=None:Compress=T" );

   // K-Nearest Neighbour classifier (KNN)
   if (Use["KNN"])
      factory->BookMethod( TMVA::Types::kKNN, "KNN",
                           "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   // H-Matrix (chi2-squared) method
   if (Use["HMatrix"])
      factory->BookMethod( TMVA::Types::kHMatrix, "HMatrix", "!H:!V:VarTransform=None" );

   // Linear discriminant (same as Fisher discriminant)
   if (Use["LD"])
      factory->BookMethod( TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher discriminant (same as LD)
   if (Use["Fisher"])
      factory->BookMethod( TMVA::Types::kFisher, "Fisher", "H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher with Gauss-transformed input variables
   if (Use["FisherG"])
      factory->BookMethod( TMVA::Types::kFisher, "FisherG", "H:!V:VarTransform=Gauss" );

   // Composite classifier: ensemble (tree) of boosted Fisher classifiers
   if (Use["BoostedFisher"])
      factory->BookMethod( TMVA::Types::kFisher, "BoostedFisher", 
                           "H:!V:Boost_Num=20:Boost_Transform=log:Boost_Type=AdaBoost:Boost_AdaBoostBeta=0.2:!Boost_DetailedMonitoring" );

   // Function discrimination analysis (FDA) -- test of various fitters - the recommended one is Minuit (or GA or SA)
   if (Use["FDA_MC"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MC",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:SampleSize=100000:Sigma=0.1" );

   if (Use["FDA_GA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:PopSize=300:Cycles=3:Steps=20:Trim=True:SaveBestGen=1" );

   if (Use["FDA_SA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_SA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=SA:MaxCalls=15000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   if (Use["FDA_MT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=2:UseImprove:UseMinos:SetBatch" );

   if (Use["FDA_GAMT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GAMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:Cycles=1:PopSize=5:Steps=5:Trim" );

   if (Use["FDA_MCMT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MCMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:SampleSize=20" );

   // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
   if (Use["MLP"])
      factory->BookMethod( TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator" );

   if (Use["MLPBFGS"])
      factory->BookMethod( TMVA::Types::kMLP, "MLPBFGS", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:!UseRegulator" );

   if (Use["MLPBNN"])
      factory->BookMethod( TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" ); // BFGS training with bayesian regulators

   // CF(Clermont-Ferrand)ANN
   if (Use["CFMlpANN"])
      factory->BookMethod( TMVA::Types::kCFMlpANN, "CFMlpANN", "!H:!V:NCycles=2000:HiddenLayers=N+1,N"  ); // n_cycles:#nodes:#nodes:...  

   // Tmlp(Root)ANN
   if (Use["TMlpANN"])
      factory->BookMethod( TMVA::Types::kTMlpANN, "TMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N:LearningMethod=BFGS:ValidationFraction=0.3"  ); // n_cycles:#nodes:#nodes:...

   // Support Vector Machine
   if (Use["SVM"])
      factory->BookMethod( TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm" );

   // Boosted Decision Trees
   if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

   if (Use["BDT"])  // Adaptive Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTB"]) // Bagging
      factory->BookMethod( TMVA::Types::kBDT, "BDTB",
                           "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDTD",
                           "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );

   if (Use["BDTF"])  // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod( TMVA::Types::kBDT, "BDTMitFisher",
                           "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20" );

   // RuleFit -- TMVA implementation of Friedman's method
   if (Use["RuleFit"])
      factory->BookMethod( TMVA::Types::kRuleFit, "RuleFit",
                           "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02" );

   // For an example of the category classifier usage, see: TMVAClassificationCategory

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can optimize the setting (configuration) of the MVAs using the set of training events

   // ---- STILL EXPERIMENTAL and only implemented for BDT's ! 
   // factory->OptimizeAllMethods("SigEffAt001","Scan");
   // factory->OptimizeAllMethods("ROCIntegral","FitGA");

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can tell the factory to train, test, and evaluate the MVAs

   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;

   // Launch the GUI for the root macros
   if(!gROOT->IsBatch()) TMVAGui(outfileName);
}
