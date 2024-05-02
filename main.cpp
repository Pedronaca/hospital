#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Cidades {
    int cod_cidade=0;
    char nome[40]="", UF[2]=""; 
};

struct Especialidades {
    int cod_espec=0;
    char descricao[80]="";
};

struct Medicos {
    int cod_med=0, cod_espec=0, cod_cidade=0;
    char nome[40]="", endereco[60]="", tel[15]="";
};

struct Pacientes {
    int CPF=0, cod_cidade=0;
    char nome[40]="", endereco[60]="";
};

struct CID {
    int cod_cid=0;
    char descricao[80]=""; 
};

struct Medicamentos {
    int cod_medic=0, qtd_estoque=0, estoque_min=0, estoque_max=0;
    double preço_un=0.00;
    char descricao[80]=""; 
};

struct Consultas {
    int CPF_paciente=0, cod_med=0, cod_cid=0, cod_medic=0, qtd_medic=0;
    char data[10]="", horario[7]="";
};


void lerCidade (struct Cidades x[]);
void lerEspecialidade (struct Especialidades x[]);
void lerCID (struct CID x[]);
void lerMedicamentos (struct Medicamentos x[]);


int main() {
    Medicos testeMedicos[] = {
        {1, 1, 1, "Bruno", "Rua Jose de Alencar, 590", "18998051620"}, 
        {2, 2, 2, "Joao", "Rua dos Bobos, 0", "17906719018"}
    };
        
    Cidades dbCidades[10];
    Especialidades dbEspecialidades[10];
    CID dbCID[10];
    Medicamentos dbMedicamentos[10];
    Medicos dbMedicos[10];

    lerCidade(dbCidades);
    lerEspecialidade(dbEspecialidades);
    lerCID(dbCID);
    lerMedicamentos(dbMedicamentos);

    return 0;
}


void lerCidade (struct Cidades x[]) {
    char conf;
    cout << endl << "====== CADASTRO DE CIDADES ======" << endl;
    for (int i=0 ; i<i+1 ; i++) {
        cout << "Informe o NOME da cidade:" << endl;
        cin >> x[i].nome;
        cout << "Informe o CODIGO da cidade:" << endl;
        cin >> x[i].cod_cidade;
        cout << "Informe o UF da cidade:" << endl;
        cin >> x[i].UF;
        cout << endl << "Deseja cadastrar mais uma cidade? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            break;
        }
        cout << endl;
    }
}

void lerEspecialidade (struct Especialidades x[]) {
    char conf;
    cout << endl << "====== CADASTRO DE ESPECIALIDADES ======" << endl;
    for (int i=0 ; i<i+1 ; i++) {
        cout << "Informe a DESCRICAO da especialidade:" << endl;
        cin >> x[i].descricao;
        cout << "Informe o CODIGO da especialidade:" << endl;
        cin >> x[i].cod_espec;
        cout << endl << "Deseja cadastrar mais uma especialidade? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            break;
        }
        cout << endl;
    }
}

void lerCID (struct CID x[]) {
    char conf;
    cout << endl << "====== CADASTRO DE CID ======" << endl;
    for (int i=0 ; i<i+1 ; i++) {
        cout << "Informe a DESCRICAO do CID:" << endl;
        cin >> x[i].descricao;
        cout << "Informe o CODIGO do CID:" << endl;
        cin >> x[i].cod_cid;
        cout << endl << "Deseja cadastrar mais um CID? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            break;
        }
        cout << endl;
    }
}

void lerMedicamentos (struct Medicamentos x[]) {
    char conf;
    cout << endl << "====== CADASTRO DE MEDICAMENTOS ======" << endl;
    for (int i=0 ; i<i+1 ; i++) {
        cout << "Informe a DESCRICAO do medicamento:" << endl;
        cin >> x[i].descricao;
        cout << "Informe o CODIGO do medicamento:" << endl;
        cin >> x[i].cod_medic;
        cout << "Informe a QUANTIDADE EM ESTOQUE do medicamento:" << endl;
        cin >> x[i].qtd_estoque;
        cout << "Informe o ESTOQUE MINIMO do medicamento:" << endl;
        cin >> x[i].estoque_min;
        cout << "Informe o ESTOQUE MAXIMO do medicamento:" << endl;
        cin >> x[i].estoque_max;
        cout << "Informe o PRECO UNITARIO do medicamento:" << endl;
        cin >> x[i].preço_un;
        cout << endl << "Deseja cadastrar mais um CID? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            break;
        }
        cout << endl;
    }
}

void incluirMedicos (struct Medicos x[]) {
    char conf;
    cout << endl << "====== CADASTRO DE ESPECIALIDADES ======" << endl;
    for (int i=0 ; i<i+1 ; i++) {
        cout << "Informe o NOME do medico:" << endl;
        cin >> x[i].nome;
        cout << "Informe o CODIGO do medico:" << endl;
        cin >> x[i].cod_med;
        cout << "Informe o CODIGO DA ESPECIALIDADE do medico:" << endl;
        cin >> x[i].cod_espec;
        cout << "Informe o CODIGO DA CIDADE do medico:" << endl;
        cin >> x[i].cod_cidade;
        cout << "Informe o ENDERECO do medico:" << endl;
        cin >> x[i].endereco;
        cout << "Informe o TELEFONE do medico:" << endl;
        cin >> x[i].tel;
        cout << endl << "Deseja cadastrar mais um CID? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            break;
        }
        cout << endl;
    }
}