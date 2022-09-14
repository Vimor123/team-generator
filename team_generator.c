#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ALL_PLAYERS_LENGTH 1000
#define MAX_NAME_LENGTH 50


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



void split_all_players_into_list(char *players, char *all_players) {
    
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



void split_players_into_teams(char *players, char *teams, int player_count, int team_count, int players_per_team) {
    
    // Take a random player from the player list
    // Place him in a team
    // Switch the chosen player with the last player in the list
    // Repeat but without the last player
    
    srand(time(NULL));
    
    int unsorted_players = player_count;
    
    int player_in_team_index;
    int team_index;
    
    int random_player_index;
    char chosen_player[MAX_NAME_LENGTH];
    char last_player[MAX_NAME_LENGTH];
    
    char c;
    int c_index;
    
    
    player_in_team_index = 0;
    team_index = 0;
    
    while(unsorted_players > 0) {
        
        // Clearing strings
        for(c_index = 0; c_index < MAX_NAME_LENGTH; c_index++) {
            chosen_player[c_index] = '\0';
            last_player[c_index] = '\0';
        }
        
        
        // Last player
        c = *(players + (unsorted_players - 1) * MAX_NAME_LENGTH);
        c_index = 0;
        for(; c != '\0'; c = *(players + (unsorted_players - 1) * MAX_NAME_LENGTH + c_index)) {
            last_player[c_index++] = c;
        }
        
        
        // Chosen player
        random_player_index = rand() % unsorted_players;
        
        c = *(players + random_player_index * MAX_NAME_LENGTH);
        c_index = 0;
        for(; c != '\0'; c = *(players + random_player_index * MAX_NAME_LENGTH + c_index)) {
            chosen_player[c_index++] = c;
        }
        
        
        //Placing the chosen player in a team
        c_index = 0;
        for(c = chosen_player[c_index]; c != '\0'; c = chosen_player[++c_index]) {
            *(teams + team_index * (players_per_team * MAX_NAME_LENGTH) + player_in_team_index * MAX_NAME_LENGTH + c_index) = c;
        }
        
        
        //Switching the chosen player with the last player
        c_index = 0;
        for(c = last_player[c_index]; c != '\0'; c = last_player[++c_index]) {
            *(players + random_player_index * MAX_NAME_LENGTH + c_index) = c;
        }
        *(players + random_player_index * MAX_NAME_LENGTH + c_index) = '\0';
        
        
        unsorted_players--;
        team_index++;
        if(team_index == team_count) {
            team_index = 0;
            player_in_team_index++;
        }
    }
    
    return;
}



void print_teams(char *teams, int team_count, int players_per_team) {
    
    int team_index;
    int player_index;
    int c_index;
    char c;
    
    char divider[21];
    
    for(c_index = 0; c_index < 20; c_index++) {
        divider[c_index] = '=';
    }
    divider[20] = '\0';
    
    for(team_index = 0; team_index < team_count; team_index++) {
        printf("\nTeam %d\n", team_index + 1);
        printf("%s\n", divider);
        
        for(player_index = 0; player_index < players_per_team; player_index++) {
            
            c_index = 0;
            c = *(teams + team_index * players_per_team * MAX_NAME_LENGTH + player_index * MAX_NAME_LENGTH);
            
            for(; c != '\0'; c = *(teams + team_index * players_per_team * MAX_NAME_LENGTH + player_index * MAX_NAME_LENGTH + (++c_index))) {
                printf("%c", *(teams + team_index * players_per_team * MAX_NAME_LENGTH + player_index * MAX_NAME_LENGTH + c_index));
            }
            
            if(*(teams + team_index * players_per_team * MAX_NAME_LENGTH + player_index * MAX_NAME_LENGTH) != '\0')
                printf("\n");
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
    split_all_players_into_list(players[0], all_players);
    
    
    // Getting number of teams
    int team_count;
    printf("Number of teams > ");
    scanf("%d", &team_count);
    
    
    // Initializing teams
    int players_per_team;
    
    if(player_count % team_count == 0) {
        players_per_team = player_count/team_count;
    } else {
        players_per_team = player_count/team_count + 1;
    }
    
    char teams[team_count][players_per_team][MAX_NAME_LENGTH];
    
    
    // Emptying teams
    int team_index;
    player_index = 0;
    c_index = 0;
    
    for(team_index = 0; team_index < team_count; team_index++)
        for(player_index = 0; player_index < players_per_team; player_index++)
            for(c_index = 0; c_index < MAX_NAME_LENGTH; c_index++)
                teams[team_index][player_index][c_index] = '\0';
    
    
    // Splitting people into teams
    split_players_into_teams(players[0], teams[0][0], player_count, team_count, players_per_team);
    
    
    // Printing teams
    print_teams(teams[0][0], team_count, players_per_team);
    
    
    return 0;
}