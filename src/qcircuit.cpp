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

	QState GrowOp(const QState &op, size_t total_size, size_t op_parameters, size_t op_index) {

		const QState &id = definitions["ID"].op;

		QState ret(id);

		if(op_index == 0)
			ret = op;

		for(size_t i = op_index == 0 ? op_parameters : 1; i < total_size; i++) {
			if(i == op_index) {
				ret = ret.tensor(op);
				i += op_parameters - 1;
			}
			else {
				ret = ret.tensor(id);
			}
		}

		return ret;
	}

	void QCircuit::Swap(QState &state, size_t q1, size_t q2) {

		if(q1 == q2)
			return;

		if(q1 > q2) {
			Swap(state, q2, q1);
			return;
		}

		const QState swap({{1, 0, 0, 0},
						   {0, 0, 1, 0},
						   {0, 1, 0, 0},
						   {0, 0, 0, 1}});


		//Move q2 up to q1
		size_t current = q2;
		while(current > q1) {
			state = GrowOp(swap, num_qubits_, 2, current - 1) * state;
			current--;
		}

		//Move q1 down to q2 old position
		while(current < q2 - 1) {
			state = GrowOp(swap, num_qubits_, 2, current + 1) * state;
			current++;
		}

	}

	QState QCircuit::Compute() {
		if(operations_.size() == 0)
			return state_;

		QState matrix = GrowOp(definitions["ID"].op, num_qubits_, 1, 0);

		for(auto op : operations_) {
			if(op.def.num_parameters == 1) {
				matrix = GrowOp(op.def.op, num_qubits_, op.def.num_parameters, num_qubits_ - op.q1 - 1) * matrix;
			} else if(op.def.num_parameters == 2) {

				//Apply swap gates to apply cnot or other n ary gates
				size_t control = num_qubits_ - op.q1 - 1;
				size_t changer = num_qubits_ - op.q1 - 1;

				bool at_bottom = false;

				//If control is at the bottom, then we move it up one to
				//fit the changer under it.
				if(control == num_qubits_ - 1) {
					Swap(matrix, num_qubits_ - 1, num_qubits_ - 2);
					control--;
					at_bottom = true;
				}

				//Put changer under control
				//Don't double swap
				if(!at_bottom || changer != num_qubits_ - 2)
					Swap(matrix, control + 1, changer);

				//Apply the binary operator
				matrix = GrowOp(op.def.op, num_qubits_, op.def.num_parameters, control) * matrix;

				//Swap qubits back
				//Don't double swap
				if(!at_bottom || changer != num_qubits_ - 2)
					Swap(matrix, control + 1, changer);

				if(at_bottom)
					Swap(matrix, control, control + 1);

			} else {
				throw "Number of parameters > 2 not supported";
			}
		}

		return matrix * state_;
	}

}