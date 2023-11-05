#include <stdlib.h>
#include <stdio.h>

#define TAMWORD 8

typedef struct addr{
	long start;
        long end;
} addr_t;

typedef struct addrv{
  addr_t v[MAXRANGES];
  int numranges;
} addrvet_t;

#define MAXRANGES 1000

int inicializafaixas(addrvet_t *avet){
  avet->numranges = 0;
  return 0;
}
	 novafaixa = criafaixa(avet,naddr,naddr);
	 if (!primeirafaixa(avet,novafaixa){

int localizafaixa(addrvet_t * avet, int l, int r, long addrstart, long addrend){
  int median = (l+r)/2;
  if (r==l) return median;
}

int criafaixa(addrvet_t *avet, long start, long end){

  // localiza faixa
  int pos = localizafaixa(avet,0,avet->numranges,start,end);
  // ajusta vetor
  // insere faixa
    
}

int removefaixa();

int primeirafaixa();
int ultimafaixa();

int juntarfaixas();


int insertaddr(addrvet_t * avet, int l, int r, long naddr){
   int median = (l+r)/2;
   if (r>l){
     // ainda pode buscar mais o intervalo especifico
     if (naddr > avet->v[median].end){
       // naddr esta a direita do intervalo median
       insertaddr(avet,median+1,r,naddr);
     } else {
       if (naddr < avet->v[median].start){
	 // naddr esta a esquerda do intervalo median
         insertaddr(avet,l,median-1,naddr);
       } else {
	 // naddr esta inserido no intervalo median
	 // assert.
       }
     } 
   } else if (r==l){
     // encontrou o ponto onde naddr deve ser inserido
     // nao ha faixa que contenha naddr
     // proteger para addrvet vazio
     int novafaixa = -1;

     if (naddr < avet->v[median].start){
       // endereco esta a esquerda do intervalo
       if (naddr+TAMWORD >= avet->v[median].start){
         // endereco esta imediatamente a esquerda do intervalo e
         // deve ser incorporado a ele
         avet->v[median].start = naddr;
	 if (!primeirafaixa(avet,median)){
           // ha uma faixa a esquerda, verificar juncao    
           if (avet->v[median].start-avet->v[median-1].end<=TAMWORD){
	     // median-1 e median sao contiguas
	     juntarfaixas(avet,median-1,median);
	   }
	 }
       } else {
         // endereco deve criar uma nova faixa
	 // verificar se nao junta esquerda e direita
	 novafaixa = criafaixa(avet,naddr,naddr+TAMWORD);
	 if (!primeirafaixa(avet,novafaixa){
	   // verifica esquerda
	 }
	 if (!ultimafaixa(avet,novafaixa){
	   // verifica direita
	 }
       }
       // faixa ampliada ou criada deve ser testada para juncao

     }

     if (naddr > avet->v[median].start){
       // endereco esta a direita do intervalo
       if (naddr-TAMWORD <= avet->v[median].end){
         // endereco esta imediatamente a direita do intervalo e
         // deve ser incorporado a ele
         avet->v[median].end = naddr;
	 if (!ultimafaixa(avet,median)){
           // ha uma faixa a direita, verificar juncao    
           if (avet->v[median+1].start-avet->v[median].end<=TAMWORD){
	     // median+1 e median sao contiguas
	     juntarfaixas(avet,median,median+1);
	   }
	 }
       } else {
         // endereco deve criar uma nova faixa
	 novafaixa = criafaixa(avet,naddr,naddr);
	 if (!primeirafaixa(avet,novafaixa){
	   // verifica esquerda
	 }
	 if (!ultimafaixa(avet,novafaixa){
	   // verifica direita
	 }
       }
       // faixa ampliada ou criada deve ser testada para juncao

     }
     // endereco esta a direita do intervalo

     // endereco esta imediatamente a direita do intervalo e 
     // deve ser incorporado a ele

     // endereco deve criar uma nova faixa

     //faixa ampliada ou criada deve ser testada para juncao

/*

     long diff = naddr-addrvet[median].ad;

     if (naddr<avet->v[median].inicio){
       if (addrvet[median].inicio-naddr<=TAMWORD){ // adjust begin
           addrvet[median].inicio = naddr;
           if (naddr-addrvet[median-1].inicio<=TAMWORD){
           }
           // junta faixas?
       } else {
         int criafaixa = 0;
         if (posinit>0){
           // verifica faixa anterior
           int dif = naddr - addrvet[posinit-1].ad;
           if (dif > TAMWORD){ //cria nova faixa
             criafaixa = 1;
           } else { // adjust end of range
             addrvet[posinit-1].ad = naddr;     
           }
         } else {
           criafaixa = 1;
         }
       }
     } else if (naddr>addvet[posend].ad){
       if (naddr-addrvet[posend].adr<=TAMWORD){ // adjust begin
           addrvet[posend].ad = naddr;
       } else {
         // checa faixa anterior 
         // pode ter que criar faixa ou 
         // pode ter que juntar faixas
       }
     }
  
   } else { // r<l e addrvet está vazio: insere faixa
     criafaixa();
   }
*/

}

int main(){
  addrvet_t avet;
  avet.numranges = 0;
  
  // le arquivo e monta indice
  insertaddr(&avet, 0, avet.numranges-1, naddr);

  
  // reescreve arquivo


  return 0;
}
