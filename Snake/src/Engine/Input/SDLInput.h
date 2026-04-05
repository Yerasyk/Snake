#pragma once
#include "InputSystem.h"

class SDLInput : public InputSystem
{
public:
	Key Poll() override;
};

