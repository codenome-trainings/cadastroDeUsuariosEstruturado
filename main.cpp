#include <iostream>
#include <vector>
#include <stdio_ext.h>

using namespace std;

typedef struct Usuario {
    string nome;
    string rg;
    string cpf;
    string endereco;
} Usuario;

vector<Usuario> usuarios;

void menu();
void cadastrarUsuario();
void listarUsuarios();
void numeroDeUsuariosCadastrados();
void removerUltimoNumero();

int main() {
    menu();
    return 0;
}

void menu() {

    char escolha = ' ';

    cout << "1. Cadastrar usuário" << endl;
    cout << "2. Exibir usuario(s) cadastrado(s)" << endl;
    cout << "3. Exibir quantidade de usuario(s) cadastrado(s)" << endl;
    cout << "4. Remover o ultimo usuário cadastrado" << endl;
    cout << "5. Sair" << endl;
    cout << "Digite uma opção válida: ";
    cin >> escolha;

    switch (escolha) {
        case '1':
            cadastrarUsuario();
            break;
        case '2':
            listarUsuarios();
            break;
        case '3':
            numeroDeUsuariosCadastrados();
            break;
        case '4':
            removerUltimoNumero();
            break;
        default:
            cout << "Opção inválida! Tente novamente..." << endl;
    }

    __fpurge(stdin);
    cout << "Pressione qualquer tecla para prosseguir..." << endl;
    getchar();
    menu();
}

void removerUltimoNumero() {
    usuarios.erase(usuarios.end());
    cout << "Usuário removido com sucesso!" << endl;
}

void numeroDeUsuariosCadastrados() {
    cout << "Número de usuários cadastrados: " << usuarios.size() << endl;
}

void listarUsuarios() {
    for (int i = 0; i < usuarios.size(); ++i) {
        cout << "Nome: " << usuarios[i].nome << endl;
        cout << "RG: " << usuarios[i].rg << endl;
        cout << "CPF: " << usuarios[i].cpf << endl;
        cout << "Endereço: " << usuarios[i].endereco << endl;
        cout << "---" << endl << endl;
    }
}

void cadastrarUsuario() {

    Usuario *usuario;

    if(usuarios.size() > 0) usuario = (Usuario *) realloc(usuario, usuarios.size() * sizeof(Usuario));
    else usuario = (Usuario *) malloc(sizeof(Usuario));

    if(!usuario) {
        cout << "Exaustão de memória!" << endl;
        exit(1);
    }

    __fpurge(stdin);
    cout << "Digite seu nome: ";
    getline(cin, usuario->nome);

    __fpurge(stdin);
    cout << "Digite seu RG: ";
    getline(cin, usuario->rg);

    __fpurge(stdin);
    cout << "Digite seu CPF: ";
    getline(cin, usuario->cpf);

    __fpurge(stdin);
    cout << "Digite seu Endereço: ";
    getline(cin, usuario->endereco);

    usuarios.push_back(*usuario);

}


