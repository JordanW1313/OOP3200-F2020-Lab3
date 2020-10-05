/****************************************************************
* Name: Jordan Wriker & Ahmed Rizvi
* Date: 4th October, 2020
* Course: OOP-3200
* File: OOP3200-F2020-Lab3
* Purpose: The purpose of this iteration of Lab 2 is to create a new
*		   class called ExtendedWorkTicket, to work on the concept of
*		   inheritance. This new class determines whether a WorkTicket
*		   object is either open or closed.
*
******************************************************************/
#include <iostream>
#include "ExtendedWorkTicket.h"



int main()
{
	/* FIX THIS BY IMPLEMENTING A WORKING ExtendedWOrkTicket Class*/
	ExtendedWorkTicket testTicket1; // Obj created from default constructor.
	ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true); // Parameterized obj.

	// Displaying the test tickets.
	std::cout << std::endl << "As Initialized: " << std::endl;
	testTicket1.ShowWorkTicket();
	testTicket2.ShowWorkTicket();

	// Checks if testTicket1 has been changed from the default constructor initialization.
	if (!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl;

	//Checks if SetWorkTicket proceeds if there is an error in the parameters.
	if (!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 2: " << testTicket2 << std::endl;

	testTicket2.CloseTicket();

	std::cout << std::endl << "After Ticket 2 closed: " << testTicket2 << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}




