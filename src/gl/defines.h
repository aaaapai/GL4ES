#include <GL/gl.h>

#define GLAPI __attribute__((visibility("default")))
#define GLAPIENTRY

// newly-defined GL functions
GLAPI GLboolean glIsList(GLuint list);
GLAPI GLuint glGenLists(GLsizei range);
GLAPI void glActiveTextureARB(GLenum texture);
GLAPI void glArrayElement(GLint i);
GLAPI void glBegin(GLenum mode);
GLAPI void glCallList(GLuint list);
GLAPI void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
GLAPI void glClearDepth(GLdouble depth);
GLAPI void glDeleteList(GLuint list);
GLAPI void glDeleteLists(GLuint list, GLsizei range);
GLAPI void glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLAPI void glEnd();
GLAPI void glEndList();
GLAPI void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
GLAPI void glGetDoublev(GLenum pname, GLdouble *params);
GLAPI void glIndexf(GLfloat i);
GLAPI void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
GLAPI void glListBase(GLuint base);
GLAPI void glLockArraysEXT(GLint first, GLsizei count);
GLAPI void glNewList(GLuint list, GLenum mode);
GLAPI void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
GLAPI void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
GLAPI void glTexCoord2f(GLfloat s, GLfloat t);
GLAPI void glUnlockArraysEXT();
GLAPI void glVertex2f(GLfloat x, GLfloat y);
GLAPI void glVertex2i(GLint x, GLint y);
GLAPI void glVertex3f(GLfloat x, GLfloat y, GLfloat z);

// custom functions
GLAPI void glPushCall(void *call);
