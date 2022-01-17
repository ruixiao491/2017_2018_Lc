
from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'non_prompt_Lc_crosssection_0404202021_y7_Bhadronweight_wholepT2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ConfFile_cfg.py'
config.JobType.inputFiles = ['/home/xiao147/private/Gen_analyzer_nonprompt_Lc/CMSSW_9_4_10/src/data/Bhadron_y7_weight_1b1events_09082019_fit.root']

#config.Data.inputDataset = '/MinBias/rxiao-whole_decay_cmstune_nonprompt-60dab7989236dc3ed6c0ea457c7b6611/USER'
config.Data.inputDataset = '/MinBias/rxiao-nonprompt_wholedecay_table_softQCD_retry-e71de57304b253fa0ff8baeacddffe6e/USER'
config.Data.inputDBS ='phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 8  
config.Data.outLFNDirBase = '/store/user/rxiao/Non_prompt_Lc_crosssection_04042021_y7_hadron_weight_wholepT2/'

config.Data.publication = False
config.Site.storageSite = 'T2_US_Purdue'  # or T2_CH_CERN
#config.Site.whitelist = ["T2_US_Wisconsin"]

#config.section_("Debug")
#config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']

