//TODO change project name in CMakeLists.txt

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main () {
    GLFWwindow* window = NULL;
    const GLubyte* renderer;
    const GLubyte* version;
    GLuint vao;
    GLuint vbo;

    /**Triangle Coordinates*/
    GLfloat points[] = {
            0.0f,	0.5f,	0.0f,
            0.5f, -0.5f,	0.0f,
            -0.5f, -0.5f,	0.0f
    };

    /*Shader Stuff*/
    const char* vertex_shader =
            "#version 410\n"
                    "in vec3 vertex_points;"
                    "void main () {"
                    "	gl_Position = vec4 (vertex_points, 1.0);"
                    "}";
    const char* fragment_shader =
            "#version 410\n"
                    "out vec4 fragment_colour;"
                    "void main () {"
                    "	fragment_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
                    "}";

    GLuint vs, fs;
    GLuint shader_programme;

    /* start GL context and O/S window using the GLFW helper library */
    if (!glfwInit ()) {
        fprintf (stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }

    window = glfwCreateWindow (640, 480, "Hello World", NULL, NULL);
    if (!window) {
        fprintf (stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }


    glfwMakeContextCurrent (window);

    /* start GLEW extension handler */
    glewExperimental = GL_TRUE;
    glewInit ();

    /* get version info */
    renderer = glGetString (GL_RENDERER); /* get renderer string */
    version = glGetString (GL_VERSION); /* version as a string */
    printf ("Renderer: %s\n", renderer);
    printf ("OpenGL version supported %s\n", version);

    glEnable (GL_DEPTH_TEST); /* enable depth-testing */
    glDepthFunc (GL_LESS);


    glGenBuffers (1, &vbo);
    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (GLfloat), points,
                  GL_STATIC_DRAW);

    glGenVertexArrays (1, &vao);
    glBindVertexArray (vao);
    glEnableVertexAttribArray (0);
    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


    vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vs, 1, &vertex_shader, NULL);
    glCompileShader (vs);
    fs = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs, 1, &fragment_shader, NULL);
    glCompileShader (fs);
    shader_programme = glCreateProgram ();
    glAttachShader (shader_programme, fs);
    glAttachShader (shader_programme, vs);
    glLinkProgram (shader_programme);


    while (!glfwWindowShouldClose (window)) {
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram (shader_programme);
        glBindVertexArray (vao);
        glDrawArrays (GL_TRIANGLES, 0, 3);
        glfwPollEvents ();
        glfwSwapBuffers (window);
    }

    /* close GL context and any other GLFW resources */
    glfwTerminate();
    return 0;
}