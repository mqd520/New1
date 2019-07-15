#pragma once
#include <string>
#include <queue>
using namespace std;

namespace llog
{
	// ��־��������
	enum class ELogSrvType : int
	{
		Info,		// ��Ϣ
		Debug,		// ����
		Warn,		// ����
		Error,		// ����
		Fatal,		// ���ش���

		None		// ��
	};

	// ��־����
	typedef struct tagLogData
	{
		string	log;		// ��־����
		ELogSrvType type;	// ��־����
	}LogData;


	// log srv
	class LogSrv
	{
	private:
		LogSrv();

	private:
		static string strFilePath;						// ��־�ļ�·��
		static queue<LogData> LogSrv::quLogs;			// ��־����
		static CRITICAL_SECTION section;				// section
		static string strDirName;						// Ŀ¼��

	private:
		//************************************
		// Method:    д����־���ļ�
		//************************************
		static void WriteToFile(LogData& data);

		//************************************
		// Method:    д����־������̨
		//************************************
		static void WriteToConsole(LogData& data);

	public:
		//************************************
		// Method:    ��ʼ��
		// Method:    ����Ŀ¼��
		//************************************
		static void Init(string dirName = "Log");

		//************************************
		// Method:    �˳�
		//************************************
		static void Exit();

		//************************************
		// Method:    д��һ����־
		// Parameter: ��־����
		// Parameter: �Ƿ����������̨
		// Parameter: ��־��ʽ
		// Parameter: ...
		//************************************
		static void WriteLine(ELogSrvType type, string format, ...);

		//************************************
		// Method:    ������־
		//************************************
		static void ProcessLog();
	};
}