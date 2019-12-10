#pragma once

#include <string>
#include <unordered_map>

#include "quantum.h"

namespace quantum {

    struct QOperation {
        std::string id;
        size_t num_parameters;
        QState op;

        QOperation(std::string id, size_t num_parameters, QState op)
            : id(id), num_parameters(num_parameters), op(op) {}
    };

    std::unordered_map<std::string, QOperation> operations = {

        //Identity matrix
        {"ID", QOperation("ID", 1, QState({{1, 1},
                                           {1, 1}}))},

        //Controlled not
        {"CNOT", QOperation("CNOT", 2, QState({{1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 0, 1},
                                               {0, 0, 1, 0}}))},

        //Hadamard gate
        {"H", QOperation("H", 1, QState({{1, -1},
                                         {1, 1}}) * (1.0/sqrt(2)))},

        //Pauli X operator
        //Also the not operator
        {"X", QOperation("X", 1, QState({{0, 1},
                                         {1, 0}}))},

        //Pauli Y operator
        {"Y", QOperation("Y", 1, QState({{0, complex(0, -1)},
                                         {complex(0, 1), 0}}))},

        //Pauli Z operator
        {"Z", QOperation("Z", 1, QState({{1, 0},
                                         {0, -1}}))}
    };

}