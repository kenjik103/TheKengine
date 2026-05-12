#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture {
public:
  unsigned int ID;

  Texture(const char* TextureFilePath);
  ~Texture(){ glDeleteTextures(1, &ID) ;};

  void bind(unsigned int slot);
};

#endif
