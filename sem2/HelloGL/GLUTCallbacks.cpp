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
			helloGL->display();
		}
	}
	void Keyboard(unsigned char key, int x, int y) {

		helloGL->Keyboard(key, x, y);
	}
	void timer(int preferredRefresh) {
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;

		glutTimerFunc(preferredRefresh- updateTime, GLUTCallbacks::timer, preferredRefresh);
	}
}