#include <iostream>
#include <fstream>
#include <math.h> // To use pow
#include <vector> // To use vectors
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class WarBot
{
public:
	double Strength;
	double Defense;
	double Life;
	double Crit;
	double Accuracy;
	double Evasion;
	int quest;
	int Rarity;
};

fillWarbot1(WarBot &warbot1)
{
	warbot1.Strength = 120;
	warbot1.Defense = 120;
	warbot1.Life = 120;
	warbot1.Crit = 120;
	warbot1.Accuracy = 120;
	warbot1.Evasion = 120;
	warbot1.Rarity = 45;
}

fillWarbot2(WarBot &warbot2)
{
	int quest = 6;
	double enemyvalue[11] = {0, 8, 25, 45, 70, 100, 135, 175, 215, 260, 310};
	double value = enemyvalue[quest];
	warbot2.Strength = value;
	warbot2.Defense = value;
	warbot2.Life = value;
	warbot2.Crit = value;
	warbot2.Accuracy = value;
	warbot2.Evasion = value;
	warbot2.Rarity = 35;
	// If real enemy
	/*
	warbot2.Strength = 110;
	warbot2.Defense = 130;
	warbot2.Life = 128;
	warbot2.Crit = 116;
	warbot2.Accuracy = 101;
	warbot2.Evasion = 93;
	*/
}

printWarbots(WarBot warbot1, WarBot warbot2)
{
	cout << "------------Warbot 1 stats: ------------" << endl;
	cout << "Strength: " << warbot1.Strength << endl;
	cout << "Defense: " << warbot1.Defense << endl;
	cout << "Life: " << warbot1.Life << endl;
	cout << "Crit: " << warbot1.Crit << endl;
	cout << "Accuracy: " << warbot1.Accuracy << endl;
	cout << "Evasion: " << warbot1.Evasion << endl;
	cout << endl;
	cout << "------------Warbot 2 stats: ------------" << endl;
	cout << "Strength: " << warbot2.Strength << endl;
	cout << "Defense: " << warbot2.Defense << endl;
	cout << "Life: " << warbot2.Life << endl;
	cout << "Crit: " << warbot2.Crit << endl;
	cout << "Accuracy: " << warbot2.Accuracy << endl;
	cout << "Evasion: " << warbot2.Evasion << endl;
	cout << endl;
	
}

