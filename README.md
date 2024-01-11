# Directory

#Description

This program is a simple, yet effective directory listing utility written in C. It's designed to recursively list all files and subdirectories within a specified directory. The utility uses standard libraries like stdio.h, string.h, dirent.h, and sys/stat.h to accomplish its task. It's particularly useful for getting a detailed view of the directory structure and contents, making it an essential tool for system administrators, developers, or anyone who needs to manage files and directories.

#Features

Recursive Listing: Capable of traversing through all levels of directories and subdirectories.
Formatted Output: Neatly formats the directory and file names for easy readability.
Error Handling: Includes basic error handling to manage scenarios where directories can't be read.
Portable Code: Written in standard C, making it compatible with various operating systems that support C compilers.
Customizable Indentation: The output is indented to reflect the depth of directories, which can be easily modified for different visual preferences.

#How to Use

Compilation: To use this utility, first compile the code using a C compiler. For example, you can use gcc:
gcc -o listFiles listFiles.c
Replace listFiles.c with the name of your source file.

Execution: Run the compiled program from the command line. You can specify the directory to start listing from:
If no directory is specified, it defaults to the current directory.

Output: The program will list all files and directories starting from the specified directory, showing the structure in a tree-like format.

Error Messages: If the program encounters a directory it cannot open, it will output an error message and continue with other directories.
