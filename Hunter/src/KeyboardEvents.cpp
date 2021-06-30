#include <pch.h>

#include "KeyboardEvents.h"

namespace Hunter
{
	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	int KeyReleasedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
}