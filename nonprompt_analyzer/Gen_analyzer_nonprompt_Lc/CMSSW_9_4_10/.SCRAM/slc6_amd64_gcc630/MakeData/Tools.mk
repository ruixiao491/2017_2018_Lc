ALL_TOOLS      += alpgen

ALL_TOOLS      += blackhat
blackhat_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/blackhat/0.9.9-fmblme/include
blackhat_EX_LIB := Ampl_eval BG BH BHcore CutPart Cut_wCI Cuteval Integrals Interface OLA RatPart Rateval Spinors assembly ratext
blackhat_EX_USE := qd

ALL_TOOLS      += boost
boost_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/boost/1.63.0-fmblme/include
boost_EX_LIB := boost_thread boost_signals boost_date_time
boost_EX_USE := root_cxxdefaults sockets
boost_EX_FLAGS_CPPDEFINES  := -DBOOST_SPIRIT_THREADSAFE -DPHOENIX_THREADSAFE
boost_EX_FLAGS_CXXFLAGS  := -Wno-error=unused-variable

ALL_TOOLS      += boost_chrono
boost_chrono_EX_LIB := boost_chrono
boost_chrono_EX_USE := boost_system boost

ALL_TOOLS      += boost_filesystem
boost_filesystem_EX_LIB := boost_filesystem
boost_filesystem_EX_USE := boost_system boost

ALL_TOOLS      += boost_header
boost_header_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/boost/1.63.0-fmblme/include
boost_header_EX_USE := root_cxxdefaults

ALL_TOOLS      += boost_iostreams
boost_iostreams_EX_USE := boost

ALL_TOOLS      += boost_program_options
boost_program_options_EX_LIB := boost_program_options
boost_program_options_EX_USE := boost

ALL_TOOLS      += boost_python
boost_python_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/boost/1.63.0-fmblme/include
boost_python_EX_LIB := boost_python
boost_python_EX_USE := root_cxxdefaults python

ALL_TOOLS      += boost_regex
boost_regex_EX_LIB := boost_regex
boost_regex_EX_USE := boost

ALL_TOOLS      += boost_serialization
boost_serialization_EX_LIB := boost_serialization
boost_serialization_EX_USE := boost

ALL_TOOLS      += boost_signals
boost_signals_EX_LIB := boost_signals
boost_signals_EX_USE := boost

ALL_TOOLS      += boost_system
boost_system_EX_LIB := boost_system
boost_system_EX_USE := boost

ALL_TOOLS      += boost_test
boost_test_EX_LIB := boost_unit_test_framework
boost_test_EX_USE := boost

ALL_TOOLS      += bz2lib
bz2lib_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/bz2lib/1.0.6/include
bz2lib_EX_LIB := bz2
bz2lib_EX_USE := root_cxxdefaults

ALL_TOOLS      += cascade
cascade_EX_LIB := cascade_merged
cascade_EX_USE := f77compiler cascade_headers

ALL_TOOLS      += cascade_headers
cascade_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cascade/2.2.04-fmblme/include
cascade_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += castor
castor_EX_LIB := shift castorrfio castorclient castorcommon
castor_EX_USE := castor_header libuuid

ALL_TOOLS      += castor_header
castor_header_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/castor/2.1.13.9/include /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/castor/2.1.13.9/include/shift
castor_header_EX_USE := root_cxxdefaults

ALL_TOOLS      += ccache-ccompiler
ccache-ccompiler_EX_USE := gcc-ccompiler

ALL_TOOLS      += ccache-cxxcompiler
ccache-cxxcompiler_EX_USE := gcc-cxxcompiler

ALL_TOOLS      += ccache-f77compiler
ccache-f77compiler_EX_USE := gcc-f77compiler

ALL_TOOLS      += cgal
cgal_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cgal/4.2-fmblme/include
cgal_EX_LIB := CGAL_Core CGAL
cgal_EX_USE := root_cxxdefaults zlib boost_system gmp mpfr

ALL_TOOLS      += cgalimageio
cgalimageio_EX_LIB := CGAL_ImageIO
cgalimageio_EX_USE := zlib boost_system cgal

ALL_TOOLS      += charybdis
charybdis_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/charybdis/1.003-fmblme/include
charybdis_EX_LIB := charybdis
charybdis_EX_USE := root_cxxdefaults f77compiler herwig pythia6

ALL_TOOLS      += classlib
classlib_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/classlib/3.1.3-oenich/include
classlib_EX_LIB := classlib
classlib_EX_USE := zlib bz2lib pcre openssl root_cxxdefaults
classlib_EX_FLAGS_CPPDEFINES  := -D__STDC_LIMIT_MACROS -D__STDC_FORMAT_MACROS

ALL_TOOLS      += clhep
clhep_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/clhep/2.3.4.2-fmblme/include
clhep_EX_LIB := CLHEP
clhep_EX_USE := root_cxxdefaults
clhep_EX_FLAGS_CXXFLAGS  := -Wno-error=unused-variable

ALL_TOOLS      += clhepheader
clhepheader_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/clhep/2.3.4.2-fmblme/include
clhepheader_EX_USE := root_cxxdefaults
clhepheader_EX_FLAGS_CXXFLAGS  := -Wno-error=unused-variable

