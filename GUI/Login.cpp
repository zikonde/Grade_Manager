//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Login.h"
#include <fstream>
#include "teacher.h"
#include "path.h"
#include "Home.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLoginForm *LoginForm;
std::string PassedUsername;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
std::vector <std::string> parseCommaDeliminatedStrinf(std::string line){
	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while(s_stream.good()){
		std::string substr;
		getline(s_stream,substr,',');
		result.push_back(substr);
	}
	return result;
}
void __fastcall TLoginForm::LoginButtonClick(TObject *Sender)
{
	if(UsernameEdit->Text==""||IdEdit->Text==""||PasswordEdit->Text==""){
		LoginProgressLabel->Text="*请输入完";
	}else{
		LoginProgressLabel->Text="";
		std::fstream file("D:\\Embarcadero\\Win32\\学生成绩管理\\Teachers.txt",ios::in);
		if(file.is_open()){
			int pass=0,user=0,_id=0;
			std::string line;
			if(!file){LoginProgressLabel->Text="数据库访问异常";}
			while(getline(file,line)&&pass==0){
				std::vector <std::string> parsedLine=parseCommaDeliminatedStrinf(line);
				const char *username= parsedLine.at(0).c_str();
				AnsiString editUsername=UsernameEdit->Text;
				char *usernameString=editUsername.c_str();
				if(std::strcmp(username,usernameString)==0){
					user=1;
					const char *id=parsedLine.at(1).c_str();
					AnsiString editId=IdEdit->Text;
					char *IdString=editId.c_str();

					if(std::strcmp(id,IdString)==0){
						_id=1;
						const char *password=parsedLine.at(2).c_str();
						AnsiString editPassword=PasswordEdit->Text;
						char *passwordString=editPassword.c_str();

						if(std::strcmp(password,passwordString)==0){
							pass=1;
							LoginProgressLabel->Text="";
							LoginForm->Hide();
							UsernameEdit->Text="";
							IdEdit->Text="";
							PasswordEdit->Text="";
							PassedUsername=usernameString;

							std::ofstream temp_file(getPath()+"temp.txt");
							temp_file<<usernameString;
							temp_file.close();

							Application->CreateForm(__classid(THomeForm), &HomeForm);
							HomeForm->Show();
						}
						else{  LoginProgressLabel->Text="密码错误";}
					} else{ LoginProgressLabel->Text="密码或工号错误";}
				} else if(user==0){ LoginProgressLabel->Text="该用户不存在";}
			}
			file.close();
		}
	}
}
//---------------------------------------------------------------------------
