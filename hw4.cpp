//Programmer: Madison Passolano   Date: 02/23/2020
//File: hw4.cpp                   class: cs 1570 
//Purpose: To find either the result of the cube root of a number or the
//         result of a number raised to a power


#include <iostream>
#include <cstdio>

using namespace std; 

int main()
{
/*---------declare variables-----------------------*/ 
	short choice;     //what the user inputs as their menu choice 
	short base_num;   //the base number that will be used for calculations
	short expo_num;   //the number the base_num will be raised to
	short res_pow = 1;//the result of the power calculation    
	
	float res_cube;   //the result of the cube root calculation 

	bool quit = false;              //whether or not the user has selected quit
	bool entered_base_num = false;  //whether or not the base_num was entered  

	cout<<"\n\nWelcome to The Cube Root and Power Calculator."<<endl; 
	do
	{
		//outputting the menu for the options
		cout<<"\n      Menu"<<endl; 
		cout<<"1. Enter a number"<<endl; 
		cout<<"2. Power the number"<<endl;
		cout<<"3. Cube root of the number"<<endl; 
		cout<<"4. Quit"<<endl<<endl; 

		cout<<"Select an option (1-4): "; 
		cin>>choice; 
		
		switch(choice)
		{
		/*--------case 1----------------------------*/
			case 1: 
				do
				{ 
					cout<<"Input a positive integer: "; 
					cin>>base_num;
					cout<<endl; 
					//if input is not a positive integer, display error message
					if(base_num < 0) 
						cout<<"\nInvalid input, only enter positive integers.\n\n";  
				}while(base_num < 0); //base_num do while 
				cout<<"The base number to be used is "<<base_num<<"."<<endl; 
				entered_base_num = true; //allows for options 2 and 3 to work
				break;
		
		/*--------case 2---------------------------*/
			case 2: 
				if(entered_base_num == true) //if user did enter number in option 1
				{
					do
					{ 
						cout<<"Input the exponent "<<base_num<<" will be raised to: "; 
						cin>>expo_num; 
						//if number entered isnt a positive integer, display error msg
						if(expo_num < 0)
							cout<<"\nInvalid input, only input positive integers.\n\n"; 
					}while(expo_num < 0);// do while expo_num is negative
					//for loop computes base_num raised to expo_num
					for(int i=0; i < expo_num; i++)
					{
						res_pow = res_pow * base_num;
						//formula to find a number raised to the power of another number 
					} 
					cout<<base_num<<" raised to "<<expo_num<<" is "<<res_pow<<"."<<endl;
					res_pow = 1;   
					break;   
				}
				else
				{ 
					//if user did not input a base_num yet in step one
					cout<<"\nError: return to menu and input the base number in option 1.\n\n";
					break;  
				}

		/*-------case 3----------------------------*/
			case 3:
				if(entered_base_num == true)
				{
					cout<<"\nCalculating the cube root of "<<base_num<<"..."<<endl;
					res_cube = base_num; //uses res_cube as a place holder 

					for(int j=0; j<10; j++)
					{
						res_cube = ((2.0*res_cube) + (base_num/(res_cube*res_cube)))/3.0;
						//cube root formula  
					}
					cout<<"\nThe cube root of "<<base_num<<" is "<<res_cube<<"."<<endl; 
					break; 
				}
				else 
				{
					//if user did not input base_num in option 1
					cout<<"\nError: return to menu and input the base number in option 1."<<endl;
					break; 
				}
		/*------case 4----------------------------*/
			case 4: 
				cout<<"\nGoodbye."<<endl<<endl; 
				quit = true; //sets quit to true and ends the code 
				break; 

		/*------default case---------------------*/
			default: 
				cout<<"\nInvalid input, only enter positive integers from 1 to 4.\n\n";

				//this runs when there isn't a number between 1-4
				//takes the user back to the main menu so they can try again. 

		}
	}while(quit != true); //big do while loop     
	//encompasses almost entire code, used to continuously run the code until 
	//the quit option is selected 

	return 0; 
}