ALL_TOOLS      += cmsswdata
cmsswdata_EX_FLAGS_CMSSW_DATA_PACKAGE  := CalibCalorimetry/CaloMiscalibTools=V01-00-00 CalibCalorimetry/EcalTrivialCondModules=V00-01-00 CalibTracker/SiPixelESProducers=V02-00-00 CalibTracker/SiStripDCS=V01-00-00 Calibration/Tools=V01-00-00 CondFormats/JetMETObjects=V01-00-03 Configuration/Generator=V01-00-01 DQM/PhysicsHWW=V01-00-00 DQM/SiStripMonitorClient=V01-00-00 DataFormats/PatCandidates=V01-00-01 DetectorDescription/Schema=V02-02-01 EgammaAnalysis/ElectronTools=V00-01-03 EventFilter/L1TRawToDigi=V01-00-00 FastSimulation/MaterialEffects=V05-00-00 FastSimulation/TrackingRecHitProducer=V01-00-02 Fireworks/Geometry=V07-05-04 GeneratorInterface/EvtGenInterface=V02-00-08 GeneratorInterface/ReggeGribovPartonMCInterface=V00-00-02 HLTrigger/JetMET=V01-00-00 L1Trigger/L1TCalorimeter=V01-00-22 L1Trigger/L1TGlobal=V00-00-07 L1Trigger/L1THGCal=V01-00-04 L1Trigger/L1TMuon=V01-01-00 L1Trigger/RPCTrigger=V00-15-00 MagneticField/Interpolation=V01-00-02 PhysicsTools/NanoAOD=V01-00-03 RecoBTag/CTagging=V01-00-03 RecoBTag/Combined=V01-00-12 RecoBTag/SecondaryVertex=V02-00-04 RecoBTag/SoftLepton=V01-00-01 RecoEgamma/ElectronIdentification=V01-00-08 RecoEgamma/PhotonIdentification=V01-00-05 RecoHI/HiJetAlgos=V01-00-01 RecoJets/JetProducers=V05-10-20 RecoLocalCalo/EcalDeadChannelRecoveryAlgos=V01-00-00 RecoMET/METPUSubtraction=V01-00-03 RecoMuon/MuonIdentification=V01-12-02 RecoParticleFlow/PFBlockProducer=V02-04-02 RecoParticleFlow/PFProducer=V15-00-00 RecoParticleFlow/PFTracking=V13-01-00 SLHCUpgradeSimulations/Geometry=V01-00-06 SimG4CMS/Calo=V03-01-00 SimG4CMS/Forward=V02-03-18 SimTracker/SiStripDigitizer=V01-00-00 SimTransport/HectorProducer=V01-00-01 Validation/Geometry=V00-07-00

ALL_TOOLS      += coral
ALL_SCRAM_PROJECTS += coral
coral_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/coral/CORAL_2_3_21-fmblme4/include/LCG
coral_EX_USE := root_cxxdefaults
coral_ORDER := 98000

ALL_TOOLS      += cppunit
cppunit_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cppunit/1.12.1/include
cppunit_EX_LIB := cppunit
cppunit_EX_USE := root_cxxdefaults sockets

ALL_TOOLS      += csctrackfinderemulation
csctrackfinderemulation_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/CSCTrackFinderEmulation/1.2/include
csctrackfinderemulation_EX_LIB := CSCTrackFinderEmulation

ALL_TOOLS      += cuda-cublas
cuda-cublas_EX_LIB := cublas cublas_device
cuda-cublas_EX_USE := cuda
cuda-cublas_EX_FLAGS_CUDA_LDFLAGS  := -lcublas_device

ALL_TOOLS      += cuda-cufft
cuda-cufft_EX_LIB := cufft cufftw
cuda-cufft_EX_USE := cuda

ALL_TOOLS      += cuda-curand
cuda-curand_EX_LIB := curand
cuda-curand_EX_USE := cuda

ALL_TOOLS      += cuda-cusolver
cuda-cusolver_EX_LIB := cusolver
cuda-cusolver_EX_USE := cuda

ALL_TOOLS      += cuda-cusparse
cuda-cusparse_EX_LIB := cusparse
cuda-cusparse_EX_USE := cuda

ALL_TOOLS      += cuda-npp
cuda-npp_EX_LIB := nppial nppicc nppicom nppidei nppif nppig nppim nppist nppisu nppitc npps nppc
cuda-npp_EX_USE := cuda

ALL_TOOLS      += cuda-nvgraph
cuda-nvgraph_EX_LIB := nvgraph
cuda-nvgraph_EX_USE := cuda

ALL_TOOLS      += cuda-nvml
cuda-nvml_EX_LIB := nvidia-ml
cuda-nvml_EX_USE := cuda

ALL_TOOLS      += cuda-nvrtc
cuda-nvrtc_EX_LIB := nvrtc
cuda-nvrtc_EX_USE := cuda

ALL_TOOLS      += cuda-stubs
cuda-stubs_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cuda/9.0.176-fmblme2/include
cuda-stubs_EX_LIB := cuda
cuda-stubs_EX_LIBDIR := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cuda/9.0.176-fmblme2/lib64/stubs
cuda-stubs_EX_FLAGS_SKIP_TOOL_SYMLINKS  := 1

ALL_TOOLS      += cuda
cuda_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cuda/9.0.176-fmblme2/include
cuda_EX_LIB := cudart cudadevrt nvToolsExt
cuda_EX_USE := cuda-stubs
cuda_EX_FLAGS_CUDA_LDFLAGS  := -L$(CUDA_BASE)/lib64
cuda_EX_FLAGS_CUDA_FLAGS  := -gencode arch=compute_35,code=sm_35 -gencode arch=compute_50,code=sm_50 -gencode arch=compute_61,code=sm_61

ALL_TOOLS      += curl
curl_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/curl/7.52.1/include
curl_EX_LIB := curl
curl_EX_USE := root_cxxdefaults

ALL_TOOLS      += cvs2git

ALL_TOOLS      += das_client
das_client_EX_USE := python

ALL_TOOLS      += davix
davix_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/davix/0.6.4-fmblme/include/davix
davix_EX_LIB := davix
davix_EX_USE := boost_system openssl libxml2

ALL_TOOLS      += db6
db6_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/db6/6.0.30/include
db6_EX_LIB := db

ALL_TOOLS      += dbs-client

ALL_TOOLS      += dcap
dcap_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/dcap/2.47.8-oenich/include
dcap_EX_LIB := dcap
dcap_EX_USE := root_cxxdefaults

ALL_TOOLS      += distcc-ccompiler
distcc-ccompiler_EX_USE := gcc-ccompiler

ALL_TOOLS      += distcc-cxxcompiler
distcc-cxxcompiler_EX_USE := gcc-cxxcompiler

ALL_TOOLS      += distcc-f77compiler
distcc-f77compiler_EX_USE := gcc-f77compiler

ALL_TOOLS      += dmtcp

ALL_TOOLS      += doxygen

ALL_TOOLS      += dpm
dpm_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/dpm/1.8.0.1/include
dpm_EX_LIB := dpm
dpm_EX_LIBDIR := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/dpm/1.8.0.1/lib
dpm_EX_USE := root_cxxdefaults

ALL_TOOLS      += eigen
eigen_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/eigen/c7dc0a897676/include/eigen3
eigen_EX_FLAGS_CPPDEFINES  := -DEIGEN_DONT_PARALLELIZE

ALL_TOOLS      += evtgen
evtgen_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/evtgen/1.6.0-fmblme2/include
evtgen_EX_LIB := EvtGen EvtGenExternal
evtgen_EX_USE := hepmc pythia8 tauolapp photospp

ALL_TOOLS      += expat
expat_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/expat/2.1.0/include
expat_EX_LIB := expat
expat_EX_USE := root_cxxdefaults

