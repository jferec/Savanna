#pragma once
class CStats//KLASA ZAWIERAJ¥CA STATYSTYKI Z SYMULACJI
{
public:
	CStats();
	~CStats();///////////////////////////////////////////////////////
	static int getNumberOfAnimals();						/////////////
	static int getNumberOfDeaths();							/////////////
	static int getNumberOfEating();							/////////////
	static int getNumberOfDrinking();						/////////////
	static int getNumberOfReproductions();					/////////////
	static int getTotalAge();								/////////////
	static int getSimulationTime();
	static int getGeneratedID();
	/////////////
	static void setNumberOfAnimals(int value);				//GETTERY
	static void setNumberOfDeaths(int value);				//SETTERY
	static void setNumberOfEating(int value);				/////////////
	static void setNumberOfDrinking(int value);				///......////
	static void setNumberOfReproductions(int value);
	static void setTotalAge(int value);
	static void setSimulationTime(int value);
	static void setGeneratedID(int value);
	static int IDGenerator();
private:
	static int numberOfAnimals;//////////LICZBA ZWIERZAT
	static int numberOfDeaths;///////////LICZBA SMIERCI
	static int numberOfEating;///////////LICZBA POSILKOW
	static int numberOfDrinking;/////////LICZBA SPOZYC WODY
	static int numberOfReproductions;////LICZBA ROZMNOZEN
	static int totalAge;/////////////////CALKOWITY WIEK ZWIERZAT
	static int simulationTime;///////////CZAS SYMULACJI
	static int generatedID;
};
