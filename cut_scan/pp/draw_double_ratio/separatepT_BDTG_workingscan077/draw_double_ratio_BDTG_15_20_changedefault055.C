#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
#include <TF1.h>

void draw_double_ratio_BDTG_15_20_changedefault055(){
TFile *f_data1 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_90.root");
TFile *f_data2 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_80.root");
TFile *f_data3 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_70.root");
TFile *f_data4 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_65.root");
TFile *f_data5 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_60.root");
TFile *f_data6 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_55.root");
TFile *f_data7 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_50.root");
TFile *f_data8 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_45.root");
TFile *f_data9 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_40.root");
TFile *f_data10 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_35.root");
TFile *f_data11 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_30.root");
TFile *f_data12 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_25.root");
TFile *f_data13 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_20.root");
TFile *f_data14 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_15.root");
TFile *f_data15 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_minus_10.root");
TFile *f_data16 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_0.root");
TFile *f_data17 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_10.root");
TFile *f_data18 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_20.root");
TFile *f_data19 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_25.root");
TFile *f_data20 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_30.root");
TFile *f_data21 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_35.root");
TFile *f_data22 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_40.root");
TFile *f_data23 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_45.root");
TFile *f_data24 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_50.root");
TFile *f_data25 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_55.root");
TFile *f_data26 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_60.root");
TFile *f_data27 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_65.root");
TFile *f_data28 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_70.root");
TFile *f_data29 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_80.root");
//TFile *f_data_reference = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/signal_fit_firstturn_02062020/ROOT/default_fit/pol3_2gaus/working_scan_BDTG077/pp_15_20_whole_DCA_withhitscut_055.root");
TFile *f_data_reference = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/cut_scan_data_fit/ROOT/data_fit/separate_pT_BDTG_3_100_workingscan_077/15_20_changedefault055/BDTG_15_20_value_0_55.root");


TFile *f_MC_1 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_90_whole.root");
TFile *f_MC_2 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_80_whole.root");
TFile *f_MC_3 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_70_whole.root");
TFile *f_MC_4 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_65_whole.root");
TFile *f_MC_5 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_60_whole.root");
TFile *f_MC_6 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_55_whole.root");
TFile *f_MC_7 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_50_whole.root");
TFile *f_MC_8 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_45_whole.root");
TFile *f_MC_9 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_40_whole.root");
TFile *f_MC_10 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_35_whole.root");
TFile *f_MC_11 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_30_whole.root");
TFile *f_MC_12 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_25_whole.root");
TFile *f_MC_13 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_20_whole.root");
TFile *f_MC_14 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_15_whole.root");
TFile *f_MC_15 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_minus_10_whole.root");
TFile *f_MC_16 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_0_whole.root");
TFile *f_MC_17 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_10_whole.root");
TFile *f_MC_18 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_20_whole.root");
TFile *f_MC_19 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_25_whole.root");
TFile *f_MC_20 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_30_whole.root");
TFile *f_MC_21 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_35_whole.root");
TFile *f_MC_22 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_40_whole.root");
TFile *f_MC_23 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_45_whole.root");
TFile *f_MC_24 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_50_whole.root");
TFile *f_MC_25 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_55_whole.root");
TFile *f_MC_26 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_60_whole.root");
TFile *f_MC_27 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_65_whole.root");
TFile *f_MC_28 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_70_whole.root");
TFile *f_MC_29 = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_80_whole.root");
TFile *f_MC_reference = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/MC_cutscan/ROOT/MC_massplots_BDTG_separatepT_workingscan_077/inclusive_massplots/with_manually_dls_alpha_weight/weighted/pT10_MC_1020_combine/BDTG_15_20_value_0_55_whole.root");

TH1F *h_data_1 = (TH1F*)f_data1->Get("h_output");
TH1F *h_data_2 = (TH1F*)f_data2->Get("h_output");
TH1F *h_data_3 = (TH1F*)f_data3->Get("h_output");
TH1F *h_data_4 = (TH1F*)f_data4->Get("h_output");
TH1F *h_data_5 = (TH1F*)f_data5->Get("h_output");
TH1F *h_data_6 = (TH1F*)f_data6->Get("h_output");
TH1F *h_data_7 = (TH1F*)f_data7->Get("h_output");
TH1F *h_data_8 = (TH1F*)f_data8->Get("h_output");
TH1F *h_data_9 = (TH1F*)f_data9->Get("h_output");
TH1F *h_data_10 = (TH1F*)f_data10->Get("h_output");
TH1F *h_data_11 = (TH1F*)f_data11->Get("h_output");
TH1F *h_data_12 = (TH1F*)f_data12->Get("h_output");
TH1F *h_data_13 = (TH1F*)f_data13->Get("h_output");
TH1F *h_data_14 = (TH1F*)f_data14->Get("h_output");
TH1F *h_data_15 = (TH1F*)f_data15->Get("h_output");
TH1F *h_data_16 = (TH1F*)f_data16->Get("h_output");
TH1F *h_data_17 = (TH1F*)f_data17->Get("h_output");
TH1F *h_data_18 = (TH1F*)f_data18->Get("h_output");
TH1F *h_data_19 = (TH1F*)f_data19->Get("h_output");
TH1F *h_data_20 = (TH1F*)f_data20->Get("h_output");
TH1F *h_data_21 = (TH1F*)f_data21->Get("h_output");
TH1F *h_data_22 = (TH1F*)f_data22->Get("h_output");
TH1F *h_data_23 = (TH1F*)f_data23->Get("h_output");
TH1F *h_data_24 = (TH1F*)f_data24->Get("h_output");
TH1F *h_data_25 = (TH1F*)f_data25->Get("h_output");
TH1F *h_data_26 = (TH1F*)f_data26->Get("h_output");
TH1F *h_data_27 = (TH1F*)f_data27->Get("h_output");
TH1F *h_data_28 = (TH1F*)f_data28->Get("h_output");
TH1F *h_data_29 = (TH1F*)f_data29->Get("h_output");
TH1F *h_data_reference = (TH1F*) f_data_reference->Get("h_output");

TH1F *h_MC_1 = (TH1F*) f_MC_1->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_2 = (TH1F*) f_MC_2->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_3 = (TH1F*) f_MC_3->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_4 = (TH1F*) f_MC_4->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_5 = (TH1F*) f_MC_5->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_6 = (TH1F*) f_MC_6->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_7 = (TH1F*) f_MC_7->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_8 = (TH1F*) f_MC_8->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_9 = (TH1F*) f_MC_9->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_10 = (TH1F*) f_MC_10->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_11 = (TH1F*) f_MC_11->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_12 = (TH1F*) f_MC_12->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_13 = (TH1F*) f_MC_13->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_14 = (TH1F*) f_MC_14->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_15 = (TH1F*) f_MC_15->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_16 = (TH1F*) f_MC_16->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_17 = (TH1F*) f_MC_17->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_18 = (TH1F*) f_MC_18->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_19 = (TH1F*) f_MC_19->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_20 = (TH1F*) f_MC_20->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_21 = (TH1F*) f_MC_21->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_22 = (TH1F*) f_MC_22->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_23 = (TH1F*) f_MC_23->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_24 = (TH1F*) f_MC_24->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_25 = (TH1F*) f_MC_25->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_26 = (TH1F*) f_MC_26->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_27 = (TH1F*) f_MC_27->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_28 = (TH1F*) f_MC_28->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_29 = (TH1F*) f_MC_29->Get("h_whole_withcuts_prompt_sig");
TH1F *h_MC_reference = (TH1F*) f_MC_reference->Get("h_whole_withcuts_prompt_sig");

double BDTG[29];
double ratio_data[29]={h_data_1->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_2->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_3->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_4->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_5->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_6->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_7->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_8->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_9->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_10->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_11->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_12->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_13->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_14->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_15->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_16->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_17->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_18->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_19->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_20->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_21->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_22->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_23->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_24->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_25->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_26->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_27->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_28->GetBinContent(1)/(h_data_reference->GetBinContent(1)),h_data_29->GetBinContent(1)/(h_data_reference->GetBinContent(1))};
double ratio_MC[29]={h_MC_1->GetEntries()/h_MC_reference->GetEntries(),h_MC_2->GetEntries()/h_MC_reference->GetEntries(),h_MC_3->GetEntries()/h_MC_reference->GetEntries(),h_MC_4->GetEntries()/h_MC_reference->GetEntries(),h_MC_5->GetEntries()/h_MC_reference->GetEntries(),h_MC_6->GetEntries()/h_MC_reference->GetEntries(),h_MC_7->GetEntries()/h_MC_reference->GetEntries(),h_MC_8->GetEntries()/h_MC_reference->GetEntries(),h_MC_9->GetEntries()/h_MC_reference->GetEntries(),h_MC_10->GetEntries()/h_MC_reference->GetEntries(),h_MC_11->GetEntries()/h_MC_reference->GetEntries(),h_MC_12->GetEntries()/h_MC_reference->GetEntries(),h_MC_13->GetEntries()/h_MC_reference->GetEntries(),h_MC_14->GetEntries()/h_MC_reference->GetEntries(),h_MC_15->GetEntries()/h_MC_reference->GetEntries(),h_MC_16->GetEntries()/h_MC_reference->GetEntries(),h_MC_17->GetEntries()/h_MC_reference->GetEntries(),h_MC_18->GetEntries()/h_MC_reference->GetEntries(),h_MC_19->GetEntries()/h_MC_reference->GetEntries(),h_MC_20->GetEntries()/h_MC_reference->GetEntries(),h_MC_21->GetEntries()/h_MC_reference->GetEntries(),h_MC_22->GetEntries()/h_MC_reference->GetEntries(),h_MC_23->GetEntries()/h_MC_reference->GetEntries(),h_MC_24->GetEntries()/h_MC_reference->GetEntries(),h_MC_25->GetEntries()/h_MC_reference->GetEntries(),h_MC_26->GetEntries()/h_MC_reference->GetEntries(),h_MC_27->GetEntries()/h_MC_reference->GetEntries(),h_MC_28->GetEntries()/h_MC_reference->GetEntries(),h_MC_29->GetEntries()/h_MC_reference->GetEntries()};

double MC_err[29];
double zero[29];
double y[29];
for (int i=0;i<29;i++)
{
	y[i]=ratio_data[i]/ratio_MC[i];
	zero[i]=0;
	MC_err[i]=sqrt(ratio_MC[i]*h_MC_reference->GetEntries());
	//cout<<ratio_data[i]<<"       "<<ratio_MC[i]<<endl;
}
double x[29]={-0.9,-0.8,-0.7,-0.65,-0.6,-0.55,-0.5,-0.45,-0.4,-0.35,-0.3,-0.25,-0.2,-0.15,-0.1,0,0.1,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.8};
double err_data[29]={h_data_1->GetBinError(1),h_data_2->GetBinError(1),h_data_3->GetBinError(1),h_data_4->GetBinError(1),h_data_5->GetBinError(1),h_data_6->GetBinError(1),h_data_7->GetBinError(1),h_data_8->GetBinError(1),h_data_9->GetBinError(1),h_data_10->GetBinError(1),h_data_11->GetBinError(1),h_data_12->GetBinError(1),h_data_13->GetBinError(1),h_data_14->GetBinError(1),h_data_15->GetBinError(1),h_data_16->GetBinError(1),h_data_17->GetBinError(1),h_data_18->GetBinError(1),h_data_19->GetBinError(1),h_data_20->GetBinError(1),h_data_21->GetBinError(1),h_data_22->GetBinError(1),h_data_23->GetBinError(1),h_data_24->GetBinError(1),h_data_25->GetBinError(1),h_data_26->GetBinError(1),h_data_27->GetBinError(1),h_data_28->GetBinError(1),h_data_29->GetBinError(1)};
double rela_data[29];
double rou_data;
double rou_MC;
double numerator_err[29];
double denom_err[29];
double dou_ratio_err[29];
double rela_data_ref = h_data_reference->GetBinError(1)/h_data_reference->GetBinContent(1);
for (int i=0;i<29;i++)
{
	rela_data[i]=err_data[i]/(ratio_data[i]*h_data_reference->GetBinContent(1));	
    if (ratio_data[i]<1)
	{
		rou_data = err_data[i];
		rou_MC = MC_err[i];		

	}
	else
	{
		rou_data = h_data_reference->GetBinError(1);		
		rou_MC = sqrt(h_MC_reference->GetBinContent(1));
	}
	numerator_err[i]=abs(rela_data[i]*rela_data[i]+rela_data_ref*rela_data_ref-2*rou_data*rou_data/(ratio_data[i]*h_data_reference->GetBinContent(1)*h_data_reference->GetBinContent(1)));
	denom_err[i]=abs((1/MC_err[i])*(1/MC_err[i])+1/h_MC_reference->GetEntries()-2*rou_MC*rou_MC/(ratio_MC[i]*h_MC_reference->GetEntries()*h_MC_reference->GetEntries()));
	dou_ratio_err[i]=sqrt(numerator_err[i]+denom_err[i]);
}

TCanvas *c1 = new TCanvas("c1","c1",600,600);
c1->SetLeftMargin(0.12);
c1->SetRightMargin(0.05);
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);