ALL_TOOLS      += fastjet-contrib-archive
fastjet-contrib-archive_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fastjet-contrib/1.026ECF/include
fastjet-contrib-archive_EX_LIB := EnergyCorrelator GenericSubtractor JetCleanser JetFFMoments Nsubjettiness ScJet SubjetCounting VariableR

ALL_TOOLS      += fastjet-contrib
fastjet-contrib_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fastjet-contrib/1.026ECF/include
fastjet-contrib_EX_LIB := fastjetcontribfragile

ALL_TOOLS      += fastjet
fastjet_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fastjet/3.1.0/include
fastjet_EX_LIB := fastjetplugins fastjettools siscone siscone_spherical fastjet
fastjet_EX_USE := root_cxxdefaults

ALL_TOOLS      += fftjet
fftjet_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fftjet/1.5.0/include
fftjet_EX_LIB := fftjet
fftjet_EX_USE := root_cxxdefaults

ALL_TOOLS      += fftw3
fftw3_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fftw3/3.3.2/include
fftw3_EX_LIB := fftw3
fftw3_EX_USE := root_cxxdefaults

ALL_TOOLS      += freetype
freetype_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/freetype/2.5.3-oenich/include
freetype_EX_LIB := freetype-cms
freetype_EX_USE := root_cxxdefaults

ALL_TOOLS      += frontier_client
frontier_client_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/frontier_client/2.8.20-fmblme/include
frontier_client_EX_LIB := frontier_client
frontier_client_EX_USE := root_cxxdefaults zlib openssl expat python

ALL_TOOLS      += gbl
gbl_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/gbl/V02-01-03-mmelna/include
gbl_EX_LIB := GBL
gbl_EX_USE := eigen

ALL_TOOLS      += gcc-atomic
gcc-atomic_EX_LIB := atomic

ALL_TOOLS      += gcc-ccompiler
gcc-ccompiler_EX_FLAGS_CFLAGS  := -O2 -pthread
gcc-ccompiler_EX_FLAGS_CSHAREDOBJECTFLAGS  := -fPIC

ALL_TOOLS      += gcc-cxxcompiler
gcc-cxxcompiler_EX_FLAGS_CXXSHAREDFLAGS  := -shared -Wl,-E
gcc-cxxcompiler_EX_FLAGS_CXXSHAREDOBJECTFLAGS  := -fPIC
gcc-cxxcompiler_EX_FLAGS_LDFLAGS  := -Wl,-E -Wl,--hash-style=gnu
gcc-cxxcompiler_EX_FLAGS_CPPDEFINES  := -DGNU_GCC -D_GNU_SOURCE
gcc-cxxcompiler_EX_FLAGS_CXXFLAGS  := -O2 -pthread -pipe -Werror=main -Werror=pointer-arith -Werror=overlength-strings -Wno-vla -Werror=overflow -std=c++1z -ftree-vectorize -Wstrict-overflow -Werror=array-bounds -Werror=format-contains-nul -Werror=type-limits -fvisibility-inlines-hidden -fno-math-errno --param vect-max-version-for-alias-checks=50 -Xassembler --compress-debug-sections -fno-crossjumping -msse3 -felide-constructors -fmessage-length=0 -Wall -Wno-non-template-friend -Wno-long-long -Wreturn-type -Wunused -Wparentheses -Wno-deprecated -Werror=return-type -Werror=missing-braces -Werror=unused-value -Werror=address -Werror=format -Werror=sign-compare -Werror=write-strings -Werror=delete-non-virtual-dtor -Werror=maybe-uninitialized -Werror=strict-aliasing -Werror=narrowing -Werror=uninitialized -Werror=unused-but-set-variable -Werror=reorder -Werror=unused-variable -Werror=conversion-null -Werror=return-local-addr -Werror=switch -fdiagnostics-show-option -Wno-unused-local-typedefs -Wno-attributes -Wno-psabi
gcc-cxxcompiler_EX_FLAGS_LD_UNIT  := -r -z muldefs

ALL_TOOLS      += gcc-f77compiler
gcc-f77compiler_EX_LIB := gfortran m
gcc-f77compiler_EX_FLAGS_FFLAGS  := -fno-second-underscore -Wunused -Wuninitialized -O2 -cpp
gcc-f77compiler_EX_FLAGS_FOPTIMISEDFLAGS  := -O2
gcc-f77compiler_EX_FLAGS_FSHAREDOBJECTFLAGS  := -fPIC

ALL_TOOLS      += gdb

ALL_TOOLS      += gdbm
gdbm_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/gdbm/1.10/include
gdbm_EX_LIB := gdbm
gdbm_EX_USE := root_cxxdefaults

ALL_TOOLS      += geant4-parfullcms

ALL_TOOLS      += geant4
geant4_EX_USE := geant4core geant4vis xerces-c

ALL_TOOLS      += geant4core
geant4core_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/geant4/10.02.p02-elfike/include/Geant4
geant4core_EX_LIB := G4digits_hits G4error_propagation G4event G4geometry G4global G4graphics_reps G4intercoms G4interfaces G4materials G4parmodels G4particles G4persistency G4physicslists G4processes G4readout G4run G4tracking G4track G4analysis
geant4core_EX_USE := clhep root_cxxdefaults
geant4core_EX_FLAGS_CXXFLAGS  := -DG4MULTITHREADED -DG4USE_STD11 -ftls-model=global-dynamic -pthread
geant4core_EX_FLAGS_CPPDEFINES  := -DGNU_GCC -DG4V9

ALL_TOOLS      += geant4data

ALL_TOOLS      += geant4static
geant4static_EX_LIB := geant4-static
geant4static_EX_USE := clhep xerces-c
geant4static_EX_FLAGS_CXXFLAGS  := -DG4MULTITHREADED -DG4USE_STD11 -ftls-model=global-dynamic -pthread

ALL_TOOLS      += geant4vis
geant4vis_EX_LIB := G4FR G4modeling G4RayTracer G4Tree G4visHepRep G4vis_management G4visXXX G4VRML G4GMocren G4zlib
geant4vis_EX_USE := geant4core

ALL_TOOLS      += giflib
giflib_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/giflib/4.2.3-oenich/include
giflib_EX_LIB := gif
giflib_EX_USE := root_cxxdefaults

ALL_TOOLS      += git

ALL_TOOLS      += glibc

ALL_TOOLS      += glimpse

ALL_TOOLS      += gmake

