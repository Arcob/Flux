#pragma once
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "Cubemap.h"
#include "Log.h"

#include <glad/glad.h>
#include <iostream>
namespace Flux {
    class Framebuffer {
    public:
        Framebuffer() {
            glGenFramebuffers(1, &handle);
        }

        void bind() {
            glBindFramebuffer(GL_FRAMEBUFFER, handle);
        }

        void release() {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        void setTexture(GLuint attachment, Texture& texture) {
            glFramebufferTexture(GL_FRAMEBUFFER, attachment, texture.handle, 0);
        }

        void setCubemap(GLuint texture, unsigned int face, int mipmapLevel) {
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, texture, mipmapLevel);
        }

        void setDrawBuffer(GLuint target) {
            glDrawBuffer(target);
        }

        void validate() {
            GLuint error = glCheckFramebufferStatus(GL_FRAMEBUFFER);

            if (error != GL_FRAMEBUFFER_COMPLETE) {
                switch (error) {
                case GL_FRAMEBUFFER_UNDEFINED:
                    Log::error("Target is the default framebuffer, but the default framebuffer does not exist"); break;
                case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                    Log::error("Any of the framebuffer attachment points are framebuffer incomplete"); break;
                case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                    Log::error("The framebuffer does not have any texture attached to it"); break;
                case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                    Log::error("The value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for any color attachment point(s) named by GL_DRAW_BUFFERi"); break;
                case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                    Log::error("GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point named by GL_READ_BUFFER"); break;
                case GL_FRAMEBUFFER_UNSUPPORTED:
                    Log::error("The combination of internal formats of the attached textures violates an implementation-dependent set of restrictions."); break;
                case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                    Log::error("The value of GL_RENDERBUFFER_SAMPLES is not the same for all attached renderbuffers"); break;
                default:
                    Log::error("There is a problem with the framebuffer");
                }
            }
        }
    private:
        GLuint handle;
    };
}

#endif /* FRAMEBUFFER_H */
