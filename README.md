# Pipex

<img src="banner_pipex.svg" alt="PIPEX banner" />

## 📘 Overview

`pipex` is a project from the 42 curriculum that introduces you to the fundamental concepts of UNIX inter-process communication using **pipes**. The goal is to recreate the shell's behavior by connecting the output of one command to the input of another using `fork`, `execve`, `pipe`, and `dup2`.

This repository includes:
- ✅ A working version that mimics the behavior of `cmd1 | cmd2` with file redirection.
- ✨ Modular design, robust error handling, and `libft` integration.

## 🚀 Features

- Emulates the shell behavior: `./pipex infile "cmd1" "cmd2" outfile`.
- Uses `pipe()` to connect processes.
- Redirects `stdin` and `stdout` via `dup2()`.
- Executes commands with `execve()`.
- Automatically searches `PATH` for executables.
- Detailed error management and memory safety (no leaks).
- Compatible with commands that include flags (e.g., `"ls -l"`).

## 🛠 Requirements

- A C compiler (`gcc`)
- Unix-like system (Linux/macOS)
- Make

## ⚙️ Compilation

```bash
git clone https://github.com/Nouvack/pipex.git
cd pipex
make
```

## 🧪 How to Use

```bash
./pipex infile "cmd1 args" "cmd2 args" outfile
```

### 📄 Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

Equivalent to:

```bash
< input.txt grep hello | wc -l > output.txt
```

### Bonus

If you implement the bonus (`pipex_bonus.c`), you can handle multiple commands including `here_doc` support:

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" ... outfile
```

## 📂 Project Structure

```
📁 src/
  ├─ pipex.c             # main pipe logic
  ├─ pipex_utils.c       # utilities like path handling and error messages
  ├─ aux_utils.c         # helper functions (split, free, etc.)
📁 lib/LIBFT/            # your custom libft implementation
📄 pipex.h               # main header file
📄 Makefile              # build automation
```

## 📦 Output Example

```bash
$ cat infile.txt
hello world
hello shell

$ ./pipex infile.txt "grep hello" "wc -l" outfile.txt

$ cat outfile.txt
2
```

## 🧠 What I Learned

- 🔁 Process communication using `pipe()` and `fork()`
- 🧵 File descriptor manipulation via `dup2()`
- 🧪 System-level error handling with `perror` and `errno`
- 📁 Parsing `PATH` and safely executing with `execve`
- ⚙️ Code modularization and custom library usage (`libft`)

## 🧑‍💻 Author

**Name:** Noam Novack  
**GitHub:** [Nouvack](https://github.com/Nouvack)  
**42 Login:** nsantand

## 🙌 Acknowledgments

Thanks to 42 School for encouraging hands-on learning with real system-level challenges.  
This project is part of the 42 **Common Core** curriculum and was coded with care and `malloc()` love.
