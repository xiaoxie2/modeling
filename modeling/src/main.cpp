#include "main.h"

void mouse_callback(GLFWwindow* window, int button, int action, int mods) {

	int i = 0;

	int left_button = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	int right_button = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
	if (left_button == GLFW_PRESS) {

		if (!firstpree) {
			if (!pre) {
				bo = sweep(bo, he);
				swep = true;
			}
			firstpree = true;
		}
		else {
			firstpree = false;
		}

	}
	if (right_button == GLFW_PRESS) {
		if (!rightpre) {
			bo = createbasebody(1);
			swep = false;
			rightpre = true;
		}
		else {
			bo = createbasebody(0);
			swep = false;
			rightpre = false;
		}
	}

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (key)
	{
	case GLFW_KEY_UP:
		if (rightpre) {
			bo = createbasebody(1);
		}
		else {
			bo = createbasebody(0);
		}

		if (he < 6) {
			he++;
		}
		pre = true;
		bo = sweep(bo, he);
		swep = true;
		break;

	case GLFW_KEY_DOWN:
		if (rightpre) {
			bo = createbasebody(1);
		}
		else {
			bo = createbasebody(0);
		}
		if (he > 2) {
			he--;

		}
		bo = sweep(bo, he);
		pre = true;
		swep = true;
		break;
	case GLFW_KEY_TAB:

	default:
		break;
	}
}

static char* readFile(const char* fileName) {
	FILE* fp;
	char* content = NULL;
	int count = 0;

	if (fileName != NULL)
	{
		fp = fopen(fileName, "rt");

		if (fp != NULL)
		{
			fseek(fp, 0, SEEK_END);
			count = ftell(fp);
			rewind(fp);
			if (count > 0)
			{
				content = (char*)malloc(sizeof(char) * (count + 1));
				count = fread(content, sizeof(char), count, fp);
				content[count] = NULL;
			}
			fclose(fp);
		}
	}
	return content;
}

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	GLFWwindow* window_1 = glfwCreateWindow(WIDTH, HEIGHT, "sweep operation", NULL, NULL);
	int screenWidth_1, screenHeight_1;
	glfwGetFramebufferSize(window_1, &screenWidth_1, &screenHeight_1);
	cout << "screenWidth_1 = " << screenWidth_1 << ", screenHeight = " << screenHeight_1 << endl;
	glewExperimental = GL_TRUE;
	glfwMakeContextCurrent(window_1);
	glewInit();

	glfwSetInputMode(window_1, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwSetMouseButtonCallback(window_1, mouse_callback);

	glfwSetKeyCallback(window_1, key_callback);

	glEnable(GL_DEPTH_TEST);


	GLuint vertexShader_1 = glCreateShader(GL_VERTEX_SHADER);
	const char* vertshad = readFile("shader/shader.vert");

	const char* fragshad = readFile("shader/shader.frag");

	glShaderSource(vertexShader_1, 1, &vertshad, NULL);
	glCompileShader(vertexShader_1);
	GLint flag;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader_1, GL_COMPILE_STATUS, &flag);
	if (!flag)
	{
		glGetShaderInfoLog(vertexShader_1, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}

	GLuint fragmentShader_1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader_1, 1, &fragshad, NULL);
	glCompileShader(fragmentShader_1);
	glGetShaderiv(fragmentShader_1, GL_COMPILE_STATUS, &flag);
	if (!flag)
	{
		glGetShaderInfoLog(fragmentShader_1, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
	}


	GLuint shaderProgram_1 = glCreateProgram();
	glAttachShader(shaderProgram_1, vertexShader_1);
	glAttachShader(shaderProgram_1, fragmentShader_1);
	glLinkProgram(shaderProgram_1);
	glGetProgramiv(shaderProgram_1, GL_LINK_STATUS, &flag);
	if (!flag)
	{
		glGetProgramInfoLog(shaderProgram_1, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}
	glDeleteShader(vertexShader_1);
	glDeleteShader(fragmentShader_1);





	std::vector<point> vertices_3 = triangle(bo, !swep);


	float ver[max_num];
	for (int i = 0; i < vertices_3.size(); i++) {
		ver[i * 6] = vertices_3[i].pos[0];
		ver[i * 6 + 1] = vertices_3[i].pos[1];
		ver[i * 6 + 2] = vertices_3[i].pos[2];
		ver[i * 6 + 3] = vertices_3[i].color[0];
		ver[i * 6 + 4] = vertices_3[i].color[1];
		ver[i * 6 + 5] = vertices_3[i].color[2];
	}


	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ver), ver, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);





	while (!glfwWindowShouldClose(window_1))
	{

		glViewport(0, 0, screenWidth_1, screenHeight_1);
		glfwPollEvents();


		glClearColor(0.5f, 0.8f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		std::vector<point> vertices_3 = triangle(bo, !swep);


		for (int i = 0; i < vertices_3.size(); i++) {
			ver[i * 6] = vertices_3[i].pos[0];
			ver[i * 6 + 1] = vertices_3[i].pos[1];
			ver[i * 6 + 2] = vertices_3[i].pos[2];
			ver[i * 6 + 3] = vertices_3[i].color[0];
			ver[i * 6 + 4] = vertices_3[i].color[1];
			ver[i * 6 + 5] = vertices_3[i].color[2];
		}




		glBufferData(GL_ARRAY_BUFFER, sizeof(ver), ver, GL_STATIC_DRAW);
		glUseProgram(shaderProgram_1);

		glBindVertexArray(VAO);

		GLfloat time = glfwGetTime();
		glm::mat4 transform_1;
		transform_1 = glm::scale(transform_1, glm::vec3(0.15f, 0.15f, 0.15f));
		transform_1 = glm::rotate(transform_1, time * 20, glm::vec3(0.2f, 1.0f, 0.0f));
		/*transform_1 = glm::lookAt(glm::vec3(0.00f, 8.0f, 0.0f), glm::vec3(0.0f, .0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));*/
		int transform_1_Location = glGetUniformLocation(shaderProgram_1, "transform_1");
		glUniformMatrix4fv(transform_1_Location, 1, GL_FALSE, glm::value_ptr(transform_1));
		glDrawArrays(GL_TRIANGLES, 0, vertices_3.size());


		glBindVertexArray(0);
		/* 交换缓冲 */
		glfwSwapBuffers(window_1);
	}

	/* 释放资源 */
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();	// 结束
	return 0;
}
