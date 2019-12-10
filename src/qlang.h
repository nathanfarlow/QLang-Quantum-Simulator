#pragma once

#include "qcircuit.h"

namespace quantum {
    class QLangParser {
    public:
        QCircuit *Compile(std::string source);
    };
}
