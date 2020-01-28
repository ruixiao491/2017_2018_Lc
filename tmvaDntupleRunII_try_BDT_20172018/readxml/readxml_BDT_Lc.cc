#include "readxml.h"
#include "pre_forread.h"
void readxml_BDT_Lc(TString outputname="test.root",
             TString weightfile="/home/xiao147/private/TMVA_lambdaC/CMSSW_7_5_8_patch3/src/tmvaDntupleRunII_try_BDT/myTMVA/weights/TMVAClassification_BDT.weights.xml", TString collisionsyst="pp",
             TString mvatype="BDT", Float_t ptmin=6, Float_t ptmax=20)
{
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  Bool_t isPbPb = collisionsyst=="PbPb"?true:false;

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



  std::ofstream ofresult(Form("%s_%s.txt",outputresult.Data(),outputname.Data()),std::ofstream::out);
  cfout cfresult(ofresult, std::cout);

  TString cuts = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
  TString cutb = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
  TString cutg = isPbPb?Form("(%s)&&Gpt>%f&&Gpt<%f",mycutg.Data(),ptmin,ptmax):Form("(%s)&&Gpt>%f&&Gpt<%f",mycutg.Data(),ptmin,ptmax);

  // read weight file
  const char* filename = weightfile;
  void *doc = TMVA::gTools().xmlengine().ParseFile(filename,TMVA::gTools().xmlenginebuffersize());
  void* rootnode = TMVA::gTools().xmlengine().DocGetRootElement(doc); //node "MethodSetup"
  TString fullMethodName("");
  TMVA::gTools().ReadAttr(rootnode, "Method", fullMethodName);

  cfresult<<std::endl;
  cfresult<<"  ===================================================="<<std::endl;
  cfresult<<" |                Cut Opt Configuration               |"<<std::endl;
  cfresult<<"  ----------------------------------------------------"<<std::endl;
  cfresult<<" | "<<std::setiosflags(std::ios::left)<<std::setw(10)<<"Method"<<" | "<<std::setw(37)<<fullMethodName<<" |"<<std::endl;

  void* opts = TMVA::gTools().GetChild(rootnode,"Options");
  void* opt = TMVA::gTools().GetChild(opts,"Option");

  TString varProp("");
  while(opt)
    {
      TString optname("");
      TMVA::gTools().ReadAttr(opt, "name", optname);
      if(optname=="VarProp") varProp = TMVA::gTools().GetContent(opt);
      opt = TMVA::gTools().GetNextChild(opt);
    }

  void* variables = TMVA::gTools().GetChild(rootnode,"Variables");
  UInt_t nVar=0;
  std::vector<TString> varnames;
  TMVA::gTools().ReadAttr(variables, "NVar", nVar);
  void* var = TMVA::gTools().GetChild(variables,"Variable");
  for(unsigned int k=0;k<nVar;k++)
    {
      TString varname("");
      TMVA::gTools().ReadAttr(var, "Expression", varname);
      TString tem = Form("Variable%i",k);
      cfresult<<"  ----------------------------------------------------"<<std::endl;
      cfresult<<" | "<<std::setiosflags(std::ios::left)<<std::setw(10)<<tem<<" | "<<std::setw(37)<<varname<<" |"<<std::endl;
      var = TMVA::gTools().GetNextChild(var);
      varnames.push_back(varname);
    }
  cfresult<<"  ===================================================="<<std::endl;
  std::cout<<std::endl;

  TFile *inputS_pkpi = new TFile(inputSnamepkpi.Data());
  TFile *inputS_lambda1520 = new TFile(inputSnamelambda1520.Data());
  TFile *inputS_delta =  new TFile(inputSnamedelta.Data());
  TFile *inputS_kstar = new TFile(inputSnamekstar.Data());
  TFile *inputB = new TFile(inputBname.Data());
  
  TTree* background = (TTree*)inputB->Get("ntlambdaCtopkpi");
  background->AddFriend("ntHlt");
  background->AddFriend("ntHi");
  background->AddFriend("ntSkim");
  background->AddFriend("mvaTree");

  TTree* signal_pkpi = (TTree*)inputS_pkpi->Get("ntlambdaCtopkpi");
  signal_pkpi->AddFriend("ntHlt");
  signal_pkpi->AddFriend("ntHi");
  signal_pkpi->AddFriend("ntSkim");
  signal_pkpi->AddFriend("mvaTree");

  TTree* signal_lambda1520 = (TTree*)inputS_lambda1520->Get("ntlambdaCtopkpi");
  signal_lambda1520->AddFriend("ntHlt");
  signal_lambda1520->AddFriend("ntHi");
  signal_lambda1520->AddFriend("ntSkim");
  signal_lambda1520->AddFriend("mvaTree");

  TTree* signal_delta = (TTree*)inputS_delta->Get("ntlambdaCtopkpi");
  signal_delta->AddFriend("ntHlt");
  signal_delta->AddFriend("ntHi");
  signal_delta->AddFriend("ntSkim");
  signal_delta->AddFriend("mvaTree");
  
  TTree* signal_kstar = (TTree*)inputS_kstar->Get("ntlambdaCtopkpi");
  signal_kstar->AddFriend("ntHlt");
  signal_kstar->AddFriend("ntHi");
  signal_kstar->AddFriend("ntSkim");
  signal_kstar->AddFriend("mvaTree");


  TTree* generated_pkpi = (TTree*)inputS_pkpi->Get("ntGen");
  generated_pkpi->AddFriend("ntHlt");
  generated_pkpi->AddFriend("ntHi");

  TTree* generated_lambda1520 = (TTree*)inputS_lambda1520->Get("ntGen");
  generated_lambda1520->AddFriend("ntHlt");
  generated_lambda1520->AddFriend("ntHi");
  
  TTree* generated_delta = (TTree*)inputS_delta->Get("ntGen");
  generated_delta->AddFriend("ntHlt");
  generated_delta->AddFriend("ntHi");
  
  TTree* generated_kstar = (TTree*)inputS_kstar->Get("ntGen");
  generated_kstar->AddFriend("ntHlt");
  generated_kstar->AddFriend("ntHi");

  float signalWeight_pkpi     = 0.546448/100*220;
  float signalWeight_lambda1520 = 0.0772834/20*220;
  float signalWeight_delta = 0.17018/50*220 ;
  float signalWeight_kstar = 0.206089/50*220;
  float backgroundWeight = 1.0;



  for(int i=0;i<=nMVA;i++) gmvaBins[i] = minMVA+i*widMVA;
  TH1F* hcountEffS_pkpi = new TH1F("hcountEffS_pkpi",Form(";%s;Signal counts",mvatype.Data()),nMVA,minMVA,maxMVA);
  TH1F* hcountEffS_lambda1520 = new TH1F("hcountEffS_lambda1520",Form(";%s;Signal counts",mvatype.Data()),nMVA,minMVA,maxMVA);
  TH1F* hcountEffS_delta = new TH1F("hcountEffS_delta",Form(";%s;Signal counts",mvatype.Data()),nMVA,minMVA,maxMVA);
  TH1F* hcountEffS_kstar = new TH1F("hcountEffS_kstar",Form(";%s;Signal counts",mvatype.Data()),nMVA,minMVA,maxMVA);
  TH1F* hcountEffB = new TH1F("hcountEffB",Form(";%s;Background counts",mvatype.Data()),nMVA,minMVA,maxMVA);
  
  hcountEffS_pkpi->Sumw2();
  hcountEffS_kstar->Sumw2();
  hcountEffS_lambda1520->Sumw2();
  hcountEffS_delta->Sumw2();



  signal_pkpi->Project("hcountEffS_pkpi","BDT",Form("%f*(%s)",signalWeight_pkpi,cuts.Data()));
  signal_lambda1520->Project("hcountEffS_lambda1520","BDT",Form("%f*(%s)",signalWeight_lambda1520,cuts.Data()));
  signal_delta->Project("hcountEffS_delta","BDT",Form("%f*(%s)",signalWeight_delta,cuts.Data()));
  signal_kstar->Project("hcountEffS_kstar","BDT",Form("%f*(%s)",signalWeight_kstar,cuts.Data()));
  background->Project("hcountEffB","BDT",Form("%s",cutb.Data()));

  TH1F* hdisEffS = (TH1F*)hcountEffS_pkpi->Clone("hdisEffS");
  hdisEffS->Sumw2();
  hdisEffS->Add(hcountEffS_lambda1520);
  hdisEffS->Add(hcountEffS_delta);
  hdisEffS->Add(hcountEffS_kstar);
  hdisEffS->Scale(1./hdisEffS->Integral());
  hdisEffS->SetLineColor(kRed);
  hdisEffS->SetFillStyle(3004);
  hdisEffS->SetFillColor(kRed);
  hdisEffS->SetLineWidth(3);
  hdisEffS->SetStats(0);
  TH1F* hdisEffB = (TH1F*)hcountEffB->Clone("hdisEffB");
  hdisEffB->Scale(1./hcountEffB->Integral());
  hdisEffB->SetLineColor(kBlue+1);
  hdisEffB->SetFillStyle(1001);
  hdisEffB->SetFillColor(kBlue-9);
  hdisEffB->SetLineWidth(3);
  hdisEffB->SetStats(0);

  TH1F* hcountEffS = (TH1F*)hcountEffS_pkpi->Clone("hcountEffS");
  hcountEffS->Sumw2();
  hcountEffS->Add(hcountEffS_lambda1520);
  hcountEffS->Add(hcountEffS_delta);
  hcountEffS->Add(hcountEffS_kstar);


  TH2F* hemptydis = new TH2F("hemptydis",Form(";%s;Probability",mvatype.Data()),50,-1.2,1.2,10,0.,hdisEffB->GetMaximum()*1.4);
  sethempty(hemptydis);
  TLatex* texPt = new TLatex(0.22,0.823, Form("%.0f < Lc p_{T} < %.0f GeV",ptmin,ptmax));
  texPt->SetNDC();
  texPt->SetTextAlign(12);
  texPt->SetTextSize(0.045);
  texPt->SetTextFont(42);
  TLatex* texY = new TLatex(0.22,0.773, "|y| < 2.4");
  texY->SetNDC();
  texY->SetTextAlign(12);
  texY->SetTextSize(0.045);
  texY->SetTextFont(42);

  TCanvas* cdisEffSB = new TCanvas("cdisEffSB","",600,600);
  hemptydis->Draw();
  hdisEffB->Draw("same");
  hdisEffS->Draw("same");
  TLegend* leg = new TLegend(0.62,0.75,0.97,0.86);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->AddEntry(hdisEffB,"Background","f");
  leg->AddEntry(hdisEffS,"Signal","f");
  leg->Draw("same");
  drawCMS(collisionsyst);
  texPt->Draw();
  texY->Draw();
  cdisEffSB->SaveAs(Form("%s_%s.pdf",outputmvadis.Data(),outputname.Data()));

  Float_t effS[nMVA+1],effB[nMVA+1],effSig[nMVA+1];
  for(int i=0;i<(nMVA+1);i++)
    {
      effS[i] = 0;
      effB[i] = 0;
      effSig[i] = 0;
    }
  for(int i=0;i<nMVA;i++)
    {
      effS[i] = hcountEffS->Integral(i+1,nMVA)/hcountEffS->Integral();
      effB[i] = hcountEffB->Integral(i+1,nMVA)/hcountEffB->Integral();
    }

  TH2F* hemptyeff = new TH2F("hemptyeff",Form(";%s;Efficiency",mvatype.Data()),50,-1.2,1.2,10,0.,1.4);
  sethempty(hemptyeff);
  TGraph* geffS = new TGraph(nMVA+1,gmvaBins,effS);
  geffS->SetMarkerSize(1.1);
  geffS->SetMarkerColor(kRed);
  geffS->SetLineWidth(2);
  geffS->SetLineColor(kRed);
  TGraph* geffB = new TGraph(nMVA+1,gmvaBins,effB);
  geffB->SetMarkerSize(1.1);
  geffB->SetMarkerColor(kBlue+1);
  geffB->SetLineWidth(2);
  geffB->SetLineColor(kBlue+1);
  TCanvas* ceffSB = new TCanvas("ceffSB","",600,600);
  hemptyeff->Draw();
  geffS->Draw("samepl");
  geffB->Draw("samepl");
  TLegend* legeff = new TLegend(0.62,0.75,0.97,0.86);
  legeff->SetBorderSize(0);
  legeff->SetFillStyle(0);
  legeff->AddEntry(geffB,"Background","pl");
  legeff->AddEntry(geffS,"Signal","pl");
  legeff->Draw("same");
  drawCMS(collisionsyst);
  texPt->Draw();
  texY->Draw();
  ceffSB->SaveAs(Form("%s_%s.pdf",outputefficiency.Data(),outputname.Data()));

  Float_t wSignal=0, wBackground=0;
  Float_t* weights = new Float_t[2];
  //
  //calRatio(signal, background, generated, cuts, cutb, cutg, weight, ptmin, ptmax, "fonlls/fo_pp_Bplus_5p03TeV_y2p4.dat", lumi, raa, outputname, weights);
  //

  wSignal = 1;
  wBackground = 1;

  std::cout<<std::endl;
  std::cout<<"Looking for max significance ..."<<std::endl;

  Double_t maxsig = 0;
  Int_t maxindex = 0;
  for(int i=0;i<nMVA;i++)
    {
      //effSig[i] = wSignal*effS[i]/sqrt(wSignal*effS[i]+wBackground*effB[i]);
      effSig[i] = wSignal*effS[i]/sqrt(wBackground*effB[i]);
	  if(effSig[i]>maxsig)
	{
	  maxsig=effSig[i];
	  maxindex=i;
	}
    }

  // Print out opt results
  cfresult<<std::endl;
  cfresult<<"  =========================================================="<<std::endl;
  cfresult<<" |                         Opt Result                       |"<<std::endl;
  cfresult<<"  ----------------------------------------------------------"<<std::endl;
  cfresult<<" | "<<std::setiosflags(std::ios::left)<<std::setw(15)<<"S"<<" | "<<std::setw(9)<<Form("%.0f",wSignal*effS[maxindex])<<" | "<<std::setw(13)<<"B"<<" | "<<std::setw(10)<<Form("%.0f",wBackground*effB[maxindex])<<" |"<<std::endl;
  cfresult<<"  ----------------------------------------------------------"<<std::endl;
  cfresult<<" | "<<std::setiosflags(std::ios::left)<<std::setw(15)<<"effS"<<" | "<<std::setw(9)<<effS[maxindex]<<" | "<<std::setw(13)<<"sig"<<" | "<<std::setw(10)<<Form("%.2f",effSig[maxindex])<<" |"<<std::endl;
  cfresult<<"  ----------------------------------------------------------"<<std::endl;
  cfresult<<" | "<<std::setiosflags(std::ios::left)<<std::setw(35)<<mvatype<<" | "<<std::setw(18)<<gmvaBins[maxindex]<<" |"<<std::endl;
  cfresult<<"  =========================================================="<<std::endl;
  cfresult<<std::endl;

  ofresult.close();

  TH2F* hempty = new TH2F("hempty",Form(";%s;S/sqrt(B)",mvatype.Data()),50,-1.2,1.2,10,0.,maxsig*1.4);
  sethempty(hempty);
  TGraph* gsig = new TGraph(nMVA+1,gmvaBins,effSig);
  TCanvas* csig = new TCanvas("csig","",600,600);
  hempty->Draw();
  gsig->Draw("same*");
  drawCMS(collisionsyst);  
  texPt->Draw();
  texY->Draw();
  csig->SaveAs(Form("%s_%s.pdf",outputsignificance.Data(),outputname.Data()));

}


