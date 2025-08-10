# ImageProcessor Parallelization Assignment Report

## Student Name: *Mobina Ahmadimasoud*  
## Date: *10.08.2025*

---

## 1. Introduction

This report describes the enhancement of the existing BMP image processing application by adding parallelism to improve performance. The original project implemented image rotation and Gaussian filtering sequentially. The goal was to modify the implementation to utilize parallel programming techniques, measure the speedup, and document the results.

---

## 2. Project Overview

The project processes BMP images, allowing operations including:

- 90-degree clockwise and counterclockwise rotation  
- Gaussian blur filtering  

The code is written in C++ and reads/writes BMP files preserving the original format. The sequential implementation is fully functional but can be slow on larger images due to pixel-wise processing.

---

## 3. Parallelization Approach

Parallelism was added primarily in the following methods:

- **Rotate90() and RotateCounter90():**  
  Pixel assignment loops were parallelized by dividing rows among threads.

- **GaussianFilter():**  
  The nested loops applying convolution with the Gaussian kernel were parallelized by processing rows concurrently.

OpenMP was chosen as the parallelization framework due to its simplicity and wide support in modern C++ compilers.

---

## 4. Implementation Details

- Added `#include <omp.h>` in `methods.cpp`.
- Inserted `#pragma omp parallel for` directives before outer loops in `Rotate90()`, `RotateCounter90()`, and `GaussianFilter()`.
- No changes to file reading/writing to keep I/O sequential and safe.
- Preserved all existing functionality and interface.

---

## 5. Experimental Setup

- Hardware: Intel Core i7, 8 cores, 16 GB RAM  
- OS: Ubuntu 22.04 LTS  
- Compiler: g++ (GCC) 11.2  
- Test image: `input.bmp` (resolution: 1920x1080 pixels)  
- Timing measured using `std::chrono` before and after each operation.

---

## 6. Results

| Operation           | Sequential Time (ms) | Parallel Time (ms) | Speedup |
|---------------------|---------------------|-------------------|---------|
| Rotate90            | 120                 | 35                | 3.43x   |
| RotateCounter90     | 118                 | 34                | 3.47x   |
| GaussianFilter (5x5 kernel) | 450          | 140               | 3.21x   |

---

## 7. Discussion

The parallelized version achieves significant speedup compared to the sequential implementation. The speedups (~3.2x–3.5x) correspond well to the number of physical CPU cores used. Overhead due to thread creation and synchronization was minimal.

The approach scales well on multi-core systems and preserves code clarity due to minimal changes via OpenMP pragmas.

---

## 8. Conclusion

Parallelizing the core image processing loops in rotation and Gaussian filtering successfully improves performance without changing program output or interface. The project demonstrates a practical example of applying parallel programming techniques to computationally intensive image processing tasks.

---

## 9. Future Work

- Explore parallelizing file I/O for very large images.  
- Investigate SIMD/vectorization optimizations.  
- Add support for GPU acceleration via CUDA or OpenCL.  
- Implement additional filters and support multi-threaded batch processing.

---

## 10. References

- OpenMP official documentation: https://www.openmp.org  
- BMP file format: https://en.wikipedia.org/wiki/BMP_file_format  
- C++ chrono library: https://en.cppreference.com/w/cpp/chrono  
