#define _CRT_SECURE_NO_WARNINGS     //To remove warning messages

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int Maximum_Size = 100;     //Constant Limit

struct DATE     //Date --> Structure
{
	int Day = 0;
	int Month = 0;
	int Year = 0;
};

struct CONTACT     //Contact --> Structure
{
	long First = 0;
	long Second = 0;
	long Third = 0;
};

struct USER     //User --> Structure
{
	string User_Name;
	string Password;
	long ID;
	string Email;
	string Account_type;
	DATE Creation_Date;
	CONTACT Contact;
}User[Maximum_Size];

struct BOOK     //Book --> Structure
{
	string Title;
	DATE Production_Date;
	int Num_of_Copies;
	string Category;
	int Edition;
}Book[Maximum_Size];


////////////////////////////////////////////////////////////////////--> >< Functions () >< <--////////////////////////////////////////////////////////////////////
bool Login_fn(string Login_Username, string Login_Password)     //For any User                                                            //Login Check Function//
{
	int Remaining_Attempts = 3;

	cout << "\n\n\t---------------------\n\t-->  Login First  <--\n\t---------------------\n\n";
	cout << "\n\t° Enter Username --> ";
	cin >> Login_Username;

	for (int j = Remaining_Attempts; j > 0; j--)
	{
		for (int i = 0; i < Maximum_Size; i++)
		{
			if (Login_Username == User[i].User_Name)
			{
				cout << "\n\t° Enter Password --> ";
				cin >> Login_Password;

				if (Login_Password == User[i].Password)
				{
					cout << "\n\n\t--> Login Successful <--\n";
					system("cls");
					return true;
				}

				if (Login_Password != User[i].Password)
					cout << "\n\t    Invalid" << " ---> " << "Remain Attempts is: [" << -1 + j << "]\n";     //Invalid Input & Try again IF-->[Attempts are Remaining]
			}
		}
	}
	system("cls");
}

bool Admin_Login_fn(string Login_Username, string Login_Password)     //For Admins Only                                             //Admin_Login Check function//
{
	int Remaining_Attempts = 3;

	cout << "\n\n\t---------------------\n\t-->  Login First  <--\n\t---------------------\n\n";
	cout << "\n\t° Enter Username --> ";
	cin >> Login_Username;

	for (int i = 0; i < Maximum_Size; i++)
	{
		if (Login_Username == User[i].User_Name && User[i].Account_type == "staff")
		{
			for (int j = Remaining_Attempts; j > 0; j--)
			{
				cout << "\n\t° Enter Password --> ";
				cin >> Login_Password;

				if (Login_Password == User[i].Password && User[i].Account_type == "staff")
				{
					if (User[i].Account_type == "staff" || "Staff" || "STAFF")
					{
						cout << "\n\n\t--> Admin Login Successful <--\n";
						return true;     //Allowed
					}

					if (User[i].Account_type != "staff" && "Staff" && "STAFF")
					{
						cout << "\n\n\t--> You are not Allowed to do this Proccess <--\n";
						return false;     //Denied
					}
				}

				if (Login_Password != User[i].Password)
					cout << "\n\t    Invalid" << " ---> " << "Remain Attempts is: [" << -1 + j << "]\n";

			}

			if (Login_Password != User[i].Password)\
				return false;     //Denied
		}
	}
	system("cls");
}

