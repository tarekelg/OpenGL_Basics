 
 - graphics pipeline takes set of 3D coordinates and transforms them to 2d pixels

 - shaders > small programs on the gpu that process input data
 
 - graphics pipeline consists of:
 Vertex Shader > Geometry Shader > Shape Assembly > 
 Rasterization > Fragment Shader > Tests and Blending

- in mordern opengl we need at least vertex and fragment shader

- vertex data should be normalized
- coodinatesystem is in the middle
- vertex data gets stored in memory of GPU > configure how opengl should interpret and
and specify how to send data to graphics card

- manage memory via vertex buffer objects (VBO)
- send data to GPU Memory in Batches
- unique UD corresponding to a Buffer
- glGenBuffers > used to generate a Buffer

- Binding a buffer to a GL_ARRAY_BUFFER target will be used to configure the 
currently bound buffer

simple Vertex shader
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

- Fragment Shader is calculating the color output of your pixels
- shader program object is used to link the shaders together