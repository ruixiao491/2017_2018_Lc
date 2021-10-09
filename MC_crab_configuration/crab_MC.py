from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'nonprompt_small_testL'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'wholedecay_cmstune_nonprompt_py_GEN_SIM.py'
config.JobType.eventsPerLumi = 50000
config.JobType.numCores = 2
#config.JobType.maxMemoryMB = 5600
config.Data.outputPrimaryDataset = 'MinBias'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 50000
NJOBS = 2000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/rxiao/nonprompt_small_testL'
config.Data.publication = True
config.Data.outputDatasetTag = 'nonprompt_wholedecay_table_softQCD_retry_testL'
#config.Data.outputDatasetTag = 'Lc_pkpi_hardQCD_pthat_pt4'

config.Site.storageSite = 'T2_US_Purdue'
config.Site.whitelist = ["T2_US_MIT"]