void Search_Book_fn(string Book_Title, int Book_Prod_Year)                                                                                //Search Book function//
{
	int Search_Book_Choise = 0;
	int index = 0;

	cout << "\n\t° Enter >-[1]-> to:-> Search Books with a Title\n";
	cout << "\n\t° Enter >-[2]-> to:-> Search Books with Production Year\n\n";
	cout << "\n\n\n***********************************************************************\n";
	cout << "\n\n\t° -> Your Choise is:-> ";
	cin >> Search_Book_Choise;

	while (Search_Book_Choise != 1 && Search_Book_Choise != 2)     //Invalid input & try again
	{
		cout << "\t\tInvalid ";
		cout << "\n\t° -> Your Choise is:-> ";
		cin >> Search_Book_Choise;
	}

	switch (Search_Book_Choise)
	{
	case 1:     //Search by Title
	{
		system("cls");
		cout << "\n\n\t-----------------------\n\t-->   Book  Title   <--\n\t-----------------------\n\n";
		cout << "\n\t° Enter Title --> ";
		cin >> Book_Title;

		for (int i = 0; i < Maximum_Size; i++)
		{
			if (Book_Title == Book[i].Title)
			{
				index = i;

				if (Book[index].Num_of_Copies > 0)
				{
					cout << "\n\n\n\t(Title): -> [" << Book[i].Title << "] " << "   ,   " << "Production Year: " << Book[i].Production_Date.Year << "\n";
					cout << "\n\t\t,   Category: " << Book[i].Category << "   ,   " << "Edition: " << Book[i].Edition << "   ,   " << "No. of Copies: " << Book[i].Num_of_Copies << "\n\n";
				}
			}
		}

		if (Book_Title != Book[index].Title || Book[index].Num_of_Copies < 1)
			cout << "\n\n\n\t--> No Book Found with this Title\n\n";     //If Book Is not Found,, Inform the User
	}
	break;

	case 2:     //Search by Production Year
	{
		system("cls");
		cout << "\n\n\t-----------------------\n\t--> Production Year <--\n\t-----------------------\n\n";
		cout << "\n\t° Enter Production Year --> ";
		cin >> Book_Prod_Year;

		for (int i = 0; i < Maximum_Size; i++)
		{
			if (Book_Prod_Year == Book[i].Production_Date.Year)
			{
				index = i;

				if (Book[index].Num_of_Copies > 0)
				{

					cout << "\n\n\n\t(Production Year): -> [" << Book[i].Production_Date.Year << "] " << "   ,   " << "Title: " << Book[i].Title << "\n";
					cout << "\n\t\t,   Category: " << Book[i].Category << "   ,   " << "Edition: " << Book[i].Edition << "   ,   " << "No. of Copies: " << Book[i].Num_of_Copies << "\n\n";
				}
			}
		}

		if (Book_Prod_Year != Book[index].Production_Date.Year || Book[index].Num_of_Copies < 1)
			cout << "\n\n\n\t--> No Book Found with this Production Year\n\n";     //If Book Is not Found,, Inform the User
	}
	break;
	}//////////--> Search-Book >-< Switch Ends Here <--//////////
}

