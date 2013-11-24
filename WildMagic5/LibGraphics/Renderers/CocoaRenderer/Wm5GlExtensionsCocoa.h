//
//  Wm5GlExtensionsCocoa.h
//  LibGraphics
//
//  Created by Timothy Prepscius on 11/21/13.
//
//

#ifndef LibGraphics_Wm5GlExtensionsCocoa_h
#define LibGraphics_Wm5GlExtensionsCocoa_h

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#define GT_EXTERN extern

GT_EXTERN int GTExistsOpenGL33;
GT_EXTERN int GTExistsOpenGL40;

#undef GLhandleARB
#define GLhandleARB GLuint

#define glEnableVertexAttribArrayARB glEnableVertexAttribArray
#define glVertexAttribPointerARB glVertexAttribPointer
#define glDisableVertexAttribArrayARB glDisableVertexAttribArray

#define glCurrentPaletteMatrixARB GTglCurrentPaletteMatrixARB
#define glMatrixIndexubvARB GTglMatrixIndexubvARB
#define glMatrixIndexusvARB GTglMatrixIndexusvARB
#define glMatrixIndexuivARB GTglMatrixIndexuivARB
#define glMatrixIndexPointerARB GTglMatrixIndexPointerARB

GT_EXTERN void GTglCurrentPaletteMatrixARB (GLint iIndex);
GT_EXTERN void GTglMatrixIndexubvARB (GLint iSize, const GLubyte* aucIndex);
GT_EXTERN void GTglMatrixIndexusvARB (GLint iSize, const GLushort* ausIndex);
GT_EXTERN void GTglMatrixIndexuivARB (GLint iSize, const GLuint* auiIndex);
GT_EXTERN void GTglMatrixIndexPointerARB (GLint iSize, GLenum eType,
    GLsizei iStride, const GLvoid* pvPointer);


#define GL_MATRIX_PALETTE_ARB                                       0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB                       0x8841
#define GL_MAX_PALETTE_MATRICES_ARB                                 0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB                               0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB                                   0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB                                 0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB                              0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB                              0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                            0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB                           0x8849

#define glGenQueriesARB glGenQueriesEXT
#define glBeginQueryARB glBeginQueryEXT
#define glEndQueryARB glEndQueryEXT
#define glDeleteQueriesARB glDeleteQueriesEXT
#define glGetQueryObjectivARB glGetQueryObjectivEXT
#define glGetQueryObjectuivARB glGetQueryObjectuivEXT

#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT
#define GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT          0x8CD8

/*
int GTGetVersion ();
int GTSupportsExtension (const char* acExtension);

// This function must be implemented for each platform.
void* GTGetFunctionPointer (const char*);
*/

/*
GLvoid* vbo_buffer = glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
// transfer the vertex data to the VBO
memcpy(vbo_buffer, s_cubeVertices, vertex_size);

// append color data to vertex data. To be optimal, 
// data should probably be interleaved and not appended
vbo_buffer += vertex_size;
memcpy(vbo_buffer, s_cubeColors, color_size);
glUnmapBufferOES(GL_ARRAY_BUFFER);
*/

// For error checking.
extern "C" const char* GTGetErrorString (GLenum code);


#endif
