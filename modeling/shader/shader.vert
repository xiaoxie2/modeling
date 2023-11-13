#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 col;

out vec3 ourColor;
uniform mat4 transform_1;						
void main()
{
	ourColor = col;
	gl_Position = transform_1 * vec4(position, 1.0f);
}