double figth(WarBot warbot1, WarBot warbot2)
{
	std::srand(std::time(0));
	int Nfigths = 100000;
	int win1 = 0;
	int win2 = 0;
	bool printbattle = false;
	
	for(int i = 0; i<Nfigths; i++)
	{
		double salud1 = warbot1.Life * 5;
		double salud2 = warbot2.Life * 5;
		double strength1 = warbot1.Strength;
		double strength2 = warbot2.Strength;
		double defense1 = warbot1.Defense;
		double defense2 = warbot2.Defense;
		double crit1 = warbot1.Crit;
		double crit2 = warbot2.Crit;
		double accuracy1 = warbot1.Accuracy;
		double accuracy2 = warbot2.Accuracy;
		double evasion1 = warbot1.Evasion;
		double evasion2 = warbot2.Evasion;
		
		int critprob1 = warbot1.Rarity;
		int critprob2 = warbot2.Rarity;
		if(printbattle)cout << "------------Start Battle------------" << endl;
		while (salud1>=0 and salud2>=0)
		{
			
		    // Obtener un número aleatorio en el rango [0, 2000]
		    int randomNumber = std::rand() % 2001;
		    // Convertir el número a un valor decimal en el rango [0.0, 1.0]
		    double randomDecimal = static_cast<double>(randomNumber) / 2000.0;
		    // Ajustar el rango para que esté en [0.9, 1.1]
		    double random1 = 0.9 + 0.2 * randomDecimal;
		    double random2 = 0.9 + 0.2 * randomDecimal;
		    
		    // Imprimir el resultado
		    //std::cout << "Número aleatorio en el rango [0.9, 1.1]: " << random1 << " y " << random2 << std::endl;

			double attack1 = strength1 * random1;
			double attack2 = strength2 * random2;
			
			double defensebot1 = defense1 / (defense1 + 200.0);
			double defensebot2 = defense2 / (defense2 + 200.0);
			
			double damageReceivedNormal1 = attack2 - attack2*defensebot1;
			double damageReceivedNormal2 = attack1 - attack1*defensebot2;
			
			double damageReceivedCritical1 = damageReceivedNormal1 + crit2;
			double damageReceivedCritical2 = damageReceivedNormal2 + crit1;
			
			double hitProb1 = 75 + (accuracy1-evasion2)/4.0;
			double hitProb2 = 75 + (accuracy2-evasion1)/4.0;
			/*
			cout << "attack1: " << attack1 << " attack2: " << attack2 << endl;
			cout << "defensebot1: " << defensebot1 << " defensebot2: " << defensebot2 << endl;
			cout << "damageReceived1: " << damageReceivedNormal1 << " damageReceived2: " << damageReceivedNormal2 << endl;
			cout << "damageReceivedCritical1: " << damageReceivedCritical1 << " damageReceivedCritical2: " << damageReceivedCritical2 << endl;
			cout << "hitProb1: " << hitProb1 << " hitProb2: " << hitProb2 << endl;
			*/
			int numeroAleatorio1 = std::rand() % 100 + 1;
			int numeroAleatorio2 = std::rand() % 100 + 1;
			int numeroAleatorio3 = std::rand() % 100 + 1;
			int numeroAleatorio4 = std::rand() % 100 + 1;
    		//std::cout << "Número aleatorio en el rango [1, 100]: " << numeroAleatorio1 << " " << numeroAleatorio2 << " " << numeroAleatorio3 << " " << numeroAleatorio4 << std::endl;
    		
    		
    		// Start figth!
    		double damageReceived2 = 0.0;
    		double damageReceived1 = 0.0;
    		
    		// Bot 1 attacking
    		if(numeroAleatorio1 < critprob1) damageReceived2 = damageReceivedCritical2;
    		else damageReceived2 = damageReceivedNormal2;
    		
    		if(numeroAleatorio3 < hitProb1) damageReceived2 = damageReceived2;
    		else damageReceived2 = 0.0;
    		
    		salud2 = salud2 - damageReceived2;
    		
    		if(printbattle)cout << "**Bot 1 attack: " << damageReceived2 << endl;
    		
    		// check bot 2 life
    		if(salud2 <= 0){
    			win1++;
				break;	
			} 
    		
    		// Bot 2 attacking
    		if(numeroAleatorio2 < critprob2) damageReceived1 = damageReceivedCritical1;
    		else damageReceived1 = damageReceivedNormal1;
    		
    		if(numeroAleatorio4 < hitProb2) damageReceived1 = damageReceived1;
    		else damageReceived1 = 0.0;
    		
    		salud1 = salud1 - damageReceived1;
    		if(printbattle){
    			cout << "**Bot 2 attack: " << damageReceived1 << endl;
    		
	    		cout << "***Life 1: " << salud1 << endl;
	    		cout << "***Life 2: " << salud2 << endl;
			}

    		// check bot 1 life
    		if(salud1 <= 0){
    			win2++;
				break;	
			}
			
			if(printbattle)cout << "-------" << endl;

		}
		if(printbattle)cout << "Bot_1 wins: " << win1 << " || Bot_2 wins: " << win2 << endl;
	}
	double probwin = 100 * ((double)win1 / ((double)win1 + (double)win2));
	
	if(printbattle)
	{
		cout << "******************** END ALL BATTLES ********************" << endl;
		cout << endl;
		cout << "Bot_1 wins: " << win1 << " || Bot_2 wins: " << win2 << endl;
		cout << "Probability win: " << probwin << endl;
	}

	
	return probwin;
	
}


