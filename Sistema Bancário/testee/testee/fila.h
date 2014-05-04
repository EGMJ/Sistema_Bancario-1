#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename T>
struct TElemento {
    T dado;
    TElemento <T> *prox;
};

template <typename T>
struct TFila {
    TElemento <T> * inicio;
    int qtd;
};

template <typename T>
void InicializaF (TFila<T> &l){
    l.inicio = NULL;
    l.qtd = 0;
}

template <typename T>
void InsereFimF (TFila<T> &l, T m){
    TElemento <T> *novo  = new TElemento <T>;
    novo -> dado = m;
    novo -> prox = NULL;
    if (l.inicio == NULL){
        l.inicio = novo;
    } else {
       TElemento <T> *nav;
       nav  = l.inicio;
       while (nav -> prox != NULL){
            nav = nav -> prox;
       }
       nav -> prox = novo;
    }
    l.qtd++;
    l.inicio->dado.un_tempo--;
}

template <typename T>
void RemoveInicioF (TFila<T> &l){
    if (l.inicio != NULL){
        TElemento <T> *save;
        save = l.inicio;
        l.inicio = save -> prox;
        delete save;
        l.qtd--;
    }
}

#endif // FILA_H_INCLUDED
