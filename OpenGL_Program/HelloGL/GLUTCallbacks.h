#ifndef _CALLBACKS_H
#define _CALLBACKS_H
class HelloGl;

namespace GLUTCallbacks {

	void Init(HelloGl* gl);

	void Display();
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}
#endif