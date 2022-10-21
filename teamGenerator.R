# List all players and input number of teams
allPlayers <- c("Pig", "Bull", "Boar", "Bulldog",
                "Badger", "Horse", "Bear", "Tiger",
                "Wolf", "Rottweiler")

noOfTeams <- 4


# Calculating how much players each team has
playersPerTeamInt <- as.integer(length(allPlayers)/noOfTeams)
playersPerTeam <- rep(c(playersPerTeamInt), times = noOfTeams)
leftoverPlayerCount <- length(allPlayers) - playersPerTeamInt * noOfTeams

if (leftoverPlayerCount > 0) {
  for (teamIndex in  1 : leftoverPlayerCount) {
    playersPerTeam[teamIndex] = playersPerTeam[teamIndex] + 1
  }
}


# Shuffles all the players
allPlayers = sample(allPlayers)


# Printing the teams
playerIndex <- 1

for (teamIndex in 1 : noOfTeams) {
  print(paste(rep("=", 20), collapse = ""))
  print(paste("Team", teamIndex))
  print(paste(rep("=", 20), collapse = ""))
  
  for (playerInTeam in 1 : playersPerTeam[teamIndex]) {
    print(allPlayers[playerIndex])
    playerIndex = playerIndex + 1
  }
}

print(paste(rep("=", 20), collapse = ""))