parametric(WarBot warbot1, WarBot warbot2, string variable)
{
	int maxstat = 20;
	double probL[maxstat];
	double warbot1Lifevec[maxstat];
	double warbot1Strengthvec[maxstat];
	double warbot1Defensevec[maxstat];
	double warbot1Critvec[maxstat];
	double warbot1Accuracyvec[maxstat];
	double warbot1Evasionvec[maxstat];
	double warbot1Totvec[maxstat];
	
	double salud1 = warbot1.Life;
	double salud2 = warbot2.Life;
	double strength1 = warbot1.Strength;
	double strength2 = warbot2.Strength;
	double defense1 = warbot1.Defense;
	double defense2 = warbot2.Defense;
	double crit1 = warbot1.Crit;
	double crit2 = warbot2.Crit;
	double accuracy1 = warbot1.Accuracy;
	double accuracy2 = warbot2.Accuracy;
	double evasion1 = warbot1.Evasion;
	double evasion2 = warbot2.Evasion;
		
	
	for(int i = 0; i<maxstat; i++)
	{
		if(variable == "Life")
		{
			warbot1.Life = salud1 + i;
			warbot1Lifevec[i] = warbot1.Life;
		}
		if(variable ==  "Strength")
		{
			warbot1.Strength = strength1 + i;
			warbot1Strengthvec[i] = warbot1.Strength;
		}
		if(variable ==  "Defense")
		{
			warbot1.Defense = defense1 + i;
			warbot1Defensevec[i] = warbot1.Defense;
		}
		if(variable ==  "Crit")
		{
			warbot1.Crit = crit1 + i;
			warbot1Critvec[i] = warbot1.Crit;
		}
		if(variable ==  "Accuracy")
		{
			warbot1.Accuracy = accuracy1 + i;
			warbot1Accuracyvec[i] = warbot1.Accuracy;
		}
		if(variable ==  "Evasion")
		{
			warbot1.Evasion = evasion1 + i;
			warbot1Evasionvec[i] = warbot1.Evasion;
		}
		if(variable ==  "Tot")
		{
			warbot1.Life = salud1 + i;
			warbot1.Strength = strength1 + i;
			warbot1.Defense = defense1 + i;
			warbot1.Crit = crit1 + i;
			warbot1.Accuracy = accuracy1 + i;
			warbot1.Evasion = evasion1 + i;
			warbot1Totvec[i] = warbot1.Evasion + 5*i;
		}
		
		probL[i] = figth(warbot1, warbot2);
	}
	
	// Life Output
	if(variable == "Life")
	{
		ofstream Archivo;
		Archivo.open("Output/StatsWinLife.txt", ios::trunc);
		Archivo << "#Life WinProbability" << endl;	
		Archivo.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo.open("Output/StatsWinLife.txt", ios::app);
			Archivo << warbot1Lifevec[i] << " " << probL[i] << endl;
			Archivo.close();
		}	
	}

	// strength1 Output
	if(variable == "Strength")
	{
		ofstream Archivo2;
		Archivo2.open("Output/StatsWinStrength.txt", ios::trunc);
		Archivo2 << "#Strength WinProbability" << endl;	
		Archivo2.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo2.open("Output/StatsWinStrength.txt", ios::app);
			Archivo2 << warbot1Strengthvec[i] << " " << probL[i] << endl;
			Archivo2.close();
		}	
	}

	// Defense Output
	if(variable == "Defense")
	{
		ofstream Archivo3;
		Archivo3.open("Output/StatsWinDefense.txt", ios::trunc);
		Archivo3 << "#Defense WinProbability" << endl;	
		Archivo3.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo3.open("Output/StatsWinDefense.txt", ios::app);
			Archivo3 << warbot1Defensevec[i] << " " << probL[i] << endl;
			Archivo3.close();
		}	
	}
	
	// Crit Output
	if(variable == "Crit")
	{
		ofstream Archivo4;
		Archivo4.open("Output/StatsWinCrit.txt", ios::trunc);
		Archivo4 << "#Crit WinProbability" << endl;	
		Archivo4.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo4.open("Output/StatsWinCrit.txt", ios::app);
			Archivo4 << warbot1Critvec[i] << " " << probL[i] << endl;
			Archivo4.close();
		}	
	}
	
	// Accuracy Output
	if(variable == "Accuracy")
	{
		ofstream Archivo5;
		Archivo5.open("Output/StatsWinAccuracy.txt", ios::trunc);
		Archivo5 << "#Accuracy WinProbability" << endl;	
		Archivo5.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo5.open("Output/StatsWinAccuracy.txt", ios::app);
			Archivo5 << warbot1Accuracyvec[i] << " " << probL[i] << endl;
			Archivo5.close();
		}	
	}
	
	// Evasion Output
	if(variable == "Evasion")
	{
		ofstream Archivo6;
		Archivo6.open("Output/StatsWinEvasion.txt", ios::trunc);
		Archivo6 << "#Evasion WinProbability" << endl;	
		Archivo6.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo6.open("Output/StatsWinEvasion.txt", ios::app);
			Archivo6 << warbot1Evasionvec[i] << " " << probL[i] << endl;
			Archivo6.close();
		}	
	}
	
	// Tot Output
	if(variable == "Tot")
	{
		
		ofstream Archivo7;
		Archivo7.open("Output/StatsWinTot.txt", ios::trunc);
		Archivo7 << "#Stats WinProbability" << endl;	
		Archivo7.close();
		for(int i = 0; i<maxstat; i++)
		{
			Archivo7.open("Output/StatsWinTot.txt", ios::app);
			Archivo7 << warbot1Totvec[i] << " " << probL[i] << endl;
			Archivo7.close();
			//cout << " i: " << i << warbot1Totvec[i] << endl;
		}	
		
	}

}

int main()
{
	cout << "funciona " << endl;
	
	WarBot warbot1;
	WarBot warbot2;
	
	fillWarbot1(warbot1);
	fillWarbot2(warbot2);
	
	printWarbots(warbot1, warbot2);
	
	double prob = figth(warbot1, warbot2);
	cout << " Winning Probability: " << prob << endl;
	
	/*
	parametric(warbot1, warbot2, "Life");
	parametric(warbot1, warbot2, "Strength");
	parametric(warbot1, warbot2, "Defense");
	parametric(warbot1, warbot2, "Crit");
	parametric(warbot1, warbot2, "Accuracy");
	parametric(warbot1, warbot2, "Evasion");
	*/
	parametric(warbot1, warbot2, "Tot");
	
}
