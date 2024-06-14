# Sikraken: A Test Suites Generator for C Code

**Sikraken** is a new test data generator project for C code started in June 2024 by Dr Christophe Meudec, echancrure@gmail.com.
It is developed as a side project in an agile way by a team of one, part time; so don't expect miracles.

It reuses bits and pieces from other projects:
  - a parser for C using lex/yacc (Flex/Bison flavour);
  - a symbolic executor written in Prolog (ECLiPSe flavour);
  - a solver [PTC-Solver](https://github.com/echancrure/PTC-Solver) which uses Constraint Logic Programming (ECLiPSe flavour).
The initial goal is to move towards tackling [Test-Comp benchmarks](https://test-comp.sosy-lab.org/) in an agile way.

## Development Log
**14 June 2024** Sikraken can handle RegressionTests/get_sign.c
