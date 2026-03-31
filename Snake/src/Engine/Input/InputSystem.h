#pragma once
#include "Input.h"

class InputSystem {
public:
	virtual ~InputSystem() = default;
	virtual Key Poll() = 0;
};