#include "qoperation.h"

namespace quantum {

    std::unordered_map<std::string, QDefinition> definitions = {

        //Identity matrix
        {"ID", QDefinition("ID", 1, QState({{1, 0},
                                           {0, 1}}))},

        //Controlled not
        {"CNOT", QDefinition("CNOT", 2, QState({{1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 0, 1},
                                               {0, 0, 1, 0}}))},

        //Hadamard gate
        {"H", QDefinition("H", 1, QState({{1, 1},
                                         {1, -1}}) * (1.0/sqrt(2)))},

        //Pauli X operator
        //Also the not operator
        {"X", QDefinition("X", 1, QState({{0, 1},
                                         {1, 0}}))},

        //Pauli Y operator
        {"Y", QDefinition("Y", 1, QState({{0, complex(0, -1)},
                                         {complex(0, 1), 0}}))},

        //Pauli Z operator
        {"Z", QDefinition("Z", 1, QState({{1, 0},
                                         {0, -1}}))}

    };

}