#pragma once

#include "qcircuit.h"

namespace quantum {
    class QLangParser {
        QCircuit compile(std::string source);
    };
}
