#pragma once

#include "Echo/Events/Event.h"

// ����¼�
namespace Echo {

	/// @brief ����ƶ��¼�
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
			: m_PositionX(x), m_PositionY(y) {}

		float getX() const { return m_PositionX; }
		float getY() const { return m_PositionY; }

		std::string ToString() const override
		{
			// ʹ�� std::stringstream ʵ����������ת��
			std::stringstream ss{};
			ss << "MouseMovedEvent: " << m_PositionX << ", " << m_PositionY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private: 
		float m_PositionX;
		float m_PositionY;
	};

	/// @brief �������¼�
	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float x, const float y)
			: m_XOffset(x), m_YOffset(y) {}

		float getXOffset() const { return m_XOffset; }
		float getYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			// ʹ�� std::stringstream ʵ����������ת��
			std::stringstream ss{};
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset;	// x��ƫ��
		float m_YOffset;	// y��ƫ��
	};

	/// @brief ��갴ť�¼�
	class MouseButtonEvent : public Event
	{
	public:
		//��ȡ��갴ť
		unsigned int getMouseButton() const { return m_ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	protected:
		/// @brief Constructor
		/// @param Button 
		MouseButtonEvent(const unsigned int Button) 
			: m_ButtonCode(Button) {}

		unsigned int m_ButtonCode;//��갴ť���
	};

	/// @brief ��갴���¼�
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const unsigned int Button)
			: MouseButtonEvent(Button) {}

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "MouseButtonPressedEvent: " << m_ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	/// @brief ��갴���¼�
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const unsigned int Button)
			: MouseButtonEvent(Button) {}

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "MouseButtonReleasedEvent: " << m_ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}