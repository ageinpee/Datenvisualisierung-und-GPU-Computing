#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void rotate(int position[3], float alpha);
void tesselateHourGlass(int corners);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

														 // glfw window creation
														 // --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello Glut", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		std::cout << "RIGHT ARROW" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		std::cout << "LEFT ARROW" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		std::cout << "UP ARROW" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		std::cout << "DOWN ARROW" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		std::cout << "A" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
		std::cout << "B" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		std::cout << "C" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		std::cout << "D" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		std::cout << "E" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		std::cout << "F" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		std::cout << "G" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
		std::cout << "H" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		std::cout << "I" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		std::cout << "J" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		std::cout << "K" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		std::cout << "L" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		std::cout << "M" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
		std::cout << "N" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		std::cout << "O" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		std::cout << "P" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		std::cout << "Q" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		std::cout << "R" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		std::cout << "S" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		std::cout << "T" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		std::cout << "U" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
		std::cout << "V" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		std::cout << "W" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		std::cout << "X" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		std::cout << "Y" << std::endl;
	else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		std::cout << "Z" << std::endl;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void rotate(int position[3], float alpha) {
	//implementation missing
}

void tesselatHourGlass(int corners, int height) {
	if (corners > 2 && corners < 50) {
		int center[3] = { 0, 0, 0 };
		int topCenter[3] = { 0, height, 0 };
		int bottomCenter[3] = { 0, -height, 0 };
		int firstTop[3] = { 0.5, height, 0 };
		int firstBottom[3] = { 0.5, height, 0 };
		float alpha = 360 / corners;

		int polygons[200][3]; //polygons that will be returned after tesselation

		int tempPosTop[3] = firstTop;
		int tempPosBottom[3] = firstBottom;
		for (int i = 0; i < corners*12; i+=12) {
			//adding the positions for the top part
			polygons[i] = topCenter;
			polygons[i + 3] = center; 
			polygons[i + 1] = tempPosTop;
			polygons[i + 4] = tempPosTop;
			tempPosTop = rotate(tempPosTop, alpha);
			polygons[i + 2] = tempPosTop; 
			polygons[i + 5] = tempPosTop; 

			//adding the positions for the bottom part
			polygons[i + 6] = bottomCenter; 
			polygons[i + 9] = center; 
			polygons[i + 7] = tempPosBottom;
			polygons[i + 10] = tempPosBottom; 
			tempPosBottom = rotate(tempPosBottom, alpha);
			polygons[i + 8] = tempPosBottom;
			polygons[i + 11] = tempPosBottom; 
		}
		return polygons;
	}
	else {
		std::cout << "tesselation expects a number of corners between 2 and 50." << std::endl;
	}
}