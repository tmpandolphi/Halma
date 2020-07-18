#include <stdio.h>
#include <stdlib.h>

#define N 8

//Titulo Jogo.
void header(void)
{
	printf("\n\n");
	printf("\tHALMA     HALMA  HALMAHALMAHALMA  HALMA       HALMAH        AHALMA  HALMAHALMAHALMA \n");
	printf("\tHALMA     HALMA  HALMA     HALMA  HALMA       HALMAHAL    LMAHALMA  HALMA     HALMA \n");
	printf("\tHALMAHALMAHALMA  HALMA     HALMA  HALMA       HALMAHALMAHALMAHALMA  HALMA     HALMA \n");
	printf("\tHALMAHALMAHALMA  HALMAHALMAHALMA  HALMA       HALMA   LMA    HALMA  HALMAHALMAHALMA \n");
	printf("\tHALMA     HALMA  HALMAHALMAHALMA  HALMAHALMA  HALMA          HALMA  HALMA     HALMA \n");
	printf("\tHALMA     HALMA  HALMA     HALMA  HALMAHALMA  HALMA          HALMA  HALMA     HALMA \n");
}

//Gera matriz para novo jogo.
void gen_mat(char mat[N][N])
{
	int i, j, j_c;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			mat[i][j]='_';
		}
	}

    j_c=3;
    for(i=0; i<4 ; i++)
    {
        for(j=0;j<=j_c;j++)
		{
            mat[i][j]='Y';
        }
        j_c-=1;
    }

   j_c=4;
	for(i=7;i>3;i--)
	{
		for(j=7;j>=j_c;j--)
		{
            mat[i][j]='X';
		}
		j_c+=1;
	}
}

//Escreve matriz.
void write(char mat[N][N])
{
	int i, j;
	system("cls");

    header();

    printf("\n\n\n");
    printf("\tTABULEIRO!\n\n");
    printf("\t T  0 1 2 3 4 5 6 7\n\n");

	for (i=0; i < N; i++)
	{
	    printf ("\t %d  ",i);
		for (j=0; j < N; j++)
		{
			printf("%1c ",mat[i][j]);
		}
		printf("\n");
	}
}

//Testa as duas condições de fim de jogo e escreve o ganhador.
int gameover(char mat[N][N], int movimentos[2],char player)
{
    int i, j, j_c;

    //Se movimentos de X maior que 30 testa se ainda possui peças na base.
    if(movimentos[1]>=30)
    {
        j_c=3;
        for(i=0; i<4 ; i++)
        {
            for(j=0;j<=j_c;j++)
            {
                if(mat[i][j]!='_' || mat[i][j]!='X')
                {
                    printf("GAME OVER! O ganhador: Pecas Y.\n");
                    return(1);
                }

            }
            j_c-=1;
        }
    }

    //Se movimentos Y maior que 30 testa se ainda possui peças na base.
    if(movimentos[0]>=30)
    {
        j_c=4;
        for(i=7;i>3;i--)
        {
            for(j=7;j>=j_c;j--)
            {
                if(mat[i][j]!='_' || mat[i][j]!='Y')
                {
                    printf("GAME OVER! O ganhador: Pecas X.\n");
                    return(1);
                }
            }
        j_c+=1;
        }
    }

    //Testa se todas as peças de X estao na base Y.
    j_c=3;
    for(i=0; i<4 ; i++)
    {
        for(j=0;j<=j_c;j++)
        {
            if(mat[i][j]!='_' && mat[i][j]!='Y')
            {
                printf("GAME OVER! O ganhador: Pecas X.\n");
                return(1);
            }
        }
    j_c-=1;
    }

    //Testa se todas a peças de Y estao na base X.
    j_c=4;
    for(i=7;i>3;i--)
    {
        for(j=7;j>=j_c;j--)
        {
            if(mat[i][j]!='_' && mat[i][j]!='X')
            {
                printf("GAME OVER! O ganhador: Pecas Y.\n");
                return(1);
            }
        }
        j_c+=1;
    }

    //Se ninguem ganhou continua o while.
    return(0);
}

/*
//Troca as peças de lugar.
void muda_pecas()
{
    mat[x][y]='_';
    x=l;
    y=c;
    mat[l][c]=player;
    write(mat);
    printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
}
*/

