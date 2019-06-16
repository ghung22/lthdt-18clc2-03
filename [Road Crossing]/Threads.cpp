#include "Threads.h"

void exitGame(thread* t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t->join();			//Join main thread
}

void UpdateGameFrame()
{
	while (IS_RUNNING)
	{
		//...
		//update elements on screen
		//...
	}
}