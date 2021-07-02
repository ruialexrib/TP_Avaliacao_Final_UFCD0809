#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// constantes
#define NR_PRODUTOS 4
#define NR_MOEDAS 6

// assinatura das funcoes utilizadas
void mostrarMenuProdutos(int nrProdutos[], string nomeProdutos[], float precoProdutos[], int quantProdutos);
float pedirSelecao(float precoProdutos[]);
void mostrarMenuPagamento(float total, float moedasTroco[], int nrmoedas);
float recolherPagamento(float total, float moedasTroco[]);
float devolverTroco(float valor, float moedasTroco[]);

// programa principal
int main()
{
	SetConsoleOutputCP(CP_UTF8);

	// declaração de variaveis e inicialização dos arrays 
	int nrProdutos[NR_PRODUTOS] = { 1,2,3,4 };
	string nomeProdutos[NR_PRODUTOS] = { "Café", "Cappuccino", "Chocolate", "Chá" };
	float precoProdutos[NR_PRODUTOS] = { 0.25, 0.30, 0.35, 0.20 };
	float moedasTroco[NR_MOEDAS] = { 0.05 * 100, 0.1 * 100, 0.2 * 100, 0.5 * 100, 1 * 100, 2 * 100 };
	float totalProdutos = 0;
	float totalPago = 0;
	float totalTroco = 0;
	float t = 0;
	int contadorMoedas = 0;

	cout << "\n\t==================================================\n";
	cout << "\n\tTrabalho de Avaliação Final - Exercício 2";
	cout << "\n\t==================================================\n";
	cout << "\n\tUFCD 0809 - Programação em C/C++ - fundamentos";
	cout << "\n\tRui Ribeiro <rui.ribeiro.23842@formandos.cinel.pt>";
	cout << "\n\t==================================================\n";
	cout << "\n\t";
	cout << "\n\tSumário:";
	cout << "\n\t---------------------------------------------------------------------------------------";
	cout << "\n\tEste exercício simula o o funcionamento de uma máquina de vending.";
	cout << "\n\t- Passo 1 - mostra o menu de produtos e aguarda a seleção do utilizador";
	cout << "\n\t- Passo 2 - mostra o menu de pagamento e aguarda a introdução de moedas do utilizador";
	cout << "\n\t- Passo 3 - calcula e distribui o troco de acordo com o menor numero possivel de moedas disponiveis.";
	cout << "\n\n\n\t";
	cout << "\n\tPressione uma tecla para iniciar.";
	cin.get();
	system("cls");

	// mostra menu dos produtos
	mostrarMenuProdutos(nrProdutos, nomeProdutos, precoProdutos, NR_PRODUTOS);

	// regista a selecao dos produtos
	totalProdutos = pedirSelecao(precoProdutos);
	system("cls");

	if (totalProdutos > 0) {

		// mostra menu pagamento
		mostrarMenuPagamento(totalProdutos, moedasTroco, NR_MOEDAS);

		// recolhe moedas do pagamento
		totalPago = recolherPagamento(totalProdutos, moedasTroco);

		system("cls");
		// devolve o troco
		if (totalPago > totalProdutos) {
			cout << "\n\n\t-- Passo 3/3 --\n";
			cout << "\n\tA maquina calcula e distribui o troco ";
			cout << "\n\tde acordo com o menor numero possivel de moedas disponiveis.\n";

			cout << "\n\t--------------------------";
			cout << "\n\tTotal a pagar:\t" << totalProdutos << " €";
			cout << "\n\tTotal pago:\t" << totalPago << " €";
			cout << "\n\t--------------------------";
			printf("\n\tTroco:\t\t%.2f €", (float) totalPago - totalProdutos);
			cout << "\n\t--------------------------";

			cout << "\n\n\n\tTroco devolvido:";
			cout << "\n\t------------------------------------\n";
			do
			{
				contadorMoedas++;
				t = devolverTroco(((totalPago * 100) - (totalProdutos * 100) - totalTroco), moedasTroco);
				totalTroco = totalTroco + t;
			} while ((totalPago * 100) - (totalProdutos * 100) - totalTroco > 0);
			cout << "\n\n\t(" << contadorMoedas << " moedas devolvidas)";
		}
	}
	else {
		cout << "\n\n\tNão efetuaou nenhuma seleção.\n";
	}
	cout << "\n\n\n\n\tPrograma terminado.\n";
	system("pause");
}

