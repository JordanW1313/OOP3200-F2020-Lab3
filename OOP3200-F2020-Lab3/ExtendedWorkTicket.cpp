#include "ExtendedWorkTicket.h"

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
