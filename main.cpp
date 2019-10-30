#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class stiva;
class nod
{
    char info;
    nod* next;
    public:
    nod(char, nod*);
    ~nod();
    friend class stiva;
    friend ostream& operator<<(ostream&, stiva&);
    friend istream& operator>>(istream&, stiva&);
};

class stiva
{
    nod* v;
    public:
    stiva();
    ~stiva();
    void push(char);
    void pop();
    void top();
    void isempty();
    friend ostream& operator<<(ostream&, stiva&);
    friend istream& operator>>(istream&, stiva&);
    stiva& operator-(stiva);
    void invers(char*);
    void citire(int,stiva*&);
};

nod::nod(char a='0',nod*urm=NULL)
{
    this->info=a;
    this->next=urm;
}

nod::~nod()
{
}

stiva::stiva()
{
    this->v=new nod;
    this->v=NULL;
}

stiva::~stiva()
{
    while(this->v!=NULL)
    {nod *temp=this->v;
    this->v=this->v->next;
    delete temp;}
}

void stiva::push(char a)
{
    nod*temp=new nod;
    temp->info=a;
    temp->next=this->v;
    this->v=temp;
}

void stiva::pop()
{
    nod* temp=this->v;
    this->v=this->v->next;
    delete temp;

}

void stiva::top()
{
    if(this->v==NULL)cout<<"Stiva vida";
    else cout<<this->v->info<<endl;
}

void stiva::isempty()
{
    if(v==NULL)
        cout<<"Stiva este vida"<<endl;
    else
        cout<<"Stiva mai are caractere"<<endl;
}

ostream& operator<<(ostream& out, stiva& ob)
{
    while(ob.v!=NULL)
    {nod *temp=ob.v;
    out<<temp->info<<" ";
    ob.v=ob.v->next;
    delete temp;}
    return out;
}

istream& operator>>(istream& in, stiva& ob)
{
    char a;
    in>>a;
    while(a>=97&&a<=122)
    {
        ob.push(a);
        in>>a;
    }
    return in;
}

void stiva::invers(char* a)
{
    for(int i=0;i<strlen(a);i++)
        this->push(a[i]);
    cout<<*this;
}

stiva& stiva::operator-(stiva ob)
{
    stiva* temp=new stiva;
    while(this->v!=NULL&&ob.v!=NULL)
    {if(this->v->info>ob.v->info)
        temp->push(this->v->info);
    else
        temp->push(ob.v->info);
    this->pop();ob.pop();
    }
    return *temp;
}

void stiva::citire(int n,stiva*& s)
{
    stiva*temp=new stiva[n+1];
    for(int i=0;i<n;i++)
        cin>>temp[i];
        s=temp;
}

int main()
{
    char c='a';int a=0;int b;int n=0;
    srand(time(NULL));
    while(c)
    {
        cout<<"Meniu de operare:"<<endl<<"0 - Oprire"<<endl<<"1 - Initializare"<<endl<<"2 - Push"<<endl;
        cout<<"3 - Pop"<<endl<<"4 - Top"<<endl<<"5 - IsEmpty"<<endl<<"6 - Invers"<<endl;
        cout<<"7 - Diferenta"<<endl<<"8 - Citire"<<endl<<"9 - Afisare"<<endl<<"d - Delete"<<endl<<endl;
        cout<<"Optiune: ";cin>>c;cout<<endl;
        switch(c)
        {int x;char p;char*sir;int i,j,k;
        case '0': cout<<"Programul se inchide..."<<a<<"%"<<endl;_sleep(1000);while(a!=100){x=rand()*rand();x=a+x%(100-a+1);a=x;if(a!=b)cout<<"Programul se inchide..."<<a<<"%"<<endl;b=a;_sleep(1000);};c=0;break;
        case '1': stiva *s;cout<<"Numar de stive: ";cin>>n;s= new stiva[n+1];break;
        case '2': if(n==0)cout<<"Nu ai initializat.";else {cout<<"In ce stiva introduc?: ";cin>>i;cout<<"Caracter de introdus: ";cin>>p;s[i].push(p);};break;
        case '3': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Din ce stiva scot?: ";cin>>i;s[i].pop();};break;
        case '4': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva te intereseaza?: ";cin>>i;s[i].top();};break;
        case '5': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva te intereseaza?: ";cin>>i;s[i].isempty();};break;
        case '6': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa folosesc?: ";cin>>i;cout<<"Sirul este: ";sir=new char[20];cin>>sir;s[i].invers(sir);};break;
        case '7': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Intre ce stive sa fac diferenta?: ";cin>>i>>j;cout<<"In ce stiva pun rezultatul?: ";cin>>k;s[k]=s[i]-s[j];cout<<s[k];};break;
        case '8': if(n==0)cout<<"Nu ai initializat.";else {cout<<"In ce stiva citesc?(toate=n+1): ";cin>>i;if(i!=n+1)cin>>s[i];else s->citire(n,s);};break;
        case '9': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa afisez?: ";cin>>i;cout<<s[i];};break;
        case 'd': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa sterg?: ";cin>>i;s[i].~stiva();};break;
        default: cout<<"Nu ai introdus o comanda corecta!"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
