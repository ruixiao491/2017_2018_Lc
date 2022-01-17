import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('Genanalyzer'
     ,GenLabel        = cms.InputTag('genParticles')
)