TH1F *h_empty = new TH1F("h_empty","h_empty",100,-1,1);
h_empty->SetAxisRange(0,2,"Y");
h_empty->GetXaxis()->CenterTitle();
h_empty->GetYaxis()->CenterTitle();
h_empty->GetXaxis()->SetTitleOffset(1.0);
h_empty->GetYaxis()->SetTitleOffset(1.4);
h_empty->GetXaxis()->SetLabelOffset(0.007);
h_empty->GetYaxis()->SetLabelOffset(0.007);
h_empty->GetXaxis()->SetTitleSize(0.04);
h_empty->GetYaxis()->SetTitleSize(0.04);
h_empty->GetXaxis()->SetTitleFont(42);
h_empty->GetYaxis()->SetTitleFont(42);
h_empty->GetXaxis()->SetLabelFont(42);
h_empty->GetYaxis()->SetLabelFont(42);
h_empty->GetXaxis()->SetLabelSize(0.033);
h_empty->GetYaxis()->SetLabelSize(0.033);
h_empty->SetAxisRange(0,2.5,"Y");
h_empty->SetMarkerStyle(20);
h_empty->SetMarkerSize(1.5);
h_empty->GetXaxis()->SetTitle("BDTG value");
h_empty->GetYaxis()->SetTitle("(Yield_{varied cuts}^{Data}/Yield_{used cuts}^{Data})/(Yield_{varied cuts}^{MC}/Yield_{used cuts}^{MC})");
h_empty->Draw();



