
from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'nonprompt_Lc_ptshape_07312019'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ConfFile_cfg.py'

config.Data.inputDataset = '/MinBias/rxiao-whole_decay_cmstune_nonprompt-60dab7989236dc3ed6c0ea457c7b6611/USER'
config.Data.inputDBS ='phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 8  
config.Data.outLFNDirBase = '/store/user/%s/PbPb2018_rereco/Nonprompt_Lc_ptshape_withweight/' % (getUsernameFromSiteDB())

config.Data.publication = False
config.Site.storageSite = 'T2_US_Purdue'  # or T2_CH_CERN
#config.Site.whitelist = ["T2_US_Wisconsin"]

#config.section_("Debug")
#config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']

