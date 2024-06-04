#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Inclui o cabeçalho <algorithm> para a função sort

using namespace std;

// Definição da classe Roupa para representar uma peça de roupa
class Roupa {
public:
    int id; // Identificador único para o tipo de roupa
    int model; // Identificador único para cada instância da roupa
    string tipo; // Tipo da roupa (camisa, regata, jaqueta, sweater)
    string cor; // Cor da roupa
    string genero; // Gênero da roupa (masculino, feminino, unisex)
    string tamanho; // Tamanho da roupa (PP, P, M, G, GG)
    float preco; // Preço da roupa

    // Construtor da classe Roupa para inicializar os atributos
    Roupa(int i, int m, string tp, string c, string g, string t, float p) : id(i), model(m), tipo(tp), cor(c), genero(g), tamanho(t), preco(p) {}
};

// Função para ordenar as roupas pelo ID do tipo
bool compararPorID(const Roupa& a, const Roupa& b) {
    return a.id < b.id;
}

// Função para adicionar uma nova roupa ao vetor de roupas
void adicionarRoupa(vector<Roupa>& roupas) {
    string tipo, cor, genero, tamanho;
    float preco;

    // Solicita ao usuário para inserir os detalhes da roupa
    cout << "Digite o tipo de roupa (camisa, regata, jaqueta, sweater, casaco, palitó): ";
    cin >> tipo;
    cout << "Digite a cor da roupa: ";
    cin >> cor;
    cout << "Digite o genero da roupa (masculino, feminino, unisex): ";
    cin >> genero;
    cout << "Digite o tamanho da roupa (PP, P, M, G, GG): ";
    cin >> tamanho;
    cout << "Digite o preco da roupa: ";
    cin >> preco;

    // Determina o ID do tipo de roupa com base no tipo inserido pelo usuário
    int id;
    if (tipo == "camisa") {
        id = 1;
    } else if (tipo == "regata") {
        id = 2;
    } else if (tipo == "jaqueta") {
        id = 3;
    } else if (tipo == "sweater") {
        id = 4;
    } else if (tipo == "casaco") {
        id = 5;
    } else if (tipo == "palitó") {
        id = 6;
    } else {
        cout << "Tipo de roupa invalido!" << endl;
        return;
    }

    // Encontra o maior model atual para o tipo específico de roupa
    int model = 1;
    for (const auto& roupa : roupas) {
        if (roupa.id == id && roupa.model >= model) {
            model = roupa.model + 1;
        }
    }

    // Cria uma nova instância de Roupa e a adiciona ao vetor de roupas
    Roupa novaRoupa(id, model, tipo, cor, genero, tamanho, preco);
    roupas.push_back(novaRoupa);

    // Ordena o vetor de roupas após a inserção, com base no ID do tipo
    sort(roupas.begin(), roupas.end(), compararPorID);

    cout << "Roupa adicionada com sucesso!" << endl;
}

