float ptmin;
float ptmax;

TString inputSnamepkpi;
TString inputSnamelambda1520;
TString inputSnamedelta;
TString inputSnamekstar;
TString inputBname;
TString mycut;
TString mycuts;
TString mycutb;
TString mycutg;
TString colsyst;
/*
///pt>4
TString inputSname_PP_pkpi = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt4_MC_Dntuple/pkpi_whole.root";
TString inputSname_PP_kstar = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt4_MC_Dntuple/kstar_whole.root";
TString inputSname_PP_lambda1520 = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt4_MC_Dntuple/lambda1520_whole.root";
TString inputSname_PP_delta = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt4_MC_Dntuple/delta_whole.root";
*/

//pt>2 MC
TString inputSname_PP_pkpi = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt2_MC_Dntuple/pkpi_pt2_whole.root";
TString inputSname_PP_kstar = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt2_MC_Dntuple/k892_pt2_whole.root";
TString inputSname_PP_lambda1520 = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt2_MC_Dntuple/Lambda1520_pt2_whole.root";
TString inputSname_PP_delta = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt2_MC_Dntuple/Delta_pt2_whole.root";

/*
//pt>10 MC
TString inputSname_PP_pkpi = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt10_MC_Dntuple/pkpi_pt10_whole.root";
TString inputSname_PP_kstar = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt10_MC_Dntuple/K892_pt10_whole.root";
TString inputSname_PP_lambda1520 = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt10_MC_Dntuple/Lambda1520_pt10_whole.root";
TString inputSname_PP_delta = "/scratch/halstead/x/xiao147/official_2017_18_MC/pp_Dntuple/pp_pt10_MC_Dntuple/Delta_pt10_whole.root";
*/

TString inputBname_PP = "/scratch/halstead/x/xiao147/2017_pp_firstturn_dataproduction_0416_2019/small_background_pp_sample_whole.root";
/*
////This is for PbPb 10-20
///pt>4 MC samples
TString inputSname_PbPb_pkpi="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_full_production/MC_pt4_pthat0/pkpi_pt4_whole.root";
TString inputSname_PbPb_kstar="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_full_production/MC_pt4_pthat0/kaon892_pt4_whole.root";
TString inputSname_PbPb_lambda1520="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_full_production/MC_pt4_pthat0/Lambda1520_pt4_whole.root";
TString inputSname_PbPb_delta="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_full_production/MC_pt4_pthat0/delta1232_pt4_whole.root";
*/
/////pt>10 MC samples

TString inputSname_PbPb_pkpi="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_nocuts/pT10/pkpi_pT10_whole.root";
TString inputSname_PbPb_kstar="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_nocuts/pT10/kaon892_whole.root";
TString inputSname_PbPb_lambda1520="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_nocuts/pT10/Lambda1520_whole.root";
TString inputSname_PbPb_delta="/scratch/halstead/x/xiao147/official_2017_18_MC/PbPb_nocuts/pT10/delta_pT10_whole.root";


//TString inputBname_PbPb="/scratch/halstead/x/xiao147/2018PbPb_rereco_data_Dntuple_07022019/small_background_whole.root";
TString inputBname_PbPb="/scratch/halstead/x/xiao147/2018PbPb_rereco_data_Dntuple_07022019/TMVA_test_used_cen5090_whole.root";//cen50-90%
//TString inputBname_PbPb="/scratch/halstead/x/xiao147/2018_PbPb_transfer_from_brown_rice/for_TMVA_small_highpT_samples/PbPb2018_rereco_forlambdapkpi_part5_second_whole.root";//for high pt>30 GeV/c


TString mycut_PP = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&abs(Dtrk3Eta)<1.5&&Dchi2cl>0.05&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&DlxyBS/sqrt(DlxyBSErr)>2";
TString mycuts_PP = Form("(%s)&&(Dgen==23333&&Dgen_nonprompt==0)",mycut_PP.Data());//prompt

TString mycutb_PP = Form("(%s)&&((Dmass>2.215&&Dmass<2.255)||(Dmass>2.315&&Dmass<2.355))&&(HLT_HIZeroBias_part0_v6||HLT_HIZeroBias_part1_v6||HLT_HIZeroBias_part2_v6||HLT_HIZeroBias_part3_v6||HLT_HIZeroBias_part4_v6||HLT_HIZeroBias_part5_v6||HLT_HIZeroBias_part6_v6||HLT_HIZeroBias_part7_v6||HLT_HIZeroBias_part8_v6||HLT_HIZeroBias_part9_v6||HLT_HIZeroBias_part10_v6||HLT_HIZeroBias_part11_v6)==1",mycut_PP.Data());
TString mycutg_PP = "((GisSignal==15||GisSignal==16)&&(Gy>-1.2&&Gy<1.2&&Gpt>4))";

