# Hamming Code and CRC

This README.md provides an overview of Hamming Code and Cyclic Redundancy Check (CRC), along with algorithms and examples for each.

## Hamming Code

### Introduction

Hamming Code is an error-correcting code used to detect and correct errors in data transmission. It was developed by Richard W. Hamming in the early 1950s. Hamming Codes are particularly useful in situations where data integrity is critical, such as in computer memory systems and digital communication.

### Algorithm

The Hamming Code algorithm adds redundant bits to the original data to create a code word. These redundant bits help in error detection and correction. Here's a simplified algorithm to encode and decode using a (7, 4) Hamming Code:

#### Encoding Algorithm

1. Take the 4-bit data you want to send.
2. Calculate the number of redundant bits required (in this case, 3).
3. Create a data word by placing the redundant bits at positions 2^0, 2^1, 2^2 in the code word.
4. Set the redundant bits to ensure that the parity checks are satisfied.
5. The resulting 7-bit code word is ready for transmission.

#### Decoding Algorithm

1. Receive the 7-bit code word.
2. Perform parity checks at positions 1, 2, and 4.
3. Identify the position of the error, if any.
4. Correct the error, if possible, using the redundant bits.
5. Retrieve the original 4-bit data.

### Example

Let's encode the data "1101" using a (7, 4) Hamming Code:

**Encoding:**

Data: 1101

1. Calculate the number of redundant bits needed: 3.
2. Create the code word with the redundant bits: 0 1 1 0 1 0 1.
3. Set the redundant bits to satisfy the parity checks:

   - Parity bit at position 1 (1st bit): Set to 1 (odd parity).
   - Parity bit at position 2 (2nd bit): Set to 0 (even parity).
   - Parity bit at position 4 (4th bit): Set to 0 (even parity).

The final code word is: 1011010

## CRC (Cyclic Redundancy Check)

### Introduction

A Cyclic Redundancy Check (CRC) is a type of error-detecting code that is widely used in data transmission. It detects changes to raw data by appending a checksum to the data. If the data changes during transmission, the receiver can detect it and request a retransmission.

### Algorithm

The CRC algorithm is based on polynomial division. Here's a high-level overview of the CRC algorithm:

#### Generating a CRC

1. Choose a polynomial, often represented as a binary number.
2. Append a fixed number of zeros (the "divisor") to the data.
3. Perform binary polynomial division.
4. Append the remainder to the original data to create the CRC.

#### Verifying a CRC

1. Receive the data with the CRC appended.
2. Append the same fixed number of zeros (the "divisor") to the data.
3. Perform binary polynomial division.
4. If the remainder is zero, the data is likely intact.

### Example

Let's calculate a CRC for the data "101110" using a simple 3-bit CRC:

**Generating a CRC:**

Data: 101110
CRC Polynomial: 101 (in binary)

1. Append three zeros to the data: 101110000.
2. Perform binary polynomial division:

```
101110000
101
000


```