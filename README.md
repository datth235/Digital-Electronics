# Digital Electronics -- Sequence Detector (C++)

This project is developed for the **Digital Electronics** course.\
The goal of the project is to generate and analyze the **Finite State
Machine (FSM)** used for a **binary sequence detection problem**, where
the input signal is denoted as `w`.

The program automatically generates:

-   **State transition table**
-   **State encoding table**
-   **FSM graph visualization (Moore / Mealy)**
-   **Output values for each state**

All source code in this repository is written entirely by the author.

This project is intended for **educational purposes only**.

------------------------------------------------------------------------

# Features

-   Generate **FSM state transition table**
-   Generate **state encoding table**
-   Support for both **Moore FSM** and **Mealy FSM**
-   Export FSM diagrams using Graphviz
-   Save FSM diagrams as images

------------------------------------------------------------------------

# Project Structure

    Digital-Electronics
    │
    ├── image/                # Generated FSM images
    │
    ├── main.cpp              # Main program
    ├── gen_state_table.cpp   # FSM generation logic
    ├── gen_state_table.h     # FSM structures and declarations
    ├── fsm_graphviz.cpp      # Graphviz export implementation
    ├── fsm_graphviz.h        # Graphviz interface
    │
    ├── app.exe               # Precompiled Windows executable
    ├── Makefile              # Build automation (Linux / WSL)
    └── README.md

------------------------------------------------------------------------

# Requirements

Operating System:

-   Windows
-   Linux / WSL (recommended)

Compiler:

-   g++ (MinGW / MSYS2 / Dev-C++ / GCC)

Additional tool (for FSM visualization):

-   Graphviz

Install Graphviz on Linux / WSL:

    sudo apt install graphviz

------------------------------------------------------------------------

# Clone the Repository

    git clone https://github.com/datth235/Digital-Electronics.git
    cd Digital-Electronics

------------------------------------------------------------------------

# Run the Program (Windows)

If you do not want to recompile:

    app.exe

------------------------------------------------------------------------

# Build from Source

Compile manually:

    g++ main.cpp gen_state_table.cpp fsm_graphviz.cpp -o app

or using Makefile:

    make

Run the program:

    ./app

------------------------------------------------------------------------

# Program Output

The program generates:

1.  **State Transition Table**
    -   Present state
    -   Next state for `w = 0`
    -   Next state for `w = 1`
2.  **State Encoding Table**
    -   Binary encoding of each state
3.  **FSM Graph**
    -   Automatically generated using Graphviz
    -   Saved in the `Image/` directory

------------------------------------------------------------------------

# Example Output

    State Transition Table

    Present State | w=0 | w=1
    --------------------------
    A0            | A0  | A1
    A1            | A0  | A2
    A2            | A3  | A1
    ...

Generated FSM diagram:

    Image/....png

------------------------------------------------------------------------

# Notes

-   The provided executable works **only on Windows**
-   Recompiling is recommended after modifying the source code
-   This project focuses on **FSM analysis and state encoding**, not
    hardware implementation

------------------------------------------------------------------------

# Author

**Dat Nguyen Thanh**\
ET1 -- 05 -- K68 \
HaNoi University of science and technology

------------------------------------------------------------------------

# License

This project is intended **for educational purposes only**.\
Commercial use is **not permitted**.
