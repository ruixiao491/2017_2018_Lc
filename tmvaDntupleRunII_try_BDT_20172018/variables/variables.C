using namespace std;
#include "../readxml/readxml.h"
#include "../uti.h"

Bool_t isPbPb;
void variables(TString variable, TString varname, TString varlatex, Int_t varn, Float_t varmin, Float_t varmax,
               TString collisionsyst, Float_t ptMin, Float_t ptMax)
{
  setgstyle();

  ptmin = ptMin;
  ptmax = ptMax;
  colsyst = collisionsyst;
  isPbPb = (collisionsyst=="PbPb")?true:false;

  if(!isPbPb)
    {
      inputSname = inputSname_PP;
      inputBname = inputBname_PP;
      mycuts = mycuts_PP;
      mycutb = mycutb_PP;
      mycutg = mycutg_PP;
    }
  else
    {
      inputSname = inputSname_PbPb;
      inputBname = inputBname_PbPb;
      mycuts = mycuts_PbPb;
      mycutb = mycutb_PbPb;
      mycutg = mycutg_PbPb;
    }

  TFile *inputS = TFile::Open(inputSname);
  TFile *inputB = TFile::Open(inputBname);

  TTree *signal = (TTree*)inputS->Get("ntDkpi");
  signal->AddFriend("ntHlt");
  signal->AddFriend("ntHi");
  signal->AddFriend("ntSkim");
  TTree *background = (TTree*)inputB->Get("ntDkpi");
  background->AddFriend("ntHlt");
  background->AddFriend("ntHi");
  background->AddFriend("ntSkim");

  TString sels;
  if(!isPbPb) sels = Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
  else sels = Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycuts.Data(),ptmin,ptmax);
  TString selb;
  if(!isPbPb) selb = Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
  else selb = Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycutb.Data(),ptmin,ptmax);

  TH1D* hSgl = new TH1D("hSgl",Form(";%s;Probability",varlatex.Data()),varn,varmin,varmax);
  setth1d(hSgl);
  hSgl->GetXaxis()->SetLabelSize(0.045);
  hSgl->GetYaxis()->SetLabelSize(0.045);
  hSgl->GetYaxis()->SetTitleOffset(1.30);
  hSgl->GetXaxis()->SetTitleOffset(1.10);
  TH1D* hBkg = new TH1D("hBkg",Form(";%s;Probability",varlatex.Data()),varn,varmin,varmax);
  setth1d(hBkg);
  hBkg->GetXaxis()->SetLabelSize(0.045);
  hBkg->GetYaxis()->SetLabelSize(0.045);
  hBkg->GetYaxis()->SetTitleOffset(1.30);
  hBkg->GetXaxis()->SetTitleOffset(1.10);

  signal->Project("hSgl",variable,Form("%s",sels.Data()));
  background->Project("hBkg",variable,Form("%s",selb.Data()));

  cout<<hBkg->GetEntries()<<" "<<hSgl->GetEntries()<<endl;
  
  hBkg->Scale(1./hBkg->GetEntries());
  hSgl->Scale(1./hSgl->GetEntries()); 

  TCanvas* c = new TCanvas("c","",600,600);
  
  if(hBkg->GetMaximum()>hSgl->GetMaximum()) hBkg->SetMaximum(hBkg->GetMaximum()*1.2);
  else hBkg->SetMaximum(hSgl->GetMaximum()*1.2);

  hBkg->SetLineColor(kBlue+1);
  hBkg->SetFillStyle(1001);
  hBkg->SetFillColor(kBlue-9);
  hBkg->SetLineWidth(3);
  hBkg->SetStats(0);

  hSgl->SetLineColor(kRed);
  hSgl->SetFillStyle(3004);
  hSgl->SetFillColor(kRed);
  hSgl->SetLineWidth(3);
  hSgl->SetStats(0);

  hBkg->Draw();
  hSgl->Draw("same");
  
  TLegend *leg = new TLegend(0.55,0.68,0.98,0.86);
  setleg(leg);
  leg->AddEntry((TObject*)0,Form("%.0f < p_{T} < %.0f GeV",ptmin,ptmax),NULL);
  leg->AddEntry(hBkg,"Background","f");
  leg->AddEntry(hSgl,"Signal","f");
  leg->Draw("same");
  
  drawCMS(colsyst);

  c->SaveAs(Form("plots/variable_%s_%.1f_%.1f_%s.pdf",colsyst.Data(),ptmin,ptmax,varname.Data()));
}
