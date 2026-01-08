# Digital Electronics Project – Sequence Detector (C++)

This project is developed for the Digital Electronics course. The purpose of the project is to generate the state transition table and the state encoding table for a finite state machine (FSM) used in a binary input sequence detection problem, where the input signal is denoted as w.

All source code in this project is written entirely by the author.

The project is implemented in C++ and is intended for educational purposes.

Project structure:
- main.cpp : Main program
- gen_state_table.cpp  : FSM logic and state transition implementation
- gen_state_table.h    : State definitions and function declarations
- app.exe : Precompiled executable file for Windows

Requirements:
- Operating system: Windows
- Compiler (optional, for rebuilding): g++ (MinGW / MSYS2 / Dev-C++) or Microsoft Visual Studio

Clone the repository:
git clone https://github.com/datth235/Digital-Electronics.git

cd Digital-Electronics

Run the program (without recompiling):
app.exe

Build from source:
g++ main.cpp gen_state_table.cpp -o app
app

Program output:
- State transition table (present state, next state for w = 0 and w = 1)
- State encoding table (binary representation of states)
- Output values corresponding to each state

Notes:
- The executable file works only on Windows
- Recompiling is recommended after modifying the source code
- This project focuses on FSM analysis and state encoding, not hardware implementation

Author:
Dat Nguyen Thanh - ET05 - K68

License:
This project is intended for educational purposes only. Commercial use is not permitted.
