#include "const.h"

void gl4es_glBindBuffer();
void gl4es_glCopyBufferSubData();
struct vrend_context;

struct vrend_resource {
   struct pipe_resource base;
   uint32_t storage_bits;
   uint32_t map_info;

   GLuint gl_id;
   GLenum target;

   GLuint tbo_tex_id;/* tbos have two ids to track */
   bool y_0_top;

   /* used for keeping track of multisampled renderbuffer for
    * GL_EXT_multisampled_render_to_texture. */
   GLuint rbo_id;

   /* Pointer to system memory storage for this resource. Only valid for
    * VREND_RESOURCE_STORAGE_GUEST_ELSE_SYSTEM buffer storage.
    */
   char *ptr;
   /* IOV pointing to shared guest memory storage for this resource. */
   const struct iovec *iov;
   uint32_t num_iovs;
   uint64_t mipmap_offsets[VR_MAX_TEXTURE_2D_LEVELS];
   void *gbm_bo, *egl_image;
   void *aux_plane_egl_image[VIRGL_GBM_MAX_PLANES];
#ifdef WIN32
   ID3D11Texture2D *d3d_tex2d;
#endif

   uint64_t size;
   GLbitfield buffer_storage_flags;
   GLuint memobj;

   uint32_t blob_id;
   struct list_head head;
   bool is_imported;
};

void gl4es_buffer_copy(struct vrend_context *ctx,
                                       struct vrend_resource *src_res,
                                       struct vrend_resource *dst_res,
                                       uint32_t dstx, uint32_t srcx,
                                       uint32_t width)
{
   gl4es_glBindBuffer(GL_COPY_READ_BUFFER, src_res->gl_id);
   gl4es_glBindBuffer(GL_COPY_WRITE_BUFFER, dst_res->gl_id);

   gl4es_glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, srcx, dstx, width);
   gl4es_glBindBuffer(GL_COPY_READ_BUFFER, 0);
   gl4es_glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
};
