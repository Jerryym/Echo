#pragma once

#include "Echo/Core.h"

#include <functional>
#include <string>

namespace Echo {

	// �¼�����ö����
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,	// ���ڲ���
		AppTick, AppUpdate, AppRender,											// App����
		KeyPressed, KeyReleased,												// ���̲���
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled		// ������
	};

	// �¼�����ö��
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};


	class ECHO_API Event
	{
	public:
		Event();
		virtual ~Event() = default;

		//��ȡ�¼�����
		virtual EventType GetEventType() const = 0;
		//��ȡ�¼���������
		virtual const char* GetName() const = 0;
		//���¼�ֵת��Ϊ�ַ���
		virtual std::string ToString() const = 0;
	};

}

