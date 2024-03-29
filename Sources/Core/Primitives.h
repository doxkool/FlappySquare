#pragma once

#include "Buffers/VertexBuffer.h"

#include <GL/glew.h>

#include <vector>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/type_ptr.hpp>

namespace Engine
{
	class Primitive
	{
	private:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
	
	public:
		Primitive() {}
		virtual ~Primitive() {}
	
		//Functions
		void set(const Vertex* vertices,
			const unsigned nrOfVertices,
			const GLuint* indices,
			const unsigned nrOfIndices)
		{
			for (int i = 0; i < nrOfVertices; i++)
			{
				this->vertices.push_back(vertices[i]);
			}
	
			for (int i = 0; i < nrOfIndices; i++)
			{
				this->indices.push_back(indices[i]);
			}
		}
	
		inline Vertex* getVertices() { return this->vertices.data(); }
		inline GLuint* getIndices() { return this->indices.data(); }
		inline const unsigned getNrOfVertices() { return this->vertices.size(); }
		inline const unsigned getNrOfIndices() { return this->indices.size(); }
	};

	class Triangle : public Primitive
	{
	public:
		Triangle()
			: Primitive()
		{
			Vertex vertices[] =
			{
				//Position								//Color							//Texcoords			
				glm::vec3(0.0f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),
				glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),
				glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f)

				//Position								//Color							//Texcoords					//Normals
				//glm::vec3(0.0f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
				//glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				//glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f)
			};
			unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

			GLuint indices[] =
			{
				0, 1, 2	//Triangle 1
			};
			unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

			this->set(vertices, nrOfVertices, indices, nrOfIndices);
		}
	};

	class Quad : public Primitive
	{
	public:
		Quad()
			: Primitive()
		{
			Vertex vertices[] =
			{
				//Position								//Color							//Texcoords			
				glm::vec3(0.0f, 1.0f, 0.f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),
				glm::vec3(1.0f, 1.0f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),
				glm::vec3(1.0f, 0.0f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),
				glm::vec3(0.0f, 0.0f, 0.f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.f, 0.f)
			};
			unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

			GLuint indices[] =
			{
				0, 1, 2,	//Triangle 1
				0, 2, 3		//Triangle 2
			};
			unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

			this->set(vertices, nrOfVertices, indices, nrOfIndices);
		}
	};

	class Cube : public Primitive
	{
	public:
		Cube()
			: Primitive()
		{
			Vertex vertices[] =
			{
				//Position								//Color					
				glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),
				glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),
				glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),
				glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),
	
				glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),
				glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),
				glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),
				glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f)
			};
			unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);
	
			GLuint indices[] =
			{
				0, 1, 2,
				0, 2, 3,
	
				7, 6, 1,
				7, 1, 0,
	
				4, 5, 6,
				4, 6, 7,
	
				3, 2, 5,
				3, 5, 4
			};
			unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
	
			this->set(vertices, nrOfVertices, indices, nrOfIndices);
		}
	};
}