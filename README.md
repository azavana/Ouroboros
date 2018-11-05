# Ouroboros

Multiple encryption program based on RC4A (Upadted version of RC4 by Souradyuti Paul and Bart Preneel), Spritz (Updated redesign of RC4 by Ronald Rivest), SHA-512 and SHA-384.

# How it works

- 1) The program takes a clear message as an input
- 2) Perform the RC4A_Spritz encryption (using Kratos_Encrypt function)
- 3) Perform SHA-512
- 4) Perform SHA-384 (Final stage)
- 5) Swap the characters of the final stage and output the result

Only the final result is outputted
