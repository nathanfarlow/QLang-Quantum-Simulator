#pragma once

#include <string>
#include <unordered_map>

#include "quantum.h"

namespace quantum {

    struct QDefinition {
        std::string id;
        size_t num_parameters;
        QState op;

        QDefinition(std::string id, size_t num_parameters, QState op)
            : id(id), num_parameters(num_parameters), op(op) {}

        QDefinition() : op(1, 1) {}
    };

    struct QOperation {
        QDefinition def;
        size_t q1, q2;

        QOperation(QDefinition def, size_t q1, size_t q2)
            : def(def), q1(q1), q2(q2) {}
    };

    extern std::unordered_map<std::string, QDefinition> definitions;

}