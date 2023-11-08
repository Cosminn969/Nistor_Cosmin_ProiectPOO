#include <iostream>
using namespace std;

//DOMENIUL CONSTRUCTII

class Utilaj {
private:
	string* nume;
	const int anFabricatie;
	static int nrTotalUtilaje;
	float capacitate;
	int putereMotor;
	float nivelCombustibil;
	float consumPeOra;

public:

	Utilaj() : anFabricatie(2000) {
		this->nume = new string("nedeterminat");
		this->capacitate = 0;
		this->putereMotor = 0;
		this->nivelCombustibil = 0;
		this->consumPeOra = 0;
		nrTotalUtilaje++;
	}

	Utilaj(float capacitate, int putereMotor, int an) : anFabricatie(an) {
		this->capacitate = capacitate;
		this->putereMotor = putereMotor;
		this->nivelCombustibil = 0;
		this->consumPeOra = 0;
		this->nume = new string("nedeterminat");
		nrTotalUtilaje++;
	}

	Utilaj(string* nume, float capacitate, int putereMotor, float nivelCombustibil,float consumPeOra, int an) :anFabricatie(an) {
		this->capacitate = capacitate;
		this->putereMotor = putereMotor;
		this->nume = nume;
		this->nivelCombustibil = nivelCombustibil;
		this->consumPeOra = consumPeOra;
		nrTotalUtilaje++;
	}

	Utilaj(const Utilaj& u) :anFabricatie(u.anFabricatie) {
		this->nume = new string(*u.nume);
		this->capacitate = u.capacitate;
		this->putereMotor = u.putereMotor;
		this->nivelCombustibil = u.nivelCombustibil;
		this->consumPeOra = u.consumPeOra;
		nrTotalUtilaje++;
	}

	Utilaj operator=(const Utilaj& u) {
		if (this != &u) {
			if (this->nume != NULL)
				delete this->nume;
			this->nume = new string(*u.nume);
			this->capacitate = u.capacitate;
			this->putereMotor = u.putereMotor;
			this->nivelCombustibil = u.nivelCombustibil;
			this->consumPeOra = u.consumPeOra;
			
		}
		return *this;
	}

	float operator+(const Utilaj& u) {
		return consumPeOra + u.consumPeOra;
	}

	bool operator>(const Utilaj& u) {
		return this->putereMotor > u.putereMotor && this->capacitate > u.capacitate;
	}

	bool operator<(const Utilaj& u) {
		return this->putereMotor < u.putereMotor && this->capacitate < u.capacitate;
	}

	~Utilaj() {
		if (this->nume != NULL)
			delete this->nume;
	}

	void afisareUtilaj() {
		cout << "Utilajul " << *nume << " are o capacitate de " << capacitate << " metrii cubi, o putere a motorului de " 
			<< putereMotor <<", nivelul combustibilului este de "<<nivelCombustibil << " litrii, consuma "<<consumPeOra<<" litrii de combustibil pe ora si a fost fabricat in anul "<< anFabricatie;
		cout << endl;
	}

	static int getNrTotalUtilaje() {
		return nrTotalUtilaje;
	}

	void setNrTotalUtilaje(int nrTotalUtilaje) {
		if (nrTotalUtilaje > 0) {
			this->nrTotalUtilaje = nrTotalUtilaje;
		}
	}

	string getNume() {
		return *nume;
	}

	void setNume(string* nume) {
		if (nume != NULL) {
			this->nume = nume;
		}
	}

	const int getAnFabricatie() {
		return anFabricatie;
	}

	float getCapacitate() {
		return capacitate;
	}

	void setCapacitate(float capacitate) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
	}

	int getPutereMotor() {
		return putereMotor;
	}

	void setPutereMotor(int putereMotor) {
		if (putereMotor > 0) {
			this->putereMotor = putereMotor;
		}
	}

	float getConsumPeOra() {
		return consumPeOra;
	}

	void setConsumPeOra(float consumPeOra) {
		if (consumPeOra > 0) {
			this->consumPeOra = consumPeOra;
		}
	}

	float getNivelCombustibil() {
		return nivelCombustibil;
	}

	void setNivelCombustibil(float combustibil) {
		this->nivelCombustibil = combustibil;
	}



	friend void utilizeazaUtilaj(Utilaj& utilaj, int timpUtilizat);
};
int Utilaj::nrTotalUtilaje = 0;

