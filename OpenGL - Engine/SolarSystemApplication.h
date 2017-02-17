#pragma once

#include "baseApplication.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>





class SolarSystemApplication : public baseApplication
{
public:
	SolarSystemApplication();
	~SolarSystemApplication();
	
	bool setup()	override;
	void shutdown() override;
	bool update()	override;
	void render()	override;

protected:


private:
	glm::mat4 m_projection;
	glm::mat4 m_view;



};
