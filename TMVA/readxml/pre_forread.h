TString inputSnamepkpi;
TString inputSnamelambda1520;
TString inputSnamedelta;
TString inputSnamekstar;
TString inputBname;
TString mycut;
TString mycuts;
TString mycutb;
TString mycutg;


TString inputSname_PP_pkpi = "/scratch/halstead/x/xiao147/BDT_test/MVAfiles/merged_files/pp_6_20_MC_pkpi_merged.root";
TString inputSname_PP_kstar = "/scratch/halstead/x/xiao147/BDT_test/MVAfiles/merged_files/pp_6_20_MC_kstar.root";
TString inputSname_PP_lambda1520 = "/scratch/halstead/x/xiao147/BDT_test/MVAfiles/merged_files/pp_6_20_MC_lambda1520.root";
TString inputSname_PP_delta = "/scratch/halstead/x/xiao147/BDT_test/MVAfiles/merged_files/pp_6_20_MC_delta.root";

TString inputBname_PP = "/scratch/halstead/x/xiao147/BDT_test/MVAfiles/merged_files/pp_6_20_DATA.root";


TString mycut_PP = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&(DsvpvDistance/DsvpvDisErr)>1.&&Dchi2cl>0.05&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&DlxyBS/sqrt(DlxyBSErr)>2.5";
TString mycuts_PP = Form("(%s)&&Dgen==23333",mycut_PP.Data());
TString mycutb_PP = Form("(%s)&&((Dmass>2.215&&Dmass<2.255)||(Dmass>2.315&&Dmass<2.355))&&(HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)==1",mycut_PP.Data());
TString mycutg_PP = "((GisSignal==15||GisSignal==16)&&(Gy>-1.2&&Gy<1.2&&Gpt>4))";



TString inputSname_PbPb_pkpi="/scratch/halstead/x/xiao147/official_MC/PbPb_official_MC/pt10_realcentrality/whole_addbranch/add_BS_branches/pkpi_pt10_runlocally_whole.root";
TString inputSname_PbPb_kstar="/scratch/halstead/x/xiao147/official_MC/PbPb_official_MC/pt10_realcentrality/whole_addbranch/add_BS_branches/kstar_pt10_runlocally_whole.root";
TString inputSname_PbPb_lambda1520="/scratch/halstead/x/xiao147/official_MC/PbPb_official_MC/pt10_realcentrality/whole_addbranch/add_BS_branches/lambda1520_pt10_whole.root";
TString inputSname_PbPb_delta="/scratch/halstead/x/xiao147/official_MC/PbPb_official_MC/pt10_realcentrality/whole_addbranch/add_BS_branches/delta_pt10_whole.root";
TString inputBname_PbPb="/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/goldernjson/goldernjson_addBSbranches_AfterARC/MB2_goldernjson_whole.root";//for cen 0-100

TString mycut_PbPb = "Dy>-1.&&Dy<1.&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dalpha<0.2&&(DsvpvDistance/DsvpvDisErr)>2.&&Dchi2cl>0.05&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&hiBin<60";
TString mycuts_PbPb = Form("(%s)&&Dgen==23333",mycut_PbPb.Data());
TString mycutb_PbPb = Form("(%s)&&((Dmass>2.215&&Dmass<2.255)||(Dmass>2.315&&Dmass<2.355))&&(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1||HLT_HIL1MinimumBiasHF2AND_part4_v1||HLT_HIL1MinimumBiasHF2AND_part5_v1||HLT_HIL1MinimumBiasHF2AND_part6_v1||HLT_HIL1MinimumBiasHF2AND_part7_v1||HLT_HIL1MinimumBiasHF2AND_part8_v1||HLT_HIL1MinimumBiasHF2AND_part9_v1||HLT_HIL1MinimumBiasHF2AND_part10_v1||HLT_HIL1MinimumBiasHF2AND_part11_v1)",mycut_PbPb.Data());///this is for MB trigger. 
TString mycutg_PbPb = "((GisSignal==15||GisSignal==16)&&(Gy>-1.2&&Gy<1.2&&Gpt>4))";

