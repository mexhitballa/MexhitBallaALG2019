#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
  

struct nyje
{
	string vlere;
	struct nyje *pas;
};

struct nyje_peme_bin
{
	string vlere;
	struct nyje_peme_bin * majtas;
	struct nyje_peme_bin * djathtas;
};


class fjalor_liste 
{
	private:
		nyje *koka;
		string skedari;
	public:
		fjalor_liste()
		{
			this->koka=NULL;
		}

		nyje* krijo_nyje(string vlera)
		{
			nyje * n = new nyje;
			n->vlere=vlera;
			n->pas=NULL;
			return n;
		}
		
		void set_url(string skedari)
		{
			this->skedari= skedari;
		}
		
		bool radha(string nyja, string fjala)
		{
			return nyja<fjala;
		}
		
		bool te_barabarta(string nyja, string fjala)
		{
			return nyja==fjala;
		}
		
		void afisho()
		{
			nyje * tmp = this->koka;
			while(tmp!=NULL)
			{
				cout<<tmp->vlere<<endl;
				tmp=tmp->pas;
			}
		}
		
		void shto_ne_liste(string fjala)
		{
			if(this->koka==NULL)
			{
				this->koka=new nyje;
				koka->vlere=fjala;
				koka->pas= NULL;
				return;
			}
			
			nyje * n = this->krijo_nyje(fjala);
			nyje * tmp = this->koka;
			if(!radha(koka->vlere,fjala))
			{
				if(!te_barabarta(koka->vlere,fjala))
				{
					n->pas=this->koka;
					this->koka=n;
					return;
				}
			}
			while(tmp->pas!=NULL&&radha(tmp->pas->vlere,fjala))
				tmp=tmp->pas;
			if(tmp->pas==NULL)
				tmp->pas = n;
			else
			{
				if(!te_barabarta(tmp->pas->vlere,fjala))
				{
					n->pas = tmp->pas;
					tmp->pas = n;
				}
			}
		}
		void lexo()
		{
			string fjala;
			ifstream in;
			in.open( this->skedari.c_str() );
				if (!in) 
				{
				    cerr << "Gabim ne hapjen e skedarit: "<<skedari;
				    exit(1);
				}
				while(!in.eof()&&in >> fjala)
					shto_ne_liste(fjala);
			in.close();
		}
};
class fjalor_peme_bin
{
	private:
		nyje_peme_bin *koka;
		string skedari;
	public:
		fjalor_peme_bin()
		{
			this->koka=NULL;
		}
		
		nyje_peme_bin* krijo_nyje(string vlera)
		{
			nyje_peme_bin * n = new nyje_peme_bin;
			n->vlere=vlera;
			n->majtas=NULL;
			n->djathtas=NULL;
			return n;
		}
		
		void set_url(string skedari)
		{
			this->skedari= skedari;
		}
		
		bool radha(string nyja, string fjala)
		{
			return nyja<fjala;
		}
		
		bool te_barabarta(string nyja, string fjala)
		{
			return nyja==fjala;
		}
		
		void afisho(nyje_peme_bin *p)
		{
			if(p!=NULL)
			{
				afisho(p->majtas);
				cout<<p->vlere<<endl;
				afisho(p->djathtas);
			}
		}
		void afisho()
		{
			this->afisho(this->koka);
		}
		
		nyje_peme_bin * shto_ne_peme(nyje_peme_bin *p,string fjala)
		{
			if(p==NULL)
				return krijo_nyje(fjala);

			if(radha(p->vlere,fjala))
				p->djathtas = shto_ne_peme(p->djathtas, fjala);
			else if(!te_barabarta(p->vlere, fjala))
				p->majtas = shto_ne_peme(p->majtas, fjala);
			return p;
		}
		void lexo()
		{
			string fjala;
			ifstream in;
			in.open( this->skedari.c_str() );
				if (!in) 
				{
				    cerr << "Gabim ne hapjen e skedarit: "<<skedari;
				    exit(1);
				}
				while(!in.eof()&&in >> fjala)
					this->koka = shto_ne_peme(this->koka,fjala);
					
			in.close();
		}
};

int main()
{
	clock_t begin,end;
	double elapsed_secs;
	begin = clock();
	fjalor_liste F;
	F.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet100.txt");
	F.lexo();
//	F.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR LISTE: Time of execution: "<<elapsed_secs<<" seconds. [100 fjale]"<<endl;
  	
  	begin = clock();
	fjalor_liste F1;
	F1.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet1000.txt");
	F1.lexo();
//	F1.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR LISTE: Time of execution: "<<elapsed_secs<<" seconds. [1000 fjale]"<<endl;
  	
  	begin = clock();
	fjalor_liste F2;
	F2.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet100000.txt");
	F2.lexo();
//	F2.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR LISTE: Time of execution: "<<elapsed_secs<<" seconds. [100000 fjale]"<<endl;
  	
  	/*LAST ONE TAKES TOO MUCH TIME*/
//  begin = clock();
//	fjalor_liste F3;
//	F3.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet1000000.txt");
//	F3.lexo();
//	F3.afisho();
//	
//	end = clock();
//  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
//  	cout<<endl<<"FJALOR LISTE: Time of execution: "<<elapsed_secs<<" seconds. [1000000 fjale]"<<endl;
  	
  	begin = clock();
	fjalor_peme_bin FPB;

	FPB.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet100.txt");
	FPB.lexo();
//	FPB.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR PEME BINARE: Time of execution: "<<elapsed_secs<<" seconds. [100 fjale]"<<endl;
  	
  	begin = clock();
	fjalor_peme_bin FPB1;

	FPB1.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet1000.txt");
	FPB1.lexo();
//	FPB1.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR PEME BINARE: Time of execution: "<<elapsed_secs<<" seconds. [1000 fjale]"<<endl;
  	
  	
  	begin = clock();
	fjalor_peme_bin FPB2;

	FPB2.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet100000.txt");
	FPB2.lexo();
//	FPB2.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR PEME BINARE: Time of execution: "<<elapsed_secs<<" seconds. [100000 fjale]"<<endl;
  	
  	
  	begin = clock();
	fjalor_peme_bin FPB3;

	FPB3.set_url("C:/Users/Mexhit/Desktop/algoritmike/fjalet1000000.txt");
	FPB3.lexo();
//	FPB3.afisho();
	
	end = clock();
  	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
  	cout<<endl<<"FJALOR PEME BINARE: Time of execution: "<<elapsed_secs<<" seconds. [1000000 fjale]"<<endl;

  	
	return 0;
}
