#include <iostream>
#include <cmath>
#include <stdlib.h> 
#include <time.h> 
#include <stdio.h> 

using namespace std;

int main()
{
	int x,y,z,ws,wc,w,d,count=1;
	bool isValid = true;
	bool withdraw = true;

	ws = 1000;
	wc = 1000;
	x = 111;

	cout << "*** Welcome to Cal Poly's ATM ****\n\n";
	cout << "Please enter your PIN:\n";
	cin >> z;
	//keeps asking for user input until correct
	while(isValid!=false)
	{
		//if user input is correct, run this
		if(x==z)
		{
			cout << "*** Welcome to Cal Poly's ATM ****\n\n";
			cout<< "(1) Transfer from savings account to checking account.\n"
				<< "(2) Transfer from checking account to savings account.\n"
				<< "(3) Savings account balance.\n"
				<< "(4) Checking account balance.\n"
				<< "(5) Withdraw cash from either account.\n"
				<< "(6) Exit.\n"
				<< "==> Please select option (1-6):\n";
			cin >> y;
			//switch statement to select option from menu and repeat if not correct
			switch(y)
			{
			case 1:
				{
					cout<<"You have selected to Transfer from savings account to checking account.\n"
						<<"You have " << ws << "$ in your savings account.\n"
						<<"How much would you like to transfer?\n";
					cin >> d;
					//enough money
					if(d<=ws)
					{
						wc = wc+d;
						ws = ws-d;
						cout << "You now have " << wc << "$ left in your savings account.\n";
						cout << "You now have " << ws << "$ left in your checking account.\n";
						withdraw=false;
					}
					//not enough money
					else
					{
						system("CLS");
						cout<< "\nTransaction not completed.\n\n"
							<< "You only have "<<ws<<"$. \n\n";
					}
					continue;
				}
			case 2:
				{
					cout<<"You have selected to Transfer from checking account to savings account.\n"
						<<"You have " << ws << "$ in your checking account.\n"
						<<"How much would you like to transfer?\n";
					cin >> d;
					//enough money
					if(d<=wc)
					{
						ws = ws+d;
						wc = wc-d;
						cout << "You now have " << ws << "$ left in your savings account.\n";
						cout << "You now have " << wc << "$ left in your checking account.\n";
						withdraw=false;
					}
					//not enough money
					else
					{
						system("CLS");
						cout<< "\nTransaction not completed.\n\n"
							<< "You only have "<<wc<<"$. \n\n";
					}
					continue;
				}
				//prints savings balance
			case 3: 
				{
					cout << "\nYour balance in your savings account is:\n";
					cout << ws << "$\n\n";
					continue;
				}
				//prints checking balance
			case 4:
				{
					cout << "\nYour balance in your checking account is:\n";
					cout << wc << "$\n\n";
					continue;
				}
				//lets users withdraw
			case 5:
				{
					while(withdraw!=false)
					{
						cout << "Where would you like to withdraw from?\n"
							<< "(1) Checking Account.\n"
							<< "(2) Savings Account.\n";
						cin >> w;
					//select which account and repeat until correct
						switch(w)
						{
						case 1:
							{
								cout<<"You have selected Checkings.\n"
									<<"You have " << wc << "$ in your checking account.\n"
									<<"How much would you like to withdraw?\n";
								cin >> d;
								//has withdrawn money
								if(d<=wc)
								{
									wc = wc-d;
									cout << "You now have " << wc << "$ left in your checking account.\n";
									withdraw=false;
								}
								//not enough money
								else
								{
									cout << "\nYou don't have enough money.\nTry Again.\n";
								}
							}
							continue;
						case 2:
							{
								cout<<"You have selected Savings.\n"
									<<"You have " << ws << "$ in your savings account.\n"
									<<"How much would you like to withdraw?\n";
								cin >> d;
								//withdrawn money
								if(d<=ws)	
								{
									ws = ws-d;
									cout << "You now have " << ws << "$ left in your savings account.\n";
									withdraw=false;
								}
								//not enough money
								else
								{
									cout << "You don't have enough money.\nTry Again.\n";
									cin >> d;
								}
							}
							continue;
							//not valid option
						default:
							cout << "\nThis is not a valid option.\n\n";
							break;
						}
					}
					continue;
				}
			case 6:
				{
					//exited system
					cout << "\nThank you for using the ATM system.\n";
					isValid=false;
					break;
				}
			default:
				{
					//not valid option
					system("CLS");
					cout << "\nThis is not a valid option.\n\n";
				}
			}
		}
		//has input wrong pin number
		else if (count<3)
		{	
			cout << "Wrong pin! Please try again.\n\n";
			++count;
			cout << "*** Welcome to Cal Poly's ATM ****\n\n";
			cout << "Please enter your PIN:\n";
			cin >> z;
		}
		else if (count>=3)
		{
			cout << "Too many illegal PINS. Try again later.\n";
			return 0;
		}
	}
	return 0;
}