ALL_TOOLS      += gmp
gmp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/gmp-static/6.1.0-oenich/include
gmp_EX_LIB := gmp
gmp_EX_USE := mpfr

ALL_TOOLS      += gnuplot

ALL_TOOLS      += graphviz
graphviz_EX_USE := expat zlib libjpeg-turbo libpng

ALL_TOOLS      += gsl
gsl_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/gsl/2.2.1/include
gsl_EX_LIB := gsl gslcblas
gsl_EX_USE := root_cxxdefaults

ALL_TOOLS      += hdf5
hdf5_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/hdf5/1.8.17-oenich/include
hdf5_EX_LIB := hdf5

ALL_TOOLS      += hector
hector_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/hector/1.3.4_patch1-elfike2/include
hector_EX_LIB := Hector
hector_EX_USE := root_cxxdefaults

ALL_TOOLS      += hepmc
hepmc_EX_LIB := HepMCfio HepMC
hepmc_EX_USE := hepmc_headers

ALL_TOOLS      += hepmc_headers
hepmc_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/hepmc/2.06.07-oenich/include
hepmc_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += heppdt
heppdt_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/heppdt/3.03.00-fmblme2/include
heppdt_EX_LIB := HepPDT HepPID
heppdt_EX_USE := root_cxxdefaults

ALL_TOOLS      += herwig
herwig_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/herwig/6.521-fmblme/include
herwig_EX_LIB := herwig herwig_dummy
herwig_EX_USE := root_cxxdefaults f77compiler lhapdf photos

ALL_TOOLS      += herwigpp
herwigpp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/herwigpp/2.7.1-fmblme/include

ALL_TOOLS      += histfactory
histfactory_EX_LIB := HistFactory
histfactory_EX_USE := roofitcore roofit roostats rootcore roothistmatrix rootgpad rootxml rootfoam

ALL_TOOLS      += igprof

ALL_TOOLS      += intel-license

ALL_TOOLS      += ittnotify
ittnotify_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/ittnotify/16.06.18-fmblme/include
ittnotify_EX_LIB := ittnotify

ALL_TOOLS      += iwyu-cxxcompiler
iwyu-cxxcompiler_EX_USE := llvm-cxxcompiler

ALL_TOOLS      += jemalloc
jemalloc_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/jemalloc/4.5.0/include
jemalloc_EX_LIB := jemalloc
jemalloc_EX_USE := root_cxxdefaults

ALL_TOOLS      += jimmy
jimmy_EX_LIB := jimmy
jimmy_EX_USE := f77compiler herwig jimmy_headers

ALL_TOOLS      += jimmy_headers
jimmy_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/jimmy/4.2-fmblme/include
jimmy_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += ktjet
ktjet_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/ktjet/1.06-fmblme/include
ktjet_EX_LIB := KtEvent
ktjet_EX_USE := root_cxxdefaults
ktjet_EX_FLAGS_CPPDEFINES  := -DKTDOUBLEPRECISION

ALL_TOOLS      += lapack

ALL_TOOLS      += lcov

ALL_TOOLS      += lhapdf
lhapdf_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/lhapdf/6.2.1-fmblme/include
lhapdf_EX_LIB := LHAPDF
lhapdf_EX_USE := yaml-cpp root_cxxdefaults

ALL_TOOLS      += libffi
libffi_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libffi/3.2.1/include
libffi_EX_LIB := ffi

ALL_TOOLS      += libhepml
libhepml_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libhepml/0.2.1/interface
libhepml_EX_LIB := hepml
libhepml_EX_USE := root_cxxdefaults

ALL_TOOLS      += libjpeg-turbo
libjpeg-turbo_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libjpeg-turbo/1.3.1/include
libjpeg-turbo_EX_LIB := jpeg turbojpeg
libjpeg-turbo_EX_USE := root_cxxdefaults

ALL_TOOLS      += libpng
libpng_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libpng/1.6.16-oenich/include
libpng_EX_LIB := png
libpng_EX_USE := root_cxxdefaults zlib

ALL_TOOLS      += libtiff
libtiff_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libtiff/4.0.3-oenich/include
libtiff_EX_LIB := tiff
libtiff_EX_USE := root_cxxdefaults libjpeg-turbo zlib

ALL_TOOLS      += libungif
libungif_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libungif/4.1.4/include
libungif_EX_LIB := ungif
libungif_EX_USE := root_cxxdefaults zlib

ALL_TOOLS      += libuuid
libuuid_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libuuid/2.22.2/include
libuuid_EX_LIB := uuid
libuuid_EX_USE := root_cxxdefaults sockets

ALL_TOOLS      += libxml2
libxml2_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libxml2/2.9.1-oenich/include/libxml2
libxml2_EX_LIB := xml2
libxml2_EX_USE := root_cxxdefaults

ALL_TOOLS      += libxslt
libxslt_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libxslt/1.1.28-fmblme/include/libxslt
libxslt_EX_LIB := xslt

ALL_TOOLS      += llvm-analyzer-ccompiler
llvm-analyzer-ccompiler_EX_USE := llvm-ccompiler

ALL_TOOLS      += llvm-analyzer-cxxcompiler
llvm-analyzer-cxxcompiler_EX_USE := llvm-cxxcompiler

ALL_TOOLS      += llvm-ccompiler
llvm-ccompiler_EX_USE := gcc-ccompiler

ALL_TOOLS      += llvm-cxxcompiler
llvm-cxxcompiler_EX_USE := gcc-cxxcompiler
llvm-cxxcompiler_EX_FLAGS_CXXFLAGS  := -Wno-c99-extensions -Wno-c++11-narrowing -D__STRICT_ANSI__ -Wno-unused-private-field -Wno-unknown-pragmas -Wno-unused-command-line-argument -ftemplate-depth=512 -Wno-error=potentially-evaluated-expression
llvm-cxxcompiler_EX_FLAGS_REM_CXXFLAGS  := -Wno-non-template-friend -Werror=format-contains-nul -Werror=maybe-uninitialized -Werror=unused-but-set-variable -Werror=return-local-addr -fipa-pta -frounding-math -mrecip -Wno-psabi -fno-crossjumping -fno-aggressive-loop-optimizations

ALL_TOOLS      += llvm-f77compiler
llvm-f77compiler_EX_USE := gcc-f77compiler

