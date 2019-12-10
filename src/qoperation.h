#pragma once

#include <string>
#include <vector>

namespace quantum {

	class QOperation {
	protected:
		const QState &state_;
	public:
		QOperation(const QState &state) : state_(state) {}
		virtual QState GenerateMatrix() = 0;
		virtual std::string get_identifier() = 0;
	}

	//Id gate. Preserves state.
	class QId : public QOperation {
		std::string get_identifier() {return "ID";}
		QState GenerateMatrix();
	}

	//Controlled not
	class QCNot : public QOperation {
		std::string get_identifier() {return "CNOT";}
		QState GenerateMatrix();
	}

	class QHadamard : public QOperation {
		std::string get_identifier() {return "H";}
		QState GenerateMatrix();
	}

	//Pauli X matrix
	//Effectively a not gate.
	class QX : public QOperation {
		std::string get_identifier() {return "X";}
		QState GenerateMatrix();
	}

	//Pauli Y matrix
	class QY : public QOperation {
		std::string get_identifier() {return "Y";}
		QState GenerateMatrix();
	}

	//Pauli Z matrix
	class QZ : public QOperation {
		std::string get_identifier() {return "Z";}
		QState GenerateMatrix();
	}


}