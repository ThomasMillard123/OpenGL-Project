#include"GLUTCallbacks.h"
#include"HelloGl.h"

namespace GLUTCallbacks {

	namespace {

		HelloGl* helloGL = nullptr;
	}

	void Init(HelloGl* gl) {

		helloGL = gl;
	}
	void Display() {

		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}
	//keyborad inputs
	void Keyboard(unsigned char key, int x, int y) {

		helloGL->Keyboard(key, x, y);
	}
	//delta time
	void Timer(int preferredRefresh) {
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;

		glutTimerFunc(preferredRefresh- updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
}