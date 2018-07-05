//Aslan Mehrabi 876090

#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class functions{
public:
	int searchID(string);
	void openID();
}function;

class numbers{
public:
	numbers(){
		students=0;
		teachers=0;
		workers=0;
		employee=0;
		bosses=0;
		guards=0;
		input_output=0;
	}
	int students;
	int teachers;
	int workers;
	int employee;
	int bosses;
	int guards;
	int input_output;
}nums;

class input_output{
public:
	input_output(){
		output_time="not exit yet";
	}
	string ID;
	string first_name;
	string last_name;
	string number;
	string job;
	string input_date;
	string input_time;
	string output_time;//hamunrooz hame birun
}inout[10000];

class person_information{
public:
	string nationality_number;
	string first_name;
	string last_name;
	string phone_number;
	string email;
	string ID;
	int last_input;
};

class student:public person_information{
	
	string student_number;

protected:

	
	string major;
	string school;
	string degree;//maghta

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=student_number;
		inout[nums.input_output-1].job="student";         
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}
	
	void ExitFrmUniversity(){
		if(isin==-1){
			cout<<"You have not enter yet; first enter, then exit!\n";
			return;
		}
		cout<<"input time in format 'hh:mm'\n";
		string input;
		cin>>input;
		inout[isin].output_time=input;
		isin=-1;
		cout<<"Goodbye!\n";
	}

	void LimitedEditInformations(){
		while(1){
			cout<<"which information do you want to edit? Press the specified number:\n<1> password: "<<password<<" \n<2> phone number: "<<phone_number<<"\n<3> Email: "<<email<<"\n<0> back to previous menu\n";
			char input;
			cin>>input;
			switch(input){
			case '1':
				cout<<"enter password:\n";
				cin>>password;
				break;
			case '2':
				cout<<"enter phone number:\n";
				cin>>phone_number;
				break;
			case '3':
				cout<<"enter Email:\n";
				cin>>email;
				break;
			case '0':
				return;
			default:
				cout<<"Incorrect input; Please enter one of the numbers at the bigining of these line:\n";
			}
		}
	}
	void InputOutputReports(){
		int NumEnter=0;
		for(int i=0;i<nums.input_output;i++)
			if(inout[i].ID==ID)
				NumEnter++;
			
		cout<<"Total number of your inputs to the university is : "<<NumEnter<<endl;
		while(1){
			cout<<"Edit details?\n<1> Yes\n<2> No\n";
			char input;
			cin>>input;
			if(input=='2')
				return;
			else if(input=='1')
				break;
			else
				cout<<"Invalid input,press '1' or '2'\n";
		}
		for(int i=0;i<nums.input_output;i++)
			if(inout[i].ID==ID){
				cout<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
			}
		cout<<"Press any key to back to your menu:\n";
		getch();
	}
