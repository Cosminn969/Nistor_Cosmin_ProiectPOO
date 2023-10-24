#include <iostream>
using namespace std;

//DOMENIUL CONSTRUCTII

class Utilaj{
public:
	string* nume;
	const int anFabricatie;
	static int nrTotalUtilaje;
	float capacitate;
	int putereMotor;

	Utilaj() : anFabricatie(0) {
		this->nume = new string("nedeterminat");
		this->capacitate = 0;
		this->putereMotor = 0;
		nrTotalUtilaje++;
	}

	Utilaj(float capacitate, int putereMotor,int an) : anFabricatie(an) {
		this->capacitate = capacitate;
		this->putereMotor = putereMotor;
		this->nume = new string("nedeterminat");
		nrTotalUtilaje++;
	}

	Utilaj(string* nume, float capacitate, int putereMotor, int an) :anFabricatie(an) {
		this->capacitate = capacitate;
		this->putereMotor = putereMotor;
		this->nume = nume;
		nrTotalUtilaje++;
	}

	~Utilaj() {
		if (this->nume != NULL)
			delete this->nume;
	}

	void afisareUtilaj() {
		cout << "Utilajul " << *nume << " are o capacitate de " << capacitate << " metrii cubi, o putere a motorului de " << putereMotor << " si a fost fabricat in anul "
			 << anFabricatie;
		cout << endl;
	}

	static int getNrTotalUtilaje() {
		return nrTotalUtilaje;
	}
	
};
int Utilaj::nrTotalUtilaje = 0;;



class Muncitor {
public:
	string nume;
	int varsta;
	const int codMuncitor;
	static int nrTotalMuncitori;
	static int nrGenerator;
	float salariu;
	int* aniExperienta;

	Muncitor() :codMuncitor(nrGenerator++) {
		this->nume = "NA";
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		nrTotalMuncitori++;
	}

	Muncitor(string nume) :codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		nrTotalMuncitori++;
	}

	Muncitor(string nume, int varsta, int* experienta, float salariu) :codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = varsta;
		this->aniExperienta = experienta;
		this->salariu = salariu;
		nrTotalMuncitori++;
	}

	~Muncitor() {
		if (this->aniExperienta != NULL) {
			delete this->aniExperienta;
		}
	}

	void afisareMuncitor() {
		cout << "Muncitorul " << nume << ", cu codul de angajat " << codMuncitor << ", are varsta de " << varsta <<" ani, experienta in domeniu de " 
			<< *aniExperienta << " ani si un salariu de "<< salariu << " RON";
		cout << endl;
	}

	static int getNrTotalMuncitori() {
		return nrTotalMuncitori;
	}

};
int Muncitor::nrTotalMuncitori = 0;
int Muncitor::nrGenerator=500;


class Material {
public:
	string nume;
	const int codInventar;
	static int nrGenerator;
	static float cantitateTotala;
	float cantitate;
	float* rezistenta;
	bool reciclabil;

	Material() :codInventar(nrGenerator++) {
		this->nume = "Nedefinit";
		this->cantitate = 0;
		this->reciclabil = false;
		this->rezistenta = new float(0);
		cantitateTotala = cantitateTotala + cantitate;
	}

	Material(string nume, float cantitate) : codInventar(nrGenerator++) {
		this->nume = nume;
		this->cantitate = cantitate;
		this->reciclabil = false;
		this->rezistenta = new float(0);
		cantitateTotala = cantitateTotala + cantitate;
	}

	Material(string nume, float cantitate, float* rezistenta, bool reciclabil) :codInventar(nrGenerator++) {
		this->nume = nume;
		this->cantitate = cantitate;
		this->rezistenta = rezistenta;
		this->reciclabil = reciclabil;
		cantitateTotala = cantitateTotala + cantitate;
	}

	~Material() {
		if (this->rezistenta != NULL) {
			delete this->rezistenta;
		}
	}

	void afisareMaterial() {
		cout << "Materialul cu codul de inventar " << codInventar << " este " << nume << ", intr-o cantitate de " << cantitate << "kg, are o rezistenta de "
			<< *rezistenta << " MPa (megapascali) si ";
		if (reciclabil) {
			cout << "este reciclabil";
		}
		else
			cout << "nu este reciclabil";
		
		cout << endl;
	}

	static float getCantitateTotala() {
		return cantitateTotala;
	}
};
float Material::cantitateTotala = 0;
int Material::nrGenerator = 10000;

void main() {

		/*UTILAJ START*/

	Utilaj utilaj1;

	utilaj1.afisareUtilaj();
	
	Utilaj utilaj2(15.7, 200, 2010);

	utilaj2.afisareUtilaj();

	string* nume = new string("excavator");
	

	Utilaj utilaj3(nume, 10, 250,2003);

	utilaj3.afisareUtilaj();

	cout << "Numarul total de utilaje este: " << Utilaj::getNrTotalUtilaje() << endl;;

		/*UTILAJ END*/


	cout << endl;


		/*MUNCITOR START*/

	Muncitor muncitor1;

	muncitor1.afisareMuncitor();

	Muncitor muncitor2("Stefan Antonescu");

	muncitor2.afisareMuncitor();

	int* exp = new int(5);

	Muncitor muncitor3("Adelin Petrisor", 36, exp, 3500.69);

	muncitor3.afisareMuncitor();

	cout << "Numarul total de muncitori este: " << Muncitor::getNrTotalMuncitori() << endl;

		/*MUNCITOR END*/
	

	cout << endl;


		/*MATERIAL START*/

	Material material1;

	material1.afisareMaterial();


	Material material2("Ciment",263.5f);

	material2.afisareMaterial();

	float* rezistenta = new float(26.7);

	Material material3("Lemn", 50, rezistenta, true);

	material3.afisareMaterial();

	cout << "Cantitatea totala a materialelor din depozit este de: " << Material::getCantitateTotala()<<" kg";

		/*MATERIAL END*/

}