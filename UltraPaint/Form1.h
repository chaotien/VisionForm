
#pragma once
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
//#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
				delete Video1;
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
	private: System::Windows::Forms::Button^  OB_Detection;
	private: System::Windows::Forms::ToolStripMenuItem^  imageToolStripMenuItem;

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
			this->OB_Detection = (gcnew System::Windows::Forms::Button());
			this->imageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(433, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->deviceToolStripMenuItem, this->imageToolStripMenuItem});
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
			// 
			// deviceToolStripMenuItem
			// 
			this->deviceToolStripMenuItem->Name = L"deviceToolStripMenuItem";
			this->deviceToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->deviceToolStripMenuItem->Text = L"Device";
			this->deviceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deviceToolStripMenuItem_Click);
			// 
			// ButtonPlay
			// 
			this->ButtonPlay->Enabled = false;
			this->ButtonPlay->Location = System::Drawing::Point(0, 46);
			this->ButtonPlay->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ButtonPlay->Name = L"ButtonPlay";
			this->ButtonPlay->Size = System::Drawing::Size(100, 31);
			this->ButtonPlay->TabIndex = 1;
			this->ButtonPlay->Text = L"Play";
			this->ButtonPlay->UseVisualStyleBackColor = true;
			this->ButtonPlay->Click += gcnew System::EventHandler(this, &Form1::ButtonPlay_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 84);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(427, 320);
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
			// OB_Detection
			// 
			this->OB_Detection->Location = System::Drawing::Point(108, 46);
			this->OB_Detection->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->OB_Detection->Name = L"OB_Detection";
			this->OB_Detection->Size = System::Drawing::Size(132, 28);
			this->OB_Detection->TabIndex = 3;
			this->OB_Detection->Text = L"Object Detection";
			this->OB_Detection->UseVisualStyleBackColor = true;
			this->OB_Detection->Click += gcnew System::EventHandler(this, &Form1::OB_Detection_Click);
			// 
			// imageToolStripMenuItem
			// 
			this->imageToolStripMenuItem->Name = L"imageToolStripMenuItem";
			this->imageToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->imageToolStripMenuItem->Text = L"Image";
			this->imageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::imageToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(433, 406);
			this->Controls->Add(this->OB_Detection);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->ButtonPlay);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
	CascadeClassifier *cv_cascade;

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
				         Video1 = new VideoCapture;
				         Video1->open(VideoFileName);
				         if ( !Video1->isOpened())
                         {
					         this->Text = "Could not open reference:";
							 return;
                         }
						 timer1->Interval = 1000/Video1->get(CV_CAP_PROP_FPS);
						 this->Text = "YO FPS: "+ 1000/timer1->Interval;
				         this->ButtonPlay->Text = L"Play";
				         ButtonPlay->Enabled = true;
			         }
		         }
			 }
private: System::Void deviceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
                 delete Video1;
				 Video1 = new VideoCapture(0);
				 //timer1->Interval = 1000/Video1->get(CV_CAP_PROP_FPS);
				 timer1->Enabled = true;
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
				 
				 //Image processing for each frame here
				 Mat frame_gray, frame_small;
                 cvtColor( Curframe, frame_gray, CV_BGR2GRAY );
                 resize(frame_gray, frame_small, cv::Size(180,130));

                 if(cv_cascade!=NULL)
                 {
					 std::vector<Rect> Objects;
	                 cv_cascade->detectMultiScale( frame_small, Objects, 1.01, 5, 0, cv::Size(24, 16),cv::Size(26, 18) );
				     for( int i = 0; i < Objects.size(); i++ )
				     {
				         Objects[i].x = Objects[i].x*Curframe.cols/frame_small.cols;
				         Objects[i].y = Objects[i].y*Curframe.rows/frame_small.rows;
				         Objects[i].width = Objects[i].width*Curframe.cols/180;
				         Objects[i].height = Objects[i].height*Curframe.rows/130;

				         cv::Point center( Objects[i].x + Objects[i].width*0.5, Objects[i].y + Objects[i].height*0.5 );
				         ellipse( Curframe, center, cv::Size( Objects[i].width*0.5, Objects[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 0 ), 3, 8, 0 );
				     }
			     }

				 //Display in pictureBox1
				 
				 delete image1;
				 image1 = ConvertMatToBitmap(Curframe);
				 //image1 = CopyMatToBitmap(&Curframe);

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

		//適用於需同步顯示多個Image時
		System::Drawing::Bitmap^ CopyMatToBitmap(cv::Mat *src)   
		{  
		    // bitmap 初始化  
		    System::Drawing::Bitmap ^dst = gcnew System::Drawing::Bitmap(  
		        src->cols, src->rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);  
		  
		    // 获取 bitmap 数据指针  
		    System::Drawing::Imaging::BitmapData ^data = dst->LockBits(  
		        *(gcnew System::Drawing::Rectangle(0, 0, dst->Width, dst->Height)),   
		        System::Drawing::Imaging::ImageLockMode::ReadWrite,   
		        System::Drawing::Imaging::PixelFormat::Format24bppRgb  
		        );  
		  
		    // 获取 cv::Mat 数据地址  
		    src->addref();  
		  
		    // 复制图像数据  
		    if (src->channels() == 3 && src->isContinuous()) {  
		        memcpy(data->Scan0.ToPointer(), src->data,   
		            src->rows * src->cols * src->channels());  
		    }  
		    else {  
		        for (int i = 0; i < src->rows * src->cols; i++) {  
		            Byte *p = (Byte *)data->Scan0.ToPointer();  
		            *(p + i * 3) = *(p + i * 3 + 1) = *(p + i * 3 + 2) = *(src->data + i);  
		        }  
		    }  
		  
		    // 释放 cv::Mat 数据  
		    src->release();  
		  
		    // 解除 bitmap 数据保护  
		    dst->UnlockBits(data);  
		  
		    return dst;  
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

private: System::Void OB_Detection_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
			 openFileDialog1->Filter = "model files (*.xml)|*.xml|All files (*.*)|*.*";
		     openFileDialog1->FilterIndex = 1;
		     openFileDialog1->RestoreDirectory = true;

			 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		     {
				 string cv_cascade_name;
				 MarshalString(openFileDialog1->FileName, cv_cascade_name);
				 delete cv_cascade;
				 cv_cascade = new CascadeClassifier;
				 if( !cv_cascade->load( cv_cascade_name ) ){ printf("--(!)Error loading\n");  }
			 }
		 }

private: System::Void imageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	             OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
                 openFileDialog1->Filter = "avi files (*.jpeg)|*.jpeg|All files (*.*)|*.*";
                 openFileDialog1->FilterIndex = 2;
                 openFileDialog1->RestoreDirectory = true;

                 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
                 {
                     if ( (openFileDialog1->OpenFile()) != nullptr )
                     {
                         string ImageFilemName;
                         MarshalString(openFileDialog1->FileName, ImageFilemName);
                         Mat oImage;
                         Mat Curframe;
                         Curframe = imread(ImageFilemName, CV_LOAD_IMAGE_COLOR);
                         if(! Curframe.data )
                         {
                             this->Text = "Could not open image QQ";
                             return;
                         }
                         this->Text = "YO";

                         delete image1;
                         image1 = CopyMatToBitmap(&Curframe);
                         this->pictureBox1->Image=image1;

                         //Activate Image Mode
                     }
                 }

		 }
};
}

