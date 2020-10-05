#pragma once

#ifndef _EXTENDED_WORKTICKET
#define _EXTENDED_WORKTICKET

#include "WorkTicket.h"

/*   Class Declaration Section   */
class ExtendedWorkTicket : public WorkTicket
{
public:

	// Default constructor
	ExtendedWorkTicket()
	{
		WorkTicket();
		isOpen = true;
	}

	// Constructor declaration.
	ExtendedWorkTicket(int myTicketNumber, string myClientID, int day, int month, int year, string myDescription, bool myOpen);

	// CloseTicket function declaration.
	void CloseTicket();

	// Mutator
	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
		description, bool myOpen);

	void ShowWorkTicket() const override;

	friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);

private:
	// Data members exclusive to ExtendedWorkTicket.
	bool isOpen;
};

// Parameterized constructor for an ExtendedWorkTicket obj.
ExtendedWorkTicket::ExtendedWorkTicket(int myTicketNumber, string myClientID, int day, int month, int year, string myDescription, bool myOpen)
{
	SetTicketNumber(myTicketNumber);
	SetClientId(myClientID);
	SetDate(day, month, year);
	SetDescription(myDescription);
	isOpen = myOpen;
}

// Is called when a ticket is to be closed.
void ExtendedWorkTicket::CloseTicket()
{
	isOpen = false;
}

// Overloading SetWorkTicket() to also include myOpen, a boolean variable.
bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool myOpen)
{
	bool valid = true;

	if (myOpen != true)
	{
		valid = false;
	}
	else
	{
		WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description);
		isOpen = myOpen;
	}

	return valid;
}

// Overriding ShowWorkTicket() from WorkTicket.
void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();
	if (isOpen == true)
	{
		cout << "Ticket: OPEN" << endl;
	}
	else
	{
		cout << "Ticket: CLOSED" << endl;
	}

}

// Overloading the "<<" Operator.
ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	string valid;

	if (ticket.isOpen == true)
	{
		valid = "OPEN";
	}
	else
	{
		valid = "CLOSED";
	}

	out << (WorkTicket)ticket
		<< "Open:          " << valid << endl;

	return out;
}

#endif