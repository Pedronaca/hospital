#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

// Definição de STRUCTS e valores padrões

struct Cidades {
    int cod_cidade;
    string nome, UF;
};

struct Especialidades {
    int cod_espec;
    string descricao;
};

struct Medicos {
    int cod_med, cod_espec, cod_cidade;
    string nome, endereco, tel;
};

struct Pacientes {
    long long int CPF;
    int cod_cidade;
    string nome, endereco;
};

struct CID {
    string cod_cid, descricao;
};

struct Medicamentos {
    int cod_medic, qtd_estoque, estoque_min, estoque_max;
    long double preco_un;
    string descricao;
};

struct Consultas {
    long long int CPF_paciente;
    int cod_med, cod_medic, qtd_medic;
    string cod_cid, data, horario;
};


// CIDADES
bool buscaCidade(int codigo, struct Cidades x[], int numCidades);
void lerCidade(struct Cidades x[], int &numCidades);
void imprimirCidades(struct Cidades x[], int numCidades);

// ESPECIALIDADES
bool buscaEspecialidade(int codigo, struct Especialidades x[], int numEspecialidades);
void lerEspecialidade(struct Especialidades x[], int &numEspecialidades);
void imprimirEspecialides(struct Especialidades x[], int numEspecialidades);

// MEDICAMENTOS
void lerMedicamentos(struct Medicamentos x[], int &numMedicamentos);
bool buscaMedicamento(int cod_medic, struct Medicamentos x[], int numMedicamentos, bool detalhes, string corTexto);
bool consultaQuantidadeMedicamento(int cod_medic, struct Medicamentos x[], int numMedicamentos, int qtd_solicitada, int &indexDbMedicamento);
void imprimirMedicamentos(struct Medicamentos dbMedicamentos[], int numMedicamentos);
void buscaFaltasMedicamentos(struct Medicamentos x[], int numMedicamentos);
int indexMedicamento(int cod_medic, struct Medicamentos dbMedicamentos[], int numMedicamentos);

// CID
void lerCID(struct CID x[], int &numCID);
void imprimirCID(struct CID x[], int numCID);
bool buscaCID(string cod_cid, struct CID x[], int numCID, string corTexto);

// MÉDICOS
void lerMedicos(struct Medicos dbMedicos[], int& numMedicos, struct Especialidades dbEspecialidades[], int numEspecialidades, struct Cidades dbCidades[], int numCidades);
void incluirMedicos(struct Medicos dbMedicos[], int& numMedicos, struct Medicos T[], int contT);
void selecionarMedicos(struct Medicos dbMedicos[], int& numMedicos);
void excluirMedicos(struct Medicos dbMedicos[], int& numMedicos, struct Medicos T[], int contT);
void imprimirMedicos(struct Medicos dbMedicos[], int& numMedicos);
bool buscaDadosMedicos(int cod_med, struct Medicos x[], int numMedicos, struct Especialidades y[], int numEspecialidades, bool detalhes);

// PACIENTES
void lerPacientes(struct Pacientes dbPacientes[], int& numPacientes, struct Cidades dbCidades[], int numCidades);
void incluirPacientes(struct Pacientes dbPacientes[], int& numPacientes, struct Pacientes T[], int contT);
void selecionarPacientes(struct Pacientes dbPacientes[], int& numPacientes);
void excluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT);
void imprimirPacientes(struct Pacientes dbPacientes[], int numPacientes);
bool buscaDadosPacientes(long long int CPF, struct Pacientes x[], int numPacientes, struct Cidades y[], int numCidades);

// CONSULTAS
void agendarConsulta(struct Pacientes dbPacientes[], int numPacientes, struct Cidades dbCidades[], int numCidades, struct Medicos dbMedicos[], int numMedicos, struct Especialidades dbEspecialidades[], int numEspecialidades, struct CID dbCID[], int numCID, struct Medicamentos dbMedicamentos[], int numMedicamentos, struct Consultas dbConsultas[], int &numConsutlas);
void incluirConsulta(struct Consultas dbConsultas[], int &numConsultas, struct Consultas T[], int indexDbMedicamento, struct Medicamentos dbMedicamentos[], int qtd_solicitada);
void imprimirConsultas(struct Consultas dbPaciente[], int numConsultas, struct Medicos dbMedicos[], int numMedicos, struct CID dbCID[], int numCID, struct Medicamentos dbMedicamentos[], int numMedicamentos);


