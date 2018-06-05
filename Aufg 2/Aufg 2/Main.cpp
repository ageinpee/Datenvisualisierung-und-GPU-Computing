#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <LearnOpenGL/shader_m.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
glm::vec4 rotate(glm::vec4 position, float alpha);
std::vector<glm::vec4> tesselateHourGlass(int corners, float height, float width);


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

	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test

	Shader ourShader("vertex_shader.txt", "fragment_shader.txt");

	//create and link Shaders
	//-----------------------
	//int vertexShader;
	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	//glCompileShader(vertexShader);
	//
	//int success;
	//char infoLog[512];
	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//if (!success) {
	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//
	//int fragmentShader;
	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	//glCompileShader(fragmentShader);
	//
	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	//if (!success) {
	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//
	//int shaderProgram;
	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);
	//
	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//if (!success) {
	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	//}
	// delete old shaders
	//-------------------
	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);

	// create vertice-array
	// --------------------
	std::vector<glm::vec4> vertList = tesselateHourGlass(6, 0.5, 0.5);
	std::vector<float> verts;

	int vecnum;
	for (vecnum = 0; vecnum < vertList.size(); vecnum++) {
		int coordnum;
		for (coordnum = 0; coordnum < 3; coordnum++) {
			verts.push_back(vertList[vecnum][coordnum]);
			verts[vecnum + coordnum] = float(vertList[vecnum][coordnum]);
			std::cout << verts[vecnum + coordnum] << "   " << vecnum << std::endl;
		}
	}
	float* vertices = verts.data();

	//create and link Buffers
	//-----------------------
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//initialize VertexAttributePointer
	//---------------------------------
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//activate shader
	ourShader.use();

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		//render
		//------
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glUseProgram(shaderProgram);

		//activate shader
		ourShader.use();

		// create transformations
		glm::mat4 view;
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// pass transformation matrices to the shader
		ourShader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		ourShader.setMat4("view", view);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
		//std::cout << "looping" << std::endl;

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
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		std::cout << "Polygons are rendered as lines now." << std::endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		std::cout << "Polygons are rendered as filled triangles now" << std::endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
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

	glm::mat4 rotmat = glm::mat4(glm::cos(alpha), 0.0, glm::sin(alpha), 0.0,
		0.0, 1.0, 0.0, 0.0,
		-glm::sin(alpha), 0.0, glm::cos(alpha), 0.0,
		0.0, 0.0, 0.0, 1.0);
	return position * rotmat;
}







// WICHTIG!!!!!!!!!!!!!
// Offenbar sind die vertices schuld daran, dass nichts angezeigt wird. Am besten überarbeiten









std::vector<glm::vec4> tesselateHourGlass(int corners, float height, float width) {
	std::vector<glm::vec4> polygons; //polygons that will be returned after tesselation

	if (corners > 2 && corners < 50) {
		glm::vec4 center = glm::vec4(0.0, 0.0, 0.0, 0.0);
		glm::vec4 topCenter = glm::vec4(0.0, height, 0.0, 0.0);
		glm::vec4 bottomCenter = glm::vec4(0.0, -height, 0.0, 0.0);
		float alpha = float(360 / corners);

		glm::vec4 tempPosTop = glm::vec4(width, height, 0.0, 0.0);
		glm::vec4 tempPosBottom = glm::vec4(width, -height, 0.0, 0.0);

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
			std::cout << "Lauf : " << i << std::endl;
		}
		int j;
		for (j = 0; j < corners * 4; j++) {
			std::cout << glm::to_string(polygons.at(j)) << "   " << j << std::endl;
		}
		return polygons;
	}
	else {
		std::cout << "tesselation expects a number of corners between 2 and 50." << std::endl;
		return polygons;
	}
}