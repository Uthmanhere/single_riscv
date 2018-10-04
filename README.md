# Single Cycle RISC-V Microarchitecture
## Directory Structure
    .
    ├── rtl                   # System Verilog RTL Code
    ├── tb                    # Verilator testbench
    ├── vsim                  # Cycle-Accurate Simulations
    └── README.md

## Verilator Simulation
### Prerequisites
Compile open source verilator from source code as described in [verilator installation](https://www.veripool.org/projects/verilator/wiki/Installing) official page

### Running Simulation
```
$ cd vsim
$ ./compile.sh <module>
$ ./V<module>

```

#### Example
```
$ cd vsim
$ ./compile.sh alu
$ ./Valu

```
