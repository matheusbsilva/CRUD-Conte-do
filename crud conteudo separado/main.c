#include <stdio.h>
#include <stdlib.h>

#define CONTEUDO "Conteudo/"

typedef struct {int dia, mes, ano;} Data;

typedef struct {
        int hora;
        int minuto;
    }Horario;

  typedef struct {
        long int numero_contato;
        char email_contato[50];
    } Contato;

  typedef struct Conteudo //andre e matheus
  {
      char nome_do_evento[70];  //
      Data dia_de_inicio_evento;
      Data dia_fim_evento;
      char local_do_evento[50];
      Horario horario_inicial;
      Horario horario_final;
      Contato info_contato;  //DDDe e-mail tbm?
      double preco_ingresso;    // assim vao ser aceitos valores como R$1.90 ou R$999.99
      char restricoes_do_evento[100];   // EX: Altura máxima permitida, etc.
      char descricao[335];  //informações adicionais, local de compra de ingresso, etc.
  };

void create_conteudo()
{
    struct Conteudo evento;
    FILE *fp;

    printf("\nIntroduza um nome: ");    gets(evento.nome_do_evento); fflush(stdin);

    printf("\nIntroduza o dia de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.dia);  fflush(stdin);
    printf("\nIntroduza o mes de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.mes);  fflush(stdin);
    printf("\nIntroduza o ano de inicio do evento: ");  scanf("%i", &evento.dia_de_inicio_evento.ano);  fflush(stdin);

    printf("\nCaso seja um evento de dia unico, digite a mesma data\n");
    printf("\nIntroduza o dia final do evento: ");  scanf("%i", &evento.dia_fim_evento.dia);    fflush(stdin);
    printf("\nIntroduza o mes final do evento: ");  scanf("%i", &evento.dia_fim_evento.mes);    fflush(stdin);
    printf("\nIntroduza o ano final do evento: ");  scanf("%i", &evento.dia_fim_evento.ano);    fflush(stdin);

    printf("\nIntroduza o local ou endereço do evento: ");   gets(evento.local_do_evento);  fflush(stdin);

    printf("\nIntroduza o horario de inicio do evento: ");   scanf("%i %i", &evento.horario_inicial.hora, &evento.horario_inicial.minuto);
    printf("\nIntroduza o horario de termino do evento: ");    scanf("%i %i", &evento.horario_final.hora, &evento.horario_final.minuto);
        fflush(stdin);
    printf("\nIntroduza o numero e e-mail de contato: ");  scanf("%li", &evento.info_contato.numero_contato);    fflush(stdin);
        gets(evento.info_contato.email_contato);    fflush(stdin);

    printf("\nIntroduza o preço do ingresso/entrada: ");    scanf("%lf",&evento.preco_ingresso);    fflush(stdin);

    printf("\nIntroduza as restricoes do evento, caso exista: ");   gets(evento.restricoes_do_evento);  fflush(stdin);

    printf("\nIntroduza uma breve descricao do evento(max. 330 caracteres): ");  gets(evento.descricao);    fflush(stdin);

    //gravar em arquivo

     fp = fopen("teste.txt","w");

     //nome
     fputs(evento.nome_do_evento, fp);
     //info data
     fprintf(fp, " %2d/ %2d/ %2d ", evento.dia_de_inicio_evento.dia, evento.dia_de_inicio_evento.mes, evento.dia_de_inicio_evento.ano);
     fprintf(fp, " %2d/ %2d/ %2d ", evento.dia_fim_evento.dia, evento.dia_fim_evento.mes, evento.dia_fim_evento.ano);
     //info local
     fputs(evento.local_do_evento, fp);
     //info horario
     fprintf(fp, " %2d:%2d ", evento.horario_inicial.hora, evento.horario_inicial.minuto);
     fprintf(fp, " %2d:%2d ", evento.horario_final.hora, evento.horario_final.minuto);
     //info contato
     fprintf(fp, " %d ", evento.info_contato.numero_contato);
     fputs(evento.info_contato.email_contato, fp);
     //info preço
     fprintf(fp, " R$: %.2lf ", evento.preco_ingresso);
     //info restricao e descricao
     fputs(evento.restricoes_do_evento, fp);    fprintf(fp," ");    fputs(evento.descricao, fp);



     fclose(fp);
}



int main()
{

    create_conteudo();

    return 0;
}
