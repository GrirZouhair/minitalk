# 📡 Minitalk

A **client-server communication project** in C using **UNIX signals** — part of the 42/1337 curriculum.

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42](https://img.shields.io/badge/School-42-black.svg)](https://42.fr)

## 📖 Description

Minitalk demonstrates low-level **inter-process communication (IPC)** using only UNIX signals. The client sends messages to the server one bit at a time using `SIGUSR1` and `SIGUSR2`, and the server reconstructs and displays the message in real time.

This project teaches fundamental concepts about:
- Signal handling in UNIX systems
- Bitwise operations
- Process communication
- Binary data encoding/decoding

## 🎯 How It Works

```
┌─────────┐    SIGUSR1 (bit 0)     ┌─────────┐
│         │ ────────────────────►  │         │
│ CLIENT  │    SIGUSR2 (bit 1)     │ SERVER  │
│         │ ────────────────────►  │         │
└─────────┘                        └─────────┘
     │                                  │
     │  Encodes each character          │  Decodes 8 bits
     │  into 8 bits and sends           │  back into character
     │  them as signals                 │  and prints it
     └──────────────────────────────────┘
```

Each character is converted to its binary representation and sent bit by bit:
- `SIGUSR1` → represents bit `0`
- `SIGUSR2` → represents bit `1`

## ✨ Features

| Mandatory | Bonus |
|-----------|-------|
| ✅ Client-server communication via UNIX signals | ✅ Unicode/UTF-8 support |
| ✅ Bit-by-bit message encoding/decoding | ✅ Server acknowledgment (confirmation signal) |
| ✅ Server displays PID on launch | |
| ✅ Handle multiple messages without restart | |

## 📦 Requirements

- GCC compiler
- Make
- Unix-like OS (Linux, macOS)

## 🛠️ Installation

```bash
# Clone the repository
git clone https://github.com/GrirZouhair/minitalk.git
cd minitalk

# Compile mandatory part
make

# Compile bonus part
make bonus

# Clean object files
make clean

# Full clean (including executables)
make fclean

# Recompile
make re
```

## 🚀 Usage

### Step 1: Start the Server

```bash
./server
```

The server will display its **PID** (Process ID):
```
Server PID: 12345
```

### Step 2: Send a Message from Client

In another terminal:
```bash
./client <server_pid> "Your message here"
```

**Example:**
```bash
./client 12345 "Hello, World!"
```

The server will display:
```
Hello, World!
```

### Bonus Executables

```bash
./server_bonus
./client_bonus <server_pid> "Message with Unicode: 你好 🚀"
```

## 📁 Project Structure

```
minitalk/
├── Makefile
├── minitalk.h
├── utils.c
├── mandatory/
│   ├── client.c
│   └── server.c
└── bonus/
    ├── client_bonus.c
    └── server_bonus.c
```

## 🔧 Technical Details

### Signal Handling

```c
// Server signal handler example
void sig_handler(int sig, siginfo_t *info, void *context)
{
    static int bit = 0;
    static unsigned char c = 0;

    if (sig == SIGUSR2)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}
```

### Allowed Functions

| Function | Description |
|----------|-------------|
| `write` | Output to file descriptor |
| `signal` | Basic signal handling |
| `sigaction` | Advanced signal handling |
| `sigemptyset` | Initialize signal set |
| `sigaddset` | Add signal to set |
| `kill` | Send signal to process |
| `getpid` | Get process ID |
| `malloc` / `free` | Memory allocation |
| `pause` | Wait for signal |
| `sleep` / `usleep` | Suspend execution |
| `exit` | Terminate process |

## 🧪 Testing

```bash
# Basic test
./client $(pgrep server) "Hello 42!"

# Long message test
./client $(pgrep server) "Lorem ipsum dolor sit amet, consectetur adipiscing elit."

# Empty string
./client $(pgrep server) ""

# Special characters (bonus)
./client_bonus $(pgrep server_bonus) "émojis: 🎉 中文 العربية"

# Stress test - rapid messages
for i in {1..10}; do ./client $(pgrep server) "Message $i"; done
```

## 📚 Skills Learned

- **UNIX Signals**: Understanding `SIGUSR1`, `SIGUSR2`, `sigaction`
- **Bitwise Operations**: Encoding/decoding data at the bit level
- **Process Communication**: IPC fundamentals
- **Binary Representation**: Converting characters to binary and back
- **Error Handling**: Managing signal reliability and edge cases

## ⚠️ Common Issues

| Issue | Solution |
|-------|----------|
| Messages corrupted | Add `usleep()` between signals to prevent signal loss |
| Server crashes | Ensure proper signal handler setup with `sigaction` |
| Unicode not working | Use bonus version with proper bit counting for multi-byte chars |

## 👤 Author

**Zouhair Grir**
- GitHub: [@GrirZouhair](https://github.com/GrirZouhair)
- 42 Intra: zogrir

## 📄 License

This project is part of the 42 school curriculum.

---

*Made with ❤️ at 42/1337*
