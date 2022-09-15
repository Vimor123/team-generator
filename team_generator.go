package main

import ( 
    "fmt"
    "bufio"
    "os"
    "strings"
    "math/rand"
    "time"
)


func splitPeopleIntoTeams(players []string, numberOfTeams int) [][]string {
    
    // Take a random player from the player list
    // Place him in a team
    // Switch the chosen player with the last player in the list
    // Repeat but without the last player
    
    rand.Seed(time.Now().UnixNano())
    
    unsortedPlayers := len(players)
    
    var teamIndex int
    var randomPlayerIndex int
    var chosenPlayer string
    var lastPlayer string
    
    teams := make([][]string, numberOfTeams)
    
    teamIndex = 0
    
    for unsortedPlayers > 0 {
        
        randomPlayerIndex = rand.Intn(unsortedPlayers)
        chosenPlayer = players[randomPlayerIndex]
        lastPlayer = players[unsortedPlayers - 1]
        
        
        teams[teamIndex] = append(teams[teamIndex], chosenPlayer)
        
        teamIndex++
        
        if teamIndex >= numberOfTeams {
            teamIndex = 0
        }
        
        
        players[unsortedPlayers - 1] = chosenPlayer
        players[randomPlayerIndex] = lastPlayer
        
        unsortedPlayers--
        
    }
    
    return teams
}



func printTeams(teams [][]string) {
    
    var divider string
    
    for cIndex := 0; cIndex < 20; cIndex++ {
        divider += "="
    }
    
    
    for teamIndex := 0; teamIndex < len(teams); teamIndex++ {
        
        fmt.Printf("\nTeam %d\n", teamIndex + 1)
        fmt.Println(divider)
        
        for playerIndex := 0; playerIndex < len(teams[teamIndex]); playerIndex++ {
            fmt.Println(teams[teamIndex][playerIndex])
        }
    }
}



func main() {

	fmt.Printf("Names (delimiter = \",\") : ")
	inputReader := bufio.NewReader(os.Stdin)
	all_players, _ := inputReader.ReadString('\n')
	all_players = all_players[:len(all_players) - 1]
	
	
	players := strings.Split(all_players, ",")
	
	for playerIndex := 0; playerIndex < len(players); playerIndex++ {
	    players[playerIndex] = strings.Trim(players[playerIndex], " ")
	}
	
	
	var numberOfTeams int
	
	fmt.Printf("Number of teams : ")
	fmt.Scanf("%d", &numberOfTeams)
	
	
	teams := splitPeopleIntoTeams(players, numberOfTeams)
	
	printTeams(teams) 
}