int main() {
    int opcao = 0;

    int numMedicos = 2;
    Medicos dbMedicos[40] = {
        {1, 1, 1, "Bruno", "Rua Jose de Alencar, 590", "18998051620"},
        {2, 2, 2, "Joao", "Rua dos Bobos, 0", "17906719018"}
    };

    int numCidades = 2;
    Cidades dbCidades[40] = {
        {1, "Assis", "SP"},
        {2, "Londrina", "PR"}
    };

    int numEspecialidades = 2;
    Especialidades dbEspecialidades[40] = {
        {1, "Cardiologista"},
        {2, "Neurologista"}
    };

    int numCID = 2;
    CID dbCID[40] = {
        {"Z76.5", "Pessoa fingindo ser doente (simulacao consciente)"},
        {"T30.1", "Queimadura de primeiro grau, parte do corpo nao especificada"}
    };
    
    int numMedicamentos = 2;
    Medicamentos dbMedicamentos[40] = {
        {1, 4, 6, 10, 6.99, "DORFLEX C/10CP 300MG"},
        {2, 10, 1, 10, 24.49, "ANADOR C/24CP 500MG"}
    };

    int numPacientes = 2;
    Pacientes dbPacientes[40] = {
        {1, 1, "Lucas Cardoso", "R. Parana"},
        {68477679010, 2, "Pedro Lucas", "Av. Rui Barbosa"}
    };

    int numConsultas = 1;
    Consultas dbConsultas[40] =  {
        {68477679010, 1, 1, 1, "T30.1", "10/10/2024", "10:30"}
    };

    do {
        system("cls");

        cout << "============================================================" << endl
            << "==========        " << "\033[46m" << "GERENCIAMENTO HOSPITALAR" << "\033[0m" << "        ==========" << endl
            << "============================================================" << endl << endl << endl;

        cout << "MENU: " << endl << endl;
        cout << "(1) - Incluir medico(s)" << endl;
        cout << "(2) - Excluir medico" << endl;
        cout << "(3) - Listar medicos" << endl << endl;

        cout << "(4) - Incluir paciente(s)" << endl;
        cout << "(5) - Excluir paciente" << endl;
        cout << "(6) - Listar pacientes" << endl << endl;

        cout << "(7) - Agendar consulta" << endl;
        cout << "(8) - Listar consultas" << endl << endl;

        cout << "(9) - Cadastrar medicamento(s)" << endl;
        cout << "(10) - Listar medicamentos" << endl << endl;

        cout << "(11) - Cadastrar cidade(s)" << endl;
        cout << "(12) - Listar cidades" << endl << endl;

        cout << "(13) - Cadastras especialidade(s)" << endl;
        cout << "(14) - Listar especialides" << endl << endl;

        cout << "(15) - Cadatrar CID(s)" << endl;
        cout << "(16) - Listar CIDs" << endl << endl;

        cout << "(0) - Sair" << endl << endl;

        cout << "Selecione uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                lerMedicos(dbMedicos, numMedicos, dbEspecialidades, numEspecialidades, dbCidades, numCidades);
                break;

            case 2:
                selecionarMedicos(dbMedicos, numMedicos);
                break;

            case 3:
                imprimirMedicos(dbMedicos, numMedicos);
                break;

            case 4:
                lerPacientes(dbPacientes, numPacientes, dbCidades, numCidades);
                break;

            case 5:
                selecionarPacientes(dbPacientes, numPacientes);
                break;

            case 6:
                imprimirPacientes(dbPacientes, numPacientes);
                break;

            case 7:
                agendarConsulta(dbPacientes, numPacientes, dbCidades, numCidades, dbMedicos, numMedicos, dbEspecialidades, numEspecialidades, dbCID, numCID, dbMedicamentos, numMedicamentos, dbConsultas, numConsultas);
                break;

            case 8:
                imprimirConsultas(dbConsultas, numConsultas, dbMedicos, numMedicos, dbCID, numCID, dbMedicamentos, numMedicamentos);
                break;

            case 9:
                lerMedicamentos(dbMedicamentos, numMedicamentos);
                break;

            case 10:
                imprimirMedicamentos(dbMedicamentos, numMedicamentos);
               break;

            case 11:
                lerCidade(dbCidades, numCidades);
                break;
            
            case 12:
                imprimirCidades(dbCidades, numCidades);
                break;

            case 13:
                lerEspecialidade(dbEspecialidades, numEspecialidades);
                break;
            
            case 14:
                imprimirEspecialides(dbEspecialidades, numEspecialidades);
                break;

            case 15: 
                lerCID(dbCID, numCID);
                break;

            case 16:
                imprimirCID(dbCID, numCID);
                break;

            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}

int indexMedicamento(int cod_medic, struct Medicamentos dbMedicamentos[], int numMedicamentos) {
    int i=0;
    for (; i<numMedicamentos ; i++) {
        if (cod_medic == dbMedicamentos[i].cod_medic) {
            return i;
        }
    }
    return 0;
}

bool buscaEspecialidade(int codigo, struct Especialidades x[], int numEspecialidades) {
    int i;
    for (i = 0; i < numEspecialidades; i++) {
        if (codigo == x[i].cod_espec) {
            cout << "\033[32m" << "Especialidade: " << x[i].descricao << "\033[0m" << endl;
            return true;
        }
    }
    cout << "\033[31m" << "ESPECIALIDADE NAO ENCONTRADA!" << "\033[0m" << endl;
    return false;
}

bool buscaCidade(int codigo, struct Cidades x[], int numCidades) {
    for (int i = 0; i < numCidades; i++) {
        if (codigo == x[i].cod_cidade) {
            cout << "\033[32m" << "Cidade: " << x[i].nome << " - " << x[i].UF << "\033[0m" << endl << endl;
            return true;
        }
    }
    cout << "\033[31m" << "CIDADE NAO ENCONTRADA!" << "\033[0m" << endl;
    return false;
}

bool buscaCID(string cod_cid, struct CID x[], int numCID, string corTexto) {
    for (int i = 0; i < numCID; i++) {
        if (cod_cid == x[i].cod_cid) {
            cout << "\33" << corTexto << "CID: " << x[i].cod_cid << " - " << x[i].descricao << "\33[0m" << endl;
            return true;
        }
    }
    cout << "\033[31m" << "CID NAO ENCONTRADA!" << "\033[0m" << endl;
    return false;
}

bool buscaMedicamento(int cod_medic, struct Medicamentos x[], int numMedicamentos, bool detalhes, string corTexto) {
    for (int i = 0; i < numMedicamentos; i++) {
        if (cod_medic == x[i].cod_medic) {
            cout << "\33" << corTexto << "Medicamento: " << x[i].descricao << " - Quantidade em estoque: " << x[i].qtd_estoque << "\33[0m" << endl;
            if (detalhes) {
                cout << "\33" << corTexto << "Estoque minimo: " << x[i].estoque_min << endl
                    << "Estoque maximo: " << x[i].estoque_max << endl
                    << "Valor unitario: R$" << x[i].preco_un << endl  
                    << "Valor total em estoque: R$" << x[i].qtd_estoque * x[i].preco_un << endl
                    << "Codigo do medicamento: " << x[i].cod_medic << "\33[0m" << endl << endl;
            }

            return true;
        }
    }
    cout << "\033[31m" << "MEDICAMENTO NAO ENCONTRADO!" << "\033[0m" << endl << endl;
    return false;
}

bool consultaQuantidadeMedicamento(int cod_medic, struct Medicamentos x[], int numMedicamentos, int qtd_solicitada, int &indexDbMedicamento) {
    for (int i = 0; i < numMedicamentos; i++) {
        if (cod_medic == x[i].cod_medic ) {
            if (qtd_solicitada > x[i].qtd_estoque) {
                cout << "\033[31m" << "QUANTIDADE SOLICITADA E MAIOR QUE A QUANTIDADE EM ESTOQUE" << "\033[0m" << endl;
                return false;
            } else {
                cout << "\033[32m" << "Quantidade solicitada: " << qtd_solicitada << "\033[0m" << endl << endl;
                indexDbMedicamento = i;
                return true;
            }
        }
    }
    cout << "\033[31m" << "MEDICAMENTO NAO ENCONTRADO!" << "\033[0m" << endl << endl;
    return false;
}

bool buscaDadosPacientes(long long int CPF, struct Pacientes x[], int numPacientes, struct Cidades y[], int numCidades) {
    int i = 0, f = numPacientes;
    int m = (i + f) / 2;
    for (; f >= i && CPF != x[m].CPF; m = (i + f) / 2) {
        if (CPF > x[m].CPF) {
            i = m + 1;
        }
        else {
            f = m - 1;
        }
    }
    if (CPF == x[m].CPF) {
        cout << "\033[32m" << "Codigo do paciente: " << x[m].CPF << "\033[0m" << endl;
        cout << "\033[32m" << "Nome: " << x[m].nome << "\033[0m" << endl;
        buscaCidade(x[m].cod_cidade, y, numCidades);
        return true;
    }
    else {
        cout << "\033[31m" << "PACIENTE NAO ENCONTRADO!" << "\033[0m" << endl << endl;
        return false;
    }
}


bool buscaDadosMedicos(int cod_med, struct Medicos x[], int numMedicos, struct Especialidades y[], int numEspecialidades, bool detalhes) {
    int i = 0, f = numMedicos;
    int m = (i + f) / 2;
    for (; f >= i && cod_med != x[m].cod_med; m = (i + f) / 2) {
        if (cod_med > x[m].cod_med) {
            i = m + 1;
        }
        else {
            f = m - 1;
        }
    }
    if (cod_med == x[m].cod_med) {
        if (detalhes) {
            cout << "\033[32m" << "Codigo do medico: " << x[m].cod_med << "\033[0m" << endl;
            cout << "\033[32m" << "Nome: " << x[m].nome << "\033[0m" << endl;
            buscaEspecialidade(x[m].cod_espec, y, numEspecialidades);
        } else {
            cout << "Medico: " << x[m].nome << endl;
        }
        
        return true;
    }
    else {
        cout << "\033[31m" << "MEDICO NAO ENCONTRADO" << "\033[0m" << endl << endl;
        return false;
    }
}


void lerCidade(struct Cidades x[], int &numCidades) {
    int cod_cidade;
    char conf = ' ';
    bool codValido;

    for (int i=numCidades ; i<40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE CIDADES\033[0m =================" << endl;

        cout << endl << "Informe o NOME da cidade: ";
        cin.ignore();
        getline(cin, x[i].nome);

        while (!codValido) {
            cout << endl << "Informe o CODIGO da cidade: ";
            cin >> cod_cidade;
            if (numCidades != 0) {
                for (int j = 0 ; j < numCidades ; j++) {
                    if (cod_cidade == x[j].cod_cidade) {
                        j = numCidades;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_cidade = cod_cidade; 
                        codValido = true;
                    }
                }
            }
        }

        cout << endl << "Informe o UF da cidade: ";
        cin.ignore();
        getline(cin, x[i].UF);

        numCidades++;

        cout << endl << "Deseja cadastrar mais uma cidade? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
    }
}

void imprimirCidades(struct Cidades x[], int numCidades) {
    system("cls");

    cout << endl << "================= \033[46mLISTA DE CIDADES\033[0m =================" << endl;
    
    for (int i=0 ; i<numCidades ; i++) {
        cout << endl
            << "Nome: " << x[i].nome << endl
            << "- Codigo da cidade: " << x[i].cod_cidade << endl
            << "- UF: " << x[i].UF << endl << endl; 
    }

    getch();
}

void lerEspecialidade(struct Especialidades x[], int &numEspecialidades) {
    int cod_espec;
    char conf = ' ';
    bool codValido;

    for (int i=numEspecialidades ; i <40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE ESPECIALIDADES\033[0m =================" << endl;

        cout << endl << "Informe a DESCRICAO da especialidade: ";
        cin.ignore();
        getline(cin, x[i].descricao);

        while (!codValido) {
            cout << endl << "Informe o CODIGO da especialidade: ";
            cin >> cod_espec;
            if (numEspecialidades != 0) {
                for (int j = 0; j < numEspecialidades ; j++) {
                    if (cod_espec == x[j].cod_espec) {
                        j = numEspecialidades;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_espec = cod_espec;
                        codValido = true;
                    }
                }
            }
        }

        numEspecialidades++;

        cout << endl << "Deseja cadastrar mais uma especialidade? (S/N): ";
        cin >> conf;
        conf = toupper(conf);

        if (conf != 'S') {
            return;
        }
    }
}

void imprimirEspecialides(struct Especialidades x[], int numEspecialidades) {
    system("cls");

    cout << endl << "================= \033[46mLISTA DE ESPECIALIDADES\033[0m =================" << endl;
    
    for (int i=0 ; i<numEspecialidades ; i++) {
        cout << endl
            << "Descricao: " << x[i].descricao << endl
            << "- Codigo da especialide: " << x[i].cod_espec << endl << endl;
    }

    getch();
}


void lerCID(struct CID x[], int &numCID) {
    string cod_cid;
    char conf = ' ';
    bool codValido;
    
    for (int i=numCID ; i<40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE CID\033[0m =================" << endl;

        cout << endl << "Informe a DESCRICAO da CID: ";
        cin.ignore();
        getline(cin, x[i].descricao);

        while (!codValido) {
            cout << endl << "Informe o CODIGO da CID: ";
            cin >> cod_cid;
            if (numCID != 0) {
                for (int j = 0 ; j < numCID ; j++) {
                    if (cod_cid == x[j].cod_cid) {
                        j = numCID;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_cid = cod_cid; 
                        codValido = true;
                    }
                }
            }
        }

        numCID++;

        cout << endl << "Deseja cadastrar mais um CID? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
    }
}

void imprimirCID(struct CID x[], int numCID) {
    system("cls");

    cout << endl << "================= \033[46mLISTA DE CID\033[0m =================" << endl;
    
    for (int i=0 ; i<numCID ; i++) {
        cout << endl
            << "Descricao: " << x[i].descricao << endl
            << "- Codigo da CID : " << x[i].cod_cid << endl << endl;
    }

    getch();
}

void lerMedicamentos(struct Medicamentos x[], int &numMedicamentos) {
    int cod_medic;
    char conf = ' ';
    bool codValido;

    for (int i=numMedicamentos ; i<40 ; i++) {
        system("cls");

        codValido = false;

        cout << endl << "================= \033[46mCADASTRO DE MEDICAMENTOS\033[0m =================" << endl;

        cout << endl << "Informe a DESCRICAO do medicamento: ";
        cin.ignore();
        getline(cin, x[i].descricao);

        while (!codValido) {
            cout << endl << "Informe o CODIGO do medicamento: ";
            cin >> cod_medic;
            if (numMedicamentos != 0) {
                for (int j = 0 ; j < numMedicamentos ; j++) {
                    if (cod_medic == x[j].cod_medic) {
                        j = numMedicamentos;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        x[i].cod_medic = cod_medic; 
                        codValido = true;
                    }
                }
            }
        }

        cout << endl << "Informe a QUANTIDADE EM ESTOQUE do medicamento: ";
        cin >> x[i].qtd_estoque;

        cout << endl << "Informe o ESTOQUE MINIMO do medicamento: ";
        cin >> x[i].estoque_min;

        cout << endl << "Informe o ESTOQUE MAXIMO do medicamento: ";
        cin >> x[i].estoque_max;

        cout << endl << "Informe o PRECO UNITARIO do medicamento: ";
        cin >> x[i].preco_un;

        numMedicamentos++;

        cout << endl << "Deseja cadastrar mais um MEDICAMENTO? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
    }
}

void lerMedicos(
    struct Medicos dbMedicos[],
    int& numMedicos,
    struct Especialidades dbEspecialidades[],
    int numEspecialidades,
    struct Cidades dbCidades[],
    int numCidades
) {
    system("cls");
    char conf;
    const int numT = 20;
    int contT = 0, codMedico, codEspecialidade, codCidade;

    Medicos T[numT];

    // Laço de repetição para inclusão de médico(os)
    for (int i = 0; i < numT;) {
        cout << endl << "================= \033[46mCADASTRO DE MEDICOS\033[0m =================" << endl;
        bool codValido = false, codEspecialidadeValido = false, codCidadeValido = false; // Reset das variáveis para a próxima execução do 'for'

        // Validação de código (existe ou não)
        while (!codValido) {
            cout << endl << "Informe o CODIGO do medico: ";
            cin >> codMedico;
            if (numMedicos != 0) {
                for (int j = 0; j < numMedicos; j++) {
                    if (codMedico == dbMedicos[j].cod_med) {
                        j = numMedicos; // Finaliza a contagem do "for"
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        codValido = true;
                    }
                }
            } else {
                codValido = true;  
            }
            if (codValido) {
                for (int j = 0; j < contT; j++) {
                    if (codMedico == T[j].cod_med) {
                        j = contT;
                        codValido = false;
                        cout << "\033[31m" << "ESTE CODIGO JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        codValido = true;
                    }
                }
                if (codValido) {
                    T[i].cod_med = codMedico;
                }
            }
        }

        cout << endl << "Informe o NOME do medico: ";
        cin.ignore();
        getline(cin, T[i].nome);

        // Validação de código de especialidade (caso não tenha, entrará em loop)
        while (!codEspecialidadeValido) {
            cout << endl << "Informe o CODIGO DA ESPECIALIDADE do medico: ";
            cin >> codEspecialidade;
                if (buscaEspecialidade(codEspecialidade, dbEspecialidades, numEspecialidades)) {
                    T[i].cod_espec = codEspecialidade;
                    codEspecialidadeValido = true;
                }
        }

        while (!codCidadeValido) {
            cout << endl << "Informe o CODIGO DA CIDADE do medico: ";
            cin >> codCidade;
            if (buscaCidade(codCidade, dbCidades, numCidades)) {
                T[i].cod_cidade = codCidade;
                codCidadeValido = true;
            }
        }

        cout << "Informe o ENDERECO do medico: ";
        cin.ignore();
        getline(cin, T[i].endereco);

        cout << endl << "Informe o TELEFONE do medico: ";
        cin.ignore();
        getline(cin, T[i].tel);

        contT++;

        cout << endl << "Deseja cadadstrar mais um medico? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S') {
            i++;
            system("cls");
        }
        else {
            // i = numT;
            // Confirmação da inclusão
            while (true) {
                conf = ' '; // Resetar o conf para poder ser utilizado outras vezes
                cout << endl << "Confirma a inclusao do(s) medico(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf) {
                case 'S':
                    incluirMedicos(dbMedicos, numMedicos, T, contT);
                    return;
                case 'N':
                    return;
                default:
                    cout << endl << "\033[31m" << "DIGITE UMA RESPOSTA VALIDA" << "\033[0m" << endl;
                }
            }
        }
    }
}

void incluirMedicos(struct Medicos dbMedicos[], int& numMedicos, struct Medicos T[], int contT) {
    int x = 0, y = 0, z = 0; // x: cont array atualizado ; y: cont array medicos(DB - seqencial) ; z: cont array transição médicos
    const int numA = 40;
    Medicos A[numA];
    for (; y < numMedicos && z < contT; x++) { // Ira executar até que um dos contadores fique com mesmo valor dos limites
        if (dbMedicos[y].cod_med < T[z].cod_med) {
            A[x] = dbMedicos[y];
            y++;
        }
        else if (dbMedicos[y].cod_med > T[z].cod_med) {
            A[x] = T[z];
            z++;
        }
    }
    // Caso um dos contadores não tenham chegado até o fim, os mesmos entraram em um desses "while"
    while (y < numMedicos) {
        A[x] = dbMedicos[y];
        y++;
        x++;
    }
    while (z < contT) {
        A[x] = T[z];
        z++;
        x++;
    }
    // Atualizar os dados de dbMedicos pelos de A
    for (int i = 0; i < x; ++i) {
        dbMedicos[i] = A[i];
    }

    numMedicos = numMedicos + contT; // Atualiza o número de médicos
}

void selecionarMedicos(struct Medicos dbMedicos[], int& numMedicos) {
    system("cls");

    char conf = ' ';
    const int numT = 1;
    Medicos T[numT];
    int contT = 0;
    int cod_med;

    int i = 0, f = numMedicos;
    int m = (i + f) / 2;

    cout << endl << "================= \033[46mEXCLUIR MEDICO\033[0m =================" << endl << endl;
    cout << "Informe o CODIGO do medico: ";
    cin >> cod_med;

    for (; f >= i && cod_med != dbMedicos[m].cod_med; m = (i + f) / 2) {
        if (cod_med > dbMedicos[m].cod_med) {
            i = m + 1;
        }
        else {
            f = m - 1;
        }
    }
    if (cod_med == dbMedicos[m].cod_med) {
        cout << "Codigo do medico: " << dbMedicos[m].cod_med << endl;
        cout << "Nome: " << dbMedicos[m].nome << endl << endl;
        while (conf != 'S') {
            conf = ' ';
            cout << "Deseja excluir o cadastro de " << dbMedicos[m].nome << " ? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
            switch (conf) {
            case 'S':
                T[0] = dbMedicos[m];
                contT++;
                excluirMedicos(dbMedicos, numMedicos, T, contT);
                break;
            case 'N':
                return;
            default:
                cout << endl << "\033[31m" << "DIGITE UMA RESPOSTA VALIDA" << "\033[0m" << endl;
            }
        }
    }
    else {
        cout << "Medico nao encontrado";
        getch();
    }
}

void excluirMedicos(struct Medicos dbMedicos[], int& numMedicos, struct Medicos T[], int contT) {
    int a = 0, s = 0, t = 0; // a: cont array atualizado ; s: cont array sequencial ; t: cont array transição
    const int numA = 40;
    Medicos A[numA];

    for (; t < contT; s++) {
        if (dbMedicos[s].cod_med != T[t].cod_med) {
            A[a] = dbMedicos[s];
            a++;
        } else {
            t++;
        }
    }
    while (s < numMedicos) {
        A[a] = dbMedicos[s];
        s++;
        a++;
    }

    for (int i = 0; i < a; ++i) {
        dbMedicos[i] = A[i];
    }

    numMedicos = numMedicos - contT;

    return;
}

void imprimirMedicos(struct Medicos dbMedicos[], int& numMedicos) {
    system("cls");

    cout << endl << "================= \033[46mLISTA DE MEDICOS\033[0m =================" << endl;
    cout << endl << "\033[45m" << "Total de medicos: " << numMedicos << "\033[0m" << endl;

    for (int i = 0; i < numMedicos; i++) {
        cout << endl << "Nome: " << dbMedicos[i].nome << endl
            << "- Codigo: " << dbMedicos[i].cod_med << endl
            << "- Cod. Especialidade: " << dbMedicos[i].cod_espec << endl
            << "- Telefone: " << dbMedicos[i].tel << endl
            << "- Cod. Cidade: " << dbMedicos[i].cod_cidade << endl
            << "- Endereco: " << dbMedicos[i].endereco << endl;
    }

    getch();
}

void lerPacientes(struct Pacientes dbPacientes[], int& numPacientes, struct Cidades dbCidades[], int numCidades) {
    system("cls");
    char conf;
    const int numT = 20;
    int contT = 0, codCidade;
    long long int CPF;

    Pacientes T[numT];

    for (int i = 0; i < numT;) {
            cout << endl << "================= \033[46mCADASTRO DE PACIENTES\033[0m =================" << endl;
        bool CPFValido = false, codCidadeValido = false;

        while (!CPFValido) {
            cout << endl << "Informe o CPF do Paciente: ";
            cin >> CPF;
            if (numPacientes != 0) {
                for (int j = 0; j < numPacientes; j++) {
                    if (CPF == dbPacientes[j].CPF) {
                        j = numPacientes;
                        CPFValido = false;
                        cout << "\033[31m" << "ESTE CPF JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        CPFValido = true;
                    }
                }
            } else {
                CPFValido = true;
            }
            if (CPFValido) {
                for (int j = 0; j < contT; j++) {
                    if (CPF == T[j].CPF) {
                        j = contT;
                        CPFValido = false;
                        cout << "\033[31m" << "ESTE CPF JA ESTA EM USO!" << "\033[0m" << endl;
                    }
                    else {
                        CPFValido = true;
                    }
                }
                if (CPFValido) {
                    T[i].CPF = CPF;
                }
            }
        }

        cout << endl << "Informe o NOME do paciente: ";
        cin.ignore();
        getline(cin, T[i].nome);

        while (!codCidadeValido) {
            cout << endl << "Informe o CODIGO DA CIDADE do paciente: ";
            cin >> codCidade;
            if (buscaCidade(codCidade, dbCidades, numCidades)) {
                T[i].cod_cidade = codCidade;
                codCidadeValido = true;
            }
        }

        cout << "Informe o ENDERECO do paciente: ";
        cin.ignore();
        getline(cin, T[i].endereco);

        contT++;

        cout << endl << "Deseja cadadstrar mais um paciente? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S') {
            i++;
            system("cls");
        }
        else {
            i = numT;
            while (true) {
                conf = ' ';
                cout << endl << "Confirma a inclusao do(s) paciente(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf) {
                case 'S':
                    incluirPacientes(dbPacientes, numPacientes, T, contT);
                    return; // Retorna à tela principal após a inclusão
                case 'N':
                    return; // Retorna à tela principal sem incluir os pacientes
                default:
                    cout << endl << "\033[31m" << "DIGITE UMA RESPOSTA VALIDA" << "\033[0m" << endl;
                }
            }
        }
    }
}

void incluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT) {
    int x = 0, y = 0, z = 0; // x: cont array atualizado ; y: cont array sequencial ; z: cont array transição
    const int numA = 40;
    Pacientes A[numA];
    for (; y < numPacientes && z < contT; x++) { // Ira executar até que um dos contadores fique com mesmo valor dos limites
        if (dbPacientes[y].CPF < T[z].CPF) {
            A[x] = dbPacientes[y];
            y++;
        }
        else if (dbPacientes[y].CPF > T[z].CPF) {
            A[x] = T[z];
            z++;
        }
    }
    while (y < numPacientes) {
        A[x] = dbPacientes[y];
        y++;
        x++;
    }
    while (z < contT) {
        A[x] = T[z];
        z++;
        x++;
    }

    for (int i = 0; i < x; ++i) {
        dbPacientes[i] = A[i];
    }

    numPacientes = numPacientes + contT;

    return;
}

void selecionarPacientes(struct Pacientes dbPacientes[], int& numPacientes) {
    system("cls");

    char conf = ' ';
    const int numT = 1;
    Pacientes T[numT];
    int contT = 0;
    long long int CPF;

    int i = 0, f = numPacientes;
    int m = (i + f) / 2;

    cout << endl << "================= \033[46mEXCLUIR MEDICO\033[0m =================" << endl << endl;
    cout << "Informe o CPF do paciente: ";
    cin >> CPF;

    for (; f >= i && CPF != dbPacientes[m].CPF; m = (i + f) / 2) {
        if (CPF > dbPacientes[m].CPF) {
            i = m + 1;
        }
        else {
            f = m - 1;
        }
    }
    if (CPF == dbPacientes[m].CPF) {
        cout << "Codigo do paciente: " << dbPacientes[m].CPF << endl;
        cout << "Nome: " << dbPacientes[m].nome << endl << endl;
        while (conf != 'S') {
            conf = ' ';
            cout << "Deseja excluir o cadastro de " << dbPacientes[m].nome << " ? (S/N): ";
            cin >> conf;
            conf = toupper(conf);
            switch (conf) {
            case 'S':
                T[0] = dbPacientes[m];
                contT++;
                excluirPacientes(dbPacientes, numPacientes, T, contT);
                break;
            case 'N':
                return;
            default:
                cout << endl << "\033[31m" << "DIGITE UMA RESPOSTA VALIDA" << "\033[0m" << endl;
            }
        }
    }
    else {
        cout << "\033[31m" << "PACIENTE NAO ENCONTRADO!" << "\033[0m";
        getch();
    }
}

