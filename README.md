# otter
This project is designed to scoring exam results in a Linux environment. It provides simple commands to calculate scoring results for submitted sources.

## Install and Setting
1. Download the program, then unzip it.
2. Build the program using cmake.
3. [Option] Modify the bashrc file to alias it.

## Usage
This project has two features One is to compare the result with the expectation for a single test case, and the other is to perform the above operation for multiple test cases. The commands are as follows:
```bash
otter source_file input_file output_file    // single testcase

otter -d source_file input_dir/ output_dir/ // multi-testcase
```
The result of the above command is the total number of test cases and the number of correct and incorrect test cases.

## License
[LGPL-2.1](https://github.com/quixote2871/otter/blob/main/LICENSE)
