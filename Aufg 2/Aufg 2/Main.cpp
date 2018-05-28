#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <list>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
glm::vec4 rotate(glm::vec4 position, float alpha);
std::vector<glm::vec4> tesselateHourGlass(int corners, float height);


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

glm::vec4 rotate(glm::vec4 position, float alpha) {
	glm::mat4 rotmat = glm::mat4( glm::cos(alpha),  0.0, glm::sin(alpha), 0.0, 
								  0.0,			    1.0, 0.0,			  0.0, 
								  -glm::sin(alpha), 0.0, glm::cos(alpha), 0.0, 
								  0.0,				0.0, 0.0,			  1.0);
	return position * rotmat;
}

std::vector<glm::vec4> tesselateHourGlass(int corners, float height) {
	if (corners > 2 && corners < 50) {
		glm::vec4 center = glm::vec4( 0.0, 0.0, 0.0, 0.0 );
		glm::vec4 topCenter = glm::vec4( 0.0, height, 0.0, 0.0 );
		glm::vec4 bottomCenter = glm::vec4( 0.0, -height, 0.0, 0.0);
		float alpha = float(360/corners);

		std::vector<glm::vec4> polygons; //polygons that will be returned after tesselation

		glm::vec4 tempPosTop = glm::vec4( 0.5, height, 0.0, 0.0 );
		glm::vec4 tempPosBottom = glm::vec4( 0.5, height, 0.0, 0.0 );

		int i;
		for (i = 0; i < corners; i++) {
			//adding the positions for the top part
			glm::vec4 oldTempPosTop = tempPosTop;
			tempPosTop = rotate(tempPosTop, alpha);

			polygons.push_back(topCenter);
			polygons.push_back(oldTempPosTop);
			polygons.push_back(tempPosTop);

			polygons.push_back(center);
			polygons.push_back(oldTempPosTop);
			polygons.push_back(tempPosTop);
			
			glm::vec4 oldTempPosBottom = tempPosBottom;
			tempPosBottom = rotate(tempPosBottom, alpha);

			polygons.push_back(bottomCenter);
			polygons.push_back(oldTempPosBottom);
			polygons.push_back(tempPosBottom);

			polygons.push_back(center);
			polygons.push_back(oldTempPosBottom);
			polygons.push_back(tempPosBottom);
		}
		int j;
		for (i = 0; i < corners; i++) {
			std::cout << glm::to_string( polygons.at(i) ) << std::endl;
		}
		return polygons;
	}
	else {
		std::cout << "tesselation expects a number of corners between 2 and 50." << std::endl;
	}
}