void utilizeazaUtilaj(Utilaj& utilaj, int timpUtilizat) {
	if (timpUtilizat > 0) {
		float combustibilUtilizat = utilaj.consumPeOra * timpUtilizat;
		utilaj.nivelCombustibil -= combustibilUtilizat;
		if (utilaj.nivelCombustibil > 0) {
			cout << "Utilajul "<<*utilaj.nume<<" a fost utilizat timp de " << timpUtilizat << " ore, cu un consum pe ora de " << utilaj.consumPeOra << " si a ramas cu "
				<< utilaj.nivelCombustibil << " litrii de combustibil" << endl;
		}
		else
			cout << "Utilajul a fost utilizat timp de " << timpUtilizat << "ore, cu un consum pe ora de " << utilaj.consumPeOra << " si la finalul utilizarii a ramas fara combustibil";

	}
	else
		cout << "Utilajul nu a fost utilizat";
		

}


class Muncitor {
private:
	string nume;
	int varsta;
	const int codMuncitor;
	static int nrTotalMuncitori;
	static int nrGenerator;
	static float bonusPeOra;
	float salariu;
	int orePesteProgram;
	int* aniExperienta;

public:

	Muncitor() :codMuncitor(nrGenerator++) {
		this->nume = "NA";
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		this->orePesteProgram = 0;
		nrTotalMuncitori++;
	}

