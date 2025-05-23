#include "GLFW/glfw3.h"
#include <cstdio>
#include <cstdlib> 

int main ()
{
    GLFWwindow *window;
    
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Terminate GLFW
    glfwTerminate();
    
    return 0;
}