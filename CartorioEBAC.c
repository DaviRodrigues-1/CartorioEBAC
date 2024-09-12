#include <stdio.h> //comunicaï¿½ï¿½o com o usuario
#include <stdlib.h> 
#include <locale.h> //alocaï¿½ï¿½o de texto por regiï¿½o
#include <string.h> //Biblioteca para strings 

int registro(){
    char arquivo[40];
    char cpf [40];
    char nome [40];
    char sobrenome[40];
    char cargo [40];
    
    printf("Digte o cpf a ser cadastrado: ");
    scanf(" %s", cpf);
    
    strcpy(arquivo,cpf); //x=y, o valor de CPF determina o valor de ARQUIVO, no caso o nome
    
    FILE *file = fopen(arquivo, "r");
    if (file != NULL){
        printf("Erro: O CPF %s já está registrado!\n\n", cpf);
        fclose(file);
        system("pause");
        return 0; //se o cpf ja estiver registrado, ele volta para o inicio do menu.
	}
        
   
    file = fopen(arquivo, "w"); //Abre o arquivo tipo w (write)
    fprintf(file, "%s",cpf); //escreve no arquivo FILE, o char CPF
    fclose(file); //fecha o arquivo FILE
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf(" %s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf(" %s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file); 
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Registro salvo com sucesso!\n");
    system("pause");
    return 0;
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    char *subs;
    
    
    printf("Digite o cpf a ser consultado: \n");
    scanf(" %s", cpf);
    system("cls");
    
    FILE *file;
    file = fopen(cpf, "r"); //r= read
    
    if(file == NULL)
	{
    	printf("Esse CPF não está cadastrado! \n");
    }
    
    while(fgets(conteudo, 200, file)!= NULL)
	{
    	
    	printf("Essas são as informações do usuario: \n\n");
    	
    	subs = strtok(conteudo, ","); //string | limitaï¿½ï¿½o 
        printf("CPF: %s\n", subs);
        
        subs = strtok(NULL, ",");
        printf("Nome: %s\n", subs);
        
        subs = strtok(NULL, ",");
        printf("Sobrenome: %s\n", subs);
        
        subs = strtok(NULL, ",");
        printf("Cargo: %s\n\n", subs);	
	}
	
	system("pause");
	fclose(file);
    
}

int deletar()
{
  	char cpf[40];
  	
  	printf("Digite o CPF do usuario a ser deletado:");
  	scanf(" %s",cpf);
  	
  	FILE *file;
  	file = fopen(cpf, "r");
  	fclose(file);
  	
  	if(file == NULL)
	{
		system("cls"); 
  		printf("Esse CPF não está cadastrado no sistema!\n\n");	
	}
	else
	{
		if(remove(cpf)==0){
		printf("Usuário removido com sucesso!\n");
		}
	}
	system("pause");
  }


int main(){
	
	int opcao=0;
	int laco=1;
	char senhad[]="a";
    int comp;
    
    setlocale(LC_ALL, "Portuguese");

   printf("|--------------------------------|\n");
   printf("| \t Cartório da EBAC \t | \n|--------------------------------|\n\n");
   printf("Login de ADM!\n\n Digite sua senha:");
   scanf("%s", senhad);

  comp = strcmp(senhad, "admin");

  if(comp == 0){
	setlocale(LC_ALL, "Portuguese");
	
	while (laco == 1){   //  | entrada | saï¿½da | adicionar n de "loops"| 
	 setlocale(LC_ALL, "Portuguese");
	 system("cls"); 
	
	 printf("|--------------------------------|\n");
	 printf("| \t Cartório da EBAC \t | \n|--------------------------------|\n\n");
	 printf(" Escolha a opção desejada:\n\n");
	 printf("\t[1]- Registrar nomes \n");
	 printf("\t[2]- Consultar nomes\n");
	 printf("\t[3]- Apagar nomes\n");
	 printf("\t[4]- Sair do menu\n\n\n"); //fim do menu
	 printf("Opção: ");
	
	 scanf(" %d", &opcao);    //escanear o input, esse aq ï¿½ o leitor de opï¿½ï¿½es, ele armazena as info!
	 system("cls"); 
	   
	 
	 //-------------------------------------------------------//
	 
	 switch(opcao){   //varios "casos" (case) 
	 	
		 case 1:
		 registro();
		 break;
		 
		 case 2:
		 consulta();
		 break;
		 
		 case 3:
		 deletar();
		 break;
		 
		 case 4:
		 printf("Voce escolheu sair! Obrigado por utilizar o programa\n");
		 return 0;
		 break;
		 
		 default:
		 printf("Essa opção nï¿½o existe! \n");
		 system("pause");
		 break;
		 
		 
	  };
   };
  }  
  else
  {
    printf("Senha incorreta!");
    return 0;
   } 
};
