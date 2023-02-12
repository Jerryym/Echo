#include "echopch.h"
#include "Log.h"

namespace Echo {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// ������־ģʽ
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// ��ʼ���������־�������ɫ�͵ȼ�
		s_CoreLogger = spdlog::stdout_color_mt("ECHO");
		s_CoreLogger->set_level(spdlog::level::trace);

		// ��ʼ���ͻ�����־�������ɫ�͵ȼ�
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}