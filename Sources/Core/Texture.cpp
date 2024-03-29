#define STB_IMAGE_IMPLEMENTATION

#include "Core/Texture.h"

namespace Engine
{
	Texture::Texture(const char* texPath)
		: texturePath(texPath)
	{
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, this->ID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;

		if (texPath)
		{
			unsigned char* data = stbi_load(texPath, &width, &height, &nrChannels, 0);
			if (data)
			{
				if (nrChannels == 3)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				}
				if (nrChannels == 4)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				}

				glGenerateMipmap(GL_TEXTURE_2D);
				LOG_TRACE("Texture loaded : {}", texPath);
			}
			else
			{
				LOG_ERROR("Failed to load texture : {}", texPath);

				stbi_image_free(data);
				unsigned char* data = stbi_load("Game/Textures/Default_Tex.jpg", &width, &height, &nrChannels, 0);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			stbi_image_free(data);
		}
	}

	Texture::~Texture()
	{
	}

	void Texture::texUnit(const char* uniform, GLuint unit)
	{
		// Gets the location of the uniform
		GLuint texUni = glGetUniformLocation(Shader::GetID(), uniform);
		// Shader needs to be activated before changing the value of a uniform
		Shader::Activate(); 
		// Sets the value of the uniform
		glUniform1i(texUni, unit);
	}

	void Texture::BindTexture()
	{
		glBindTexture(GL_TEXTURE_2D, this->ID);
	}
}