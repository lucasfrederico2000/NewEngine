#pragma once
#include <glm/glm.hpp>

class cCamera
{
	float cameraSpeed;
	float yaw;
	float pitch;
	float mouseSensitivity;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;

	void UpdateCameraVectors();

public:
	float FOV;
	float nearPlane;
	float farPlane;

	cCamera();

	void MoveForward(float deltaTime); // w
	void MoveBackward(float deltaTime); // s
	void MoveRight(float deltaTime); // d
	void MoveLeft(float deltaTime); // a
	void MoveUp(float deltaTime); // q
	void MoveDown(float deltaTime); // e

	void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

	glm::mat4 GetViewMatrix();
};