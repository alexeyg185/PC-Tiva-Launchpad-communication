//Author: Alexey Gruzdev July 2015

#include <Windows.h>
#include <iostream>
#include <stdint.h>
#include <string>
#include <msclr/marshal_cppstd.h>

#include "emb_main_gui.h"
#include "serial_handler.h"


using namespace std;
using namespace embedded_project;
using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

extern uint32_t switch1_status;
extern uint32_t switch2_status;

int COM_number=3; 
CSerial serial_con_handler;

void Embedded_p_Main_GUI::up_down_domain_filler(DomainUpDown^ object_to_fill, int low, int high, int offset)
{

	int value_to_insert;

	for (value_to_insert = high; value_to_insert >= low; value_to_insert -= offset)
	{
		object_to_fill->Items->Add(value_to_insert);
	}

	//sets the first index to show in the window
	object_to_fill->SelectedIndex = 0;

	return;
}

void Embedded_p_Main_GUI::up_down_set_selected_value(DomainUpDown^ object_to_read)
{
	COM_number = object_to_read->SelectedItem->GetHashCode();

}

void Embedded_p_Main_GUI::connect_to_uart(void)
{

	if (serial_con_handler.Open(COM_number, CBR_115200))
		MessageBox::Show("The port opened successfully");
	else
	{

		string err = std::to_string(GetLastError());
		String^ err_m = gcnew String(err.c_str());

		MessageBox::Show("Failed to open the selected port! Please check your configurations. Refer to Google with this error number: " + err_m);

	}
}

void Embedded_p_Main_GUI::send_cmnd_to_board(static char* color)
{
	//Tx
	int nBytesSent = serial_con_handler.SendData(color, 1);

	if (nBytesSent<1)
		MessageBox::Show("Problem with sending data");
	
}


DWORD main_thread(void)
{
	
	char* lpBuffer = new char[2];
	int nBytesRead;

	while (1)
	{

		//Rx
		nBytesRead = serial_con_handler.ReadData(lpBuffer, 2);
		if (nBytesRead > 0)
		{
			//0 - sw1 is off; 1 - sw1 is on; 2 - sw2 is off; 3 - sw2 is on;
			
			switch (*lpBuffer)
			{

			case '0':
				Embedded_p_Main_GUI::E_P_GUI->btn_sw1_color_update(false);
				break;
			case '1':
				Embedded_p_Main_GUI::E_P_GUI->btn_sw1_color_update(true);
				break;
			case '2':
				Embedded_p_Main_GUI::E_P_GUI->btn_sw2_color_update(false);
				break;
			case '3':
				Embedded_p_Main_GUI::E_P_GUI->btn_sw2_color_update(true);
				break;

			default:
				break;

			}

		}//switch
	}//while

	

}


[STAThread]
void Main(array<String^>^ args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Embedded_p_Main_GUI form;

	//MessageBox::Show("Please specify the COM port number Tiva LaunchPad is connected to");


	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&main_thread, NULL, 0, NULL);

	Application::Run(%form);


}