void excluirPacientes(struct Pacientes dbPacientes[], int& numPacientes, struct Pacientes T[], int contT) {
    int a = 0, s = 0, t = 0; // a: cont array atualizado ; s: cont array sequencial ; t: cont array transição
    const int numA = 40;
    Pacientes A[numA];

    for (; t < contT; s++) {
        if (dbPacientes[s].CPF != T[t].CPF) {
            A[a] = dbPacientes[s];
            a++;
        } else {
            t++;
        }
    }
    while (s < numPacientes) {
        A[a] = dbPacientes[s];
        s++;
        a++;
    }

    for (int i = 0; i < a; ++i) {
        dbPacientes[i] = A[i];
    }

    numPacientes = numPacientes - contT;

    return;
}

void imprimirPacientes(struct Pacientes dbPacientes[], int numPacientes) {
    system("cls");

    cout << endl << "================= \033[46mLISTA DE PACIENTES\033[0m =================" << endl << endl;
    cout << "\033[45m" << "Total de pacientes: " << numPacientes << "\033[0m" << endl;
    
    for (int i = 0; i < numPacientes; i++) {
        cout << endl << "Nome: " << dbPacientes[i].nome << endl
            << "- CPF: " << dbPacientes[i].CPF << endl
            << "- Endereco: " << dbPacientes[i].endereco << endl
            << "- Cod. Cidade: " << dbPacientes[i].cod_cidade << endl;
    }

    getch();
}

