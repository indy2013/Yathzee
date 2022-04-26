
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define AANTAL_PLAYERS 2
#define AANTAL_RONDES 13
#define AANTAL_REROLLS 2

int showDie();
int throwDie ();
void sortDie(int die[5]);

int dice1(int dieNumber);
int dice2(int dieNumber);
int dice3(int dieNumber);
int dice4(int dieNumber);
int dice5(int dieNumber);
int dice6(int dieNumber);

int scoreboard(int p);
int scoreboard_string_end(int i);

int checkCombo(int die[5], int getal);

int threeOfAKind(int die[5]);
int fourOfAKind(int die[5]);
int fullHouse(int die[5]);
int smallStraight(int die[5]);
int largeStraight(int die[5]);
int yahtzee(int die[5]);
int kans(int die[5]);

int categorie[2][13];

int playername();
char playersnames[AANTAL_PLAYERS][20];

void printIntro(void);

void reroll (int die[5]);
void kiesCombo(int die[5], int p);

int die[5];
int p[15];

int main(void)
{
    srand(time(NULL));

    //DEMO Code voor testen van kaarten
    //dit is voor de welkom screen

    printIntro();
    playername();

    for (int j = 1; j < AANTAL_RONDES; j++) {
        int p = 0;

        for (int i = 0; i < 5; i++) {
            die[i] = throwDie();
        }

        reroll(die);
        showDie();
        sortDie(die);
		scoreboard(p);
        kiesCombo(die, p);
        scoreboard(p);

        printf("Druk op enter voor speler 2...\n\n");
        getchar();
        getchar();
        printf("Speler 2:\n");

        p = 1;

        for (int i = 0; i < 5; i++) {
            die[i] = throwDie();
        }

        reroll(die);
        showDie();
        sortDie(die);
		scoreboard(p);
        kiesCombo(die, p);
        scoreboard(p);

        int ronde = j + 1;
        if(ronde != AANTAL_RONDES) {
            printf("Druk op enter voor ronde %d/%d...\n\n", ronde, AANTAL_RONDES);
            getchar();
            getchar();
            printf("Speler 1:\n");
        }
    }

    scoreboard(0);

    int score[2];
    score[0] = categorie[0][6]+categorie[0][7]+categorie[0][8]+categorie[0][9]+categorie[0][10]+categorie[0][11]+categorie[0][12]+categorie[0][0]+categorie[0][1]+categorie[0][2]+categorie[0][3]+categorie[0][4]+categorie[0][5];
    score[1] = categorie[1][6]+categorie[1][7]+categorie[1][8]+categorie[1][9]+categorie[1][10]+categorie[1][11]+categorie[1][12]+categorie[1][0]+categorie[1][1]+categorie[1][2]+categorie[1][3]+categorie[1][4]+categorie[1][5];

    if (score[0] < score[1])
        printf("%s heeft gewonnen, met %d punten!\n%s had %d punten!\n",playersnames[1],score[1],playersnames[0],score[0]);
    else
        printf("%s heeft gewonnen, met %d punten!\n%s had %d punten!\n\n",playersnames[0],score[0],playersnames[1],score[1]);

    printf("Druk op enter om opnieuw te spelen...");
    getchar();
    getchar();

    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 13; ++j) {
            categorie[i][j] = 0;
        }
    }

    main();

}

int showDie()
{
    for(int i = 0; i <5; i++){
        int dieNumber = i + 1;
        switch (die[i])
        {
            case 1:
                dice1(dieNumber);
                break;
            case 2:
                dice2(dieNumber);
                break;
            case 3:
                dice3(dieNumber);
                break;
            case 4:
                dice4(dieNumber);
                break;
            case 5:
                dice5(dieNumber);
                break;
            case 6:
                dice6(dieNumber);
                break;
            default:
                printf("Die off the tabel! Try again!");
                break;
        }
    }
    return 0;
}


int throwDie()
{
    int getal = (rand() % 6) +1;
    return getal;
}



void sortDie(int die[5])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = i + 1; j < 5; ++j)
        {
            if(die[i] > die[j])
            {
                int a = die[i];
                die[i] = die[j];
                die[j] = a;
            }
        }
    }
}

