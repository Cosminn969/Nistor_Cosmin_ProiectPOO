#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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

	friend ofstream& operator<<(ofstream& out, const Utilaj& u) {
		out << "Utilajul " << *u.nume << " are o capacitate de " << u.capacitate << " metrii cubi, o putere a motorului de "
			<< u.putereMotor << ", nivelul combustibilului este de " << u.nivelCombustibil << " litrii, consuma " << u.consumPeOra << " litrii de combustibil pe ora si a fost fabricat in anul " << u.anFabricatie;
		out << endl;

		return out;
	}

	friend ifstream& operator>>(ifstream& in, Utilaj& u) {
		in >> *u.nume;
		in >> u.capacitate;
		in >> u.putereMotor;
		in >> u.nivelCombustibil;
		in >> u.consumPeOra;
		
		return in;
	}

	

	friend istream& operator>>(istream& i, Utilaj& u) {
		cout << "Numele utilajului: ";
		i >> *u.nume;
		cout << "Capacitatea utilajului: ";
		i >> u.capacitate;
		cout << "Puterea motorului: ";
		i >> u.putereMotor;
		cout << "Nivelul combustibilului: ";
		i >> u.nivelCombustibil;
		cout << "Consumul pe ora: ";
		i >> u.consumPeOra;

		return i;

	}

	friend ostream& operator<<(ostream& o, const Utilaj& u) {
		o << "Utilajul " << *u.nume << " are o capacitate de " << u.capacitate << " metrii cubi, o putere a motorului de "
			<< u.putereMotor << ", nivelul combustibilului este de " << u.nivelCombustibil << " litrii, consuma " << u.consumPeOra << " litrii de combustibil pe ora si a fost fabricat in anul " << u.anFabricatie;
		o << endl;
		return o;
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

class Persoana {

	float greutate;
	float inaltime;

public:
	virtual void descriePersoana() = 0;

	Persoana() {
		this->greutate = 65;
		this->inaltime = 170;
	}

	Persoana(float g, float i) {
		this->greutate = g;
		this->inaltime = i;
	}

	float getGreutate() {
		return this->greutate;
	}

	void setGreutate(float g) {
		this->greutate = g;
	}

	float getInaltime() {
		return this->inaltime;
	}

	void setInaltime(float i) {
		this->inaltime = i;
	}
};

class Muncitor: public Persoana {
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

	Muncitor() :Persoana(), codMuncitor(nrGenerator++) {
		this->nume = "NA";
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		this->orePesteProgram = 0;
		nrTotalMuncitori++;
	}

	Muncitor(string nume) :Persoana(),codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = 0;
		this->salariu = 0;
		this->aniExperienta = new int(0);
		this->orePesteProgram = 0;
		nrTotalMuncitori++;
	}

	Muncitor(string nume, int varsta, int* experienta,int ore, float salariu) :Persoana(),codMuncitor(nrGenerator++) {
		this->nume = nume;
		this->varsta = varsta;
		this->aniExperienta = experienta;
		this->salariu = salariu;
		this->orePesteProgram = ore;
		nrTotalMuncitori++;
	}

	Muncitor(const Muncitor& m) :Persoana(m),codMuncitor(nrGenerator++) {
		this->nume = m.nume;
		this->varsta = m.varsta;
		this->aniExperienta =new int (*m.aniExperienta);
		this->salariu = m.salariu;
		this->orePesteProgram=m.orePesteProgram;
		nrTotalMuncitori++;
	}

	Muncitor operator=(const Muncitor& m) {
		if (this != &m) {
			Persoana::operator=(m);
			this->nume = m.nume;
			this->varsta = m.varsta;
			if (this->aniExperienta != NULL) {
				delete this->aniExperienta;
			}
			this->aniExperienta = new int(*m.aniExperienta);
			this->salariu = m.salariu;
			this->orePesteProgram = m.orePesteProgram;
		}
		return *this;
	}

	void descriePersoana() {
		cout << "Muncitorul " << this->nume << " are " << this->varsta << " ani"<<endl;
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

	friend ofstream& operator<<(ofstream& out, const Muncitor& m) {
		out << "Nume: " << m.nume << endl;
		out << "Varsta: " << m.varsta << endl;
		out << "Cod: " << m.codMuncitor << endl;
		out << "Experienta: " << *m.aniExperienta << " ani" << endl;
		out << "Salariu: " << m.salariu << " RON" << endl;
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Muncitor& m) {
		
		in >> m.nume;
		
		in >> m.varsta;
		
		in >> *m.aniExperienta;
		
		in >> m.salariu;
		cout << endl;
		return in;
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

	friend ostream& operator<<(ostream& o, const Material& m) {
		o << "Materialul cu codul de inventar " << m.codInventar << " este " << m.nume << ", intr-o cantitate de " << m.cantitate << "kg, are o rezistenta de "
			<< *m.rezistenta << " MPa (megapascali) si ";
		if (m.reciclabil) {
			cout << "este reciclabil";
		}
		else
			cout << "nu este reciclabil";

		cout << endl;
		return o;
	}

	friend istream& operator>>(istream& tastatura, Material& m) {
		cout << "Numele materialului: ";
		tastatura >> m.nume;
		cout << "Cantitatea: ";
		tastatura >> m.cantitate;
		cout << "Rezistenta: ";
		tastatura >> *m.rezistenta;
		cout << "Este reciclabil? (y/n): ";
		char aux;
		tastatura >> aux;
		if (aux == 'y' || aux == 'Y')
			m.reciclabil = true;
		else
			if (aux == 'n' || aux == 'N')
				m.reciclabil = false;
			else
				cout << "Ati introdus un caracter gresit";
		cout << endl;
		return tastatura;
	}

	void scrieMaterialBinar(fstream& f) {
		f.write(( char*)(&this->nume), sizeof(string));
		f.write((char*)(&this->cantitate), sizeof(float));
		f.write((char*)(this->rezistenta), sizeof(float));
		f.write((char*)(this->reciclabil), sizeof(bool));
	}

	void citesteMaterialBinar(fstream& f) {
		int lungimeNume;
		f.read((char*)(&lungimeNume), sizeof(int));

		char* bufferNume = new char[lungimeNume + 1];
		f.read(bufferNume, lungimeNume);
		bufferNume[lungimeNume] = '\0';
		this->nume = bufferNume;
		delete[] bufferNume;
		f.read((char*)(&this->cantitate), sizeof(float));
		f.read((char*)(this->rezistenta), sizeof(float));
		f.read((char*)(&this->codInventar), sizeof(int));
		f.read((char*)(this->reciclabil), sizeof(bool));
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

class Intreprindere {
	float cifraAfaceri;

public:
	virtual void descrieIntreprindere() = 0;

	Intreprindere() {
		this->cifraAfaceri = 10000;
	}

	Intreprindere(float cif) {
		this->cifraAfaceri = cif;
	}

	float getCifraAfaceri() {
		return this->cifraAfaceri;
	}

	void setCifraAfaceri(float cif) {
		this->cifraAfaceri = cif;
	}
};

class FirmaConstructii: public Intreprindere {
private:
	string nume;
	int nrAngajati;
	int nrUtilaje;
	const int anInfiintare;
	vector<Utilaj> utilaje;
	vector<Muncitor> muncitori;
	
public:

	FirmaConstructii() :anInfiintare(2000) {
		this->nume = "Nedefint";
		this->nrAngajati = 0;
		this->nrUtilaje = 0;
		
	}


	FirmaConstructii(string nume, int nrA, int nrU, const vector<Utilaj> u, const vector<Muncitor> m) :Intreprindere(), anInfiintare(2002) {
		this->nume = nume;
		this->nrAngajati = nrA;
		this->nrUtilaje = nrU;
		this->utilaje = u;
		this->muncitori = m;
	}

	FirmaConstructii(const FirmaConstructii& f):Intreprindere(), anInfiintare(f.anInfiintare) {
		this->nume = f.nume;
		this->nrAngajati = f.nrAngajati;
		this->nrUtilaje = f.nrUtilaje;
		this->utilaje = f.utilaje;
	}

	void descrieIntreprindere() {
		cout << "Intreprinderea " << nume << " a fost infiintata in anul " << anInfiintare << " si are cifra de afaceri " << getCifraAfaceri()<<endl;
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	string getNume() {
		return this->nume;
	}

	int getNrUtilaje() {
		return this->nrUtilaje;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setNrAng(int nrA) {
		this->nrAngajati = nrA;
	}

	void setNrUt(int nrU) {
		this->nrUtilaje = nrU;
	}

	void afisareFirma() {
		cout << "Firma " << nume << " a fost infiintata in anul " << anInfiintare << ", are " << nrAngajati << " angajati si " << nrUtilaje << " utilaje"<<endl;
		if (!utilaje.empty()) {
			cout << "Utilajele firmei sunt:"<<endl;
			for (vector<Utilaj>::iterator it = utilaje.begin(); it != utilaje.end(); it++) {
				Utilaj utilaj = *it;
				utilaj.afisareUtilaj();
			}
		}
		else
			cout << "Firma nu detine utilaje";

		if (!muncitori.empty()) {
			cout << "Angajatii firmei sunt:"<<endl;
			for (vector<Muncitor>::iterator i = muncitori.begin(); i != muncitori.end(); i++) {
				Muncitor muncitor = *i;
				muncitor.afisareMuncitor();
			}
		}
	}

	friend istream& operator>>(istream& is, FirmaConstructii& f) {
		cout << "Numele firmei: ";
		is >> f.nume;
		std::cout << "Numarul de angajati: ";
		is >> f.nrAngajati;
		cout << "Numarul de utilaje: ";
		is >> f.nrUtilaje;

		f.utilaje.clear(); 
		f.utilaje.resize(f.nrUtilaje); 

		f.muncitori.clear();
		f.muncitori.resize(f.nrAngajati);

		for (vector<Utilaj>::iterator it = f.utilaje.begin(); it != f.utilaje.end(); ++it) {
			is >> *it;
		}

		for (vector<Muncitor>::iterator i = f.muncitori.begin(); i != f.muncitori.end(); i++) {
			is >> *i;
		}
		return is;
	}

	friend ostream& operator<<(ostream & os, const FirmaConstructii& f) {
		os << "Nume firma: " << f.nume << endl;
		;
		os << "Numar utilaje: " << f.nrUtilaje << endl;
		os << "Utilaje: " << endl;
		for (vector<Utilaj>::const_iterator it = f.utilaje.begin(); it != f.utilaje.end(); ++it) {
			os << *it;
		}
		
		os << "Numar angajati: " << f.nrAngajati << endl;
		os << "Angajati: " << endl;

		for (vector<Muncitor>::const_iterator i = f.muncitori.begin(); i != f.muncitori.end(); ++i) {
			os << *i;
		}

		return os;
	}

	void scrieFirmaBinar(fstream& f) {
		f.write((char*)(&this->nume), sizeof(string));
		f.write((char*)(&this->nrUtilaje), sizeof(int));
		for (vector<Utilaj>::iterator it = utilaje.begin(); it != utilaje.end(); ++it) {
			f.write((char*)&it, sizeof(Utilaj));
		}
		f.write((char*)(this->nrAngajati), sizeof(int));
		for (vector<Muncitor>::iterator i = muncitori.begin(); i != muncitori.end(); i++) {
			f.write((char*)&i,sizeof(Muncitor));
		}
	}

	void citesteFirmaBinar(fstream& f) {
		f.read((char*)(&this->nume), sizeof(string));
		f.read((char*)(&this->nrUtilaje), sizeof(int));
		for (vector<Utilaj>::iterator it = utilaje.begin(); it != utilaje.end(); ++it) {
			f.read((char*)&it, sizeof(Utilaj));
		}
		f.read((char*)(this->nrAngajati), sizeof(int));
		for (vector<Muncitor>::iterator i = muncitori.begin(); i != muncitori.end(); i++) {
			f.read((char*)&i, sizeof(Muncitor));
		}
	}

	bool operator<(const FirmaConstructii& f){
		return this->nrAngajati < f.nrAngajati;
	}

	bool operator>(const FirmaConstructii& f) {
		return this->nrAngajati > f.nrAngajati;
	}

};

class Excavator :public Utilaj {
private:
	string producator;
	float latimeSina;
	float greutate;
	float latimeCupa;
	int fortaSapare;

public:

	Excavator() :Utilaj() {
		this->producator = "Nedefinit";
		this->latimeSina = 0;
		this->latimeCupa = 0;
		this->fortaSapare = 0;
	}
	
	Excavator(string prod, float lSina, float lCupa, float greutate, int fortaSapare) :Utilaj() {
		
		this->producator = prod;
		this->latimeSina = lSina;
		this->latimeCupa = lCupa;
		this->greutate = greutate;
		this->fortaSapare = fortaSapare;
	}

	Excavator(const Excavator& e) :Utilaj(e) {
		this->producator = e.producator;
		this->latimeSina = e.latimeSina;
		this->latimeCupa = e.latimeCupa;
		this->greutate = e.greutate;
		this->fortaSapare = e.fortaSapare;
	}

	Excavator operator=(const Excavator& e) {
		if (this != &e) {
			Utilaj::operator=(e);
			this->producator = e.producator;
			this->latimeCupa = e.latimeCupa;
			this->latimeSina = e.latimeSina;
			this->greutate = e.greutate;
			this->fortaSapare = e.fortaSapare;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Excavator& excavator) {
		
		out << (Utilaj)excavator;
		out << "Producator: " << excavator.producator << endl;
		out << "Latime sina: " << excavator.latimeSina<<"mm" << endl;
		out << "Greutate: " << excavator.greutate <<"kg" << endl;
		out << "Latime cupa: " << excavator.latimeCupa<<"mm" << endl;
		out << "Forta sapare: " << excavator.fortaSapare<<"kN" << endl;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Excavator& excavator) {
		 
		in >> (Utilaj&)excavator;  
		cout << "Producator: ";
		in >> excavator.producator;
		cout << "Latime sina: ";
		in >> excavator.latimeSina;
		cout << "Greutate: ";
		in >> excavator.greutate;
		cout << "Latime cupa: ";
		in >> excavator.latimeCupa;
		cout << "Forta sapare: ";
		in >> excavator.fortaSapare;

		return in;
	}

	string getProducator() const {
		return producator;
	}

	void setProducator(const string& producator) {
		this->producator = producator;
	}

	float getLatimeSina() const {
		return latimeSina;
	}

	void setLatimeSina(float latimeSina) {
		this->latimeSina = latimeSina;
	}

	float getGreutate() const {
		return greutate;
	}

	void setGreutate(float greutate) {
		this->greutate = greutate;
	}

	float getLatimeCupa() const {
		return latimeCupa;
	}

	void setLatimeCupa(float latimeCupa) {
		this->latimeCupa = latimeCupa;
	}

	int getFortaSapare() const {
		return fortaSapare;
	}

	void setFortaSapare(int fortaSapare) {
		this->fortaSapare = fortaSapare;
	}

};

class Ciment :public Material {
private:
	string tipCiment;

public:

	Ciment() :Material() {
		this->tipCiment = "Nedefinit";
	}

	Ciment(string tip) :Material("Ciment", 100) {
		this->tipCiment = tip;
	}
	
	friend istream& operator>>(istream& is, Ciment& ciment) {
		is >> (Material&)ciment;
		cout << "Tip ciment: ";
		is >> ciment.tipCiment;

		return is;
	}

	friend ostream& operator<<(ostream& os, const Ciment& ciment) {
		os << (Material)ciment;
		os << "Tip ciment: " << ciment.tipCiment << endl;
		
		return os;
	}

	string getTipCiment() {
		return this->tipCiment;
	}

	void setTipCiment(string ciment) {
		this->tipCiment = ciment;
	}
};



void liniute() {
	for (int i = 0; i < 171; i++) {
		cout << "-";
	}
	cout << endl;
}


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

	Utilaj utilaj3(nume, 10, 250, 400, 20, 2003);

	utilaj3.afisareUtilaj();

	utilizeazaUtilaj(utilaj3, 2); //Functia friend a clasei Utilaj

	cout << "UTILAJ 4:" << endl;
	Utilaj utilaj4 = utilaj3; //Apelarea constructorului de copiere

	utilaj4.afisareUtilaj();

	cout << "Utilajul 4 are numele " << utilaj4.getNume() << " a fost fabricat in anul " << utilaj4.getAnFabricatie() << ", are o capacitate de " << utilaj4.getCapacitate()
		<< " metrii cubi, puterea motorului este de " << utilaj4.getPutereMotor() << " CP, nivelul combustibilului este de " << utilaj4.getNivelCombustibil()
		<< " litrii, iar consumul pe ora este de " << utilaj4.getConsumPeOra() << " litrii" << endl;



	Utilaj utilaj5;
	utilaj5.afisareUtilaj();
	utilaj5 = utilaj4;
	utilaj5.afisareUtilaj();

	cout << "Consumul adunat al celor 2 utilaje: " << utilaj3 + utilaj4 << endl;

	if (utilaj2 > utilaj3)
		cout << utilaj2.getNume() << " are o putere si o capacitate mai mare decat " << utilaj3.getNume() << endl;

	if (utilaj3 < utilaj2)
		cout << utilaj3.getNume() << " are o putere si o capacitate mai mica decat " << utilaj2.getNume() << endl;

	cout << "Numarul total de utilaje este: " << Utilaj::getNrTotalUtilaje() << endl;

	/*UTILAJ END*/


	liniute();


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

	Muncitor muncitor3("Adelin Petrisor", 36, exp, 3, 3500.69);

	muncitor3.afisareMuncitor();

	cout << "MUNCITOR 4:" << endl;
	Muncitor muncitor4 = muncitor3;

	muncitor4.setNume("Petronel Mirel");
	bonusMuncitor(muncitor4);

	cout << "Muncitorul " << muncitor4.getNume() << ", cu codul de angajat " << muncitor4.getCodMuncitor() << ", are varsta de " << muncitor4.getVarsta() << " ani, experienta in domeniu de "
		<< *muncitor4.getAniExperienta() << " ani si un salariu de " << muncitor4.getSalariu() << " RON" << endl;

	Muncitor muncitor5 = muncitor4;
	cout << "MUNCITOR 5:" << endl;
	muncitor5 = muncitor3;
	cout << muncitor5;


	cout << "MUNCITOR 6: " << endl;
	Muncitor muncitor6;
	cin >> muncitor6;

	muncitor6++;
	cout << muncitor6.getSalariu() << endl;

	cout << "Numarul total de muncitori este: " << Muncitor::getNrTotalMuncitori() << endl;

	/*MUNCITOR END*/



	liniute();

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

	liniute();

	/*VECTORI*/

	Utilaj vectorUtilaje[3];


	for (int i = 0; i < 3; i++) {
		cout << "Introduceti datele legate de utilajul " << i + 1 << endl;
		cin >> vectorUtilaje[i];
	}


	for (int i = 0; i < 3; i++) {
		cout << vectorUtilaje[i] << endl;
	}

	liniute();

	Muncitor vectorMuncitori[3];

	for (int i = 0; i < 3; i++) {
		cout << "Introduceti datele legate de muncitorul " << i + 1 << endl;
		cin >> vectorMuncitori[i];
	}


	for (int i = 0; i < 3; i++) {
		cout << vectorMuncitori[i] << endl;
	}

	liniute();


	Material vectorMateriale[3];

	for (int i = 0; i < 3; i++) {
		cout << "Introduceti datele legate de materialul " << i + 1 << endl;
		cin >> vectorMateriale[i];
	}


	for (int i = 0; i < 3; i++) {
		cout << vectorMateriale[i] << endl;
	}

	liniute();

	Utilaj matriceUtilaje[2][2];
	int k = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Introduceti datele legate de utilajul " << ++k << endl;
			cin >> matriceUtilaje[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Pe locul de parcare rand " << i + 1 << " coloana " << j + 1<< " este: "<<matriceUtilaje[i][j];
		}
	}

	liniute();

	FirmaConstructii firma("Bouscwitz", 3, 3, { utilaj1,utilaj2,utilaj3 }, { muncitor2,muncitor3,muncitor4 });

	cout << firma;


	//FISIERE TEXT

		//Utilaj
	ifstream finUti("utilaj.in", ios::in);

	Utilaj utilaj;

	finUti >> utilaj;

	ofstream foutUti("utilaj.txt", ios::out);
	foutUti << utilaj1;
	foutUti << utilaj;

	//Muncitor

	ifstream finMun("muncitor.in", ios::in);

	Muncitor muncitor7;

	finMun >> muncitor7;

	ofstream foutMun("muncitor.txt", ios::out);
	foutMun << muncitor2;
	foutMun << muncitor3;
	foutMun << muncitor7;

	//FISIERE BINARE

		//Material
	Material material("Otel", 34);
	fstream fisOut("material.dat", ios::out | ios::binary);
	/*material1.scrieMaterialBinar(fisOut);*/

	fstream fisIn("material.dat", ios::in | ios::binary);
	/*material1.citesteMaterialBinar(fisIn);*/


		//Firma

	FirmaConstructii firma1;

	fstream fileOut("firma.dat", ios::out | ios::binary);
	/*firma1.scrieFirmaBinar(fileOut);*/

	fstream fileIn("firma.dat", ios::in | ios::binary);
	/*firma1.citesteFirmaBinar(fileIn);*/

	fileIn.close();
	fileOut.close();
	fisOut.close();
	fisIn.close();
	finUti.close();
	foutUti.close();
	finMun.close();
	foutMun.close();

	liniute();

	//EXCAVATOR
	Excavator excavator1("CAT", 500, 990, 13500, 97);

	cout << excavator1 << endl << "producator: " << excavator1.getProducator() << " greutate: " << excavator1.getGreutate() << endl;

	excavator1.setGreutate(13000);

	cout << "Noua greutate: " << excavator1.getGreutate() << endl;

	Excavator excavator2;

	cin >> excavator2;
	cout << excavator2;

	Utilaj* uti = &excavator1;
	//Upcasting
	uti->afisareUtilaj();


	liniute();

	//CIMENT

	Ciment ciment1("CEM I 42.5R");

	cout << ciment1;

	ciment1.setTipCiment("CEM II/B-S 32.5R");

	cout << ciment1;

	Material* mat = &ciment1;
	//Upcasting
	mat->afisareMaterial();

	//CLASE ABSTRACTE

	vector<Persoana*> vectorPersoane;

	for (int i = 0; i < 5; i++) {
		vectorPersoane.push_back(new Muncitor());
	}

	for (vector<Persoana*>::iterator it = vectorPersoane.begin(); it != vectorPersoane.end(); ++it) {
		(*it)->descriePersoana();
	}

	vector<Intreprindere*> vectorIntreprindere;

	for (int i = 0; i < 5; i++) {
		vectorIntreprindere.push_back(new FirmaConstructii());
	}

	for (vector<Intreprindere*>::iterator it = vectorIntreprindere.begin(); it != vectorIntreprindere.end(); ++it) {
		(*it)->descrieIntreprindere();
	}

}