#include <iostream>
#include <algorithm> // para std::sort

using namespace std;

struct Item {
    int codigo;
    string nome;
};

int main() {
    Item itens[3] = {
        {3, "Item C"},
        {1, "Item A"},
        {2, "Item B"}
    };

    sort(begin(itens), end(itens), [](const Item& a, const Item& b) {
        return a.codigo < b.codigo;
    });

    // Exibindo o array ordenado
    cout << "Itens ordenados por código em ordem crescente:" << endl;
    for (const auto &item : itens) {
        cout << "Código: " << item.codigo << ", Nome: " << item.nome << endl;
    }

    return 0;
}
