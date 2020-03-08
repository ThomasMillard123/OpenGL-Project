#pragma once
class HelloGl;

namespace GLUTCallbacks {

	void Init(HelloGl* gl);

	void Display();
	void timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}