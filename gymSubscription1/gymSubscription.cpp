#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct fitnes
{
	char name[20]{}, data[20]{}, gender[20]{}, city[20]{};
	int  danni{}, nomer{}, visit{}, serialnum{}, egn{}, age{}, day{}, month{}, year{};
	double cena{}, time{};
};
void n(fitnes* b, int& Count, fitnes cus)
{
	b[Count] = cus;
	Count++;
}
void addnewcustomer(fitnes* b, int& Count)
{
	srand(time(0));
	fitnes addnewcustomer;
	fitnes card;
	int cardchoice;
	if (Count > 100)
	{
		cout << "   |<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "    You cannot enter more than 100 customers!" << endl;
		cout << "             Returning to main menu..." << endl;
		cout << "   |<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
		return;
	}
	system("cls");
	cout << " Enter the date upon joining the gym. " << endl; 
	cout << "Enter day: " << endl;;
	cout << "=>";
	cin >> addnewcustomer.day;
	cout << "Enter month (in number): " << endl;
	cout << "=>";
	cin >> addnewcustomer.month;
	if (addnewcustomer.month < 1 || addnewcustomer.month > 12)
	{
		cout << " Enter a month from 1 to 12 ! " << endl;
		system("pause");
		return;
	}
	cout << "Enter year: " << endl;
	cout << "=>";
	cin >> addnewcustomer.year;
	cout << endl;
	cout << "\n Enter the time upon joining the gym." << endl; 
	cout << " => ";
	cin.ignore(0);
	cin >> addnewcustomer.time;
	cout << "\n What is the name of the new customer?" << endl; 
	cout << " => ";
	cin.ignore(0);
	cin >> addnewcustomer.name;
	cout << " What is the personal ID of the customer?" << endl; 
	cout << " => ";
	cin.ignore();
	cin >> addnewcustomer.egn;
	cout << "\n What is the gender of the new customer?" << endl;
	cout << "Choose Male/Female" << endl;
	cout << "=>";
	cin.ignore(0);
	cin >> addnewcustomer.gender;
	cout << "\n What is the customer's age?" << endl; 
	cout << " => ";
	cin >> addnewcustomer.age;
	cout << "\n Residential city of the customer?" << endl;
	cout << " => ";
	cin.ignore();
	cin >> addnewcustomer.city;
	do
	{
		cout << "\n How many visits do you want to add to your card?" << endl; 
		cout << " 1. 10 visits / 30 lv." << endl;
		cout << " 2. 15 visits / 40 lv." << endl;
		cout << " 3. 20 visits / 50 lv." << endl;
		cout << " => ";
		cin >> cardchoice;
	} while (cardchoice < 1 || cardchoice > 3);

	if (cardchoice == 1)
	{
		addnewcustomer.serialnum = rand() % 200000 + 100000;
		addnewcustomer.visit = 10;
		addnewcustomer.cena = 30;
	}
	if (cardchoice == 2)
	{
		addnewcustomer.serialnum = rand() % 200000 + 100000;
		addnewcustomer.visit = 15;
		addnewcustomer.cena = 40;
	}
	if (cardchoice == 3)
	{
		addnewcustomer.serialnum = rand() % 200000 + 100000;
		addnewcustomer.visit = 20;
		addnewcustomer.cena = 50;
	}
	n(b, Count, addnewcustomer);
	if (Count > 0);
	{
		cout << "\n|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "     You have entered " << Count << " customer/s/." << endl;
		cout << "     You can enter " << 100 - Count << " more." << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
	}
}
void ShowCustomers(fitnes* b, int& Count)
{
	if (Count < 1)
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "  You must enter at least 1 customer for this option to take effect." << endl;
		cout << "           You have entered " << Count << " so far." << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
		system("pause");
	}
	else if (Count > 0)
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "                         Customer List" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << " Number:" << i + 1 << " | Day:" << b[i].day << "| Month:" << b[i].month << "| Year:" << b[i].year << " | Time:" << b[i].time << " | Name:" << b[i].name << "| Personal ID: " << b[i].egn << " | City:" << b[i].city << " | Age: " << b[i].age << " | Serial Number:" << b[i].serialnum << " | Visits left: " << b[i].visit << " | Price paid: " << b[i].cena << endl;
		}
		cout << endl;
		system("pause");
	}


}

