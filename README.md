# 🚀 PIPEX

`pipex` is a 42 school project that replicates the behavior of the Unix shell using pipes (`|`). Its goal is to execute two commands connected via a pipe, correctly redirecting standard input and output between files and processes.

---

## 🎯 Project Objectives

- Use of `fork`, `execve`, `pipe`, `dup2`, `waitpid`
- File descriptor manipulation
- Standard input/output redirection
- Command path resolution using `PATH`
- Error and permission handling
- Memory and resource management

---

## ⚙️ Compilation

Use the provided `Makefile`:

```bash
make
```

To clean object files:

```bash
make clean
```

To fully clean the project:

```bash
make fclean
```

---

## 🧪 Usage

Run the binary using the following syntax:

```bash
./pipex input_file "command1" "command2" output_file
```

📌 **Example:**

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

This is equivalent to:

```bash
< input.txt grep hello | wc -l > output.txt
```

---

## 🗂️ Project Structure

```
pipex/
├── src/
│   ├── pipex.c
│   ├── pipex_utils.c
│   └── aux_utils.c
├── lib/
│   └── LIBFT/         # Custom library (libft)
├── pipex.h            # Main header
├── Makefile
```

---

## ❌ Error Handling

- Invalid commands
- Non-existent or inaccessible files
- Incorrect usage
- Execution and access verification for binaries

---

## 👤 Author

- **Noam Novack**  
- GitHub: [Nouvack](https://github.com/Nouvack)  
- 42 login: `nsantand`

---

## 🧾 License

This project was developed for educational purposes as part of the 42 school curriculum.