public:
	student(){
		isin=-1;
		InputPermition=true;
	}

	string password;
	int isin;//age dakhel bashe shomare inout// ~ -1
	bool InputPermition;

	void registeration(){
		cout<<"enter 'student number':\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('s'+input1)==-1)
				break;
			cout<<"This student number is still in the system,enter another student number:\n";
		}
		student_number=input1;
		ID='s'+student_number;
		password='s'+student_number;
		cout<<"ID and password of this student is: "<<ID<<"\nEnter students's last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}
	void menu(){
		while(1){
			cout<<"\nwhat do you want to do ? input numbers to do this tasks:\n<1> Edit your prsonal informations \n<2> Edit your input-output reports \n<3> Enter to the university\n<4> Exit from university\n<0> Exit\n";
			char input;
			cin>>input;
			switch (input){
			case '1':
				LimitedEditInformations();
				break;
			case '2':
				InputOutputReports();
				break;
			case '3':
				EnterToUniversity();
				return;
			case '4':
				ExitFrmUniversity();
				return;
			case'0':
				return;
			default:
				cout<<"please enter one of valid numbers in the list:\n";
			}
		}
	}
	
	void EditInformations(){//faghat super boss mitune dastresi dashte bashe. 
		while(1){
			cout<<"\nwhich information do you want to edit? Press the specified number:\n<1> first name: "<<first_name<<"\n<2> last name: "<<last_name<<"\n<3> nationality number: "<<nationality_number<<"\n";
			cout<<"<4> major: "<<major<<"\n<5> school: "<<school <<"\n<6> degree: "<<degree<<"\n<7> password: "<<password<<" \n<8> phone number: "<<phone_number<<"\n<9> Email: "<<email<<"\n<10> student number: "<<student_number<<"\n<11> InputPermition: ";
			if(InputPermition)	
				cout<<"Yes";
			else
				cout<<"No";			
			cout<<"\n<0> back to previous menu\n";

			int input;
			cin>>input;
			switch(input){
			case 1:
				cout<<"enter first name:\n";
				cin>>first_name;
				break;
			case 2:
				cout<<"enter last name:\n";
				cin>>last_name;
				break;
			case 3:
				cout<<"enter nationality number:\n";
				cin>>nationality_number;
				break;
			case 4:
				cout<<"enter major:\n";
				cin>>major;
				break;
			case 5:
				cout<<"enter school:\n";
				cin>>school;
				break;
			case 6:
				cout<<"enter degree:\n";
				cin>>degree;
				break;
			case 7:
				cout<<"password:\n";
				cin>>password;
				break;
			case 8:
				cout<<"enter phone number:\n";
				cin>>phone_number;
				break;
			case 9:
				cout<<"enter Email:\n";
				cin>>email;
				break;
			case 10:
				cout<<"enter student number:\n";
				cin>>student_number;
				break;
			case 11:
				cout<<"Select input permition:\n<1> Yes\n<2> No\n";
				char input2;
				cin>>input2;
				switch (input2){
				case '1':
					InputPermition=true;
					break;
				case '2':
					InputPermition=false;
				}
				break;
			case 0:
				return;
			default:
				cout<<"Incorrect input; Please enter one of the numbers at the bigining of these lines:\n";
			}
		}

	}
} s[100];

class worker: public student{
	
protected:

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=personnel_number;
		inout[nums.input_output-1].job="worker";       
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}

	void InputOutputReports(){
		int NumEnter=0;
		for(int i=0;i<nums.input_output;i++)
			if(inout[i].ID==ID)
				NumEnter++;
			
		cout<<"Total number of your inputs to the university is : "<<NumEnter<<endl;
		while(1){
			cout<<"Edit details?\n<1> Yes\n<2> No\n";
			char input;
			cin>>input;
			if(input=='2')
				return;
			else if(input=='1')
				break;
			else
				cout<<"Invalid input,press '1' or '2'\n";
		}
		for(int i=0;i<nums.input_output;i++)
			if(inout[i].ID==ID){
				cout<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
			}
		cout<<"Press any key to back to your menu:\n";
		getch();
	}

public:

	string personnel_number;

	worker(){
		isin=-1;
		InputPermition=true;
	}

	void registeration(){
		cout<<"enter 'personnel number of this worker':\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('w'+input1)==-1)
				break;
			cout<<"This personnel number is still in the system,enter another personnel number:\n";
		}
		personnel_number=input1;
		ID='w'+personnel_number;
		password='w'+personnel_number;
		cout<<"ID and password of this worker is: "<<ID<<"\nEnter the last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}

	void EditInformations(){
		while(1){
			cout<<"\nwhich information do you want to edit? Press the specified number:\n<1> first name: "<<first_name<<"\n<2> last name: "<<last_name<<"\n<3> nationality number: "<<nationality_number<<"\n";
			cout<<"<4> major: "<<major<<"\n<5> school: "<<school <<"\n<6> degree: "<<degree<<"\n<7> password: "<<password<<" \n<8> phone number: "<<phone_number<<"\n<9> Email: "<<email<<"\n<10> personnel number: "<<personnel_number<<"\n<11> InputPermition: ";
			if(InputPermition)	
				cout<<"Yes";
			else
				cout<<"No";			
			cout<<"\n<0> back to previous menu\n";

			int input;
			cin>>input;
			switch(input){
			case 1:
				cout<<"enter first name:\n";
				cin>>first_name;
				break;
			case 2:
				cout<<"enter last name:\n";
				cin>>last_name;
				break;
			case 3:
				cout<<"enter nationality number:\n";
				cin>>nationality_number;
				break;
			case 4:
				cout<<"enter major:\n";
				cin>>major;
				break;
			case 5:
				cout<<"enter school:\n";
				cin>>school;
				break;
			case 6:
				cout<<"enter degree:\n";
				cin>>degree;
				break;
			case 7:
				cout<<"password:\n";
				cin>>password;
				break;
			case 8:
				cout<<"enter phone number:\n";
				cin>>phone_number;
				break;
			case 9:
				cout<<"enter Email:\n";
				cin>>email;
				break;
			case 10:
				cout<<"enter personnel number:\n";
				cin>>personnel_number;
				break;
			case 11:
				cout<<"Select input permition:\n<1> Yes\n<2> No\n";
				char input2;
				cin>>input2;
				switch (input2){
				case '1':
					InputPermition=true;
					break;
				case '2':
					InputPermition=false;
				}
				break;
			case 0:
				return;
			default:
				cout<<"Incorrect input; Please enter one of the numbers at the bigining of these lines:\n";
			}
		}

	}
}w[10];


