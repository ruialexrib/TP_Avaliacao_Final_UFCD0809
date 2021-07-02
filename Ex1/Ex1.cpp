#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

// constante com o numero de canais
#define NR_CANAIS 4

// assinatura das funcoes utilizadas
int lerQuantasCasasPesquisar();
void pesquisarAudiencias(string nomeCanais[], int nrcanais[], int audienciaCanais[], int casasPesquisar);
void mostraResultados(string nomeCanais[], int nrcanais[], int audienciaCanais[], int casasPesquisar);

// programa principal
int main()
{
	SetConsoleOutputCP(CP_UTF8);

	// declaração de variaveis e inicialização dos arrays 
	int nrcanais[NR_CANAIS] = { 1,2,3,4 };
	string nomeCanais[NR_CANAIS] = { "RTP1", "RTP2", "SIC", "TVI" };
	int audienciaCanais[NR_CANAIS] = { };

	int casasPesquisar = 0;

	cout << "\n\t==================================================\n";
	cout << "\n\tTrabalho de Avaliação Final - Exercício 1";
	cout << "\n\t==================================================\n";
	cout << "\n\tUFCD 0809 - Programação em C/C++ - fundamentos";
	cout << "\n\tRui Ribeiro <rui.ribeiro.23842@formandos.cinel.pt>";
	cout << "\n\t==================================================\n";
	cout << "\n\t";
	cout << "\n\tSumário:";
	cout << "\n\t---------------------------------------------------------------------------------------";
	cout << "\n\tEste exercício simula o calculo de audiências para os 4 canais de televisão.";
	cout << "\n\t- Passo 1 - lê quantas casas deverão fazer parte da pesquisa";
	cout << "\n\t- Passo 2 - efetua pesquisa de audiencias pedindo o canal e o numero de pessoas que assistiram";
	cout << "\n\t- Passo 3 - mostra os resultados finais";
	cout << "\n\n\n\t";
	cout << "\n\tPressione uma tecla para iniciar.";
	cin.get();
	system("cls");

	// lê quantas casas deverão fazer parte da pesquisa
	casasPesquisar = lerQuantasCasasPesquisar();

	// efetua pesquisa de audiencias
	pesquisarAudiencias(nomeCanais, nrcanais, audienciaCanais, casasPesquisar);

	// mostra os resultados da audiencia
	mostraResultados(nomeCanais, nrcanais, audienciaCanais, casasPesquisar);

	cout << "\n\n\n\n\tPrograma terminado.\n";
	system("pause");
}


/// <summary>
/// pede ao utilizador quantas casas serão alvo da pesquisa de audiencias
/// </summary>
/// <returns>devolve inteiro com o numero de casas a pesquisar</returns>
int lerQuantasCasasPesquisar() {
	int casasPesquisar;
	do
	{
		cout << "\n\t-- Passo 1/3 --\n\n\tQuantas casas serão alvo da pesquisa de audiencias ?\t";
		if (cin >> casasPesquisar) {
			break;
		}
		else {
			cout << "\n\tErro. Numero inválido\t";
		}
	} while (true);
	return casasPesquisar;
}


/// <summary>
/// efetua a pesquisa de audiencias
/// perguntando ao utilizador qual o canal e o numero de pessoas que assistiram a esse canal
/// </summary>
/// <param name="nomeCanais">array com os nomes dos canais</param>
/// <param name="nrcanais">array com os numeros dos canais</param>
/// <param name="audienciaCanais">array com os contadores de pessoas que assistiram cada canal</param>
/// <param name="casasPesquisar">quantas casas deverão fazer parte da pesquisa</param>
void pesquisarAudiencias(string nomeCanais[], int nrcanais[], int audienciaCanais[], int casasPesquisar) {
	int nrcanal = 0;
	int pessoasAssistir = 0;
	bool terminaCasa;

	for (int i = 0; i < casasPesquisar; i++)
	{
		system("cls");
		cout << "\n\t-- Passo 2/3 --\n\n\tPesquisa de Audiência:\n\tCasa Nr [" << i + 1 << "/" << casasPesquisar << "]" << endl;
		cout << "\n\tTermine a recolha nesta casa, indicando a opção 9.\n";
		cout << "\n\t-------------------------------";
		cout << "\n\tNr Canal\tNome do Canal";
		cout << "\n\t-------------------------------";
		for (int j = 0; j < NR_CANAIS; j++)
		{
			cout << "\n\t" << nrcanais[j] << "\t\t" << nomeCanais[j];
		}
		cout << "\n\t-------------------------------";
		cout << "\n\t" << 9 << "\t\t" << "Terminar casa";
		cout << "\n\t-------------------------------";

		do
		{
			terminaCasa = false;

			// pede e valida o nr do canal
			do
			{
				cout << "\n\n\tIntroduza o Nr.Canal:\t";
				if (cin >> nrcanal) {
					if (nrcanal == 1 || nrcanal == 2 || nrcanal == 3 || nrcanal == 4 || nrcanal == 9) {
						break;
					}
					else {
						cout << "\n\tErro. Opção inválida\t";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
				else {
					cout << "\n\tErro. Numero inválido\t";
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (true);

			// verifica se a pesquisa de canais nesta casa deverá terminar (opção 9)
			terminaCasa = nrcanal == 9;

			if (!terminaCasa) {
				// pede e valida o numero de pessoas
				do
				{
					cout << "\n\tIntroduza a quantidade de pessoas que assistiram o canal [" << nomeCanais[nrcanal - 1] << "]:\t";
					if (cin >> pessoasAssistir) {
						break;
					}
					else {
						cout << "\n\tErro. Numero inválido\t";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				} while (true);

				// adiciona ao contador de audiencia dos canais
				audienciaCanais[nrcanal - 1] = audienciaCanais[nrcanal - 1] + pessoasAssistir;
				cout << "\n\t-------------------------------";
			}

		} while (!terminaCasa);
	}
}

/// <summary>
/// mostra os resultados das audiencias nas diferentes casas
/// </summary>
/// <param name="nomeCanais">array com os nomes dos canais</param>
/// <param name="nrcanais">array com os numeros dos canais</param>
/// <param name="audienciaCanais">array com os contadores de pessoas que assistiram cada canal</param>
/// <param name="casasPesquisar">quantas casas deverão fazer parte da pesquisa</param>
void mostraResultados(string nomeCanais[], int nrcanais[], int audienciaCanais[], int casasPesquisar) {
	int soma = 0;
	system("cls");

	// configura o cout para aceitar 2 casas decimais fixo
	cout << fixed;
	cout << setprecision(2);

	cout << "\n\t-- Passo 3/3 --\n\n\tResultados da pesquisa de audiência";
	cout << "\n\t--------------------------------------------\n";
	cout << "\n\tForam efetuadas pesquisas de audiencias em " << casasPesquisar << " casas.\n";
	cout << "\n\tAs percentagens de audiencias são:\n";
	// calcula a soma
	for (int i = 0; i < NR_CANAIS; i++)
	{
		soma = soma + audienciaCanais[i];
	}
	// mostra os resultados e percentagens
	cout << "\n\t--------------------------------------------";
	cout << "\n\tNr Canal\tNome do Canal\tAudiências (%)";
	cout << "\n\t--------------------------------------------";
	for (int i = 0; i < NR_CANAIS; i++)
	{
		cout << "\n\t" << nrcanais[i] << "\t\t" << nomeCanais[i] << "\t\t" << "(" << audienciaCanais[i] << "/" << soma << ") " << (float)audienciaCanais[i] / soma * 100 << "%";
	}
	cout << "\n\t--------------------------------------------";
}