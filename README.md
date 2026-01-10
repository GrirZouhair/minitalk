# Minitalk

A simple **client-server communication project** in **C** using **UNIX signals**.

Minitalk is part of the 42/1337 cursus and teaches how to use low-level **inter-process communication (IPC)** through signals. The client sends messages to the server one bit at a time using `SIGUSR1` and `SIGUSR2`, and the server reconstructs and displays the message in real time.:contentReference[oaicite:1]{index=1}

---

## 🚀 Table of Contents

- [About](#about)  
- [Features](#features)  
- [Requirements](#requirements)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Bonus](#bonus)  
- [Project Structure](#project-structure)  
- [Skills Learned](#skills-learned)  
- [License](#license)

---

## 📌 About

Minitalk creates a basic communication channel between two processes:  
- **Server**: waits for messages and prints them  
- **Client**: sends text messages bit by bit using signals

Only `SIGUSR1` and `SIGUSR2` are used to encode binary message data.:contentReference[oaicite:2]{index=2}

---

## ⚙️ Features

✔ Client-server communication via UNIX signals  
✔ Bit-by-bit message encoding and decoding  
✔ Simple POSIX signal handling  
✔ Makefile for building project

---

## 📦 Requirements

- C compiler (`gcc`)  
- `Make`  
- Unix-like OS (Linux, macOS)  
- Basics of signal handling and IPC

---

## 📥 Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/GrirZouhair/minitalk.git
    cd minitalk
    ```

2. Compile the project:

    ```bash
    make
    ```

This generates the `server` and `client` executables.

---

## ▶️ Usage

### 1️⃣ Run the server

Open a terminal:

```bash
./server
