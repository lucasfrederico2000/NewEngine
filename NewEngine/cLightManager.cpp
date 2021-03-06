#include "cLightManager.h"
#include <sstream>
#include <glad/glad.h>

void cLightManager::SetupUniformLocations(unsigned int program)
{
	for (unsigned int lightIndex = 0; lightIndex != NUMBER_OF_LIGHTS; lightIndex++)
	{
		std::stringstream ssLight;
		ssLight << "theLights[" << lightIndex << "].";

		std::string sLightUniformName = ssLight.str() + "position";
		this->lights[lightIndex].position_uniform_location = glGetUniformLocation(program, sLightUniformName.c_str());
	
		sLightUniformName = ssLight.str() + "diffuse";
		this->lights[lightIndex].diffuse_uniform_location = glGetUniformLocation(program, sLightUniformName.c_str());

		sLightUniformName = ssLight.str() + "diffuse";
		this->lights[lightIndex].diffuse_uniform_location = glGetUniformLocation(program, sLightUniformName.c_str());

		//sLightUniformName = ssLight.str() + "specular";
		//this->theLights[lightIndex].specular_uniform_location = glGetUniformLocation(shaderProgram, sLightUniformName.c_str());////		std::cout << sLightUniformName << " = " << this->theLights[lightIndex].specular_uniform_location << std::endl;

		//sLightUniformName = ssLight.str() + "atten";
		//this->theLights[lightIndex].atten_uniform_location = glGetUniformLocation(shaderProgram, sLightUniformName.c_str());

		sLightUniformName = ssLight.str() + "direction";
		this->lights[lightIndex].direction_uniform_location = glGetUniformLocation(program, sLightUniformName.c_str());

		sLightUniformName = ssLight.str() + "extraParam";
		this->lights[lightIndex].extraParam_uniform_location = glGetUniformLocation(program, sLightUniformName.c_str());
	}
}

void cLightManager::SetUnimormValues(unsigned int program)
{
	for (unsigned int lightIndex = 0; lightIndex != NUMBER_OF_LIGHTS; lightIndex++)
	{
		glUniform4f(this->lights[lightIndex].position_uniform_location,
			this->lights[lightIndex].position.x,
			this->lights[lightIndex].position.y,
			this->lights[lightIndex].position.z,
			this->lights[lightIndex].position.w);

		glUniform4f(this->lights[lightIndex].diffuse_uniform_location,
			this->lights[lightIndex].diffuse.x,
			this->lights[lightIndex].diffuse.y,
			this->lights[lightIndex].diffuse.z,
			this->lights[lightIndex].diffuse.w);

		//glUniform4f(this->lights[lightIndex].specular_uniform_location,
		//	this->lights[lightIndex].specular.x,
		//	this->lights[lightIndex].specular.y,
		//	this->lights[lightIndex].specular.z,
		//	this->lights[lightIndex].specular.w);

		//glUniform4f(this->lights[lightIndex].atten_uniform_location,
		//	this->lights[lightIndex].atten.x,
		//	this->lights[lightIndex].atten.y,
		//	this->lights[lightIndex].atten.z,
		//	this->lights[lightIndex].atten.w);

		glUniform4f(this->lights[lightIndex].direction_uniform_location,
			this->lights[lightIndex].direction.x,
			this->lights[lightIndex].direction.y,
			this->lights[lightIndex].direction.z,
			this->lights[lightIndex].direction.w);

		glUniform4f(this->lights[lightIndex].extraParam_uniform_location,
			this->lights[lightIndex].extraParam.x,
			this->lights[lightIndex].extraParam.y,
			this->lights[lightIndex].extraParam.z,
			this->lights[lightIndex].extraParam.w);
	}//for (unsigned int lightIndex...
}
