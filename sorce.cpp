#include <iostream>
using namespace std;
#define sep "\t|"

struct schedule {
	int flight_num, available_seats, flight_date[3];
	string departure_city;
	int  taking_off_hour, taking_off_minute;
	string arrival_city;
	int  reaching_hour, reaching_minute;
};
struct passenger {
	string ID, name, address, phone_number, log, email, password;
};
struct ticket {
	string number, passenger_ID;
	int flight_date[3], flight_num;
};


bool login(string email, string pass);
void loginPrompt();
void adminPrompt();
string emailPrompt();
void signUp();
int menu();

void add_schedule();
void edit_schedule(int k);
void Delete_Flight_Num(int q);
bool admin_access();

schedule get_flight(int flightNumber);
ticket get_ticket(string ticketNumber);

void cancel(string ticketNumber);
void modify(int flightNumber);

schedule display_flights();
passenger display_passengers();
ticket display_tickets();



const int schedule_size = 99;
const int passenger_size = 99;
const int ticket_size = 99;
string passengerID;


//SEED STRUCT ARRAYS

schedule flights[schedule_size]
= {
	{132,200,{2,2,2023},"Tokyo",12,40,"Cairo",16,00},
	{888,10,{3,9,2023},"Berlin",7,00,"Sydney",14,40},
	{103,500,{4,4,2023},"Mekkah",23,10,"Paris",7,00},
	{130,42,{5,4,2023},"Mekkah",23,10,"Paris",7,00},
	{108,19,{8,4,2023},"Mekkah",22,50,"Paris",1,00},
	{},
	{741,130,{9,3,2023},"Kuwait",2,50,"Alex",16,10}
};
passenger passengers[passenger_size]
= {
	{"400","Ahmed","addr1","010101010","ahmed@gmail.com","123"},
	{"401","Ali","addr2","011123465","ali@gmail.com","123"},
	{"402","Ramy","addr3","012456220","ramy@gmail.com","123"},
	{"403","Waleed","addr4","0105601472","waleed@hotmail.com","123"}
};
ticket tickets[ticket_size]
= {
	{"1000","400",{3,9,2023},888},
	{"1001","400",{4,4,2023},103},
	{},
	{"1002","402",{2,2,2023},132},
	{"1003","403",{2,2,2023},132}
};



int main() {

	int choice = menu();
	switch (choice)
	{
	case 1:
	{
		adminPrompt();
		break;
	}
	case 2:
	{
		loginPrompt();
		break;
	}
	case 3:
	{
		signUp(); break;
	}
	}
	return 0;
}





int menu()
{
	int choice;
	cout << "\n\n                    -----------------------" << endl << "                    WELCOME TO FCIS AIRLINE  " << endl << "                    -----------------------";
	cout << "\n\n\n";
	cout << "|press 1 to login as admin|";
	cout << "\n\n|press 2 to login as a passenger|";
	cout << "\n\n|press 3 to register a new account|";
	cout << "\n\nplease enter your choice  ";
	cin >> choice;
	return choice;

}
bool login(string email, string pass)
{
	for (int i = 0; i < passenger_size; i++)
	{
		if (email == passengers[i].email && pass == passengers[i].password)
		{
			passengerID = passengers[i].ID;
			return 1;
		}
	}
	return 0;

}

void loginPrompt() {
	string email, password;
	int choice;

	cout << "Enter your email: "; cin >> email;
	cout << "Enter your password: "; cin >> password;

	if (!login(email, password))
	{
		cout << "\nInvalid email or password\n\n[1] Retry\n[2] Back to Main Menu";
		cin >> choice;
	}

	switch (choice)
	{
	case 1: { loginPrompt(); break;}
	case 2: { main(); break;}
	}
}

void signUp()
{
	cout << "\t\t\tAccount Registration\n";
	cout << "\t\t\t**********************\n\n";

	passengers[passenger_size - 1].ID = "405";
	passengers[passenger_size - 1].email = emailPrompt();
	cout << "Password: "; cin >> passengers[passenger_size - 1].password;
	cout << "Name: "; cin >> passengers[passenger_size - 1].name;
	cout << "Address: "; cin >> passengers[passenger_size - 1].address;
	cout << "Phone Number: "; cin >> passengers[passenger_size - 1].phone_number;

	cout << "Signed Up successfully!\n";
	system("clear");
}

bool usedEmail(string email) {
	for (int i = 0; i < passenger_size; i++)
	{
		if (email == passengers[i].email)
		{
			return 1;
		}
	}
	return 0;
}

