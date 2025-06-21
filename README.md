# 🔗 PIPEX

<img src="banner.svg" alt="PIPEX banner" />

## 📘 Overview

`pipex` is a project from the 42 curriculum that replicates a simple Unix shell behavior by executing commands connected by pipes (`|`). The goal is to simulate the following shell operation:

```bash
< infile cmd1 | cmd2 > outfile
```

It challenges students to work directly with system calls like `pipe`, `fork`, `dup2`, and `execve`, and to develop a deeper understanding of UNIX I/O, process management, and inter-process communication.

This repository includes:
- ✅ A mandatory version that handles two commands and a single pipe.
- ✨ A bonus version (optional) that supports multiple pipes and `here_doc`.

---

## 🚀 Features

- Execute two shell commands connected by a pipe.
- Proper file redirection for input and output files.
- Command path resolution using the `PATH` environment variable.
- Handles error reporting for invalid commands and missing files.
- Manages child processes and resources cleanly.
- Minimal memory footprint with no leaks (Valgrind clean).

---

## 🌟 Bonus Features (Optional)

- Support for unlimited number of piped commands:
  ```bash
  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  ```
- Support for **here_doc** syntax:
  ```bash
  ./pipex here_doc LIMITER cmd1 cmd2 outfile
  ```

---

## 🛠 Requirements

- A C compiler (`gcc`, `clang`, etc.)
- Must use allowed system calls only:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `access`, `dup`, `dup2`, `execve`, `pipe`, `fork`, `wait`, `waitpid`, `perror`, `strerror`
- **No memory leaks allowed**
- Bonus must support dynamic pipelines and heredoc syntax

---

## ⚙️ How to Compile

Clone and build the project using the provided `Makefile`:

```bash
git clone https://github.com/Nouvack/pipex.git
cd pipex
make
```

To clean object files:
```bash
make clean
```

To clean everything:
```bash
make fclean
```

To rebuild:
```bash
make re
```

---

## 📄 Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

### 🔁 Equivalent to:

```bash
< infile cmd1 | cmd2 > outfile
```

### ✅ Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

---

## 🧪 Testing Scenarios

| Test Case              | Description                                   | Expected Outcome               |
|------------------------|-----------------------------------------------|--------------------------------|
| Valid commands         | Normal redirection between cmd1 & cmd2        | Output in outfile              |
| Non-existent infile    | Should return error and exit gracefully       | Proper error message           |
| Invalid command        | Handles `command not found` errors            | Error output from shell        |
| Permissions error      | Denied access to read/write files             | Displays error using `perror`  |
| Empty file             | cmd1 receives no input                        | cmd2 handles accordingly       |
| Output redirection     | outfile is created or overwritten             | Result of pipeline stored      |
| Bonus: here_doc        | Accepts input until LIMITER is reached        | Then proceeds like a pipe      |

---

## 📂 Project Structure

```
pipex/
├── src/
│   ├── pipex.c           # Core pipeline logic
│   ├── pipex_utils.c     # Command parsing & execution
│   └── aux_utils.c       # Additional helper functions
├── lib/
│   └── LIBFT/            # Custom libft functions
├── include/
│   └── pipex.h           # Header file with prototypes
├── Makefile
```

---

## 🧠 What I Learned

- 🔄 How processes communicate via pipes in UNIX
- 🔧 Using `dup2()` for file descriptor manipulation
- 🔍 Searching `PATH` for executable commands
- 🧼 Managing dynamic memory and avoiding leaks
- 🧵 Using `fork()` and synchronizing with `waitpid()`

---

## 👨‍💻 Author

**Name:** Noam Novack  
**GitHub:** [Nouvack](https://github.com/Nouvack)  
**42 Login:** nsantand

---

## 🙌 Acknowledgments

Special thanks to 42 School for providing rigorous, real-world inspired projects that deepen understanding of system-level programming.

This project was proudly developed as part of the 42 Common Core.  
Crafted with `pipe()`, `fork()` and lots of `💻`.