ALL_TOOLS      += llvm
llvm_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/llvm/4.0.1/include
llvm_EX_LIB := clang
llvm_EX_FLAGS_LDFLAGS  := -Wl,-undefined -Wl,suppress
llvm_EX_FLAGS_CXXFLAGS  := -D_DEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -O3 -fomit-frame-pointer -fPIC -Wno-enum-compare -Wno-strict-aliasing -fno-rtti

ALL_TOOLS      += lwtnn
lwtnn_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/lwtnn/1.0-fmblme3/include
lwtnn_EX_LIB := lwtnn
lwtnn_EX_USE := root_cxxdefaults eigen boost_system

ALL_TOOLS      += madgraph5amcatnlo
madgraph5amcatnlo_EX_LIB := MadGraph5aMCatNLO
madgraph5amcatnlo_EX_USE := root_cxxdefaults

ALL_TOOLS      += mcdb
mcdb_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/mcdb/1.0.3/interface
mcdb_EX_LIB := mcdb
mcdb_EX_USE := root_cxxdefaults xerces-c

ALL_TOOLS      += mctester
mctester_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/mctester/1.25.0a-elfike2/include
mctester_EX_LIB := HEPEvent HepMCEvent MCTester
mctester_EX_USE := root_cxxdefaults root hepmc

ALL_TOOLS      += md5
md5_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/md5/1.0.0/include
md5_EX_LIB := cms-md5

ALL_TOOLS      += meschach
meschach_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/meschach/1.2.pCMS1/include
meschach_EX_LIB := meschach
meschach_EX_USE := root_cxxdefaults

ALL_TOOLS      += millepede
millepede_EX_USE := sockets pcre zlib

ALL_TOOLS      += mpfr
mpfr_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/mpfr-static/3.1.3-oenich/include
mpfr_EX_LIB := mpfr

ALL_TOOLS      += numpy-c-api
numpy-c-api_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/py2-numpy/1.14.1-elfike/c-api/core/include
numpy-c-api_EX_LIB := npymath

ALL_TOOLS      += openblas
openblas_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/OpenBLAS/0.2.19-mlhled2/include
openblas_EX_LIB := openblas

ALL_TOOLS      += opengl
opengl_EX_LIB := GL GLU
opengl_EX_USE := x11

ALL_TOOLS      += openldap
openldap_EX_USE := openssl db6

ALL_TOOLS      += openloops

ALL_TOOLS      += openmpi
openmpi_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openmpi/2.1.2rc4/include
openmpi_EX_LIB := mpi mpi_cxx

ALL_TOOLS      += openssl
openssl_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openssl/1.0.2d/include
openssl_EX_LIB := ssl crypto
openssl_EX_USE := root_cxxdefaults

ALL_TOOLS      += oracle
oracle_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/oracle/12.1.0.2.0/include
oracle_EX_LIB := clntsh
oracle_EX_USE := root_cxxdefaults sockets

ALL_TOOLS      += oracleocci
oracleocci_EX_LIB := occi
oracleocci_EX_USE := oracle

ALL_TOOLS      += pacparser
pacparser_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/pacparser/1.3.5/include
pacparser_EX_LIB := pacparser
pacparser_EX_USE := root_cxxdefaults

ALL_TOOLS      += pcre
pcre_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/pcre/8.37-oenich/include
pcre_EX_LIB := pcre
pcre_EX_USE := root_cxxdefaults zlib bz2lib

ALL_TOOLS      += photos
photos_EX_LIB := photos
photos_EX_USE := photos_headers f77compiler

ALL_TOOLS      += photos_headers
photos_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/photos/215.5/include
photos_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += photospp
photospp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/photospp/3.61-oenich/include
photospp_EX_LIB := Photospp PhotosppHepMC PhotosppHEPEVT
photospp_EX_USE := hepmc

ALL_TOOLS      += professor

ALL_TOOLS      += professor2
professor2_EX_USE := py2-numpy py2-sympy py2-matplotlib root yoda eigen

ALL_TOOLS      += protobuf
protobuf_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/protobuf/3.4.0-fmblme/include
protobuf_EX_LIB := protobuf
protobuf_EX_USE := root_cxxdefaults

ALL_TOOLS      += py2-appdirs
py2-appdirs_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-argparse
py2-argparse_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-avro
py2-avro_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-backports_abc
py2-backports_abc_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-backportsssl_match_hostname
py2-backportsssl_match_hostname_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-bleach
py2-bleach_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-bottleneck
py2-bottleneck_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-certifi
py2-certifi_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-chardet
py2-chardet_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-cjson
py2-cjson_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-click
py2-click_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-climate
py2-climate_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-configparser
py2-configparser_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-cx-oracle
py2-cx-oracle_EX_USE := python oracle

ALL_TOOLS      += py2-cycler
py2-cycler_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-dablooms

ALL_TOOLS      += py2-decorator
py2-decorator_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-deepdish
py2-deepdish_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-docopt
py2-docopt_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-downhill
py2-downhill_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-dxr
py2-dxr_EX_USE := python sqlite py2-pysqlite py2-pippkgs

ALL_TOOLS      += py2-entrypoints
py2-entrypoints_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-enum34
py2-enum34_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-fs
py2-fs_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-funcsigs
py2-funcsigs_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-functools32
py2-functools32_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-futures
py2-futures_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-h5py
py2-h5py_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-hep_ml
py2-hep_ml_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-histogrammar
py2-histogrammar_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-html5lib
py2-html5lib_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-hyperas
py2-hyperas_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-hyperopt
py2-hyperopt_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-idna
py2-idna_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-ipykernel
py2-ipykernel_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-ipython
py2-ipython_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-ipython_genutils
py2-ipython_genutils_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-ipywidgets
py2-ipywidgets_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jinja
py2-jinja_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jinja2
py2-jinja2_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jsonpickle
py2-jsonpickle_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jsonschema
py2-jsonschema_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jupyter
py2-jupyter_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jupyter_client
py2-jupyter_client_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jupyter_console
py2-jupyter_console_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-jupyter_core
py2-jupyter_core_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-keras
py2-keras_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-lint
py2-lint_EX_USE := python

ALL_TOOLS      += py2-lizard
py2-lizard_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-llvmlite
py2-llvmlite_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-markupsafe
py2-markupsafe_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-matplotlib
py2-matplotlib_EX_USE := python zlib libpng py2-numpy py2-pippkgs

ALL_TOOLS      += py2-mistune
py2-mistune_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-mock
py2-mock_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-mpmath
py2-mpmath_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-nbconvert
py2-nbconvert_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-nbformat
py2-nbformat_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-networkx
py2-networkx_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-nose
py2-nose_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-notebook
py2-notebook_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-numba
py2-numba_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-numexpr
py2-numexpr_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-numpy
py2-numpy_EX_USE := python zlib lapack openblas

