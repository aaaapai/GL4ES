#include "gl.h"

#ifndef __SHADER_H_
#define __SHADER_H_

typedef struct {
    GLuint          id;     // internal id of the shader
    GLenum          type;   // type of the shader (GL_VERTEX or GL_FRAGMENT)
    int             attached; // number of time the shader is attached
    int             deleted;// flagged for deletion
    int             compiled;// flag if compiled
    char*           source; // original source of the shader
    char*           converted;  // converted source (or null if nothing)
} shader_t;

KHASH_MAP_INIT_INT(shaderlist, shader_t *)


GLuint gl4es_glCreateShader(GLenum shaderType);
void gl4es_glDeleteShader(GLuint shader);
void gl4es_glCompileShader(GLuint shader);
void gl4es_glShaderSource(GLuint shader, GLsizei count, const GLchar * const *string, const GLint *length);
void gl4es_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLboolean gl4es_glIsShader(GLuint shader);
void gl4es_glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
void gl4es_glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
void gl4es_glGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint *range, GLint *precision);
void gl4es_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
void gl4es_glReleaseShaderCompiler(void);

#define CHECK_SHADER(type, shader) \
    if(!shader) { \
        noerrorShim(); \
        return; \
    } \
    shader_t *glshader = NULL; \
    khint_t k_##shader; \
    { \
        int ret; \
        khash_t(shaderlist) *shaders = glstate->glsl.shaders; \
        k_##shader = kh_get(shaderlist, shaders, shader); \
        if (k_##shader != kh_end(shaders)) \
            glshader = kh_value(shaders, k_##shader); \
    } \
    if (!glshader) { \
        errorShim(GL_INVALID_OPERATION); \
        return; \
    }


#endif