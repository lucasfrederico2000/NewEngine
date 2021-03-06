#pragma once

#include "cAnimation.h"
#include <vector>

class cSpriteAnimation : public cAnimation
{
public:
	int& spriteIdRef;
	glm::vec3& modelScaleRef;
	int initId;
	glm::vec3 initScale;

	std::vector<sKeyFrameSprite> keyframes;

	cSpriteAnimation(int& _spriteRef, glm::vec3& _modelScale);
	void AddKeyFrame(sKeyFrameSprite newKeyframe);

	virtual void Reset();
	void Reset(int newInitId, glm::vec3 newInitScale);

	virtual void Process(float deltaTime);
};