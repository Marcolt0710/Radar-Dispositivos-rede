#include <iostream>
using namespace std;

int main() {
    int estado[10];
    int n;
    int ativos = 0;
    int inativos = 0;
    float porcentagem;

    cout << "Quantos dispositivos (1 a 10)? ";
    cin >> n;
    while (n < 1 || n > 10) {
        cout << "Invalido! Digite de 1 a 10: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Dispositivo " << i + 1 << " (1 ativo / 0 inativo): ";
        cin >> estado[i];
        while (estado[i] != 0 && estado[i] != 1) {
            cout << "Invalido! Digite 0 ou 1: ";
            cin >> estado[i];
        }
    }

    cout << "Estados: ";
    for (int i = 0; i < n; i++) {
        cout << estado[i] << " ";
        if (estado[i] == 1) {
            ativos = ativos + 1;
        } else {
            inativos = inativos + 1;
        }
    }
    cout << endl;

    porcentagem = ativos * 100.0 / n;

    cout << "Ativos: " << ativos << endl;
    cout << "Inativos: " << inativos << endl;
    cout << "Disponibilidade: " << porcentagem << "%" << endl;

    if (inativos >= 2) {
        cout << "ALERTA!" << endl;
    } else {
        cout << "Sem alerta" << endl;
    }

    return 0;
}