void reroll (int die[5])
{
    int getal = 0;
    int reroll_die = 0;

    for (int lijst = 0; lijst < AANTAL_REROLLS; lijst ++)
    {
        do
        {
            showDie();
            printf("Hoeveel dobbelstenen wil je opnieuw rollen: ");
            scanf("%d", &getal);

        } while ((getal != 1) && (getal != 2) && (getal != 3) && (getal != 4) && (getal != 5) && (getal != 0));

        if (getal != 0)
        {
            for (int reroll_lijst = 0; reroll_lijst < getal; reroll_lijst++)
            {
                do
                {
                    printf("Geef een dobbelsteen die je opnieuw wil rollen: ");
                    scanf("%d", &reroll_die);
                    die[reroll_die - 1] = throwDie();
                }
                while((reroll_die != 5) && (reroll_die != 1) && (reroll_die != 2) && (reroll_die != 3) && (reroll_die != 4));
            }
        }
        else
        {
            break;
        }
    }
}

int dice1(int dieNumber)
{
    int a=1;
    printf("      .-------------.    \n");
    printf("     /             /|    \n");
    printf("    /      o      / |    \n");
    printf("   /_____________/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int dice2(int dieNumber)
{
    int a=2;
    printf("      .-------------.    \n");
    printf("     /  o          /|    \n");
    printf("    /             / |    \n");
    printf("   /__________o__/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int dice3(int dieNumber)
{
    int a=3;
    printf("      .-------------.    \n");
    printf("     /  o          /|    \n");
    printf("    /      o      / |    \n");
    printf("   /___________o_/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int dice4(int dieNumber)
{
    int a=4;
    printf("      .-------------.    \n");
    printf("     /  o       o  /|    \n");
    printf("    /             / |    \n");
    printf("   /__o________o_/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int dice5(int dieNumber)
{
    int a=5;
    printf("      .-------------.    \n");
    printf("     /  o       o  /|    \n");
    printf("    /      o      / |    \n");
    printf("   /__o_______o__/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int dice6(int dieNumber)
{
    int a=6;
    printf("      .-------------.    \n");
    printf("     /  o       o  /|    \n");
    printf("    /  o       o  / |    \n");
    printf("   /__o_______o__/  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  |    \n");
    printf("   |             |  /     \n");
    printf("   |             | /     \n");
    printf("   |             |/       \n");
    printf("%d. '-------------'        \n",dieNumber);
    return a;
}

int playername(){

    printf("geef de naam van player 1(max 20 characters)\n\r");
    scanf("%s",&playersnames[0]);
    printf("geef de naam van player 2(max 20 characters)\n\r");
    scanf("%s",&playersnames[1]);
    return 0;
}


int scoreboard(int p){
    printf("\n");
    printf(" player %s                       \n",playersnames[p]); //moet nog functie zodat de | niet wordt verschoven (extra)
    printf(" X-----------------X-------------X\n\r");

    printf(" |1: enen             |    %d       ",categorie[p][0]); scoreboard_string_end(categorie[p][0]);
    printf(" |2: twees            |    %d       ",categorie[p][1]); scoreboard_string_end(categorie[p][1]);
    printf(" |3: dries            |    %d       ",categorie[p][2]); scoreboard_string_end(categorie[p][2]);
    printf(" |4: vieren           |    %d       ", categorie[p][3]); scoreboard_string_end(categorie[p][3]);
    printf(" |5: vijven           |    %d       ", categorie[p][4]); scoreboard_string_end(categorie[p][4]);
    printf(" |6: zessen           |    %d       ", categorie[p][5]); scoreboard_string_end(categorie[p][5]);

    int totall = categorie[p][0]+categorie[p][1]+categorie[p][2]+categorie[p][3]+categorie[p][4]+categorie[p][5];

    printf(" |totall              |    %d       ", totall); scoreboard_string_end(totall);

    printf(" X-----------------X-------------X\n\r");

    printf(" |7: three of a kind  |    %d       ", categorie[p][6]); scoreboard_string_end(categorie[p][6]);
    printf(" |8: four of a kind   |    %d       ", categorie[p][7]); scoreboard_string_end(categorie[p][7]);
    printf(" |9: full house       |    %d       ", categorie[p][8]); scoreboard_string_end(categorie[p][8]);
    printf(" |10: smallStraight   |    %d       ", categorie[p][9]); scoreboard_string_end(categorie[p][9]);
    printf(" |11: largeStraight   |    %d       ", categorie[p][10]); scoreboard_string_end(categorie[p][10]);
    printf(" |12: yathzee         |    %d       ", categorie[p][11]); scoreboard_string_end(categorie[p][11]);
    printf(" |13: chance          |    %d       ", categorie[p][12]); scoreboard_string_end(categorie[p][12]);

    int totall_2 = categorie[p][6]+categorie[p][7]+categorie[p][8]+categorie[p][9]+categorie[p][10]+categorie[p][11]+categorie[p][12];
    int totall_full = totall+totall_2;

    printf(" |totall              |    %d       ", totall_2); scoreboard_string_end(totall_2);
    printf(" |fulltotall          |    %d       ", totall_full); scoreboard_string_end(totall_full);

    printf(" X-----------------X-------------X\n\r");
    printf("\n");
    return 0;
}

int scoreboard_string_end(int i) {
    if (i <= 9) printf(" ");
    printf("|\n\r");

    return i;
}

void kiesCombo(int die[5], int p)
{
    int keuze = 0;

    printf("geef de combinatie in die je wil gebruiken(gebruik de nummers naast de namen): ");
    scanf("%d" , &keuze);

    switch(keuze)
    {
        case 1:
            categorie[p][0] = checkCombo(die, 1);
            break;
        case 2:
            categorie[p][1] = checkCombo(die, 2);
            break;
        case 3:
            categorie[p][2] = checkCombo(die, 3);
            break;
        case 4:
            categorie[p][3] = checkCombo(die, 4);
            break;
        case 5:
            categorie[p][4] = checkCombo(die, 5);
            break;
        case 6:
            categorie[p][5] = checkCombo(die, 6);
            break;
        case 7:
            categorie[p][6] = threeOfAKind(die);
            break;
        case 8:
            categorie[p][7] = fourOfAKind(die);
            break;
        case 9:
            categorie[p][8] = fullHouse(die);
            break;
        case 10:
            categorie[p][9] = smallStraight(die);
            break;
        case 11:
            categorie[p][10] = largeStraight(die);
            break;
        case 12:
            categorie[p][11] = yahtzee(die);
            break;
        case 13:
            categorie[p][12] = kans(die);
            break;
        default:
            printf("geef een juiste combinaties in\n");
            kiesCombo(die, p);
            break;
        }
    return;
}

int checkCombo(int die[5], int getal){
    int b = 0;
    for(int a = 0; a < 5; a++){
        if(die[a] == getal)
        b++;
    }
    b = b*getal;
    return b;
}

int threeOfAKind(int die[5]){
    int a = 0;
    if (die[0] == die[1] && die[1] == die[2]){
        a = die[0] + die[1] + die[2];
    }
    else if (die[1] == die[2] && die[2] == die[3]){
        a = die[1] + die[2] + die[3];
    }
    else if (die[2] == die[3] && die[3] == die[4]){
        a = die[2] + die[3] + die[4];
    }
    else if (die[3] == die[4] && die[4] == die[5]){
        a = die[3] + die[4] + die[5];
    }
    return a;
}

int fourOfAKind(int die[5]){
    int a = 0;
    if (die[0] == die[1] && die[1] == die[2] && die[2] == die[3]){
        a = die[0] + die[1] + die[2] + die[3];
    }
    else if (die[1] == die[2] && die[2] == die[3] && die[3] == die[4]){
        a = die[1] + die[2] + die[3] + die[4];
    }
    else if (die[2] == die[3] && die[3] == die[4] && die[4] == die[5]){
        a = die[2] + die[3] + die[4] + die[5];
    }
    return a;
}

int fullHouse(int die[5]){
    int a = 0;
    if (die[0] == die[1] && die[2] == die[3] && die[3] == die[4]){
        a = 25;
    }
    else if (die[1] == die[2] && die[3] == die[4] && die[4] == die[5]){
        a = 25;
    }
    else if (die[5] == die[4] && die[3] == die[2] && die[2] == die[1]){
        a= 25;
    }
    else if (die[4] == die[3] && die[2] == die[1] && die[1] == die[0]){
        a= 25;
    }
    return a;
}

int smallStraight(int die[5]){
    int a = 0;
    int b = 0;
	int c2 = 0;
	do{
		for(a = 0; a != 5; a++){
			if (die[a] == die[a+1]){
            die[a] = die[a] - 1;
			}
		}
		c2++;
	}while(c2 != 5);
    if (die[0] == die[1] -1 && die[0] == die[2] -2 &&  die[0] == die[3] - 3){
        b = 30;
    }
    else if (die[1] == die[2] -1 && die[1] == die[3] -2 &&  die[1] == die[4] - 3){
        b = 30;
    }
    else if (die[2] == die[3] -1 && die[2] == die[4] -2 &&  die[2] == die[5] - 3){
        b = 30;
    }
    return b;
}

int largeStraight(int die[5]){
    int a = 0;
    int b = 0;
    int c = 0;
    do{
        if (die[a] == die[a+1]){
            die[a] = die[a] - 1;
        }
        c++;
    }while(c != 5);
    if (die[0] == die[1] -1 && die[0] == die[2] -2 &&  die[0] == die[3] - 3 && die[0] == die[4] - 4){ //moet aanpassen
        b = 40;
    }
    else if (die[1] == die[2] -1 && die[1] == die[3] -2 &&  die[1] == die[4] - 3 &&  die[1] == die[5] - 4){
        b = 40;
    }

    return b;
}

int  yahtzee(int die[5]){
    int a = 0;

    if ( die[0] == 1 && die[1] == 1 &&  die[2] == 1 && 	die[3] == 1 &&  die[4] == 1 &&  die[5] == 1 ){
        a = 50;
    }
    else if (die[0] == 2 && die[1] == 2 && die[2] == 2 && die[3] == 2 && die[4] == 2 && die[5] == 2){
        a = 50;
    }
    else if (die[0] == 3 && die[1] == 3 && die[2] == 3 && die[3] == 3 && die[4] == 3 && die[5] == 3){
		a = 50;
    }
    else if (die[0] == 4 && die[1] == 4 && die[2] == 4 && die[3] == 4 && die[4] == 4 && die[5] == 4){
        a = 50;
    }
    else if (die[0] == 5 && die[1] == 5 && die[2] == 5 && die[3] == 5 && die[4] == 5 && die[5] == 5){
        a = 50;
    }
    else if (die[0] == 6 && die[1] == 6 && die[2] == 6 && die[3] == 6 && die[4] == 6 && die[5] == 6){
        a =50;
    }
    return a;
}

int kans(int die[5]){
    int a = 0;
    a = die[0] + die[1] + die[2] + die[3] + die[4] + die[5];
    return a;
}



void printIntro(void)
{


    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
    printf("| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |  \n");
    printf("| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |  \n");
    printf("| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |  \n");
    printf("| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |  \n");
    printf("| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |  \n");
    printf("| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |  \n");
    printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n");
    printf(" .----------------.  .----------------.                                                                                                       \n");
    printf("| .--------------. || .--------------. |                                                                                                      \n");
    printf("| |  _________   | || |     ____     | |                                                                                                      \n");
    printf("| | |  _   _  |  | || |   .'    `.   | |                                                                                                      \n");
    printf("| | |_/ | | \\_|  | || |  /  .--.  \\  | |                                                                                                      \n");
    printf("| |     | |      | || |  | |    | |  | |                                                                                                      \n");
    printf("| |    _| |_     | || |  \\  `--'  /  | |                                                                                                      \n");
    printf("| |   |_____|    | || |   `.____.'   | |                                                                                                      \n");
    printf("| |              | || |              | |                                                                                                      \n");
    printf("| '--------------' || '--------------' |                                                                                                      \n");
    printf(" '----------------'  '----------------'                                                                                                       \n");
    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
    printf("| |  ____  ____  | || |      __      | || |  ____  ____  | || |  _________   | || |   ________   | || |  _________   | || |  _________   | |  \n");
    printf("| | |_  _||_  _| | || |     /  \\     | || | |_   ||   _| | || | |  _   _  |  | || |  |  __   _|  | || | |_   ___  |  | || | |_   ___  |  | |  \n");
    printf("| |   \\ \\  / /   | || |    / /\\ \\    | || |   | |__| |   | || | |_/ | | \\_|  | || |  |_/  / /    | || |   | |_  \\_|  | || |   | |_  \\_|  | |  \n");
    printf("| |    \\ \\/ /    | || |   / ____ \\   | || |   |  __  |   | || |     | |      | || |     .'.' _   | || |   |  _|  _   | || |   |  _|  _   | |  \n");
    printf("| |    _|  |_    | || | _/ /    \\ \\_ | || |  _| |  | |_  | || |    _| |_     | || |   _/ /__/ |  | || |  _| |___/ |  | || |  _| |___/ |  | |  \n");
    printf("| |   |______|   | || ||____|  |____|| || | |____||____| | || |   |_____|    | || |  |________|  | || | |_________|  | || | |_________|  | |  \n");
    printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n");
}
