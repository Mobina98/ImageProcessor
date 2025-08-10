## Author

**Mobina Ahmadimasoud, group 24.B83-mm**

## Contacts
st067173@student.spbu.ru

# Parallel BMP Image Processor

This project performs rotation and Gaussian filtering on BMP images. It extends a sequential Lab 1 solution by introducing parallelism using OpenMP.

## Features

- Load `.bmp` image (24-bit)
- Rotate image 90° clockwise or counterclockwise
- Apply Gaussian blur using a configurable kernel
- Parallelized filtering using OpenMP
- Tested with GitHub Actions CI

## Usage

$ make
$ ./main
Hello, please enter name of file: input.bmp

## documentation

$ make doc
$ xdg-open docs/html/index.html