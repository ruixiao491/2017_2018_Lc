import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageService.MessageLogger_cfi")
#process.load("Gen_analyzer.Genanalyzer.CfiFile_cfi")

#process.genParticlePlusGEANT = cms.EDProducer("GenPlusSimParticleProducer",
#		src           = cms.InputTag("g4SimHits"), # use "famosSimHits" for FAMOS
#		setStatus     = cms.int32(8),             # set status = 8 for GEANT GPs        filter        = cms.vstring("pt > 0.0"),  # just for testing (optional)
#		genParticles   = cms.InputTag("genParticles") # original genParticle list
#       genParticles   = cms.InputTag("hiGenParticles") # original genParticle list
#)


process.demo = cms.EDAnalyzer('Genanalyzer',
	  GenLabel        = cms.InputTag('genParticles')

)

#process.gp = cms.Path(process.genParticlePlusGEANT)
process.p = cms.Path(process.demo)

import FWCore.ParameterSet.VarParsing as VarParsing
ivars = VarParsing.VarParsing('analysis')
ivars.maxEvents = -1
ivars.outputFile='results.root'
ivars.inputFiles='file:/mnt/hadoop/store/user/rxiao/PYTHIA_cmstune_whole_decay_nonprompt/MinBias/whole_decay_cmstune_nonprompt/190727_165329/0000/wholedecay_cmstune_py_GEN_999.root'
ivars.parseArguments()# get and parse the command line arguments

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(ivars.inputFiles)
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(ivars.maxEvents)
)
process.TFileService = cms.Service("TFileService",
    fileName = cms.string(ivars.outputFile)
)
