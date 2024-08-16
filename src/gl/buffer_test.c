#include "buffers.h"

#include "../glx/hardext.h"
#include "attributes.h"
#include "debug.h"
#include "gl4es.h"
#include "glstate.h"
#include "logs.h"
#include "init.h"
#include "loader.h"

#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37

void gl4es_buffer_copy(GLenum target, GLuint buffer, GLuint buffer, GLintptr writeOffset, GLintptr readOffset, GLsizeiptr size)
{
   gl4es_glBindBuffer(GL_COPY_READ_BUFFER, GLuint buffer);
   gl4es_glBindBuffer(GL_COPY_WRITE_BUFFER, GLuint buffer);

   gl4es_glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
   gl4es_glBindBuffer(GL_COPY_READ_BUFFER, 0);
   gl4es_glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
};
