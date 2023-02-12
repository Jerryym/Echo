#pragma once

#include "Echo/Events/Event.h"
#include <sstream>

namespace Echo {

	/// @brief �����¼�
	class KeyEvent : public Event
	{
	public:
		unsigned int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(const unsigned int KeyCode)
			: m_KeyCode(KeyCode) {}

		unsigned int m_KeyCode; //���̰������
	};

	/// @brief ���̰����¼�
	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const unsigned int KeyCode, bool isRepeat = false)
			: KeyEvent(KeyCode), m_bIsRepeat(isRepeat) {}

		//�Ƿ��ظ�����
		bool IsRepeat() const { return m_bIsRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "KeyPressedEvent: " << m_KeyCode << ", repeat = " << m_bIsRepeat;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool m_bIsRepeat;
	};

	/// @brief �����ͷ��¼�
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const unsigned int KeyCode)
			: KeyEvent(KeyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}