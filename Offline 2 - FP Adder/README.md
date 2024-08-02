# Floating Point Adder

## Overview

This project demonstrates the implementation of a floating point adder, and this readme focuses on handling the exponent part of the floating point numbers. The adder aligns the mantissas of the two numbers by adjusting the exponent, performs the addition, and then normalizes the result.

## Exponent Handling Circuit

### Initial Exponent Handling Circuit

The first design of the exponent handling circuit (shown below) compares the exponents of two floating point numbers \(X\) and \(Y\) to determine the larger exponent and the difference between them. However, this design misses some corner cases, particularly when the difference between the exponents becomes significantly negative.

![image](https://github.com/user-attachments/assets/b21c28c0-d649-415a-b588-379325657ecc)


### Enhanced Exponent Handling Circuit

To address the missing corner cases, an additional part was added to the circuit. This enhancement ensures that if the exponent difference is significantly negative, the circuit can handle it properly by making the difference positive and finding the correct maximum shift amount. The additional logic adjusts the exponent difference and ensures proper alignment of the mantissas.

![image](https://github.com/user-attachments/assets/2bf2e4b4-365d-41fb-b973-518d20ee3693)


## Key Features

1. **Comparison and Selection**: The circuit accurately determines the larger exponent and calculates the difference.
2. **Handling Corner Cases**: The additional circuit handles situations where the exponent difference becomes significantly negative.
3. **Normalization**: The circuit normalizes the result by adjusting the mantissas accordingly.

## Summary

The floating point adder project, particularly the exponent handling circuits, demonstrates a robust solution for aligning the mantissas of two floating point numbers. The enhanced circuit addresses critical corner cases, ensuring accurate floating point addition even in edge cases. This project showcases fundamental digital logic design skills, essential for implementing floating point arithmetic in hardware.
