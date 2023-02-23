#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Echo/Events/ApplicationEvent.hpp"
#include "Window.h"

namespace Echo {

	class ECHO_API Application
	{
	public:
		Application();
		virtual ~Application();

		/// @brief ��ǰ�¼�
		/// @param event 
		void OnEvent(Event& event);

		/// @brief ����
		void Run();

	private:
		/// @brief �رմ���
		/// @param closeEvent ���ڹر��¼�
		/// @return true
		bool OnWindowClose(WindowCloseEvent& closeEvent);

		std::unique_ptr<Window> m_Window;	//Ӧ����ʾ����
		bool m_bRunning = true;				//����״̬�Ŀ���
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


