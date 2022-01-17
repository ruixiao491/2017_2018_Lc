ALL_TOOLS      += cuda
cuda_EX_INCLUDE := /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/cuda/9.0.176-fmblme2/include
cuda_EX_LIB := cudart cudadevrt nvToolsExt
cuda_EX_USE := cuda-stubs
cuda_EX_FLAGS_CUDA_LDFLAGS  := -L$(CUDA_BASE)/lib64
cuda_EX_FLAGS_CUDA_FLAGS  := -gencode arch=compute_35,code=sm_35 -gencode arch=compute_50,code=sm_50 -gencode arch=compute_61,code=sm_61