class teacher:public worker{

protected:

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=personnel_number;
		inout[nums.input_output-1].job="teacher";     
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}

public:

	teacher(){
		isin=-1;
		InputPermition=true;
	}

	void registeration(){
		cout<<"enter 'personnel number of this teacher':\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('t'+input1)==-1)
				break;
			cout<<"This personnel number is still in the system,enter another personnel number:\n";
		}
		personnel_number=input1;
		ID='t'+personnel_number;
		password='t'+personnel_number;
		cout<<"ID and password of this teacher is: "<<ID<<"\nEnter the last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}
}t[10];


class employee:public worker{

protected:

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=personnel_number;
		inout[nums.input_output-1].job="employee";
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}

public:

	employee(){
		isin=-1;
		InputPermition=true;
	}

	void registeration(){
		cout<<"enter 'personnel number' of this employee:\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('e'+input1)==-1)
				break;
			cout<<"This personnel number is still in the system,enter another personnel number:\n";
		}
		personnel_number=input1;
		ID='e'+personnel_number;
		password='e'+personnel_number;
		cout<<"ID and password of this employee is: "<<ID<<"\nEnter the last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}
}e[10];

class boss:public worker{

protected:

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=personnel_number;
		inout[nums.input_output-1].job="boss";     
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}

public:

	boss(){
		isin=-1;
		InputPermition=true;
	}

	void registeration(){
		cout<<"enter 'personnel number' of this boss:\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('b'+input1)==-1)
				break;
			cout<<"This personnel number is still in the system,enter another personnel number:\n";
		}
		personnel_number=input1;
		ID='b'+personnel_number;
		password='b'+personnel_number;
		cout<<"ID and password of this employee is: "<<ID<<"\nEnter the last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}
}b[10];
class guard:public worker{

public:
	void InputOutputReports(){
		
		char input;
		string input1;
		int Num=0;
			cout<<"Which kind of input and output reports do you want to edit?\n<1> Your own reports\n<2> Sorted by date \n<3> Sorted by job\n<4> Reports of a person\n";
			cin>>input;
			switch(input){
			case '1':
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].ID==ID){
						cout<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of your enters to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '2':
				for(int i=0;i<nums.input_output;i++){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '3':
				cout<<"students:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="student"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of students to the university is: "<<Num<<endl;
				Num=0;
				cout<<"teachers:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="teacher"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of teachers to the university is: "<<Num<<endl;
				Num=0;
				cout<<"bosses:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="boss"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of bosses to the university is: "<<Num<<endl;
				Num=0;
				cout<<"guards:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="guard"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of guards to the university is: "<<Num<<endl;
				Num=0;
				cout<<"workers:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="worker"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of workers to the university is: "<<Num<<endl;
				Num=0;
				cout<<"employees:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="employee"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of employees to the university is: "<<Num<<endl;
				Num=0;
				cout<<"super boss:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="super boss"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of super boss to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '4':
				cout<<"Enter the ID of person you want to see his or her reports:";
				cin>>input1;
					for(int i=0;i<nums.input_output;i++)
					if(inout[i].ID==input1){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
					
			if(Num>0)
				cout<<"total number of enters: "<<Num<<endl;
			else
				cout<<"This ID is not valid\n";
			cout<<"Press any key to back to your menu:\n";
			getch();
				break;
			default:
			cout<<"Invalid input\n";
			InputOutputReports();
		};
	}

	void EnterToUniversity(){
		if(!InputPermition){
			cout<<"You don't have permition to enter to the university,\nSuper boss can solve your problem.\n";
			return;
		}
		else if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].number=personnel_number;
		inout[nums.input_output-1].job="guard";     
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}

public:

	guard(){
		isin=-1;
		InputPermition=true;
	}

