 int opc_pizza(){
system("cls");
    FILE * pf = NULL;
FILE * pf2 = NULL;
    int escpizza,valorpizza1,valorpizza2,valorpizza3,valorpizza4,valorpizza5,valorpizza6;
    
    valorpizza1 = 0;
        valorpizza2 = 0;
            valorpizza3 = 0;
                valorpizza4 = 0;
                    valorpizza5 = 0;
                        valorpizza6 = 0;
    char pizza[20] = "NA";
   char pizza2[20] = "NA";
   char pizza3[20] = "NA";
   char pizza4[20] = "NA";
   char pizza5[20] = "NA";
   char pizza6[20] = "NA";
   

    pf = fopen( "pizzas.txt", "r" );

    if(!pf)
        return 1;

    fscanf( pf, "\n%s\n", &pizza );

    fscanf( pf, "\n%s\n", &pizza2 );
    fscanf( pf, "\n%s\n", &pizza3 );
        fscanf( pf, "\n%s\n", &pizza4 );
    fscanf( pf, "\n%s\n", &pizza5 );
    fscanf( pf, "\n%s\n", &pizza6 );

    fclose(pf);
     pf2 = fopen( "valorp.txt", "r" );
       fscanf( pf2, "\n%d\n", &valorpizza1 );
    fscanf( pf2, "\n%d\n", &valorpizza2);
    fscanf( pf2, "\n%d\n", &valorpizza3 );
    fscanf( pf2, "\n%d\n", &valorpizza4 );
        fscanf( pf2, "\n%d\n", &valorpizza5 );
    fscanf( pf2, "\n%d\n", &valorpizza6 );
    fclose(pf2);

  printf( "1: %s %d ", pizza,valorpizza1 );	
    printf("Reais\n");

  
    printf( "2: %s %d ", pizza2,valorpizza2 );
     printf("Reais\n");
    printf( "3: %s %d ", pizza3,valorpizza3 );
     printf("Reais\n");
    printf( "4: %s %d ", pizza4,valorpizza4 );
     printf("Reais\n");
 
    printf( "5: %s %d ", pizza5,valorpizza5 );
     printf("Reais\n");

  
     printf( "6: %s %d ", pizza6,valorpizza6 );
      printf("Reais\n");
      
      printf("Digite 0 para voltar ou escolha o sabor ");
  
    scanf(" %i", &escpizza);
        switch(escpizza){
            case 1:
            printf("Pizza 1 selecioada %s",pizza);
            

            break;
            case 2:
           printf("Pizza 2 selecioada %s",pizza2);

            break;
            case 3:
printf("Pizza 3 selecioada %s",pizza3);
            break;
            case 4:
            	printf("Pizza 4 selecioada %s",pizza4);
            break;
            case 5:
      printf("Pizza 5 selecioada %s",pizza5);
          break;
          case 6:
          	printf("Pizza 6 selecionada %s",pizza6);
     default:
          
break;
	  }


}