void agendarConsulta(
    struct Pacientes dbPacientes[],
    int numPacientes,
    struct Cidades dbCidades[],
    int numCidades,
    struct Medicos dbMedicos[],
    int numMedicos,
    struct Especialidades dbEspecialidades[],
    int numEspecialidades,
    struct CID dbCID[],
    int numCID,
    struct Medicamentos dbMedicamentos[],
    int numMedicamento,
    struct Consultas dbConsultas[],
    int &numConsultas
) {
    system("cls");

    Consultas T[1];
    long long int CPF;
    int cod_med, cod_medic, qtd_solicitada, indexDbMedicamento=0;
    string cod_cid;
    char conf = ' ';
    bool CPFValido=false, codMedValido=false, codCIDValido=false, codMedic=false, qtdSolicitadaValida=false;

    cout << endl << "================= \033[46mAGENDAR CONSULTA\033[0m =================" << endl << endl;

    while (!CPFValido) {
        cout << "Informe o CPF do paciente: ";
        cin >> CPF;
        cout << endl;
        if (buscaDadosPacientes(CPF, dbPacientes, numPacientes, dbCidades, numCidades)) {
            T[0].CPF_paciente = CPF;
            CPFValido = true;
        }
    }

    while (!codMedValido) {
        cout << "Informe o CODIGO DO MEDICO: ";
        cin >> cod_med;
        cout << endl;
        if (buscaDadosMedicos(cod_med, dbMedicos, numMedicos, dbEspecialidades, numEspecialidades, true)) {
            T[0].cod_med = cod_med;
            codMedValido = true;
        }
    }

    while (!codCIDValido) {
        cout << endl << "Informe o CODIGO DA CID: ";
        cin >> cod_cid;
        cout << endl;
        if (buscaCID(cod_cid, dbCID, numCID, "[32m")) {
            T[0].cod_cid = cod_cid;
            codCIDValido = true;
        }
    }

    while (!codMedic) {
        cout << endl << "Informe o CODIGO DO MEDICAMENTO: ";
        cin >> cod_medic;
        cout << endl;
        if (buscaMedicamento(cod_medic, dbMedicamentos, numMedicamento, false, "[32m")) {
            T[0].cod_medic = cod_medic;
            codMedic = true;
        }
    }

    while (!qtdSolicitadaValida) {
        cout << endl << "Informe a QUANTIDADE DO MEDICAMENTO: ";
        cin >> qtd_solicitada;
        cout << endl;
        if (consultaQuantidadeMedicamento(cod_medic, dbMedicamentos, numMedicamento, qtd_solicitada, indexDbMedicamento)) {
            T[0].qtd_medic = qtd_solicitada;
            qtdSolicitadaValida = true;
        }
    }

    cout << "Informe a DATA da consulta: ";
    cin.ignore();
    getline(cin, T[0].data);

    cout << endl << "Informe o HORARIO da consulta: ";
    cin.ignore();
    getline(cin, T[0].horario);

    while (true) {
        conf = ' ';
        cout << endl << "Confirma a inclusao da consulta? (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        switch (conf) {
            case 'S':
                incluirConsulta(dbConsultas, numConsultas, T, indexDbMedicamento, dbMedicamentos, qtd_solicitada);
                return;
            case 'N':
                return;
            default:
                cout << endl << "\033[31m" << "DIGITE UMA RESPOSTA VALIDA" << "\033[0m" << endl;
        }
    }
}