ALL_TOOLS      += py2-ordereddict
py2-ordereddict_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-packaging
py2-packaging_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pandas
py2-pandas_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-pandocfilters
py2-pandocfilters_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-parsimonious
py2-parsimonious_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pathlib2
py2-pathlib2_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pbr
py2-pbr_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pexpect
py2-pexpect_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pickleshare
py2-pickleshare_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pip

ALL_TOOLS      += py2-pippkgs

ALL_TOOLS      += py2-pippkgs_depscipy

ALL_TOOLS      += py2-pkgconfig
py2-pkgconfig_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-prettytable
py2-prettytable_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-prompt_toolkit
py2-prompt_toolkit_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-protobuf
py2-protobuf_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-prwlock
py2-prwlock_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-psutil
py2-psutil_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-ptyprocess
py2-ptyprocess_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pycurl
py2-pycurl_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pygithub

ALL_TOOLS      += py2-pygments
py2-pygments_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pyparsing
py2-pyparsing_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pysqlite
py2-pysqlite_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pytest
py2-pytest_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-python-dateutil
py2-python-dateutil_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pytz
py2-pytz_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-pyyaml

ALL_TOOLS      += py2-pyzmq
py2-pyzmq_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-qtconsole
py2-qtconsole_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-rep
py2-rep_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-repozelru
py2-repozelru_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-requests
py2-requests_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-root_numpy
py2-root_numpy_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-root_pandas
py2-root_pandas_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-rootpy
py2-rootpy_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-scandir
py2-scandir_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-schema
py2-schema_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-scikit-learn
py2-scikit-learn_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-scipy
py2-scipy_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-seaborn
py2-seaborn_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-setuptools
py2-setuptools_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-shutil_get_terminal_size
py2-shutil_get_terminal_size_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-simplegeneric
py2-simplegeneric_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-singledispatch
py2-singledispatch_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-six
py2-six_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-sqlalchemy
py2-sqlalchemy_EX_USE := python

ALL_TOOLS      += py2-sympy
py2-sympy_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-tables
py2-tables_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-tensorflow
py2-tensorflow_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-terminado
py2-terminado_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-testpath
py2-testpath_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-theanets
py2-theanets_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-theano
py2-theano_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-thriftpy
py2-thriftpy_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-tornado
py2-tornado_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-tqdm
py2-tqdm_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-traitlets
py2-traitlets_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-uncertainties
py2-uncertainties_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-urllib3
py2-urllib3_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-virtualenv
py2-virtualenv_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-virtualenvwrapper
py2-virtualenvwrapper_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-wcwidth
py2-wcwidth_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-webencodings
py2-webencodings_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-werkzeug
py2-werkzeug_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-widgetsnbextension
py2-widgetsnbextension_EX_USE := py2-pippkgs

ALL_TOOLS      += py2-xgboost
py2-xgboost_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += py2-xrootdpyfs
py2-xrootdpyfs_EX_USE := py2-pippkgs_depscipy

ALL_TOOLS      += pyclang
pyclang_EX_USE := python

ALL_TOOLS      += pydata
pydata_EX_FLAGS_LDFLAGS  := $(PYDATA_BASE)/lib/pydata.o
pydata_EX_FLAGS_NO_RECURSIVE_EXPORT  := 1

ALL_TOOLS      += pyminuit2

ALL_TOOLS      += pyqt
pyqt_EX_USE := python qt sip

ALL_TOOLS      += pythia6
pythia6_EX_LIB := pythia6 pythia6_dummy pythia6_pdfdummy
pythia6_EX_USE := pythia6_headers f77compiler

ALL_TOOLS      += pythia6_headers
pythia6_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/pythia6/426/include
pythia6_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += pythia8
pythia8_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/pythia8/230/include
pythia8_EX_LIB := pythia8
pythia8_EX_USE := root_cxxdefaults cxxcompiler hepmc lhapdf

ALL_TOOLS      += python-ldap
python-ldap_EX_USE := openssl openldap python

ALL_TOOLS      += python
python_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/python/2.7.11-fmblme/include/python2.7
python_EX_LIB := python2.7
python_EX_USE := root_cxxdefaults sockets

ALL_TOOLS      += qd
qd_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qd/2.3.13/include
qd_EX_LIB := qd_f_main qdmod qd

ALL_TOOLS      += qt
qt_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/QtOpenGL /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/QtGui
qt_EX_LIB := QtOpenGL QtGui
qt_EX_USE := root_cxxdefaults qtbase qt3support x11 opengl

ALL_TOOLS      += qt3support
qt3support_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/Qt3Support
qt3support_EX_LIB := Qt3Support
qt3support_EX_USE := root_cxxdefaults qtbase
qt3support_EX_FLAGS_CPPDEFINES  := -DQT3_SUPPORT

ALL_TOOLS      += qtbase
qtbase_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/Qt /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/QtCore /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/QtXml
qtbase_EX_LIB := QtCore QtXml
qtbase_EX_USE := root_cxxdefaults zlib
qtbase_EX_FLAGS_CPPDEFINES  := -DQT_ALTERNATE_QTSMANIP -DQT_CLEAN_NAMESPACE -DQT_THREAD_SUPPORT

ALL_TOOLS      += qtdesigner
qtdesigner_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/qt/4.8.7/include/QtDesigner
qtdesigner_EX_LIB := QtDesigner
qtdesigner_EX_USE := root_cxxdefaults qtbase qt

ALL_TOOLS      += rivet
rivet_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/rivet/2.5.4-elfike2/include
rivet_EX_LIB := Rivet
rivet_EX_USE := hepmc fastjet gsl yoda

ALL_TOOLS      += roofit
roofit_EX_LIB := RooFit
roofit_EX_USE := roofitcore rootcore rootmath roothistmatrix

ALL_TOOLS      += roofitcore
roofitcore_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/lcg/root/6.10.08-elfike2/include
roofitcore_EX_LIB := RooFitCore
roofitcore_EX_USE := rootcore roothistmatrix rootgpad rootminuit root_cxxdefaults

ALL_TOOLS      += roostats
roostats_EX_LIB := RooStats
roostats_EX_USE := roofitcore roofit rootcore roothistmatrix rootgpad

ALL_TOOLS      += root
root_EX_USE := rootphysics
root_EX_FLAGS_NO_CAPABILITIES  := yes

ALL_TOOLS      += root_cxxdefaults

