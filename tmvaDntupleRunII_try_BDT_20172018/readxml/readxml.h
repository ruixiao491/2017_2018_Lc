#ifndef _READXML_H_
#define _READXML_H_

#include "uti.h"
#include "/home/xiao147/private/TMVA_lambdaC/CMSSW_7_5_8_patch3/src/tmvaDntupleRunII_try_BDT/myTMVA/TMVAClassification.h"
#include "cfout.h"

//const int NmaxFonll = 401; //fonll data points number
//float fcentral[NmaxFonll],fpt[NmaxFonll];
const int NEff = 100;
const int nMVA = 50;
Float_t minMVA = -1;
Float_t maxMVA = 1;
Float_t widMVA = (maxMVA-minMVA)/nMVA;
Float_t gmvaBins[nMVA+1];


TString outputresult = "results/fresult";
TString outputmvadis = "plots/cmvadistribution";
TString outputefficiency = "plots/cefficiency";
TString outputsignificance = "plots/csignificance";

#endif
