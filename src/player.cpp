#include "player.h"

#include <godot_cpp/classes/input.hpp>

void Player::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Player::set_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void Player::_physics_process(double p_delta) {
	Input *input = Input::get_singleton();
	Vector2 velocity;
	if (input->is_action_pressed("ui_up")) {
		velocity.y = -1;
	};
	if (input->is_action_pressed("ui_down")) {
		velocity.y = 1;
	};
	if (input->is_action_pressed("ui_left")) {
		velocity.x = -1;
	};
	if (input->is_action_pressed("ui_right")) {
		velocity.x = 1;
	};
	set_velocity(velocity * speed);
	move_and_slide();
}

float Player::get_speed() const {
	return speed;
}

void Player::set_speed(float p_speed) {
	speed = p_speed;
}

Player::Player() {
}