void incluirConsulta(struct Consultas dbConsultas[], int &numConsultas, struct Consultas T[], int indexDbMedicamento, struct Medicamentos dbMedicamentos[], int qtd_solicitada) {
    int x = 0, y = 0, z = 0; // x: cont array atualizado ; y: cont array sequencial ; z: cont array transição
    Consultas A[40];

    for (; y < numConsultas && z < 1; x++) {
        if (dbConsultas[y].CPF_paciente < T[z].CPF_paciente) {
            A[x] = dbConsultas[y];
            y++;
        }
        else if (dbConsultas[y].CPF_paciente > T[z].CPF_paciente) {
            A[x] = T[z];
            z++;
        } else if (dbConsultas[y].CPF_paciente == T[z].CPF_paciente) {
            A[x] = T[z];
            z++;
        }
    }
    while (y < numConsultas) {
        A[x] = dbConsultas[y];
        y++;
        x++;
    }
    while (z < 1) {
        A[x] = T[z];
        z++;
        x++;
    }

    for (int i = 0; i < x; ++i) {
        dbConsultas[i] = A[i];
    }

    numConsultas = numConsultas + 1;
    dbMedicamentos[indexDbMedicamento].qtd_estoque = dbMedicamentos[indexDbMedicamento].qtd_estoque - qtd_solicitada;

    return;
}