string emailPrompt() {
	string email;
	cout << "Email: "; cin >> email;
	if (usedEmail(email))
	{
		cout << "\nEmail is used before! Please try again\n";
		emailPrompt();
	}
	return email;
}
void adminPrompt()
{
	string email, password; int choice;

	cout << "\nEnter your email: "; cin >> email;
	cout << "Enter your password: "; cin >> password;

	if (email == "admin@gmail.com" && password == "admin123")
	{
		//admin()
	}
	else
	{
		cout << "\n**************************************\n";
		cout << "\nInvalid email or password\n\n[1] Retry\n[2] Back to Main Menu\n";
	}
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1: { adminPrompt(); break;}
		case 2: { main(); break;}
		default: { cout << "Invalid choice! Please try again\n"; break;}
		}

	} while (choice != 1 && choice != 2);

}


//************************ADMIN*******************************//

int num = 4, actual_num = 4;
void add_schedule() {
	cout << "Enter the flight number\n";
	cin >> flights[num].flight_num;
	cout << "Enter the number of available seats\n";
	cin >> flights[num].available_seats;
	cout << "Enter the day of flight\n";
	cin >> flights[num].flight_date[0];
	cout << "Enter the month\n";
	cin >> flights[num].flight_date[1];
	cout << "Enter the year\n";
	cin >> flights[num].flight_date[2];
	cout << "Enter the departure city\n";
	cin >> flights[num].departure_city;
	cout << "Enter the taking off hour\n";
	cin >> flights[num].taking_off_hour;
	cout << "Enter the taking off minute\n";
	cin >> flights[num].taking_off_minute;
	cout << "Enter the arrival city\n";
	cin >> flights[num].arrival_city;
	cout << "Enter the reaching hour\n";
	cin >> flights[num].reaching_hour;
	cout << "Enter the reaching minute\n";
	cin >> flights[num++].reaching_minute;
	actual_num++;
}
void edit_schedule(int k) {
	bool found = 0;
	for (int u = 0; u < num; u++)
		if (k == flights[u].flight_num)
		{
			k = u, found = 1;
			break;
		}
	if (!found)
	{
		cout << "There isn't flight with this number\nif you want to try again, enter the number of flight you want to edit , else enter -1\n";
		cin >> k;
		if (k == -1)
			return;
		else
			edit_schedule(k);
	}
	cout << "How many things you want to edit ? and what do you want to edit ?\n1.the number of available seats\n2.the date of flight\n3.the departure city\n4.the time of taking off\n5.arrival city\n6.reaching time\n";
	int trials, operation;
	cin >> trials;
	while (trials--)
	{
		cout << "Enter the number which you want do its operation\n";
		cin >> operation;
		if (operation == 1)
		{
			cout << "Enter the new number\n";
			cin >> flights[k].available_seats;
		}
		else if (operation == 2)
		{
			cout << "Enter the day\n";
			cin >> flights[k].flight_date[0];
			cout << "Enter the month\n";
			cin >> flights[k].flight_date[1];
			cout << "Enter the year\n";
			cin >> flights[k].flight_date[2];
		}
		else if (operation == 3)
		{
			cout << "Enter the departure city";
			cin >> flights[k].departure_city;
		}
		else if (operation == 4)
		{
			cout << "Enter hour\n";
			cin >> flights[k].taking_off_hour;
			cout << "Enter minute\n";
			cin >> flights[k].taking_off_minute;
		}
		else if (operation == 5)
		{
			cout << "Enter the arrival city";
			cin >> flights[k].arrival_city;
		}
		else if (operation == 6)
		{
			cout << "Enter hour\n";
			cin >> flights[k].reaching_hour;
			cout << "Enter minute\n";
			cin >> flights[k].reaching_minute;
		}
		else
			cout << "Invalid number !\n";
	}
}
void Delete_Flight_Num(int q) {
	bool ok = false;
	for (int i = 0; i < num; ++i) {
		if (q == flights[i].flight_num) {
			q = i;
			ok = true;
			break;
		}
	}
	if (!ok) {
		cout << " Sorry Number Not found \n If you want to try again, Enter the flight number you want to delete , if you want to skip enter -1 \n";
		int ans;
		cin >> ans;
		if (ans == -1)
			return;
		else
			Delete_Flight_Num(ans);

	}
	flights[q] = { -1,-1,-1,-1,-1,"",-1,-1,"",-1,-1 };
	if (ok)
		cout << "Done!\n";
	actual_num--;
}
bool admin_access() {
	cout << "Choose the Operation you want to do !\n1.add new schedule\n2.edit an flights schudule\n3.delete an ecisting schedule\n";
	int i;
	cin >> i;
	while (i != 1 && i != 2 && i != 3)
	{
		cout << "Please write a correct number!\n";
		cin >> i;
	}
	if (i == 1)
		add_schedule();
	else if (i == 2)
	{
		int k;
		cout << "Enter the number of the flight\n";
		cin >> k;
		edit_schedule(k);
	}
	else if (i == 3) {
		if (actual_num < 1)
			cout << "There isn't any flight to delete!\n";
		else
		{
			cout << "How many flight you want to delete? \n";
			int t;
			cin >> t;
			while (t <= 0 || t > actual_num) {
				cout << "Invalid Number!\n Please Enter Number Between 1 and " << actual_num << " \n";
				cin >> t;
			}
			while (t--) {
				cout << "_________________________________________Enter Flight Number To Delete ______________________________________________\n";
				int q;
				cin >> q;
				Delete_Flight_Num(q);
			}
		}
	}
	cout << "If you want to do another operation enter 1 \nelse enter any other number.\n";
	int continu;
	cin >> continu;
	if (continu == 1)
		admin_access();
	else
		return 1;
}

