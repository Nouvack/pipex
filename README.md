# 🔧 PIPEX – A Unix Shell Pipe Emulator

Welcome to **PIPEX**, a project developed as part of the curriculum at [42 School](https://42.fr/). This program emulates the behavior of Unix shell pipelines, enabling the redirection of input and output streams between commands and files, mimicking the following shell behavior:

```bash
< infile command1 | command2 > outfile
```

---

## 📚 Learning Objectives

This project demonstrates proficiency in low-level system programming using:

- Process creation and synchronization (`fork`, `waitpid`)
- Inter-process communication with `pipe`
- File descriptor duplication with `dup2`
- Executing programs via `execve`
- Command resolution using the `PATH` environment variable
- Advanced file and error handling
- Manual memory management

---

## 🧠 Project Overview

`pipex` takes four arguments:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

It performs the following operations:
1. Opens the `infile` and redirects it to `stdin`.
2. Executes `cmd1`, writing its output to a pipe.
3. Executes `cmd2`, reading input from that pipe.
4. Writes the final output to `outfile`.

---

## 🛠️ Compilation

Compile the project with:

```bash
make
```

Available Makefile targets:

| Command         | Description                  |
|----------------|------------------------------|
| `make`         | Compiles the project         |
| `make clean`   | Removes object files         |
| `make fclean`  | Removes binaries and objects |
| `make re`      | Recompiles from scratch      |

---

## 🚀 Usage Examples

```bash
./pipex input.txt "grep 42" "wc -l" output.txt
```

This command emulates the shell instruction:

```bash
< input.txt grep 42 | wc -l > output.txt
```

More examples:

```bash
./pipex lorem.txt "cat" "wc -w" words.txt
./pipex data.csv "tail -n +2" "cut -d, -f2" result.txt
```

---

## 📁 Project Structure

```
pipex/
├── src/
│   ├── pipex.c           # Core logic
│   ├── pipex_utils.c     # Helper functions
│   └── aux_utils.c       # Extra utilities
├── lib/
│   └── LIBFT/            # Custom C standard library (libft)
├── include/
│   └── pipex.h           # Main header
├── Makefile
```

---

## 🔍 Error Handling

The program gracefully handles:

- Missing or invalid arguments
- File permission errors
- Command not found in `PATH`
- Failed system calls (`open`, `dup2`, `pipe`, `fork`, etc.)

Descriptive error messages are displayed using `perror` or custom messages.

---

## 🧪 Testing

You can test `pipex` by comparing its output with the shell pipeline equivalent:

```bash
diff <(./pipex infile "cmd1" "cmd2" outfile) <( < infile cmd1 | cmd2 > outfile )
```

This is a good way to verify correctness of redirection and execution flow.

---

## 🧠 Bonus Ideas

To go beyond the basics, you can implement:

- Support for multiple pipes (i.e., more than two commands)
- Handling quoted arguments correctly
- Here-doc (`<<`) support
- Robust `PATH` resolution

---

## 👨‍💻 Author

**Noam Novack**  
📎 GitHub: [@Nouvack](https://github.com/Nouvack)  
🏫 42 Login: `nsantand`

---

## 📜 License

This project was created for academic purposes as part of the 42 School program.  
Feel free to explore, fork, and learn from it.
