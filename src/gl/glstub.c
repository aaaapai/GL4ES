#include <gl.h>

#define STUB(def)\
def {\
    /*printf("stub: %s;\n", #def);*/\
}

STUB(void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b));
STUB(void glIndexf(GLfloat c));

STUB(void glFogCoordd(GLdouble coord));
STUB(void glFogCoordf(GLfloat coord));
STUB(void glFogCoorddv(const GLdouble *coord));
STUB(void glFogCoordfv(const GLfloat *coord));

// STUB(void glMultiTexCoord());
// STUB(void glVertexAttrib());
// STUB(void glEvalCoord());
// STUB(void glEvalPoint());
STUB(GLint glRenderMode(GLenum mode));
STUB(void glArrayElement(GLint i));
STUB(void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha));
STUB(void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha));
STUB(void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha));
STUB(void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha));
STUB(void glDrawBuffer(GLenum mode));
STUB(void glEdgeFlag(GLboolean flag));
STUB(void glInitNames());
STUB(void glLightModeli(GLenum pname, GLint param));
STUB(void glLoadName(GLuint name));
STUB(void glPixelTransferf(GLenum pname, GLfloat param));
STUB(void glPixelTransferi(GLenum pname, GLint param));
STUB(void glPixelZoom(GLfloat xfactor, GLfloat yfactor));
STUB(void glPolygonMode(GLenum face, GLenum mode));
STUB(void glPolygonStipple(const GLubyte *mask));
STUB(void glPopName());
STUB(void glPushName());
STUB(void glReadBuffer(GLenum mode));
// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
STUB(void glSelectBuffer(GLsizei size, GLuint *buffer));

#undef STUB
