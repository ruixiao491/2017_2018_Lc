# MC_gen_fragment are the folders for MC request

In McM there is some modification for the kind of request evtgen+pythia8 one has to include
convertPythiaCodes = cms.untracked.bool(False) together with the 2014 evtgen dec and
pdl files. Because there is some modification in code from pythia6 to pythia8  while using PHSP
decay model. That is why it seems in 2010 decay table the generation is stuck in a event forever.

The following lines are needed to include in the gen-fragment file

    decay_table = cms.string('GeneratorInterface/EvtGenInterface/data/DECAY_2014_NOLONGLIFE.DEC'),
    operates_on_particles = cms.vint32(),
    particle_property_file = cms.FileInPath('GeneratorInterface/EvtGenInterface/data/evt_2014.pdl'),
    convertPythiaCodes = cms.untracked.bool(False),
