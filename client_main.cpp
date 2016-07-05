#include "Manager_client.h"
int main()
{
	Manager manager = Manager();
	
	while(manager.run() == false)
	{
		manager.new_world();
	}

}
