#pragma once


#define RED 0
#define GREEN 1
#define BLUE 2


namespace embedded_project 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Embedded_p_Main_GUI
	/// </summary>
	public ref class Embedded_p_Main_GUI : public System::Windows::Forms::Form
	{
	public:

		static char* color;
		void send_cmnd_to_board(static char*);
		void up_down_domain_filler(DomainUpDown^ object_to_fill, int low, int high, int offset);
		void up_down_set_selected_value(DomainUpDown^ object_to_read);
		void connect_to_uart(void);
	private: System::Windows::Forms::Button^  btn_sw1;
	public:


		static Embedded_p_Main_GUI^ E_P_GUI = nullptr;

		Embedded_p_Main_GUI(void)
		{
			InitializeComponent();
			E_P_GUI = this;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Embedded_p_Main_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  blue_btn;
	private: System::Windows::Forms::Button^  red_btn;
	private: System::Windows::Forms::Button^  green_btn;
	private: System::Windows::Forms::Button^  cnt_btn;
	//private: System::Windows::Forms::Button^  btn_sw1;
	private: System::Windows::Forms::Button^  btn_sw2;

	private: DomainUpDown^ up_down_COM;
	private: System::ComponentModel::IContainer^  components;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->blue_btn = (gcnew System::Windows::Forms::Button());
			this->red_btn = (gcnew System::Windows::Forms::Button());
			this->green_btn = (gcnew System::Windows::Forms::Button());
			this->cnt_btn = (gcnew System::Windows::Forms::Button());
			this->btn_sw2 = (gcnew System::Windows::Forms::Button());
			this->btn_sw1 = (gcnew System::Windows::Forms::Button());
			this->up_down_COM = (gcnew System::Windows::Forms::DomainUpDown());
			this->SuspendLayout();
			// 
			// blue_btn
			// 
			this->blue_btn->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->blue_btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->blue_btn->Location = System::Drawing::Point(44, 60);
			this->blue_btn->Name = L"blue_btn";
			this->blue_btn->Size = System::Drawing::Size(75, 23);
			this->blue_btn->TabIndex = 0;
			this->blue_btn->Text = L"Blue";
			this->blue_btn->UseVisualStyleBackColor = false;
			this->blue_btn->Click += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::blue_btn_Click);
			// 
			// red_btn
			// 
			this->red_btn->BackColor = System::Drawing::Color::Red;
			this->red_btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->red_btn->Location = System::Drawing::Point(147, 60);
			this->red_btn->Name = L"red_btn";
			this->red_btn->Size = System::Drawing::Size(75, 23);
			this->red_btn->TabIndex = 1;
			this->red_btn->Text = L"Red";
			this->red_btn->UseVisualStyleBackColor = false;
			this->red_btn->Click += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::red_btn_Click);
			// 
			// green_btn
			// 
			this->green_btn->BackColor = System::Drawing::Color::ForestGreen;
			this->green_btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->green_btn->Location = System::Drawing::Point(251, 60);
			this->green_btn->Name = L"green_btn";
			this->green_btn->Size = System::Drawing::Size(75, 23);
			this->green_btn->TabIndex = 2;
			this->green_btn->Text = L"Green";
			this->green_btn->UseVisualStyleBackColor = false;
			this->green_btn->Click += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::green_btn_Click);
			//
			//cnt btn
			//
			this->cnt_btn->BackColor = System::Drawing::Color::Gray;
			this->cnt_btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cnt_btn->Location = System::Drawing::Point(137, 121);
			this->cnt_btn->Name = L"cnt_btn";
			this->cnt_btn->Size = System::Drawing::Size(75, 23);
			this->cnt_btn->TabIndex = 2;
			this->cnt_btn->Text = L"Connect to the selected COM";
			this->cnt_btn->UseVisualStyleBackColor = false;
			this->cnt_btn->Click += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::cnt_btn_Click);
			// 
			// btn_sw2
			// 
			this->btn_sw2->BackColor = System::Drawing::Color::LawnGreen;
			this->btn_sw2->Enabled = false;
			this->btn_sw2->Location = System::Drawing::Point(251, 201);
			this->btn_sw2->Name = L"btn_sw2";
			this->btn_sw2->Size = System::Drawing::Size(75, 57);
			this->btn_sw2->TabIndex = 6;
			this->btn_sw2->Text = L"Switch 2";
			this->btn_sw2->UseVisualStyleBackColor = false;
			// 
			// btn_sw1
			// 
			this->btn_sw1->BackColor = System::Drawing::Color::LawnGreen;
			this->btn_sw1->Enabled = false;
			this->btn_sw1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_sw1->Location = System::Drawing::Point(44, 201);
			this->btn_sw1->Name = L"btn_sw1";
			this->btn_sw1->Size = System::Drawing::Size(75, 57);
			this->btn_sw1->TabIndex = 5;
			this->btn_sw1->Text = L"Switch 1";
			this->btn_sw1->UseVisualStyleBackColor = false;

			//

			//
			this->up_down_COM->BackColor = System::Drawing::SystemColors::Window;
			this->up_down_COM->Location = System::Drawing::Point(47, 123);
			this->up_down_COM->Name = L"up_down_COM";
			this->up_down_COM->ReadOnly = true;
			this->up_down_COM->Size = System::Drawing::Size(64, 20);
			this->up_down_COM->TabIndex = 8;
			this->up_down_COM->SelectedItemChanged += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::up_down_COM_SelectedItemChanged);
			this->up_down_COM->ChangeUICues += gcnew System::Windows::Forms::UICuesEventHandler(this, &Embedded_p_Main_GUI::up_down_COM_ChangeUICues);
			// 
			// Embedded_p_Main_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 299);
			this->Controls->Add(this->btn_sw2);
			this->Controls->Add(this->btn_sw1);
			this->Controls->Add(this->green_btn);
			this->Controls->Add(this->red_btn);
			this->Controls->Add(this->blue_btn);
			this->Controls->Add(this->cnt_btn);
			this->Controls->Add(this->up_down_COM);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Embedded_p_Main_GUI";
			this->Text = L"Tiva Launchpad Basic Controller";
			this->Load += gcnew System::EventHandler(this, &Embedded_p_Main_GUI::Embedded_p_Main_GUI_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Embedded_p_Main_GUI_Load(System::Object^  sender, System::EventArgs^  e)
	{
				
	}

	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}

	private: System::Void up_down_COM_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e)
	{
				 up_down_set_selected_value(this->up_down_COM);
	}

	private: System::Void up_down_COM_ChangeUICues(System::Object^  sender, System::Windows::Forms::UICuesEventArgs^  e)
	{
					up_down_domain_filler(this->up_down_COM, 0, 15, 1);
	}

	public: System::Void btn_sw1_color_update(bool sw1_pressed)
	{
		if (sw1_pressed == true)
			this->btn_sw1->BackColor = System::Drawing::Color::Tomato;	
		else
			this->btn_sw1->BackColor = System::Drawing::Color::LawnGreen;

				
	}

	public: System::Void btn_sw2_color_update(bool sw2_pressed)
	{
		if (sw2_pressed == true)
			this->btn_sw2->BackColor = System::Drawing::Color::Tomato;
		else
			this->btn_sw2->BackColor = System::Drawing::Color::LawnGreen;
	}


	private: System::Void red_btn_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 
				this->color = "r";
				this->send_cmnd_to_board(color);
	}

	private: System::Void blue_btn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 this->color = "b";
				 this->send_cmnd_to_board(color);
	}

	private: System::Void green_btn_Click(System::Object^  sender, System::EventArgs^  e) 
	{ 
				this->color = "g";
				this->send_cmnd_to_board(color);
	}
	
	private: System::Void cnt_btn_Click(System::Object^  sender, System::EventArgs^  e)
	{
				connect_to_uart();
	}


};//class
	
}//namespace
