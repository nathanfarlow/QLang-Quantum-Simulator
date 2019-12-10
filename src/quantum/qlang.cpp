#include "qlang.h"

#include <string>
#include <vector>
#include <algorithm>
#include <regex>

namespace quantum {

    //Split a string based on some regex
    std::vector<std::string> split(const std::string &text, const std::regex &reg) {
        std::vector<std::string> iter(
            std::sregex_token_iterator(text.begin(), text.end(), reg, -1),
            std::sregex_token_iterator()
        );
        return iter;
    }

    //Return uppercase string
    std::string upper(std::string text) {
        std::transform(text.begin(), text.end(), text.begin(), ::toupper);
        return text;
    }

    //Parse number from string, returns -1 if it cannot
    int num(const std::string &text) {
        try {
            return std::stoi(text);
        } catch(...) {
            return -1;
        }
    }

    bool valid_gate(std::string name) {
        return definitions.find(name) != definitions.end();
    }

    QCircuit *QLangParser::Compile(std::string source) {
        auto lines = split(source, std::regex("\\n"));

        QCircuit *c = nullptr;

        //Why do line numbers start counting at 1?
        for(size_t i = 0; i < lines.size(); i++) {

            auto words = split(lines[i], std::regex("\\s+"));

            if(words.size() > 0) {

                if(upper(words[0]) == "CIRCUIT") {

                    if(words.size() >= 2 && num(words[1]) > 0) {
                        c = new QCircuit(num(words[1]));

                        if(words.size() >= 3) {
                            try {
                                c->Init(words[2]);
                            } catch(...) {
                                throw "Invalid circuit qubit initializer on line " + std::to_string(i + 1);
                            }
                        } else {
                            c->InitZero();
                        }
                        
                    } else {
                        throw "Invalid circuit declaration on line " + std::to_string(i + 1);
                    }

                } else if(valid_gate(upper(words[0]))) {

                    if(c == nullptr) {
                        throw "Tried to execute gates without first defining circuit on line " + std::to_string(i + 1);
                    }

                    QDefinition def = definitions[upper(words[0])];

                    if(words.size() - 1 < def.num_parameters) {
                        throw "Not enough arguments for gate on line " + std::to_string(i + 1);
                    }

                    if(num(words[1]) < 0)
                        throw "Bad first argument for gate on line " + std::to_string(i + 1);

                    if(def.num_parameters == 2 && num(words[2]) < 0)
                        throw "Bad second argument for gate on line " + std::to_string(i + 1);

                    size_t q1 = num(words[1]);
                    size_t q2 = num(words[2]);

                    if(q1 > c->get_num_qubits() - 1 || (def.num_parameters == 2 && q2 > c->get_num_qubits() - 1))
                        throw "Qubit index out of range on line " + std::to_string(i + 1);

                    c->AddOperation(QOperation(def, q1, q2));

                } else if(words[0].length() > 0 && words[0][0] != ';') {
                    throw "Unkown identifier on line " + std::to_string(i + 1);
                }

            }

        }

        return c;
    }
}