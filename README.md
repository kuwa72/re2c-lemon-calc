# re2c-lemon-calc

Sample arithmetic calculator implementation using [re2c](https://re2c.org/) for lexical analysis and [Lemon](https://www.sqlite.org/lemon.html) for LALR parser generation in C.

## Overview

Demonstrates how to combine re2c and Lemon to parse and evaluate mathematical expressions from the command line.

## Building & Running

```bash
make
./calc "1 + 2 * (3 + 4)"
```
