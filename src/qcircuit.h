#pragma once

#include "quantum.h"
#include "qoperation.h"

namespace quantum {

	class QCircuit {
	private:
		size_t num_qubits_;

		std::vector<QOperation> operations_;
	public:
		QState state_;

		QCircuit(size_t num_qubits)
			: num_qubits_(num_qubits), state_(num_qubits * 2, 1, 0) {}

		//Initialize qubits to all 100% 0
		void InitZero();
		//Initialize state with a string of classical bits
		void Init(std::string cbits);
		//Add an operation to the schedule
		void AddOperation(QOperation operation);
		//Compute the output state vector
		QState Compute();
	};

}