void Buy_Book_fn(string Book_Title, int Book_Prod_Year)                                                                                      //Buy Book function//
{
	int Search_Book_Choise = 0;
	bool Buy_Book_Choise = 0;
	int index = 0;
	int book_index = 0;

	cout << "\n\t° Enter >-[1]-> to:-> Search with a Title\n";
	cout << "\n\t° Enter >-[2]-> to:-> Search with Production Year\n\n";
	cout << "\n\n***********************************************************************\n";
	cout << "\n\n\t° -> Your Choise is:-> ";
	cin >> Search_Book_Choise;

	while (Search_Book_Choise != 1 && Search_Book_Choise != 2)     //Invalid input & try again
	{
		cout << "\t\tInvalid ";
		cout << "\n\t° -> Your Choise is:-> ";
		cin >> Search_Book_Choise;
	}

	switch (Search_Book_Choise)
	{
	case 1:     //Search by Title
	{
		system("cls");
		cout << "\n\n\t-----------------------\n\t-->   Book  Title   <--\n\t-----------------------\n\n";
		cout << "\n\t° Enter Title --> ";
		cin >> Book_Title;

		for (int i = 0; i < Maximum_Size; i++)
		{
			if (Book_Title == Book[i].Title)
			{
				index = i;
				book_index = i;

				if (Book[index].Num_of_Copies > 0)
				{
					cout << "\n\n\n\t(Title): -> [" << Book[i].Title << "] " << "   ,   " << "Production Year: " << Book[i].Production_Date.Year << "\n";
					cout << "\n\t\t,   Category: " << Book[i].Category << "   ,   " << "Edition: " << Book[i].Edition << "   ,   " << "No. of Copies: " << Book[i].Num_of_Copies << "\n\n";
					cout << "\n***********************************************************************\n";
					cout << "\n\t° Enter >-[1]-> to:-> Buy This Book\n";
					cout << "\n\t° Enter >-[0]-> to:-> Cancel Process\n";
					cout << "\n\n***********************************************************************\n";
					cout << "\n\t° -> Your Choise is:-> ";
					cin >> Buy_Book_Choise;

					while (Buy_Book_Choise != 1 && Buy_Book_Choise != 0)     //Invalid input & try again
					{
						cout << "\t\tInvalid ";
						cout << "\n\t° -> Your Choise is:-> ";
						cin >> Buy_Book_Choise;
					}

					system("cls");
					switch (Buy_Book_Choise)
					{
					case 1:     //Want to Buy
					{
						system("cls");
						cout << "\n\n\t---------------------\n\t-->    Buy Book   <--\n\t---------------------\n\n";
						cout << "\n\n\n\t--> successfull Buying <--\n\n";
						Book[book_index].Num_of_Copies--;     //Subtractting -> (1) -> from the total num of Copies
					}
					break;

					case 0:     //No Buying
					{
						system("cls");
						cout << "\n\n\n\n\t--> Canceled Successfully <--\n\n";
					}
					break;
					}//////////--> Buy-Choise >-< Switch Ends Here <--//////////
				}
			}
		}

		if (Book_Title != Book[index].Title || Book[index].Num_of_Copies < 1)
			cout << "\n\n\n\t--> No Book Found with this Title <--\n\n";     //If Book Is not Found,, Inform the User
	}
	break;

	case 2:     //Search by Production Year
	{
		system("cls");
		cout << "\n\n\t-----------------------\n\t--> Production Year <--\n\t-----------------------\n\n";
		cout << "\n\t° Enter Production Year --> ";
		cin >> Book_Prod_Year;

		for (int i = 0; i < Maximum_Size; i++)
		{
			if (Book_Prod_Year == Book[i].Production_Date.Year)
			{
				index = i;
				book_index = i;

				if (Book[index].Num_of_Copies > 0)
				{
					cout << "\n\n\n\t(Production Year): -> [" << Book[i].Production_Date.Year << "] " << "   ,   " << "Title: " << Book[i].Title << "\n";
					cout << "\n\t\t,   Category: " << Book[i].Category << "   ,   " << "Edition: " << Book[i].Edition << "   ,   " << "No. of Copies: " << Book[i].Num_of_Copies << "\n\n";
					cout << "\n***********************************************************************\n";
					cout << "\n\t° Enter >-[1]-> to:-> Buy This Book\n";
					cout << "\n\t° Enter >-[0]-> to:-> Cancel Process\n";
					cout << "\n\n***********************************************************************\n";
					cout << "\n\t° -> Your Choise is:-> ";
					cin >> Buy_Book_Choise;

					while (Buy_Book_Choise != 1 && Buy_Book_Choise != 0)     //Invalid input & try again
					{
						cout << "\t\tInvalid ";
						cout << "\n\t° -> Your Choise is:-> ";
						cin >> Buy_Book_Choise;
					}

					system("cls");
					switch (Buy_Book_Choise)
					{
					case 1:     //Want to Buy
					{
						system("cls");
						cout << "\n\n\t---------------------\n\t-->    Buy Book   <--\n\t---------------------\n\n";
						cout << "\n\n\n\t--> successfull Buying <--\n\n";
						Book[book_index].Num_of_Copies--;     //Subtractting -> (1) -> from the total num of Copies
					}
					break;

					case 0:     //No Buying
					{
						system("cls");
						cout << "\n\n\n\n\t--> Canceled Successfully <--\n\n";
					}
					break;
					}//////////--> Buy-Choise >-< Switch Ends Here <--//////////
				}
			}
		}

		if (Book_Prod_Year != Book[index].Production_Date.Year || Book[index].Num_of_Copies < 1)
			cout << "\n\n\n\t--> No Book Found with this Production Year <--\n\n";     //If Book Is not Found,, Inform the User
	}
	break;
	}//////////--> Search-Book >-< Switch Ends Here <--//////////
}

void Register_fn(int New_Users_Num)                                                                                                          //Register function//
{
	if (New_Users_Num != 0)
	{
		for (int i = 4; i < 4 + New_Users_Num; i++)
		{
			cout << "\n\n***********************************************************************\n\n\t--->User (" << -3 + i << ") <--- \n";

			cout << "Enter Username: ";     //Username
			cin >> User[i].User_Name;

			cout << "Enter Password: ";     //Password
			cin >> User[i].Password;

			cout << "Enter ID: ";     //ID
			cin >> User[i].ID;

			cout << "Enter Account Type: ";     //Account Type
			cin >> User[i].Account_type;

			cout << "Enter Email: ";     //E-mail
			cin >> User[i].Email;

			cout << "Enter Maximum ->(3)<- Contacts:\n";     //Contacts
			cout << "\t-(1)--> : "; cin >> User[i].Contact.First;
			cout << "\t-(2)--> : "; cin >> User[i].Contact.Second;
			cout << "\t-(3)--> : "; cin >> User[i].Contact.Third;

			cout << "Enter creation Date: \n";     //Creation Date
			cout << "\t-[Day]--> "; cin >> User[i].Creation_Date.Day;
			cout << "\t-[Month]--> "; cin >> User[i].Creation_Date.Month;
			cout << "\t-[Year]--> "; cin >> User[i].Creation_Date.Year;
		}
	}
}

