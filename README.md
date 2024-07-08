# CSE 306: Computer Architecture

Welcome to the repository for CSE 306: Computer Architecture. This repository contains the codes and designs for various computer architecture assignments.

## Getting Started

### Prerequisites
Ensure you have the following installed on your local machine:
- GCC Compiler
- Make

### How to Run

1. **Clone the Repository**: 
    ```sh
    git clone https://github.com/Anonto050/CSE-306-Computer_Architecture.git
    ```
2. **Navigate to the Assignment Directory**: 
    ```sh
    cd CSE-306-Computer_Architecture/assignment-folder
    ```
3. **Compile the Code**: 
    ```sh
    make
    ```
4. **Run the Executable**: 
    ```sh
    ./output-executable
    ```

## Assignment Details

### Offline 1: ALU Design
- **Description**: Design and implementation of an Arithmetic Logic Unit (ALU).
- **Files**:
  - [Source Code](Offline%201%20-%20ALU/)
  - [Design Document](Offline%201%20-%20ALU/design.pdf)

### Offline 2: Floating Point Adder
- **Description**: Implementation of a Floating Point Adder. This assignment involves the design of a floating point adder that performs addition operations on floating point numbers following IEEE 754 standard. The solution handles normalization, rounding, and exceptions such as overflow and underflow.
- **Files**:
  - [Source Code](Offline%202%20-%20FP%20Adder/)
  - [Design Document](Offline%202%20-%20FP%20Adder/design.pdf)
- **Solution Breakdown**:
  - **Normalization**: Aligning the exponents of the two numbers.
  - **Addition/Subtraction**: Performing the arithmetic operation.
  - **Rounding**: Rounding the result to fit the precision limits.
  - **Handling Exceptions**: Managing overflow and underflow scenarios.

### Offline 3: MIPS Architecture
- **Description**: MIPS processor simulation. This assignment includes the design and implementation of a MIPS processor simulation that can execute a subset of the MIPS instruction set. The solution involves the creation of a data path and control unit to handle various instructions.
- **Files**:
  - [Source Code](Offline%203%20-%20MIPS/)
  - [Design Document](Offline%203%20-%20MIPS/design.pdf)
- **Solution Breakdown**:
  - **Instruction Fetch**: Retrieving instructions from memory.
  - **Instruction Decode**: Decoding the fetched instruction.
  - **Execution**: Performing arithmetic or logical operations.
  - **Memory Access**: Reading from or writing to memory.
  - **Write Back**: Writing the result back to the register file.


## Additional Information
For further details and instructions, refer to the individual assignment folders and design documents. If you have any questions or need assistance, feel free to reach out.

## Authors
- [Anonto050](https://github.com/Anonto050)


---

Happy coding!