	Muncitor(string nume) :codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		this->orePesteProgram = 0;
		nrTotalMuncitori++;
	}

	Muncitor(string nume, int varsta, int* experienta,int ore, float salariu) :codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = varsta;
		this->aniExperienta = experienta;
		this->salariu = salariu;
		this->orePesteProgram = ore;
		nrTotalMuncitori++;
	}

	Muncitor(const Muncitor& m) :codMuncitor(nrGenerator++) {
		this->nume = m.nume;
		this->varsta = m.varsta;
		this->aniExperienta =new int (*m.aniExperienta);
		this->salariu = m.salariu;
		this->orePesteProgram=m.orePesteProgram;
		nrTotalMuncitori++;
	}

	Muncitor operator=(const Muncitor& m) {
		this->nume = m.nume;
		this->varsta = m.varsta;
		if (this->aniExperienta != NULL) {
			delete this->aniExperienta;
		}
		this->aniExperienta = new int(*m.aniExperienta);
		this->salariu = m.salariu;
		this->orePesteProgram = m.orePesteProgram;
		return *this;
	}

	friend ostream& operator<<(ostream& monitor, const Muncitor& m) {
		monitor << "Nume: " << m.nume<<endl;
		monitor << "Varsta: " << m.varsta << endl;
		monitor << "Cod: " << m.codMuncitor << endl;
		monitor << "Experienta: " << *m.aniExperienta << " ani" << endl;
		monitor << "Salariu: " << m.salariu << " RON" << endl;
		return monitor;
	}

	friend istream& operator>>(istream& tastatura, Muncitor& m) {
		cout << "Nume: ";
		tastatura >> m.nume;
		cout << "Varsta: ";
		tastatura >> m.varsta;
		cout << "Experienta: ";
		tastatura >> *m.aniExperienta;
		cout << "Salariu: ";
		tastatura >> m.salariu;
		cout << endl;
		return tastatura;
	}

	Muncitor operator++(int) {
		this->salariu += 800;
		return *this;
	}

	~Muncitor() {
		if (this->aniExperienta != NULL) {
			delete this->aniExperienta;
		}
	}

	void afisareMuncitor() {
		cout << "Muncitorul " << nume << ", cu codul de angajat " << codMuncitor << ", are varsta de " << varsta << " ani, experienta in domeniu de "
			<< *aniExperienta << " ani si un salariu de " << salariu << " RON";
		cout << endl;
	}

	static int getNrTotalMuncitori() {
		return nrTotalMuncitori;
	}

	void setNrTotalMuncitori(static int muncitori) {
		this->nrTotalMuncitori = muncitori;
	}

	string getNume() {
		return nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	int getVarsta() {
		return varsta;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	const int getCodMuncitor() {
		return codMuncitor;
	}

	static int getNrGenerator() {
		return nrGenerator;
	}

	void setNrGenerator(static int generator) {
		this->nrGenerator = generator;
	}

	float getSalariu() {
		return salariu;
	}

	void setSalariu(float salariu) {
		if (salariu > 0) {
			this->salariu = salariu;
		}
	}

	int* getAniExperienta() {
		return aniExperienta;
	}

	void setAniExperienta(int* experienta) {
		this->aniExperienta = experienta;
	}

	int getOre() {
		return orePesteProgram;
	}

	void setOre(int ore) {
		this->orePesteProgram = ore;
	}

	friend void bonusMuncitor(Muncitor& muncitor);
};
int Muncitor::nrTotalMuncitori = 0;
int Muncitor::nrGenerator = 500;
float Muncitor::bonusPeOra = 24.99;

void bonusMuncitor(Muncitor& muncitor) {
	if (muncitor.orePesteProgram > 0) {
		float bonus = (muncitor.bonusPeOra * Muncitor::bonusPeOra);
		muncitor.salariu +=0.05 * bonus;
		cout << muncitor.nume << " a lucrat " << muncitor.orePesteProgram << " ore peste program si a capatat un bonus de " << bonus
			<< " RON, din care 5% a fost adaugat la salariu, care a devenit " << muncitor.salariu << endl;;
	}
	else
		cout << muncitor.nume << " nu a lucrat peste program"<<endl;
}


class Material {
private:
	string nume;
	const int codInventar;
	static int nrGenerator;
	static float cantitateTotala;
	float cantitate;
	float* rezistenta;
	bool reciclabil;

public:

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

	Material(const Material& m) :codInventar(nrGenerator++) {
		this->nume = m.nume;
		this->cantitate = m.cantitate;
		this->rezistenta = new float(*m.rezistenta);
		this->reciclabil = m.reciclabil;
		cantitateTotala = cantitateTotala + cantitate;
	}
	
	Material operator=(const Material& m) {
		if (this != &m) {
			this->nume = m.nume;
			cantitateTotala = cantitateTotala - this->cantitate + m.cantitate;
			this->cantitate = m.cantitate;
			if (this->rezistenta != NULL)
				delete this->rezistenta;
			this->rezistenta = new float(*m.rezistenta);
			this->reciclabil = m.reciclabil;
		}
		return *this;
	}

	Material operator+=(const Material& m) {
		this->cantitate += m.cantitate;
		return *this;
	}

	operator float() {
		return cantitate;
	}

	Material operator!() {
		cantitateTotala -= cantitate;
		if (cantitate != 0)
			cantitate = 0;
		
		return *this;
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

	void setCantitateTotala(float cantitate) {
		if (cantitate > 0) {
			this->cantitateTotala = cantitate;
		}
	}

	string getNume() {
			return nume;
	}

	void setNume(string nume) {
		if (&this->nume != NULL)
			this->nume = nume;
	}

	const int getCodInventar() {
		return codInventar;
	}

	float getCantitate() {
		return cantitate;
	}

	void setCantitate(float cantitate) {
		if (cantitate != this->cantitate) {
			cantitateTotala -= this->cantitate;
			cantitateTotala += cantitate;
		}
		
		this->cantitate=cantitate;
		
	}

	float* getRezistenta() {
		return rezistenta;
	}

	void setRezistenta(float* rezistenta){
		this->rezistenta = rezistenta;
	}

	bool getReciclabil(){
		return reciclabil;
	}

	void setReciclabil(bool reciclabil) {
		this->reciclabil = reciclabil;
	}
};
float Material::cantitateTotala = 0;
int Material::nrGenerator = 10000;



void main() {

	/*UTILAJ START*/
	cout << "UTILAJ 1:" << endl;
	Utilaj utilaj1;
	utilaj1.afisareUtilaj();
	string* nume1 = new string("buldozer");
	utilaj1.setCapacitate(40);
	utilaj1.setConsumPeOra(25);
	utilaj1.setNivelCombustibil(500);
	utilaj1.setNume(nume1);
	utilaj1.setPutereMotor(300);
	utilaj1.afisareUtilaj();


	cout << "UTILAJ 2:" << endl;
	Utilaj utilaj2(15.7, 300, 2010);
	utilaj2.afisareUtilaj();
	string* nume3 = new string("macara");
	utilaj2.setNume(nume3);
	utilaj2.setNivelCombustibil(200);
	utilaj2.setConsumPeOra(7);
	utilaj2.afisareUtilaj();

	cout << "UTILAJ 3:" << endl;
	
	string* nume = new string("excavator");

	Utilaj utilaj3(nume, 10, 250,400,20, 2003);
	
	utilaj3.afisareUtilaj();

	utilizeazaUtilaj(utilaj3, 2); //Functia friend a clasei Utilaj

	cout << "UTILAJ 4:" << endl;
	Utilaj utilaj4 = utilaj3; //Apelarea constructorului de copiere

	utilaj4.afisareUtilaj();

	cout << "Utilajul 4 are numele " << utilaj4.getNume() << " a fost fabricat in anul " << utilaj4.getAnFabricatie() << ", are o capacitate de " << utilaj4.getCapacitate()
		<< " metrii cubi, puterea motorului este de " << utilaj4.getPutereMotor() << " CP, nivelul combustibilului este de " << utilaj4.getNivelCombustibil()
		<< " litrii, iar consumul pe ora este de " << utilaj4.getConsumPeOra()<<" litrii"<< endl;

	

	Utilaj utilaj5;
	utilaj5.afisareUtilaj();
	utilaj5 = utilaj4;
	utilaj5.afisareUtilaj();

	cout <<"Consumul adunat al celor 2 utilaje: "<<utilaj3 + utilaj4 << endl;

	if (utilaj2 > utilaj3)
		cout << utilaj2.getNume() << " are o putere si o capacitate mai mare decat " << utilaj3.getNume() << endl;

	if (utilaj3 < utilaj2)
		cout << utilaj3.getNume() << " are o putere si o capacitate mai mica decat " << utilaj2.getNume() << endl;
	
	cout << "Numarul total de utilaje este: " << Utilaj::getNrTotalUtilaje() << endl;
	
	/*UTILAJ END*/


	for (int i = 0; i < 171; i++) {
		cout << "-";
	}
	cout << endl;


	/*MUNCITOR START*/

	Muncitor muncitor1;
	cout << "MUNCITOR 1:" << endl;
	int* experienta = new int(11);
	muncitor1.afisareMuncitor();
	muncitor1.setAniExperienta(experienta);
	muncitor1.setNume("Gheorghita Anton");
	muncitor1.setSalariu(4890);
	muncitor1.setVarsta(43);
	muncitor1.afisareMuncitor();

	cout << "MUNCITOR 2:" << endl;
	Muncitor muncitor2("Stefan Antonescu");

	int* exp2 = new int(3);
	muncitor2.afisareMuncitor();
	
	muncitor2.setAniExperienta(exp2);		
	muncitor2.setNume("Stefanel Antonescu");		
	muncitor2.setSalariu(2890);					
	muncitor2.setVarsta(26);					
	
	muncitor2.afisareMuncitor();

	cout << "MUNCITOR 3:" << endl;
	
	int* exp = new int(5);

	Muncitor muncitor3("Adelin Petrisor", 36, exp,3, 3500.69);

	muncitor3.afisareMuncitor();

	cout << "MUNCITOR 4:" << endl;
	Muncitor muncitor4 = muncitor3;
	
	muncitor4.setNume("Petronel Mirel");
	bonusMuncitor(muncitor4);
	
	cout << "Muncitorul " << muncitor4.getNume() << ", cu codul de angajat " << muncitor4.getCodMuncitor() << ", are varsta de " << muncitor4.getVarsta() << " ani, experienta in domeniu de "
		<< *muncitor4.getAniExperienta() << " ani si un salariu de " << muncitor4.getSalariu() << " RON"<<endl;
	
	Muncitor muncitor5 = muncitor4;
	cout << "MUNCITOR 5:" << endl;
	muncitor5 = muncitor3;
	cout << muncitor5;
	

	cout << "MUNCITOR 6: " << endl;
	Muncitor muncitor6;
	cin >> muncitor6;
	
	muncitor6++;
	cout << muncitor6.getSalariu()<<endl;

	cout << "Numarul total de muncitori este: " << Muncitor::getNrTotalMuncitori() << endl;

	/*MUNCITOR END*/

	

	for (int i = 0; i < 171; i++) {
		cout << "-";
	}
	cout << endl;

	/*MATERIAL START*/

	Material material1;
	material1.afisareMaterial();
	material1.setCantitate(37);
	material1.setNume("nisip");
	material1.setReciclabil(true);
	float* rez = new float(7.3);
	material1.setRezistenta(rez);
	material1.afisareMaterial();


	Material material2("Ciment", 263.5f);

	material2.afisareMaterial();

	float* rezistenta = new float(26.7);

	Material material3("Lemn", 50, rezistenta, true);

	material3.afisareMaterial();

	Material material4 = material3;

	material4.setCantitate(68.7);

	material4.afisareMaterial();


	cout << "MATERIAL 5: " << endl;
	Material material5;

	material5 = material4;
	material5.afisareMaterial();

	material5 += material3;
	material5.afisareMaterial();

	!material5;

	material5.afisareMaterial();

	cout << "Cantitatea totala a materialelor din depozit este de: " << Material::getCantitateTotala() << " kg" << endl;
	
	/*MATERIAL END*/

}