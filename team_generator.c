#include <stdio.h>
#define MAX_ALL_PLAYERS_LENGTH 1000
#define MAX_NAME_LENGTH 100



int get_number_of_players(char *all_players) {
    
    int player_count = 1;
    
    char c;
    int c_index = 0;
    
    for(c = all_players[c_index]; c != '\0'; c = all_players[++c_index]) {
        if(c == ',') {
            player_count++;
        }
    }
    
    return player_count;
}



void split_players_into_teams(char *players, char *all_players) {
    
    int player_index = 0;
    char c;
    int c_index = 0;
    int c_player_index = 0;
    
    for(c = all_players[c_index]; c != '\0'; c = all_players[++c_index]) {
        if(c == ',') {
            player_index++;
            c_player_index = 0;
        } else if(c_player_index == 0 && c == ' ') {
            c_player_index = 0;
        } else {
            players[player_index * MAX_NAME_LENGTH + c_player_index++] = c;
        }
    }
    
    return;
}



int main(void) {
    
    // Getting all_players string
    char all_players[MAX_ALL_PLAYERS_LENGTH];
    printf("Names (delimiter : \",\") > ");
    scanf("%[^\n]%*c", all_players);
    
    
    // Calculating number of players
    int player_count;
    
    player_count = get_number_of_players(all_players);
    
    
    // Initializing player list
    char players[player_count][MAX_NAME_LENGTH];
    
    
    // Emptying player list
    int player_index;
    int c_index;
    
    for(player_index = 0; player_index < player_count; player_index++)
        for(c_index = 0; c_index < MAX_NAME_LENGTH; c_index++)
            players[player_index][c_index] = '\0';
    
    // Splitting all_players into player list
    split_players_into_teams(players[0], all_players);
    
    
    // Getting number of teams
    int team_count;
    printf("Number of teams > ");
    scanf("%d", &team_count);
    
    int players_per_team;
    
    if(player_count % team_count == 0) {
        players_per_team = player_count/team_count;
    } else {
        players_per_team = player_count/team_count + 1;
    }
    
    
    // Initializing teams
    char teams[team_count][players_per_team][MAX_NAME_LENGTH];
    
    printf("%d\n", players_per_team);
    
    for(int player_index = 0; player_index < player_count; player_index++) {
        printf("%s\n", players[player_index]);
    }
    
    return 0;
}