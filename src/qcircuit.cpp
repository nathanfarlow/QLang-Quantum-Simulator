#include "qcircuit.h"

#include "qoperation.h"

namespace quantum {

	size_t pow(size_t a, size_t b) {
        size_t accum = 1;

        for(size_t i = 0; i < b; i++)
            accum *= a;
        
        return accum;
    }

	void QCircuit::InitZero() {
		state_ *= 0;
		state_[0][0] = 1;
	}

	void QCircuit::Init(std::string cbits) {
		if(cbits.length() != num_qubits_)
			throw "Length of cbit string is not the same as number of qubits for quantum state.";

		const QState zero({std::vector<complex>({1}), std::vector<complex>({0})});
		const QState one({std::vector<complex>({0}), std::vector<complex>({1})});

		state_ = zero;

		if(cbits[0] == '1')
			state_ = one;
		else if(cbits[0] != '0')
			throw "Invalid character in cbit string, need 0 or 1.";

		for(size_t i = 1; i < num_qubits_; i++) {
			QState next = zero;
			if(cbits[i] == '1')
				next = one;
			else if(cbits[i] != '0')
				throw "Invalid character in cbit string, need 0 or 1.";
			state_ = state_.tensor(next);
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
			if(i == op_index)
				ret = ret.tensor(op);
			else
				ret = ret.tensor(id);
		}

		return ret;
	}

	QState QCircuit::Compute() {
		if(operations_.size() == 0)
			return state_;

		QState matrix = GrowOp(definitions["ID"].op, num_qubits_, 0);

		for(auto op : operations_) {
			if(op.def.num_parameters == 1) {
				matrix = GrowOp(op.def.op, num_qubits_, op.q1) * matrix;
			} else {

			}
		}

		return matrix * state_;
	}

}