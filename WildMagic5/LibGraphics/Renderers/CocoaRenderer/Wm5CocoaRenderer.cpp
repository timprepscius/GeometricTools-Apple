// Geometric Tools, LLC
// Copyright (c) 1998-2011
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.6.0 (2011/07/23)

#include "Wm5GraphicsPCH.h"
#include "Wm5Renderer.h"
#include "Wm5CocoaRendererData.h"
#include "Wm5CocoaRendererInput.h"

using namespace Wm5;

//----------------------------------------------------------------------------
Renderer::Renderer (RendererInput& input, int width, int height,
                    Texture::Format colorFormat, Texture::Format depthStencilFormat,
                    int numMultisamples)
{
    Initialize(width, height, colorFormat, depthStencilFormat,
               numMultisamples);
    
    CocoaRendererData* data = new0 CocoaRendererData();
    mData = data;
    
    // Load the function pointers for the OpenGL extensions.  This only
    // needs to occur once.  If you want a file to be created that stores
    // the OpenGL driver information, change the input filename to a
    // valid string; for example, "OpenGLDriverInfo.txt".
    //const char* infoFile = "OpenGLDriverInfo.txt";
    const char* infoFile = 0;

//    GTInitGL(infoFile);
    
    // Select the shader profiles.
    VertexShader::SetProfile(VertexShader::VP_ARBVP1);
    PixelShader::SetProfile(PixelShader::PP_ARBFP1);
    
    // Query the device for its capabilities.  TODO:  The number of images
    // turns out to be larger than what Shader Model 3 supports.  Why is this?
    data->mMaxVShaderImages = 0;
    data->mMaxPShaderImages = 0;
    data->mMaxCombinedImages = 0;
    glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
                  &data->mMaxVShaderImages);
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS,
                  &data->mMaxPShaderImages);
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
                  &data->mMaxCombinedImages);
    
    // Set the default render states.
    data->mCurrentRS.Initialize(mDefaultAlphaState, mDefaultCullState,
                                mDefaultDepthState, mDefaultOffsetState, mDefaultStencilState,
                                mDefaultWireState);
}
//----------------------------------------------------------------------------
Renderer::~Renderer ()
{
    delete0(mData);
    Terminate();
}
//----------------------------------------------------------------------------
void Renderer::DisplayColorBuffer ()
{
}
//----------------------------------------------------------------------------