// Função para buscar roupas com base no tipo
void buscarPorTipo(vector<Roupa>& roupas, const string& tipo) {
    int id;
    if (tipo == "camisa") {
        id = 1;
    } else if (tipo == "regata") {
        id = 2;
    } else if (tipo == "jaqueta") {
        id = 3;
    } else if (tipo == "sweater") {
        id = 4;
    } else if (tipo == "casaco") {
        id = 5;
    } else if (tipo == "palitó") {
        id = 6;
    } else {
        cout << "Tipo de roupa invalido!" << endl;
        return;
    }

    // Inicializa as variáveis de busca
    int inicio = 0;
    int fim = roupas.size() - 1;
    bool encontrado = false;
    vector<Roupa> roupasEncontradas;

    // Realiza a busca binária no vetor ordenado de roupas
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (roupas[meio].id == id) {
            roupasEncontradas.push_back(roupas[meio]);
            encontrado = true;

            // Continuar para encontrar todas as roupas do mesmo tipo (para trás)
            int pos = meio - 1;
            while (pos >= 0 && roupas[pos].id == id) {
                roupasEncontradas.push_back(roupas[pos]);
                pos--;
            }

            // Continuar para encontrar todas as roupas do mesmo tipo (para frente)
            pos = meio + 1;
            while (pos < roupas.size() && roupas[pos].id == id) {
                roupasEncontradas.push_back(roupas[pos]);
                pos++;
            }

            break;
        } else if (roupas[meio].id < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (!encontrado) {
        cout << "Roupa do tipo " << tipo << " nao encontrada." << endl;
        return;
    }

    // Pergunta ao usuário se deseja ordenar por preço
    char ordenar;
    cout << "Deseja ordenar as roupas por preco? (s/n): ";
    cin >> ordenar;

    if (ordenar == 's' || ordenar == 'S') {
        // Pergunta ao usuário a ordem de ordenação
        char ordem;
        cout << "Ordenar por preco mais baixo ou mais alto? (b/a): ";
        cin >> ordem;

        // Função de comparação para o Insertion Sort
        auto compararPorPreco = [ordem](const Roupa& a, const Roupa& b) {
            return (ordem == 'b' || ordem == 'B') ? a.preco < b.preco : a.preco > b.preco;
        };

        // Função de ordenação Insertion Sort
        for (size_t i = 1; i < roupasEncontradas.size(); ++i) {
            Roupa key = roupasEncontradas[i];
            int j = i - 1;
            while (j >= 0 && compararPorPreco(key, roupasEncontradas[j])) {
                roupasEncontradas[j + 1] = roupasEncontradas[j];
                j--;
            }
            roupasEncontradas[j + 1] = key;
        }
    }

    // Pergunta ao usuário se deseja buscar por gênero dentro do tipo especificado
    char buscarGenero;
    cout << "Deseja filtrar por genero? (s/n): ";
    cin >> buscarGenero;

    if (buscarGenero == 's' || buscarGenero == 'S') {
        string genero;
        cout << "Digite o genero de roupa a ser buscado: ";
        cin >> genero;

        vector<Roupa> roupasFiltradas;
        for (const auto& roupa : roupasEncontradas) {
            if (roupa.genero == genero) {
                roupasFiltradas.push_back(roupa);
            }
        }

        if (!roupasFiltradas.empty()) {
            cout << "Roupa(s) encontrada(s) do genero " << genero << ":" << endl;
            for (const auto& roupa : roupasFiltradas) {
                cout << "Tipo: " << roupa.tipo << ", Cor: " << roupa.cor << ", Genero: " << roupa.genero << ", Tamanho: " << roupa.tamanho << ", Preco: " << roupa.preco << endl;
            }
        } else {
            cout << '\n' << "Nenhuma roupa do genero " << genero << " encontrada." << endl;
        }
    } else {
        // Exibe as roupas encontradas e possivelmente ordenadas
        cout << '\n' << "Roupa(s) encontrada(s):" << '\n' << endl;
        for (const auto& roupa : roupasEncontradas) {
            cout << "Tipo: " << roupa.tipo << ", Cor: " << roupa.cor << ", Genero: " << roupa.genero << ", Tamanho: " << roupa.tamanho << ", Preco: " << roupa.preco << endl;
        }
    }
}

int main() {
    vector<Roupa> roupas = {
        {1, 1, "camisa", "azul", "masculino", "M", 120.34},
        {1, 2, "camisa", "vermelho", "feminino", "P", 88.76},
        {1, 3, "camisa", "preto", "masculino", "G", 65.89},
        {1, 4, "camisa", "branco", "feminino", "PP", 49.23},
        {1, 5, "camisa", "verde", "masculino", "GG", 132.55},
        {2, 1, "regata", "amarelo", "feminino", "M", 98.67},
        {2, 2, "regata", "cinza", "masculino", "P", 34.99},
        {2, 3, "regata", "rosa", "feminino", "G", 78.45},
        {3, 1, "jaqueta", "marrom", "masculino", "PP", 43.67},
        {3, 2, "jaqueta", "roxo", "feminino", "GG", 89.23},
        {4, 1, "sweater", "preto", "unisex", "M", 102.76},
        {4, 2, "sweater", "branco", "unisex", "P", 55.34},
        {4, 3, "sweater", "cinza", "unisex", "G", 110.89},
    };

    // Ordena o vetor de roupas pelo ID do tipo
    sort(roupas.begin(), roupas.end(), compararPorID);

    int opcao;

    do {
        cout << '\n' << "1. Adicionar nova roupa" << endl;
        cout << "2. Buscar por tipo de roupa" << endl;
        cout << "3. Sair" << '\n' << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                adicionarRoupa(roupas);
                break;
            case 2: {
                string tipo;
                cout << "Digite o tipo de roupa a ser buscado: ";
                cin >> tipo;
                cout << '\n';
                buscarPorTipo(roupas, tipo);
                break;
            }
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while(opcao != 3);

    return 0;
}
