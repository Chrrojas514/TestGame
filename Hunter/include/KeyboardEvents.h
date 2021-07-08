#pragma once

#include "Event.h"

namespace Hunter
{
	class HUNTER_API KeyPressedEvent : public Event
	{
	public:
		int GetKeyCode() const;
		KeyPressedEvent(int key);

	private:
		int mKeyCode{ -1 };
	};

	class HUNTER_API KeyReleasedEvent : public Event
	{
	public:
		int GetKeyCode() const;
		KeyReleasedEvent(int key);

	private:
		int mKeyCode{ -1 };
	};
}