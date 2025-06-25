#include <EGL/egl.h>
#include <../gl/gl.h>
#include <GL/gl.h>

#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;

#define MAP_EGL(func_name, egl_func) \
    MAP(#func_name, eglGetProcAddress(#egl_func))

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        printf("glX stub: %s\n", #func_name); \
        return (void *)glXStub;               \
    }

void glXStub(void *x, ...) {
    return;
}

void *glXGetProcAddressARB(const char *name) {
    // generated gles wrappers
#ifdef USE_ES2
    #include "gles2funcs.inc"
#else
    #include "glesfuncs.inc"
#endif

    void* proc = dlsym(RTLD_DEFAULT, (const char*)name);

    if (!proc) {
            return NULL;
    }
    return proc;
	
    // stubs for unimplemented functions
    STUB(glAccum);
    STUB(glAreTexturesResident);
    STUB(glClearAccum);
    STUB(glColorMaterial);
    STUB(glCopyTexImage3D);
    STUB(glCopyTexSubImage3D);
    STUB(glEdgeFlagPointer);
    STUB(glFeedbackBuffer);
    STUB(glGetClipPlane);
    STUB(glGetLightiv);
    STUB(glGetMaterialiv);
    STUB(glGetPixelMapfv);
    STUB(glGetPixelMapuiv);
    STUB(glGetPixelMapusv);
    STUB(glGetPolygonStipple);
    STUB(glGetStringi);
    STUB(glGetTexGendv);
    //STUB(glGetTexGenfv);
    STUB(glGetTexGeniv);
    STUB(glMaterialiv);
    STUB(glPassThrough);
    STUB(glPixelMapfv);
    STUB(glPixelMapuiv);
    STUB(glPixelMapusv);
    STUB(glPixelStoref);
    STUB(glPrioritizeTextures);
    STUB(glSelectBuffer);
    //STUB(glTexSubImage1D);

    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
