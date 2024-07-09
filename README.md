# CSE-306-Computer-Architecture-Sessional
This is a repository containing all the simulations and reports of CSE-306 Computer Architecture Sessional.

## 4-bit ALU
**This ALU contains:**
- Two 4-bit inputs A and B
- Three control signals cs<sub>2</sub>, cs<sub>1</sub>, cs<sub>0</sub> as ALU opcodes
- One 4-bit output
- Four flags: C (Carry), S (Sign), V (Overflow), Z (Zero)

### Implemented functions and opcodes:
<p align="center">
<table>
<thead>
  <tr>
    <th style="text-align:center" colspan="3">Control Signals</th>
    <th style="text-align:center" rowspan="2">Functions</th>
  </tr>
  <tr>
    <th>cs<sub>2</sub></th>
    <th>cs<sub>1</sub></th>
    <th>cs<sub>0</sub></th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>AND</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>Sub</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>X</td>
    <td>Decrement A</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>Complement A</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>XOR</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>X</td>
    <td>Add</td>
  </tr>
</tbody>
</table>
</p>

### Truth table:
<p align="center">
<table>
<thead>
  <tr>
    <th style="text-align:center" colspan="3">Control Signals</th>
    <th style="text-align:center" rowspan="2">Required Outputs</th>
    <th style="text-align:center" colspan="3">Adder Inputs</th>
    <th style="text-align:center" rowspan="2">Functions</th>
  </tr>
  <tr>
    <th>cs<sub>2</sub></th>
    <th>cs<sub>1</sub></th>
    <th>cs<sub>0</sub></th>
    <th>X<sub>i</sub></th>
    <th>Y<sub>i</sub></th>
    <th>Z<sub>i</sub></th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>A AND B</td>
    <td>A<sub>i</sub></td>
    <td>B<sub>i</sub></td>
    <td>0</td>
    <td>AND</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>A - B</td>
    <td>A<sub>i</sub></td>
    <td>B<sub>i</sub>'</td>
    <td>1</td>
    <td>Sub</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>0</td>
    <td>A - 1</td>
    <td>A<sub>i</sub></td>
    <td>0</td>
    <td>1</td>
    <td>Decrement A</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>A'</td>
    <td>A<sub>i</sub></td>
    <td>1</td>
    <td>0</td>
    <td>Complement A</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>A XOR B</td>
    <td>A<sub>i</sub></td>
    <td>B<sub>i</sub></td>
    <td>0</td>
    <td>XOR</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>X</td>
    <td>A + B</td>
    <td>A<sub>i</sub></td>
    <td>B<sub>i</sub></td>
    <td>C<sub>i</sub></td>
    <td>Add</td>
  </tr>
</tbody>
</table>
</p>

### Simplified inputs to individual full adders:
X<sub>i</sub> = A(S<sub>1</sub>' + S<sub>2</sub> XOR B)

Y<sub>i</sub> = S<sub>2</sub>B

Z<sub>i</sub> = S<sub>1</sub>'C<sub>i</sub>

### Circuit diagram:
![4 bit ALU circuit diagram](1%20-%204%20bit%20ALU/4%20bit%20ALU%20circuit%20diagram.png)

### Flags:
- **Carry (C)**: Set if there is a carry out of the most significant bit.
- **Sign (S)**: Reflects the highest order bit of the result.
- **Overflow (V)**: Set if there is a signed overflow.
- **Zero (Z)**: Set if the result is zero.

## Floating Point Adder
The adder takes two 32 bit floating point numbers and adds them together. The numbers are represented in the following format:

|  Sign | Exponent |        Fraction        |
|:-----:|:--------:|:---------------------:|
| 1 bit |  12 bits | 19 bits (Lowest bits) |

The numbers are in normalized form. There are two flags U (underflow) and O (overflow) which are set if the result is too small or too large to be represented in the format.

### Flow chart:
<p align="center">
  <img src="2 - Floating Point Adder/floating_point_adder_flowchart.svg" height="1200em" alt="Floating point adder flow chart"></img>
</p>

### Circuit diagram:
![Floating point adder circuit diagram](2%20-%20Floating%20Point%20Adder/floating_point_adder_circuit_diagram.png)

### What individual components do:
- **Sign check**: Checks if a 32 floating point number is positive, negative or the exponent is zero. If the number is positive then the output is the same as input. If the number is negative then it outputs the two's complement of the input. And if the exponent is zero then the output is zero.
- **Normalizer**: Normalizes a floating point number. But if the number is overflowed or underflowed while trying to normalize then the appropriate flags are set.
- **Rounder**: Rounds the 32 bit significand to 19 bits.

## 4-bit MIPS Processor

### Design Specification:
- **Address Bus**: 8 bits
- **Data Bus**: 4 bits
- **Registers**: $zero, $t0, $t1, $t2, $t3, $t4 (all 4-bits)
- **Control Unit**: Microprogrammed, using Control Words stored in a special memory (EEPROM)

### Instruction Set:
- **Arithmetic Instructions**:
  - `add` (A): Adds two registers.
  - `addi` (B): Adds an immediate value to a register.
  - `sub` (C): Subtracts two registers.
  - `subi` (D): Subtracts an immediate value from a register.
- **Logical Instructions**:
  - `and` (E): Performs bitwise AND on two registers.
  - `andi` (F): Performs bitwise AND with an immediate value.
  - `or` (G): Performs bitwise OR on two registers.
  - `ori` (H): Performs bitwise OR with an immediate value.
  - `sll` (I): Shifts a register value left by a specified amount.
  - `srl` (J): Shifts a register value right by a specified amount.
  - `nor` (K): Performs bitwise NOR on two registers.
- **Memory Instructions**:
  - `lw` (L): Loads a word from memory to a register.
  - `sw` (M): Stores a word from a register to memory.
- **Control Instructions**:
  - `beq` (N): Branches if two registers are equal.
  - `bneq` (O): Branches if two registers are not equal.
  - `j` (P): Jumps to a specified address.

### MIPS Instruction Formats:
- **R-type**:
<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Src Reg 2</th>
    <th>Dst Reg</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- **S-type**:
<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Dst Reg</th>
    <th>Shamt</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- **I-type**:
<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Src Reg 2/Dst Reg</th>
    <th>Addr./Immdt.</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- **J-type**:
<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th style="text-align:center" colspan="2">Target Jump Address</th>
    <th>0</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td colspan="2">8-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>


### Instruction Set Assignment:
Each group has a specific assignment of instruction opcodes based on their section and group number. Refer to the provided assignment document for detailed opcode assignments.

### Additional MIPS Details:
The repository contains additional details and resources related to the 4-bit MIPS processor, including simulation files and implementation guides. You can explore these resources in the [Offline 3 - MIPS](https://github.com/Anonto050/CSE-306-Computer_Architecture/tree/main/Offline%203%20-%20MIPS) directory of the repository.

### Circuit Diagram:
![4-bit MIPS Circuit Diagram](3%20-%204%20bit%20MIPS%20processor/4-bit_mips_processor_circuit_diagram.png)
