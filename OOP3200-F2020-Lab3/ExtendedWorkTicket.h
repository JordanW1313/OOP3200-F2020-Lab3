#pragma once

#ifndef _EXTENDED_WORKTICKET
#define _EXTENDED_WORKTICKET

#include "WorkTicket.h"
//#include "ExtendedWorkTicket.cpp"

class ExtendedWorkTicket : public WorkTicket
{
public:

	/*ExtendedWorkTicket(int myTicketNumber = 0, string myClientID = " ", int day = 1, int month = 1, int year = 2020, string myDescription = " ", bool myOpen = true) :
		WorkTicket(myTicketNumber, myClientID, day, month, year, myDescription), isOpen{ myOpen } {

	}*/

	ExtendedWorkTicket(int myTicketNumber, string myClientID, int day, int month, int year, string myDescription, bool myOpen);

	void CloseTicket();

	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
		description, bool myOpen);

	void ShowWorkTicket() const override;

	friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);

private:
	bool isOpen;
};

ExtendedWorkTicket::ExtendedWorkTicket(int myTicketNumber, string myClientID, int day, int month, int year, string myDescription, bool myOpen)
{
	SetTicketNumber(myTicketNumber);
	SetClientId(myClientID);
	SetDate(day, month, year);
	SetDescription(myDescription);
	isOpen = myOpen;
}

void ExtendedWorkTicket::CloseTicket()
{
	isOpen = false;
}

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