ALL_TOOLS      += root_interface
root_interface_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/lcg/root/6.10.08-elfike2/include
root_interface_EX_USE := root_cxxdefaults

ALL_TOOLS      += rootcling
rootcling_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/lcg/root/6.10.08-elfike2/include
rootcling_EX_LIB := Core
rootcling_EX_USE := root_interface sockets pcre zlib xz

ALL_TOOLS      += rootcore
rootcore_EX_LIB := Tree Net
rootcore_EX_USE := rootmathcore rootthread

ALL_TOOLS      += rooteg
rooteg_EX_LIB := EG
rooteg_EX_USE := rootgraphics

ALL_TOOLS      += rooteve
rooteve_EX_LIB := Eve
rooteve_EX_USE := rootgeompainter rootrgl

ALL_TOOLS      += rootfoam
rootfoam_EX_LIB := Foam
rootfoam_EX_USE := roothistmatrix

ALL_TOOLS      += rootgeom
rootgeom_EX_LIB := Geom
rootgeom_EX_USE := rootrio rootmathcore

ALL_TOOLS      += rootgeompainter
rootgeompainter_EX_LIB := GeomPainter
rootgeompainter_EX_USE := rootgeom rootgraphics

ALL_TOOLS      += rootgpad
rootgpad_EX_LIB := Gpad Graf
rootgpad_EX_USE := roothistmatrix

ALL_TOOLS      += rootgraphics
rootgraphics_EX_LIB := TreePlayer Graf3d Postscript
rootgraphics_EX_USE := rootgpad

ALL_TOOLS      += rootguihtml
rootguihtml_EX_LIB := GuiHtml
rootguihtml_EX_USE := rootinteractive

ALL_TOOLS      += roothistmatrix
roothistmatrix_EX_LIB := Hist Matrix
roothistmatrix_EX_USE := rootcore

ALL_TOOLS      += roothtml
roothtml_EX_LIB := Html
roothtml_EX_USE := rootgpad

ALL_TOOLS      += rootinteractive
rootinteractive_EX_LIB := Gui
rootinteractive_EX_USE := libjpeg-turbo libpng rootgpad rootrint

ALL_TOOLS      += rootmath
rootmath_EX_LIB := GenVector MathMore
rootmath_EX_USE := rootcore gsl

ALL_TOOLS      += rootmathcore
rootmathcore_EX_LIB := MathCore
rootmathcore_EX_USE := rootcling

ALL_TOOLS      += rootminuit
rootminuit_EX_LIB := Minuit
rootminuit_EX_USE := rootgpad

ALL_TOOLS      += rootminuit2
rootminuit2_EX_LIB := Minuit2
rootminuit2_EX_USE := rootgpad

ALL_TOOLS      += rootmlp
rootmlp_EX_LIB := MLP
rootmlp_EX_USE := rootgraphics

ALL_TOOLS      += rootphysics
rootphysics_EX_LIB := Physics
rootphysics_EX_USE := roothistmatrix

ALL_TOOLS      += rootpy
rootpy_EX_LIB := PyROOT
rootpy_EX_USE := rootgraphics

ALL_TOOLS      += rootpymva
rootpymva_EX_LIB := PyMVA
rootpymva_EX_USE := roottmva numpy-c-api

ALL_TOOLS      += rootrflx
rootrflx_EX_USE := root_interface rootcling
rootrflx_EX_FLAGS_GENREFLEX_CPPFLAGS  := -DCMS_DICT_IMPL -D_REENTRANT -DGNUSOURCE -D__STRICT_ANSI__
rootrflx_EX_FLAGS_GENREFLEX_GCCXMLOPT  := -m64
rootrflx_EX_FLAGS_GENREFLEX_ARGS  := --deep

ALL_TOOLS      += rootrgl
rootrgl_EX_LIB := RGL
rootrgl_EX_USE := rootinteractive rootgraphics

ALL_TOOLS      += rootrint
rootrint_EX_LIB := Rint
rootrint_EX_USE := rootcling

ALL_TOOLS      += rootrio
rootrio_EX_LIB := RIO
rootrio_EX_USE := rootcling

ALL_TOOLS      += rootsmatrix
rootsmatrix_EX_LIB := Smatrix
rootsmatrix_EX_USE := rootcling

ALL_TOOLS      += rootspectrum
rootspectrum_EX_LIB := Spectrum
rootspectrum_EX_USE := roothistmatrix

ALL_TOOLS      += rootthread
rootthread_EX_LIB := Thread
rootthread_EX_USE := rootrio

ALL_TOOLS      += roottmva
roottmva_EX_LIB := TMVA
roottmva_EX_USE := rootmlp rootminuit

ALL_TOOLS      += rootxml
rootxml_EX_LIB := XMLParser
rootxml_EX_USE := rootcore libxml2

ALL_TOOLS      += rootxmlio
rootxmlio_EX_LIB := XMLIO
rootxmlio_EX_USE := rootrio

ALL_TOOLS      += scons

ALL_TOOLS      += self
self_EX_INCLUDE := /home/xiao147/private/Gen_analyzer_nonprompt_Lc/CMSSW_9_4_10/src /home/xiao147/private/Gen_analyzer_nonprompt_Lc/CMSSW_9_4_10/include/LCG /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_10/src /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_10/include/LCG
self_EX_LIBDIR := /home/xiao147/private/Gen_analyzer_nonprompt_Lc/CMSSW_9_4_10/lib/slc6_amd64_gcc630 /home/xiao147/private/Gen_analyzer_nonprompt_Lc/CMSSW_9_4_10/external/slc6_amd64_gcc630/lib /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_10/lib/slc6_amd64_gcc630 /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_10/external/slc6_amd64_gcc630/lib
self_EX_FLAGS_SYMLINK_DEPTH_CMSSW_SEARCH_PATH  := 2
self_EX_FLAGS_LLVM_ANALYZER  := llvm-analyzer
self_EX_FLAGS_SKIP_TOOLS_SYMLINK  := cxxcompiler ccompiler f77compiler gcc-cxxcompiler gcc-ccompiler gcc-f77compiler llvm-cxxcompiler llvm-ccompiler llvm-f77compiler llvm-analyzer-cxxcompiler llvm-analyzer-ccompiler icc-cxxcompiler icc-ccompiler icc-f77compiler x11 dpm
self_EX_FLAGS_DEFAULT_COMPILER  := gcc
self_EX_FLAGS_EXTERNAL_SYMLINK  := PATH LIBDIR CMSSW_SEARCH_PATH
self_EX_FLAGS_NO_EXTERNAL_RUNTIME  := LD_LIBRARY_PATH PATH CMSSW_SEARCH_PATH
TOOLS_OVERRIDABLE_FLAGS  +=CPPDEFINES CXXFLAGS FFLAGS CFLAGS CPPFLAGS LDFLAGS CUDA_FLAGS CUDA_LDFLAGS
self_ORDER := 20000
IS_PATCH:=