/// <summary>
/// mostra o menu de produtos
/// </summary>
/// <param name="nrProdutos">array com o nr dos produtos</param>
/// <param name="nomeProdutos">array com o nome dos produtos</param>
/// <param name="precoProdutos">array com o preço dos produtos</param>
/// <param name="quantProdutos">quantidade de produtos</param>
void mostrarMenuProdutos(int nrProdutos[], string nomeProdutos[], float precoProdutos[], int quantProdutos) {

	cout << "\n\t-- Passo 1/3 --\n\n\tOs seguintes produtos estão disponiveis para seleção:";
	cout << "\n\tIndique um produto de cada vez.";
	cout << "\n\tTermine e pague, indicando a opção 9.\n";
	cout << "\n\t------------------------------------";
	cout << "\n\tNr Produto\tPreço\tProduto";
	cout << "\n\t------------------------------------";
	for (int i = 0; i < quantProdutos; i++)
	{
		cout << "\n\t" << nrProdutos[i] << "\t\t" << "€ " << precoProdutos[i] << "\t" << nomeProdutos[i];
	}
	cout << "\n\t------------------------------------";
	cout << "\n\t" << 9 << "\t\t" << "Terminar e pagar";
	cout << "\n\t------------------------------------";
}

/// <summary>
/// mostra o menu de pagamento
/// </summary>
/// <param name="total">total a pagar</param>
/// <param name="moedasTroco">array com as moedas disponiveis para pagar</param>
/// <param name="nrmoedas">numeros de moedas</param>
void mostrarMenuPagamento(float total, float moedasTroco[], int nrmoedas) {
	cout << "\n\t-- Passo 2/3 --\n\n\tTotal a pagar:\t" << total << " €";
	cout << "\n\tIntroduza as seguintes moedas para efetuar o pagamento:";
	cout << "\n\tIntroduza uma moeda de cada vez até atingir o total a pagar.";
	cout << "\n\tSe exceder o valor a pagar a maquina devolve o troco de acordo com o menor numero possivel de moedas disponiveis.";
	cout << "\n\t------------------------------------";
	cout << "\n\tNr Moeda\tValor";
	cout << "\n\t------------------------------------";
	for (int i = 0; i < nrmoedas; i++)
	{
		cout << "\n\t" << i + 1 << "\t\t" << "€ " << moedasTroco[i] / 100;
	}
	cout << "\n\t------------------------------------";
}

/// <summary>
/// recolhe o pagamento
/// </summary>
/// <param name="total">total a pagar</param>
/// <param name="moedasTroco">rray com as moedas disponiveis para pagar</param>
/// <returns>devolve o valor pago</returns>
float recolherPagamento(float total, float moedasTroco[]) {
	int nrmoeda = 0;
	bool terminaRecolha;
	float totalPagamento = 0;
	bool troco;

	do
	{
		terminaRecolha = false;

		// pede e valida o nr moeda
		do
		{
			cout << "\n\n\tIntroduza o Nr.Moeda:\t";
			if (cin >> nrmoeda) {
				if (nrmoeda == 1 || nrmoeda == 2 || nrmoeda == 3 || nrmoeda == 4 || nrmoeda == 5 || nrmoeda == 6) {
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

		// adiciona ao total do pagamento
		totalPagamento = totalPagamento + moedasTroco[nrmoeda - 1] / 100;

		cout << "\n\t--------------------------";
		cout << "\n\tTotal a pagar:\t" << total << " €";
		cout << "\n\tTotal pago:\t" << totalPagamento << " €";
		cout << "\n\t--------------------------";

		// verifica se a recolha de moedas deve terminar (se o total pago é igual ou superior ao total a pagar)
		terminaRecolha = totalPagamento >= total;

	} while (!terminaRecolha);

	return totalPagamento;
}

/// <summary>
/// regista a selecao de produtos
/// </summary>
/// <param name="precoProdutos">array comn o preco dos produtos</param>
/// <returns>devolve o total dos produtos selecionados, valor a pagar</returns>
float pedirSelecao(float precoProdutos[]) {
	int nrproduto = 0;
	bool terminaSelecao;
	float totalProdutos = 0;
	int contadorProdutos = 0;

	do
	{
		terminaSelecao = false;

		// pede e valida nr produto
		do
		{
			cout << "\n\n\tIntroduza o Nr.Produto:\t";
			if (cin >> nrproduto) {
				if (nrproduto == 1 || nrproduto == 2 || nrproduto == 3 || nrproduto == 4 || nrproduto == 9) {
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

		// verifica se a selecao de produtos deve terminar (opção 9)
		terminaSelecao = nrproduto == 9;

		if (!terminaSelecao) {
			// adiciona ao total de produtos
			totalProdutos = totalProdutos + precoProdutos[nrproduto - 1];
			contadorProdutos++;

			cout << "\n\t------------------------------------";
			cout << "\n\tTotal Selecionado:\t" << totalProdutos << " (" << contadorProdutos << " produtos)";
			cout << "\n\t------------------------------------";
		}
	} while (!terminaSelecao);

	return totalProdutos;

}

/// <summary>
/// devolve o troco
/// </summary>
/// <param name="valor">valor remanescente</param>
/// <param name="moedasTroco">array com as moedas de troco</param>
/// <returns>a moeda mais alta que corresponde ao troco que ainda falta devolver</returns>
float devolverTroco(float valor, float moedasTroco[]) {
	for (int i = NR_MOEDAS - 1; i >= 0; i--)
	{
		if (moedasTroco[i] <= valor) {
			cout << "\t" << moedasTroco[i] / 100 << " €";
			return moedasTroco[i];
		}
	}
}



