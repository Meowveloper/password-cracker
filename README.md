# C-Based Password Cracker

This project is an educational tool developed to explore and understand the principles behind password cracking through common attack vectors. It is implemented in C for performance and provides a command-line interface for operation.

## Features

*   **Dictionary Attack:** Cracks hashes by iterating through a provided wordlist.
*   **Brute-Force Attack:** Systematically generates and tests all possible character combinations up to a specified length.
*   **MD5 Hashing Support:** Currently supports the cracking of MD5 hashes.
*   **Performance Reporting:** Provides a summary upon completion, including total time, attempts, and cracking speed (hashes per second).

## Build Instructions

The project uses a standard `Makefile` for compilation. Ensure you have `gcc` and `make` installed.

1.  **Navigate to the project directory:**
    ```bash
    cd password-cracker
    ```

2.  **Compile the source code:**
    ```bash
    make
    ```
    This will generate a native executable named `password-cracker` in the same directory.

## Usage

The application is controlled via command-line arguments.

### Dictionary Attack

To run a dictionary attack, you need to provide the target hash and the path to a wordlist file.

**Syntax:**
```bash
./password-cracker -d <HASH_TO_CRACK> /path/to/wordlist.txt
```

**Example:**
```bash
./password-cracker -d 5d41402abc4b2a76b9719d911017c592 ./rockyou.txt
```

### Brute-Force Attack

To run a brute-force attack, you only need to provide the target hash.

**Syntax:**
```bash
./password-cracker -b <HASH_TO_CRACK>
```

**Example:**
```bash
./password-cracker -b 5d41402abc4b2a76b9719d911017c592
```

---

## Wordlists for Dictionary Attack

### The `rockyou.txt` Wordlist

The dictionary attack's effectiveness is highly dependent on the quality of the wordlist used. For this project, we use `rockyou.txt`, one of the most famous and effective real-world password lists. It was sourced from a 2009 data breach and contains over 14 million unique passwords.

Using this list allows for a realistic simulation of how a dictionary attack would perform against a set of compromised hashes.

### Downloading and Using `rockyou.txt`

The wordlist can be downloaded and extracted using the following commands:

1.  **Download the compressed file:**
    ```bash
    wget https://github.com/danielmiessler/SecLists/raw/master/Passwords/Leaked-Databases/rockyou.txt.tar.gz
    ```

2.  **Extract the archive:**
    ```bash
    tar -xvzf rockyou.txt.tar.gz
    ```

This will produce the `rockyou.txt` file, which can then be used as the wordlist for the dictionary attack mode.
