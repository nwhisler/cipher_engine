# cipher-engine

A modular C++ cryptography toolkit implementing both **block** and **stream** cipher modes through a deterministic command‑line interface. This academic project demonstrates applied cryptography concepts, file‑based encryption pipelines, and robust systems programming practices in modern C++.

---

## Overview

`cipher-engine` is a C++ program that supports encryption and decryption workflows using configurable cipher types. It was developed as part of an academic cryptography assignment to explore how classical cipher primitives can be implemented at the systems level with reusable components, input validation, and modular design.

The project includes:

* Block cipher implementation using XOR‑based transformation
* Stream cipher implementation for continuous data encryption
* File‑based input/output pipeline
* CLI argument parsing and validation utilities
* Modular C++ class design with reusable helper functions
* Makefile‑based build automation

This project emphasizes correctness, deterministic execution, and secure software engineering practices.

---

## Learning Objectives

This project was designed to reinforce:

* Practical implementation of **block vs. stream cipher concepts**
* File I/O handling in C++
* Modular program architecture with headers and source files
* Command‑line interface design
* Input validation and error handling
* Deterministic encryption pipelines
* Build automation with Makefiles

---

## Build Instructions

Make sure you have a C++ compiler installed (e.g., `g++`).

```bash
make
```

This compiles the program into an executable (name depends on Makefile configuration).

To clean build artifacts:

```bash
make clean
```

---

## Usage

Program arguments:

```
./cipher-engine <cipher_type> <input_file> <output_file> <key_file> <mode>
```

### Parameters

| Argument      | Description                                   |
| ------------- | --------------------------------------------- |
| `cipher_type` | `B` for Block cipher, `S` for Stream cipher   |
| `input_file`  | Path to plaintext or ciphertext input         |
| `output_file` | Path where output will be written             |
| `key_file`    | File containing encryption key                |
| `mode`        | `E` for Encrypt, `D` for Decrypt              |

---

## Example

Encrypt a file using block cipher:

```bash
./cipher-engine B plaintext.txt encrypted.txt key.txt E
```

Decrypt it:

```bash
./cipher-engine B encrypted.txt decrypted.txt key.txt D
```

Stream cipher encryption:

```bash
./cipher-engine S plaintext.txt encrypted.txt key.txt E
```

---

## Implementation Notes

### Block Cipher

* Uses XOR‑based transformation with key input
* Implements both encryption and decryption pipelines
* Includes filtering to ensure valid ASCII output

### Stream Cipher

* Applies continuous XOR transformation across input stream
* Designed to simulate real‑time encryption behavior