TGraphErrors *graph1 = new TGraphErrors(29,x,y,zero,dou_ratio_err);
//graph1->GetXaxis()->SetRangeUser(-2,1);
//graph1->GetYaxis()->SetRangeUser(0,2);

graph1->Draw("same");

//TF1 * f1= new TF1("f1","[0]*(x-0.77)+1",-1,1);
TF1 * f1= new TF1("f1","[0]*(x-0.55)+1",-1,1);
TH1F *h_uncer = new TH1F("h_uncer","h_uncer",10,0,6);
h_uncer->Sumw2();


TLine *l1 =  new TLine(-1,1,1,1);
l1->SetLineStyle(9);
l1->SetLineColor(8);
l1->SetLineWidth(3);
l1->Draw("same");

TLine *l2 =  new TLine(0.55,0, 0.55,1);
l2->SetLineStyle(9);
l2->SetLineColor(8);
l2->SetLineWidth(3);
l2->Draw("same");

graph1->Fit(f1,"I","",-1,1);
cout<<f1->Eval(-1)<<endl;

TLatex* tex;
tex = new TLatex(0.18,0.85,Form("15 < p_{T} < 20 GeV/c"));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.18,0.78,"|y| < 1");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex =  new TLatex(0.75,0.85,"#font[61]{#Lambda_{C}^{+} + #Lambda_{C}^{#font[122]{\55}}}");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.055);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.12,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.61,0.93, "#scale[0.8]{252 nb^{-1} (5.02 TeV pp)}");//pp

TLatex Tl2;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05*0.75);
Tl.SetTextFont(42);
Tl.DrawLatex(0.23,0.93, "#font[52]{Preliminary}");


cout<<"uncertainty"<<abs(f1->Eval(-1)-1)<<endl;
h_uncer->SetBinContent(1,abs(f1->Eval(-1)-1));
/*
c1->SaveAs("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/draw_double_ratio/ROOT/separatepT_BDTG_workingscan077/pp_15_20_cutscan_BDTG_withpTweight.pdf");
TFile *result = TFile::Open("/home/xiao147/private/2017_pp_Lc_speedup_version_2_toDtuple/CMSSW_9_4_10/src/Bfinder/Bfinder/Dntuple/analysis_firstturn_04072020/cut_scan/draw_double_ratio/ROOT/separatepT_BDTG_workingscan077/pp_15_20_cutscan_BDTG_withpTweight.root","recreate");
h_uncer->Write();
graph1->Write();
f1->Write();
result->Close();
*/


}
