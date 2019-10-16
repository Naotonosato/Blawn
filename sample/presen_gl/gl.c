#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void read_shader(GLuint obj,char* filename)
{
    FILE* file = fopen(filename,"r");
    char line[5000];
    char text[50000];
    int len = 0;
    while(fscanf(file,"%s",line) != EOF)
    {
        strcat(text,line);
        len += strlen(line);
    }
    fclose(file);
    GLchar* source_ptr = (GLchar*)text;
    GLint g_len = len;
    //glShaderSource(obj,1,source_ptr,&g_len);
}

GLuint make_shader(char* vert,char* frag)
{
    puts("...\n");
    puts("...2\n"); 
    GLuint vert_obj = glCreateShader(GL_VERTEX_SHADER);
    puts("...3\n");
    GLuint frag_obj = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint compiled,linked;
    puts("...2\n");
    
    read_shader(vert_obj,vert);
    read_shader(frag_obj,frag);

    glCompileShader(vert_obj);
    glGetShaderiv(vert_obj,GL_COMPILE_STATUS,&compiled);
    if (compiled == GL_FALSE)
    {
        return -1;
    }
    glCompileShader(frag_obj);
    glGetShaderiv(frag_obj,GL_COMPILE_STATUS,&compiled);
    if (compiled == GL_FALSE)
    {
        return -1;
    }
    GLuint shader = glCreateProgram();
    glAttachShader(shader,vert_obj);
    glAttachShader(shader,frag_obj);
    
    glLinkProgram(shader);
    glGetShaderiv(shader,GL_LINK_STATUS,&linked);
    if (linked == GL_FALSE)
    {
        return -1;
    }
    return shader;
}

GLFWwindow * create_window(char* title)
{
    if (glfwInit() == GL_FALSE){
        puts("error init\n");
        return NULL;
    }
    return glfwCreateWindow(640,480,title,NULL,NULL);
}

int draw(GLFWwindow *  window)
{
    if (window == NULL){
        puts("Can't create GLFW window.\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (glewInit() != GLEW_OK)
    {
        puts("error init glew\n");
        return 1;
    }
    glClearColor(0.2f,0.2f,0.2f,1.0f);
    GLuint vao;
    GLuint vbo;
    double r = 0;
    double g = 0;
    double b = 0;
    while (glfwWindowShouldClose(window) == GL_FALSE){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(sin(cos(r)),cos(sin(g)),sin(cos(b)),1.0);
        glfwSwapBuffers(window);
        r +- 0.03;
        g += 0.1;
        b += 0.05;
        glfwWaitEvents();
    }

    return 0;
}