void imprimirConsultas(struct Consultas dbPaciente[], int numConsultas, struct Medicos dbMedicos[], int numMedicos, struct CID dbCID[], int numCID, struct Medicamentos dbMedicamentos[], int numMedicamentos) {
    system("cls");
    int numEspecRef=1;
    Especialidades ref[1];
    double totalArecadado=0;

    cout << endl << "================= \033[46mLISTA DE CONSULTAS\033[0m =================" << endl << endl;
    cout << "\033[45m" << "Numero de consultas: " << numConsultas << "\033[0m" << endl;

    for (int i=0 ; i<numConsultas ; i++) {
        totalArecadado = totalArecadado + 100 + (dbMedicamentos[indexMedicamento(dbPaciente[i].cod_medic, dbMedicamentos, numMedicamentos)].preco_un * dbPaciente[i].qtd_medic);
    }

    cout << "\033[42m" << "Total arrecadado: R$" << totalArecadado << "\033[0m" << endl;

    for (int i=0 ; i < numConsultas ; i++) {
        cout << endl << endl << "CPF Paciente: " << dbPaciente[i].CPF_paciente << endl;
        buscaDadosMedicos(dbPaciente[i].cod_med, dbMedicos, numMedicos, ref, numEspecRef, false);
        cout << "Data: " << dbPaciente[i].data << endl;
        cout << "Horario: " << dbPaciente[i].horario << endl;
        buscaCID(dbPaciente[i].cod_cid, dbCID, numCID, "[37m");
        buscaMedicamento(dbPaciente[i].cod_medic, dbMedicamentos, numMedicamentos, false, "[37m");
        cout << "Quantidade solicitada: " << dbPaciente[i].qtd_medic << endl;
        cout << "Valor da consulta: R$" << 100 + (dbMedicamentos[indexMedicamento(dbPaciente[i].cod_medic, dbMedicamentos, numMedicamentos)].preco_un * dbPaciente[i].qtd_medic) << endl;
    }

    getch();
}

