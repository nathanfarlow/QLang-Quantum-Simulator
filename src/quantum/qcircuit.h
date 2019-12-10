#pragma once

#include "quantum.h"
#include "qoperation.h"


namespace quantum {

    size_t pow(size_t a, size_t b);

    class QCircuit {
    private:
        size_t num_qubits_;

        std::vector<QOperation> operations_;

    public:
        QState state_;

        QCircuit(size_t num_qubits)
            : num_qubits_(num_qubits), state_(pow(2, num_qubits), 1) {}

        //Swap two qubits
        void Swap(QState &state, size_t q1, size_t q2);
        //Initialize qubits to all 100% 0
        void InitZero();
        //Initialize state with a string of classical bits
        void Init(std::string cbits);
        //Add an operation to the schedule
        void AddOperation(QOperation operation);
        //Compute the output state vector
        QState Compute();

        size_t get_num_qubits() {return num_qubits_;}
    };

}
