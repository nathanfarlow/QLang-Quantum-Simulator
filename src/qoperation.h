#pragma once

#include <string>
#include <unordered_map>

#include "quantum.h"

namespace quantum {

    struct QDefintion {
        std::string id;
        size_t num_parameters;
        QState op;

        QDefintion(std::string id, size_t num_parameters, QState op)
            : id(id), num_parameters(num_parameters), op(op) {}

        QDefintion() : op(1, 1) {}
    };

    struct QOperation {
        QDefintion op;
        size_t q1, q2;

        QOperation(QDefintion op, size_t q1, size_t q2)
            : op(op), q1(q1), q2(q2) {}
    };

    extern std::unordered_map<std::string, QDefintion> definitions;

}