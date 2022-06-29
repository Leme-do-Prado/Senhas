#include <iostream>
using namespace std;

#define MAX 30

struct Fila {
	float nos[MAX+1];
	int ini;
	int fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	int ret;
	if (i == MAX) {
		ret = 0;
	}
	else {
		ret = i + 1;
	}
	return ret;
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(Fila *f) {
	int i = f->ini;
	cout << "---------" << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
    cout << "---------" << endl;
}

int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
        f->fim = incrementa(f->fim);

	}
	return podeEnfileirar;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

void freeFila(Fila *f) {
	free(f);
}

int main(int argc, char** argv){
	int opt, senha = 0, senhaexibida;
	bool bin = false;
	Fila *senhasGeradas;
	senhasGeradas = init();
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	
	cout << "0. Sair\n1. Gerar senha\n2. Realizar atendimento";
	
	
	while(bin == false){
			cout << count(senhasAtendidas)
			cin >> opt;
			switch(opt){
		case 0:
		cout << "Fim do programa. Obrigado!" << endl;
		freeFila(senhasAtendidas);
		bin = true;
		
		break;
		case 1:
		incrementa(senha);
		enqueue(senhasGeradas, senha);
		
		break;
		case 2:
		senhaexibida = senhasGeradas->ini;
		dequeue(senhasGeradas->ini);
		cout << senhaexibida;
		enqueue(senhasAtendidas, senhaexibida);
		if(isEmpty(senhasGeradas)==true){
			count(senhasAtendidas);
			opt = 0;
		} 
		
		break;
	}
	}

	
}
