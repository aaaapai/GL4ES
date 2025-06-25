#include "../gl/attributes.h"
#include <GL/gl.h>
#include <GLES/gl.h>
#include "glx.h"



#ifdef DEBUG
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) {printf("%p (%s)\n", (void*)func, #func) ;return (void *)func;}
#else
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;
#endif

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

#ifdef DEBUG
#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        printf("=> STUB\n");                  \
        if(!globals4es.silentstub) LOGD("GL4ES stub: %s\n", #func_name); \
        return (void *)STUB_FCT;              \
    }
#else
#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        if(!globals4es.silentstub) LOGD("GL4ES stub: %s\n", #func_name); \
        return (void *)STUB_FCT;              \
    }
#endif


#define STUB_FCT glXStub
void glXStub(void *x, ...) {
    return;
}

void *glXGetProcAddress(const char *name) __attribute__((visibility("default")));
void *glXGetProcAddress(const char *name) {

#ifdef USE_ES2
    #include "gles2funcs.inc"
#else
    #include "glesfuncs.inc"
#endif
	
    EXT(glArrayElement);
    EXT(glDrawArrays);
    EXT(glVertexPointer);
    EXT(glNormalPointer);
    EXT(glColorPointer);
    //EXT(glIndexPointer);	//TODO
    EXT(glTexCoordPointer);
    //EXT(glEdgeFlagPointer);	//TODO
    //EXT(glGetPointerv);	//TODO


    // OES wrapper
    EX(glClearDepthfOES);
    EX(glClipPlanefOES);
    EX(glDepthRangefOES);
    EX(glFrustumfOES);
    EX(glGetClipPlanefOES);
    EX(glOrthofOES);

    // passthrough
    // batch thunking!
    #define THUNK(suffix, type)       \
    EX(glColor3##suffix##v);          \
    EX(glColor3##suffix);             \
    EX(glColor4##suffix##v);          \
    EX(glColor4##suffix);             \
    EX(glSecondaryColor3##suffix##v); \
    EX(glSecondaryColor3##suffix);    \
    EXT(glSecondaryColor3##suffix##v); \
    EXT(glSecondaryColor3##suffix);    \
    EX(glIndex##suffix##v);           \
    EX(glIndex##suffix);              \
    EX(glNormal3##suffix##v);         \
    EX(glNormal3##suffix);            \
    EX(glRasterPos2##suffix##v);      \
    EX(glRasterPos2##suffix);         \
    EX(glRasterPos3##suffix##v);      \
    EX(glRasterPos3##suffix);         \
    EX(glRasterPos4##suffix##v);      \
    EX(glRasterPos4##suffix);         \
    EX(glWindowPos2##suffix##v);      \
    EX(glWindowPos2##suffix);         \
    EX(glWindowPos3##suffix##v);      \
    EX(glWindowPos3##suffix);         \
    EX(glVertex2##suffix##v);         \
    EX(glVertex2##suffix);            \
    EX(glVertex3##suffix##v);         \
    EX(glVertex3##suffix);            \
    EX(glVertex4##suffix##v);         \
    EX(glVertex4##suffix);            \
    EX(glTexCoord1##suffix##v);       \
    EX(glTexCoord1##suffix);          \
    EX(glTexCoord2##suffix##v);       \
    EX(glTexCoord2##suffix);          \
    EX(glTexCoord3##suffix##v);       \
    EX(glTexCoord3##suffix);          \
    EX(glTexCoord4##suffix##v);       \
    EX(glTexCoord4##suffix);          \
    EX(glMultiTexCoord1##suffix##v);  \
    EX(glMultiTexCoord1##suffix);     \
    EX(glMultiTexCoord2##suffix##v);  \
    EX(glMultiTexCoord2##suffix);     \
    EX(glMultiTexCoord3##suffix##v);  \
    EX(glMultiTexCoord3##suffix);     \
    EX(glMultiTexCoord4##suffix##v);  \
    EX(glMultiTexCoord4##suffix);     \
    EXT(glMultiTexCoord1##suffix##v); \
    EXT(glMultiTexCoord1##suffix);    \
    EXT(glMultiTexCoord2##suffix##v); \
    EXT(glMultiTexCoord2##suffix);    \
    EXT(glMultiTexCoord3##suffix##v); \
    EXT(glMultiTexCoord3##suffix);    \
    EXT(glMultiTexCoord4##suffix##v); \
    EXT(glMultiTexCoord4##suffix);    \
    ARB(glMultiTexCoord1##suffix##v); \
    ARB(glMultiTexCoord1##suffix);    \
    ARB(glMultiTexCoord2##suffix##v); \
    ARB(glMultiTexCoord2##suffix);    \
    ARB(glMultiTexCoord3##suffix##v); \
    ARB(glMultiTexCoord3##suffix);    \
    ARB(glMultiTexCoord4##suffix##v); \
    ARB(glMultiTexCoord4##suffix);

    THUNK(b, GLbyte);
    THUNK(d, GLdouble);
    THUNK(i, GLint);
    THUNK(s, GLshort);
    THUNK(ub, GLubyte);
    THUNK(ui, GLuint);
    THUNK(us, GLushort);
    THUNK(f, GLfloat);
    #undef THUNK

#ifdef USE_ES2
    EX(glCompileShaderARB);
    EX(glCreateShaderObjectARB);
    EX(glGetObjectParameterivARB);
    EX(glShaderSourceARB);
#endif

    // functions we actually define
    EX(glActiveTexture);
    EXT(glActiveTexture);
    ARB(glActiveTexture);
    EX(glArrayElement);
    EXT(glArrayElement);
    EX(glBegin);
    EX(glBitmap);
    EX(glBlendColor);
    EXT(glBlendColor);
    ARB(glBlendColor);
    EX(glBlendEquationSeparatei);
    EXT(glBlendEquationSeparatei);
    ARB(glBlendEquationSeparatei);
    EX(glBlendFuncSeparate);
    EXT(glBlendFuncSeparate);
    ARB(glBlendFuncSeparate);
    EX(glBlendFuncSeparatei);
    EXT(glBlendFuncSeparatei);
    ARB(glBlendFuncSeparatei);
    EX(glCallList);
    EX(glCallLists);
    EX(glClearDepth);
    EX(glClientActiveTexture);
    EXT(glClientActiveTexture);
    ARB(glClientActiveTexture);
    EX(glClipPlane);
    EX(glCopyPixels);
    EX(glDeleteLists);
    EX(glDepthRange);
    EX(glDisable);
    EX(glDrawBuffer);
    EX(glDrawPixels);
    EX(glDrawRangeElements);
    EXT(glDrawRangeElements);
    EX(glEdgeFlag);
    EX(glEnable);
    EX(glEnd);
    EX(glEndList);
    EX(glEvalCoord1d);
    EX(glEvalCoord1f);
    EX(glEvalCoord2d);
    EX(glEvalCoord2f);
    EX(glEvalMesh1);
    EX(glEvalMesh2);
    EX(glEvalPoint1);
    EX(glEvalPoint2);
    EX(glFogCoordd);
    EX(glFogCoorddv);
    EX(glFogCoordf);
    EX(glFogCoordfv);
    EX(glFogi);
    EX(glFogiv);
    EX(glFrustum);
    EX(glGenLists);
    EX(glGetDoublev);
    EX(glGetIntegerv);
    EX(glGetMapdv);
    EX(glGetMapfv);
    EX(glGetMapiv);
    EX(glGetTexImage);
    EX(glGetTexLevelParameterfv);
    EX(glGetTexLevelParameteriv);
    EX(glInitNames);
    EX(glInterleavedArrays);
    EX(glIsList);
#ifndef USE_ES2
    EX(glLighti);
    EX(glLightiv);
    EX(glLightModeli);
    EX(glLightModeliv);
#endif
    EX(glLineStipple);
    EX(glListBase);
    EX(glLoadMatrixd);
    EX(glLoadName);
    EX(glLockArraysEXT);
    EX(glMap1d);
    EX(glMap1f);
    EX(glMap2d);
    EX(glMap2f);
    EX(glMapGrid1d);
    EX(glMapGrid1f);
    EX(glMapGrid2d);
    EX(glMapGrid2f);
    EX(glMateriali);
    EX(glMultMatrixd);
    EX(glNewList);
    EX(glOrtho);
    EX(glPixelTransferf);
    EX(glPixelTransferi);
    EX(glPixelZoom);
    EX(glPolygonMode);
    EX(glPolygonStipple);
    EX(glPopAttrib);
    EX(glPopClientAttrib);
    EX(glPopName);
    EX(glPushAttrib);
    EX(glPushClientAttrib);
    EX(glPushName);
    EX(glRasterPos2i);
    EX(glReadBuffer);
    EX(glRectd);
    EX(glRectf);
    EX(glRecti);
    EX(glRects);
    EX(glRectdv);
    EX(glRectfv);
    EX(glRectiv);
    EX(glRectsv);
    EX(glRenderMode);
    EX(glRotated);
    EX(glScaled);
    EX(glSecondaryColorPointer);
    EXT(glSecondaryColorPointer);
    EX(glTexEnvf);
    EX(glTexEnvi);
    EX(glTexEnvfv);
    EX(glTexEnviv);
    EX(glTexGend);
    EX(glTexGendv);
    EX(glTexGenf);
    EX(glTexGenfv);
    EX(glTexGeni);
    EX(glTexGeniv);
    EX(glTexImage1D);
    EX(glTexImage2D);
    EX(glTexImage3D);
    EX(glTexSubImage1D);
    EX(glTexSubImage2D);
    EX(glTexSubImage3D);
    EX(glCompressedTexImage2D);
    EX(glCompressedTexSubImage2D);
    EX(glCopyTexImage1D);
    EX(glCopyTexImage2D);
    EX(glCopyTexSubImage1D);
    EX(glCopyTexSubImage2D);
    EX(glTranslated);
    EX(glUnlockArraysEXT);
	EX(glGetTexGenfv);
	EX(glLoadTransposeMatrixf);
	EX(glLoadTransposeMatrixd);
	EX(glMultTransposeMatrixd);
	EX(glMultTransposeMatrixf);

    
#if !defined(NOX11) || defined(GLX_STUBS)
    // glX calls
    EX(glXChooseVisual);
    EX(glXCopyContext);
    EX(glXCreateContext);
    EX(glXCreateNewContext);
    EX(glXCreateContextAttribsARB);
    EX(glXDestroyContext);
    EX(glXGetConfig);
    EX(glXGetCurrentDisplay);
    EX(glXGetCurrentDrawable);
    EX(glXIsDirect);
    EX(glXMakeCurrent);
    EX(glXMakeContextCurrent);
    EX(glXQueryExtensionsString);
    EX(glXQueryServerString);
    EX(glXSwapBuffers);
    EX(glXSwapIntervalEXT);
#endif
    MAP("glXSwapIntervalMESA", gl4es_glXSwapInterval);
    MAP("glXSwapIntervalSGI", gl4es_glXSwapInterval);
#if !defined(NOX11) || defined(GLX_STUBS)
    EX(glXUseXFont);
    EX(glXWaitGL);
    EX(glXWaitX);
    EX(glXGetCurrentContext);
    EX(glXQueryExtension);
    EX(glXQueryDrawable);
    EX(glXQueryVersion);
    EX(glXGetClientString);
    EX(glXGetFBConfigs);
    EX(glXChooseFBConfig);
    MAP("glXChooseFBConfigSGIX", gl4es_glXChooseFBConfig);
    EX(glXGetFBConfigAttrib);
    EX(glXQueryContext);
    EX(glXGetVisualFromFBConfig);
    EX(glXCreateWindow);
    EX(glXDestroyWindow);
    
    EX(glXCreatePbuffer);
    EX(glXDestroyPbuffer);
    EX(glXCreatePixmap);
    EX(glXDestroyPixmap);
    EX(glXCreateGLXPixmap);
    EX(glXDestroyGLXPixmap);
    STUB(glXGetCurrentReadDrawable);
    STUB(glXGetSelectedEvent);
    STUB(glXSelectEvent);
    
    EX(glXCreateContextAttribs);
    ARB(glXCreateContextAttribs);
#endif
    EX(glXGetProcAddress);
    ARB(glXGetProcAddress);

    
}

#ifdef AMIGAOS4
//AliasExport(void*,aglGetProcAddress,,(const char* name));
#else
void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
#endif