void Weekly_Report_fn(int New_Users_Num)                                                                                         //Weekly Registration Report fn//
{
	time_t now = time(0);     //Current Date data from Desktop
	tm* current_time_ptr = localtime(&now);     //Pointer set to the current_local_time data at Desktop

	if (New_Users_Num == 0)     //If New_Users_Num is (0) --> The Output is: [nothing found]
		cout << "\n->No Users Created since a week ago<-\n\n";

	for (int i = 4; i < 4 + New_Users_Num; i++)
	{
		if (User[i].Creation_Date.Year == 1900 + current_time_ptr->tm_year)     //check Years
		{

			if (User[i].Creation_Date.Month == 1 + current_time_ptr->tm_mon)     //Check the Current Month
			{
				if (User[i].Creation_Date.Day > current_time_ptr->tm_mday - 7)     //check Days till a week ago
				{
					cout << "\n\t(No." << -3 + i << ")  -> [" << User[i].User_Name << "] <-\n";
					cout << "Password: " << User[i].Password << "   ,   " << "ID: " << User[i].ID << "   ,   " << "Authority: " << User[i].Account_type << "   ,   " << "Email: " << User[i].Email << endl;
					cout << "Contacts:" << "  (1)-> : " << User[i].Contact.First << "  (2)->: " << User[i].Contact.Second << "  (3)->: " << User[i].Contact.Third << endl;
					cout << "Creation Date: " << User[i].Creation_Date.Day << "-" << User[i].Creation_Date.Month << "-" << User[i].Creation_Date.Year << "\n\n";
				}
			}

			if (User[i].Creation_Date.Day - 31 > current_time_ptr->tm_mday - 7)     //check the Previous Month if -> [Days till a week ago >-< Exists]
			{
				cout << "\n\t(No." << -3 + i << ")  -> [" << User[i].User_Name << "] <-\n";
				cout << "Password: " << User[i].Password << "   ,   " << "ID: " << User[i].ID << "   ,   " << "Authority: " << User[i].Account_type << "   ,   " << "Email: " << User[i].Email << endl;
				cout << "Contacts:" << "  (1)-> : " << User[i].Contact.First << "  (2)->: " << User[i].Contact.Second << "  (3)->: " << User[i].Contact.Third << endl;
				cout << "Creation Date: " << User[i].Creation_Date.Day << "-" << User[i].Creation_Date.Month << "-" << User[i].Creation_Date.Year << "\n\n";
			}

		}

	}//[For loop] --> ends Here

}

bool Back_Option_fn(int back_option)                                                                                                            //Back Obtion fn//
{
	cout << "\n\n\n***********************************************************************\n";
	cout << "\n\t° --> To Return Menu,, Enter [0] --> ";
	cin >> back_option;

	if (Back_Option_fn == 0)
		return true;     //Back Successed,, Returning to Menu

	while (back_option != 0)     //Invalid input & Try again
	{
		cout << "\n\t\tInvalid ";
		cout << "\n\t° --> To Return Menu,, Enter [0] --> ";
		cin >> back_option;

		if (Back_Option_fn == 0)
			return true;
	}
	system("cls");
}
/////////////////////////////////////////////////////////////////////--> End of Functions <--/////////////////////////////////////////////////////////////////////

