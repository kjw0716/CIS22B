# CIS 22B — Intermediate C++ Programming

C++ coursework from De Anza College built around one evolving model: **air-cargo unit load devices (ULDs)** loaded onto Boeing 737 and 767 aircraft. Each lab extends the same `Cargo` class, moving from basic classes to file parsing, exceptions, inheritance, polymorphism, and STL containers.

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=flat-square&logo=cplusplus&logoColor=white)](#build-and-run)
[![Topics](https://img.shields.io/badge/topics-OOP%20%C2%B7%20STL%20%C2%B7%20exceptions-555?style=flat-square)](#lab-guide)

## Lab guide

| File | Focus |
| --- | --- |
| [LAB2.cpp](LAB2.cpp) | A `Cargo` class with constructors, destructor, getters and setters; objects created on the heap and filled from console input |
| [LAB3 Jackie.cpp](<LAB3 Jackie.cpp>) | Copy constructor, an overloaded `==` operator, and comparing an original unit with its copy; kilogram-to-pound weight conversion |
| [lab4.cpp](lab4.cpp) | Read a cargo data file line by line with `istringstream`, handle six- and seven-field records (`Combo Flat`), and report bad records with `try` / `throw` / `catch` |
| [lab5_Jackie.cpp](lab5_Jackie.cpp) | Abstract `Cargo` base class with `Boeing737` and `Boeing767` subclasses, validated ULD types per aircraft, maximum-load checks, and storage in `std::vector` and `std::forward_list` |

## Data format

Labs 4 and 5 read a whitespace-separated text file, one cargo unit per line:

```text
<type> <abbreviation> <ULD id> <aircraft> <weight> <destination>
Container AYF AYF12345AA 737 1250 SEA
Combo Flat CFE CFE88776QR 737 2900 SFO
```

`Combo Flat` is the only two-word type. [sample-cargo.txt](sample-cargo.txt) contains valid units plus two intentionally rejected lines (a 767-only container on a 737 and an unknown type) so you can see the error handling in Lab 5.

| Aircraft | Accepted abbreviations | Maximum load |
| --- | --- | --- |
| 737 | AYF, AYK, AAA, AYY, PAG, PMC, PLA, CFE, CFK, CFM | 46,000 lb |
| 767 | AKE, APE, AKC, AQP, AQF, AAP, P1P, P6P, CFQ, CFX, CFP | 116,000 lb |

## Build and run

Any C++17 compiler works. With `g++`, from the repository root:

```sh
g++ -std=c++17 -o lab5 lab5_Jackie.cpp
./lab5
```

Enter `sample-cargo.txt` when the program asks for the data file. Lab 4 also reads the file name from standard input, so `echo sample-cargo.txt | ./lab4` works after building `lab4.cpp` the same way. Labs 2 and 3 prompt for each field interactively.

## Archive notes

- Each lab is a single self-contained file; compile them separately because they all define `Cargo`.
- The original course data files are not included. `sample-cargo.txt` was written to match the format the code parses.
- All four files compiled with MinGW-w64 `g++` (`-std=c++17`) during documentation verification, and Labs 4 and 5 ran against the sample data.
