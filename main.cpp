#include <iostream>
#include <string>
#include <string.h>
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
    int cod_cid;
    string descricao; 
};

struct Medicamentos {
    int cod_medic, qtd_estoque, estoque_min, estoque_max;
    double preco_un;
    string descricao; 
};

struct Consultas {
    int CPF_paciente, cod_med, cod_cid, cod_medic, qtd_medic;
    string data, horario;
};


bool buscaCidade(int codigo, struct Cidades x[], int numCidades);
void lerCidade (struct Cidades x[]);

bool buscaEspecialidade(int codigo, struct Especialidades x[], int numEspecialidades);
void lerEspecialidade (struct Especialidades x[]);

void lerCID (struct CID x[]);
void lerMedicamentos (struct Medicamentos x[]);


void lerMedicos ( struct Medicos dbMedicos[], int &numMedicos, struct Especialidades dbEspecialidades[], int numEspecialidades, struct Cidades dbCidades[], int numCidades); 
void incluirMedicos(struct Medicos dbMedicos[], int &numMedicos, struct Medicos T[], int contT);
void selecionarMedicos(struct Medicos dbMedicos[], int &numMedicos);
void excluirMedicos(struct Medicos dbMedicos[], int &numMedicos, struct Medicos T[], int contT);
void imprimirMedicos(struct Medicos dbMedicos[], int &numMedicos);

void lerPacientes (struct Pacientes dbPacientes[], int &numPacientes, struct Cidades dbCidades[], int numCidades);
void incluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT);
void selecionarPacientes(struct Pacientes dbPacientes[], int &numPacientes);
void excluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT) ;
void imprimirPacientes(struct Pacientes dbPacientes[], int &numPacientes);

int main() {
    int opcao;

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

    CID dbCID[10];

    Medicamentos dbMedicamentos[10];

    int numPacientes = 2;
    Pacientes dbPacientes[40] = {
        {1, 1, "Lucas Cardoso", "R. Parana"},
        {68477679010, 2, "Pedro Lucas", "Av. Rui Barbosa"}
    };


    while (opcao != 0) {
        system("cls");
    
        cout << "============================================================" << endl
             << "==========        GERENCIAMENTO HOSPITALAR        ==========" << endl
             << "============================================================" << endl << endl << endl;

        // cout << endl << numPacientes << endl;

        cout << "MENU: " << endl;
        cout << "(1) - Incluir medico(s)" << endl;
        cout << "(2) - Excluir medico(s)" << endl;
        cout << "(3) - Listar medico(s)" << endl;
        cout << "(4) - Incluir paciente(s)" << endl;
        cout << "(5) - Excluir paciente(s)" << endl;
        cout << "(6) - Listar paciente(s)" << endl;
        cout << endl << "(0) - Sair" << endl << endl;
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

            default:
                break;
        }

    }

    return 0;
}

bool buscaEspecialidade(int codigo, struct Especialidades x[], int numEspecialidades) {
    int i;
    for (i = 0; i < numEspecialidades; i++) {
        if (codigo == x[i].cod_espec) {
            cout << "Especialidade: " << x[i].descricao << endl;
            return true;
        }
    }
    cout << "ESPECIALIDADE NAO ENCONTRADA!" << endl;
    return false;
}

bool buscaCidade(int codigo, struct Cidades x[], int numCidades) {
    int i;
    for (i = 0; i < numCidades; i++) {
        if (codigo == x[i].cod_cidade) {
            cout << "Cidade: " << x[i].nome << " - " << x[i].UF << endl << endl;
            return true;
        }
    }
    cout << "CIDADE NAO ENCONTRADA!" << endl;
    return false;
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
            return;
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
            return;
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
            return;
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
        cin >> x[i].preco_un;
        cout << endl << "Deseja cadastrar mais um CID? (S/N)" << endl;
        cin >> conf;
        conf = toupper(conf);
        if (conf != 'S') {
            return;
        }
        cout << endl;
    }
}

