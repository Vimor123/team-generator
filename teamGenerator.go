package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strings"
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
		lastPlayer = players[unsortedPlayers-1]

		teams[teamIndex] = append(teams[teamIndex], chosenPlayer)

		teamIndex++

		if teamIndex >= numberOfTeams {
			teamIndex = 0
		}

		players[unsortedPlayers-1] = chosenPlayer
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

	fmt.Printf("\n")

	for teamIndex := 0; teamIndex < len(teams); teamIndex++ {

		fmt.Printf("Team %d\n", teamIndex+1)
		fmt.Println(divider)

		for playerIndex := 0; playerIndex < len(teams[teamIndex]); playerIndex++ {
			fmt.Println(teams[teamIndex][playerIndex])
		}

		fmt.Printf("\n")
	}
}

func main() {

	fmt.Printf("Names (delimiter = \",\") : ")
	inputReader := bufio.NewReader(os.Stdin)
	allPlayers, _ := inputReader.ReadString('\n')
	allPlayers = allPlayers[:len(allPlayers)-1]

	players := strings.Split(allPlayers, ",")

	for playerIndex := 0; playerIndex < len(players); playerIndex++ {
		players[playerIndex] = strings.Trim(players[playerIndex], " ")
	}

	var numberOfTeams int

	fmt.Printf("Number of teams : ")
	fmt.Scanf("%d", &numberOfTeams)

	teams := splitPeopleIntoTeams(players, numberOfTeams)

	printTeams(teams)
}
