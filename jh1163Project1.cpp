/* 	Author: Jihad Hamad, Student ID# 11458410, JihadHamad@my.unt.edu
	Date: October 9, 2022
	Instructor: Dr. Shrestha
	Description: A program that displays different "animations" of the shapes Square, Triangle, and Pentagon, and a special "animation" of a user prompted string.
	The user enters a length size for the shapes, and each shape is made out of a random ASCii value. The special sentence option is made to remove numbers from the user String.
*/



#include<iostream>		// multiple headers that allow different functions in the code to function properly, such as isdigit, cin.ignore, string prompts, and bool variable Valid
#include<cctype>
#include<string>
#include<stdbool.h>
#include<unistd.h> 
#include<cstdio>
using namespace std;

int main()
{

	enum Options{Square = 1, Triangle = 2, Pentagon = 3, Sentence = 4, Quit = 5}; // enumeration list used for the switch case for the user menu after size is inputted


	Options user_Choices; 		// connecting the enumeration list to variable user_Choices, that will be connected to the choice variable


	int length;			// decleration of the intger variables length, randomNum, and choice
   	int randomNum;
	int choice;


   	char symbol;			// decleration of the character variables symbol and againChoice
	char againChoice;


	string userString;		// decleration of the string variables userString and newString


    	bool Valid;			// decleration of the boolean variable Valid
	


	
    	do{				// a do while loop that asks the user to input the length of the shape animations, and repeats if the length is not an odd number


	cout << "What is the size of your animation?: "; cin >> length; cout << endl;		// prompting for and asking for user to input length

        if(length % 2 == 1){
            cout << "What would you like to generate?"; cout << endl;	// program continues if the remainder of the length value divided by 2 is 1, meaning odd
        }

        else if(length % 2 == 0){
            cout << "Sorry you have to input an odd number for the size\n\n";
        }
    
    	}while(length % 2 == 0);	// repeats if the remainder of the length value divided by 2 is 0



    
    
    srand(time(NULL));			// seeding for the random number which will be the ASCii value of the random symbol for the shape animations



    do{							// start of the do while loop that asks the user for their animation options


    randomNum = (rand() % 31) + 34;			// assigning randNum variable with a random number


    symbol = static_cast<char>(randomNum);		// static casting the randNum number into a character symbol or number, that is assigned into the symbol variable


    user_Choices = static_cast<Options>(choice);	// static casting the the choice variable into the Options enumeration and assigning it to the user_Choices variable


	// displaying the menu to the user and reading in their option into the integer value choice


    cout << "1.Square\n2.Triangle\n3.Pentagon\n4.Sentence\n5.Quit\nWhat is your choice?: "; cin >> choice; cout << endl;


    switch (choice)	//start of the switch case from all options connected to the choice variable, which is connected to the enumeration variable user_Choices
    {


    case Square:				// the square option activates a triple nested for loop that displays the individual character squares, then system clears, making the display look "amimated"	
        for(int g = 0; g < length; g++){

	    system("clear");

		for(int v = 0; v <= g; v++){
	
        		for (int i = 0; i <= g; i++){

                    	cout << symbol;
        }

	    cout << endl;

	}

	sleep(1);				// sleep function is what slows down program iteration to appear that it "Animates"

	}

     cout << endl;

	// displaying and reading in a message asking if the user would like to repeat the program and be sent back to the menu, user enters y or n into the variable againChoice

	cout << "Would you like to go again? Yes(Y)/No(N): "; cin >> againChoice;
		
		againChoice = toupper(againChoice);	// if the user enters a lowercase y or n, it is changed into its uppercase form to use for the if statement below	
		

		if(againChoice == 'Y'){			// if againChoice is "Y", the bool variable Valid is set to false, which loops the do while loop and shows the menu again
		Valid = false;
		
		}
		else if(againChoice == 'N'){		// if againChoice is "N", variable Valid is set to true, and stops the do while loop, showing the ending message and exiting the program
		Valid = true;
		}

        break;

    case Triangle:
	system("clear");		// clearing the screen to output the triangle pattern

	// a double nested for loop that makes the triangle pattern

	for (int i = 1; i <= length; i++){

            for (int j = length; j >= i; j--){
                
           	cout << " ";
		}

		for (int h = 1; h <= i; h++){
		
		cout << symbol;

		if(h !=1){			// an if loop that takes off the second symbol at the start of the pyramid, checking when h is not 1 and displaying the random symbol if so
		
		cout << symbol;

		}
		}
		cout << endl;
		sleep(1);
        	}

		// the if statment and againChoice variable read in as described in the square case at the begginning of the swtich case

		cout << "Would you like to go again? Yes(Y)/No(N): "; cin >> againChoice;
		
		againChoice = toupper(againChoice);
		
		if(againChoice == 'Y'){
		Valid = false;
		
		}
		else if(againChoice == 'N'){
		Valid = true;
		}

	break;

    case Pentagon:
	system("clear");


		// the Pentagon combines the "animation" of the triangle first then the Square animation second 


	for (int i = 1; i <= length ; i++){

            for (int j = length; j >= i; j--){
                
           	cout << " ";

		}
		for (int h = 1; h <= i; h++){
		
		cout << symbol;

		if(h !=1){
		
		cout << symbol;

		}
		}

		cout << endl;

		sleep(1);
        	}


		// the square animation has one less loop to have the concurrent animation style of the triangle 


		for(int g = 0; g < length - 1; g++){	// the outer loop iterater one less than the length variable so that the base of the triangle is connected to the top of the square

			cout << " ";

        		for (int i = 0; i <= length * 2 - 2; i++){	// the inner loops length is doubled and lessened by two so that the width is big enough to cover the base of the triangle
			
                    	cout << symbol;

			}
			cout << endl;
			sleep(1);

			}

			// the user prompted repeat message as described in the previous cases 

		cout << "Would you like to go again? Yes(Y)/No(N): "; cin >> againChoice;
		
		againChoice = toupper(againChoice);
		
		if(againChoice == 'Y'){
		Valid = false;
		
		}
		else if(againChoice == 'N'){
		Valid = true;
		}


        break;

    case Sentence:
	system("clear");



	cout << "Enter words and string: "; 		// program asking to input words and strings 
	cin.ignore(); getline(cin, userString); 	// the cin.ignore helps to clear the input buffer and allow getline to work properly
	cout << endl;


		// the double nested for loop that controls the sentence animation 

		for(int i = 0; i < userString.length(); i++){	

				if (isdigit(userString[i])){		// the if statement that looks through every character in userString, and sees if it an integer or not

					userString.erase(i, 1);
					i--;				// i is set back by one if the character is an integer 
					}

					system("clear");
	
        				for (int j = 0; j < i; j++){

					cout << endl;

					}

					cout << userString;
					cout << endl;
					sleep(1);
					
		}

	cout << endl;


	// the user prompted repeat message as described in the previous cases

	
	cout << "Would you like to go again? Yes(Y)/No(N): "; cin >> againChoice;
		
		againChoice = toupper(againChoice);
		
		if(againChoice == 'Y'){
		Valid = false;
		
		}
		else if(againChoice == 'N'){
		Valid = true;
		}

	break;

    case Quit:		// the Quit case, if selected, the program displays a goodbye message and exits the program

	cout << "Game Over, See You Soon!!\n"; 
	exit(0);
        break;
    
    default:		// if the user enters an invalid choice not from the Options enumeration, the message displays, and variable Valid is set to false, so that the do while loop loops	
      
	  cout << "You Entered a Wrong choice\n\n";

    Valid = false;
        break;
    }

    }while(Valid == false);

	cout << "Game Over, See You Soon!!\n";	// the ending user message if they choose not to repeat the options

return 0;
}

ннннннн