void lerMedicos (
    struct Medicos dbMedicos[],
    int &numMedicos, 
    struct Especialidades dbEspecialidades[], 
    int numEspecialidades,
    struct Cidades dbCidades[],
    int numCidades
) {
    system("cls");
    char conf;
    const int numT = 20;
    int contT=0, codMedico, codEspecialidade, codCidade;

    Medicos T[numT];
    
    // Laço de repetição para inclusão de médico(os)
    for (int i=0 ; i<numT ;) {
        cout << endl << "====== INCLUIR MEDICO ======" << endl;
        bool codValido=false, codEspecialidadeValido=false, codCidadeValido=false; // Reset das variáveis para a próxima execução do 'for'
        
        // Validação de código (existe ou não)
        while (!codValido) {
            cout << endl << "Informe o CODIGO do medico: ";
            cin >> codMedico;
            for (int j=0 ; j<numMedicos ; j++) {
                if (codMedico == dbMedicos[j].cod_med) {
                    j = numMedicos; // Finaliza a contagem do "for"
                    codValido = false;
                    cout << "ESTE CODIGO JA ESTA EM USO!"<< endl;
                } else {
                    codValido = true;
                }
            }
            if (codValido) {
                for (int j=0 ; j<contT ; j++) {
                    if (codMedico == T[j].cod_med) {
                        j = contT;
                        codValido = false;
                        cout << "ESTE CODIGO JA ESTA EM USO!"<< endl;
                    } else {
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
        } else {
            // i = numT;
            // Confirmação da inclusão
            while (true) {
                conf = ' '; // Resetar o conf para poder ser utilizado outras vezes
                cout << endl << "Confirma a inclusao do(s) medico(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf)  {
                    case 'S':
                        incluirMedicos(dbMedicos, numMedicos, T, contT);
                        return;
                    case 'N':
                        return;
                    default:
                        cout << endl << "DIGITE UMA RESPOSTA VALIDA" << endl;
                }
            }
        }
    }
}

void incluirMedicos(struct Medicos dbMedicos[], int &numMedicos, struct Medicos T[], int contT) {
    int x=0, y=0, z=0; // x: cont array atualizado ; y: cont array medicos(DB - seqencial) ; z: cont array transição médicos
    const int numA = 40;
    Medicos A[numA];
    for (; y<numMedicos && z<contT ; x++) { // Ira executar até que um dos contadores fique com mesmo valor dos limites
        if (dbMedicos[y].cod_med < T[z].cod_med) {
            A[x] = dbMedicos[y];
            y++; 
        } else if (dbMedicos[y].cod_med > T[z].cod_med) {
            A[x] = T[z];
            z++;
        }
    }
    // Caso um dos contadores não tenham chegado até o fim, os mesmos entraram em um desses "while"
    while (y < numMedicos){
        A[x] = dbMedicos[y];
        y++;
        x++;
    }
    while (z < contT){
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

void selecionarMedicos(struct Medicos dbMedicos[], int &numMedicos) {
    system("cls");
    
    char conf;
    const int numT = 20;
    Medicos T[numT];
    int contT=0;
    int cod_med;
    
    int i = 0, f = numMedicos;
    int m = (i + f) / 2;

    cout << "Informe o CODIGO do medico: ";
    cin >> cod_med;
    
    for (; f >= i && cod_med != dbMedicos[m].cod_med; m = (i + f) / 2){
        if (cod_med > dbMedicos[m].cod_med) {
            i = m + 1;
        } else {
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
            switch (conf)  {
                case 'S':
                    contT++;
                    excluirMedicos(dbMedicos, numMedicos, T, contT);
                    break;
                case 'N':
                    return;
                default:
                    cout << endl << "DIGITE UMA RESPOSTA VALIDA" << endl;
            }
        }
    } else {
        cout << "Medico nao encontrado";
        getch();
    }
}

void excluirMedicos(struct Medicos dbMedicos[], int &numMedicos, struct Medicos T[], int contT)  {
    int x=0, y=0, z=0; // x: cont array atualizado ; y: cont array sequencial ; z: cont array transição
    const int numA = 40;
    Medicos A[numA];

    for (; z < contT; z++) {
        while (dbMedicos[y].cod_med == T[z].cod_med && y < numMedicos) {
            y++;
        }
        if (y < numMedicos) {
            A[x] = dbMedicos[y];
            x++;
        }
        y++;
    }
    for (int i = 0; i < x; ++i) {
        dbMedicos[i] = A[i];
    }

    numMedicos = numMedicos - contT;

    return;
}

void imprimirMedicos(struct Medicos dbMedicos[], int &numMedicos) {
    system("cls");

    cout << endl << "====== LISTA DE MEDICOS ======" << endl;
    for (int i=0 ; i<numMedicos ; i++) {
        cout << endl << "Nome: " << dbMedicos[i].nome << endl
            << "- Codigo: " << dbMedicos[i].cod_med << endl
            << "- Cod. Especialidade: " << dbMedicos[i].cod_espec << endl
            << "- Telefone: " << dbMedicos[i].tel << endl
            << "- Cod. Cidade: " << dbMedicos[i].cod_cidade << endl
            << "- Endereco: " << dbMedicos[i].endereco << endl;
    }

    getch();
}

void lerPacientes (struct Pacientes dbPacientes[], int &numPacientes, struct Cidades dbCidades[], int numCidades) {
    system("cls");
    char conf;
    const int numT = 20;
    int contT=0, codCidade;
    long long int CPF;

    Pacientes T[numT];
    
    for (int i=0 ; i<numT ;) {
        cout << endl << "====== INCLUIR PACIENTE ======" << endl;
        bool CPFValido=false, codCidadeValido=false;
        
        while (!CPFValido) {
            cout << endl << "Informe o CPF do Paciente: ";
            cin >> CPF;
            for (int j=0 ; j<numPacientes ; j++) {
                if (CPF == dbPacientes[j].CPF) {
                    j = numPacientes;
                    CPFValido = false;
                    cout << "ESTE CPF JA ESTA EM USO!"<< endl;
                } else {
                    CPFValido = true;
                }
            }
            if (CPFValido) {
                for (int j=0 ; j<contT ; j++) {
                    if (CPFValido == T[j].CPF) {
                        j = contT;
                        CPFValido = false;
                        cout << "ESTE CPF JA ESTA EM USO!"<< endl;
                    } else {
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
        } else {
            i = numT;
            while (true) {
                conf = ' ';
                cout << endl << "Confirma a inclusao do(s) paciente(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf)  {
                    case 'S':
                        incluirPacientes(dbPacientes, numPacientes, T, contT);
                        return; // Retorna à tela principal após a inclusão
                    case 'N':
                        return; // Retorna à tela principal sem incluir os pacientes
                    default:
                        cout << endl << "DIGITE UMA RESPOSTA VALIDA" << endl;
                }
            }
        }
    }
}

void incluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT) {
    int x=0, y=0, z=0; // x: cont array atualizado ; y: cont array sequencial ; z: cont array transição
    const int numA = 40;
    Pacientes A[numA];
    for (; y<numPacientes && z<contT ; x++) { // Ira executar até que um dos contadores fique com mesmo valor dos limites
        if (dbPacientes[y].CPF < T[z].CPF) {
            A[x] = dbPacientes[y];
            y++; 
        } else if (dbPacientes[y].CPF > T[z].CPF) {
            A[x] = T[z];
            z++;
        }
    }
    while (y < numPacientes){
        A[x] = dbPacientes[y];
        y++;
        x++;
    }
    while (z < contT){
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

void selecionarPacientes(struct Pacientes dbPacientes[], int &numPacientes) {
    system("cls");
    
    char conf;
    const int numT = 20;
    Pacientes T[numT];
    int contT=0;
    long long int CPF;
    
    int i = 0, f = numPacientes;
    int m = (i + f) / 2;

    cout << "Informe o CPF do paciente: ";
    cin >> CPF;
    
    for (; f >= i && CPF != dbPacientes[m].CPF; m = (i + f) / 2){
        if (CPF > dbPacientes[m].CPF) {
            i = m + 1;
        } else {
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
            switch (conf)  {
                case 'S':
                    contT++;
                    excluirPacientes(dbPacientes, numPacientes, T, contT);
                    break;
                case 'N':
                    return;
                default:
                    cout << endl << "DIGITE UMA RESPOSTA VALIDA" << endl;
            }
        }
    } else {
        cout << "Paciente nao encontrado";
        getch();
    }
}

void excluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT)  {
    int x=0, y=0, z=0; // x: cont array atualizado ; y: cont array sequencial ; z: cont array transição
    const int numA = 40;
    Pacientes A[numA];

    for (; z < contT; z++) {
        while (dbPacientes[y].CPF == T[z].CPF && y < numPacientes) {
            y++;
        }
        if (y < numPacientes) {
            A[x] = dbPacientes[y];
            x++;
        }
        y++;
    }
    for (int i = 0; i < x; ++i) {
        dbPacientes[i] = A[i];
    }

    numPacientes = numPacientes - contT;

    return;
}

void imprimirPacientes(struct Pacientes dbPacientes[], int &numPacientes) {
    system("cls");

    cout << endl << "====== LISTA DE PACIENTES ======" << endl;
    for (int i=0 ; i<numPacientes ; i++) {
        cout << endl << "Nome: " << dbPacientes[i].nome << endl 
            << "- CPF: " << dbPacientes[i].CPF << endl
            << "- Endereco: " << dbPacientes[i].endereco << endl
            << "- Cod. Cidade: " << dbPacientes[i].cod_cidade << endl;
    }

    getch();
}