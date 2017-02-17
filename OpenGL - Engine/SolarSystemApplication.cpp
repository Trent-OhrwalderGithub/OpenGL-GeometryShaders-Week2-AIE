#include "SolarSystemApplication.h"
#include <Gizmos.h>

SolarSystemApplication::SolarSystemApplication()
	: baseApplication("Solar System", 1280, 720)
{

}

SolarSystemApplication::~SolarSystemApplication()
{

}

bool SolarSystemApplication::setup()
{
	aie::Gizmos::create(64000, 64000, 0, 0);

	m_projection =	glm::perspective(glm::pi<float>() * 0.25f,
					(float)getWindowWidth() / (float)getWindowHeight(),
					0.1f, 1000.0f);

	m_view = glm::lookAt(glm::vec3(10, 10, 10),
						 glm::vec3(0, 0, 0),
						 glm::vec3(0, 1, 0)
						);


	return true;
}

void SolarSystemApplication::shutdown()
{
	aie::Gizmos::destroy();
}

bool SolarSystemApplication::update()
{
	return true;
}

void SolarSystemApplication::render()
{
	aie::Gizmos::clear();

	// Just Gizmos stuff // 


	aie::Gizmos::draw(m_projection * m_view);
}


