# Studio 0

## Intro to Multi-Paradigm Programming

In this studio, you will set up the programming environment used for the course, confirm that it is working correctly, and iteratively refine a simple C++ program to use additional language and library features.

The exercises assume use of `gcc 8.3.0` and the provided `Makefile`, which builds with the C++17 standard via `-std=c++17`. For more information about C++17 support in `g++`, see the [GCC C++ status page](https://gcc.gnu.org/projects/cxx-status.html#cxx17).

## Collaboration

You may complete this studio individually or in a small group.

## Exercises

Record your answers in `ANSWERS.md` as you work, and number your responses so they are easy to match to each exercise.

1. List the names of the people who worked together on this studio.

2. Connect to `shell.cec.wustl.edu` using your WUSTL Key credentials.

   On macOS or Linux, you can run `ssh` directly from a terminal. On modern Windows systems, you can use `ssh` directly from Windows Terminal or PowerShell.

   Be careful to specify your username explicitly, for example:

   ```bash
   ssh username@shell.cec.wustl.edu
   ```

   If repeated password attempts are a concern set up your SSH key first; see [Generating SSH Keys](docs/ssh_key_generation.md).

   Because compiles may be computationally intensive, do not run them on `shell.cec.wustl.edu`. Instead, run:

   ```bash
   qlogin
   ```

   This will connect you to a dedicated Linux host.

   As part of this exercise, record the hostname of the Linux lab machine you use. You can retrieve it with:

   ```bash
   hostname
   ```

3. Configure your environment to use `gcc 8.3.0` by running:

   ```bash
   module add gcc-8.3.0
   ```

   Also add that command as its own line at the end of `~/.bashrc`.

   Then confirm that the correct compiler is active:

   ```bash
   which g++
   g++ -v
   ```

   Record the output of both commands.

4. Follow [Setting Up SSH Keys for Git](docs/ssh-keys-guide.md) to set up GitHub SSH keys on the Linux server. Then, clone your `studio0` repo from the linux server and work inside that cloned directory.  

   The cloned repo already includes `studio0.cpp` and `Makefile`.

   Build the program:

   ```bash
   make
   ```

   Run the executable:

   ```bash
   ./studio0
   ```

   Record the compiler output and program output.

5. To modify source code in your cloned repo on the Linux server, you can use [remote-ssh from Visual Studio Code](https://code.visualstudio.com/docs/remote/ssh). If you prefer a different Integrated Development Environment (IDE), Google how to use remote-ssh from your preferred IDE. If you are comfortable using a terminal editor on Linix (vim, emacs, etc), you are welcome to use it to modify your code as well. 

   Modify `main` so its parameters are named `argc` and `argv`. Declare additional non-zero `const int` values that can be returned to report distinct failure modes.

   Update the program so that if no command-line arguments are provided, it prints a helpful usage message like:

   ```text
   usage: studio0 <arg1> [<arg2> ...]
   ```

   Return an appropriate non-zero error code in that case. Use `argv[0]` in the message rather than hard-coding the executable name.

   Compile and run the program with no arguments, then inspect the return value:

   ```bash
   echo $?
   ```

   Then run it again with one command-line argument and record both the program output and the returned value for each case.

6. Modify the program so that instead of writing to standard output, it treats each command-line argument as an output filename. For each filename, use an `ofstream` to open the file, write the same output as before, and close it.

   Add any additional non-zero error codes needed if a file cannot be opened.

   Test the program with the name of a file that does not yet exist. Confirm behavior by checking the return value and printing the resulting file contents:

   ```bash
   cat <filename>
   ```

   Then make the file read-only:

   ```bash
   chmod a-w <filename>
   ```

   Run the program again with that filename and confirm that it returns an appropriate error value. Record the returned values and resulting file contents after each run.

## Deliverables

Commit and push all modified and added files to the repo.
