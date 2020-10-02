#pragma once

#ifndef _EXTENDED_WORKTICKET
#define _EXTENDED_WORKTICKET

#include "WorkTicket.h"

class ExtendedWorkTicket : public WorkTicket
{
public:

	/*ExtendedWorkTicket() : WorkTicket()
	}
		SetTicketNumber(0);
		SetClientId(" ");
		SetDate(1, 1, 2020);
		SetDescription(" ");
		isOpen = true;
	};*/
	ExtendedWorkTicket(int myTicketNumber, string myClientID, int day, int month, int year, string myDescription, bool myOpen);

	void CloseTicket();

	bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
		description, bool myOpen);

	void ShowWorkTicket() const override;

private:
	bool isOpen;
};


#endif