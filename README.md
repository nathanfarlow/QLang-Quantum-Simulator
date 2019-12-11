# QLang quantum simulator

![gui](https://github.com/CS126FA19/fantastic-finale-nathanfarlow/blob/master/img/screenshot.png "GUI")

# Build
```
git clone https://github.com/CS126FA19/fantastic-finale-nathanfarlow
cd fantastic-finale-nathanfarlow
make
```

# Run
```
cd fantastic-finale-nathanfarlow
bin/quantum
```

# Usage
Type your QLang code into the left input box. Press the compile button, and the output box on the right will print the resulting state vector.

# QLang
## Initialize
Valid QLang programs must start with a circuit declaration. Declare a circuit with `circuit n 01011...` where n is the number of qubits in the system and 01011... is a bitstring to initialize the state. The bitstring is optional, and without it the state will be initialized to |0>. Example:
```
;Create a circuit with 2 quibits, in the state |01>
circuit 2 01
```

## Comments
Declare a comment with `;`.

## Gates

Apply gates with `gate qubit1 qubit2... qubitn` where gate is the name of the gate and the parameters are integers denoting which qubit(s) to operate on with the gate. Example:
```
;Initialize circuit
circuit 2

;Apply the Hadamard gate to the 0th qubit
h 0
;Apply the controlled not gate with qubit 0 as the control and qubit 1 as the target
cnot 0 1
```

Currently supported gates are the following:

| Gate      | Parameters               | Description                  |
|-----------|--------------------------|------------------------------|
| `ID`      | 1                        | Does nothing to qubit state  |
| `H`       | 1                        | Hadamard gate                |
| `X`       | 1                        | Pauli X gate (not gate)      |
| `Y`       | 1                        | Pauli Y gate                 |
| `Z`       | 1                        | Pauli Z gate                 |
| `CNOT`    | 2                        | Conditional not gate         |
