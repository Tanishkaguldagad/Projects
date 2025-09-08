#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player {
	int jerseyno;
	char playername[20];
	int runs;
	int wickets;
	int matchesplayed;
};
struct player players[100];
int playercount=0;
void addplayer() {
	struct player p;
	printf("enter jersey number:");
	scanf("%d",&p.jerseyno);
	printf("enter player name\n:");
	scanf("%s",p.playername);

	printf("enter runs\n:");
	scanf("%d",&p.runs);

	printf("enter wickets\n:");
	scanf("%d",&p.wickets);

	printf("enter matches played\n:");
	scanf("%d",&p.matchesplayed);

	players[playercount]=p;
	playercount++;

	printf("Player Added Successfully!\n");

}
void removeplayer() {
	int jersey,found=0;

	printf("enter a jersey number of player to remove:");
	scanf("%d",&jersey);

	for(int i=0; i<playercount; i++) {
		if(players[i].jerseyno==jersey) {
			for(int j=i; j<playercount-1; j++) {
				players[j]=players[j+1];
			}
			playercount--;
			found=1;
			printf("Player with Jersey No %d removed successfully!\n",jersey);
			break;
		}
	}
	if (!found) {
		printf("Player with Jersey No %d not found!\n",jersey);
	}
}

void searchplayer() {
	int jersey, found = 0;
	printf("Enter Jersey Number to search: ");
	scanf("%d", &jersey);

	for (int i = 0; i < playercount; i++) {
		if (players[i].jerseyno == jersey) {
			printf("\n--- Player Found ---\n");
			printf("Jersey No: %d\n", players[i].jerseyno);
			printf("Name: %s\n", players[i].playername);
			printf("Runs: %d\n", players[i].runs);
			printf("Wickets: %d\n", players[i].wickets);
			printf("Matches: %d\n", players[i].matchesplayed);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf(" \nPlayer with Jersey No %d not found!\n", jersey);
	}
}
void updateplayer() {
	int jersey,found=0;
	printf("enter a jersey no to display:");
	scanf("%d",&jersey);

	for(int i=0; i<playercount; i++) {
		if (players[i].jerseyno == jersey) {
			printf("\n--- Current Player Data ---\n");
			printf("Jersey No: %d\n", players[i].jerseyno);
			printf("Name: %s\n", players[i].playername);
			printf("Runs: %d\n", players[i].runs);
			printf("Wickets: %d\n", players[i].wickets);
			printf("Matches: %d\n", players[i].matchesplayed);

			printf("\n enter new runs:");
			scanf("%d",&players[i].runs);
			printf("\n enter new wickets:");
			scanf("%d",&players[i].wickets);
			printf("\n enter new matches played:");
			scanf("%d",&players[i].matchesplayed);


			printf("\n Player data updated successfully!\n");
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("\n Player with given jersey number %d not found\n", jersey);
	}
}

void displaysortedplayers() {
	int choice;
	printf("\n --display sorted players \n:");
	printf("1.minimum to maximum runs:");
	printf("2.maximum to minimum runs:");
	printf("3.minimum to maximum wickets:");
	printf("4.maximum to minimum wickets:");
	printf("enter your choice:");
	scanf("%d",&choice);

	struct player tempPlayers[100];
	for(int i=0; i<playercount; i++) {
		tempPlayers[i]=players[i];
	}
	for(int i=0; i<playercount; i++)
		for(int j=0; j<playercount-i-1; j++) {
			int swapneeded=0;

			if(choice==1 && (tempPlayers[j].runs>tempPlayers[j+1].runs))
				swapneeded=1;
			else if(choice==2 &&tempPlayers[j].runs<tempPlayers[j+1].runs)
				swapneeded=1;
			else if(choice==3 &&tempPlayers[j].runs>tempPlayers[j+1].wickets)
				swapneeded=1;
			else if(choice==4 &&tempPlayers[j].runs<tempPlayers[j+1].wickets)
				swapneeded=1;

			if (swapneeded) {
				struct player temp = tempPlayers[j];
				tempPlayers[j] = tempPlayers[j + 1];
				tempPlayers[j + 1] = temp;
			}
		}
		printf("\n--- Sorted Player List ---\n");
  	for (int i = 0; i < playercount; i++) {
	printf("Jersey No: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",tempPlayers[i].jerseyno, tempPlayers[i].playername,
	       tempPlayers[i].runs, tempPlayers[i].wickets, tempPlayers[i].matchesplayed);
    }
}
void displayallplayers() {
	if(playercount==0) {
		printf("\n No players in the database\n");
		return;

		printf("---all players---\n:");
		for (int i = 0; i < playercount; i++) {
			printf("Jersey No: %d\n", players[i].jerseyno);
			printf("Name: %s\n", players[i].playername);
			printf("Runs: %d\n", players[i].runs);
			printf("Wickets: %d\n", players[i].wickets);
			printf("Matches: %d\n", players[i].matchesplayed);
			printf("-------------------------\n");
		}
	}
	
}
	void main() {
		addplayer();
		removeplayer();
		searchplayer();
		updateplayer();
		displaysortedplayers();
		displayallplayers();
	}
