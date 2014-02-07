
#pragma once
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
//#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

namespace UltraPaint {
	using namespace std;
	using namespace cv;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			UltraPen = gcnew Pen(Color::Blue, 1);
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete UltraPen;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deviceToolStripMenuItem;
	private: System::Windows::Forms::Button^  ButtonPlay;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;

	protected: 


	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deviceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ButtonPlay = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(321, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->deviceToolStripMenuItem});
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
			// 
			// deviceToolStripMenuItem
			// 
			this->deviceToolStripMenuItem->Name = L"deviceToolStripMenuItem";
			this->deviceToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->deviceToolStripMenuItem->Text = L"Device";
			// 
			// ButtonPlay
			// 
			this->ButtonPlay->Enabled = false;
			this->ButtonPlay->Location = System::Drawing::Point(0, 34);
			this->ButtonPlay->Name = L"ButtonPlay";
			this->ButtonPlay->Size = System::Drawing::Size(75, 23);
			this->ButtonPlay->TabIndex = 1;
			this->ButtonPlay->Text = L"Play";
			this->ButtonPlay->UseVisualStyleBackColor = true;
			this->ButtonPlay->Click += gcnew System::EventHandler(this, &Form1::ButtonPlay_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 63);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 305);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->ButtonPlay);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	Bitmap^ image1; //Temp image
	static int TotalFrame=0; //Total frame number
	static int CurFrame=0;
	VideoCapture *Video1;
	Pen ^UltraPen;

	/** System::String to cv::string **/
	void MarshalString ( System::String^ s, string& os ) 
	{
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	/** Open Video File **/
	private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				 openFileDialog1->Filter = "avi files (*.avi)|*.avi|All files (*.*)|*.*";
		         openFileDialog1->FilterIndex = 2;
		         openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		         {
			         if ( (openFileDialog1->OpenFile()) != nullptr )
			         {
				         string VideoFileName;
				         MarshalString(openFileDialog1->FileName, VideoFileName);
				         delete Video1;
				         Video1 = new VideoCapture();
				         Video1->open(VideoFileName);
				         if ( !Video1->isOpened())
                         {
					         this->Text = "Could not open reference:";
							 return;
                         }
						 timer1->Interval = 1000/Video1->get(CV_CAP_PROP_FPS);
			         }
		         }

				 this->Text = "YO FPS: "+ 1000/timer1->Interval;
				 this->ButtonPlay->Text = L"Play";
				 ButtonPlay->Enabled = true;

			 }
	private: System::Void ButtonPlay_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(ButtonPlay->Text == "Play")
				 {
				     timer1->Enabled = true;
					 ButtonPlay->Text = "Pause";
			     }
				 else
				 {
				     timer1->Enabled = false;
					 ButtonPlay->Text = "Play";
				 }
			 }
    private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 Mat Curframe;
				 Video1->read(Curframe);

				 //Display in pictureBox1
				 delete image1;
				 //image1=(gcnew 
				 //System::Drawing::Bitmap(Curframe.cols,Curframe.rows,Curframe.step, 
				 //System::Drawing::Imaging::PixelFormat::Format24bppRgb,
				 //(System::IntPtr)Curframe.data));
				 image1 = ConvertMatToBitmap(Curframe);
				 this->pictureBox1->Image = image1;
		     }

	    System::Drawing::Bitmap^ ConvertMatToBitmap(cv::Mat& cvImg)  
		{
		    System::Drawing::Bitmap^ bmpImg;  
		  
		    //Examine pixel value range(depth)  
		    if(cvImg.depth() != CV_8U)  
		    {  
		        cout << "Pixel depth:" << cvImg.depth() << ". 8 bits only！" << endl;  
		        bmpImg = gcnew System::Drawing::Bitmap(1,1,System::Drawing::Imaging::PixelFormat::Format8bppIndexed);  
		        return (bmpImg);  
		    }  
		  
		    //color image
		    if(cvImg.channels() == 3)  
		    {  
		        bmpImg = gcnew Bitmap(  
		            cvImg.cols,  
		            cvImg.rows,  
		            cvImg.step,  
		            System::Drawing::Imaging::PixelFormat::Format24bppRgb,  
		            (System::IntPtr)cvImg.data );  
		    }  
		    //gray image 
		    else if(cvImg.channels() == 1)  
		    {  
		        bmpImg = gcnew Bitmap(  
		            cvImg.cols,  
		            cvImg.rows,  
		            cvImg.step,  
		            System::Drawing::Imaging::PixelFormat::Format8bppIndexed,  
		            (System::IntPtr)cvImg.data);  
		    }  
		  
		    return (bmpImg);  
		}  

		 /** Mouse event in pictureBox1. Drag and Draw a rectangle **/
		 static bool is_dragging = false;  
         static int x_down, y_down, x_up, y_up;
		 static int DrawRecX, DrawRecY, DrawRecWidth, DrawRecHeight;
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 is_dragging = true;
			 x_down = e->X;
		     y_down = e->Y;
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->Text = "( " + e->X + ", " + e->Y + " )";
			 if(is_dragging == true)
		     {
				 //Get the curent location of mouse
				 x_up = e->X;
				 y_up = e->Y;
				 pictureBox1->Invalidate();
			 }
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 //Get the curent location of mouse
			 x_up = e->X;
			 y_up = e->Y;
			 pictureBox1->Invalidate();
			 is_dragging = false;
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 //According to the coordinate of mouse,we draw a rectangle on the image
			 Graphics^ gr = e->Graphics;
			 DrawRecX = x_down <= x_up ? x_down : x_up;
			 DrawRecY = y_down <= y_up ? y_down : y_up;
			 DrawRecWidth = x_down <= x_up ? x_up - x_down : x_down - x_up;
			 DrawRecHeight = y_down <= y_up ? y_up - y_down : y_down - y_up;
			 gr->DrawRectangle(UltraPen, DrawRecX ,DrawRecY, DrawRecWidth, DrawRecHeight);
		 }
};
}

