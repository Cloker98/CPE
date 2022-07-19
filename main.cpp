#include <iostream> // Biblioteca que define o espaço de nomes;
#include <string> // Biblioteca que permite o uso de cadeia de caracteres;
#include <cstdlib> // Biblioteca que permine o sorteio das palavras aleatórias;
#include <ctime> // Biblioteca que permine o sorteio das palavras aleatórias;
#include <stdio.h> // Biblioteca que permine o uso do printf;

using namespace std;

// define constantes para desenho da forca
#define CHANCES 6
#define EMPTY_WORD 45
#define PIPE 124
#define UNDERLINE 95
#define LEFT_BAR 47
#define RIGHT_BAR 92
#define CABECA 48

int main(void)
{
 char jogador [8] = "Jogador";
 char palavra[10];
 char letra;
 int palavra_sorteada, i, jogar_novamente;
 int quantidate_letras, erros, acertos;
 bool letra_correta, vencedor;

 string palavras_secretas [] = {"caneta","borracha","caderno","caneca","barbante","celular","pano","luz","panela","filme","televisao","mesa","amor","parede","trabalho","toalha","amnesia","torrada","vestido","lobo"};

 srand(time (NULL)); // Regra para sorteio.

 do {
palavra_sorteada = rand () % 20; // Regra de limite do sorteio.

for(i = 0; i < 10; i++)
{
  palavra[i]= palavras_secretas[palavra_sorteada][i];
}

quantidate_letras = palavras_secretas[palavra_sorteada].length();
erros   = 0;
acertos = 0;
letra_correta;
vencedor = false;
// inicia palavra descoberta como uma lista de "-"
string descoberto = string(quantidate_letras, '-');

while( erros <= CHANCES && acertos <= quantidate_letras ) {
  letra_correta = false;

  system ("cls");

  cout << "J O G O D A F O R C A" << endl;
  cout << "Bem vindo, Jogador! Esta versão só está disponível para um participante por vez. Boa sorte!" << endl << endl << endl;

  cout << "Jogador, insira seu primeiro palpite:" << endl;

  cout << "Voce possui:" << ' ' << CHANCES - erros << ' ' << "chances." << endl;
  cout << "Voce acertou:" << ' ' << acertos << ' ' << "letras" << endl;

  // utiliza codigos ASCII para desenhar forca

  switch (erros){
	case 0:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  break;
	case 1:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  break;
	case 2:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  break;
	case 3:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR << endl;
	  break;
	case 4:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR;
	  cout << ' ' << (char)RIGHT_BAR << endl;
	  break;
	case 5:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR << (char)PIPE << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR;
	  cout << ' ' << (char)RIGHT_BAR << endl;
	  break;
	case 6:
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE;
	  cout << (char)UNDERLINE << endl;
	  cout << ' ' << ' ' << ' ' << (char)PIPE << endl;
	  cout << ' ' << ' ' << ' ' << (char) CABECA << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR << (char)PIPE << (char)RIGHT_BAR << endl;
	  cout << ' ' << ' ' << (char)LEFT_BAR;
	  cout << ' ' << (char)RIGHT_BAR << endl;
	  break;
  }

  cout << descoberto << endl;

  // verifica vitoria ou derrota
  if (acertos >= quantidate_letras) {
	vencedor = true;
	break;
  }else if(erros >= CHANCES) {
	break;
  }

  // ler caractere
  letra = getchar();

  // verifica se é um caractere válido, se não, pega o próximo chute
  if(letra == '\n')
	continue;

  for(i = 0; i < quantidate_letras; i++)
  {
	// verifica se é uma letra correta
	if(palavra[i] == letra) {
	  if(descoberto[i] != letra) {
		descoberto[i] = letra;
		acertos++;
	  }

	  letra_correta = true;
	}
  }

  if(!letra_correta)
	erros++;

}

if( vencedor )
  cout<<"\n\tPARABENS!!!\n Voce ganhou!\n\n";
else
  cout<<"\n\tNão foi dessa vez.\n Palavra correta: " << palavra << "\n\n" << endl;

cout << "Deseja jogar novamente? Se sim, tecle 1, senao, tecle 2!" << endl;
cin >> jogar_novamente;

 }while(jogar_novamente == 1);

 return 0;
}
