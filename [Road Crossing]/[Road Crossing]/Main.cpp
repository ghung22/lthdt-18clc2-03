#include "Window.h"
#include "Threads.h"
#include "CGAME.h"

/* RETURN VALUE LIST:
	0	-	No error.
	1	-	Program runs to the end of main.
*/

int main()
{
	//...
	thread gThread(UpdateGameFrame);		//Run the function along with main()
	while (true)
	{
		char pressed = toupper(getchar());
		//...
		if (pressed == 27) //ESC button
		{
			exitGame(&gThread);
			return 0;
		}
	}

	return 1;
}