//X e Y são posições da peça que quer movimentar, D é a quantia de pulos, L e C são as nova posição das peças.
int mov(char mat[N][N], char player)
{
    int x,y,l,c,n,i;

    printf("\n\n %c, entre a casa da peca que quer movimentar:\n",player);
    scanf("%d%d",&x,&y);
    printf(" Entre quantos pulos deseja fazer 0 para 1 casa para qualquer lado, ou 1 a 3 para pular sobre outras pecas.\n");
    do
    {
        scanf("%d",&n);
        if (n>3 || n<0)
        {
            printf("Numero invalido. Entre quantos pulos deseja fazer 0 para 1 casa para qualquer lado, \nou 1 a 3 para pular sobre outras pecas.\n");
            n=-1;
        }
    }
    while(n==-1);
    printf("%d",n);

    if(n==0)
    {
            printf(" Digite o movimento %d, linha e coluna.\n",i+1);
            scanf("%d%d",&l,&c);

        if(mat[l][c]=='_' && l<8 && c<8 && l>-1 && c>-1);
        {
                    mat[x][y]='_';
                    x=l;
                    y=c;
                    mat[l][c]=player;
                    write(mat);
                    printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
        }
    }
    else if(n>=1 && n<=3)
    {
        for(i=0;i<n;i++)
        {
            printf(" Digite o movimento %d, linha e coluna.\n",i+1);
            scanf("%d%d",&l,&c);

                if(mat[l][c]=='_' && (l<8 && c<8) && (l>-1 && c>-1))
                {
                    if(l==x+2 && c==y)
                    {
                        if(mat[x+1][y]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x && c==y+2)
                    {
                        if (mat[x][y+1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x-2 && c==y)
                    {
                        if (mat[x-1][y]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x && c==y-2)
                    {
                        if (mat[x][y-1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x+2 && c==y+2)
                    {
                        if (mat[x+1][y+1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x-2 && c==y-2)
                    {
                        if (mat[x-1][y-1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x+2 && c==y-2)
                    {
                        if (mat[x+1][y-1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                    }
                    else if(l==x-2 && c==y+2)
                    {
                        if (mat[x-1][y+1]!='_')
                        {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                        }
                        else
                        {
                            printf("Movimento Invalido, nao pulou sobre outra peca.\n");
                            i--;
                        }
                }
            }
            else if((l==x+1 && c==y)||(l==x && c==y+1)||(l==x+1 && c==y+1)||(l==x-1 && c==y)||(l==x && c==y-1)||(l==x-1 && c==y-1)||(l==x+1 && c==y-1)||(l==x-1 && c==y+1))
            {
                if (n>1)
                {
                    printf("Nao e possivel mover uma casa após um pulo.\n");
                    i=4;
                }
                /*else if(n==1)
                {
                            mat[x][y]='_';
                            x=l;
                            y=c;
                            mat[l][c]=player;
                            write(mat);
                            printf("\n Ultimo movimento: Pecas %c, L%d C%d.\n\n",player,l,c);
                            printf("Voce moveu so uma casa, seus pulos foram zerados.\n");
                            i=4;
                }*/
            }
            else
            {
                printf("Movimento Invalido.\n");
                i--;
            }
        }
    }
}

void game(char mat[N][N])
{
    char player='Y';
    int movimentos[2], i=0, test=0;

    movimentos[0]=0;
    movimentos[1]=0;

    printf("\n Player Y, %d movimento(s).",movimentos[0]);
    printf("\n Player X, %d movimento(s).\n",movimentos[1]);

    do
    {
        mov(mat, player);
        if(player=='Y')
        {
            player='X';
            movimentos[i]+=1;
            i=1;
        }
        else
        {
            player='Y';
            movimentos[i]+=1;
            i=0;
        }

        printf("Player Y, %d movimento(s).\n",movimentos[0]);
        printf("Player X, %d movimento(s).\n",movimentos[1]);
        test=gameover(mat,movimentos,player);
    }
    while(test==0);
}


int main()
{
	char    mat[N][N];
    int option=0,exit=0;

    while(exit==0)
    {
        system("cls");
        header();
        printf("\n\n\t\t\t DIGITE O NUMERO DA OPCAO DESEJADA!\n\n");
		printf("\t\t\t > 1. NOVO JOGO;\n \t\t\t > 2. SAIR;\n\n\n");
        printf("Digite sua escolha: ");

        scanf("%d",&option);
		switch(option)
		{
            case 1:
                gen_mat(mat);
                write(mat);
                game(mat);
                printf("\nDeseja continuar? Digite 0 - Yes, 1 - No.\n ");
                scanf("%d",&exit);
                break;

            case 2:
                system("cls");
                header();
                printf("\n\nPressione qualquer tecla para continuar!\n");
                exit=1;
            break;
		}
	}
}