void correct(fitnes* b, int& Count)
{
	string search;
	int c3;
	int c1, c2;
	system("cls");
	if (Count < 1)
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "   You have to enter customers first to take effect!" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
	}
	else
	{
		cout << "\n Enter customer name: " << endl; 
		cout << "=>";
		cin >> search;
		for (int i = 0; i < Count; i++)
		{
			if (search == b[i].name)
			{
				system("cls");
				cout << "\n Enter the new personal id of the customer: " << endl; 
				cout << "=>";
				cin.ignore(0);
				cin >> c1;
				b[i].egn = c1;
				cout << "\n Personal ID successfully corrected!" << endl << endl;
				cout << "\n Choose new age for the customer: " << endl; 
				cout << "=>";
				cin >> c2;
				b[i].age = c2;
				cout << "\n Age successfully corrected!" << endl << endl;
				system("pause");
			}

		}
	}
}
void clean(fitnes* b, int& Count)
{
	string cln;
	system("cls");
	if (Count < 1)
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "   You have to enter customers first to take effect!" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
	}
	else
	{
		cout << "\n Enter the customer's name: " << endl;
		cout << "=>";
		cin >> cln;
		for (int i = 0; i < Count; i++)
		{
			if (cln == b[i].name)
			{
				b[i].cena = 0;
				b[i].visit = 0;
			}
		}
		cout << "|<<<<<<<<<<<>>>>>>>>>>>>|" << endl;
		cout << " Successfully refunded!" << endl;
		cout << "|<<<<<<<<<<<>>>>>>>>>>>>|" << endl;
		system("pause");
	}
}
void addworkout(fitnes* b, int& Count)
{
	system("cls");
	string search;
	double c4;
	if (Count < 1)
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "   You have to enter customers first to take effect!" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
	}
	for (int i = 0; i < Count; i++)
	{
		do
		{

			cout << " => Enter customer name: ";
			cin >> search;
			if (search == b[i].name)
			{
				system("cls");
				cout << "\n Enter the time of the workout: " << endl;
				cout << "=>";
				cin >> c4;
				b[i].time = c4;
			}
			if (search == b[i].name)
			{
				b[i].visit -= 1;
				cout << "  Customer has finished workout!" << endl << endl;
				system("pause");
				return;
			}
			else if (search != b[i].name)
			{
				cout << "  Name (" << search << ") not found in customer list!" << endl;
				cout << "  Please try again!" << endl;
				system("pause");
				break;
			}
		} while (search != b[i].name);

		if (b[i].visit == 0)
		{
			cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
			cout << " The customer has ran out of visits, please buy a new card!" << endl;
			cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
			system("pause");
			return;
		}
	}

}
void renewal(fitnes* b, int& Count)
{
	system("cls");
	int renew;
	if (Count < 1)
	{
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>|" << endl;
		cout << " There are no customers added in the system!" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>|" << endl;
		system("pause");
	}
	else
	{

		cout << " Customers with no visits left:" << endl;
		cout << "--------------------------------" << endl << endl;
		for (int i = 0; i < Count; i++)
		{
			if (b[i].visit == 0)
			{
				cout << "How many visits do you want to add to " << b[i].name << "'s card? " << endl;
				cout << "=> ";
				cin >> renew;
				b[i].visit += renew;
				for (int j = 0; j < renew; j++)
				{
					b[i].cena += 3;
				}
			}
		}
		cout << endl << " Customers with visits left:" << endl;
		cout << "-------------------------------" << endl << endl;
		for (int i = 0; i < Count; i++)
		{
			if (b[i].visit > 0)
			{
				cout << b[i].name << " has " << b[i].visit << " visits left! " << endl;
			}
		}
		cout << endl;
		system("pause");
		return;
	}
}


void binary(fitnes* b, int& Count)
{
	fitnes Data;
	fstream File;
	File.open("FitnesData.bin", ios::binary | ios::out);
	if (File.is_open())
	{
		File.write((char*)b, sizeof(fitnes) * Count);
		File.close();
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "|                            Data has been successfully saved to binary!                   |" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "|                                Couldn't open the binary file!                            |" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
		system("pause");
	}
}

