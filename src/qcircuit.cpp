#include "qcircuit.h"

#include "qoperation.h"

namespace quantum {

	void QCircuit::InitZero() {
		for(size_t i = 0; i < num_qubits_ * 2; i++) {
			if(i % 2 == 0)
				state_[i][0] = 1;
			else
				state_[i][0] = 0;
		}
	}

	void QCircuit::Init(std::string cbits) {
		if(cbits.length() > num_qubits_)
			throw "Length of cbit string is too long for quantum state.";

		InitZero();

		for(size_t i = 0; i < cbits.length(); i++) {
			if(cbits[i] == '1') {
				state_[i * 2][0] = 0;
				state_[i * 2 + 1][0] = 1;
			} else if(cbits[i] != '0'){
				throw "Invalid character in cbit string, need 0 or 1.";
			}
		}
	}

	void QCircuit::AddOperation(QOperation operation) {
		operations_.push_back(operation);
	}

	QState GrowOp(const QState &op, size_t total_size, size_t op_index) {

		const QState &id = definitions["ID"].op;

		QState ret(id);

		if(op_index == 0)
			ret = op;

		for(size_t i = 1; i < total_size; i++) {
			if(op_index == i)
				ret.tensor(op);
			else
				ret.tensor(id);
		}

		return ret;
	}

	QState QCircuit::Compute() {
		if(operations_.size() == 0)
			return state_;

		QState matrix = GrowOp(definitions["ID"].op, num_qubits_, 0);



		return matrix;
	}

}