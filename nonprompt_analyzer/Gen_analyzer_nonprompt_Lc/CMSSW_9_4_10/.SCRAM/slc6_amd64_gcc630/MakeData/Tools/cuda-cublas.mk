ALL_TOOLS      += cuda-cublas
cuda-cublas_EX_LIB := cublas cublas_device
cuda-cublas_EX_USE := cuda
cuda-cublas_EX_FLAGS_CUDA_LDFLAGS  := -lcublas_device