int main()
{
	system("Color F0");     //to set the council's --> [background -> WHITE] & [text -> BLACK]

	/////--> Initializing <--/////
	int choise = 0;
	int New_Users_Num = 0;
	string Login_Username = {};
	string Login_Password = {};
	string Book_Title = {};
	int Book_Prod_Year = 0;
	int back_option = 1;

	////////////////////////////////////////--> (4) Librarians Accounts <--////////////////////////////////////////
	User[0].User_Name = "ahmed";
	User[0].Password = "111";
	User[0].ID = 1;
	User[0].Account_type = "staff";                                                                       //Staff//
	User[0].Email = "ahmed@gmail.com";
	User[0].Contact.First = 01111111111;  User[0].Contact.Second = 01222222222;  User[0].Contact.Third = 01333333333;
	User[0].Creation_Date.Day = 21;  User[0].Creation_Date.Month = 1;  User[0].Creation_Date.Year = 2020;
	////////////////////////////////////////
	User[1].User_Name = "mohamed";
	User[1].Password = "222";
	User[1].ID = 2;
	User[1].Account_type = "staff";                                                                       //Staff//
	User[1].Email = "mohamed@gmail.com";
	User[1].Contact.First = 02111111111;  User[1].Contact.Second = 02222222222;  User[1].Contact.Third = 02333333333;
	User[1].Creation_Date.Day = 22;  User[1].Creation_Date.Month = 2;  User[1].Creation_Date.Year = 2020;
	////////////////////////////////////////
	User[2].User_Name = "omer";
	User[2].Password = "333";
	User[2].ID = 3;
	User[2].Account_type = "guest";                                                                       //guest//
	User[2].Email = "omar@gmail.com";
	User[2].Contact.First = 03111111111;  User[2].Contact.Second = 03222222222;  User[2].Contact.Third = 03333333333;
	User[2].Creation_Date.Day = 23;  User[2].Creation_Date.Month = 3;  User[2].Creation_Date.Year = 2020;
	////////////////////////////////////////
	User[3].User_Name = "eslam";
	User[3].Password = "444";
	User[3].ID = 4;
	User[3].Account_type = "student";                                                                   //Student//
	User[3].Email = "eslam@gmail.com";
	User[3].Contact.First = 04111111111;  User[3].Contact.Second = 04222222222;  User[3].Contact.Third = 04333333333;
	User[3].Creation_Date.Day = 24;  User[3].Creation_Date.Month = 4;  User[3].Creation_Date.Year = 2020;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////--> (12) Books already registered <--////////////////////////////////////////
	Book[0].Title = "programming";
	Book[0].Production_Date.Year = 2009;
	Book[0].Category = "PROGRAMMING";
	Book[0].Num_of_Copies = 1;
	Book[0].Edition = 1;
	////////////////////////////////////////
	Book[1].Title = "english";
	Book[1].Production_Date.Year = 2010;
	Book[1].Category = "ENGLISH";
	Book[1].Num_of_Copies = 2;
	Book[1].Edition = 3;
	////////////////////////////////////////
	Book[2].Title = "arabic";
	Book[2].Production_Date.Year = 2011;
	Book[2].Category = "ARABIC";
	Book[2].Num_of_Copies = 3;
	Book[2].Edition = 5;
	////////////////////////////////////////
	Book[3].Title = "maths";
	Book[3].Production_Date.Year = 2012;
	Book[3].Category = "MATHS";
	Book[3].Num_of_Copies = 1;
	Book[3].Edition = 7;
	////////////////////////////////////////
	Book[4].Title = "history";
	Book[4].Production_Date.Year = 2013;
	Book[4].Category = "HISTORY";
	Book[4].Num_of_Copies = 2;
	Book[4].Edition = 2;
	////////////////////////////////////////
	Book[5].Title = "science";
	Book[5].Production_Date.Year = 2014;
	Book[5].Category = "SCIENCE";
	Book[5].Num_of_Copies = 3;
	Book[5].Edition = 4;
	////////////////////////////////////////
	Book[6].Title = "geography";
	Book[6].Production_Date.Year = 2015;
	Book[6].Category = "GEOGRAPHY";
	Book[6].Num_of_Copies = 1;
	Book[6].Edition = 6;
	////////////////////////////////////////
	Book[7].Title = "physics";
	Book[7].Production_Date.Year = 2016;
	Book[7].Category = "PHYSICS";
	Book[7].Num_of_Copies = 2;
	Book[7].Edition = 8;
	////////////////////////////////////////
	Book[8].Title = "psychology";
	Book[8].Production_Date.Year = 2017;
	Book[8].Category = "PSYCHOLOGY";
	Book[8].Num_of_Copies = 3;
	Book[8].Edition = 1;
	////////////////////////////////////////
	Book[9].Title = "chemistry";
	Book[9].Production_Date.Year = 2018;
	Book[9].Category = "CHEMISTRY";
	Book[9].Num_of_Copies = 1;
	Book[9].Edition = 3;
	////////////////////////////////////////
	Book[10].Title = "biology";
	Book[10].Production_Date.Year = 2019;
	Book[10].Category = "BIOLOGY";
	Book[10].Num_of_Copies = 2;
	Book[10].Edition = 5;
	////////////////////////////////////////
	Book[11].Title = "french";
	Book[11].Production_Date.Year = 2020;
	Book[11].Category = "FRENCH";
	Book[11].Num_of_Copies = 3;
	Book[11].Edition = 7;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////--> Main >< Menu <--//////////////////////////////////////////////////
	do
	{
		back_option = 1;     //To Enter the (Do --> While) LOOP

		cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t@@@@ -------> WELCOME to: <------- @@@@";
		cout << "\n\t\t@@@@-> Library Management System <-@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << "\n\n";

		////////////////////--> Options <--////////////////////
		cout << "\n\t° Enter >-[1]-> to:-> Register User\n";
		cout << "\n\t° Enter >-[2]-> to:-> Weekly Report\n";
		cout << "\n\t° Enter >-[3]-> to:-> Buy Books\n";
		cout << "\n\t° Enter >-[4]-> to:-> Search Books\n";
		cout << "\n\t° Enter >-[0]-> to:-> EXIT\n\n";

		cout << "\n\n\n***********************************************************************\n";
		cout << "\n\t° -> Your Choise is:-> ";
		cin >> choise;

		while (choise != 0 && choise != 1 && choise != 2 && choise != 3 && choise != 4)     //Invalid input & try again
		{
			cout << "\t\tInvalid ";
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choise; cout << endl;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (choise == 1)     //Option --> [1]
		{
			system("cls");
			if (Admin_Login_fn(Login_Username, Login_Password) == 1)     //If Admin Login is Valid,, Continue to Registration
			{
				system("cls");
				cout << "\n\n\n\t--> Adminstration Login is Valid <--\n";     //Allowed
				cout << "\n\n\n***********************************************************************\n";
				cout << "\n\n\t---------------------\n\t-->  New Register <--\n\t---------------------\n\n";

				cout << "\n\n\n\t° Enter number of New Users: ";
				cin >> New_Users_Num;

				system("cls");
				Register_fn(New_Users_Num);
				Back_Option_fn(back_option);     //Returns to Menu 
			}

			else
			{
				cout << "\n\n\t--> Sorry,, You are not allowed to do this Process <--\n";     //Denied
				Back_Option_fn(back_option);     //Returns to Menu,, If there is invalid Login
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (choise == 2)     //Option --> [2]
		{
			system("cls");
			cout << "\n\n\t---------------------\n\t--> Weekly Report <--\n\t---------------------\n\n";
			Weekly_Report_fn(New_Users_Num);
			Back_Option_fn(back_option);     //Returns to Menu
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (choise == 3)     //Option --> [3]
		{
			system("cls");
			if (Admin_Login_fn(Login_Username, Login_Password) == 1)
			{
				system("cls");
				cout << "\n\n\n\t--> Adminstration Login is Valid <--\n";     //Allowed
				cout << "\n\n\n***********************************************************************\n";
				cout << "\n\n\t---------------------\n\t-->    Buy Book   <--\n\t---------------------\n\n";
				Buy_Book_fn(Book_Title, Book_Prod_Year);
				Back_Option_fn(back_option);     //Returns to Menu 
			}

			else
			{
				cout << "\n\n\t--> Sorry,, You are not allowed to do this Process <--\n";     //Denied
				Back_Option_fn(back_option);     //Returns to Menu,, If there is invalid Login
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (choise == 4)     //Option --> [4]
		{
			system("cls");
			if (Login_fn(Login_Username, Login_Password) == 1)
			{
				system("cls");
				cout << "\n\n\n\t--> Login is Valid <--\n";     //Allowed
				cout << "\n\n\n***********************************************************************\n";
				cout << "\n\n\t---------------------\n\t-->  Search Books <--\n\t---------------------\n\n";
				Search_Book_fn(Book_Title, Book_Prod_Year);
				Back_Option_fn(back_option);     //Returns to Menu
			}

			else
			{
				cout << "\n\n\t--> Login is not Valid <--\n";     //Denied
				Back_Option_fn(back_option);     //Returns to Menu,, If there is Invalid Login
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (choise == 0)     //Option --> [EXIT]
			back_option = 0;     //To Scape the (Do --> While) LOOP
		////////////////////////////////////////////////////////////////////////////////////////////////////
	} while (back_option != 0);     //LOOPs --> During Back_fn is true

	return 0;
	//////////////////////////////////////////////////--> End Program <--//////////////////////////////////////////////////
}