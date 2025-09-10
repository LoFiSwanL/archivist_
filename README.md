🔐 Simple File Archiver (C++)      //in progress

A basic file archiver implemented in modern C++ using Huffman compression algorithm. The goal of this project was to explore file compression techniques and get hands-on experience with bit manipulation, file I/O, and algorithm implementation.

🚀 Features:
- Compresses and decompresses text files
- Based on Huffman coding algorithm
- Works with arbitrary file sizes
- Cross-platform (tested on Windows and Linux)
- Simple CLI interface

🛠 Technologies Used:
- C++17/C++20
- STL: vector, map, priority_queue, fstream, etc.
- Bit-level operations
- File I/O
- CLI parsing

📁 Project Structure:
/src
├── main.cpp
├── compressor.cpp
├── decompressor.cpp
├── huffman_tree.cpp
/include
├── compressor.h
├── decompressor.h
├── huffman_tree.h
/README.md

📌 How to Run:
1. Clone the repository:
   git clone https://github.com/yourusername/file-archiver.git
   cd file-archiver

2. Build with CMake:
   mkdir build && cd build
   cmake ..
   make

3. Run:
   ./archiver -c input.txt output.archive
   ./archiver -d output.archive output.txt

✅ Future Improvements:
- Support for compressing multiple files (like .zip)
- Custom archive format
- GUI version with Qt
- Benchmarking against existing tools