#include "summator.h"
#include <godot_cpp/core/class_db.hpp>

void Summator::_bind_methods() {
	// D_METHOD is name of method used in interface to Godot callers.
	ClassDB::bind_method(D_METHOD("add", "value"), &Summator::add);
	ClassDB::bind_method(D_METHOD("reset"), &Summator::reset);
	ClassDB::bind_method(D_METHOD("get_total"), &Summator::get_total);
}

void Summator::add(int p_value) {
	count += p_value;
}

void Summator::reset() {
	count = 0;
}

int Summator::get_total() const {
	return count;
}

Summator::Summator() {
}