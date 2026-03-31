#pragma once

#include "InputSystem.h"

class ConsoleInput : public InputSystem
{
public:
	Key Poll() override;
};

