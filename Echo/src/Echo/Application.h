#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Echo/Events/ApplicationEvent.hpp"
#include "Window.h"
#include "LayerStack.h"

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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		/// @brief �رմ���
		/// @param closeEvent ���ڹر��¼�
		/// @return true
		bool OnWindowClose(WindowCloseEvent& closeEvent);

		std::unique_ptr<Window> m_Window;	//Ӧ����ʾ����
		bool m_bRunning = true;				//����״̬�Ŀ���
		LayerStack m_LayerStack;			//��ջ
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