bool flightExists(int flightNumber) {
	for (int i = 0; i < schedule_size; i++)
	{
		if (flightNumber == flights[i].flight_num)
		{
			return 1;
		}
	}
	return 0;
}
schedule get_flight(int flightNumber) {
	for (int i = 0; i < schedule_size; i++)
	{
		if (flightNumber == flights[i].flight_num)
		{
			return flights[i];
		}
	}
}
bool ticketExists(string ticketNumber) {
	for (int i = 0; i < ticket_size; i++)
	{
		if (ticketNumber == tickets[i].number)
		{
			return 1;
		}
	}
	return 0;
}
ticket get_ticket(string ticketNumber) {
	for (int i = 0; i < ticket_size; i++)
	{
		if (ticketNumber == tickets[i].number)
		{
			return tickets[i];
		}
	}
}

//************************PASSENGER*******************************//

void cancel(string ticketNumber) {

	ticket t = get_ticket(ticketNumber);
	schedule f = get_flight(t.flight_num);
	f.available_seats++;

	t.number = "";
	t.passenger_ID = "";
	t.flight_date[0] = 0;
	t.flight_date[1] = 0;
	t.flight_date[2] = 0;
	t.flight_num = 0;

}
void modify(int flightNumber) {

}


schedule display_flights() {
	int counter = 0, choice, flightIndex[schedule_size];

	cout << "Option" << sep << "No." << sep << "Seats" << sep << "Day" << sep << "Month" << sep << "Year" << sep << "From" << sep << "Hour" << sep << "Minute" << sep << "To" << sep << "Hour" << sep << "Minute" << endl;
	cout << "_________________________________________________________________________________________________" << endl;

	for (int i = 0; i < schedule_size; i++)
	{
		if (flights[i].flight_num == 0) continue;
		cout << "[" << counter + 1 << "]" << sep << flights[i].flight_num << sep << flights[i].available_seats << sep << flights[i].flight_date[0] << sep << flights[i].flight_date[1] << sep << flights[i].flight_date[2] << sep << flights[i].departure_city << sep << flights[i].taking_off_hour << sep << flights[i].taking_off_minute << sep << flights[i].arrival_city << sep << flights[i].reaching_hour << sep << flights[i].reaching_minute << endl;

		flightIndex[counter] = i; counter++;
	}

	cout << "\nFlight Index: ";
	cin >> choice;
	return flights[flightIndex[choice - 1]];

}
passenger display_passengers() {
	int choice;

	cout << "Option" << sep << "ID" << sep << "Name" << sep << "Address" << sep << "Phone No." << sep << "Log" << endl;
	cout << "__________________________________________________________________" << endl;
	for (int i = 0; i < passenger_size; i++)
	{
		if (passengers[i].ID.empty()) continue;
		cout << "[" << i + 1 << "]" << sep << passengers[i].ID << sep << passengers[i].name << sep << passengers[i].address << sep << passengers[i].phone_number << passengers[i].log << endl;
	}
	cout << "\nPassenger Index: ";
	cin >> choice;
	return passengers[choice - 1];

}
ticket display_tickets() {
	int counter = 0, choice, ticketIndex[ticket_size];

	cout << "Option" << sep << "No." << sep << "ID" << sep << "Day" << sep << "Month" << sep << "Year" << sep << "FNo." << endl;
	cout << "___________________________________________________________________________" << endl;
	for (int i = 0; i < ticket_size; i++)
	{
		if (tickets[i].number.empty()) continue;
		cout << "[" << counter + 1 << "]" << sep << tickets[i].number << sep << tickets[i].passenger_ID << sep << tickets[i].flight_date[0] << sep << tickets[i].flight_date[1] << sep << tickets[i].flight_date[2] << sep << tickets[i].flight_num << endl;
		ticketIndex[counter] = i;counter++;
	}
	cout << "\nTicket Index: ";
	cin >> choice;
	return tickets[ticketIndex[choice - 1]];
}
