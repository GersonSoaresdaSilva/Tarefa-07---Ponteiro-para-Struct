/*Faça um programa com menu de três opções (1-ler linha, 2- mostrar e 3- sair), contendo um STRUCT para cadastrar o nome, a idade, o sexo, salário e salarioNovo de pelo menos duas pessoas. Crie um ponteiro para manipular o STRUCT. O programa deverá conter as seguintes sub rotinas abaixo: (use switch case )*/

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int pos = -1;

typedef struct pessoa cad;
struct pessoa
{
  string nome [3];
  int idade   [3];
  char sexo   [3];
  double sal  [3];
  double nsal [3];
};
cad tabCad;
cad *ptrCad = &tabCad;

//minhas subrotinas
string ler_nome ();
int ler_idade   ();
char ler_sexo   ();
double ler_sal  ();
double novo_sal (double *salario);
void novoCad    ();
void listarCad  ();
void controle   ();

int main() {
  setlocale(LC_ALL, "Portuguese");
  controle  ();

  return 0;
}

string ler_nome ()
{
  string nomeCad;
  cin.ignore ();
  cout << "\nDigite o nome.: ";
  getline(cin, nomeCad);
  return nomeCad;
}

int ler_idade   ()
{
  int idadeCad;
  cout << "\nDigite a idade.: ";
  cin  >> idadeCad;
  return idadeCad;
}

char ler_sexo   ()
{
  char sexoCad;
  cout << "\nDigite o sexo (F/M).: ";
  cin  >> sexoCad;
  return sexoCad;
}

double ler_sal  ()
{
  double salCad;
  cout << "\nDigite o salário.: ";
  cin  >> salCad;
  return salCad;
}

double novo_sal (double *salario)
{
  double auxSal;
  auxSal = *salario * (1.1); //cálcula aumento de 10%
  return auxSal;
}

void novoCad    ()
{
  pos ++;
  if (pos >= 3) 
  {
    cout << "\nLimite de dados foi atingido!" << endl;
    system ("sleep 4");
  }
  else 
  {
    string auxNome = ler_nome ();
    ptrCad -> nome  [pos] = auxNome;
    ptrCad -> idade [pos] = ler_idade ();
    ptrCad -> sexo  [pos] = ler_sexo  ();
    ptrCad -> sal   [pos] = ler_sal   ();
    double calcSal = ptrCad -> sal [pos];
    ptrCad -> nsal  [pos] = novo_sal (&calcSal);
    system ("sleep 2");
  }
}

void listarCad  ()
{
  if (pos == -1)
  {
    cout << "\nLista vazia!" << endl;
  }
  else
  {
    cout << "\n***  Lista de Funcionários  ***" << endl;
    for (int i = 0; i <= pos; i++)
    {
      cout << "\npos [" << i << "]" << " Nome.: " << ptrCad -> nome [i] << " Idade.: " << ptrCad -> idade [i] << " Sexo.: " << ptrCad -> sexo [i] << " Salário.: " << ptrCad -> sal [i] << " Novo salário.: " << ptrCad -> nsal [i] << endl;
    }
  }
system ("sleep 4");
}

void controle   ()
{
  int opcMenu;
  while (true)
  {
    system ("clear");
    cout << "\n***  Menu de Controle  ***" << endl;
    cout << "\n1 - Ler \n2 - Listar \n3 - Sair \nOpção.: ";
    cin  >> opcMenu;
    switch (opcMenu)
    {
      case 1: novoCad   (); break;
      case 2: listarCad (); break;
      case 3: exit (0);     break;
      default: cout << "\nError: Opção Inválida! \nTente novamente." << endl; system ("sleep 4"); break;
    }

  }

}