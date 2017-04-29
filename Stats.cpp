#include "Stats.h"


	int CStats::numberOfAnimals = 0;
	int CStats::numberOfDeaths = 0;
	int CStats::numberOfEating = 0;
	int CStats::numberOfDrinking = 0;
	int CStats::numberOfReproductions = 0;
	int CStats::totalAge = 0;
	int CStats::simulationTime = 0;
	int CStats::generatedID = 100000;
CStats::CStats()
{
}


CStats::~CStats()
{
}

int CStats::getNumberOfAnimals()
{
	return numberOfAnimals;
}
int CStats::getNumberOfDeaths()
{
	return numberOfDeaths;
}
int CStats::getNumberOfEating()
{
	return numberOfEating;
}
int CStats::getNumberOfDrinking()
{
	return numberOfDrinking;
}
int CStats::getNumberOfReproductions()
{
	return numberOfReproductions;
}
int CStats::getTotalAge()
{
	return totalAge;
}
int CStats::getSimulationTime()
{
	return simulationTime;
}
int CStats::getGeneratedID()
{
	return generatedID;
}

void CStats::setNumberOfAnimals(int value)
{
	numberOfAnimals = value;
}

void CStats::setNumberOfDeaths(int value)
{
	numberOfDeaths = value;
}
void CStats::setNumberOfEating(int value)
{
	numberOfEating = value;
}
void CStats::setNumberOfDrinking(int value)
{
	numberOfDrinking = value;
}
void CStats::setNumberOfReproductions(int value)
{
	numberOfReproductions = value;
}
void CStats::setTotalAge(int value)
{
	totalAge = value;
}
void CStats::setSimulationTime(int value)
{
	simulationTime = value;
}

void CStats::setGeneratedID(int value)
{
	generatedID = value;
}
int CStats::IDGenerator()
{ 
	setGeneratedID(CStats::getGeneratedID() + 1);
	return generatedID;
}