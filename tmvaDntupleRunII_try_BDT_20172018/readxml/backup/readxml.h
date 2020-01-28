#include "../uti.h"
#include "../prefilter.h"
const int NmaxFonll = 401; //fonll data points number
Float_t central[NmaxFonll],pt[NmaxFonll];
const int NEff = 100;
Double_t effS[NEff], effB[NEff],effSig[NEff],effBac[NEff];
const int NmaxVar = 10;
std::vector<TString> cuts;
std::vector<Double_t> cutval[NmaxVar];
TString varval[NmaxVar];

Int_t Nsigma = 2;
Float_t raa,nskim,lumin;
TString mvafun;
