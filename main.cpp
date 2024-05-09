#include <iostream>
#include <string>
#include <string.h>
#include <cmath>

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

void lerPacientes (struct Pacientes dbPacientes[], int &numPacientes, struct Cidades dbCidades[], int numCidades);
void incluirPacientes(struct Pacientes dbPacientes[], int &numPacientes, struct Pacientes T[], int contT);

int main() {
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
        {45469778835, 1, "Pedro Lucas", "Av. Rui Barbosa"},
        {45241445312, 2, "Lucas Cardoso", "R. Paraná"}
    };

    // lerCidade(dbCidades);
    // lerEspecialidade(dbEspecialidades);
    // lerCID(dbCID);
    // lerMedicamentos(dbMedicamentos);

    lerMedicos(dbMedicos, numMedicos, dbEspecialidades, numEspecialidades, dbCidades, numCidades);

    lerPacientes(dbPacientes, numPacientes, dbCidades, numCidades);

    return 0;
}


void home() {
    cout << "=============================================" << endl
         << "========= GERENCIAMENTO DE HOSPITAL =========" << endl
         << "=============================================" << endl << endl << endl;

    cout << "MENU: ";
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
            i = numT;
            conf = ' '; // Resetar o conf para poder ser utilizado outras vezes
            // Confirmação da inclusão
            for (;conf != 'S';) {
                cout << endl << "Confirma a inclusao do(s) medico(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf)  {
                    case 'S':
                        incluirMedicos(dbMedicos, numMedicos, T, contT);
                        break;
                    case 'N':
                        break;
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

void lerPacientes (struct Pacientes dbPacientes[], int &numPacientes, struct Cidades dbCidades[], int numCidades) {
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
            conf = ' ';
            for (;conf != 'S';) {
                cout << endl << "Confirma a inclusao do(s) paciente(s)? (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                switch (conf)  {
                    case 'S':
                        incluirPacientes(dbPacientes, numPacientes, T, contT);
                        break;
                    case 'N':
                        break;
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
}