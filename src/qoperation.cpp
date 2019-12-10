#include "qoperation.h"

namespace quantum {

    std::unordered_map<std::string, QDefintion> definitions = {

        //Identity matrix
        {"ID", QDefintion("ID", 1, QState({{1, 0},
                                           {0, 1}}))},

        //Controlled not
        {"CNOT", QDefintion("CNOT", 2, QState({{1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 0, 1},
                                               {0, 0, 1, 0}}))},

        //Hadamard gate
        {"H", QDefintion("H", 1, QState({{1, -1},
                                         {1, 1}}) * (1.0/sqrt(2)))},

        //Pauli X operator
        //Also the not operator
        {"X", QDefintion("X", 1, QState({{0, 1},
                                         {1, 0}}))},

        //Pauli Y operator
        {"Y", QDefintion("Y", 1, QState({{0, complex(0, -1)},
                                         {complex(0, 1), 0}}))},

        //Pauli Z operator
        {"Z", QDefintion("Z", 1, QState({{1, 0},
                                         {0, -1}}))}
        
    };

}