ALL_TOOLS      += sherpa
sherpa_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/sherpa/2.2.4-elfike2/include/SHERPA-MC
sherpa_EX_LIB := SherpaMain ToolsMath ToolsOrg
sherpa_EX_USE := root_cxxdefaults hepmc lhapdf qd blackhat fastjet sqlite openmpi openloops

ALL_TOOLS      += sigcpp
sigcpp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/sigcpp/2.6.2-oenich/include/sigc++-2.0
sigcpp_EX_LIB := sigc-2.0
sigcpp_EX_USE := root_cxxdefaults

ALL_TOOLS      += sip
sip_EX_USE := python

ALL_TOOLS      += sloccount

ALL_TOOLS      += sockets
sockets_EX_LIB := nsl crypt dl rt

ALL_TOOLS      += sqlite
sqlite_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/sqlite/3.16.2/include
sqlite_EX_LIB := sqlite3
sqlite_EX_USE := root_cxxdefaults

ALL_TOOLS      += starlight
starlight_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/starlight/r193-fmblme/include
starlight_EX_LIB := Starlib
starlight_EX_USE := root_cxxdefaults clhep

ALL_TOOLS      += tauola
tauola_EX_LIB := pretauola tauola
tauola_EX_USE := f77compiler tauola_headers

ALL_TOOLS      += tauola_headers
tauola_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tauola/27.121.5/include
tauola_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += tauolapp
tauolapp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tauolapp/1.1.5-fmblme2/include
tauolapp_EX_LIB := TauolaCxxInterface TauolaFortran TauolaTauSpinner
tauolapp_EX_USE := root_cxxdefaults hepmc f77compiler pythia8 lhapdf

ALL_TOOLS      += tbb
tbb_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tbb/2018/include
tbb_EX_LIB := tbb
tbb_EX_USE := root_cxxdefaults
tbb_EX_FLAGS_CPPDEFINES  := -DTBB_USE_GLIBCXX_VERSION=60300

ALL_TOOLS      += tcmalloc
tcmalloc_EX_LIB := tcmalloc

ALL_TOOLS      += tcmalloc_minimal
tcmalloc_minimal_EX_LIB := tcmalloc_minimal

ALL_TOOLS      += tensorflow-c
tensorflow-c_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tensorflow-c/1.1.0-elfike/include
tensorflow-c_EX_LIB := tensorflow

ALL_TOOLS      += tensorflow-cc
tensorflow-cc_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tensorflow-cc/1.3.0-elfike/tensorflow_cc/include
tensorflow-cc_EX_LIB := tensorflow_cc
tensorflow-cc_EX_USE := tensorflow-c eigen protobuf

ALL_TOOLS      += thepeg
thepeg_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/thepeg/1.9.2p1-fmblme/include
thepeg_EX_LIB := ThePEG LesHouches
thepeg_EX_USE := root_cxxdefaults lhapdf gsl

ALL_TOOLS      += tinyxml
tinyxml_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tinyxml/2.5.3-fmblme/include
tinyxml_EX_LIB := tinyxml

ALL_TOOLS      += tkonlinesw
tkonlinesw_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tkonlinesw/4.1.0-1-elfike2/include
tkonlinesw_EX_LIB := ICUtils Fed9UUtils
tkonlinesw_EX_USE := root_cxxdefaults xerces-c
tkonlinesw_EX_FLAGS_CXXFLAGS  := -DCMS_TK_64BITS

ALL_TOOLS      += tkonlineswdb
tkonlineswdb_EX_LIB := DeviceDescriptions Fed9UDeviceFactory
tkonlineswdb_EX_USE := tkonlinesw oracle oracleocci

ALL_TOOLS      += toprex
toprex_EX_LIB := toprex
toprex_EX_USE := toprex_headers f77compiler

ALL_TOOLS      += toprex_headers
toprex_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/toprex/4.23/include
toprex_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += utm
utm_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/utm/utm_0.6.5-fmblme/include
utm_EX_LIB := tmeventsetup tmtable tmxsd tmgrammar tmutil
utm_EX_USE := root_cxxdefaults

ALL_TOOLS      += valgrind
valgrind_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/valgrind/3.12.0-oenich/include
valgrind_EX_USE := root_cxxdefaults

ALL_TOOLS      += vdt
vdt_EX_LIB := vdt
vdt_EX_USE := vdt_headers

ALL_TOOLS      += vdt_headers
vdt_headers_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/vdt/0.3.9/include
vdt_headers_EX_USE := root_cxxdefaults

ALL_TOOLS      += vincia
vincia_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/vincia/2.2.01-fmblme/include
vincia_EX_LIB := vincia VinciaMG4 VinciaMG5
vincia_EX_USE := root_cxxdefaults pythia8

ALL_TOOLS      += x11
x11_EX_USE := sockets

ALL_TOOLS      += xerces-c
xerces-c_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xerces-c/3.1.3/include
xerces-c_EX_LIB := xerces-c
xerces-c_EX_USE := root_cxxdefaults

ALL_TOOLS      += xrootd
xrootd_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xrootd/4.6.1-fmblme/include/xrootd /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xrootd/4.6.1-fmblme/include/xrootd/private
xrootd_EX_LIB := XrdUtils XrdClient
xrootd_EX_USE := root_cxxdefaults

ALL_TOOLS      += xz
xz_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xz/5.2.2-oenich/include
xz_EX_LIB := lzma
xz_EX_USE := root_cxxdefaults

ALL_TOOLS      += yaml-cpp
yaml-cpp_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/yaml-cpp/0.5.1-fmblme/include
yaml-cpp_EX_LIB := yaml-cpp
yaml-cpp_EX_USE := boost

ALL_TOOLS      += yoda
yoda_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/yoda/1.6.7-elfike2/include
yoda_EX_LIB := YODA
yoda_EX_USE := root_cxxdefaults

ALL_TOOLS      += zlib
zlib_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/zlib-x86_64/1.2.11/include
zlib_EX_LIB := z
zlib_EX_USE := root_cxxdefaults

