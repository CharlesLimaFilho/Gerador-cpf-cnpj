#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int validar (char *CPF );
int gerar ();
int gerar_cnpj();

int main (void){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	char cpfs[18];
	int n = rand() % 10;
	int mant = 1, mant2 = 2, cpf[9], op, ver, cont;
	while(mant ==1){
		printf("\nDigite [1] para verificar se um CPF/CNPJ é válido\nDigite [2] para gerar um CPF válido aleatório\nDigite [3] para gerar um CNPJ válido aleatório\nDigite [0] para sair do programa");
		scanf("%d", &op);
		if(op == 2){
			gerar();
		}
		else if(op == 1){
			printf("\nDigite um cpf/cnpj qualquer para ver se é válido ou não :  ");
			scanf(" %18[^\n]", cpfs);
			ver = validar(cpfs);
			if (ver == 2) {
				printf("\nO cpf/cnpj é válido!");
			} else {
				printf("\nO cpf/cnpj não é válido!");
			}
		}
		else if(op == 0){
			break;
		}
		else if(op == 3){
			gerar_cnpj();
		}
		else{
			printf("Digite um número válido.");
		}
	}
	
	
	return 0;
}

int validar ( char *CPF){
	int mult1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, mult2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, cont2 = 0;
	int n_cpf [14] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}, n_cnpj[18] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}, d_ver[2], cont, soma = 0, numero = 10, ver = 0;
	if (strlen(CPF) == 14) {
		for(cont = 0; cont < 14; cont++) {
		if (CPF[cont] == '.' || CPF[cont] == '-') {
			continue;
		} else {
			n_cpf[cont] = CPF[cont] - '0';
			//printf("%d ", n_cpf[cont]);
		}
	}
	for (cont = 0; cont < 12; cont++) {
		if(n_cpf[cont] != 99){
			soma = soma + (n_cpf[cont]* numero); 
			numero--;
		}
	}
	//printf("\n%d",soma);
	if (soma % 11 < 2) {
		d_ver[0] = 0;
	} else {
		d_ver[0] = 11 - (soma % 11);
	}
	
	numero = 11;
	soma = 0;
	
	for (cont = 0; cont < 13; cont++) {
		if(n_cpf[cont] != 99){
			soma = soma + (n_cpf[cont] * numero); 
			numero--;
		}
	}
	//printf("\n%d ",soma);
	if (soma % 11 < 2) {
		d_ver[1] = 0;
	} else {
		d_ver[1] = 11 - (soma % 11);
	}
	
	for(cont = 12; cont <= 13; cont++){
		//printf(" %d",n_cpf[cont]);
		if(n_cpf[cont] == d_ver[cont - 12]) {
			ver++;
			//printf("\n %d ", ver);
		}
	} 
	return ver;
	}
	else if (strlen(CPF) == 18){
		for(cont = 0; cont < 18; cont++) {
		if (CPF[cont] == '.' || CPF[cont] == '-' || CPF[cont] == '/') {
			continue;
		} else {
			n_cnpj[cont] = CPF[cont] - '0';
			//printf("%d ", n_cpf[cont]);
		}
	}
	
	for (cont = 0; cont < 16; cont++) {
		if(n_cnpj[cont] != 99){
			soma = soma + (n_cnpj[cont] * mult1[cont2]);
			cont2++;
		}
	}
	//printf("%d",soma);
	
	if (soma % 11 < 2) {
		d_ver[0] = 0;
	} else {
		d_ver[0] = 11 - (soma % 11);
	}
	
	soma = 0;
	cont2 = 0;
	
	for (cont = 0; cont < 17; cont++) {
		if(n_cnpj[cont] != 99){
			soma = soma + (n_cnpj[cont] * mult2[cont2]);
			cont2++;
		}
	}
	
	//printf("\n%d",soma);
	
	if (soma % 11 < 2) {
		d_ver[1] = 0;
	} else {
		d_ver[1] = 11 - (soma % 11);
	}
	for(cont = 16; cont <= 17; cont++){
		//printf(" %d",n_cpf[cont]);
		if(n_cnpj[cont] == d_ver[cont - 16]) {
			ver++;
			//printf("\n %d ", ver);
		}
	}
	return ver;
	
	}
	else
		printf("Digite corretamente um CPF/CNPJ!\n");
	return 0;
}

int gerar ( ){
	int cont;
	int cpf[14] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}, soma = 0, numero = 10;
	char cpfs[14];
	for (cont = 0; cont < 14; cont++) {
		if (cont == 3 || cont == 7 || cont == 11) {
			continue;
		}
		else {
			cpf[cont] = rand() % 10;
			//printf(" %d ", cpf[cont]);
		}
	}
	
	for (cont = 0; cont < 12; cont++) {
		if(cpf[cont] != 99){
			soma = soma + (cpf[cont]* numero); 
			numero--;
		}
	}
	//printf("\n%d",soma);
	if (soma % 11 < 2) {
		cpf[12] = 0;
	} else {
		cpf[12] = 11 - (soma % 11);
	}
	
	numero = 11;
	soma = 0;
	
	for (cont = 0; cont < 13; cont++) {
		if(cpf[cont] != 99){
			soma = soma + (cpf[cont] * numero); 
			numero--;
		}
	}
	//printf("\n%d ",soma);
	if (soma % 11 < 2) {
		cpf[13] = 0;
	} else {
		cpf[13] = 11 - (soma % 11);
	}
	
	
	for (cont = 0; cont < 14; cont++) {
		if (cont == 3 || cont == 7) {
			cpfs[cont] = '.';
		}
		else if (cont == 11){
			cpfs[cont] = '-';
		} else {
			cpfs[cont] = cpf[cont] + '0';
		}
		//printf(" %s ", cpfs);
	}
	printf("\n%s\n", cpfs);
	return 0;
}

int gerar_cnpj(){
	int cont, cont2 =0;
	int cnpj[18] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}, mult1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, mult2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, soma = 0;
	char cnpjs[18];
	for (cont = 0; cont < 18; cont++) {
		if (cont == 2 || cont == 6 || cont == 10 || cont == 15) {
			continue;
		}
		else {
			cnpj[cont] = rand() % 10;
			//printf(" %d ", cpf[cont]);
		}
	}
	
	for (cont = 0; cont < 16; cont++) {
		if(cnpj[cont] != 99){
			soma = soma + (cnpj[cont] * mult1[cont2]);
			cont2++;
		}
	}
	if (soma % 11 < 2) {
		cnpj[16] = 0;
	} else {
		cnpj[16] = 11 - (soma % 11);
	}
	
	soma = 0;
	cont2 = 0;
	
	for (cont = 0; cont < 17; cont++) {
		if(cnpj[cont] != 99){
			soma = soma + (cnpj[cont] * mult2[cont2]);
			cont2++;
		}
	}
	if (soma % 11 < 2) {
		cnpj[17] = 0;
	} else {
		cnpj[17] = 11 - (soma % 11);
	}
	
	for (cont = 0; cont < 18; cont++) {
		if (cont == 2 || cont == 6) {
			cnpjs[cont] = '.';
		}
		else if (cont == 10){
			cnpjs[cont] = '/';
			
		} else if(cont == 15){
			cnpjs[cont] = '-';
		}
		else  {
			cnpjs[cont] = cnpj[cont] + '0';
		}
		//printf(" %s ", cpfs);
	}
	printf("\n%s\n", cnpjs);
	return 0;
}
