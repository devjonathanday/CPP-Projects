#include "Factory.h"

Factory::Factory() {}
Factory::Factory(Factory const&) {}
void Factory::operator=(Factory const&) {}

Factory & Factory::GetFactory()
{
	static Factory instance;
	return instance;
}

IBox* Factory::Create(std::string type)
{
	//switch (type)
	//{
	//case "Red":
	//		return new RedBox();
	//		break;
	//case "Blue":
	//	return new BlueBox();
	//	break;
	//}
	if (type == "Red")
		return new RedBox();

	if (type == "Blue")
		return new BlueBox();

	return NULL;
}