#pragma once

#include <GL/glew.h>

#include <glm.hpp>
#include <vector>

#include <cstdint>

namespace Engine
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 texCoords;
	};

	class  VertexBuffer
	{
	public:
		VertexBuffer(std::vector<Vertex>& vertices);
		~VertexBuffer();

		void Bind();
		void Unbind();

		//virtual void SetData(const void* data, uint32_t size) override;

	private:
		uint32_t ID;
	};
}