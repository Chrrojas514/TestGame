#include <pch.h>

#include "KeyboardEvents.h"

namespace Hunter
{
	KeyPressedEvent::KeyPressedEvent(int key) : mKeyCode(key) {};

	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleasedEvent::KeyReleasedEvent(int key) : mKeyCode(key) {};

	int KeyReleasedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
}