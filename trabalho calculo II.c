/*01- Desenvolver um algoritmo integrado que realize a análise completa de uma Progressão
Geométrica (PG), unindo programação, cálculo de somas finitas/infinitas e critérios de
convergência (Linguagem C ou outra).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void AnalitPG();
void IdentClas(float an, float q, int n);
float SumFinAnal(float a1, float q, int n);
float SumFinEmp(float a1, float q, int n);
int main(void){
    AnalitPG();
}

void AnalitPG(){
    float a1; //primeiro termo
    float an;
    float q; //razao
    int n; //numeros de termos 
    int i, j;

    //Imput
    printf("\nInsert the first term of GP: ");
    scanf("%f", &a1);
    printf("\nInsert the rate of GP (decimal): ");
    scanf("%f", &q);
    printf("\nInsert the number of terms for finit analitc: ");
    scanf("%d", &n);

    an = a1;
    IdentClas(an, q, n);

    printf("\nA soma finita dos %d primeiros termos pela formula analitica eh: %.3f", n, SumFinAnal(a1, q, n));
    printf("\nA soma finita dos %d primeiros termos pela forma empirica eh: %.3f\n", n, SumFinEmp(a1, q, n));

    
}

    void IdentClas(float an, float q, int n){
    //gerar os n termos e classificar a sequencia como crescente, decrescente, constante ou alternada
    printf("\nIndentificacao e classificacao: \n");
    int i;
    for(i=0;i<n;i++){
        printf("%.3f ", an);
        an = an * q;
    }
    if (q>1){
        printf("\nA sequencia eh crescente.");
    }
    else if (q<1) printf("\nA sequencia eh decrescente.");
    else if(q==1) printf("\nA sequencia eh constante.");
    //achar como seria alternada
}

float SumFinAnal(float a1, float q, int n){
    float Sn, exp;
    if (q == 1){
        Sn = a1 * n;
    }
    else{
        exp = pow(q, n);
        Sn = (a1 * (exp - 1)) / (q - 1);
    }
    return Sn;
}

float SumFinEmp(float a1, float q, int n){
    float sum = 0, an = a1;
    int i;

    for (i = 0; i < n; i++){
        sum += an;   // soma o termo atual
        an *= q;     // depois avança para o próximo
    }
    return sum;
}
