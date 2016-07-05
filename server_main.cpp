#include "Manager_server.h"
int main()
{
	Manager manager = Manager();
	
	while(manager.run() == false)
	{
		manager.newWorld();
	}
}
