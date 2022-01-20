#include <iostream>
using namespace std;

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET& p)
{
	cin >> p.packet_no >> p.prior_level; // read packet_no, prior_level
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer(PACKET& p)
{
	PACKET *pac;

	pac = new PACKET();

	*pac = p;
	
	PACKET *it = new PACKET();
	it->next = &buffer;
	bool inserted = false;
	while(it->next)
	{
		if(pac->prior_level < it->next->prior_level)
		{
			pac->next = it->next;
			it->next = pac;
			inserted = true;
			break;
		}
		else
		{
			it = it->next;
		}
	}
	
	if(!inserted)
	{
		last_packet->next = pac;
		last_packet = pac;
	}

	return SUCCESS;
}

int Get_Packet_from_Buffer(PACKET& p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	p = *buffer.next;
	delete buffer.next;

	buffer.next = p.next;
	
	return SUCCESS;
}

int main(void)
{
	int N;
	PACKET packet;

	cin >> N;	// read number of packet
	
	last_packet = &buffer;
	packet.next = NULL;

	for (int i = 0; i < N; i++)
	{
		Input_Packet(packet);
		Put_Packet_to_Buffer(packet);
	}
	
	// print packet processing order 
	while (Get_Packet_from_Buffer(packet) == SUCCESS)
	{
		cout << packet.packet_no << " ";
	}

	return 0;
}