int Binaryread(fitnes* b)
{
	long pos;
	int n = 0;
	fitnes Data;
	fstream File;
	File.open("FitnesData.bin", ios::binary | ios::in);
	if (!File) {
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "|                 There is no binary file data entered to run the program!                   |" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
		system("pause");
		return n;
	}
	File.seekg(0l, ios::end);
	pos = File.tellg();
	File.close();
	n = pos / (sizeof(fitnes));

	File.open("FitnesData.bin", ios::binary | ios::in);
	if (!File) {
		system("cls");
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
		cout << "|                                Couldn't open the binary file!                              |" << endl;
		cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>| " << endl << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		File.read((char*)&Data, sizeof(fitnes));
		b[i] = Data;
	}
	File.close();
	return n;
}
void main()
{
	fitnes b[100];
	int o;
	int Newcustomer = Binaryread(b);
	int choice;
	do
	{
		system("cls");
		cout << "   ___________________ " << endl;
		cout << "  |                   |" << endl;
		cout << "  |     Main Menu     |" << endl;
		cout << " _|___________________|_____________________________________" << endl;
		cout << "| 1. Add new customer with card                             |" << endl; 
		cout << "| 2. Add multiple customers with cards                      |" << endl;
		cout << "| 3. Show customers                                         |" << endl;
		cout << "| 4. Correct data of a customer                             |" << endl;
		cout << "| 5. Refund customer's visits and price                     |" << endl;
		cout << "| 6. Do a workout for a certain customer                    |" << endl;
		cout << "| 7. Renew the customer's card                              |" << endl;
		cout << "| 8. Write to binary                                        |" << endl;
		cout << "| 9. Exit the program                                       |" << endl;
		cout << "|___________________________________________________________|" << endl;
		cout << " Select an option: ";
		do {
			cout << "\n Your choice is:";
			cin >> choice;
		} while (choice < 1 || choice > 9);
		switch (choice)
		{
		case 1: addnewcustomer(b, Newcustomer); break;
		case 2:
		{   system("cls");
		int x;
		cout << "\n Choose X customers to add: "; 
		cin >> x;
		system("cls");
		if (x < 1)
		{
			system("cls");
			cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
			cout << "  You must enter at least 1 customer for this option to take effect." << endl;
			cout << "           You have entered " << Newcustomer << " so far." << endl;
			cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
			system("pause");
		}
		for (int i = 0; i < x; i++)
		{
			addnewcustomer(b, Newcustomer);
		}
		}
		break;
		case 3:
		{
			do
			{
				system("cls");
				cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
				cout << "                   Show Customer/s/" << endl;
				cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
				cout << "  1. Show all customers" << endl;  
				cout << "  2. Show customers with finished visits" << endl; 
				cout << "  3. Return back..." << endl << endl; 
				cout << "  => Choose an option: ";
				cin >> o;
			} while (o < 1 || o > 3);
			switch (o)
			{
			case 1:
			{
				do
				{
					system("cls");
					if (Newcustomer == 0)
					{
						system("cls");
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
						cout << "  You must enter at least 1 customer for this option to take effect." << endl;
						cout << "           You have entered " << Newcustomer << " so far." << endl;
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
						system("pause");
					}
					else if (Newcustomer < 100)
					{
						system("cls");
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
						cout << "                         CUSTOMER LIST" << endl;                                     
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
						for (int i = 0; i < Newcustomer; i++)
						{
							cout << " Number:" << i + 1 << endl << "| Day:" << b[i].day << endl << "| Month:" << b[i].month << endl << "| Year:" << b[i].year << endl << "| Time:" << b[i].time << endl << "| Name:" << b[i].name << endl << "| Personal ID: " << b[i].egn << endl << "| Gender: " << b[i].gender << endl << "| City:" << b[i].city << endl << "| Age: " << b[i].age << endl << "| Serial Number:" << b[i].serialnum << endl << "| Visits left: " << b[i].visit << endl << "| Price paid: " << b[i].cena << endl;
						}
						cout << endl;
						system("pause");
					}break;
				} while (true);
			}
			break;
			case 2:
			{
				do
				{
					system("cls");
					if (Newcustomer == 0)
					{
						system("cls");
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
						cout << "  You must have at least 1 customer with zero visits to take effect." << endl;
						cout << "           You have not entered any yet." << endl;
						cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
						system("pause");
					}
					for (int i = 0; i < Newcustomer; i++)
					{
						if (b[i].visit > 0)
						{
							cout << "|<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>|" << endl;
							cout << " There are no customers with zero visits left." << endl;
							cout << "|<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>|" << endl;
							system("pause");
							break;

						}
						else
						{
							system("cls");
							cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl;
							cout << "                    CUSTOMERS WITH NO VISITS LEFT" << endl;                     
							cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|" << endl << endl;
							for (int i = 0; i < Newcustomer; i++)
							{
								if (b[i].visit == 0)
								{
									cout << "| Name: " << b[i].name << endl << "| Age: " << b[i].age << endl << " | City: " << b[i].city << endl;
								}
							}cout << endl;
							system("pause");
							break;
						}
					}break;
				} while (true);
			}

			case 3:
			{
				break;
			}


			}
		}break;
		case 4:correct(b, Newcustomer); break;
		case 5:clean(b, Newcustomer); break;
		case 6:addworkout(b, Newcustomer); break;
		case 7:renewal(b, Newcustomer); break;
		case 8:binary(b, Newcustomer); break;
		}
	} while (choice != 9);
	{
		system("cls");
		cout << "|<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>|" << endl;
		cout << "  Thanks for using the program!" << endl;
		cout << "      Exiting..." << endl;
		cout << "|<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>|" << endl;
	}
}