	void registeration(){
		cout<<"enter 'personnel number' of this guard:\n";
		string input1;
		while(1){
			cin>>input1;
			if(function.searchID('h'+input1)==-1)
				break;
			cout<<"This personnel number is still in the system,enter another personnel number:\n";
		}
		personnel_number=input1;
		ID='g'+personnel_number;
		password='g'+personnel_number;
		cout<<"ID and password of this guard is: "<<ID<<"\nEnter the last name:\n";
		cin>>last_name;
		char input;
		while(1){
			cout<<"\nDo you want to enter the other personal informations now? \n<1> Yes\n<2> No, input later\n";
			cin>>input;
			if(input=='1'){
				EditInformations();
				break;
			}
			else if(input=='2')
				break;
			else
				cout<<"Invalid input, please press '1' or '2':\n";
		}
	}
		void menu(){
		while(1){
			cout<<"\nwhat do you want to do ? input numbers to do this tasks:\n<1> Edit your prsonal informations \n<2> Edit input-output reports \n<3> Enter to the university\n<4> Exit from university\n<0> Exit\n";
			char input;
			cin>>input;
			switch (input){
			case '1':
				LimitedEditInformations();
				break;
			case '2':
				InputOutputReports();
				break;
			case '3':
				EnterToUniversity();
				return;
			case '4':
				ExitFrmUniversity();
				return;
			case'0':
				return;
			default:
				cout<<"please enter one of valid numbers in the list:\n";
			}
		}
	}
}g[10];
class superboss:public person_information{
	
	string school;
	string major;
	string grade;
	string personnel_number;
	int isin;

	void EnterToUniversity(){
		if(isin>-1){
			cout<<"Error: you have entered to the University but you didn't go out.\nyou can not enter now.report your exit to the system first.\n";
			return;
		}
		
		nums.input_output++;
		inout[nums.input_output-1].ID=ID;
		inout[nums.input_output-1].first_name=first_name;
		inout[nums.input_output-1].last_name=last_name;
		inout[nums.input_output-1].job="super boss";         
		string input;
		cout<<"Input date in format 'yy/mm/dd':\n";
		cin>>input;
		inout[nums.input_output-1].input_date=input;
		cout<<"Input time in format 'hh:mm':\n";
		cin>>input;
		inout[nums.input_output-1].input_time=input;
		isin=nums.input_output-1; 
		cout<<"welcome "<<first_name<<" "<<last_name<<"!\n";
	}
	
	void ExitFrmUniversity(){
		if(isin==-1){
			cout<<"You have not enter yet; first enter, then exit!\n";
			return;
		}
		cout<<"input time in format 'hh:mm'\n";
		string input;
		cin>>input;
		inout[isin].output_time=input;
		isin=-1;
		cout<<"Goodbye!\n";
	}

