#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define GLEW_STATIC	
#include <GL/glew.h>	
#include <GLFW/glfw3.h> 
#include <vector>

#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "sweeping.h"
#include "base.h"
#include "triangle.h"

#define max_num  1000


const GLint WIDTH = 600, HEIGHT = 600;
body* bo = createbasebody(0);
bool firstpree = false;
bool rightpre = false;
int he = 3;
bool pre = false;
bool swep = false;

void mouse_callback(GLFWwindow* window, int button, int action, int mods);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

static char* readFile(const char* fileName);