//TString mycut_PbPb = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dalpha<0.2&&Dchi2cl>0.05&&phfCoincFilter2Th4&&pprimaryVertexFilter&&pclusterCompatibilityFilter&&abs(PVz)<15&&hiBin<180&&(DsvpvDistance/DsvpvDisErr)>2";
TString mycut_PbPb = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dalpha<0.2&&phfCoincFilter2Th4&&pprimaryVertexFilter&&pclusterCompatibilityFilter&&abs(PVz)<15&&hiBin>=100&&hiBin<180&&Dchi2cl>0.05&&(DsvpvDistance/DsvpvDisErr)>2&&Dalpha<0.2";//30-40 GeV/c
//TString mycut_PbPb = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dalpha<0.2&&phfCoincFilter2Th4&&pprimaryVertexFilter&&pclusterCompatibilityFilter&&abs(PVz)<15&&hiBin<180&&(DsvpvDistance/DsvpvDisErr)>2&&Dalpha<0.2&&Dchi2cl>0.05";//6-20 GeV/c 0-90% centrality
//TString mycut_PbPb = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dalpha<0.2&&phfCoincFilter2Th4&&pprimaryVertexFilter&&pclusterCompatibilityFilter&&abs(PVz)<15&&(DsvpvDistance/DsvpvDisErr)>2&&Dalpha<0.2&&Dchi2cl>0.05";//for other centrality
TString mycuts_PbPb = Form("(%s)&&(Dgen==23333&&Dgen_nonprompt==0)",mycut_PbPb.Data());

TString mycutb_PbPb = Form("(%s)&&hiBin>=100&&hiBin<180&&((Dmass>2.215&&Dmass<2.255)||(Dmass>2.315&&Dmass<2.355))&&(HLT_HIMinimumBias_part0_v1||HLT_HIMinimumBias_part1_v1||HLT_HIMinimumBias_part2_v1||HLT_HIMinimumBias_part3_v1||HLT_HIMinimumBias_part4_v1||HLT_HIMinimumBias_part5_v1||HLT_HIMinimumBias_part6_v1||HLT_HIMinimumBias_part7_v1||HLT_HIMinimumBias_part8_v1||HLT_HIMinimumBias_part9_v1||HLT_HIMinimumBias_part10_v1||HLT_HIMinimumBias_part11_v1||HLT_HIMinimumBias_part12_v1||HLT_HIMinimumBias_part13_v1||HLT_HIMinimumBias_part14_v1||HLT_HIMinimumBias_part15_v1||HLT_HIMinimumBias_part16_v1||HLT_HIMinimumBias_part17_v1||HLT_HIMinimumBias_part18_v1||HLT_HIMinimumBias_part19_v1||HLT_HIMinimumBias_SinglePixelTrack_part0_v1||HLT_HIMinimumBias_SinglePixelTrack_part1_v1||HLT_HIMinimumBias_SinglePixelTrack_part2_v1||HLT_HIMinimumBias_SinglePixelTrack_part3_v1||HLT_HIMinimumBias_SinglePixelTrack_part4_v1||HLT_HIMinimumBias_SinglePixelTrack_part5_v1||HLT_HIMinimumBias_SinglePixelTrack_part6_v1||HLT_HIMinimumBias_SinglePixelTrack_part7_v1||HLT_HIMinimumBias_SinglePixelTrack_part8_v1||HLT_HIMinimumBias_SinglePixelTrack_part9_v1||HLT_HIMinimumBias_SinglePixelTrack_part10_v1||HLT_HIMinimumBias_SinglePixelTrack_part11_v1||HLT_HIMinimumBias_SinglePixelTrack_part12_v1||HLT_HIMinimumBias_SinglePixelTrack_part13_v1||HLT_HIMinimumBias_SinglePixelTrack_part14_v1||HLT_HIMinimumBias_SinglePixelTrack_part15_v1||HLT_HIMinimumBias_SinglePixelTrack_part16_v1||HLT_HIMinimumBias_SinglePixelTrack_part17_v1||HLT_HIMinimumBias_SinglePixelTrack_part18_v1||HLT_HIMinimumBias_SinglePixelTrack_part19_v1)",mycut_PbPb.Data());///this is for MB trigger. 
TString mycutg_PbPb = "((GisSignal==15||GisSignal==16)&&(Gy>-1.2&&Gy<1.2&&Gpt>10))";