void imprimirMedicamentos(struct Medicamentos dbMedicamentos[], int numMedicamentos) {
    system("cls");
    
    int cod_medic;
    bool codMedicValido = false;

    cout << endl << "================= \033[46mLISTA DE MEDICAMENTOS\033[0m =================" << endl << endl;
    cout << "Numero de medicamentos: " << numMedicamentos << endl << endl;
    cout << "\033[45m" << "(CODIGO) - DESCRICAO" << "\033[0m" << endl;

    for (int i = 0; i < numMedicamentos; i++) {
        cout << endl << "(" << dbMedicamentos[i].cod_medic << ") - " << dbMedicamentos[i].descricao << endl;
    }

    cout << endl << "=========================================================" << endl << endl
        << "OPCOES:" << endl << endl
        << "(-1) - Medicamentos ABAIXO do ESTOQUE MINIMO" << endl
        << "(0) - SAIR" << endl << endl;


    while (!codMedicValido) {
        cout << "Informe o CODIGO DO MEDICAMENTO ou a OPCAO desejada: ";
        cin >> cod_medic;

        switch (cod_medic) {
            case -1:
                buscaFaltasMedicamentos(dbMedicamentos, numMedicamentos);
                return;

            case 0:
                return; 

            default:
                cout << endl;
                if (buscaMedicamento(cod_medic, dbMedicamentos, numMedicamentos, true, "[36m")) {
                    codMedicValido = true;
                }
        }
    }

    getch();
}

void buscaFaltasMedicamentos(struct Medicamentos x[], int numMedicamentos) {
    system("cls");

    int qtd_faltas=0, cod_medic=0;
    bool codMedicValido=false;

    cout <<"============= \033[46mLISTA DE MEDICAMENTOS EM FALTA\033[0m =============" << endl << endl;

    for (int i = 0; i < numMedicamentos; i++) {
        if (x[i].qtd_estoque < x[i].estoque_min) {
            cout << "Medicamento: " << "\033[41m" << x[i].descricao << "\033[0m" << " (Codigo: " << x[i].cod_medic << ")" << endl 
                << "Em estoque: " << "\033[31m" << x[i].qtd_estoque << "\033[0m" << endl
                << "Estoque minimo: " << "\033[33m" << x[i].estoque_min << "\033[0m" << endl
                << "Estoque maximo: " << x[i].estoque_max << endl 
                << "Quantidade a ser comprada: " << "\033[36m" << x[i].estoque_max - x[i].qtd_estoque << "\033[0m || Valor de compra: R$" << (x[i].estoque_max - x[i].qtd_estoque) * x[i].preco_un << endl << endl;

            qtd_faltas++;
        }
    }
    if (qtd_faltas != 0) {
        cout << endl << "==========================================================" << endl << endl
            << "OPCOES:" << endl << endl
            << "(0) - SAIR" << endl << endl;

        while (!codMedicValido) {
            cout << "Insira CODIGO do MEDICAMENTO para REPOR ESTOQUE ou a OPCAO desejada: ";
            cin >> cod_medic;

            switch (cod_medic) {
                case 0:
                    return; 

                default:
                    for (int i=0 ; i<numMedicamentos ; i++) {
                        if (cod_medic == x[i].cod_medic) { // Validação se o codigo informado é valido
                            if (x[i].qtd_estoque < x[i].estoque_min) { // Validação se de fato o medicamento possui estoque com falta
                                codMedicValido = true;
                                x[i].qtd_estoque = x[i].qtd_estoque + (x[i].estoque_max - x[i].qtd_estoque);
                            }
                        }
                    }
                    if (codMedicValido) {
                        cout << endl << "\033[32m" << "Estoque do medicamento foi reposto com sucesso!" << "\033[0m";
                        getch();
                        return;
                    } else {
                        cout << endl << "\033[31m" << "CODGIO DO MEDICAMENTO INVALIDO OU OPCAO INVALIDA" << "\033[0m";
                    }
                }
            }
    
    }
    if (qtd_faltas == 0) {
        cout << "\033[36m" << "NAO HA MEDICAMENTOS EM FALTA!" << "\033[0m" << endl << endl;
    }

    getch();
}