	void InputOutputReports(){
		
		char input;
		string input1;
		int Num=0;
			cout<<"Which kind of input and output reports do you want to edit?\n<1> Your own reports\n<2> Sorted by date \n<3> Sorted by job\n<4> Reports of a person\n";
			cin>>input;
			switch(input){
			case '1':
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].ID==ID){
						cout<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of your enters to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '2':
				for(int i=0;i<nums.input_output;i++){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '3':
				cout<<"students:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="student"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of students to the university is: "<<Num<<endl;
				Num=0;
				cout<<"teachers:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="teacher"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of teachers to the university is: "<<Num<<endl;
				Num=0;
				cout<<"bosses:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="boss"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of bosses to the university is: "<<Num<<endl;
				Num=0;
				cout<<"guards:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="guard"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of guards to the university is: "<<Num<<endl;
				Num=0;
				cout<<"workers:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="worker"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of workers to the university is: "<<Num<<endl;
				Num=0;
				cout<<"employees:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="employee"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of employees to the university is: "<<Num<<endl;
				Num=0;
				cout<<"super boss:\n";
				for(int i=0;i<nums.input_output;i++)
					if(inout[i].job=="super boss"){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				cout<<"total number of enters of super boss to the university is: "<<Num<<endl;
				cout<<"Press any key to back to your menu:\n";
				getch();
				break;
			case '4':
				cout<<"Enter the ID of person you want to see his or her reports:";
				cin>>input1;
					for(int i=0;i<nums.input_output;i++)
					if(inout[i].ID==input1){
						cout<<"name: "<<inout[i].first_name<<" "<<inout[i].last_name<<"\t"<<"date: "<<inout[i].input_date<<"\tEnter: "<<inout[i].input_time<<"\tExit: "<<inout[i].output_time<<endl;
						Num++;
					}
				if(Num>0)
					cout<<"total number of enters: "<<Num<<endl;
				else
					cout<<"This ID is not valid\n";
			cout<<"Press any key to back to your menu:\n";
			getch();
				break;
			default:
			cout<<"Invalid input\n";
			InputOutputReports();
		};
	}

	void EnterPassword(){
		string temp1,temp2;
		cin>>temp1;
		cout<<"Please verify your password:\n";
		cin>>temp2;
		if(temp1==temp2){
			password=temp1;
			cout<<"The password has saved!\n";
			return;
		}
		cout<<"Two input passwords wasn't matched,please enter your password again:\n";
		EnterPassword();
	}

	
	void EditInformations(){
		while(1){
			cout<<"which information do you want to edit? Press the specified number:\n<1> first name: "<<first_name<<"\n<2> last name: "<<last_name<<"\n<3> nationality number: "<<nationality_number<<"\n";
			cout<<"<4> major: "<<major<<"\n<5> school: "<<school <<"\n<6> grade: "<<grade<<"\n<7> password: "<<password<<" \n<8> phone number: "<<phone_number<<"\n<9> Email: "<<email<<"\n<10> personnel number: "<<personnel_number<<"\n<11> ID: "<<ID<<"\n<0> back to previous menu\n";
			int input;
			cin>>input;
			switch(input){
			case 1:
				cout<<"enter first name:\n";
				cin>>first_name;
				break;
			case 2:
				cout<<"enter last name:\n";
				cin>>last_name;
				break;
			case 3:
				cout<<"enter nationality number:\n";
				cin>>nationality_number;
				break;
			case 4:
				cout<<"enter major:\n";
				cin>>major;
				break;
			case 5:
				cout<<"enter school:\n";
				cin>>school;
				break;
			case 6:
				cout<<"enter grade:\n";
				cin>>grade;
				break;
			case 7:
				cout<<"password:\n";
				cin>>password;
				break;
			case 8:
				cout<<"enter phone number:\n";
				cin>>phone_number;
				break;
			case 9:
				cout<<"enter Email:\n";
				cin>>email;
				break;
			case 10:
				cout<<"enter personnel number:\n";
				cin>>personnel_number;
				break;
			case 11:
				cout<<"enter ID:\n";
				cin>>ID;
				break;			
			case 0:
				return;
			default:
				cout<<"Incorrect input; Please enter one of the numbers at the bigining of these line:\n";
			}
		}
	}

	void InputInformations(){
		EnterPassword();
		while(1){
			cout<<"Do you want to input your personal informations? \n<1> Yes\n<2> No\n";
			char input;
			cin>>input;
			if (input=='1')
				break;
			else if(input=='2')
				return;
			else
				cout<<"Invalid input,please try again\n";
		}
		EditInformations();
	}

	void registration(){
		nums.bosses++;
		ID="sboss";
		cout<<"University input-output program,designed by:A.Mehrabi\n";
		cout<<"\nHello Super boss of the universty\nyour ID is 'sboss'\nplease enter your password:\n";
		InputInformations();
		menu();
	}
	void OthersInformations(){//use to edit the other person's information,just for Superboss.
		cout<<"Enter the ID of the person which you want to edit\nEnter '0' to return to the previous menu:\n";
		string input;
		cin>>input;
		if(input=="0")
			return;
		int ReturnSearch=function.searchID(input);
		if(ReturnSearch!=-1){
			if(input==sb.ID)
				EditInformations();
			else if(ReturnSearch<nums.bosses && input==b[ReturnSearch].ID)
				b[ReturnSearch].EditInformations();
			else if(ReturnSearch<nums.students && input==s[ReturnSearch].ID)
				s[ReturnSearch].EditInformations();
			else if(ReturnSearch<nums.employee && input==e[ReturnSearch].ID)
				e[ReturnSearch].EditInformations();
			else if(ReturnSearch<nums.workers && input==w[ReturnSearch].ID)
				w[ReturnSearch].EditInformations();
			else if(ReturnSearch<nums.guards && input==g[ReturnSearch].ID)
				g[ReturnSearch].EditInformations();
			else if(ReturnSearch<nums.teachers && input==t[ReturnSearch].ID)
				t[ReturnSearch].EditInformations();
				
		}
		else{
			cout<<"This ID is not in the system\n" ;
			OthersInformations();
		}
	}
	void AddPerson(){
		cout<<"\nwhat kind of person do you want to add?\n<1> student\n<2> teacher\n<3> employee\n<4> worker\n<5> boss\n<6> guard\n<0> back to previous menu\n";
		char input;
		cin>>input;
		switch (input){
		case '0':
			return;
		case '1':
			nums.students++;
			s[nums.students-1].registeration();
			break;
		case '2':
			nums.teachers++;
			t[(nums.teachers)-1].registeration();
			break;
		case '3':
			nums.employee++;
			e[(nums.employee)-1].registeration();
			break;
		case '4':
			nums.workers++;
			w[(nums.workers)-1].registeration();
			break;
		case '5':
			nums.bosses++;
			b[(nums.bosses)-1].registeration();
			break;
		case '6':
			nums.guards++;
			g[(nums.guards)-1].registeration();
			break;
		default:
			cout<<"Invalid input, enter one of the specified numbers:\n";
			AddPerson();

			//b[nums.bosses-1].i;
			/*for(int i=0;i<(nums.bosses)-1;i++){
				*(temp+i)=*(b+i);
			}*/
		//	for(int i=0;i<nums-1;i++)
			//	temp[i]=b[i];
		}
	}
public:
	superboss(){
		isin=-1;
		registration();
	}
	
	string password;

	void menu(){
		cout<<"what do you want to do boss? input numbers to do this tasks:\n<1> Add a person to system \n<2> Edit your prsonal information \n";
		cout<<"<3> Edit input-output reports\n<4> Edit personal Informations and permition to enter of others\n<5> Enter to the university\n<6> Exit from the university\n<0> Exit\n";
		char input;
		cin>>input;
		switch (input){//in switch ke tamum shod barmigarde be 2bare hamnija
		case '1':
			AddPerson();
			break;
		case '2':
			EditInformations();
			break;
		case '3':
			InputOutputReports();
			break;
		case '4':
			OthersInformations();
			break;
		case '5':
			EnterToUniversity();
			break;
		case '6':
			ExitFrmUniversity();
			break;
		case'0':
			return;
		default:
			cout<<"please enter one of valid numbers in the list:\n";
		}
		menu();
	}
} sb;



int functions::searchID(string input){//return:-1 not found / others:number of the member in array.
	int i;
	if(input==sb.ID)
		return 0;
	for(i=0;i<nums.bosses;i++)
		if(input==b[i].ID)
			return i;
	for(i=0;i<nums.students;i++)
		if(input==s[i].ID)
			return i;
	for(i=0;i<nums.employee;i++)
		if(input==e[i].ID)
			return i;
	for(i=0;i<nums.workers;i++)
		if(input==w[i].ID)
			return i;
	for(i=0;i<nums.guards;i++)
		if(input==g[i].ID)
			return i;
	for(i=0;i<nums.teachers;i++)
		if(input==t[i].ID)
			return i;
	return -1;
}
void functions::openID(){
	string inputu;
	string inputp;
	cout<<"\nHello!\nPlease enter your ID:\n";
	while(1){
		cin>>inputu;
		int ReturnSearch=function.searchID(inputu);
		if(ReturnSearch!=-1){
			if(inputu==sb.ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==sb.password){
					sb.menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
			else if(ReturnSearch<nums.bosses && inputu==(b[ReturnSearch]).ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==b[ReturnSearch].password){
					b[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
				
			else if(ReturnSearch<nums.students && inputu==s[ReturnSearch].ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==s[ReturnSearch].password){
					s[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}

			else if(ReturnSearch<nums.employee && inputu==e[ReturnSearch].ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==e[ReturnSearch].password){
					e[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
			
			else if(ReturnSearch<nums.workers && inputu==w[ReturnSearch].ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==w[ReturnSearch].password){
					w[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
			else if(ReturnSearch<nums.guards && inputu==g[ReturnSearch].ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==g[ReturnSearch].password){
					g[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
			else if(ReturnSearch<nums.teachers && inputu==t[ReturnSearch].ID){
				cout<<"Enter your password:\n";
				cin>>inputp;
				if(inputp==t[ReturnSearch].password){
					t[ReturnSearch].menu();
					break;
				}
				cout<<"Username or password is incorrect,enter username again:\n";
			}
		}
			else{
				cout<<"This ID is not in the system\nEnter your ID again:\n" ;
			}
	}
}

void main(){

	while(1)
		function.openID();
	
}
