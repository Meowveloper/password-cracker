### How the Final System Will Be Used:

#### Step 1: Open the Command Line

The user will start by opening a terminal or command prompt. All interactions will happen here.

#### Step 2: Choose an Attack

The user decides how they want to crack the password hash.

**Option A: Dictionary Attack (Cracking with a wordlist)**

If the user has a list of common passwords (a "dictionary" or "wordlist"), they will use this mode.

*   **What they'll type:**
    ```bash
    ./password-cracker -d <HASH_TO_CRACK> /path/to/their/wordlist.txt
    ```
    For example:
    ```bash
    ./password-cracker -d 5d41402abc4b2a76b9719d911017c592 /home/user/downloads/rockyou.txt
    ```

**Option B: Brute-Force Attack (Trying every combination)**

If the user doesn't have a wordlist, they can tell the program to try every possible combination of letters, numbers, and symbols.

*   **What they'll type:**
    ```bash
    ./password-cracker -b <HASH_TO_CRACK>
    ```

#### Step 3: Watch the Progress

As the program runs, it will provide real-time feedback, so the user knows it's working.

*   For a dictionary attack, it might show: `Trying word: "password123"...`
*   For a brute-force attack, it might show: `Current attempt: "aT5!g"...`

#### Step 4: Get the Result

When the program is finished, it will display a clear result.

*   **If successful, it will show:**
    ```
    Success!
    Hash: 5d41402abc4b2a76b9719d911017c592
    Password: hello
    ```
*   It will also provide a summary report, like:
    ```
    Time Elapsed: 15.2 seconds
    Cracking Speed: 5,234 hashes per second
    ```

#### Advanced Use: Auditing Multiple Passwords

The system will also have a powerful "audit" mode for checking the strength of many passwords at once.

1.  The user will have a file (`passwords.txt`) containing many hashes.
2.  They will run a command like:
    ```bash
    ./password-cracker --audit /path/to/passwords.txt /path/to/wordlist.txt
    ```
3.  The program will then try to crack all the hashes in the file and generate a final report that gives an overall "password strength score" and recommendations for improvement.